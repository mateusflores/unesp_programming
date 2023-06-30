/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Project/Maven2/JavaApp/src/main/java/${packagePath}/${mainClassName}.java to edit this template
 */

package br.unesp.rc.atividade1.lista03_ex02;

import entities.Carrinho;
import entities.Item;
import entities.Produto;

/**
 *
 * @author aluno
 */
public class Lista03_ex02 {

    public static void main(String[] args) {
        Carrinho c = new Carrinho();
        
        // criando produtos 
        Produto cafe = new Produto(0, "Café Três Corações", 4.99, 0.5);
        Produto acucar = new Produto(1, "Açúcar União", 10.50, 0.0);
        Produto coca = new Produto(2, "Coca-Cola", 7.45, 0.05);
        Produto leite = new Produto(3, "Leite Piracanjuba", 8.99, 0.0);
        Produto arroz = new Produto(4, "Arroz Prato Fino", 12.00, 0.5);
        Produto banana = new Produto(5, "Banana Prata", 0.90, 0.0);
        
        // Adicionando os produtos ao carrinho
        c.incluirItem(new Item(cafe, 2));
        c.incluirItem(new Item(acucar, 1));
        c.incluirItem(new Item(coca, 5));
        c.incluirItem(new Item(leite, 4));
        c.incluirItem(new Item(arroz, 3));
        c.incluirItem(new Item(banana, 15));
        c.incluirItem(new Item(coca, 1));
        
        c.listarItens();
        System.out.printf("\nTotal a pagar: %.2f", c.valorTotalItens());
        
        
    }
}
