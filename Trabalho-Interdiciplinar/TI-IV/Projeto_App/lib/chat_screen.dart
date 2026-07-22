import 'dart:async';
import 'package:flutter/material.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:firebase_auth/firebase_auth.dart';

class ChatScreen extends StatefulWidget {
  final String chatId;
  final String tituloMaterial;

  const ChatScreen({
    super.key,
    required this.chatId,
    required this.tituloMaterial,
  });

  @override
  State<ChatScreen> createState() => _ChatScreenState();
}

class _ChatScreenState extends State<ChatScreen> {
  final _mensagemController = TextEditingController();
  final _usuarioAtual = FirebaseAuth.instance.currentUser;

  Timer? _timerDigitando;
  String? _meuNome;
  String? _fotoPerfilOutroUsuario;

  @override
  void initState() {
    super.initState();
    _buscarMeuNome();
    _buscarDadosDoOutroUsuario();
  }

  @override
  void dispose() {
    _timerDigitando?.cancel();
    _pararDeDigitar();
    _mensagemController.dispose();
    super.dispose();
  }

  Future<void> _buscarDadosDoOutroUsuario() async {
    if (_usuarioAtual == null) return;

    try {
      final chatDoc = await FirebaseFirestore.instance.collection('chats').doc(widget.chatId).get();
      if (!chatDoc.exists) return;

      final doadorId = chatDoc.data()?['doadorId'];
      final interessadoId = chatDoc.data()?['interessadoId'];
      final outroUsuarioId = _usuarioAtual.uid == doadorId ? interessadoId : doadorId;

      final userDoc = await FirebaseFirestore.instance.collection('usuarios').doc(outroUsuarioId).get();

      if (mounted) {
        setState(() {
          _fotoPerfilOutroUsuario = userDoc.data()?['fotoPerfil'];
        });
      }
    } catch (e) {
      debugPrint('Erro ao buscar foto: $e');
    }
  }

  Future<void> _buscarMeuNome() async {
    if (_usuarioAtual != null) {
      final doc = await FirebaseFirestore.instance.collection('usuarios').doc(_usuarioAtual.uid).get();
      if (mounted) {
        setState(() {
          _meuNome = doc.data()?['nome'] ?? 'Usuário';
        });
      }
    }
  }

  void _aoDigitar(String texto) {
    if (_meuNome == null || _usuarioAtual == null) return;

    FirebaseFirestore.instance.collection('chats').doc(widget.chatId).set({
      'digitando': {_usuarioAtual.uid: _meuNome},
    }, SetOptions(merge: true));

    _timerDigitando?.cancel();
    _timerDigitando = Timer(const Duration(seconds: 2), _pararDeDigitar);
  }

  void _pararDeDigitar() {
    if (_usuarioAtual == null) return;

    FirebaseFirestore.instance.collection('chats').doc(widget.chatId).set({
      'digitando': {_usuarioAtual.uid: FieldValue.delete()},
    }, SetOptions(merge: true));
  }

  Future<void> _enviarMensagem() async {
    final texto = _mensagemController.text.trim();
    if (texto.isEmpty) return;

    _mensagemController.clear();

    try {
      final usuarioAtual = FirebaseAuth.instance.currentUser;
      await FirebaseFirestore.instance
          .collection('chats')
          .doc(widget.chatId)
          .collection('mensagens')
          .add({
        'texto': texto,
        'remetenteId': usuarioAtual!.uid,
        'dataHora': FieldValue.serverTimestamp(),
      });

      await FirebaseFirestore.instance.collection('chats').doc(widget.chatId).update({
        'ultimoContato': FieldValue.serverTimestamp(),
      });
    } catch (e) {
      if (mounted) {
        ScaffoldMessenger.of(context).showSnackBar(SnackBar(content: Text('Erro ao enviar: $e'), backgroundColor: Colors.red));
      }
    }
  }

