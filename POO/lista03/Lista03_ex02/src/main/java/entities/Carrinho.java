/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package entities;

import java.util.HashSet;
import java.util.Set;

public class Carrinho {
    private Set<Item> itensCarrinho = new HashSet<>();

    public Carrinho() {
    }
     
    public void incluirItem(Item i) {
        itensCarrinho.add(i);
        
    }
    
    public void removerItem(Item i) {
        itensCarrinho.remove(i);
    }
    
    public void listarItens() {
        int i = 1;
        for (Item item : itensCarrinho) {
            System.out.println((int)(i) + "º item: " + 
                    item.getProduto().getNome() + 
                    "\n Quant: " + item.getQuantidade() + 
                    "\n Preço: " + item.getProduto().getPreco() +
                    "\n Desconto: " + item.getProduto().getDesconto()
            );
            i++;
        }
    }
    
    public double valorTotalItens() {
        double valorTotal = 0;
        for (Item item : itensCarrinho) {
            valorTotal += item.getQuantidade() * (item.getProduto().getPreco() * ( 1 - item.getProduto().getDesconto()));
        }
        return valorTotal;
    }
}
