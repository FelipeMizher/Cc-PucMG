from collections import deque
from puzzle.no import No
from puzzle.movimentacao import Movimentacao

class BFS:
    def buscar(estado_inicial):

        raiz = No(estado_inicial)

        fila = deque([raiz])

        visitados = set()

        visitados.add(estado_inicial)

        nos_visitados = 0

        while fila:

            no_atual = fila.popleft()

            nos_visitados += 1

            if no_atual.estado.objetivo():

                return no_atual, nos_visitados

            sucessores = Movimentacao.gerar_sucessores(no_atual)

            for sucessor in sucessores:

                if sucessor.estado not in visitados:

                    visitados.add(sucessor.estado)

                    fila.append(sucessor)

        return None, nos_visitados
    
    def reconstruir_caminho(no):
        caminho = []

        while no is not None:

            caminho.append(no)
            no = no.pai

        caminho.reverse()

        return caminho