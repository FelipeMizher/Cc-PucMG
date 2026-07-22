import 'package:flutter/material.dart';
import 'package:firebase_auth/firebase_auth.dart';
import 'package:cloud_firestore/cloud_firestore.dart';
import 'home_screen.dart';

class LoginScreen extends StatefulWidget {
  const LoginScreen({super.key});

  @override
  State<LoginScreen> createState() => _LoginScreenState();
}

class _LoginScreenState extends State<LoginScreen> {
  final _nomeController = TextEditingController();
  final _emailController = TextEditingController();
  final _senhaController = TextEditingController();
  final _auth = FirebaseAuth.instance;

  bool _carregando = false;
  bool _isLogin = true;

  Future<void> _entrarOuCadastrar() async {
    setState(() => _carregando = true);
    try {
      if (_isLogin) {
        // Fazer Login
        await _auth.signInWithEmailAndPassword(
          email: _emailController.text.trim(),
          password: _senhaController.text.trim(),
        );
      } else {
        // Criar Conta
        if (_nomeController.text.trim().isEmpty) {
          _mostrarErro('Por favor, digite seu nome.');
          setState(() => _carregando = false);
          return;
        }

        UserCredential cred = await _auth.createUserWithEmailAndPassword(
          email: _emailController.text.trim(),
          password: _senhaController.text.trim(),
        );

        // Salva o NOME no banco de dados
        await FirebaseFirestore.instance.collection('usuarios').doc(cred.user!.uid).set({
          'nome': _nomeController.text.trim(),
          'email': _emailController.text.trim(),
          'dataCadastro': FieldValue.serverTimestamp(),
        });
      }

      // Se deu tudo certo, volta pra tela de onde o usuário veio
      if (mounted) {
        if (Navigator.canPop(context)) {
          // Se ela veio de outra tela, apenas fecha o Login e ela volta pra onde estava
          Navigator.pop(context);
        } else {
          // Se for a primeira tela (por segurança), vai pra Home
          Navigator.pushReplacement(context, MaterialPageRoute(builder: (context) => const HomeScreen()));
        }
      }

      // ==== Erros ====
    } on FirebaseAuthException catch (e) {
      String mensagemErro = 'Ocorreu um erro na autenticação.';

      // Erros de Login
      if (e.code == 'invalid-credential' || e.code == 'user-not-found' || e.code == 'wrong-password') {
        mensagemErro = 'E-mail ou senha incorretos. Tente novamente.';
      } else if (e.code == 'invalid-email') {
        mensagemErro = 'O formato do e-mail é inválido.';
      } else if (e.code == 'user-disabled') {
        mensagemErro = 'Esta conta foi desativada.';
      } else if (e.code == 'too-many-requests') {
        mensagemErro = 'Muitas tentativas. Tente novamente mais tarde.';
      }
      // Erros de Cadastro
      else if (e.code == 'email-already-in-use') {
        mensagemErro = 'Este e-mail já está cadastrado. Vá em "Fazer login".';
      } else if (e.code == 'weak-password') {
        mensagemErro = 'A senha é muito fraca. Use pelo menos 6 caracteres.';
      }

      _mostrarErro(mensagemErro);

    } catch (e) {
      // Erro genérico (como falta de internet)
      _mostrarErro('Erro inesperado. Verifique sua internet.');
    }
    // ===================================================

    setState(() => _carregando = false);
  }

  void _mostrarErro(String mensagem) {
    ScaffoldMessenger.of(context).showSnackBar(
        SnackBar(content: Text(mensagem), backgroundColor: Colors.red)
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Colors.white,
      body: Center(
        child: SingleChildScrollView(
          padding: const EdgeInsets.all(24.0),
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            crossAxisAlignment: CrossAxisAlignment.stretch,
            children: [
              const Icon(Icons.school, size: 100, color: Colors.blue),
              const SizedBox(height: 20),
              Text(
                _isLogin ? 'Bem-vindo!' : 'Crie sua conta',
                textAlign: TextAlign.center,
                style: const TextStyle(fontSize: 28, fontWeight: FontWeight.bold, color: Colors.blue),
              ),
              const SizedBox(height: 40),

              if (!_isLogin) ...[
                TextField(
                  controller: _nomeController,
                  decoration: const InputDecoration(labelText: 'Seu Nome', border: OutlineInputBorder(), prefixIcon: Icon(Icons.person)),
                ),
                const SizedBox(height: 16),
              ],

              TextField(
                controller: _emailController,
                keyboardType: TextInputType.emailAddress,
                decoration: const InputDecoration(labelText: 'E-mail', border: OutlineInputBorder(), prefixIcon: Icon(Icons.email)),
              ),
              const SizedBox(height: 16),

              TextField(
                controller: _senhaController,
                obscureText: true,
                decoration: const InputDecoration(labelText: 'Senha (mínimo 6 caracteres)', border: OutlineInputBorder(), prefixIcon: Icon(Icons.lock)),
              ),
              const SizedBox(height: 24),

              if (_carregando)
                const Center(child: CircularProgressIndicator())
              else
                ElevatedButton(
                  onPressed: _entrarOuCadastrar,
                  style: ElevatedButton.styleFrom(padding: const EdgeInsets.all(16), backgroundColor: Colors.blue, foregroundColor: Colors.white),
                  child: Text(_isLogin ? 'Entrar' : 'Cadastrar', style: const TextStyle(fontSize: 18)),
                ),

              const SizedBox(height: 12),

              TextButton(
                onPressed: () => setState(() => _isLogin = !_isLogin),
                child: Text(_isLogin ? 'Não tem uma conta? Cadastre-se' : 'Já tem uma conta? Faça login', style: const TextStyle(color: Colors.blue)),
              )
            ],
          ),
        ),
      ),
    );
  }
}
