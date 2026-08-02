class Estado:

    def tem_solucao(self):
        """
        Uma inversão ocorre sempre que um número maior aparece antes de um número menor no tabuleiro (lendo da esquerda para a direita, de cima para baixo).

        Ignoramos o espaço vazio (0) nessa contagem.

        Se o número total de inversões for ímpar, o tabuleiro não tem solução.
        """
        inversoes = 0
        # Transforma a tupla em uma lista ignorando o zero (espaço vazio)
        estado_sem_zero = [x for x in self.tabuleiro if x != 0]
        
        # Conta as inversões
        tamanho = len(estado_sem_zero)
        for i in range(tamanho):
            for j in range(i + 1, tamanho):
                if estado_sem_zero[i] > estado_sem_zero[j]:
                    inversoes += 1
                    
        # Se for par (resto 0), tem solução
        return inversoes % 2 == 0

    def __init__(self, tabuleiro):
        self.tabuleiro = tuple(tabuleiro)

    def objetivo(self):
        return self.tabuleiro == (
            1, 2, 3,
            4, 5, 6,
            7, 8, 0
        )

    def posicao_vazia(self):
        return self.tabuleiro.index(0)

    def __eq__(self, outro):
        return self.tabuleiro == outro.tabuleiro

    def __hash__(self):
        return hash(self.tabuleiro)

    def __str__(self):
        resultado = ""

        for i in range(0, 9, 3):
            linha = self.tabuleiro[i:i+3]
            resultado += " ".join(map(str, linha)) + "\n"

        return resultado
    
    def __repr__(self):
        return self.__str__()