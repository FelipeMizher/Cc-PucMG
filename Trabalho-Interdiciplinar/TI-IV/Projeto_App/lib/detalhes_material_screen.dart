import 'dart:async';
import 'package:flutter/material.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:google_maps_flutter/google_maps_flutter.dart';
import 'package:url_launcher/url_launcher.dart';
import 'package:connectivity_plus/connectivity_plus.dart';
import 'package:cached_network_image/cached_network_image.dart'; // ==== IMPORT DO CACHE ADICIONADO ====
import 'chat_screen.dart';
import 'login_screen.dart';
import 'local_database.dart';

class DetalhesMaterialScreen extends StatefulWidget {
  final Map<String, dynamic> material;
  final String materialId;

  const DetalhesMaterialScreen({
    super.key,
    required this.material,
    required this.materialId,
  });

  @override
  State<DetalhesMaterialScreen> createState() => _DetalhesMaterialScreenState();
}

class _DetalhesMaterialScreenState extends State<DetalhesMaterialScreen> {
  bool _isOffline = false;
  late StreamSubscription<List<ConnectivityResult>> _connectivitySubscription;

  @override
  void initState() {
    super.initState();
    _checarInternetInicial();
    _monitorarInternet();
  }

  @override
  void dispose() {
    _connectivitySubscription.cancel();
    super.dispose();
  }

  Future<void> _checarInternetInicial() async {
    final result = await Connectivity().checkConnectivity();
    if (mounted) {
      setState(() {
        _isOffline = result.contains(ConnectivityResult.none);
      });
    }
  }

  void _monitorarInternet() {
    _connectivitySubscription = Connectivity().onConnectivityChanged.listen((List<ConnectivityResult> results) {
      if (mounted) {
        setState(() {
          _isOffline = results.contains(ConnectivityResult.none);
        });
      }
    });
  }

  Future<void> _abrirNoGoogleMaps(BuildContext context, double lat, double lng) async {
    final url = Uri.parse('https://www.google.com/maps/search/?api=1&query=$lat,$lng');
    try {
      if (await canLaunchUrl(url)) {
        await launchUrl(url, mode: LaunchMode.externalApplication);
      } else {
        throw 'Não foi possível abrir o mapa.';
      }
    } catch (e) {
      if (context.mounted) {
        ScaffoldMessenger.of(context).showSnackBar(
          const SnackBar(content: Text('Erro ao abrir o Google Maps.'), backgroundColor: Colors.red),
        );
      }
    }
  }

