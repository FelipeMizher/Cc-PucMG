import 'package:flutter/material.dart';
import 'dart:math';
import 'grafo_servico.dart';
import 'detalhes_material_screen.dart';

class MapaGrafoView extends StatefulWidget {
  final List<RegiaoNo> nosGrafo;

  const MapaGrafoView({super.key, required this.nosGrafo});

  @override
  State<MapaGrafoView> createState() => _MapaGrafoViewState();
}

class _MapaGrafoViewState extends State<MapaGrafoView> {
  List<Offset> _posicoesTratadas = [];
  double _ultimoLargura = 0;
  double _ultimoAltura = 0;

  // ==== ALGORITMO DE DISTRIBUIÇÃO FÍSICA ====
  void _calcularETratarPosicoes(double larguraTela, double alturaTela) {
    if (widget.nosGrafo.isEmpty) return;
    if (_ultimoLargura == larguraTela && _ultimoAltura == alturaTela && _posicoesTratadas.isNotEmpty) return;

    _ultimoLargura = larguraTela;
    _ultimoAltura = alturaTela;

    // Ponto central estrito da tela do smartphone
    double centroX = larguraTela / 2;
    double centroY = alturaTela / 2;
    final RegiaoNo noCentro = widget.nosGrafo.first;
    List<Offset> posicoes = [];
    double fatorZoomVisual = 0.7;

    // 1. Distribuição radial geométrica inicial mapeada por camadas BFS
    for (int i = 0; i < widget.nosGrafo.length; i++) {
      final no = widget.nosGrafo[i];
      if (no.nivelBfs == 0 || no.id == noCentro.id) {
        posicoes.add(Offset(centroX, centroY));
        continue;
      }

      double deltaLat = no.latitude - noCentro.latitude;
      double deltaLng = no.longitude - noCentro.longitude;
      double anguloReal = atan2(deltaLat, deltaLng);

      // Multiplicador radial baseado na camada multiplicado pelo fator de zoom
      double raioPixelAresta = (no.nivelBfs * 180.0) * fatorZoomVisual;
      raioPixelAresta = raioPixelAresta.clamp(140.0, 450.0);

      posicoes.add(Offset(
        centroX + raioPixelAresta * cos(anguloReal),
        centroY + raioPixelAresta * sin(anguloReal),
      ));
    }

    // Configuração dos parâmetros físicos do sistema de molas (Spring-Embedded Layout)
    double raioColisaoNo = 140.0 * fatorZoomVisual;
    double margemSegurancaAresta = 70.0 * fatorZoomVisual;
    double kAtracaoMola = 0.08;

    // 2. Loop de Simulação de Física Molecular Estável (Relaxamento de Forças)
    for (int iteracao = 0; iteracao < 65; iteracao++) {

      // PARTE A: Repulsão Nó-Nó (Evita sobreposição de círculos)
      for (int i = 0; i < posicoes.length; i++) {
        for (int j = i + 1; j < posicoes.length; j++) {
          double dx = posicoes[j].dx - posicoes[i].dx;
          double dy = posicoes[j].dy - posicoes[i].dy;
          double distancia = sqrt(dx * dx + dy * dy);

          if (distancia < raioColisaoNo) {
            if (distancia == 0) { dx = 1.0; distancia = 1.0; }
            double penetracao = raioColisaoNo - distancia;
            double fX = (dx / distancia) * (penetracao / 2);
            double fY = (dy / distancia) * (penetracao / 2);

            if (i != 0) posicoes[i] = Offset(posicoes[i].dx - fX, posicoes[i].dy - fY);
            if (j != 0) posicoes[j] = Offset(posicoes[j].dx + fX, posicoes[j].dy + fY);
          }
        }
      }

      // PARTE B: Força de Atração Elástica (Mola) -> NÃO DEIXA O FILHO FICAR LONGE DO PAI REAL
      for (int i = 0; i < widget.nosGrafo.length; i++) {
        final noPai = widget.nosGrafo[i];
        for (int j = 0; j < widget.nosGrafo.length; j++) {
          final noFilho = widget.nosGrafo[j];

          if (noPai.conexoesDistancias.containsKey(noFilho.id)) {
            double dx = posicoes[j].dx - posicoes[i].dx;
            double dy = posicoes[j].dy - posicoes[i].dy;
            double distanciaVisual = sqrt(dx * dx + dy * dy);

            double comprimentoAlvoMola = 200.0 * fatorZoomVisual;
            double diferenca = distanciaVisual - comprimentoAlvoMola;

            if (distanciaVisual > 0) {
              double forcaAtracaoX = (dx / distanciaVisual) * diferenca * kAtracaoMola;
              double forcaAtracaoY = (dy / distanciaVisual) * diferenca * kAtracaoMola;

              if (j != 0) {
                posicoes[j] = Offset(posicoes[j].dx - forcaAtracaoX, posicoes[j].dy - forcaAtracaoY);
              }
            }
          }
        }
      }

      // PARTE C: Repulsão Nó-Aresta (Impede nós de ficarem presos em linhas alheias)
      for (int i = 0; i < widget.nosGrafo.length; i++) {
        final noPai = widget.nosGrafo[i];
        final Offset pPai = posicoes[i];

        for (int j = 0; j < widget.nosGrafo.length; j++) {
          final noFilho = widget.nosGrafo[j];

          if (noPai.conexoesDistancias.containsKey(noFilho.id)) {
            final Offset pFilho = posicoes[j];

            for (int k = 0; k < posicoes.length; k++) {
              if (k == i || k == j || k == 0) continue;

              final Offset pNoIntruso = posicoes[k];
              double arestaDx = pFilho.dx - pPai.dx;
              double arestaDy = pFilho.dy - pPai.dy;
              double comprimentoArestaQuadrado = (arestaDx * arestaDx + arestaDy * arestaDy).toDouble();

              if (comprimentoArestaQuadrado == 0) continue;

              double t = ((pNoIntruso.dx - pPai.dx) * arestaDx + (pNoIntruso.dy - pPai.dy) * arestaDy) / comprimentoArestaQuadrado;
              t = t.clamp(0.0, 1.0);

              Offset pProjetado = Offset(pPai.dx + t * arestaDx, pPai.dy + t * arestaDy);
              double desvioX = pNoIntruso.dx - pProjetado.dx;
              double desvioY = pNoIntruso.dy - pProjetado.dy;
              double distanciaAresta = sqrt(desvioX * desvioX + desvioY * desvioY);

              if (distanciaAresta < margemSegurancaAresta) {
                if (distanciaAresta == 0) { desvioX = 1.0; distanciaAresta = 1.0; }
                double forcaEmpurrao = margemSegurancaAresta - distanciaAresta;

                posicoes[k] = Offset(
                    pNoIntruso.dx + (desvioX / distanciaAresta) * forcaEmpurrao,
                    pNoIntruso.dy + (desvioY / distanciaAresta) * forcaEmpurrao
                );
              }
            }
          }
        }
      }
    }

    WidgetsBinding.instance.addPostFrameCallback((_) {
      if (mounted) {
        setState(() {
          _posicoesTratadas = posicoes;
        });
      }
    });
  }

