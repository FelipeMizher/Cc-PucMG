import 'dart:async';
import 'package:flutter/material.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:shared_preferences/shared_preferences.dart';
import 'package:connectivity_plus/connectivity_plus.dart';
import 'package:cached_network_image/cached_network_image.dart';
import 'detalhes_material_screen.dart';
import 'local_database.dart';

class FeedDoacoesScreen extends StatefulWidget {
  const FeedDoacoesScreen({super.key});

  @override
  State<FeedDoacoesScreen> createState() => _FeedDoacoesScreenState();
}

class _FeedDoacoesScreenState extends State<FeedDoacoesScreen> {
  String _textoBusca = '';
  String _categoriaSelecionada = 'Todos';

  // ==== NOVO FILTRO DE FAVORITOS ADICIONADO ====
  final List<String> _categorias = ['Todos', 'Favoritos', 'Livros', 'Cadernos', 'Mochilas', 'Uniformes', 'Outros'];

  bool _isOffline = false;
  late StreamSubscription<List<ConnectivityResult>> _connectivitySubscription;

  @override
  void initState() {
    super.initState();
    _checarInternetInicial();
    _monitorarInternet();
    _carregarUltimaCategoria();
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
        // Se estiver offline, força o filtro para Favoritos para não tentar ler o Firebase
        if (_isOffline) _categoriaSelecionada = 'Favoritos';
      });
    }
  }

  void _monitorarInternet() {
    _connectivitySubscription = Connectivity().onConnectivityChanged.listen((List<ConnectivityResult> results) {
      if (mounted) {
        setState(() {
          _isOffline = results.contains(ConnectivityResult.none);
          if (_isOffline) _categoriaSelecionada = 'Favoritos';
        });
      }
    });
  }

  Future<void> _carregarUltimaCategoria() async {
    final prefs = await SharedPreferences.getInstance();
    setState(() {
      // Se estiver offline, ignora a última memória e finca no filtro Favoritos
      _categoriaSelecionada = _isOffline ? 'Favoritos' : (prefs.getString('ultima_categoria') ?? 'Todos');
    });
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.grey.shade50,
      appBar: AppBar(
        title: const Text('Materiais Disponíveis', style: TextStyle(color: Colors.white, fontWeight: FontWeight.bold)),
        backgroundColor: _isOffline ? Colors.red.shade700 : Colors.blue.shade700,
        iconTheme: const IconThemeData(color: Colors.white),
        elevation: 0,
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
                  Icon(Icons.wifi_off, color: Colors.white, size: 18),
                  SizedBox(width: 8),
                  Text(
                    'Você está offline. Mostrando apenas favoritos.',
                    style: TextStyle(color: Colors.white, fontWeight: FontWeight.bold),
                  ),
                ],
              ),
            ),

          // Barra de Pesquisa (Funciona filtrando favoritos em modo offline)
          Container(
            color: _isOffline ? Colors.red.shade700 : Colors.blue.shade700,
            padding: const EdgeInsets.fromLTRB(16, 0, 16, 16),
            child: TextField(
              onChanged: (valor) => setState(() => _textoBusca = valor.toLowerCase()),
              decoration: InputDecoration(
                hintText: 'O que você está procurando?',
                prefixIcon: const Icon(Icons.search, color: Colors.grey),
                filled: true,
                fillColor: Colors.white,
                border: OutlineInputBorder(borderRadius: BorderRadius.circular(30), borderSide: BorderSide.none),
                contentPadding: const EdgeInsets.symmetric(vertical: 0),
              ),
            ),
          ),

          // Filtros de Categoria
          Container(
            height: 60,
            color: Colors.white,
            child: ListView.builder(
              scrollDirection: Axis.horizontal,
              padding: const EdgeInsets.symmetric(horizontal: 16, vertical: 10),
              itemCount: _categorias.length,
              itemBuilder: (context, index) {
                final categoria = _categorias[index];
                final bool isSelecionado = _categoriaSelecionada == categoria;

                // Desabilita os outros filtros se o usuário estiver offline (forçando ele a ficar na aba Favoritos)
                final bool desabilitarChip = _isOffline && categoria != 'Favoritos';

                return Padding(
                  padding: const EdgeInsets.only(right: 8.0),
                  child: ChoiceChip(
                    label: Text(categoria),
                    selected: isSelecionado,
                    selectedColor: _isOffline ? Colors.red.shade100 : Colors.blue.shade100,
                    labelStyle: TextStyle(
                      color: isSelecionado ? (_isOffline ? Colors.red.shade800 : Colors.blue.shade800) : (desabilitarChip ? Colors.grey : Colors.black87),
                      fontWeight: isSelecionado ? FontWeight.bold : FontWeight.normal,
                    ),
                    onSelected: desabilitarChip ? null : (selecionado) async {
                      setState(() => _categoriaSelecionada = categoria);
                      final prefs = await SharedPreferences.getInstance();
                      await prefs.setString('ultima_categoria', categoria);
                    },
                  ),
                );
              },
            ),
          ),

          const Divider(height: 1, thickness: 1),

          // Seleção da Lista com base na internet e no filtro
          Expanded(
            child: (_isOffline || _categoriaSelecionada == 'Favoritos')
                ? _buildListaOfflineSQLite()
                : _buildListaOnlineFirebase(),
          ),
        ],
      ),
    );
  }

  // ==== MOTOR OFFLINE / FILTRO FAVORITOS (Lê do SQLite) ====
  Widget _buildListaOfflineSQLite() {
    return FutureBuilder<List<Map<String, dynamic>>>(
      future: DatabaseHelper.instance.buscarTodosFavoritos(),
      builder: (context, snapshot) {
        if (snapshot.connectionState == ConnectionState.waiting) {
          return const Center(child: CircularProgressIndicator());
        }

        if (!snapshot.hasData || snapshot.data!.isEmpty) {
          return _buildTelaVazia('Nenhum material salvo nos favoritos.');
        }

        var favoritosOffline = snapshot.data!;

        // Filtro de texto local na lista offline
        if (_textoBusca.isNotEmpty) {
          favoritosOffline = favoritosOffline.where((item) {
            final titulo = (item['titulo'] ?? '').toString().toLowerCase();
            return titulo.contains(_textoBusca);
          }).toList();
        }

        return ListView.builder(
          padding: const EdgeInsets.all(16),
          itemCount: favoritosOffline.length,
          itemBuilder: (context, index) {
            final item = favoritosOffline[index];
            final String urlCapa = item['fotoUrl'] ?? '';

            // Remapeia os dados do SQLite de volta para a estrutura que a tela de Detalhes espera
            final Map<String, dynamic> materialConvertido = {
              'titulo': item['titulo'],
              'categoria': item['categoria'],
              'fotos': urlCapa.isNotEmpty ? [urlCapa] : [],
              'descricao': item['descricao'] ?? 'Item disponível em seus favoritos offline.',
              'doadorId': item['doadorId'] ?? '',
              'status': 'disponivel',
              'latitude': item['latitude'],
              'longitude': item['longitude'],
            };

            return _buildCardMaterial(
              idDocumento: item['id'],
              titulo: item['titulo'],
              categoria: item['categoria'],
              descricao: item['descricao'] ?? 'Salvo Offline',
              urlCapa: urlCapa,
              materialMapData: materialConvertido,
            );
          },
        );
      },
    );
  }

  // ==== MOTOR ONLINE (Lê do Firebase) ====
  Widget _buildListaOnlineFirebase() {
    return StreamBuilder<QuerySnapshot>(
      stream: _categoriaSelecionada == 'Todos'
          ? FirebaseFirestore.instance.collection('materiais').where('status', isEqualTo: 'disponivel').snapshots()
          : FirebaseFirestore.instance.collection('materiais').where('status', isEqualTo: 'disponivel').where('categoria', isEqualTo: _categoriaSelecionada).snapshots(),
      builder: (context, snapshot) {
        if (snapshot.connectionState == ConnectionState.waiting) return const Center(child: CircularProgressIndicator());
        if (snapshot.hasError) return Center(child: Text('Erro ao carregar dados: ${snapshot.error}'));
        if (!snapshot.hasData || snapshot.data!.docs.isEmpty) return _buildTelaVazia('Nenhum material encontrado.');

        var materiais = snapshot.data!.docs;

        if (_textoBusca.isNotEmpty) {
          materiais = materiais.where((doc) {
            final titulo = (doc['titulo'] ?? '').toString().toLowerCase();
            return titulo.contains(_textoBusca);
          }).toList();
        }

        if (materiais.isEmpty) return _buildTelaVazia('Nenhum resultado para "$_textoBusca".');

        return ListView.builder(
          padding: const EdgeInsets.all(16),
          itemCount: materiais.length,
          itemBuilder: (context, index) {
            final material = materiais[index].data() as Map<String, dynamic>;
            final idDocumento = materiais[index].id;
            final List fotos = material['fotos'] ?? [];
            final String urlCapa = fotos.isNotEmpty ? fotos[0] : '';

            return _buildCardMaterial(
              idDocumento: idDocumento,
              titulo: material['titulo'] ?? 'Sem Título',
              categoria: material['categoria'] ?? 'Sem Categoria',
              descricao: material['descricao'] ?? '',
              urlCapa: urlCapa,
              materialMapData: material,
            );
          },
        );
      },
    );
  }

  Widget _buildCardMaterial({
    required String idDocumento,
    required String titulo,
    required String categoria,
    required String descricao,
    required String urlCapa,
    required Map<String, dynamic> materialMapData,
  }) {
    return Card(
      elevation: 2,
      margin: const EdgeInsets.only(bottom: 16),
      shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(15)),
      clipBehavior: Clip.antiAlias,
      child: InkWell(
        // ==== CARREGAMENTO OFFLINE DISPONÍVEL SIM! ====
        onTap: () {
          Navigator.push(
            context,
            MaterialPageRoute(
              builder: (context) => DetalhesMaterialScreen(
                materialId: idDocumento,
                material: materialMapData,
              ),
            ),
          );
        },
        child: Row(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            Container(
              width: 120,
              height: 120,
              color: Colors.grey.shade200,
              child: urlCapa.isNotEmpty
                  ? CachedNetworkImage(
                imageUrl: urlCapa,
                fit: BoxFit.cover,
                placeholder: (context, url) => const Center(child: CircularProgressIndicator(strokeWidth: 2)),
                errorWidget: (context, url, error) => const Icon(Icons.image_not_supported, color: Colors.grey, size: 40),
              )
                  : const Icon(Icons.image_not_supported, color: Colors.grey, size: 40),
            ),
            Expanded(
              child: Padding(
                padding: const EdgeInsets.all(12.0),
                child: Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [
                    Row(
                      mainAxisAlignment: MainAxisAlignment.spaceBetween,
                      crossAxisAlignment: CrossAxisAlignment.start,
                      children: [
                        Container(
                          padding: const EdgeInsets.symmetric(horizontal: 8, vertical: 4),
                          decoration: BoxDecoration(color: Colors.blue.shade50, borderRadius: BorderRadius.circular(8)),
                          child: Text(categoria, style: TextStyle(fontSize: 10, fontWeight: FontWeight.bold, color: Colors.blue.shade700)),
                        ),
                        FutureBuilder<bool>(
                          future: DatabaseHelper.instance.isFavoritado(idDocumento),
                          builder: (context, snapshotLocal) {
                            final bool favoritado = snapshotLocal.data ?? false;
                            return GestureDetector(
                              onTap: () async {
                                if (favoritado) {
                                  await DatabaseHelper.instance.removerFavorito(idDocumento);
                                } else {
                                  await DatabaseHelper.instance.adicionarFavorito(materialMapData, idDocumento);
                                }
                                setState(() {});
                              },
                              child: Icon(
                                favoritado ? Icons.star : Icons.star_border,
                                color: favoritado ? Colors.amber : Colors.grey,
                                size: 26,
                              ),
                            );
                          },
                        ),
                      ],
                    ),
                    const SizedBox(height: 4),
                    Text(titulo, style: const TextStyle(fontSize: 16, fontWeight: FontWeight.bold), maxLines: 2, overflow: TextOverflow.ellipsis),
                    const SizedBox(height: 4),
                    Text(descricao, style: TextStyle(fontSize: 13, color: Colors.grey.shade600), maxLines: 1, overflow: TextOverflow.ellipsis),
                  ],
                ),
              ),
            )
          ],
        ),
      ),
    );
  }

  Widget _buildTelaVazia(String mensagem) {
    return Center(
      child: Padding(
        padding: const EdgeInsets.all(32.0),
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            Icon(Icons.search_off, size: 80, color: Colors.grey.shade400),
            const SizedBox(height: 16),
            Text(mensagem, textAlign: TextAlign.center, style: TextStyle(fontSize: 16, color: Colors.grey.shade600)),
          ],
        ),
      ),
    );
  }
}