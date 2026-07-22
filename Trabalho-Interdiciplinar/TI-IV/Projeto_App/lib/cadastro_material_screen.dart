import 'dart:io';
import 'dart:convert';
import 'package:flutter/material.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:geolocator/geolocator.dart';
import 'package:geocoding/geocoding.dart';
import 'package:image_picker/image_picker.dart';
import 'package:http/http.dart' as http;
import 'package:url_launcher/url_launcher.dart';
// ==== IMPORT DA IA ====
import 'package:google_mlkit_image_labeling/google_mlkit_image_labeling.dart';

class CadastroMaterialScreen extends StatefulWidget {
  const CadastroMaterialScreen({super.key});

  @override
  State<CadastroMaterialScreen> createState() => _CadastroMaterialScreenState();
}

class _CadastroMaterialScreenState extends State<CadastroMaterialScreen> {
  // Controles de Texto Principais
  final _tituloController = TextEditingController();
  final _serieController = TextEditingController();
  final _descricaoController = TextEditingController();

  // Controles de Texto para o Endereço
  final _cepController = TextEditingController();
  final _ruaController = TextEditingController();
  final _numeroController = TextEditingController();
  final _bairroController = TextEditingController();
  final _cidadeController = TextEditingController();

  String _categoriaSelecionada = 'Livros';
  bool _salvando = false;
  bool _buscandoLocalizacao = false;
  String _statusCarregamento = '';

  double? _latitude;
  double? _longitude;
  List<XFile> _fotosSelecionadas = [];

  bool _usarEnderecoManual = false;

  final List<String> _categorias = [
    'Livros',
    'Cadernos',
    'Mochilas',
    'Uniformes',
    'Outros',
  ];

  Future<void> _abrirSiteCorreios() async {
    final url = Uri.parse(
      'https://buscacepinter.correios.com.br/app/endereco/index.php',
    );
    try {
      if (await canLaunchUrl(url)) {
        await launchUrl(url, mode: LaunchMode.externalApplication);
      } else {
        throw 'Não foi possível abrir o site.';
      }
    } catch (e) {
      if (mounted) {
        ScaffoldMessenger.of(context).showSnackBar(
          const SnackBar(
            content: Text('Erro ao tentar abrir o site dos Correios.'),
            backgroundColor: Colors.red,
          ),
        );
      }
    }
  }

