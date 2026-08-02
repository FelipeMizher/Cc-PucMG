# 8-Puzzle Search AI

Projeto desenvolvido para a disciplina de Inteligência Artificial da Pontifícia Universidade Católica de Minas Gerais (PUC Minas).

## Objetivo

Implementar e comparar algoritmos de busca para resolver o problema clássico do 8-Puzzle.

O sistema permite:

- Inserir um estado inicial do tabuleiro;
- Verificar se o problema possui solução;
- Executar diferentes algoritmos de busca;
- Comparar desempenho entre algoritmos;
- Visualizar o caminho até a solução;
- Exibir métricas de execução.

---

## O Problema

O 8-Puzzle consiste em um tabuleiro 3x3 contendo oito peças numeradas e um espaço vazio.

Exemplo de estado objetivo:

| 1 | 2 | 3 |
|---|---|---|
| 4 | 5 | 6 |
| 7 | 8 |   |

O objetivo é alcançar esse estado através da movimentação das peças adjacentes ao espaço vazio.

---

## Algoritmos Implementados

### Busca Não Informada

- Breadth-First Search (BFS)
- Depth-First Search (DFS)
- Uniform Cost Search (UCS)

### Busca Informada

- Greedy Search
- A* Search

---

## Heurísticas do A*

### H1 - Peças Fora do Lugar

Conta quantas peças não estão em suas posições corretas.

### H2 - Distância Manhattan

Soma das distâncias horizontais e verticais de cada peça até sua posição objetivo.

### H3 - Distância Euclidiana

Soma das distâncias em linha reta de cada peça até sua posição objetivo.

---

## Estrutura do Projeto

```text
src/
│
├── puzzle/
│   ├── state.py
│   ├── node.py
│   ├── successors.py
│   └── solvability.py
│
├── algorithms/
│   ├── bfs.py
│   ├── dfs.py
│   ├── uniform_cost.py
│   ├── greedy.py
│   └── astar.py
│
├── heuristics/
│   ├── misplaced_tiles.py
│   ├── manhattan.py
│   └── euclidean.py
│
├── metrics/
│   └── statistics.py
│
└── interface/
    ├── menu.py
    └── visualization.py
```

---

## Métricas Coletadas

Para cada execução são registradas:

- Tempo de execução
- Número de nós gerados
- Número de nós visitados
- Profundidade da solução
- Caminho encontrado

---

## Tecnologias Utilizadas

- Python 3.12+
- heapq
- queue
- time
- matplotlib

---

## Instalação

Clone o repositório:

```bash
git clone https://github.com/SEU-USUARIO/8-puzzle-search-ai.git
```

Entre na pasta:

```bash
cd 8-puzzle-search-ai
```

Instale as dependências:

```bash
pip install -r requirements.txt
```

---

## Execução

```bash
python main.py
```

---

## Exemplo de Entrada

```text
1 2 3
4 0 6
7 5 8
```

Onde:

- 0 representa o espaço vazio.

---

## Integrantes

<table width="560">
    <td align="center" width="140">
      <a href="https://github.com/flp2113" title="Felipe Guerzoni">
        <img src="https://avatars.githubusercontent.com/u/161882746?v=4" width="100px;" alt="Foto do Felipe"/><br>
        <sub>
          <img src="https://img.shields.io/badge/-Felipe%20Guerzoni-181717?style=flat-square&logo=github&logoColor=white" alt="GitHub Felipe Guerzoni">
        </sub>
      </a>
    </td>
    <td align="center" width="140">
      <a href="https://github.com/FelipeMizher" title="Felipe Mizher">
        <img src="https://avatars.githubusercontent.com/u/130677681?v=4" width="100px;" alt="Foto do Felipe"/><br>
        <sub>
          <img src="https://img.shields.io/badge/-Felipe%20Mizher-181717?style=flat-square&logo=github&logoColor=white" alt="GitHub Felipe Mizher">
        </sub>
      </a>
    </td>
    <td align="center" width="140">
      <a href="https://github.com/mioj0kt" title="Matheus Felipe">
        <img src="https://avatars.githubusercontent.com/u/161849185?v=4" width="100px;" alt="Foto do Matheus"/><br>
        <sub>
          <img src="https://img.shields.io/badge/-Matheus%20Felipe-181717?style=flat-square&logo=github&logoColor=white" alt="GitHub Matheus Felipe">
        </sub>
      </a>
    </td>
    <td align="center" width="140">
      <a href="https://github.com/MarcosVettel" title="Marcos Paulo">
        <img src="https://avatars.githubusercontent.com/u/134240264?v=4" width="100px;" alt="Foto do Marcos"/><br>
        <sub>
          <img src="https://img.shields.io/badge/-Marcos%20Paulo-181717?style=flat-square&logo=github&logoColor=white" alt="GitHub Marcos Paulo">
        </sub>
      </a>
    </td>
</table>

---

## Disciplina

Inteligência Artificial

PUC Minas - Ciência da Computação

2026
