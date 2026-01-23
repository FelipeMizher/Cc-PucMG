package Arquivo;

import java.util.ArrayList;
import java.util.List;
import Entidades.Lista;
import Entidades.ListaProduto;
import Estruturas.ArvoreBMais;
import Estruturas.HashExtensivel;
import Pares.ParCodigoLista;
import Pares.ParUsuarioLista;

public class ArquivoLista extends Arquivo<Lista> {

    private static final String PATH_PREFIX = "TP_03 - Índice invertido/";

    private ArvoreBMais<ParUsuarioLista> indiceUsuarioLista;
    private HashExtensivel<ParCodigoLista> indiceCodigoLista;

    public ArquivoLista() throws Exception {
        super("listas", Lista.class.getConstructor());

        indiceUsuarioLista = new ArvoreBMais<>(ParUsuarioLista.class.getConstructor(), 5,
                PATH_PREFIX + "Dados/listas/usuarioLista.idx");
        indiceCodigoLista = new HashExtensivel<>(ParCodigoLista.class.getConstructor(), 4,
                PATH_PREFIX + "Dados/listas/codigoLista.d.db", PATH_PREFIX + "Dados/listas/codigoLista.c.db");
    }

    /**
     * Busca uma lista pelo seu código compartilhável.
     * 
     * @param codigo O código de 10 caracteres.
     * @return A Lista encontrada, ou null se não existir.
     */
    public Lista readByCodigo(String codigo) throws Exception {
        // 1. Criamos um objeto de busca apenas para calcular o hash.
        ParCodigoLista pBusca = new ParCodigoLista(codigo, -1);
        int hashCodeBusca = pBusca.hashCode();

        // 2. Usamos o hashCode (um int) para buscar no índice.
        ParCodigoLista pEncontrado = indiceCodigoLista.read(hashCodeBusca);

        // 3. Verificação de segurança contra colisões de hash:
        // Confirma se o código encontrado é realmente o que buscamos.
        if (pEncontrado != null && pEncontrado.getCodigo().equals(codigo)) {
            return super.read(pEncontrado.getIdLista());
        }

        return null;
    }

    public List<Lista> readAll(int idUsuario) throws Exception {
        List<Lista> listasDoUsuario = new ArrayList<>();
        ArrayList<ParUsuarioLista> pares = indiceUsuarioLista.read(new ParUsuarioLista(idUsuario, -1));

        for (ParUsuarioLista par : pares) {
            Lista lista = super.read(par.getIdLista());
            if (lista != null) {
                listasDoUsuario.add(lista);
            }
        }

        return listasDoUsuario;
    }

    @Override
    public int create(Lista obj) throws Exception {
        obj.setCodigoCompartilhavel(ArquivoNanoID.generate());
        int idLista = super.create(obj);
        obj.setId(idLista);

        indiceUsuarioLista.create(new ParUsuarioLista(obj.getIdUsuario(), idLista));
        indiceCodigoLista.create(new ParCodigoLista(obj.getCodigoCompartilhavel(), idLista));

        return idLista;
    }

    @Override
    public boolean delete(int idLista) throws Exception {
        Lista lista = super.read(idLista);
        if (lista == null) {
            return false;
        }

        // ANTES de deletar a lista, deleta todas as associações
        ArquivoListaProduto arqLP = new ArquivoListaProduto();
        List<ListaProduto> produtosNaLista = arqLP.readByIdLista(idLista);
        for (ListaProduto lp : produtosNaLista) {
            arqLP.delete(lp.getId());
        }
        // FIM DA MODIFICAÇÃO

        if (super.delete(idLista)) {
            ParCodigoLista pDelete = new ParCodigoLista(lista.getCodigoCompartilhavel(), -1);
            int hashCodeDelete = pDelete.hashCode();

            indiceCodigoLista.delete(hashCodeDelete);

            indiceUsuarioLista.delete(new ParUsuarioLista(lista.getIdUsuario(), idLista));
            return true;
        }

        return false;
    }
}