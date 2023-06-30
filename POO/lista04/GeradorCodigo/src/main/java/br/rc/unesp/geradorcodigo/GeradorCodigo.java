/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Project/Maven2/JavaApp/src/main/java/${packagePath}/${mainClassName}.java to edit this template
 */

package br.rc.unesp.geradorcodigo;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author aluno
 */
public class GeradorCodigo {

    public static void main(String[] args) {
        List<String> entradas = new ArrayList<>();
        
        Scanner scn = new Scanner(System.in);
        System.out.print("Classe: ");
        entradas.add(scn.nextLine());
        System.out.print("Pacote: ");
        entradas.add(scn.nextLine());
        
        System.out.print("Modificador: ");
        entradas.add(scn.nextLine());
        System.out.print("Tipo: ");
        entradas.add(scn.nextLine());
        System.out.print("Nome: ");
        entradas.add(scn.nextLine());
        
        System.out.print("Modificador: ");
        entradas.add(scn.nextLine());
        System.out.print("Tipo: ");
        entradas.add(scn.nextLine());
        System.out.print("Nome: ");
        entradas.add(scn.nextLine());
        
        scn.close();
    }
}
