import time
from puzzle.estados import Estado
from algorithms.bfs import BFS
from algorithms.dfs import DFS
from algorithms.gulosa import Gulosa
from algorithms.a_estrela import a_estrela
from algorithms.uniforme import UCS
from heuristics.fora_do_lugar import fora_do_lugar
from heuristics.manhattan import distancia_manhattan
from heuristics.euclidiana import distancia_euclidiana

def montar_tabuleiro():
    print("Digite os números do tabuleiro separados por espaço:")
    entrada = input("Tabuleiro: ")

    numeros = list(map(int, entrada.split()))

    if len(numeros) != 9:
        raise ValueError("O tabuleiro deve possuir exatamente 9 números.")
    
    return Estado(numeros)

def menu(tabuleiro):
    print("\n===== 8 PUZZLE =====\n")

    print("Seu tabuleiro:\n")
    print(tabuleiro)


    print("Escolha o algoritmo:")

    print("1 - BFS")
    print("2 - DFS")
    print("3 - Busca Uniforme")
    print("4 - Busca Gulosa")
    print("5 - A*")
    print("\n0 - Sair")

    return int(input("\nOpcao: "))

def menu_heuristica():
    print("\n--- Escolha a Heurística para esse algoritmo ---")
    print("1 - Peças fora do lugar (Misplaced Tiles)")
    print("2 - Distância de Manhattan")
    print("3 - Distância Euclidiana")
    return int(input("\nOpção de heurística: "))

def exibir_estatisticas(nos_visitados, profundidade, tempo_execucao):
    print("\n===== ESTATÍSTICAS =====")
    print(f"Nós visitados: {nos_visitados}")
    print(f"Profundidade do objetivo: {profundidade}")
    print(f"Tempo de execução: {tempo_execucao:.5f} segundos")

def mostrar_caminho(caminho, resumido=False):
    if resumido:
        # Pega apenas as strings de movimento, ignorando o nó raiz que é None
        movimentos = [no.movimento for no in caminho if no.movimento]
        
        print(f"\nCaminho completo ({len(movimentos)} passos):")
        
        # Imprime os movimentos agrupados para não estourar a linha do terminal
        for i in range(0, len(movimentos), 15):
            print(" -> ".join(movimentos[i:i+15]))
            
        print("\nEstado Objetivo alcançado:")
        print(caminho[-1].estado)
        
    else:
        for i, no in enumerate(caminho):
            print(f"Passo {i}")
            if no.movimento:
                print("Movimento:", no.movimento)

            print(no.estado)

def main():
    estado_inicial = montar_tabuleiro()

    if not estado_inicial.tem_solucao():
        print("\nEste caso NÃO possui solução (número ímpar de inversões).")
        print("Tente iniciar com outro tabuleiro.")
        return
    
    opcao = menu(estado_inicial)

    if opcao == 1:
        inicio = time.perf_counter()

        solucao, nos_visitados = BFS.buscar(estado_inicial)

        fim = time.perf_counter()
        tempo_execucao = fim - inicio # tempo de execução do algoritmo

        if solucao:
            caminho = BFS.reconstruir_caminho(solucao)
            mostrar_caminho(caminho)
            exibir_estatisticas(nos_visitados, solucao.profundidade, tempo_execucao)
        else:
            print("Solução não encontrada.")

    elif opcao == 2:
        inicio = time.perf_counter()

        solucao, nos_visitados = DFS.buscar(estado_inicial)

        fim = time.perf_counter()
        tempo_execucao = fim - inicio # tempo de execução do algoritmo

        if solucao:
            caminho = DFS.reconstruir_caminho(solucao)
            mostrar_caminho(caminho, True)
            exibir_estatisticas(nos_visitados, solucao.profundidade, tempo_execucao)
        else:
            print("Solução não encontrada.")
        

    elif opcao == 3:
        inicio = time.perf_counter()

        solucao, nos_visitados = UCS.buscar(estado_inicial)

        fim = time.perf_counter()
        tempo_execucao = fim - inicio # tempo de execução do algoritmo

        if solucao:
            caminho = UCS.reconstruir_caminho(solucao)
            mostrar_caminho(caminho, True)
            exibir_estatisticas(nos_visitados, solucao.profundidade, tempo_execucao)
        else:
            print("Solução não encontrada.")

    elif opcao == 4:
        op_heuristica = menu_heuristica()

        funcao_heuristica = None
        if op_heuristica == 1:
            funcao_heuristica = fora_do_lugar
        elif op_heuristica == 2:
            funcao_heuristica = distancia_manhattan
        elif op_heuristica == 3:
            funcao_heuristica = distancia_euclidiana
        else:
            print("Opção de heurística inválida.")
            return

        inicio = time.perf_counter()

        solucao, nos_visitados = Gulosa.buscar(estado_inicial, funcao_heuristica)

        fim = time.perf_counter()
        tempo_execucao = fim - inicio # tempo de execução do algoritmo 

        if solucao:
            caminho = Gulosa.reconstruir_caminho(solucao)
            mostrar_caminho(caminho)
            exibir_estatisticas(nos_visitados, solucao.profundidade, tempo_execucao)
        else:
            print("Solução não encontrada.")

    elif opcao == 5:
        op_heuristica = menu_heuristica()

        funcao_heuristica = None
        if op_heuristica == 1:
            funcao_heuristica = fora_do_lugar
        elif op_heuristica == 2:
            funcao_heuristica = distancia_manhattan
        elif op_heuristica == 3:
            funcao_heuristica = distancia_euclidiana
        else:
            print("Opção de heurística inválida.")
            return

        print("\nBuscando solução com A*...")
        inicio = time.perf_counter()
        
        # Passando a função heurística escolhida como argumento
        solucao, nos_visitados = a_estrela.buscar(estado_inicial, funcao_heuristica)
        
        fim = time.perf_counter()
        tempo_execucao = fim - inicio # tempo de execução do algoritmo

        if solucao:
            caminho = a_estrela.reconstruir_caminho(solucao)
            mostrar_caminho(caminho)
            exibir_estatisticas(nos_visitados, solucao.profundidade, tempo_execucao)
        else:
            print("Solução não encontrada.")

    elif opcao == 0:
        print("Saindo do programa...")
        return

    else:
        print("Opção inválida.")

if __name__ == "__main__":
    main()