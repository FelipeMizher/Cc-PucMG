import math

def distancia_euclidiana(tabuleiro):
    distancia = 0
    
    for i in range(9):
        valor = tabuleiro[i]
        if valor != 0:
            linha_atual, col_atual = divmod(i, 3)
            linha_obj, col_obj = divmod(valor - 1, 3)
            
            # Distância reta: sqrt(dx² + dy²)
            distancia += math.sqrt((linha_atual - linha_obj)**2 + (col_atual - col_obj)**2)
            
    return distancia