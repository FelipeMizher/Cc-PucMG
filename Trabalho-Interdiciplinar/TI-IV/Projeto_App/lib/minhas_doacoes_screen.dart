import 'package:flutter/material.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'lista_interessados_screen.dart';

class MinhasDoacoesScreen extends StatelessWidget {
  const MinhasDoacoesScreen({super.key});

  // Função para Atualizar o Status com POP-UP DE CONFIRMAÇÃO E AVISO NO CHAT
  Future<void> _marcarComoDoado(
    BuildContext context,
    String idDocumento,
  ) async {
    bool confirmar =
        await showDialog(
          context: context,
          builder: (context) => AlertDialog(
            title: const Text('Confirmar Doação?'),
            content: const Text(
              'Tem certeza que deseja marcar este item como doado?\n\nEssa ação NÃO PODE ser desfeita. O item sairá da lista de disponíveis do aplicativo.',
            ),
            actions: [
              TextButton(
                onPressed: () => Navigator.pop(context, false),
                child: const Text('Cancelar'),
              ),
              TextButton(
                onPressed: () => Navigator.pop(context, true),
                child: const Text(
                  'Sim, já doei',
                  style: TextStyle(
                    color: Colors.green,
                    fontWeight: FontWeight.bold,
                  ),
                ),
              ),
            ],
          ),
        ) ??
        false;

    if (confirmar) {
      // 1. Muda o status do item para "doado"
      await FirebaseFirestore.instance
          .collection('materiais')
          .doc(idDocumento)
          .update({'status': 'doado'});

      // 2. Busca todos os chats vinculados a este material
      final chatsSnapshot = await FirebaseFirestore.instance
          .collection('chats')
          .where('materialId', isEqualTo: idDocumento)
          .get();

      // 3. Envia uma "Mensagem do Sistema" para cada um desses chats
      for (var chatDoc in chatsSnapshot.docs) {
        await chatDoc.reference.collection('mensagens').add({
          'texto':
              'Este item foi marcado como DOADO pelo proprietário. O item não está mais disponível. Deseja encerrar este chat?',
          'remetenteId': 'SISTEMA', // ID especial para o app reconhecer!
          'dataHora': FieldValue.serverTimestamp(),
        });

        // Atualiza o último contato para essa mensagem de aviso subir pro topo da lista da pessoa
        await chatDoc.reference.update({
          'ultimoContato': FieldValue.serverTimestamp(),
        });
      }

      if (context.mounted) {
        ScaffoldMessenger.of(context).showSnackBar(
          const SnackBar(
            content: Text('Item marcado como doado com sucesso!'),
            backgroundColor: Colors.green,
          ),
        );
      }
    }
  }

  // Função para Excluir o Material (Delete do CRUD)
  Future<void> _excluirMaterial(
    BuildContext context,
    String idDocumento,
  ) async {
    // Mostra uma caixinha de confirmação antes de apagar
    bool confirmar =
        await showDialog(
          context: context,
          builder: (context) => AlertDialog(
            title: const Text('Excluir Material?'),
            content: const Text('Tem certeza que deseja apagar esta doação?'),
            actions: [
              TextButton(
                onPressed: () => Navigator.pop(context, false),
                child: const Text('Cancelar'),
              ),
              TextButton(
                onPressed: () => Navigator.pop(context, true),
                child: const Text(
                  'Excluir',
                  style: TextStyle(color: Colors.red),
                ),
              ),
            ],
          ),
        ) ??
        false;

    if (confirmar) {
      await FirebaseFirestore.instance
          .collection('materiais')
          .doc(idDocumento)
          .delete();
    }
  }

  @override
  Widget build(BuildContext context) {
    // Pega o ID do usuário logado neste momento
    final usuarioAtual = FirebaseAuth.instance.currentUser;

    return Scaffold(
      appBar: AppBar(
        title: const Text(
          'Gerenciar Minhas Doações',
          style: TextStyle(color: Colors.white),
        ),
        backgroundColor: Colors.blue.shade800,
        iconTheme: const IconThemeData(color: Colors.white),
      ),
      body: StreamBuilder<QuerySnapshot>(
        // Filtra apenas os materiais deste usuário!
        stream: FirebaseFirestore.instance
            .collection('materiais')
            .where('doadorId', isEqualTo: usuarioAtual?.uid)
            .snapshots(),
        builder: (context, snapshot) {
          if (snapshot.connectionState == ConnectionState.waiting) {
            return const Center(child: CircularProgressIndicator());
          }

          if (!snapshot.hasData || snapshot.data!.docs.isEmpty) {
            return const Center(
              child: Padding(
                padding: EdgeInsets.all(24.0),
                child: Text(
                  'Você ainda não cadastrou nenhuma doação.',
                  textAlign:
                      TextAlign.center, // Força o texto a ficar no meio da tela
                  style: TextStyle(fontSize: 18, color: Colors.grey),
                ),
              ),
            );
          }

          final meusMateriais = snapshot.data!.docs;

          return ListView.builder(
            padding: const EdgeInsets.all(16),
            itemCount: meusMateriais.length,
            itemBuilder: (context, index) {
              final material =
                  meusMateriais[index].data() as Map<String, dynamic>;
              final docId = meusMateriais[index]
                  .id; // O ID único do documento no Firebase
              final bool estaDisponivel = material['status'] == 'disponivel';

              return Card(
                elevation: 2,
                margin: const EdgeInsets.only(bottom: 16),
                child: Column(
                  children: [
                    ListTile(
                      title: Text(
                        material['titulo'] ?? '',
                        style: const TextStyle(
                          fontWeight: FontWeight.bold,
                          fontSize: 18,
                        ),
                      ),
                      subtitle: Text(
                        'Status: ${material['status'].toString().toUpperCase()}',
                      ),
                      trailing: IconButton(
                        icon: const Icon(Icons.delete, color: Colors.red),
                        onPressed: () => _excluirMaterial(context, docId),
                        tooltip: 'Excluir Doação',
                      ),
                    ),
                    const Divider(height: 1),
                    Padding(
                      padding: const EdgeInsets.symmetric(
                        horizontal: 8.0,
                        vertical: 8.0,
                      ),
                      child: Row(
                        mainAxisAlignment: MainAxisAlignment.spaceEvenly,
                        children: [
                          // Botão de Marcar como Doado (Só aparece se estiver disponível)
                          if (estaDisponivel)
                            TextButton.icon(
                              icon: const Icon(
                                Icons.check_circle,
                                color: Colors.green,
                              ),
                              label: const Text(
                                'Já Doei',
                                style: TextStyle(color: Colors.green),
                              ),
                              onPressed: () => _marcarComoDoado(context, docId),
                            ),

                          // Botão de Ver Interessados
                          TextButton.icon(
                            icon: const Icon(Icons.chat),
                            label: const Text('Ver Interessados'),
                            onPressed: () {
                              // Agora o botão navega para a lista de chats deste material!
                              Navigator.push(
                                context,
                                MaterialPageRoute(
                                  builder: (context) => ListaInteressadosScreen(
                                    materialId: docId,
                                    tituloMaterial:
                                        material['titulo'] ?? 'Material',
                                  ),
                                ),
                              );
                            },
                          ),
                        ],
                      ),
                    ),
                  ],
                ),
              );
            },
          );
        },
      ),
    );
  }
}