  @override
  Widget build(BuildContext context) {
    final usuarioAtual = FirebaseAuth.instance.currentUser;
    final bool isMeuItem = widget.material['doadorId'] == usuarioAtual?.uid;

    final double? lat = widget.material['latitude'];
    final double? lng = widget.material['longitude'];
    final bool temLocalizacao = lat != null && lng != null;

    final List<dynamic> fotosDinamicas = widget.material['fotos'] ?? [];
    final List<String> fotos = fotosDinamicas.map((e) => e.toString()).toList();

    final Color corTema = _isOffline ? Colors.red.shade700 : Colors.blue;
    final Color corDestaqueTexto = _isOffline ? Colors.red.shade900 : Colors.blue;

    return Scaffold(
      backgroundColor: Colors.grey.shade50,
      appBar: AppBar(
        title: const Text('Detalhes da Doação', style: TextStyle(color: Colors.white)),
        backgroundColor: corTema,
        iconTheme: const IconThemeData(color: Colors.white),
      ),
      body: Column(
        children: [
          if (_isOffline)
            Container(
              width: double.infinity,
              color: Colors.red,
              padding: const EdgeInsets.symmetric(vertical: 8),
              child: const Row(
                mainAxisAlignment: MainAxisAlignment.center,
                children: [
                  Icon(Icons.cloud_off, color: Colors.white, size: 18),
                  SizedBox(width: 8),
                  Text(
                    'Visualização Offline (Dados locais)',
                    style: TextStyle(color: Colors.white, fontWeight: FontWeight.bold),
                  ),
                ],
              ),
            ),

          Expanded(
            child: SingleChildScrollView(
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  // Carrossel de Fotos
                  if (fotos.isNotEmpty) ...[
                    SizedBox(
                      height: 280,
                      child: ListView.builder(
                        scrollDirection: Axis.horizontal,
                        padding: const EdgeInsets.all(16),
                        itemCount: fotos.length,
                        itemBuilder: (context, index) {
                          return GestureDetector(
                            onTap: () {
                              Navigator.push(
                                context,
                                MaterialPageRoute(
                                  builder: (context) => TelaVisualizacaoFotos(fotos: fotos, indiceInicial: index),
                                ),
                              );
                            },
                            child: Container(
                              width: MediaQuery.of(context).size.width * 0.8,
                              margin: const EdgeInsets.only(right: 12),
                              decoration: BoxDecoration(
                                borderRadius: BorderRadius.circular(15),
                                boxShadow: const [BoxShadow(color: Colors.black12, blurRadius: 5)],
                                image: DecorationImage(
                                  image: CachedNetworkImageProvider(fotos[index]),
                                  fit: BoxFit.cover,
                                ),
                              ),
                              child: fotos.length > 1
                                  ? Align(
                                alignment: Alignment.bottomRight,
                                child: Container(
                                  margin: const EdgeInsets.all(10),
                                  padding: const EdgeInsets.symmetric(horizontal: 10, vertical: 5),
                                  decoration: BoxDecoration(
                                    color: Colors.black.withValues(alpha: 0.7),
                                    borderRadius: BorderRadius.circular(15),
                                  ),
                                  child: Text('${index + 1}/${fotos.length}', style: const TextStyle(color: Colors.white, fontWeight: FontWeight.bold)),
                                ),
                              )
                                  : null,
                            ),
                          );
                        },
                      ),
                    ),
                  ] else ...[
                    Container(
                      height: 200,
                      width: double.infinity,
                      color: Colors.grey.shade200,
                      child: const Icon(Icons.image_not_supported, size: 60, color: Colors.grey),
                    ),
                  ],

                  Padding(
                    padding: const EdgeInsets.all(20.0),
                    child: Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      children: [
                        Text(
                          widget.material['titulo'] ?? 'Sem título',
                          style: const TextStyle(fontSize: 28, fontWeight: FontWeight.bold),
                        ),
                        const SizedBox(height: 16),

                        Row(
                          children: [
                            Chip(
                              label: Text(widget.material['categoria'] ?? 'Outros'),
                              backgroundColor: _isOffline ? Colors.red.shade50 : Colors.blue.shade50,
                              side: BorderSide.none,
                            ),
                            const SizedBox(width: 10),
                            Chip(
                              label: Text(
                                widget.material['status'].toString().toUpperCase(),
                                style: const TextStyle(color: Colors.white, fontWeight: FontWeight.bold),
                              ),
                              backgroundColor: widget.material['status'] == 'disponivel' ? Colors.green : Colors.grey,
                              side: BorderSide.none,
                            ),
                          ],
                        ),
                        const SizedBox(height: 30),

                        Text(
                          'Descrição do Item:',
                          style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold, color: corDestaqueTexto),
                        ),
                        const SizedBox(height: 10),
                        Container(
                          width: double.infinity,
                          padding: const EdgeInsets.all(16),
                          decoration: BoxDecoration(
                            color: Colors.white,
                            borderRadius: BorderRadius.circular(10),
                            border: Border.all(color: Colors.grey.shade300),
                            boxShadow: const [BoxShadow(color: Colors.black12, blurRadius: 2, offset: Offset(0, 1))],
                          ),
                          child: Text(
                            widget.material['descricao'] ?? 'Nenhuma descrição fornecida.',
                            style: const TextStyle(fontSize: 16, height: 1.5),
                          ),
                        ),

                        if (temLocalizacao) ...[
                          const SizedBox(height: 30),
                          Text(
                            'Localização de Retirada:',
                            style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold, color: corDestaqueTexto),
                          ),
                          const SizedBox(height: 10),

                          if (_isOffline)
                            Container(
                              height: 180,
                              width: double.infinity,
                              decoration: BoxDecoration(
                                color: Colors.grey.shade200,
                                borderRadius: BorderRadius.circular(15),
                                border: Border.all(color: Colors.grey.shade300, width: 2),
                              ),
                              child: const Column(
                                mainAxisAlignment: MainAxisAlignment.center,
                                children: [
                                  Icon(Icons.map_outlined, size: 40, color: Colors.grey),
                                  SizedBox(height: 8),
                                  Text(
                                    'Mapa indisponível offline',
                                    style: TextStyle(color: Colors.grey, fontWeight: FontWeight.bold),
                                  ),
                                  Text(
                                    'As coordenadas permanecem seguras localmente.',
                                    style: TextStyle(color: Colors.grey, fontSize: 12),
                                  ),
                                ],
                              ),
                            )
                          else
                            Container(
                              height: 180,
                              width: double.infinity,
                              decoration: BoxDecoration(
                                borderRadius: BorderRadius.circular(15),
                                border: Border.all(color: Colors.grey.shade300, width: 2),
                                boxShadow: const [BoxShadow(color: Colors.black12, blurRadius: 4)],
                              ),
                              child: ClipRRect(
                                borderRadius: BorderRadius.circular(13),
                                child: GoogleMap(
                                  initialCameraPosition: CameraPosition(target: LatLng(lat, lng), zoom: 15),
                                  markers: {
                                    Marker(markerId: const MarkerId('local'), position: LatLng(lat, lng)),
                                  },
                                  zoomControlsEnabled: false,
                                  scrollGesturesEnabled: false,
                                  myLocationButtonEnabled: false,
                                  mapToolbarEnabled: false,
                                ),
                              ),
                            ),
                          const SizedBox(height: 12),

                          SizedBox(
                            width: double.infinity,
                            child: OutlinedButton.icon(
                              onPressed: _isOffline ? null : () => _abrirNoGoogleMaps(context, lat, lng),
                              icon: Icon(Icons.map, color: _isOffline ? Colors.grey : Colors.green),
                              label: Text(
                                _isOffline ? 'Rotas indisponíveis offline' : 'Ver Rota no Google Maps',
                                style: TextStyle(color: _isOffline ? Colors.grey : Colors.green, fontSize: 16),
                              ),
                              style: OutlinedButton.styleFrom(
                                padding: const EdgeInsets.all(12),
                                side: BorderSide(color: _isOffline ? Colors.grey.shade300 : Colors.green, width: 2),
                              ),
                            ),
                          ),
                        ],
                      ],
                    ),
                  ),
                ],
              ),
            ),
          ),

          Container(
            padding: const EdgeInsets.all(20),
            decoration: BoxDecoration(
              color: Colors.white,
              boxShadow: [BoxShadow(color: Colors.grey.shade300, blurRadius: 10, offset: const Offset(0, -3))],
            ),
            child: SizedBox(
              width: double.infinity,
              child: ElevatedButton.icon(
                onPressed: (isMeuItem || _isOffline)
                    ? null
                    : () async {
                  if (usuarioAtual == null) {
                    ScaffoldMessenger.of(context).showSnackBar(
                        const SnackBar(content: Text('Crie uma conta ou faça login para conversar com o doador!'), backgroundColor: Colors.orange)
                    );
                    Navigator.push(context, MaterialPageRoute(builder: (context) => const LoginScreen()));
                    return;
                  }

                  showDialog(
                    context: context,
                    builder: (_) => const Center(child: CircularProgressIndicator()),
                    barrierDismissible: false,
                  );
                  try {
                    final chatId = '${widget.materialId}_${usuarioAtual.uid}';

                    await DatabaseHelper.instance.adicionarFavorito(widget.material, widget.materialId);

                    final userDoc = await FirebaseFirestore.instance.collection('usuarios').doc(usuarioAtual.uid).get();
                    final interessadoNome = userDoc.data()?['nome'] ?? 'Usuário Interessado';

                    await FirebaseFirestore.instance.collection('chats').doc(chatId).set({
                      'materialId': widget.materialId,
                      'materialTitulo': widget.material['titulo'],
                      'doadorId': widget.material['doadorId'],
                      'interessadoId': usuarioAtual.uid,
                      'interessadoNome': interessadoNome,
                      'ultimoContato': FieldValue.serverTimestamp(),
                    }, SetOptions(merge: true));

                    if (context.mounted) {
                      Navigator.pop(context);
                      Navigator.push(context, MaterialPageRoute(builder: (context) => ChatScreen(chatId: chatId, tituloMaterial: widget.material['titulo'] ?? 'Chat')));
                    }
                  } catch (e) {
                    if (context.mounted) {
                      Navigator.pop(context);
                      ScaffoldMessenger.of(context).showSnackBar(SnackBar(content: Text('Erro ao abrir chat: $e'), backgroundColor: Colors.red));
                    }
                  }
                },
                icon: Icon(isMeuItem ? Icons.block : (_isOffline ? Icons.wifi_off : Icons.chat)),
                label: Padding(
                  padding: const EdgeInsets.all(16.0),
                  child: Text(
                    isMeuItem
                        ? 'Este item é seu'
                        : (_isOffline ? 'Indisponível Offline' : 'Tenho Interesse'),
                    style: const TextStyle(fontSize: 18),
                  ),
                ),
                style: ElevatedButton.styleFrom(
                  backgroundColor: corTema,
                  foregroundColor: Colors.white,
                  disabledBackgroundColor: Colors.grey.shade300,
                  disabledForegroundColor: Colors.grey.shade600,
                ),
              ),
            ),
          ),
        ],
      ),
    );
  }
}

