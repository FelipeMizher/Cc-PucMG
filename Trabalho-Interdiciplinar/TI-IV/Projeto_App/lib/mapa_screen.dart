import 'dart:async';
import 'package:flutter/material.dart';
import 'package:google_maps_flutter/google_maps_flutter.dart';
import 'package:geolocator/geolocator.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'grafo_servico.dart';
import 'mapa_grafo_view.dart';

class MapaScreen extends StatefulWidget {
  const MapaScreen({super.key});

  @override
  State<MapaScreen> createState() => _MapaScreenState();
}

class _MapaScreenState extends State<MapaScreen> {
  GoogleMapController? _mapController;
  Position? _posicaoAtual;
  bool _carregando = true;

  @override
  void initState() {
    super.initState();
    _obterLocalizacaoAtual();
  }

  // Descobre a localização física do dispositivo pelo GPS
  Future<void> _obterLocalizacaoAtual() async {
    try {
      _posicaoAtual = await Geolocator.getCurrentPosition(
        locationSettings: const LocationSettings(
          accuracy: LocationAccuracy.high,
        ),
      );
    } catch (e) {
      debugPrint("Erro ao pegar GPS do usuário: $e");
    }

    setState(() {
      _carregando = false;
    });
  }

  @override
  Widget build(BuildContext context) {
    // Coordenadas de foco inicial caso o GPS do emulador/dispositivo falhe
    double latFoco = _posicaoAtual?.latitude ?? -19.917299;
    double lngFoco = _posicaoAtual?.longitude ?? -43.934559;

    return DefaultTabController(
      length: 2,
      child: Scaffold(
        appBar: AppBar(
          title: const Text(
            'Mapa de Doações',
            style: TextStyle(color: Colors.white, fontWeight: FontWeight.bold),
          ),
          backgroundColor: Colors.blue,
          iconTheme: const IconThemeData(color: Colors.white),
          bottom: const TabBar(
            labelColor: Colors.white,
            unselectedLabelColor: Colors.white60,
            indicatorColor: Colors.white,
            tabs: [
              Tab(icon: Icon(Icons.map), text: "Visão Geral"),
              Tab(icon: Icon(Icons.hub), text: "Rede de Proximidade"),
            ],
          ),
        ),
        body: _carregando
            ? const Center(child: CircularProgressIndicator())
            : StreamBuilder<QuerySnapshot>(
          // Fluxo de dados vivo e reativo conectado ao Firestore
          stream: FirebaseFirestore.instance
              .collection('materiais')
              .where('status', isEqualTo: 'disponivel')
              .snapshots(),
          builder: (context, snapshot) {
            if (snapshot.connectionState == ConnectionState.waiting) {
              return const Center(child: CircularProgressIndicator());
            }

            var documentos = snapshot.data?.docs ?? [];

            Set<Marker> novosMarcadores = {};
            List<Map<String, dynamic>> materiaisListaInferior = [];

            // Processamento matricial dinâmico das distâncias geográficas
            for (var doc in documentos) {
              final dados = doc.data() as Map<String, dynamic>;
              final double? lat = dados['latitude'];
              final double? lng = dados['longitude'];

              if (lat != null && lng != null) {
                double distanciaMetros = 0;
                String distanciaTexto = "Distância desconhecida";

                if (_posicaoAtual != null) {
                  distanciaMetros = Geolocator.distanceBetween(
                    _posicaoAtual!.latitude,
                    _posicaoAtual!.longitude,
                    lat,
                    lng,
                  );

                  if (distanciaMetros < 1000) {
                    distanciaTexto = "${distanciaMetros.toInt()} m de distância";
                  } else {
                    distanciaTexto = "${(distanciaMetros / 1000).toStringAsFixed(1)} km de distância";
                  }
                }

                materiaisListaInferior.add({
                  'id': doc.id,
                  'titulo': dados['titulo'] ?? 'Sem título',
                  'lat': lat,
                  'lng': lng,
                  'distanciaMetros': distanciaMetros,
                  'distanciaTexto': distanciaTexto,
                });

                novosMarcadores.add(
                  Marker(
                    markerId: MarkerId(doc.id),
                    position: LatLng(lat, lng),
                    infoWindow: InfoWindow(
                      title: dados['titulo'] ?? 'Sem título',
                      snippet: distanciaTexto,
                    ),
                    icon: BitmapDescriptor.defaultMarkerWithHue(BitmapDescriptor.hueRed),
                  ),
                );
              }
            }

            // Ordenação clássica de proximidade para o feed inferior do mapa
            materiaisListaInferior.sort(
                  (a, b) => a['distanciaMetros'].compareTo(b['distanciaMetros']),
            );

            return TabBarView(
              physics: const NeverScrollableScrollPhysics(), // Bloqueia swipe lateral para não dar conflito com o arrastar do mapa
              children: [

                // ==== ABA 1: VISÃO GERAL (GOOGLE MAPS + LISTA INFERIOR) ====
                Stack(
                  children: [
                    GoogleMap(
                      initialCameraPosition: CameraPosition(
                        target: LatLng(latFoco, lngFoco),
                        zoom: 14,
                      ),
                      myLocationEnabled: true,
                      myLocationButtonEnabled: true,
                      markers: novosMarcadores,
                      onMapCreated: (controller) => _mapController = controller,
                    ),

                    Align(
                      alignment: Alignment.bottomCenter,
                      child: Container(
                        height: 280,
                        decoration: const BoxDecoration(
                          color: Colors.white,
                          borderRadius: BorderRadius.only(
                            topLeft: Radius.circular(25),
                            topRight: Radius.circular(25),
                          ),
                          boxShadow: [
                            BoxShadow(
                              color: Colors.black26,
                              blurRadius: 10,
                              spreadRadius: 2,
                            ),
                          ],
                        ),
                        child: Column(
                          crossAxisAlignment: CrossAxisAlignment.stretch,
                          children: [
                            Center(
                              child: Container(
                                margin: const EdgeInsets.only(top: 12, bottom: 12),
                                width: 50,
                                height: 5,
                                decoration: BoxDecoration(
                                  color: Colors.grey.shade300,
                                  borderRadius: BorderRadius.circular(10),
                                ),
                              ),
                            ),
                            const Padding(
                              padding: EdgeInsets.symmetric(horizontal: 20),
                              child: Text(
                                'Materiais próximos de você',
                                style: TextStyle(
                                  fontSize: 18,
                                  fontWeight: FontWeight.bold,
                                ),
                              ),
                            ),
                            const SizedBox(height: 10),

                            Expanded(
                              child: materiaisListaInferior.isEmpty
                                  ? const Center(
                                child: Text(
                                  'Nenhum material disponível por perto.',
                                  style: TextStyle(color: Colors.grey),
                                ),
                              )
                                  : ListView.builder(
                                itemCount: materiaisListaInferior.length,
                                itemBuilder: (context, index) {
                                  final item = materiaisListaInferior[index];
                                  return ListTile(
                                    leading: CircleAvatar(
                                      backgroundColor: Colors.blue.shade50,
                                      child: const Icon(
                                        Icons.menu_book,
                                        color: Colors.blue,
                                      ),
                                    ),
                                    title: Text(
                                      item['titulo'],
                                      style: const TextStyle(fontWeight: FontWeight.bold),
                                    ),
                                    subtitle: Text(
                                      item['distanciaTexto'],
                                      style: const TextStyle(color: Colors.grey),
                                    ),
                                    trailing: const Icon(Icons.chevron_right),
                                    onTap: () {
                                      _mapController?.animateCamera(
                                        CameraUpdate.newLatLngZoom(
                                          LatLng(item['lat'], item['lng']),
                                          17,
                                        ),
                                      );
                                    },
                                  );
                                },
                              ),
                            ),
                          ],
                        ),
                      ),
                    ),
                  ],
                ),

                // ==== ABA 2: REDE DE PROXIMIDADE (GRAFO DINÂMICO ASSÍNCRONO COM BFS) ====
                FutureBuilder<List<RegiaoNo>>(
                  future: ServicoGrafos().gerarGrafoBFSDinamico(documentos, latFoco, lngFoco),
                  builder: (context, grafoSnapshot) {
                    if (grafoSnapshot.connectionState == ConnectionState.waiting) {
                      return const Center(child: CircularProgressIndicator());
                    }

                    final nosCalculados = grafoSnapshot.data ?? [];
                    return MapaGrafoView(nosGrafo: nosCalculados);
                  },
                ),
              ],
            );
          },
        ),
      ),
    );
  }
}