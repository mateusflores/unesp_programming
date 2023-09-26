/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Project/Maven2/JavaApp/src/main/java/${packagePath}/${mainClassName}.java to edit this template
 */

package br.unesp.rc.atividade1.lista03_ex01;

import num.ListaNumeros;

/**
 *
 * @author aluno
 */
public class Lista03_ex01 {

    public static void main(String[] args) {
        ListaNumeros l = new ListaNumeros();
        
        for (int i = 0; i<5; i++) {
            l.addNumber();
        }
        
        l.inverterLista();
    }
}
