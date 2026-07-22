import 'package:flutter/material.dart';

class SobreScreen extends StatelessWidget {
  const SobreScreen({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text('Sobre o EloEscolar', style: TextStyle(color: Colors.white)),
        backgroundColor: Colors.blue.shade700,
        iconTheme: const IconThemeData(color: Colors.white),
      ),
      body: SingleChildScrollView(
        padding: const EdgeInsets.all(24.0),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.center,
          children: [
            const SizedBox(height: 20),

            // ==== LOGO DO APP ====
            Container(
              padding: const EdgeInsets.all(20),
              decoration: BoxDecoration(
                color: Colors.blue.shade50,
                shape: BoxShape.circle,
              ),
              child: Icon(Icons.school, size: 80, color: Colors.blue.shade700),
            ),
            const SizedBox(height: 16),

            // ==== NOME E VERSÃO ====
            const Text(
              'EloEscolar',
              style: TextStyle(fontSize: 28, fontWeight: FontWeight.bold),
            ),
            const Text(
              'Versão 1.0.0',
              style: TextStyle(color: Colors.grey, fontSize: 16),
            ),
            const SizedBox(height: 40),

            // ==== MISSÃO DO APP ====
            const Text(
              'O EloEscolar é uma plataforma dedicada a facilitar a doação e o acesso a materiais escolares. Acreditamos que a educação transforma vidas e queremos garantir que nenhum estudante fique para trás por falta de recursos.',
              textAlign: TextAlign.center,
              style: TextStyle(fontSize: 16, height: 1.5, color: Colors.black87),
            ),
            const SizedBox(height: 40),
            const Divider(),
            const SizedBox(height: 20),

            // ==== CRÉDITOS DA EQUIPE ====
            const Text(
              'Desenvolvido por:',
              style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold, color: Colors.black54),
            ),
            const SizedBox(height: 16),

            // Lista de nomes do Grupo 09
            _buildNomeIntegrante('Daniel Bueno Lacerda'),
            _buildNomeIntegrante('Felipe Rivetti Mizher'),
            _buildNomeIntegrante('Marcos Paulo Miranda Pereira'),
            _buildNomeIntegrante('Matheus Felipe Cavalcanti Xavier'),
            _buildNomeIntegrante('Paulo Gabriel de Oliveira Leite'),

            const SizedBox(height: 20),
            const Text(
              'Projeto de Ciência da Computação\nGrupo 09',
              textAlign: TextAlign.center,
              style: TextStyle(fontSize: 14, color: Colors.grey, fontWeight: FontWeight.w500),
            ),

            const SizedBox(height: 40),
            const Divider(),

            // ==== SUPORTE ====
            ListTile(
              leading: Icon(Icons.code, color: Colors.blue.shade700, size: 30),
              title: const Text('Código Aberto'),
              subtitle: const Text('Projeto hospedado no GitHub Classroom'),
            ),
          ],
        ),
      ),
    );
  }

  // Função auxiliar para desenhar a lista de nomes
  Widget _buildNomeIntegrante(String nome) {
    return Padding(
      padding: const EdgeInsets.symmetric(vertical: 4.0),
      child: Row(
        mainAxisAlignment: MainAxisAlignment.center,
        children: [
          const Icon(Icons.circle, size: 8, color: Colors.blue),
          const SizedBox(width: 10),
          Text(
            nome,
            style: const TextStyle(fontSize: 16, fontWeight: FontWeight.w600, color: Colors.black87),
          ),
        ],
      ),
    );
  }
}
