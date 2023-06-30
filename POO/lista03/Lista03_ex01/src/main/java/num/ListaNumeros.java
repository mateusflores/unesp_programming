/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package num;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author aluno
 */
public class ListaNumeros {
    private List<Integer> lista = new ArrayList<>();

    public ListaNumeros() {
    }
    
    public void addNumber() {
        Scanner scn = new Scanner(System.in);
        System.out.println("\nInsira o " + (int) (this.lista.size()+1) + "º numero: ");
        Integer n = scn.nextInt();
        this.lista.add(n);
    }
    
    public void inverterLista() {
        Collections.reverse(lista);
        System.out.println("A lista foi invertida.\nResultado: ");
        exibirLista();
    }
    
    public void exibirLista() {
        for (int i = 0; i < lista.size(); i++) {
            System.out.print(lista.get(i) + " ");
        }
    }
    
}