  // ==== MÉTODOS DE FOTO ====
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
                'Adicionar fotos',
                style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold),
              ),
            ),
            ListTile(
              leading: const Icon(Icons.photo_library, color: Colors.blue),
              title: const Text('Escolher da Galeria (Várias)'),
              onTap: () {
                Navigator.pop(context);
                _escolherFotosDaGaleria();
              },
            ),
            ListTile(
              leading: const Icon(Icons.camera_alt, color: Colors.blue),
              title: const Text('Tirar Foto Agora'),
              onTap: () {
                Navigator.pop(context);
                _tirarFotoComCamera();
              },
            ),
          ],
        ),
      ),
    );
  }

  Future<void> _escolherFotosDaGaleria() async {
    final ImagePicker picker = ImagePicker();
    final List<XFile> imagens = await picker.pickMultiImage(imageQuality: 70);
    if (imagens.isNotEmpty) {
      setState(() {
        _fotosSelecionadas.addAll(imagens);
        if (_fotosSelecionadas.length > 10) {
          _fotosSelecionadas = _fotosSelecionadas.sublist(0, 10);
        }
      });
    }
  }

  Future<void> _tirarFotoComCamera() async {
    final ImagePicker picker = ImagePicker();
    final XFile? foto = await picker.pickImage(
      source: ImageSource.camera,
      imageQuality: 70,
    );
    if (foto != null) {
      setState(() {
        if (_fotosSelecionadas.length < 10) {
          _fotosSelecionadas.add(foto);
        }
      });
    }
  }

  void _removerFoto(int index) =>
      setState(() => _fotosSelecionadas.removeAt(index));

  // ==== INTELIGÊNCIA ARTIFICIAL: VALIDAÇÃO DE IMAGEM ====
  Future<bool> _validarImagemComIA() async {
    if (_fotosSelecionadas.isEmpty || _categoriaSelecionada == 'Outros') return true;

    try {
      final InputImage imagemEntrada = InputImage.fromFilePath(_fotosSelecionadas[0].path);
      final labeler = ImageLabeler(options: ImageLabelerOptions(confidenceThreshold: 0.6));

      final List<ImageLabel> rotulosEncontrados = await labeler.processImage(imagemEntrada);
      labeler.close();

      List<String> nomesAchados = rotulosEncontrados.map((e) => e.label.toLowerCase()).toList();
      debugPrint("A IA achou: $nomesAchados");

      Map<String, List<String>> palavrasChave = {
        'Livros': ['book', 'publication', 'text', 'paper', 'notebook', 'magazine', 'document'],
        'Cadernos': ['notebook', 'paper', 'document', 'book', 'office supplies'],
        'Mochilas': ['backpack', 'bag', 'luggage', 'handbag', 'suitcase'],
        'Uniformes': ['clothing', 'shirt', 't-shirt', 'pants', 'apparel', 'uniform', 'shoe', 'footwear', 'jacket'],
      };

      List<String> esperados = palavrasChave[_categoriaSelecionada] ?? [];

      for (String achado in nomesAchados) {
        if (esperados.contains(achado)) {
          return true;
        }
      }

      return false;
    } catch (e) {
      return true; // Em caso de erro na IA, deixa passar
    }
  }

  // ==== ALERTA DA CONFIRMAÇÃO SUAVE ====
  Future<bool> _mostrarDialogoConfirmacaoSuave() async {
    bool confirmou = false;
    await showDialog(
      context: context,
      builder: (context) => AlertDialog(
        shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(15)),
        title: const Row(
          children: [
            Icon(Icons.warning_amber_rounded, color: Colors.orange, size: 30),
            SizedBox(width: 10),
            Text('Tem certeza?'),
          ],
        ),
        content: Text(
          'Nossa inteligência artificial analisou a foto e ela não parece se encaixar na categoria "$_categoriaSelecionada".\n\nDeseja publicar assim mesmo?',
          style: const TextStyle(fontSize: 16),
        ),
        actions: [
          TextButton(
            onPressed: () {
              confirmou = false;
              Navigator.pop(context);
            },
            child: const Text('Voltar', style: TextStyle(color: Colors.grey, fontSize: 16)),
          ),
          ElevatedButton(
            onPressed: () {
              confirmou = true;
              Navigator.pop(context);
            },
            style: ElevatedButton.styleFrom(backgroundColor: Colors.blue),
            child: const Text('Sim, publicar', style: TextStyle(color: Colors.white)),
          ),
        ],
      ),
    );
    return confirmou;
  }

  // ==== UPLOAD CLOUDINARY ====
  Future<List<String>> _fazerUploadCloudinary() async {
    List<String> urls = [];
    final urlCloudinary = Uri.parse(
      'https://api.cloudinary.com/v1_1/dmxyru582/image/upload',
    );
    for (int i = 0; i < _fotosSelecionadas.length; i++) {
      setState(
            () => _statusCarregamento =
        'Enviando foto ${i + 1} de ${_fotosSelecionadas.length}...',
      );
      final request = http.MultipartRequest('POST', urlCloudinary)
        ..fields['upload_preset'] = 'hgtkoxc1'
        ..files.add(
          await http.MultipartFile.fromPath('file', _fotosSelecionadas[i].path),
        );
      final response = await request.send();
      if (response.statusCode == 200) {
        final responseData = await response.stream.bytesToString();
        final jsonMap = json.decode(responseData);
        urls.add(jsonMap['secure_url']);
      } else {
        throw Exception('Erro ao enviar a foto ${i + 1}.');
      }
    }
    return urls;
  }

  // ==== LOCALIZAÇÃO 1: GPS ====
  Future<void> _pegarLocalizacaoGPS() async {
    setState(() => _buscandoLocalizacao = true);

    try {
      bool servicoHabilitado = await Geolocator.isLocationServiceEnabled();
      if (!servicoHabilitado) {
        throw 'O GPS do seu celular está desligado. Por favor, ligue-o e tente novamente.';
      }

      LocationPermission permissao = await Geolocator.checkPermission();
      if (permissao == LocationPermission.denied) {
        permissao = await Geolocator.requestPermission();
        if (permissao == LocationPermission.denied) {
          throw 'Você precisa permitir o acesso à localização para capturar o GPS.';
        }
      }

      if (permissao == LocationPermission.deniedForever) {
        throw 'Permissão negada permanentemente. Libere o GPS nas configurações do celular.';
      }

      Position posicao = await Geolocator.getCurrentPosition(
        locationSettings: const LocationSettings(
          accuracy: LocationAccuracy.high,
        ),
      );

      setState(() {
        _latitude = posicao.latitude;
        _longitude = posicao.longitude;
      });

      if (mounted) {
        ScaffoldMessenger.of(context).showSnackBar(
          const SnackBar(
            content: Text('Localização capturada com sucesso!'),
            backgroundColor: Colors.green,
          ),
        );
      }
    } catch (e) {
      if (mounted) {
        ScaffoldMessenger.of(context).showSnackBar(
          SnackBar(content: Text(e.toString()), backgroundColor: Colors.red),
        );
      }
    }

    setState(() => _buscandoLocalizacao = false);
  }

  // ==== LOCALIZAÇÃO 2: API DO VIACEP ====
  Future<void> _buscarCepAPI() async {
    String cepLimpo = _cepController.text.replaceAll(RegExp(r'[^0-9]'), '');

    if (cepLimpo.length != 8) {
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(
          content: Text('O CEP deve ter 8 números!'),
          backgroundColor: Colors.orange,
        ),
      );
      return;
    }

    setState(() => _buscandoLocalizacao = true);
    try {
      final response = await http.get(
        Uri.parse('https://viacep.com.br/ws/$cepLimpo/json/'),
      );
      if (response.statusCode == 200) {
        final dados = json.decode(response.body);

        if (dados.containsKey('erro')) {
          throw Exception('CEP inexistente.');
        }

        setState(() {
          _ruaController.text = dados['logradouro'] ?? '';
          _bairroController.text = dados['bairro'] ?? '';
          _cidadeController.text = '${dados['localidade']} - ${dados['uf']}';
        });

        if (mounted) {
          ScaffoldMessenger.of(context).showSnackBar(
            const SnackBar(
              content: Text('Endereço preenchido! Digite o número.'),
              backgroundColor: Colors.green,
            ),
          );
        }
      }
    } catch (e) {
      if (mounted) {
        ScaffoldMessenger.of(context).showSnackBar(
          const SnackBar(
            content: Text('Não foi possível achar o CEP.'),
            backgroundColor: Colors.red,
          ),
        );
      }
    }
    setState(() => _buscandoLocalizacao = false);
  }

  // ==== SALVAR E CONVERTER O ENDEREÇO EM COORDENADA ====
  Future<void> _salvarMaterial() async {
    if (_tituloController.text.isEmpty || _descricaoController.text.isEmpty) {
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(
          content: Text('Preencha título e descrição!'),
          backgroundColor: Colors.red,
        ),
      );
      return;
    }
    if (_fotosSelecionadas.isEmpty) {
      ScaffoldMessenger.of(context).showSnackBar(
        const SnackBar(
          content: Text('Adicione pelo menos 1 foto!'),
          backgroundColor: Colors.orange,
        ),
      );
      return;
    }

    // ==== VALIDAÇÃO DA IA ENTRA AQUI! ====
    setState(() { _salvando = true; _statusCarregamento = 'Analisando imagem com IA...'; });

    bool imagemCondiz = await _validarImagemComIA();

    if (!imagemCondiz) {
      setState(() => _salvando = false);
      bool usuarioForcou = await _mostrarDialogoConfirmacaoSuave();

      if (!usuarioForcou) {
        return; // O usuário decidiu arrumar a foto, então paramos o salvamento aqui.
      }
    }
    // =====================================

    if (_usarEnderecoManual) {
      if (_ruaController.text.isEmpty ||
          _numeroController.text.isEmpty ||
          _cidadeController.text.isEmpty) {
        ScaffoldMessenger.of(context).showSnackBar(
          const SnackBar(
            content: Text(
              'Preencha os dados do endereço (Rua, Número e Cidade)!',
            ),
            backgroundColor: Colors.orange,
          ),
        );
        setState(() => _salvando = false); // Evita ficar travado
        return;
      }

      setState(() {
        _salvando = true;
        _statusCarregamento = 'Localizando endereço no mapa...';
      });

      try {
        String enderecoCompleto =
            "${_ruaController.text}, ${_numeroController.text}, ${_bairroController.text}, ${_cidadeController.text}, Brasil";
        List<Location> locais = await locationFromAddress(enderecoCompleto);

        if (locais.isNotEmpty) {
          _latitude = locais.first.latitude;
          _longitude = locais.first.longitude;
        } else {
          throw Exception('Endereço não encontrado no mapa.');
        }
      } catch (e) {
        setState(() => _salvando = false);
        if (mounted) {
          ScaffoldMessenger.of(context).showSnackBar(
            const SnackBar(
              content: Text(
                'Endereço não encontrado no mapa. Verifique se digitou certo.',
              ),
              backgroundColor: Colors.red,
            ),
          );
        }
        return;
      }
    } else {
      if (_latitude == null || _longitude == null) {
        ScaffoldMessenger.of(context).showSnackBar(
          const SnackBar(
            content: Text('Capture a localização pelo GPS primeiro!'),
            backgroundColor: Colors.orange,
          ),
        );
        setState(() => _salvando = false);
        return;
      }
    }

    setState(() {
      _salvando = true;
      _statusCarregamento = 'Preparando envio...';
    });

    try {
      List<String> linksDasFotos = await _fazerUploadCloudinary();
      setState(() => _statusCarregamento = 'Salvando doação...');

      final usuarioAtual = FirebaseAuth.instance.currentUser;
      await FirebaseFirestore.instance.collection('materiais').add({
        'titulo': _tituloController.text.trim(),
        'categoria': _categoriaSelecionada,
        'serieEscolar': _serieController.text.trim(),
        'descricao': _descricaoController.text.trim(),
        'latitude': _latitude,
        'longitude': _longitude,
        'fotos': linksDasFotos,
        'doadorId': usuarioAtual?.uid,
        'status': 'disponivel',
        'dataCriacao': FieldValue.serverTimestamp(),
      });
      if (mounted) {
        Navigator.pop(context);
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

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text(
          'Criar Doação',
          style: TextStyle(color: Colors.white),
        ),
        backgroundColor: Colors.blue,
      ),
      body: SingleChildScrollView(
        padding: const EdgeInsets.all(20.0),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.stretch,
          children: [
            // --- FOTOS ---
            const Text(
              'Fotos do Produto (1 a 10):',
              style: TextStyle(fontWeight: FontWeight.bold, fontSize: 16),
            ),
            const SizedBox(height: 10),
            if (_fotosSelecionadas.isNotEmpty)
              SizedBox(
                height: 100,
                child: ListView.builder(
                  scrollDirection: Axis.horizontal,
                  itemCount: _fotosSelecionadas.length,
                  itemBuilder: (context, index) {
                    return Stack(
                      children: [
                        Container(
                          margin: const EdgeInsets.only(right: 10),
                          width: 100,
                          height: 100,
                          decoration: BoxDecoration(
                            borderRadius: BorderRadius.circular(10),
                            image: DecorationImage(
                              image: FileImage(
                                File(_fotosSelecionadas[index].path),
                              ),
                              fit: BoxFit.cover,
                            ),
                          ),
                        ),
                        Positioned(
                          top: 0,
                          right: 10,
                          child: GestureDetector(
                            onTap: () => _removerFoto(index),
                            child: const CircleAvatar(
                              radius: 12,
                              backgroundColor: Colors.red,
                              child: Icon(
                                Icons.close,
                                size: 14,
                                color: Colors.white,
                              ),
                            ),
                          ),
                        ),
                      ],
                    );
                  },
                ),
              ),
            const SizedBox(height: 10),
            OutlinedButton.icon(
              onPressed: _fotosSelecionadas.length >= 10
                  ? null
                  : _mostrarMenuEscolhaFoto,
              icon: const Icon(Icons.add_photo_alternate),
              label: const Text('Adicionar Fotos'),
            ),
            const Divider(height: 40),

            // --- CAMPOS DO PRODUTO ---
            TextField(
              controller: _tituloController,
              decoration: const InputDecoration(
                labelText: 'Nome do material',
                border: OutlineInputBorder(),
              ),
            ),
            const SizedBox(height: 16),
            DropdownButtonFormField<String>(
              initialValue: _categoriaSelecionada,
              decoration: const InputDecoration(
                labelText: 'Categoria',
                border: OutlineInputBorder(),
              ),
              items: _categorias
                  .map(
                    (String cat) =>
                    DropdownMenuItem(value: cat, child: Text(cat)),
              )
                  .toList(),
              onChanged: (String? novaCat) {
                if (novaCat != null) {
                  setState(() => _categoriaSelecionada = novaCat);
                }
              },
            ),
            const SizedBox(height: 16),
            TextField(
              controller: _descricaoController,
              maxLines: 3,
              decoration: const InputDecoration(
                labelText: 'Descrição',
                border: OutlineInputBorder(),
              ),
            ),
            const SizedBox(height: 24),

            // --- SESSÃO: LOCALIZAÇÃO ---
            const Text(
              'Onde o material está?',
              style: TextStyle(fontWeight: FontWeight.bold, fontSize: 16),
            ),
            const SizedBox(height: 12),

            Container(
              decoration: BoxDecoration(
                color: Colors.grey.shade100,
                borderRadius: BorderRadius.circular(10),
                border: Border.all(color: Colors.grey.shade300),
              ),
              child: SwitchListTile(
                title: Text(
                  _usarEnderecoManual
                      ? 'Usar Localização Atual'
                      : 'Digitar o Endereço Manualmente',
                  style: const TextStyle(fontWeight: FontWeight.bold),
                ),
                subtitle: Text(
                  _usarEnderecoManual
                      ? 'Pegar automaticamente onde estou agora'
                      : 'Use o CEP',
                ),
                value: _usarEnderecoManual,
                activeThumbColor: Colors.blue,
                onChanged: (bool valor) {
                  setState(() {
                    _usarEnderecoManual = valor;
                    _latitude = null;
                    _longitude = null;
                  });
                },
              ),
            ),
            const SizedBox(height: 16),

            if (!_usarEnderecoManual)
              ElevatedButton.icon(
                onPressed: _buscandoLocalizacao ? null : _pegarLocalizacaoGPS,
                icon: _buscandoLocalizacao
                    ? const SizedBox(
                  width: 20,
                  height: 20,
                  child: CircularProgressIndicator(
                    color: Colors.white,
                    strokeWidth: 2,
                  ),
                )
                    : const Icon(Icons.my_location),
                label: Text(
                  _latitude == null
                      ? 'Capturar minha localização'
                      : 'Localização via GPS OK!',
                ),
                style: ElevatedButton.styleFrom(
                  backgroundColor: _latitude == null
                      ? Colors.blue
                      : Colors.green,
                  foregroundColor: Colors.white,
                  padding: const EdgeInsets.symmetric(vertical: 14),
                ),
              )
            else
              Column(
                crossAxisAlignment: CrossAxisAlignment.start,
                children: [
                  Row(
                    children: [
                      Expanded(
                        child: TextField(
                          controller: _cepController,
                          keyboardType: TextInputType.number,
                          decoration: const InputDecoration(
                            labelText: 'CEP (Só números)',
                            border: OutlineInputBorder(),
                          ),
                        ),
                      ),
                      const SizedBox(width: 8),
                      SizedBox(
                        height: 60,
                        child: ElevatedButton(
                          onPressed: _buscandoLocalizacao
                              ? null
                              : _buscarCepAPI,
                          style: ElevatedButton.styleFrom(
                            backgroundColor: Colors.blue,
                            foregroundColor: Colors.white,
                          ),
                          child: _buscandoLocalizacao
                              ? const CircularProgressIndicator(
                            color: Colors.white,
                          )
                              : const Icon(Icons.search),
                        ),
                      ),
                    ],
                  ),

                  // ==== LINK PARA OS CORREIOS ====
                  const SizedBox(height: 8),
                  InkWell(
                    onTap: _abrirSiteCorreios,
                    child: Padding(
                      padding: const EdgeInsets.symmetric(vertical: 4.0),
                      child: Text(
                        'Não sabe seu CEP?',
                        style: TextStyle(
                          color: Colors.blue.shade700,
                          decoration: TextDecoration.underline,
                          fontWeight: FontWeight.w500,
                        ),
                      ),
                    ),
                  ),
                  const SizedBox(height: 16),

                  // =====================================
                  TextField(
                    controller: _ruaController,
                    decoration: const InputDecoration(
                      labelText: 'Rua / Logradouro',
                      border: OutlineInputBorder(),
                    ),
                  ),
                  const SizedBox(height: 12),
                  Row(
                    children: [
                      Expanded(
                        flex: 1,
                        child: TextField(
                          controller: _numeroController,
                          keyboardType: TextInputType.text,
                          decoration: const InputDecoration(
                            labelText: 'Número',
                            border: OutlineInputBorder(),
                          ),
                        ),
                      ),
                      const SizedBox(width: 12),
                      Expanded(
                        flex: 2,
                        child: TextField(
                          controller: _bairroController,
                          decoration: const InputDecoration(
                            labelText: 'Bairro',
                            border: OutlineInputBorder(),
                          ),
                        ),
                      ),
                    ],
                  ),
                  const SizedBox(height: 12),
                  TextField(
                    controller: _cidadeController,
                    enabled: false,
                    decoration: InputDecoration(
                      labelText: 'Cidade/UF',
                      border: const OutlineInputBorder(),
                      filled: true,
                      fillColor: Colors.grey.shade200,
                    ),
                  ),
                ],
              ),

            const SizedBox(height: 32),

            // --- BOTÃO SALVAR ---
            if (_salvando)
              Column(
                children: [
                  const CircularProgressIndicator(),
                  const SizedBox(height: 10),
                  Text(
                    _statusCarregamento,
                    style: const TextStyle(
                      fontWeight: FontWeight.bold,
                      color: Colors.blue,
                    ),
                  ),
                ],
              )
            else
              ElevatedButton(
                onPressed: _salvarMaterial,
                style: ElevatedButton.styleFrom(
                  backgroundColor: const Color(0xFF81C784),
                  foregroundColor: Colors.white,
                  padding: const EdgeInsets.all(16),
                ),
                child: const Text(
                  'Publicar Doação',
                  style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold),
                ),
              ),
          ],
        ),
      ),
    );
  }
}