  Future<void> _encerrarChat() async {
    bool confirmar = await showDialog(
      context: context,
      builder: (context) => AlertDialog(
        title: const Row(
          children: [
            Icon(Icons.warning_amber_rounded, color: Colors.red),
            SizedBox(width: 10),
            Text('Encerrar Chat?'),
          ],
        ),
        content: const Text('Esta conversa será apagada permanentemente.'),
        actions: [
          TextButton(onPressed: () => Navigator.pop(context, false), child: const Text('Cancelar')),
          ElevatedButton(
            onPressed: () => Navigator.pop(context, true),
            style: ElevatedButton.styleFrom(backgroundColor: Colors.red, foregroundColor: Colors.white),
            child: const Text('Sim, Encerrar'),
          ),
        ],
      ),
    ) ?? false;

    if (confirmar) {
      await FirebaseFirestore.instance.collection('chats').doc(widget.chatId).delete();
      if (mounted) {
        Navigator.pop(context);
        ScaffoldMessenger.of(context).showSnackBar(const SnackBar(content: Text('Chat removido.'), backgroundColor: Colors.grey));
      }
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.grey.shade100,
      appBar: AppBar(
        title: Text(widget.tituloMaterial, style: const TextStyle(color: Colors.white)),
        backgroundColor: Colors.blue,
        iconTheme: const IconThemeData(color: Colors.white),
        actions: [
          IconButton(icon: const Icon(Icons.delete_outline, color: Colors.white), onPressed: _encerrarChat),
        ],
      ),
      body: Column(
        children: [
          Expanded(
            child: StreamBuilder<QuerySnapshot>(
              stream: FirebaseFirestore.instance
                  .collection('chats')
                  .doc(widget.chatId)
                  .collection('mensagens')
                  .orderBy('dataHora', descending: true)
                  .snapshots(),
              builder: (context, snapshot) {
                if (snapshot.connectionState == ConnectionState.waiting) {
                  return const Center(child: CircularProgressIndicator());
                }
                if (!snapshot.hasData || snapshot.data!.docs.isEmpty) {
                  return const Center(child: Text('Nenhuma mensagem. Diga olá!', style: TextStyle(color: Colors.grey)));
                }

                final mensagens = snapshot.data!.docs;

                return ListView.builder(
                  reverse: true,
                  padding: const EdgeInsets.all(16),
                  itemCount: mensagens.length,
                  itemBuilder: (context, index) {
                    final msg = mensagens[index].data() as Map<String, dynamic>;
                    final bool isSistema = msg['remetenteId'] == 'SISTEMA';
                    final bool souEu = msg['remetenteId'] == _usuarioAtual?.uid;

                    if (isSistema) {
                      return Container(
                        margin: const EdgeInsets.symmetric(vertical: 24, horizontal: 8),
                        padding: const EdgeInsets.all(20),
                        decoration: BoxDecoration(
                          color: Colors.orange.shade50,
                          borderRadius: BorderRadius.circular(15),
                          border: Border.all(color: Colors.orange.shade300, width: 2),
                        ),
                        child: Column(
                          children: [
                            const Icon(Icons.info_outline, color: Colors.orange, size: 40),
                            const SizedBox(height: 12),
                            Text(
                              msg['texto'] ?? '',
                              textAlign: TextAlign.center,
                              style: TextStyle(fontSize: 16, fontWeight: FontWeight.bold, color: Colors.orange.shade900),
                            ),
                            const SizedBox(height: 16),
                            SizedBox(
                              width: double.infinity,
                              child: ElevatedButton.icon(
                                onPressed: _encerrarChat,
                                icon: const Icon(Icons.delete_forever),
                                label: const Text('Encerrar Chat'),
                                style: ElevatedButton.styleFrom(backgroundColor: Colors.red, foregroundColor: Colors.white),
                              ),
                            ),
                          ],
                        ),
                      );
                    }

                    bool temFotoValida = _fotoPerfilOutroUsuario != null && _fotoPerfilOutroUsuario!.trim().isNotEmpty;

                    return Padding(
                      padding: const EdgeInsets.symmetric(vertical: 4),
                      child: Row(
                        mainAxisAlignment: souEu ? MainAxisAlignment.end : MainAxisAlignment.start,
                        crossAxisAlignment: CrossAxisAlignment.end,
                        children: [
                          if (!souEu) ...[
                            // ==== A FOTO EXPANSÍVEL ====
                            GestureDetector(
                              onTap: () {
                                // Só expande se o usuário tiver uma foto real
                                if (temFotoValida) {
                                  Navigator.push(
                                    context,
                                    MaterialPageRoute(
                                      builder: (context) => TelaFotoPerfilCheia(
                                        urlFoto: _fotoPerfilOutroUsuario!,
                                      ),
                                    ),
                                  );
                                }
                              },
                              child: Hero(
                                // A 'tag' deve ser única para a animação funcionar.
                                // Usamos a própria URL da foto como tag.
                                tag: _fotoPerfilOutroUsuario ?? 'avatar_placeholder',
                                child: CircleAvatar(
                                  radius: 16,
                                  backgroundColor: Colors.blue.shade100,
                                  backgroundImage: temFotoValida ? NetworkImage(_fotoPerfilOutroUsuario!) : null,
                                  child: !temFotoValida ? Icon(Icons.person, size: 20, color: Colors.blue.shade700) : null,
                                ),
                              ),
                            ),
                            // ==========================================================
                            const SizedBox(width: 8),
                          ],

                          Flexible(
                            child: Container(
                              padding: const EdgeInsets.symmetric(horizontal: 16, vertical: 12),
                              decoration: BoxDecoration(
                                color: souEu ? Colors.blue.shade500 : Colors.white,
                                borderRadius: BorderRadius.circular(20).copyWith(
                                  bottomRight: souEu ? const Radius.circular(0) : null,
                                  bottomLeft: !souEu ? const Radius.circular(0) : null,
                                ),
                                boxShadow: const [BoxShadow(color: Colors.black12, blurRadius: 4, offset: Offset(0, 2))],
                              ),
                              child: Text(
                                msg['texto'] ?? '',
                                style: TextStyle(fontSize: 16, color: souEu ? Colors.white : Colors.black87),
                              ),
                            ),
                          ),
                        ],
                      ),
                    );
                  },
                );
              },
            ),
          ),

          StreamBuilder<DocumentSnapshot>(
            stream: FirebaseFirestore.instance.collection('chats').doc(widget.chatId).snapshots(),
            builder: (context, snapshot) {
              if (!snapshot.hasData || !snapshot.data!.exists) return const SizedBox.shrink();
              final dadosChat = snapshot.data!.data() as Map<String, dynamic>?;
              if (dadosChat == null || !dadosChat.containsKey('digitando')) return const SizedBox.shrink();

              final mapDigitando = dadosChat['digitando'] as Map<String, dynamic>;
              final outrosDigitando = mapDigitando.entries
                  .where((e) => e.key != _usuarioAtual?.uid && e.value != null)
                  .map((e) => e.value.toString())
                  .toList();

              if (outrosDigitando.isEmpty) return const SizedBox.shrink();
              return Container(
                padding: const EdgeInsets.symmetric(horizontal: 20, vertical: 6),
                alignment: Alignment.centerLeft,
                child: Text('${outrosDigitando.join(', ')} está digitando...', style: TextStyle(color: Colors.grey.shade600, fontStyle: FontStyle.italic, fontSize: 13)),
              );
            },
          ),

          Container(
            padding: const EdgeInsets.symmetric(horizontal: 12, vertical: 8),
            decoration: BoxDecoration(color: Colors.white, boxShadow: [BoxShadow(color: Colors.grey.shade300, blurRadius: 5, offset: const Offset(0, -2))]),
            child: SafeArea(
              child: Row(
                children: [
                  Expanded(
                    child: TextField(
                      controller: _mensagemController,
                      onChanged: _aoDigitar,
                      decoration: InputDecoration(
                        hintText: 'Digite sua mensagem...',
                        filled: true,
                        fillColor: Colors.grey.shade100,
                        border: OutlineInputBorder(borderRadius: BorderRadius.circular(25), borderSide: BorderSide.none),
                        contentPadding: const EdgeInsets.symmetric(horizontal: 20, vertical: 10),
                      ),
                    ),
                  ),
                  const SizedBox(width: 8),
                  CircleAvatar(
                    radius: 24,
                    backgroundColor: Colors.blue,
                    child: IconButton(icon: const Icon(Icons.send, color: Colors.white, size: 20), onPressed: _enviarMensagem),
                  ),
                ],
              ),
            ),
          ),
        ],
      ),
    );
  }
}

// ==== TELA PARA VER FOTO DE PERFIL EM TELA CHEIA ====
class TelaFotoPerfilCheia extends StatelessWidget {
  final String urlFoto;

  const TelaFotoPerfilCheia({super.key, required this.urlFoto});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.black, // Fundo preto
      appBar: AppBar(
        backgroundColor: Colors.black,
        iconTheme: const IconThemeData(color: Colors.white),
        elevation: 0, // Remove a sombra
      ),
      body: Center(
        child: Hero(
          // Deve ter a MESMA 'tag' que usamos na tela anterior
          tag: urlFoto,
          child: InteractiveViewer(
            // O InteractiveViewer permite zoom com os dedos (gesto de pinça)
            minScale: 0.5,
            maxScale: 4.0,
            child: Image.network(
              urlFoto,
              fit: BoxFit.contain, // Garante que a imagem não seja cortada
              width: double.infinity,
            ),
          ),
        ),
      ),
    );
  }
}