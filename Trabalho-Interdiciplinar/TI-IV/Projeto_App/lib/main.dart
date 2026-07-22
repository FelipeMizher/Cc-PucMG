import 'package:elo_escolar/home_screen.dart';
import 'package:flutter/material.dart';
import 'package:firebase_core/firebase_core.dart';
import 'login_screen.dart';

void main() async {
  // Garante que o Flutter inicie antes de chamar configurações nativas
  WidgetsFlutterBinding.ensureInitialized();

  // Inicializa a conexão com o Firebase
  await Firebase.initializeApp();

  runApp(const EloEscolarApp());
}

class EloEscolarApp extends StatelessWidget {
  const EloEscolarApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'EloEscolar',
      debugShowCheckedModeBanner: false, // Tira aquela faixa de "DEBUG" da tela
      theme: ThemeData(
        colorScheme: ColorScheme.fromSeed(seedColor: Colors.blue),
        useMaterial3: true, // Usa o design mais moderno do Android
      ),
      home: const HomeScreen(), // A primeira tela que abre é o Home (evitar o login)
    );
  }
}
