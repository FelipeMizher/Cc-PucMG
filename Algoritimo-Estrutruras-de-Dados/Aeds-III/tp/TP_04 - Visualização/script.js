/* * PresenteFácil - TP4 Visualização
 * Recursos Completos: CRUD, Importação/Exportação, Visualização, Simulação Binária, Avatars
 */

const KEY_STORAGE = "produtos_db";
const elementos = {
    // Tabela e Filtros
    tabelaBody: document.querySelector("#tabela-produtos tbody"),
    inputBusca: document.querySelector("#input-busca"),
    selectOrdenacao: document.querySelector("#select-ordenacao"),
    
    // Sidebar
    jsonViewer: document.querySelector("#json-viewer"),
    hexViewer: document.querySelector("#hex-viewer"),
    tabButtons: document.querySelectorAll(".tab-btn"),
    codeContents: document.querySelectorAll(".code-content"),
    emptyState: document.querySelector("#empty-state"),
    resizer: document.querySelector("#resizer"),
    
    // Modais
    modalProduto: document.querySelector("#modal-produto"),
    modalVisualizar: document.querySelector("#modal-visualizar"),
    
    // Formulário
    form: document.querySelector("#form-produto"),
    tituloModal: document.querySelector("#modal-titulo"),
    inputs: {
        id: document.querySelector("#produto-id"),
        gtin: document.querySelector("#produto-gtin"),
        nome: document.querySelector("#produto-nome"),
        descricao: document.querySelector("#produto-descricao"),
        imagem: document.querySelector("#produto-imagem")
    },
    
    // Visualização Detalhada
    viewCampos: {
        imgContainer: document.querySelector("#view-img-container"),
        gtin: document.querySelector("#view-gtin"),
        nome: document.querySelector("#view-nome"),
        descricao: document.querySelector("#view-descricao")
    },
    
    // Botões
    btnNovo: document.querySelector("#btn-novo-produto"),
    btnsFechar: document.querySelectorAll(".btn-fechar-modal"),
    btnsCancelar: document.querySelectorAll(".btn-cancelar-modal"),
    btnReset: document.querySelector("#btn-reset"),
    btnDownload: document.querySelector("#btn-download"),
    btnImportar: document.querySelector("#btn-importar"),
    inputImportar: document.querySelector("#input-importar"),
    btnViewEditar: document.querySelector("#btn-view-editar"),
    btnViewExcluir: document.querySelector("#btn-view-excluir"),
    
    // Toast
    toast: document.querySelector("#toast"),
    toastMsg: document.querySelector("#toast-msg")
};

// --- MODEL ---
const Model = {
    ler() { return JSON.parse(localStorage.getItem(KEY_STORAGE)) || []; },
    salvar(produtos) {
        const jsonString = JSON.stringify(produtos, null, 2);
        localStorage.setItem(KEY_STORAGE, jsonString);
        View.atualizarPaineis(produtos, jsonString);
    },
    adicionar(produto) {
        const produtos = this.ler();
        if (produtos.some(p => p.gtin === produto.gtin)) throw new Error("Erro: Já existe um produto com este GTIN!");
        produto.id = produtos.length > 0 ? Math.max(...produtos.map(p => p.id)) + 1 : 1;
        produtos.push(produto);
        this.salvar(produtos);
    },
    atualizar(produtoEditado) {
        let produtos = this.ler();
        const index = produtos.findIndex(p => p.id === parseInt(produtoEditado.id));
        if (index !== -1) {
            produtos[index] = { ...produtos[index], ...produtoEditado };
            this.salvar(produtos);
        }
    },
    remover(id) {
        const produtos = this.ler().filter(p => p.id !== id);
        this.salvar(produtos);
    },
    limparTudo() { localStorage.removeItem(KEY_STORAGE); this.salvar([]); }
};