  @override
  Widget build(BuildContext context) {
    if (widget.nosGrafo.isEmpty) {
      return const Center(child: Text("Nenhuma região com doações mapeada.", style: TextStyle(color: Colors.white70)));
    }

    return Scaffold(
      backgroundColor: Colors.grey.shade900,
      body: LayoutBuilder(
        builder: (context, constraints) {
          // Dispara a distribuição calculando dinamicamente em cima do canvas do celular
          _calcularETratarPosicoes(constraints.maxWidth, constraints.maxHeight);

          if (_posicoesTratadas.length < widget.nosGrafo.length) {
            return const Center(child: CircularProgressIndicator());
          }

          return InteractiveViewer(
            boundaryMargin: const EdgeInsets.all(400),
            minScale: 0.35,
            maxScale: 2.0,
            // initialScale deletado para sumir com o erro de compilação
            child: SizedBox(
              width: constraints.maxWidth,
              height: constraints.maxHeight,
              child: Stack(
                clipBehavior: Clip.none,
                children: [
                  // Camada das Arestas
                  CustomPaint(
                    size: Size(constraints.maxWidth, constraints.maxHeight),
                    painter: GrafoCamadasPainter(nos: widget.nosGrafo, posicoes: _posicoesTratadas),
                  ),

                  // Camada dos Vértices Dinâmicos
                  ...List.generate(widget.nosGrafo.length, (index) {
                    final no = widget.nosGrafo[index];
                    final posicao = _posicoesTratadas[index];

                    return Positioned(
                      left: posicao.dx - 45,
                      top:  posicao.dy - 45,
                      child: GestureDetector(
                        onTap: () => _mostrarItensDaRegiao(context, no),
                        behavior: HitTestBehavior.opaque,
                        child: Container(
                          width: 90,
                          height: 90,
                          decoration: BoxDecoration(
                            color: no.nivelBfs == 0 ? Colors.blue.shade700 : Colors.grey.shade800,
                            shape: BoxShape.circle,
                            border: Border.all(
                                color: no.nivelBfs == 0 ? Colors.amber.shade400 : Colors.blue.shade400,
                                width: no.nivelBfs == 0 ? 3 : 2
                            ),
                            boxShadow: const [BoxShadow(color: Colors.black45, blurRadius: 6, offset: Offset(0, 3))],
                          ),
                          child: Column(
                            mainAxisAlignment: MainAxisAlignment.center,
                            children: [
                              Padding(
                                padding: const EdgeInsets.symmetric(horizontal: 6.0),
                                child: Text(
                                  no.nomeBairro,
                                  textAlign: TextAlign.center,
                                  maxLines: 2,
                                  overflow: TextOverflow.ellipsis,
                                  style: const TextStyle(color: Colors.white, fontSize: 10, fontWeight: FontWeight.bold),
                                ),
                              ),
                              const SizedBox(height: 2),
                              Text(
                                "${no.materiais.length} ${no.materiais.length == 1 ? 'item' : 'itens'}",
                                style: TextStyle(color: Colors.amber.shade200, fontSize: 9, fontWeight: FontWeight.w500),
                              ),
                            ],
                          ),
                        ),
                      ),
                    );
                  }),
                ],
              ),
            ),
          );
        },
      ),
    );
  }

