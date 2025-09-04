package com.btgaming.compras.controller;

import com.btgaming.compras.dto.ComponenteDTO;
import com.btgaming.compras.model.Estoque;
import com.btgaming.compras.repository.EstoqueRepository;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;
import java.util.stream.Collectors;

@RestController
@RequestMapping("/estoque")
@CrossOrigin(origins = "*")
public class EstoqueController{

    @Autowired
    private EstoqueRepository estoqueRepo;

    private ComponenteDTO toDTO(Estoque e){
        return new ComponenteDTO(
            e.getId(),
            e.getNomeModelo(),
            e.getTipoItem().getIdTipoItem(),
            e.getQuantidadeEstoque()
        );
    }

    @GetMapping
    public List<ComponenteDTO> listarDisponiveis(){
        return estoqueRepo.findByQuantidadeEstoqueGreaterThanOrderByNomeModelo(0)
                          .stream()
                          .map(this::toDTO)
                          .collect(Collectors.toList());
    }

    @GetMapping("/{id}")
    public ResponseEntity<ComponenteDTO> buscarSeDisponivel(@PathVariable Integer id) {
        Estoque e = estoqueRepo.findByIdAndQuantidadeEstoqueGreaterThan(id, 0);
        return (e != null) ? ResponseEntity.ok(toDTO(e))
                           : ResponseEntity.notFound().build();
    }

    @PutMapping("/{id}/remover")
    public ResponseEntity<Void> removerUmaUnidade(@PathVariable Integer id){

        Estoque e = estoqueRepo.findById(id).orElse(null);
        if(e == null){
            return ResponseEntity.notFound().build();
        }

        if(e.getQuantidadeEstoque() > 0){
            e.setQuantidadeEstoque(e.getQuantidadeEstoque() - 1);
            estoqueRepo.save(e);
        }

        return ResponseEntity.noContent().build();
    }

    @PutMapping("/{id}/adicionar")
    public ResponseEntity<Void> adicionarUmaUnidade(@PathVariable Integer id){

        Estoque e = estoqueRepo.findById(id).orElse(null);
        if(e == null){
            return ResponseEntity.notFound().build();
        }

        e.setQuantidadeEstoque(e.getQuantidadeEstoque() + 1);
        estoqueRepo.save(e);

        return ResponseEntity.noContent().build();
    }
}