// --- SERIALIZER ---
const Serializer = {
    stringToBytes(str) {
        if (!str) str = "";
        const bytes = [];
        for (let i = 0; i < str.length; i++) {
            let code = str.charCodeAt(i);
            bytes.push(code < 128 ? code : 63);
        }
        return bytes;
    },
    writeInt(array, num) {
        array.push((num >> 24) & 0xFF, (num >> 16) & 0xFF, (num >> 8) & 0xFF, num & 0xFF);
    },
    writeUTF(array, str) {
        const strBytes = this.stringToBytes(str);
        const len = strBytes.length;
        array.push((len >> 8) & 0xFF, len & 0xFF);
        strBytes.forEach(b => array.push(b));
    },
    simularArquivoBinario(produtos) {
        const arquivoBytes = [];
        this.writeInt(arquivoBytes, produtos.length > 0 ? Math.max(...produtos.map(p=>p.id)) : 0);
        produtos.forEach(p => {
            const payloadTemp = [];
            this.writeInt(payloadTemp, p.id);
            this.writeUTF(payloadTemp, p.gtin);
            this.writeUTF(payloadTemp, p.nome);
            this.writeUTF(payloadTemp, p.descricao);
            this.writeUTF(payloadTemp, p.imagem || "");
            arquivoBytes.push(0x20); // Lápide
            this.writeInt(arquivoBytes, payloadTemp.length);
            payloadTemp.forEach(b => arquivoBytes.push(b));
        });
        return arquivoBytes;
    }
};

