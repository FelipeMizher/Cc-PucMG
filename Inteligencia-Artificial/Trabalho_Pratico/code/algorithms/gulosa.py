import heapq
from puzzle.no import No
from puzzle.movimentacao import Movimentacao

class Gulosa:
    @staticmethod
    def buscar(estado_inicial, funcao_heuristica):

        h_inicial = funcao_heuristica(estado_inicial.tabuleiro)
        raiz = No(estado_inicial, heuristica=h_inicial)

        fronteira = []
        contador = 0
        heapq.heappush(fronteira, (raiz.heuristica, contador, raiz))

        visitados = set()
        nos_visitados = 0

        while fronteira:
            _, _, no_atual = heapq.heappop(fronteira)

            if no_atual.estado in visitados:
                continue

            visitados.add(no_atual.estado)
            nos_visitados += 1

            if no_atual.estado.objetivo():
                return no_atual, nos_visitados

            sucessores = Movimentacao.gerar_sucessores(no_atual)

            for sucessor in sucessores:
                if sucessor.estado not in visitados:
                    sucessor.heuristica = funcao_heuristica(
                        sucessor.estado.tabuleiro
                    )
                    contador += 1
                    heapq.heappush(
                        fronteira,
                        (sucessor.heuristica, contador, sucessor)
                    )

        return None, nos_visitados

    @staticmethod
    def reconstruir_caminho(no):
        caminho = []

        while no is not None:
            caminho.append(no)
            no = no.pai

        caminho.reverse()
        return caminho
