package com.btgaming.compras.dto;

import com.fasterxml.jackson.annotation.JsonProperty;
import java.io.Serializable;

public class EstoqueDTO implements Serializable{

    private static final long serialVersionUID = 1L;

    @JsonProperty("id")
    private Integer id;

    @JsonProperty("nomeModelo")
    private String nomeModelo;

    @JsonProperty("idTipoItem")
    private Integer idTipoItem;

    @JsonProperty("nomeTipo")
    private String nomeTipo;     

    @JsonProperty("quantidadeEstoque")
    private Integer quantidadeEstoque;

    public EstoqueDTO() {}

    public EstoqueDTO(Integer id,
                         String nomeModelo,
                         Integer idTipoItem,
                         String nomeTipo,
                         Integer quantidadeEstoque){
        this.id = id;
        this.nomeModelo = nomeModelo;
        this.idTipoItem = idTipoItem;
        this.nomeTipo = nomeTipo;
        this.quantidadeEstoque = quantidadeEstoque;
    }

    public Integer getId(){ 
        return id; 
    }
    public void setId(Integer id){ 
        this.id = id; 
    }

    public String getNomeModelo(){ 
        return nomeModelo; 
    }
    public void setNomeModelo(String n){ 
        this.nomeModelo = n; 
    }

    public Integer getIdTipoItem(){ 
        return idTipoItem; 
    }
    public void setIdTipoItem(Integer id){ 
        this.idTipoItem = id; 
    }

    public String getNomeTipo(){ 
        return nomeTipo; 
    }
    public void setNomeTipo(String nome){ 
        this.nomeTipo = nome; 
    }

    public Integer getQuantidadeEstoque(){ 
        return quantidadeEstoque; 
    }
    public void setQuantidadeEstoque(Integer q){ 
        this.quantidadeEstoque = q; 
    }
}