// --- VIEW ---
const View = {
    timerToast: null,
    formatarGTIN(valor) { return valor.replace(/\D/g, "").padStart(13, "0"); },
    getIniciais(nome) {
        const partes = nome.trim().split(" ");
        if (partes.length === 0) return "?";
        if (partes.length === 1) return partes[0].substring(0, 2).toUpperCase();
        return (partes[0][0] + partes[1][0]).toUpperCase();
    },
    mostrarToast(mensagem, tipo = 'sucesso') {
        elementos.toastMsg.textContent = mensagem;
        elementos.toast.classList.remove("hidden", "erro");
        if (tipo === 'erro') {
            elementos.toast.classList.add("erro");
            elementos.toast.querySelector(".toast-icon").textContent = "!";
        } else {
            elementos.toast.querySelector(".toast-icon").textContent = "✓";
        }
        if (this.timerToast) clearTimeout(this.timerToast);
        this.timerToast = setTimeout(() => elementos.toast.classList.add("hidden"), 4000);
    },
    renderizarTabela(produtos) {
        elementos.tabelaBody.innerHTML = "";
        
        // Lógica de mensagem vazia
        if (produtos.length === 0) {
            const termo = elementos.inputBusca.value.trim();
            const texto = termo ? "Nenhum produto encontrado." : "Nenhum produto cadastrado.";
            elementos.emptyState.querySelector("p").textContent = texto;
            
            elementos.emptyState.classList.remove("hidden");
            return;
        }
        
        elementos.emptyState.classList.add("hidden");
        produtos.forEach(p => {
            const tr = document.createElement("tr");
            
            let avatarHtml;
            const iniciais = this.getIniciais(p.nome);
            if (p.imagem && p.imagem.trim() !== "") {
                avatarHtml = `<img src="${p.imagem}" class="product-avatar-img" alt="${iniciais}" onerror="this.onerror=null; this.parentNode.innerHTML='${iniciais}';">`;
            } else {
                avatarHtml = iniciais;
            }

            tr.innerHTML = `
                <td><span class="txt-gtin">${p.gtin}</span></td>
                <td>
                    <div class="product-name-wrapper">
                        <div class="product-avatar">${avatarHtml}</div>
                        <span class="txt-nome">${p.nome}</span>
                    </div>
                </td>
                <td><span class="txt-desc" title="${p.descricao}">${p.descricao}</span></td>
                <td class="text-center actions-cell">
                    <button class="btn-action-new btn-edit-new" title="Editar">
                        <svg width="20" height="20" fill="none" stroke="currentColor" viewBox="0 0 24 24"><path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M11 5H6a2 2 0 00-2 2v11a2 2 0 002 2h11a2 2 0 002-2v-5m-1.414-9.414a2 2 0 112.828 2.828L11.828 15H9v-2.828l8.586-8.586z"></path></svg>
                    </button>
                    <button class="btn-action-new btn-delete-new" title="Excluir">
                        <svg width="20" height="20" fill="none" stroke="currentColor" viewBox="0 0 24 24"><path stroke-linecap="round" stroke-linejoin="round" stroke-width="2" d="M19 7l-.867 12.142A2 2 0 0116.138 21H7.862a2 2 0 01-1.995-1.858L5 7m5 4v6m4-6v6m1-10V4a1 1 0 00-1-1h-4a1 1 0 00-1 1v3M4 7h16"></path></svg>
                    </button>
                </td>
            `;
            
            tr.addEventListener("click", (e) => {
                if (!e.target.closest(".btn-action-new")) {
                    Controller.abrirVisualizar(p.id);
                }
            });

            tr.querySelector(".btn-edit-new").addEventListener("click", (e) => {
                e.stopPropagation();
                Controller.abrirEditar(p.id);
            });
            tr.querySelector(".btn-delete-new").addEventListener("click", (e) => {
                e.stopPropagation();
                Controller.excluir(p.id);
            });

            elementos.tabelaBody.appendChild(tr);
        });
    },
    atualizarPaineis(produtos, jsonString) {
        elementos.jsonViewer.textContent = jsonString;
        elementos.hexViewer.textContent = this.gerarHexDump(Serializer.simularArquivoBinario(produtos));
    },
    gerarHexDump(bytes) {
        let output = "OFFSET   | 00 01 02 03 04 05 06 07 | ASCII\n---------|-------------------------|---------\n";
        for (let i = 0; i < bytes.length; i += 8) {
            let offset = i.toString(16).padStart(8, '0').toUpperCase();
            let hexPart = "", asciiPart = "";
            for (let j = 0; j < 8; j++) {
                if (i + j < bytes.length) {
                    let b = bytes[i + j];
                    hexPart += b.toString(16).padStart(2, '0').toUpperCase() + " ";
                    asciiPart += (b >= 32 && b <= 126) ? String.fromCharCode(b) : ".";
                } else { hexPart += "   "; asciiPart += " "; }
            }
            output += `${offset} | ${hexPart.trimEnd().padEnd(23," ")} | ${asciiPart}\n`;
        }
        return output;
    },
    fecharTodosModais() {
        document.querySelectorAll(".modal-overlay").forEach(m => m.classList.add("hidden"));
    },
    abrirModal(modal) {
        this.fecharTodosModais();
        modal.classList.remove("hidden");
    },
    preencherForm(p) {
        elementos.inputs.id.value = p.id;
        elementos.inputs.gtin.value = p.gtin;
        elementos.inputs.nome.value = p.nome;
        elementos.inputs.descricao.value = p.descricao;
        elementos.inputs.imagem.value = p.imagem || "";
        elementos.inputs.gtin.disabled = true;
    },
    preencherVisualizacao(p) {
        const iniciais = this.getIniciais(p.nome);
        if (p.imagem && p.imagem.trim() !== "") {
            elementos.viewCampos.imgContainer.innerHTML = `<img src="${p.imagem}" alt="${iniciais}" onerror="this.onerror=null; this.parentNode.innerHTML='<div class=\\'view-avatar-large\\'>${iniciais}</div>';">`;
        } else {
            elementos.viewCampos.imgContainer.innerHTML = `<div class="view-avatar-large">${iniciais}</div>`;
        }
        elementos.viewCampos.gtin.textContent = p.gtin;
        elementos.viewCampos.nome.textContent = p.nome;
        elementos.viewCampos.descricao.textContent = p.descricao;
    }
};

