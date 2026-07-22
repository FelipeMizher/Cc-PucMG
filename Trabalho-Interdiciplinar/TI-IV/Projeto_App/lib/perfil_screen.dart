import 'dart:convert';
import 'package:flutter/material.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:image_picker/image_picker.dart';
import 'package:http/http.dart' as http;
import 'login_screen.dart';

class PerfilScreen extends StatefulWidget {
  const PerfilScreen({super.key});

  @override
  State<PerfilScreen> createState() => _PerfilScreenState();
}

class _PerfilScreenState extends State<PerfilScreen> {
  final _nomeController = TextEditingController();
  final _usuarioAtual = FirebaseAuth.instance.currentUser;
  bool _carregando = true;
  bool _salvando = false;
  String? _urlFotoPerfil;

  @override
  void initState() {
    super.initState();
    _carregarDadosUsuario();
  }

  Future<void> _carregarDadosUsuario() async {
    if (_usuarioAtual != null) {
      try {
        final doc = await FirebaseFirestore.instance
            .collection('usuarios')
            .doc(_usuarioAtual.uid)
            .get();
        if (doc.exists) {
          setState(() {
            _nomeController.text = doc.data()?['nome'] ?? '';
            _urlFotoPerfil = doc.data()?['fotoPerfil'];
          });
        }
      } catch (e) {
        debugPrint('Erro ao carregar dados: $e');
      }
    }
    setState(() => _carregando = false);
  }

