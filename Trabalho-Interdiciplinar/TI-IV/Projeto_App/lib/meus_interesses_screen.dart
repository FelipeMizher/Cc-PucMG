import 'package:flutter/material.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'chat_screen.dart';

class MeusInteressesScreen extends StatelessWidget {
  const MeusInteressesScreen({super.key});

  @override
  Widget build(BuildContext context) {
    final usuarioAtual = FirebaseAuth.instance.currentUser;

    // O DefaultTabController é o que cria a mágica das "Abas" na tela
    return DefaultTabController(
      length: 2, // Temos 2 abas
      child: Scaffold(
        appBar: AppBar(
          title: const Text(
            'Central de Mensagens',
            style: TextStyle(color: Colors.white, fontWeight: FontWeight.bold),
          ),
          backgroundColor: Colors.blue.shade700,
          iconTheme: const IconThemeData(color: Colors.white),
          bottom: const TabBar(
            labelColor: Colors.white,
            unselectedLabelColor: Colors.white70,
            indicatorColor: Colors.white,
            indicatorWeight: 3,
            tabs: [
              Tab(icon: Icon(Icons.favorite), text: 'Meus Interesses'),
              Tab(icon: Icon(Icons.supervisor_account), text: 'Interessados'),
            ],
          ),
        ),
        // O TabBarView mostra o conteúdo de cada aba, na ordem
        body: TabBarView(
          children: [
            // ABA 1: Sou o interessado (Quero receber)
            _buildListaChats(
              uid: usuarioAtual?.uid ?? '',
              campoBusca: 'interessadoId',
              mensagemVazia:
                  'Você ainda não demonstrou interesse em nenhuma doação.',
              souDoador: false,
            ),

            // ABA 2: Sou o doador (Pessoas querendo meus itens)
            _buildListaChats(
              uid: usuarioAtual?.uid ?? '',
              campoBusca: 'doadorId',
              mensagemVazia:
                  'Ninguém entrou em contato sobre as suas doações ainda.',
              souDoador: true,
            ),
          ],
        ),
      ),
    );
  }

  // ==== FUNÇÃO REUTILIZÁVEL PARA CONSTRUIR AS DUAS LISTAS ====
  // Ao invés de escrever o StreamBuilder duas vezes, criamos essa função
  // que muda o comportamento dependendo de qual aba estamos
  Widget _buildListaChats({
    required String uid,
    required String campoBusca,
    required String mensagemVazia,
    required bool souDoador,
  }) {
    return StreamBuilder<QuerySnapshot>(
      // Ele usa o 'campoBusca'
      stream: FirebaseFirestore.instance
          .collection('chats')
          .where(campoBusca, isEqualTo: uid)
          .snapshots(),
      builder: (context, snapshot) {
        if (snapshot.hasError) {
          return Center(child: Text('Erro: ${snapshot.error}'));
        }

        if (snapshot.connectionState == ConnectionState.waiting) {
          return const Center(child: CircularProgressIndicator());
        }

        if (!snapshot.hasData || snapshot.data!.docs.isEmpty) {
          return Center(
            child: Padding(
              padding: const EdgeInsets.all(24.0),
              child: Text(
                mensagemVazia,
                textAlign: TextAlign.center,
                style: const TextStyle(fontSize: 16, color: Colors.grey),
              ),
            ),
          );
        }

        final meusChats = snapshot.data!.docs;

        return ListView.builder(
          padding: const EdgeInsets.all(16),
          itemCount: meusChats.length,
          itemBuilder: (context, index) {
            final chat = meusChats[index].data() as Map<String, dynamic>;
            final chatId = meusChats[index].id;

            final tituloMaterial =
                chat['materialTitulo'] ?? 'Material sem título';
            final nomeInteressado = chat['interessadoNome'] ?? 'Alguém';

            // Inteligência Visual: Muda os textos dependendo de quem está lendo
            final tituloPrincipal = souDoador
                ? '$nomeInteressado quer seu item'
                : tituloMaterial;
            final subtitulo = souDoador
                ? 'Item: $tituloMaterial'
                : 'Toque para continuar a conversa';
            final icone = souDoador
                ? Icons.mark_email_unread
                : Icons.chat_bubble;
            final corBase = souDoador ? Colors.orange : Colors.green;

            return Card(
              elevation: 2,
              margin: const EdgeInsets.only(bottom: 12),
              shape: RoundedRectangleBorder(
                borderRadius: BorderRadius.circular(15),
              ),
              child: ListTile(
                contentPadding: const EdgeInsets.symmetric(
                  horizontal: 16,
                  vertical: 8,
                ),
                leading: CircleAvatar(
                  backgroundColor: corBase.withValues(alpha: 0.2),
                  radius: 25,
                  child: Icon(icone, color: corBase),
                ),
                title: Text(
                  tituloPrincipal,
                  style: const TextStyle(
                    fontWeight: FontWeight.bold,
                    fontSize: 16,
                  ),
                ),
                subtitle: Padding(
                  padding: const EdgeInsets.only(top: 4.0),
                  child: Text(subtitulo),
                ),
                trailing: const Icon(Icons.chevron_right, color: Colors.grey),
                onTap: () {
                  Navigator.push(
                    context,
                    MaterialPageRoute(
                      builder: (context) => ChatScreen(
                        chatId: chatId,
                        tituloMaterial: tituloMaterial,
                      ),
                    ),
                  );
                },
              ),
            );
          },
        );
      },
    );
  }
}
