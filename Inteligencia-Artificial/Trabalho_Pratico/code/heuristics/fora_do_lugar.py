def fora_do_lugar(tabuleiro):
    objetivo = (1, 2, 3, 4, 5, 6, 7, 8, 0)
    fora_do_lugar = 0
    
    for i in range(9):
        # Ignora o zero e verifica se o número está na posição errada
        if tabuleiro[i] != 0 and tabuleiro[i] != objetivo[i]:
            fora_do_lugar += 1
            
    return fora_do_lugar