class TelaVisualizacaoFotos extends StatefulWidget {
  final List<String> fotos;
  final int indiceInicial;

  const TelaVisualizacaoFotos({super.key, required this.fotos, required this.indiceInicial});

  @override
  State<TelaVisualizacaoFotos> createState() => _TelaVisualizacaoFotosState();
}

class _TelaVisualizacaoFotosState extends State<TelaVisualizacaoFotos> {
  late PageController _pageController;
  late int _indiceAtual;

  @override
  void initState() {
    super.initState();
    _indiceAtual = widget.indiceInicial;
    _pageController = PageController(initialPage: widget.indiceInicial);
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.black,
      appBar: AppBar(
        backgroundColor: Colors.black,
        iconTheme: const IconThemeData(color: Colors.white),
        title: Text('${_indiceAtual + 1} de ${widget.fotos.length}', style: const TextStyle(color: Colors.white)),
      ),
      body: PageView.builder(
        controller: _pageController,
        itemCount: widget.fotos.length,
        onPageChanged: (index) => setState(() => _indiceAtual = index),
        itemBuilder: (context, index) {
          return InteractiveViewer(
            panEnabled: true,
            minScale: 0.5,
            maxScale: 4.0,
            child: CachedNetworkImage(
              imageUrl: widget.fotos[index],
              fit: BoxFit.contain,
              placeholder: (context, url) => const Center(child: CircularProgressIndicator(color: Colors.white)),
              errorWidget: (context, url, error) => const Icon(Icons.image_not_supported, color: Colors.grey, size: 80),
            ),
          );
        },
      ),
    );
  }
}