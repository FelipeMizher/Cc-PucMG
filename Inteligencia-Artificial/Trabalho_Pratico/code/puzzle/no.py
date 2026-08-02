class No:
    def __init__(
        self,
        estado,
        pai = None,
        movimento = None,
        custo = 0,
        profundidade = 0,
        heuristica = 0
        ):
        self.estado = estado
        self.pai = pai
        self.movimento = movimento
        self.custo = custo
        self.profundidade = profundidade
        self.heuristica = heuristica

    def f(self):
        return self.custo + self.heuristica

    def __lt__(self, outro):
        return self.f() < outro.f()

    def __repr__(self):
        return (f"No(custo = {self.custo}, " f"profundidade = {self.profundidade}, " f"heuristica = {self.heuristica})")