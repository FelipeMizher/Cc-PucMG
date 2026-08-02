from puzzle.no import No
from puzzle.movimentacao import Movimentacao

class DFS:
    @staticmethod
    def buscar(estado_inicial):
        raiz = No(estado_inicial)
        
        # O DFS usa uma Pilha (Stack). Em Python, uma lista comum serve para isso.
        pilha = [raiz] 
        visitados = set()
        nos_visitados = 0

        while pilha:
            # .pop() sem argumentos remove e retorna o ÚLTIMO elemento da lista
            no_atual = pilha.pop()
            
            # Como um estado pode ser adicionado à pilha mais de uma vez antes de 
            # ser explorado, precisamos garantir que ele não foi visitado no meio tempo.
            if no_atual.estado in visitados:
                continue

            visitados.add(no_atual.estado)
            nos_visitados += 1

            if no_atual.estado.objetivo():
                return no_atual, nos_visitados

            sucessores = Movimentacao.gerar_sucessores(no_atual)

            # Invertemos a lista de sucessores antes de colocar na pilha.
            # Isso garante que a ordem de exploração siga a mesma do BFS (Cima, Baixo, Esq, Dir)
            for sucessor in reversed(sucessores):
                if sucessor.estado not in visitados:
                    pilha.append(sucessor)

        return None, nos_visitados
    
    @staticmethod
    def reconstruir_caminho(no):
        caminho = []
        while no is not None:
            caminho.append(no)
            no = no.pai
        caminho.reverse()
        return caminho