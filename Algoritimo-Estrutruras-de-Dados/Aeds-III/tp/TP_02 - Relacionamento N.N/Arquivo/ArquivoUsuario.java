package Arquivo;

import java.util.List;

import Entidades.Lista;
import Entidades.Usuario;
import Estruturas.HashExtensivel;
import Pares.ParEmailID;

public class ArquivoUsuario extends Arquivo<Usuario> {

    private static final String PATH_PREFIX = "TP_02 - Relacionamento N.N/";

    HashExtensivel<ParEmailID> indiceIndiretoEmail;

    public ArquivoUsuario() throws Exception {
        super("usuarios", Usuario.class.getConstructor());
        indiceIndiretoEmail = new HashExtensivel<>(ParEmailID.class.getConstructor(), 4,
                PATH_PREFIX + "Dados/usuarios/indiceEmail.d.db",
                PATH_PREFIX + "Dados/usuarios/indiceEmail.c.db");
    }

    // Cria um novo usuário no arquivo de dados e atualiza o índice de emails
    @Override
    public int create(Usuario u) throws Exception {
        int id = super.create(u);
        u.setId(id);
        indiceIndiretoEmail.create(new ParEmailID(u.getEmail(), u.getId()));
        return id;
    }

    // Lê um usuário do arquivo buscando pelo email
    public Usuario read(String email) throws Exception {
        ParEmailID p = new ParEmailID(email, -1);
        p = indiceIndiretoEmail.read(p.hashCode());

        if (p == null)
            return null;
        else
            return super.read(p.getID());
    }

    @Override
    public boolean update(Usuario novoUsuario) throws Exception {
        // Primeiro, lemos o usuário antigo pelo ID para obter o email antigo
        Usuario velhoUsuario = super.read(novoUsuario.getId());
        if (velhoUsuario == null) {
            return false;
        }

        // Realiza o update no arquivo principal
        if (super.update(novoUsuario)) {
            // Se o email foi alterado, precisamos atualizar o índice
            if (!novoUsuario.getEmail().equals(velhoUsuario.getEmail())) {
                // Deleta o índice do email antigo
                indiceIndiretoEmail.delete(new ParEmailID(velhoUsuario.getEmail(), -1).hashCode());
                // Cria o índice para o novo email
                indiceIndiretoEmail.create(new ParEmailID(novoUsuario.getEmail(), novoUsuario.getId()));
            }
            return true;
        }
        return false;
    }

    /**
     * Deleta um usuário pelo seu ID, mas APENAS se ele não tiver listas associadas.
     * 
     * @param id O ID do usuário a ser excluído.
     * @return true se a exclusão foi bem-sucedida.
     * @throws Exception se o usuário tiver listas vinculadas.
     */
    @Override
    public boolean delete(int id) throws Exception {
        // 1. Abre o arquivo de listas para fazer a verificação.
        ArquivoLista arqListas = new ArquivoLista();
        // 2. Tenta ler as listas do usuário.
        List<Lista> listasDoUsuario = arqListas.readAll(id);
        // 3. Se a lista não estiver vazia, lança uma exceção e impede a exclusão.
        if (!listasDoUsuario.isEmpty()) {
            throw new Exception("Este usuário não pode ser excluído pois possui " + listasDoUsuario.size()
                    + " lista(s) vinculada(s).");
        }
        // 4. Se a lista estiver vazia, prossegue com a exclusão normal.
        Usuario u = super.read(id);
        if (u == null)
            return false;

        if (super.delete(id)) {
            return indiceIndiretoEmail.delete(new ParEmailID(u.getEmail(), -1).hashCode());
        }
        return false;
    }
}