from puzzle.no import No
from puzzle.estados import Estado


class Movimentacao:

    @staticmethod
    def gerar_sucessores(no_atual):

        sucessores = []

        estado = list(no_atual.estado.tabuleiro)

        pos_vazio = estado.index(0)

        linha = pos_vazio // 3
        coluna = pos_vazio % 3

        movimentos = [
            (-1, 0, "CIMA"),
            (1, 0, "BAIXO"),
            (0, -1, "ESQUERDA"),
            (0, 1, "DIREITA")
        ]

        for dl, dc, nome_movimento in movimentos:

            nova_linha = linha + dl
            nova_coluna = coluna + dc

            if 0 <= nova_linha < 3 and 0 <= nova_coluna < 3:

                nova_pos = nova_linha * 3 + nova_coluna

                novo_tabuleiro = estado.copy()

                novo_tabuleiro[pos_vazio], novo_tabuleiro[nova_pos] = (
                    novo_tabuleiro[nova_pos],
                    novo_tabuleiro[pos_vazio]
                )

                novo_estado = Estado(tuple(novo_tabuleiro))

                sucessores.append(
                    No(
                        estado=novo_estado,
                        pai=no_atual,
                        movimento=nome_movimento,
                        custo=no_atual.custo + 1,
                        profundidade=no_atual.profundidade + 1
                    )
                )

        return sucessores