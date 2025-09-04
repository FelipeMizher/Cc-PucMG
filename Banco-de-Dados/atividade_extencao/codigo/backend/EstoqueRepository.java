package com.btgaming.compras.repository;

import com.btgaming.compras.model.Estoque;
import org.springframework.data.jpa.repository.JpaRepository;
import java.util.List;

public interface EstoqueRepository extends JpaRepository<Estoque, Integer>{

    /** Retorna todos os componentes com quantidadeEstoque > 0 ordenados por nomeModelo */
    List<Estoque> findByQuantidadeEstoqueGreaterThanOrderByNomeModelo(int quantidade);

    /** Retorna um componente com quantidadeEstoque > 0 pelo ID, se existir */
    Estoque findByIdAndQuantidadeEstoqueGreaterThan(Integer id, int quantidade);
}
