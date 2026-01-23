package Controles;

import Arquivo.ArquivoLista;
import Entidades.Lista;
import Views.VisaoBuscaLista;

public class ControleBuscaLista {

    private ArquivoLista arqListas;
    private VisaoBuscaLista visao;

    public ControleBuscaLista() {
        try {
            this.arqListas = new ArquivoLista();
        } catch (Exception e) {
            e.printStackTrace();
        }
        this.visao = new VisaoBuscaLista();
    }

    public void executa() {
        String codigo;
        do {
            codigo = visao.leCodigo();
            if (!codigo.equalsIgnoreCase("R")) {
                try {
                    Lista listaEncontrada = arqListas.readByCodigo(codigo);
                    visao.mostraListaEncontrada(listaEncontrada);
                } catch (Exception e) {
                    System.out.println("Erro ao buscar a lista: " + e.getMessage());
                }
            }
        } while (!codigo.equalsIgnoreCase("R"));
    }
}