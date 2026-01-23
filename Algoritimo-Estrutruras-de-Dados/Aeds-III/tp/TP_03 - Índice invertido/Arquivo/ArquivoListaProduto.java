package Arquivo;

import java.util.ArrayList;
import java.util.List;
import Entidades.ListaProduto;
import Estruturas.ArvoreBMais;
import Pares.ParListaProduto;
import Pares.ParProdutoLista;

public class ArquivoListaProduto extends Arquivo<ListaProduto> {

    private static final String PATH_PREFIX = "TP_03 - Índice invertido/";

    private ArvoreBMais<ParListaProduto> indiceListaProduto;
    private ArvoreBMais<ParProdutoLista> indiceProdutoLista;

    public ArquivoListaProduto() throws Exception {
        super("lista_produto", ListaProduto.class.getConstructor());

        indiceListaProduto = new ArvoreBMais<>(ParListaProduto.class.getConstructor(), 5,
                PATH_PREFIX + "Dados/lista_produto/lista_produto.idx");
        indiceProdutoLista = new ArvoreBMais<>(ParProdutoLista.class.getConstructor(), 5,
                PATH_PREFIX + "Dados/lista_produto/produto_lista.idx");
    }

    @Override
    public int create(ListaProduto obj) throws Exception {
        int id = super.create(obj);
        obj.setId(id);
        indiceListaProduto.create(new ParListaProduto(obj.getIdLista(), id));
        indiceProdutoLista.create(new ParProdutoLista(obj.getIdProduto(), id));
        return id;
    }

    @Override
    public boolean delete(int id) throws Exception {
        ListaProduto lp = super.read(id);
        if (lp == null)
            return false;

        if (super.delete(id)) {
            indiceListaProduto.delete(new ParListaProduto(lp.getIdLista(), id));
            indiceProdutoLista.delete(new ParProdutoLista(lp.getIdProduto(), id));
            return true;
        }
        return false;
    }

    public List<ListaProduto> readByIdLista(int idLista) throws Exception {
        List<ListaProduto> listaDeProdutos = new ArrayList<>();
        ArrayList<ParListaProduto> pares = indiceListaProduto.read(new ParListaProduto(idLista, -1));

        for (ParListaProduto par : pares) {
            ListaProduto lp = super.read(par.getIdListaProduto());
            if (lp != null) {
                listaDeProdutos.add(lp);
            }
        }
        return listaDeProdutos;
    }

    public List<ListaProduto> readByIdProduto(int idProduto) throws Exception {
        List<ListaProduto> listaDeListas = new ArrayList<>();
        ArrayList<ParProdutoLista> pares = indiceProdutoLista.read(new ParProdutoLista(idProduto, -1));

        for (ParProdutoLista par : pares) {
            ListaProduto lp = super.read(par.getIdListaProduto());
            if (lp != null) {
                listaDeListas.add(lp);
            }
        }
        return listaDeListas;
    }
}