package Arquivo;

import java.util.ArrayList;
import java.util.List;
import Entidades.Produto;
import Estruturas.HashExtensivel;
import Pares.ParGtinId;
import Pares.ParIDEndereco;

public class ArquivoProduto extends Arquivo<Produto> {

    private static final String PATH_PREFIX = "TP_02 - Relacionamento N.N/";

    HashExtensivel<ParGtinId> indiceGtin;

    public ArquivoProduto() throws Exception {
        super("produtos", Produto.class.getConstructor());
        indiceGtin = new HashExtensivel<>(
                ParGtinId.class.getConstructor(), 4,
                PATH_PREFIX + "Dados/produtos/indiceGtin.d.db",
                PATH_PREFIX + "Dados/produtos/indiceGtin.c.db");
    }

    @Override
    public int create(Produto obj) throws Exception {
        if (read(obj.getGtin13()) != null) {
            throw new Exception("Produto com GTIN-13 já cadastrado.");
        }
        int id = super.create(obj);
        obj.setId(id);
        indiceGtin.create(new ParGtinId(obj.getGtin13(), id));
        return id;
    }

    public Produto read(String gtin) throws Exception {
        ParGtinId p = indiceGtin.read(gtin.hashCode());
        if (p == null || !p.getGtin().equals(gtin)) {
            return null;
        }
        return super.read(p.getId());
    }

    public List<Produto> readAll() throws Exception {
        List<Produto> todosProdutos = new ArrayList<>();
        arquivo.seek(TAM_CABECALHO); // Pula o cabeçalho

        while (arquivo.getFilePointer() < arquivo.length()) {
            long endereco = arquivo.getFilePointer();
            byte lapide = arquivo.readByte();
            short tam = arquivo.readShort();

            if (lapide == ' ') {
                byte[] ba = new byte[tam];
                arquivo.read(ba);
                Produto p = construtor.newInstance();
                p.fromByteArray(ba);
                todosProdutos.add(p);
            } else {
                arquivo.skipBytes(tam);
            }
        }
        return todosProdutos;
    }

    // A exclusão de um produto (inativação)
    @Override
    public boolean delete(int id) throws Exception {
        Produto p = super.read(id);
        if (p == null)
            return false;

        // Verificar se o produto está em alguma lista, se sim, não permitir exclusão
        p.setAtivo(false);
        return super.update(p);
    }

    public boolean reativar(int id) throws Exception {
        Produto p = super.read(id);
        if (p == null)
            return false;

        p.setAtivo(true);
        return super.update(p);
    }
}