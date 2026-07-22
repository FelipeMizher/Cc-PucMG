import 'dart:math';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:geocoding/geocoding.dart';

class RegiaoNo {
  final String id;
  final String nomeBairro;
  final double latitude;
  final double longitude;
  final List<Map<String, dynamic>> materiais;
  int nivelBfs;
  double distanciaDoCentroKm;
  String? idNoPai;
  Map<String, double> conexoesDistancias = {};

  RegiaoNo({
    required this.id,
    required this.nomeBairro,
    required this.latitude,
    required this.longitude,
    required this.materiais,
    this.nivelBfs = 0,
    this.distanciaDoCentroKm = 0.0,
    this.idNoPai,
  });
}

class ServicoGrafos {
  double calcularDistanciaReal(double lat1, double lon1, double lat2, double lon2) {
    const double raioTerra = 6371;
    double dLat = (lat2 - lat1) * pi / 180;
    double dLon = (lon2 - lon1) * pi / 180;

    double a = sin(dLat / 2) * sin(dLat / 2) +
        cos(lat1 * pi / 180) * cos(lat2 * pi / 180) * sin(dLon / 2) * sin(dLon / 2);

    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return raioTerra * c;
  }

  Future<List<RegiaoNo>> gerarGrafoBFSDinamico(List<QueryDocumentSnapshot> documentos, double minhaLat, double minhaLng) async {
    Map<String, List<Map<String, dynamic>>> agrupamentoPorBairro = {};
    Map<String, List<double>> coordenadasPorBairro = {};

    for (var doc in documentos) {
      final dados = doc.data() as Map<String, dynamic>;
      final double? lat = dados['latitude'];
      final double? lng = dados['longitude'];

      if (lat == null || lng == null) continue;

      String nomeBairroIdentificado = "Região Próxima";
      try {
        List<Placemark> marcas = await placemarkFromCoordinates(lat, lng).timeout(const Duration(seconds: 1));
        if (marcas.isNotEmpty && marcas.first.subLocality != null && marcas.first.subLocality!.isNotEmpty) {
          nomeBairroIdentificado = marcas.first.subLocality!;
        }
      } catch (_) {}

      var materialComId = Map<String, dynamic>.from(dados);
      materialComId['id'] = doc.id;

      if (!agrupamentoPorBairro.containsKey(nomeBairroIdentificado)) {
        agrupamentoPorBairro[nomeBairroIdentificado] = [];
        coordenadasPorBairro[nomeBairroIdentificado] = [lat, lng];
      }
      agrupamentoPorBairro[nomeBairroIdentificado]!.add(materialComId);
    }

    List<RegiaoNo> todosOsNos = [];

    for (var bairro in agrupamentoPorBairro.keys) {
      double lat = coordenadasPorBairro[bairro]![0];
      double lng = coordenadasPorBairro[bairro]![1];

      todosOsNos.add(RegiaoNo(
        id: bairro,
        nomeBairro: bairro,
        latitude: lat,
        longitude: lng,
        materiais: agrupamentoPorBairro[bairro]!,
      ));
    }

    if (todosOsNos.isEmpty) return [];

    todosOsNos.sort((a, b) => calcularDistanciaReal(minhaLat, minhaLng, a.latitude, a.longitude)
        .compareTo(calcularDistanciaReal(minhaLat, minhaLng, b.latitude, b.longitude)));

    RegiaoNo noRaiz = todosOsNos.first;
    noRaiz.nivelBfs = 0;
    noRaiz.distanciaDoCentroKm = 0.0;

    List<RegiaoNo> nosDoGrafoFinal = [noRaiz];
    List<RegiaoNo> filaBFS = [noRaiz];
    Set<String> visitados = {noRaiz.id};

    while (filaBFS.isNotEmpty) {
      RegiaoNo atual = filaBFS.removeAt(0);

      if (atual.nivelBfs >= 5) continue;

      for (var potencialVizinho in todosOsNos) {
        if (!visitados.contains(potencialVizinho.id)) {
          double distanciaEntreBairros = calcularDistanciaReal(
              atual.latitude, atual.longitude,
              potencialVizinho.latitude, potencialVizinho.longitude
          );

          if (distanciaEntreBairros <= 6.0) {
            visitados.add(potencialVizinho.id);
            potencialVizinho.nivelBfs = atual.nivelBfs + 1;
            potencialVizinho.idNoPai = atual.id;

            potencialVizinho.distanciaDoCentroKm = calcularDistanciaReal(
                noRaiz.latitude, noRaiz.longitude,
                potencialVizinho.latitude, potencialVizinho.longitude
            );

            filaBFS.add(potencialVizinho);
            nosDoGrafoFinal.add(potencialVizinho);
          }
        }
      }
    }

    nosDoGrafoFinal.sort((a, b) {
      if (a.id == noRaiz.id) return -1;
      if (b.id == noRaiz.id) return 1;
      double anguloA = atan2(a.latitude - noRaiz.latitude, a.longitude - noRaiz.longitude);
      double anguloB = atan2(b.latitude - noRaiz.latitude, b.longitude - noRaiz.longitude);
      return anguloA.compareTo(anguloB);
    });

    for (var no in nosDoGrafoFinal) {
      if (no.idNoPai != null) {
        try {
          var noPai = nosDoGrafoFinal.firstWhere((p) => p.id == no.idNoPai);
          double dist = calcularDistanciaReal(no.latitude, no.longitude, noPai.latitude, noPai.longitude);
          noPai.conexoesDistancias[no.id] = dist;
        } catch (_) {}
      }
    }

    return nosDoGrafoFinal;
  }
}