// --- CONTROLLER ---
const Controller = {
    modoDownload: 'json',
    produtoVisualizadoId: null,

    init() {
        this.atualizarLista();
        this.configurarEventos();
        this.initResizer();
        const d = Model.ler();
        View.atualizarPaineis(d, JSON.stringify(d, null, 2));
    },

    configurarEventos() {
        // Busca e Ordenação
        elementos.inputBusca.addEventListener("input", () => this.atualizarLista());
        elementos.selectOrdenacao.addEventListener("change", () => this.atualizarLista());

        // Fechar Modais
        elementos.btnsFechar.forEach(b => b.addEventListener("click", () => View.fecharTodosModais()));
        elementos.btnsCancelar.forEach(b => b.addEventListener("click", () => View.fecharTodosModais()));
        
        document.querySelectorAll(".modal-overlay").forEach(overlay => {
            overlay.addEventListener("click", (e) => {
                if(e.target === overlay) View.fecharTodosModais();
            });
        });

        // Novo Produto
        elementos.btnNovo.addEventListener("click", () => {
            elementos.form.reset();
            elementos.inputs.id.value = "";
            elementos.inputs.gtin.disabled = false;
            document.querySelector("#modal-titulo").textContent = "Adicionar Produto";
            View.abrirModal(elementos.modalProduto);
        });

        // Salvar
        elementos.form.addEventListener("submit", (e) => this.salvarFormulario(e));

        // Ações Visualização
        elementos.btnViewEditar.addEventListener("click", () => {
            if(this.produtoVisualizadoId) this.abrirEditar(this.produtoVisualizadoId);
        });
        elementos.btnViewExcluir.addEventListener("click", () => {
            if(this.produtoVisualizadoId) this.excluir(this.produtoVisualizadoId);
        });

        // Utils
        elementos.inputs.gtin.addEventListener("input", (e) => e.target.value = e.target.value.replace(/\D/g, "").slice(0, 13));
        elementos.btnReset.addEventListener("click", () => {
            if(confirm("ATENÇÃO: Apagar tudo?")) { Model.limparTudo(); this.atualizarLista(); View.mostrarToast("Limpo!"); }
        });

        // Tabs e Download
        elementos.tabButtons.forEach(btn => {
            btn.addEventListener("click", (e) => {
                elementos.tabButtons.forEach(b => b.classList.remove("active"));
                elementos.codeContents.forEach(c => c.classList.add("hidden"));
                e.target.classList.add("active");
                const tab = e.target.dataset.tab;
                if(tab === 'json') { 
                    elementos.jsonViewer.classList.remove("hidden"); 
                    elementos.btnDownload.textContent = "⬇ Baixar (.json)"; 
                    this.modoDownload = 'json'; 
                } else { 
                    elementos.hexViewer.classList.remove("hidden"); 
                    elementos.btnDownload.textContent = "⬇ Baixar (.db)"; 
                    this.modoDownload = 'db'; 
                }
            });
        });

        elementos.btnDownload.addEventListener("click", () => this.modoDownload === 'json' ? this.baixarJSON() : this.baixarDB());
        
        // Importação
        elementos.btnImportar.addEventListener("click", () => elementos.inputImportar.click());
        elementos.inputImportar.addEventListener("change", (e) => this.importarArquivo(e));
    },

    importarArquivo(e) {
        const arq = e.target.files[0];
        if(!arq) return;
        if(arq.type !== "application/json" && !arq.name.endsWith('.json')) {
            View.mostrarToast("Apenas arquivos .json são aceitos.", "erro"); e.target.value=""; return;
        }
        if(!confirm("Importar substituirá todos os dados atuais. Continuar?")) { e.target.value=""; return; }
        
        const r = new FileReader();
        r.onload = (ev) => {
            try {
                const dados = JSON.parse(ev.target.result);
                if(!Array.isArray(dados)) throw new Error("Arquivo não é uma lista válida.");
                const validados = dados.map((d, i) => {
                    if(!d.id || !d.gtin || !d.nome) throw new Error(`Item ${i+1} inválido.`);
                    return { id: Number(d.id), gtin: String(d.gtin), nome: String(d.nome), descricao: String(d.descricao||""), imagem: String(d.imagem||"") };
                });
                Model.salvar(validados);
                this.atualizarLista();
                View.mostrarToast("Importado com sucesso!");
            } catch(err) { View.mostrarToast("Erro: " + err.message, "erro"); }
            finally { e.target.value = ""; }
        };
        r.readAsText(arq);
    },

    initResizer() {
        let resizing = false;
        elementos.resizer.addEventListener('mousedown', () => { resizing=true; document.body.classList.add('resizing'); elementos.resizer.classList.add('resizing'); });
        document.addEventListener('mousemove', (e) => {
            if(!resizing) return;
            let w = window.innerWidth - e.clientX;
            if(w<300) w=300; if(w>800) w=800; if(window.innerWidth-w<400) return;
            document.documentElement.style.setProperty('--sidebar-width', `${w}px`);
        });
        document.addEventListener('mouseup', () => { resizing=false; document.body.classList.remove('resizing'); elementos.resizer.classList.remove('resizing'); });
    },

    atualizarLista() {
        let p = Model.ler();
        const t = elementos.inputBusca.value.toLowerCase().trim();
        const c = elementos.selectOrdenacao.value;
        if(t) p = p.filter(x => x.nome.toLowerCase().includes(t) || x.gtin.includes(t));
        p.sort((a,b) => c==='nome' ? a.nome.localeCompare(b.nome) : c==='gtin' ? a.gtin.localeCompare(b.gtin) : a.id-b.id);
        View.renderizarTabela(p);
    },

    salvarFormulario(e) {
        e.preventDefault();
        try {
            const id = elementos.inputs.id.value;
            const dados = {
                id: id,
                gtin: View.formatarGTIN(elementos.inputs.gtin.value),
                nome: elementos.inputs.nome.value.trim(),
                descricao: elementos.inputs.descricao.value.trim(),
                imagem: elementos.inputs.imagem.value.trim()
            };
            id ? Model.atualizar(dados) : Model.adicionar(dados);
            View.mostrarToast(id ? "Atualizado!" : "Cadastrado!");
            View.fecharTodosModais();
            this.atualizarLista();
        } catch(err) { alert(err.message); }
    },

    abrirEditar(id) {
        const p = Model.ler().find(x => x.id === id);
        if(p) {
            View.fecharTodosModais();
            document.querySelector("#modal-titulo").textContent = "Editar Produto";
            View.preencherForm(p);
            View.abrirModal(elementos.modalProduto);
        }
    },
    
    abrirVisualizar(id) {
        const p = Model.ler().find(x => x.id === id);
        if(p) {
            this.produtoVisualizadoId = id;
            View.preencherVisualizacao(p);
            View.abrirModal(elementos.modalVisualizar);
        }
    },

    excluir(id) {
        if(confirm("Excluir produto?")) {
            Model.remover(id);
            this.atualizarLista();
            View.fecharTodosModais();
            View.mostrarToast("Excluído!");
        }
    },

    baixarJSON() {
        const b = new Blob([JSON.stringify(Model.ler(),null,2)], {type:'application/json'});
        this.triggerDownload(b, 'backup.json');
    },
    baixarDB() {
        const b = new Blob([new Uint8Array(Serializer.simularArquivoBinario(Model.ler()))], {type:'application/octet-stream'});
        this.triggerDownload(b, 'dados.db');
    },
    triggerDownload(blob, nome) {
        const url = URL.createObjectURL(blob);
        const a = document.createElement('a'); a.href=url; a.download=nome;
        document.body.appendChild(a); a.click(); document.body.removeChild(a); URL.revokeObjectURL(url);
    }
};

window.Controller = Controller;
document.addEventListener("DOMContentLoaded", () => Controller.init());