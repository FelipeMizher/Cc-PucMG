import customtkinter as ctk
from tkinter import messagebox
import requests
import os
import sys
import subprocess

API_ESTOQUE_URL = "http://localhost:8080/estoque"

def get_estoque():
    try:
        resp = requests.get(API_ESTOQUE_URL)
        if resp.status_code == 200:
            return resp.json()
    except Exception as e:
        print("Erro ao buscar estoque:", e)
    return []

def remover_uma_unidade(item_id):
    try:
        url = f"{API_ESTOQUE_URL}/{item_id}/remover"
        resp = requests.put(url)
        return resp.status_code == 200
    except Exception as e:
        print("Erro ao remover unidade:", e)
        return False

def adicionar_uma_unidade(item_id):
    try:
        url = f"{API_ESTOQUE_URL}/{item_id}/adicionar"
        resp = requests.put(url)
        return resp.status_code == 200
    except Exception as e:
        print("Erro ao adicionar unidade:", e)
        return False

class AppEstoque(ctk.CTk):
    def __init__(self):
        super().__init__()
        self.title("Estoque de Itens")
        self.geometry("700x600")
        ctk.set_appearance_mode("dark")
        ctk.set_default_color_theme("blue")

        self.label = ctk.CTkLabel(self, text="Gerenciar Estoque", font=ctk.CTkFont(size=20, weight="bold"))
        self.label.pack(pady=10)

        self.scroll = ctk.CTkScrollableFrame(self, width=650, height=450)
        self.scroll.pack(pady=10, fill="both", expand=True)

        self.criar_cabecalho()

        self.botao_adicionar = ctk.CTkButton(self, text="Acessar historico de compras", command=lambda: self.abrir_historico("compras/historico_compras.py"))
        self.botao_adicionar.pack(pady=10)

        self.atualizar_lista()

    def criar_cabecalho(self):
        cabecalho = ctk.CTkFrame(self.scroll)
        cabecalho.pack(fill="x", padx=5, pady=(0, 5))

        ctk.CTkLabel(cabecalho, text="Nome do Item", width=250, anchor="w").pack(side="left", padx=5)
        ctk.CTkLabel(cabecalho, text="Id Tipo", width=120, anchor="center").pack(side="left", padx=5)
        ctk.CTkLabel(cabecalho, text="Qtd. Estoque", width=80, anchor="center").pack(side="left", padx=5)
        ctk.CTkLabel(cabecalho, text="Ações", width=120, anchor="center").pack(side="right", padx=5)

    def atualizar_lista(self):
        for widget in self.scroll.winfo_children()[1:]:
            widget.destroy()

        estoque = get_estoque()
        if not estoque:
            aviso = ctk.CTkLabel(self.scroll, text="Nenhum item para mostrar", anchor="center")
            aviso.pack(pady=20)
            return

        for item in estoque:
            self.adicionar_item(item["id"], item["nomeModelo"], item["idTipoItem"], item["quantidadeEstoque"])

    def adicionar_item(self, id_, nome, tipo, quantidade):
        linha = ctk.CTkFrame(self.scroll)
        linha.pack(fill="x", pady=2, padx=5)

        ctk.CTkLabel(linha, text=nome, width=250, anchor="w").pack(side="left", padx=5)
        ctk.CTkLabel(linha, text=str(tipo), width=120, anchor="center").pack(side="left", padx=5)
        ctk.CTkLabel(linha, text=str(quantidade), width=80, anchor="center").pack(side="left", padx=5)

        botoes = ctk.CTkFrame(linha, width=120)
        botoes.pack(side="right", padx=5)
        ctk.CTkButton(botoes, text="-", width=40, fg_color="red",
              command=lambda i=id_: self.remover_unidade(i)).pack(side="left", padx=2)
        ctk.CTkButton(botoes, text="+", width=40,
              command=lambda i=id_: self.adicionar_unidade(i)).pack(side="left", padx=2)

    def remover_unidade(self, item_id):
        sucesso = remover_uma_unidade(item_id)
        self.atualizar_lista()

    def adicionar_unidade(self, item_id):
        sucesso = adicionar_uma_unidade(item_id)
        self.atualizar_lista()

    def abrir_historico(self, nome_script):
        base_dir = os.path.dirname(__file__)
        caminho_script = os.path.abspath(os.path.join(base_dir, '..', nome_script))
        comando = "python" if sys.platform.startswith("win") else "python3"
        subprocess.Popen([comando, caminho_script])


if __name__ == "__main__":
    app = AppEstoque()
    app.mainloop()
