def distancia_manhattan(tabuleiro):
    distancia = 0
    
    for i in range(9):
        valor = tabuleiro[i]
        if valor != 0:
            # Calcula a linha e coluna atual
            linha_atual, col_atual = divmod(i, 3)
            # Calcula a linha e coluna objetivo (valor - 1, pois o 1 está no índice 0)
            linha_obj, col_obj = divmod(valor - 1, 3)
            
            # Soma a distância absoluta em eixos (sem diagonais)
            distancia += abs(linha_atual - linha_obj) + abs(col_atual - col_obj)
            
    return distancia