  // ==== MENU PARA ESCOLHER CÂMERA OU GALERIA ====
  void _mostrarMenuEscolhaFoto() {
    showModalBottomSheet(
      context: context,
      shape: const RoundedRectangleBorder(
        borderRadius: BorderRadius.vertical(top: Radius.circular(20)),
      ),
      builder: (context) => SafeArea(
        child: Wrap(
          children: [
            const Padding(
              padding: EdgeInsets.all(16.0),
              child: Text(
                'Atualizar foto de perfil',
                style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold),
              ),
            ),
            ListTile(
              leading: const Icon(Icons.photo_library, color: Colors.blue),
              title: const Text('Escolher da Galeria'),
              onTap: () {
                Navigator.pop(context);
                _alterarFotoPerfil(ImageSource.gallery);
              },
            ),
            ListTile(
              leading: const Icon(Icons.camera_alt, color: Colors.blue),
              title: const Text('Tirar Foto Agora'),
              onTap: () {
                Navigator.pop(context);
                _alterarFotoPerfil(ImageSource.camera);
              },
            ),
          ],
        ),
      ),
    );
  }

  // ==== FUNÇÃO PARA ENVIAR A FOTO PARA O CLOUDINARY ====
  Future<void> _alterarFotoPerfil(ImageSource origemDaFoto) async {
    final ImagePicker picker = ImagePicker();
    final XFile? fotoEscolhida = await picker.pickImage(
      source: origemDaFoto,
      imageQuality: 70,
    );

    if (fotoEscolhida == null) {
      return;
    }

    setState(() => _salvando = true);

    try {
      final urlCloudinary = Uri.parse(
        'https://api.cloudinary.com/v1_1/dmxyru582/image/upload',
      );

      final request = http.MultipartRequest('POST', urlCloudinary)
        ..fields['upload_preset'] = 'hgtkoxc1'
        ..files.add(
          await http.MultipartFile.fromPath('file', fotoEscolhida.path),
        );

      final response = await request.send();
      final responseData = await response.stream.bytesToString();
      final jsonMap = json.decode(responseData);

      if (response.statusCode == 200) {
        final String linkDaFoto = jsonMap['secure_url'];

        await FirebaseFirestore.instance
            .collection('usuarios')
            .doc(_usuarioAtual!.uid)
            .update({'fotoPerfil': linkDaFoto});

        setState(() => _urlFotoPerfil = linkDaFoto);

        if (mounted) {
          ScaffoldMessenger.of(context).showSnackBar(
            const SnackBar(
              content: Text('Foto atualizada!'),
              backgroundColor: Colors.green,
            ),
          );
        }
      } else {
        throw Exception(
          jsonMap['error']['message'] ?? 'Erro desconhecido ao subir foto',
        );
      }
    } catch (e) {
      if (mounted) {
        ScaffoldMessenger.of(context).showSnackBar(
          SnackBar(
            content: Text('Erro ao enviar: $e'),
            backgroundColor: Colors.red,
          ),
        );
      }
    }

    setState(() => _salvando = false);
  }

  Future<void> _salvarAlteracoes() async {
    if (_nomeController.text.trim().isEmpty) {
      return;
    }

    setState(() => _salvando = true);
    try {
      await FirebaseFirestore.instance
          .collection('usuarios')
          .doc(_usuarioAtual!.uid)
          .update({'nome': _nomeController.text.trim()});
      if (mounted) {
        ScaffoldMessenger.of(context).showSnackBar(
          const SnackBar(
            content: Text('Perfil atualizado!'),
            backgroundColor: Colors.green,
          ),
        );
      }
    } catch (e) {
      if (mounted) {
        ScaffoldMessenger.of(context).showSnackBar(
          SnackBar(content: Text('Erro: $e'), backgroundColor: Colors.red),
        );
      }
    }
    setState(() => _salvando = false);
  }

  Future<void> _excluirConta() async {
    bool confirmar =
        await showDialog(
          context: context,
          builder: (context) => AlertDialog(
            title: const Row(
              children: [
                Icon(Icons.warning_amber_rounded, color: Colors.red),
                SizedBox(width: 10),
                Text('Aviso Definitivo'),
              ],
            ),
            content: const Text(
              'Tem certeza que deseja excluir sua conta?\n\nEssa ação é DEFINITIVA e NÃO PODE ser desfeita.',
            ),
            actions: [
              TextButton(
                onPressed: () => Navigator.pop(context, false),
                child: const Text('Cancelar'),
              ),
              ElevatedButton(
                onPressed: () => Navigator.pop(context, true),
                style: ElevatedButton.styleFrom(
                  backgroundColor: Colors.red,
                  foregroundColor: Colors.white,
                ),
                child: const Text('Sim, Excluir Minha Conta'),
              ),
            ],
          ),
        ) ??
        false;

    if (confirmar) {
      setState(() => _salvando = true);
      try {
        final uid = _usuarioAtual!.uid;
        final firestore = FirebaseFirestore.instance;

        final materiaisSnapshot = await firestore
            .collection('materiais')
            .where('doadorId', isEqualTo: uid)
            .get();
        for (var doc in materiaisSnapshot.docs) {
          await doc.reference.delete();
        }

        final chatsComoDoador = await firestore
            .collection('chats')
            .where('doadorId', isEqualTo: uid)
            .get();
        for (var doc in chatsComoDoador.docs) {
          await doc.reference.delete();
        }

        final chatsComoInteressado = await firestore
            .collection('chats')
            .where('interessadoId', isEqualTo: uid)
            .get();
        for (var doc in chatsComoInteressado.docs) {
          await doc.reference.delete();
        }

        await firestore.collection('usuarios').doc(uid).delete();
        await _usuarioAtual.delete();

        if (mounted) {
          Navigator.pushAndRemoveUntil(
            context,
            MaterialPageRoute(builder: (context) => const LoginScreen()),
            (route) => false,
          );
        }
      } catch (e) {
        if (mounted) {
          ScaffoldMessenger.of(context).showSnackBar(
            const SnackBar(
              content: Text('Erro. Faça login novamente e tente excluir.'),
              backgroundColor: Colors.red,
            ),
          );
        }
      }
      setState(() => _salvando = false);
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Meu Perfil', style: TextStyle(color: Colors.white)),
        backgroundColor: Colors.blue,
        iconTheme: const IconThemeData(color: Colors.white),
      ),
      body: _carregando
          ? const Center(child: CircularProgressIndicator())
          : SingleChildScrollView(
              padding: const EdgeInsets.all(24.0),
              child: Column(
                crossAxisAlignment: CrossAxisAlignment.stretch,
                children: [
                  Center(
                    child: Stack(
                      children: [
                        CircleAvatar(
                          radius: 60,
                          backgroundColor: Colors.blue.shade100,
                          backgroundImage: _urlFotoPerfil != null
                              ? NetworkImage(_urlFotoPerfil!)
                              : null,
                          child: _urlFotoPerfil == null
                              ? const Icon(
                                  Icons.person,
                                  size: 70,
                                  color: Colors.white,
                                )
                              : null,
                        ),
                        Positioned(
                          bottom: 0,
                          right: 0,
                          child: CircleAvatar(
                            backgroundColor: Colors.blue,
                            radius: 20,
                            child: IconButton(
                              icon: const Icon(
                                Icons.camera_alt,
                                size: 20,
                                color: Colors.white,
                              ),
                              onPressed: _salvando
                                  ? null
                                  : _mostrarMenuEscolhaFoto,
                            ),
                          ),
                        ),
                      ],
                    ),
                  ),
                  const SizedBox(height: 30),

                  TextField(
                    controller: _nomeController,
                    decoration: const InputDecoration(
                      labelText: 'Seu Nome',
                      border: OutlineInputBorder(),
                      prefixIcon: Icon(Icons.person_outline),
                    ),
                  ),
                  const SizedBox(height: 16),
                  TextField(
                    controller: TextEditingController(
                      text: _usuarioAtual?.email,
                    ),
                    enabled: false,
                    decoration: InputDecoration(
                      labelText: 'E-mail (Não editável)',
                      border: const OutlineInputBorder(),
                      prefixIcon: const Icon(Icons.email_outlined),
                      filled: true,
                      fillColor: Colors.grey.shade200,
                    ),
                  ),
                  const SizedBox(height: 30),

                  if (_salvando)
                    const Center(child: CircularProgressIndicator())
                  else
                    ElevatedButton.icon(
                      onPressed: _salvarAlteracoes,
                      icon: const Icon(Icons.save),
                      label: const Padding(
                        padding: EdgeInsets.all(12.0),
                        child: Text(
                          'Salvar Alterações',
                          style: TextStyle(fontSize: 18),
                        ),
                      ),
                      style: ElevatedButton.styleFrom(
                        backgroundColor: Colors.blue,
                        foregroundColor: Colors.white,
                      ),
                    ),

                  const SizedBox(height: 40),
                  const Divider(),
                  const SizedBox(height: 20),

                  OutlinedButton.icon(
                    onPressed: _excluirConta,
                    icon: const Icon(Icons.delete_forever),
                    label: const Padding(
                      padding: EdgeInsets.all(12.0),
                      child: Text(
                        'Excluir Minha Conta',
                        style: TextStyle(fontSize: 16),
                      ),
                    ),
                    style: OutlinedButton.styleFrom(
                      foregroundColor: Colors.red,
                      side: const BorderSide(color: Colors.red),
                    ),
                  ),
                ],
              ),
            ),
    );
  }
}
