package model;
import java.util.ArrayList;

import aeds3.*;

public class ArquivoLivro extends Arquivo<Livro> {

    HashExtensivel<ParISBNID> indiceIndiretoISBN;
    ArvoreBMais<ParTituloId> indiceIndiretoTitulo;

    public ArquivoLivro() throws Exception {
        super("livro", Livro.class.getConstructor());
        indiceIndiretoISBN = new HashExtensivel<>(ParISBNID.class.getConstructor(), 3, "./dados/livro.isbn.d.db", "./dados/livro.isbn.c.db");
        indiceIndiretoTitulo = new ArvoreBMais<>(ParTituloId.class.getConstructor(), 5, "./dados/livro.titulo.db");
    }

    public int create(Livro livro) throws Exception {
        int id = super.create(livro);
        indiceIndiretoISBN.create(new ParISBNID(livro.getISBN(), id));
        indiceIndiretoTitulo.create(new ParTituloId(livro.getTitulo(), id));
        return id;
    }

    public Livro readIsbn(String isbn) throws Exception {
        ParISBNID pii = indiceIndiretoISBN.read(ParISBNID.hash(isbn));
        if(pii == null)
            return null;
        int id = pii.getID();
        return super.read(id);
    }

    public Livro[] readTitulo(String titulo) throws Exception {
        ArrayList<ParTituloId> ptis = indiceIndiretoTitulo.read(new ParTituloId(titulo, -1));
        Livro[] livros = new Livro[ptis.size()];
        int i=0;
        for (ParTituloId pti : ptis) {
            livros[i++] = super.read(pti.getId());
        }
        return livros;
    }

    public boolean update(Livro novoLivro) throws Exception {
        Livro livroAntigo = super.read(novoLivro.getID());
        String isbnAnterior = livroAntigo.getISBN();
        String tituloAnterior = livroAntigo.getTitulo();
        if(super.update(novoLivro)) {
            if(novoLivro.getISBN().compareTo(isbnAnterior)!=0) {
                indiceIndiretoISBN.delete(ParISBNID.hash(isbnAnterior));
                indiceIndiretoISBN.create(new ParISBNID(novoLivro.getISBN(), novoLivro.getID()));
            }
            if(novoLivro.getTitulo().compareTo(tituloAnterior)!=0) {
                indiceIndiretoTitulo.delete(new ParTituloId(tituloAnterior, novoLivro.getID()));
                indiceIndiretoTitulo.create(new ParTituloId(novoLivro.getTitulo(), novoLivro.getID()));
            }
            return true;
        }
        else
            return false;
    }

    @Override
    public boolean delete(int id) throws Exception {
        Livro livro = super.read(id);
        String isbn = livro.getISBN();
        String titulo = livro.getTitulo();
        if( super.delete(id) ) {
            if( indiceIndiretoISBN.delete(ParISBNID.hash(isbn))
                && indiceIndiretoTitulo.delete(new ParTituloId(titulo, id)))
                return true;
            else // deu problema
                return false;
        } else {
            // não excluiu
            return false;
        }
    }
    
}
