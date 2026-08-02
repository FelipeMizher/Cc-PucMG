import heapq
from puzzle.no import No
from puzzle.movimentacao import Movimentacao

class a_estrela:
    @staticmethod
    def buscar(estado_inicial, funcao_heuristica):
        # Calcula a heurística para o estado inicial
        h_inicial = funcao_heuristica(estado_inicial.tabuleiro)
        raiz = No(estado_inicial, heuristica=h_inicial)

        # Usamos uma lista que será manipulada pelo módulo heapq
        fronteira = []
        heapq.heappush(fronteira, raiz)

        visitados = set()
        nos_visitados = 0

        while fronteira:
            # heappop remove e retorna o nó com o menor f(n)
            no_atual = heapq.heappop(fronteira)

            # Se já visitamos este estado com um caminho menor/igual, pulamos
            if no_atual.estado in visitados:
                continue

            visitados.add(no_atual.estado)
            nos_visitados += 1

            if no_atual.estado.objetivo():
                return no_atual, nos_visitados

            sucessores = Movimentacao.gerar_sucessores(no_atual)

            for sucessor in sucessores:
                if sucessor.estado not in visitados:
                    # Calcula o h(n) do novo estado e atribui ao nó
                    sucessor.heuristica = funcao_heuristica(sucessor.estado.tabuleiro)
                    
                    # Adiciona à fila de prioridade
                    heapq.heappush(fronteira, sucessor)

        return None, nos_visitados

    @staticmethod
    def reconstruir_caminho(no):
        caminho = []
        while no is not None:
            caminho.append(no)
            no = no.pai
        caminho.reverse()
        return caminho