package com.btgaming.compras.model;

import jakarta.persistence.*;

@Entity
@Table(name = "COMPONENTE")
public class Estoque{

    @Id
    @GeneratedValue(strategy = GenerationType.IDENTITY)
    @Column(name = "ID_COMPONENTE")
    private Integer id;

    @Column(name = "NOME_MODELO", nullable = false, length = 120)
    private String nomeModelo;

    @ManyToOne(fetch = FetchType.LAZY)
    @JoinColumn(name = "ID_TIPO_ITEM", nullable = false)
    private TipoItem tipoItem;

    @Column(name = "QUANTIDADE_ESTOQUE", nullable = false)
    private Integer quantidadeEstoque;


    public Integer getId(){ 
        return id; 
    }
    public void setId(Integer id){ 
        this.id = id; 
    }

    public String getNomeModelo(){ 
        return nomeModelo; 
    }
    public void setNomeModelo(String nomeModelo){ 
        this.nomeModelo = nomeModelo; 
    }

    public TipoItem getTipoItem(){ 
        return tipoItem; 
    }
    public void setTipoItem(TipoItem tipoItem){ 
        this.tipoItem = tipoItem; 
    }

    public Integer getQuantidadeEstoque(){ 
        return quantidadeEstoque; 
    }
    public void setQuantidadeEstoque(Integer q){ 
        this.quantidadeEstoque = q; 
    }
}