  void _mostrarItensDaRegiao(BuildContext context, RegiaoNo regiao) {
    showModalBottomSheet(
      context: context,
      shape: const RoundedRectangleBorder(borderRadius: BorderRadius.vertical(top: Radius.circular(20))),
      builder: (context) => Container(
        padding: const EdgeInsets.all(16),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            Text(
              "Doações em ${regiao.nomeBairro}",
              style: TextStyle(fontSize: 18, fontWeight: FontWeight.bold, color: Colors.blue.shade800),
            ),
            const SizedBox(height: 12),
            Expanded(
              child: ListView.builder(
                itemCount: regiao.materiais.length,
                itemBuilder: (context, idx) {
                  final mat = regiao.materiais[idx];
                  return ListTile(
                    leading: const Icon(Icons.menu_book, color: Colors.blue),
                    title: Text(mat['titulo'] ?? 'Sem título', style: const TextStyle(fontWeight: FontWeight.bold)),
                    subtitle: Text(mat['categoria'] ?? 'Outros'),
                    trailing: const Icon(Icons.chevron_right),
                    onTap: () {
                      Navigator.pop(context);
                      Navigator.push(
                        context,
                        MaterialPageRoute(
                          builder: (context) => DetalhesMaterialScreen(
                            material: mat,
                            materialId: mat['id'] ?? '',
                          ),
                        ),
                      );
                    },
                  );
                },
              ),
            )
          ],
        ),
      ),
    );
  }
}

class GrafoCamadasPainter extends CustomPainter {
  final List<RegiaoNo> nos;
  final List<Offset> posicoes;

  GrafoCamadasPainter({required this.nos, required this.posicoes});

  @override
  void paint(Canvas canvas, Size size) {
    if (posicoes.length < nos.length) return;

    final pincelLinha = Paint()
      ..color = Colors.blue.withValues(alpha: 0.35)
      ..strokeWidth = 2
      ..style = PaintingStyle.stroke;

    for (int i = 0; i < nos.length; i++) {
      for (int j = 0; j < nos.length; j++) {
        if (nos[i].conexoesDistancias.containsKey(nos[j].id)) {
          canvas.drawLine(posicoes[i], posicoes[j], pincelLinha);

          Offset pontoMedio = Offset((posicoes[i].dx + posicoes[j].dx) / 2, (posicoes[i].dy + posicoes[j].dy) / 2);
          double? distancia = nos[i].conexoesDistancias[nos[j].id];

          if (distancia != null && distancia > 0.0) {
            final textPainter = TextPainter(
              text: TextSpan(
                text: " ${distancia.toStringAsFixed(1)} km ",
                style: const TextStyle(color: Colors.amber, fontSize: 9, fontWeight: FontWeight.bold, backgroundColor: Colors.black87),
              ),
              textDirection: TextDirection.ltr,
            );
            textPainter.layout();
            textPainter.paint(canvas, Offset(pontoMedio.dx - (textPainter.width / 2), pontoMedio.dy - (textPainter.height / 2)));
          }
        }
      }
    }
  }

  @override
  bool shouldRepaint(covariant CustomPainter oldDelegate) => true;
}