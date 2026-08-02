import heapq
from puzzle.no import No
from puzzle.movimentacao import Movimentacao


class UCS:
    @staticmethod
    def buscar(estado_inicial):
        
        raiz = No(estado_inicial)
        
        # fila de prioridade: (custo acumulado, contador, nó)
        fronteira = []
        contador = 0
        
        # custo inicial = 0
        heapq.heappush(fronteira, (0, contador, raiz))

        visitados = set()
        nos_visitados = 0

        # guarda melhor custo encontrado para cada estado (evita revisitar pior caminho)
        custos = {raiz.estado: 0}

        while fronteira:
            custo_atual, _, no_atual = heapq.heappop(fronteira)

            if no_atual.estado in visitados:
                continue

            visitados.add(no_atual.estado)
            nos_visitados += 1

            if no_atual.estado.objetivo():
                return no_atual, nos_visitados

            sucessores = Movimentacao.gerar_sucessores(no_atual)

            for sucessor in sucessores:

                # custo do caminho até o sucessor (cada passo custa 1)
                novo_custo = custo_atual + 1

                # se ainda não visitado ou achamos um caminho melhor
                if (sucessor.estado not in custos or
                        novo_custo < custos[sucessor.estado]):

                    custos[sucessor.estado] = novo_custo

                    # se o seu No tiver atributo de custo, opcionalmente armazenamos:
                    sucessor.custo = novo_custo

                    contador += 1
                    heapq.heappush(
                        fronteira,
                        (novo_custo, contador, sucessor)
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