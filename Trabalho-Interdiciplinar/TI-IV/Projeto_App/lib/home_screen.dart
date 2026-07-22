import 'dart:async';
import 'package:flutter/material.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:connectivity_plus/connectivity_plus.dart'; // Detecta internet
import 'login_screen.dart';
import 'cadastro_material_screen.dart';
import 'feed_doacoes_screen.dart';
import 'minhas_doacoes_screen.dart';
import 'meus_interesses_screen.dart';
import 'perfil_screen.dart';
import 'mapa_screen.dart';
import 'sobre_screen.dart';

class HomeScreen extends StatefulWidget {
  const HomeScreen({super.key});

  @override
  State<HomeScreen> createState() => _HomeScreenState();
}

class _HomeScreenState extends State<HomeScreen> {
  // ==== CONTROLES DE INTERNET ====
  bool _isOffline = false;
  late StreamSubscription<List<ConnectivityResult>> _connectivitySubscription;

  @override
  void initState() {
    super.initState();
    _checarInternetInicial();
    _monitorarInternet();
  }

  // Função para evitar o delay do primeiro carregamento offline
  Future<void> _checarInternetInicial() async {
    final result = await Connectivity().checkConnectivity();
    if (mounted) {
      setState(() {
        _isOffline = result.contains(ConnectivityResult.none);
      });
    }
  }

  @override
  void dispose() {
    _connectivitySubscription.cancel(); // Evita vazamento de memória ao fechar a tela
    super.dispose();
  }

  // ==== DETECTOR DE INTERNET ====
  void _monitorarInternet() {
    _connectivitySubscription = Connectivity().onConnectivityChanged.listen((List<ConnectivityResult> results) {
      if (mounted) {
        setState(() {
          // Se o resultado for "none", estamos sem internet
          _isOffline = results.contains(ConnectivityResult.none);
        });
      }
    });
  }

  Future<void> _sair() async {
    await FirebaseAuth.instance.signOut();
  }

  @override
  Widget build(BuildContext context) {
    // O StreamBuilder "escuta" em tempo real se o usuário está logado ou não
    return StreamBuilder<User?>(
        stream: FirebaseAuth.instance.authStateChanges(),
        builder: (context, snapshot) {
          final bool isLogado = snapshot.hasData; // Verifica se tem alguém logado

          // ==== FUNÇÃO DE BLOQUEIO (AGORA COM PROTEÇÃO OFFLINE) ====
          // Redireciona pro Login se não tiver conta, ou abre a tela se tiver
          void executarAcaoProtegida(Widget telaDestino, {bool exigeInternet = false}) {
            if (exigeInternet && _isOffline) {
              ScaffoldMessenger.of(context).showSnackBar(
                  const SnackBar(content: Text('Esta ação exige conexão com a internet!'), backgroundColor: Colors.red)
              );
              return; // Bloqueia a ação se estiver offline e a tela exigir internet
            }

            if (isLogado) {
              Navigator.push(context, MaterialPageRoute(builder: (context) => telaDestino));
            } else {
              ScaffoldMessenger.of(context).showSnackBar(
                  const SnackBar(content: Text('Faça login ou cadastre-se para acessar esta área!'), backgroundColor: Colors.orange)
              );
              Navigator.push(context, MaterialPageRoute(builder: (context) => const LoginScreen()));
            }
          }

          return Scaffold(
            backgroundColor: Colors.grey.shade50,
            appBar: AppBar(
              title: const Text('EloEscolar', style: TextStyle(color: Colors.white, fontWeight: FontWeight.bold)),
              // ==== MUDA A COR DA APPBAR SE ESTIVER OFFLINE ====
              backgroundColor: _isOffline ? Colors.red.shade700 : Colors.blue.shade700,
              elevation: 0,
              actions: [
                IconButton(
                  icon: const Icon(Icons.info_outline, color: Colors.white),
                  tooltip: 'Sobre o EloEscolar',
                  onPressed: () => Navigator.push(context, MaterialPageRoute(builder: (context) => const SobreScreen())),
                ),
                if (isLogado) ...[
                  IconButton(
                    icon: const Icon(Icons.account_circle, color: Colors.white, size: 28),
                    tooltip: 'Meu Perfil',
                    onPressed: () => Navigator.push(context, MaterialPageRoute(builder: (context) => const PerfilScreen())),
                  ),
                  IconButton(
                    icon: const Icon(Icons.logout, color: Colors.white),
                    tooltip: 'Sair da conta',
                    onPressed: _sair,
                  ),
                ] else ...[
                  // Se NÃO estiver logado, mostra o botão de Entrar
                  TextButton.icon(
                    onPressed: () => Navigator.push(context, MaterialPageRoute(builder: (context) => const LoginScreen())),
                    icon: const Icon(Icons.login, color: Colors.white),
                    label: const Text('Entrar', style: TextStyle(color: Colors.white, fontWeight: FontWeight.bold)),
                  ),
                ],
                const SizedBox(width: 8),
              ],
            ),
            body: SafeArea(
              child: SingleChildScrollView(
                child: Column(
                  crossAxisAlignment: CrossAxisAlignment.stretch,
                  children: [
                    // ==== INDICADOR OFFLINE ====
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
                              'Modo Offline ativado',
                              style: TextStyle(color: Colors.white, fontWeight: FontWeight.bold),
                            ),
                          ],
                        ),
                      ),

                    Padding(
                      padding: const EdgeInsets.all(24.0),
                      child: Column(
                        crossAxisAlignment: CrossAxisAlignment.start,
                        children: [
                          Text(
                            isLogado ? 'Olá!' : 'Bem-vindo(a)!',
                            style: TextStyle(fontSize: 32, fontWeight: FontWeight.bold, color: _isOffline ? Colors.red.shade800 : Colors.blue.shade800),
                          ),
                          const SizedBox(height: 4),
                          const Text('Como você vai transformar a educação hoje?', style: TextStyle(fontSize: 16, color: Colors.grey)),
                          const SizedBox(height: 32),

                          Row(
                            children: [
                              // Ação PROTEGIDA (Apenas quem estiver logado E com internet)
                              Expanded(
                                child: _buildCardPrincipal(
                                  context,
                                  'Quero Doar',
                                  Icons.favorite,
                                  Colors.blue,
                                      () => executarAcaoProtegida(const CadastroMaterialScreen(), exigeInternet: true),
                                  isDesabilitado: _isOffline, // Fica cinza se não tiver internet
                                ),
                              ),
                              const SizedBox(width: 16),
                              // Ação LIVRE (Qualquer um pode ver, muda o nome se offline)
                              Expanded(
                                child: _buildCardPrincipal(
                                  context,
                                  _isOffline ? 'Ver salvos' : 'Buscar Doações', // ==== TEXTO DINÂMICO ====
                                  _isOffline ? Icons.star : Icons.search,
                                  _isOffline ? Colors.orange : Colors.green, // Muda a cor levemente para chamar atenção aos favoritos
                                      () => Navigator.push(context, MaterialPageRoute(builder: (context) => const FeedDoacoesScreen())),
                                  isDesabilitado: false, // Esse botão nunca é desabilitado
                                ),
                              ),
                            ],
                          ),
                          const SizedBox(height: 24),

                          // Ação LIVRE (Qualquer um pode ver o mapa, MAS exige internet)
                          _buildBannerMapa(context),

                          const SizedBox(height: 32),

                          const Text('Minha Conta', style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold, color: Colors.black87)),
                          const SizedBox(height: 12),

                          // Ações PROTEGIDAS (Exigem internet para carregar os dados novos)
                          _buildBotaoLista(context, 'Minhas Conversas', Icons.forum_outlined, Colors.purple, () => executarAcaoProtegida(const MeusInteressesScreen(), exigeInternet: true), _isOffline),
                          const SizedBox(height: 12),
                          _buildBotaoLista(context, 'Gerenciar Minhas Doações', Icons.settings_outlined, Colors.grey.shade700, () => executarAcaoProtegida(const MinhasDoacoesScreen(), exigeInternet: true), _isOffline),
                        ],
                      ),
                    ),
                  ],
                ),
              ),
            ),
          );
        }
    );
  }

  // ==== CARD PRINCIPAL (Agora suporta visual "desabilitado") ====
  Widget _buildCardPrincipal(BuildContext context, String titulo, IconData icone, MaterialColor cor, VoidCallback acao, {bool isDesabilitado = false}) {
    final MaterialColor corMaterialAtiva = isDesabilitado ? Colors.grey : cor;

    return InkWell(
      onTap: acao,
      borderRadius: BorderRadius.circular(20),
      child: Container(
        padding: const EdgeInsets.symmetric(vertical: 24),
        decoration: BoxDecoration(
          color: isDesabilitado ? Colors.grey.shade200 : Colors.white,
          borderRadius: BorderRadius.circular(20),
          boxShadow: [
            if (!isDesabilitado) BoxShadow(color: cor.withValues(alpha: 0.15), blurRadius: 15, offset: const Offset(0, 5))
          ],
          border: Border.all(color: corMaterialAtiva.shade100, width: 2),
        ),
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          children: [
            CircleAvatar(
                backgroundColor: corMaterialAtiva.shade50,
                radius: 30,
                child: Icon(icone, size: 32, color: corMaterialAtiva.shade600)
            ),
            const SizedBox(height: 16),
            Text(
                titulo,
                style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold, color: corMaterialAtiva.shade700)
            ),
          ],
        ),
      ),
    );
  }

  // ==== BANNER DO MAPA (Agora suporta visual "desabilitado") ====
  Widget _buildBannerMapa(BuildContext context) {
    return InkWell(
      onTap: () {
        if (_isOffline) {
          ScaffoldMessenger.of(context).showSnackBar(
              const SnackBar(content: Text('O mapa exige conexão com a internet!'), backgroundColor: Colors.red)
          );
          return;
        }
        Navigator.push(context, MaterialPageRoute(builder: (context) => const MapaScreen()));
      },
      borderRadius: BorderRadius.circular(20),
      child: Container(
        padding: const EdgeInsets.all(20),
        decoration: BoxDecoration(
          gradient: LinearGradient(
              colors: _isOffline
                  ? [Colors.grey.shade400, Colors.grey.shade500] // Cinza se offline
                  : [Colors.amber.shade400, Colors.orange.shade500],
              begin: Alignment.topLeft,
              end: Alignment.bottomRight
          ),
          borderRadius: BorderRadius.circular(20),
          boxShadow: [
            if (!_isOffline) BoxShadow(color: Colors.orange.withValues(alpha: 0.3), blurRadius: 10, offset: const Offset(0, 4))
          ],
        ),
        child: Row(
          children: [
            Container(
                padding: const EdgeInsets.all(12),
                decoration: BoxDecoration(color: Colors.white.withValues(alpha: 0.3), shape: BoxShape.circle),
                child: Icon(_isOffline ? Icons.location_off : Icons.map, size: 32, color: Colors.white) // Muda o ícone
            ),
            const SizedBox(width: 16),
            Expanded(child: Column(crossAxisAlignment: CrossAxisAlignment.start, children: [
              Text('Mapa de Doações', style: const TextStyle(fontSize: 20, fontWeight: FontWeight.bold, color: Colors.white)),
              const SizedBox(height: 4),
              Text(
                  _isOffline ? 'Indisponível offline' : 'Encontre materiais perto de você',
                  style: const TextStyle(fontSize: 14, color: Colors.white)
              ),
            ])),
            const Icon(Icons.arrow_forward_ios, color: Colors.white, size: 16),
          ],
        ),
      ),
    );
  }

  // ==== BOTÃO DA LISTA (Agora suporta visual "desabilitado") ====
  Widget _buildBotaoLista(BuildContext context, String titulo, IconData icone, Color cor, VoidCallback acao, bool isDesabilitado) {
    return InkWell(
      onTap: acao,
      borderRadius: BorderRadius.circular(15),
      child: Container(
        padding: const EdgeInsets.symmetric(horizontal: 16, vertical: 16),
        decoration: BoxDecoration(
            color: isDesabilitado ? Colors.grey.shade100 : Colors.white,
            borderRadius: BorderRadius.circular(15),
            boxShadow: const [BoxShadow(color: Colors.black12, blurRadius: 4, offset: Offset(0, 2))]
        ),
        child: Row(
          children: [
            Icon(isDesabilitado ? Icons.cloud_off : icone, color: isDesabilitado ? Colors.grey : cor, size: 28),
            const SizedBox(width: 16),
            Expanded(child: Text(titulo, style: TextStyle(fontSize: 16, fontWeight: FontWeight.w600, color: isDesabilitado ? Colors.grey : Colors.black))),
            Icon(Icons.chevron_right, color: isDesabilitado ? Colors.grey.shade400 : Colors.grey),
          ],
        ),
      ),
    );
  }
}