/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Project/Maven2/JavaApp/src/main/java/${packagePath}/${mainClassName}.java to edit this template
 */

package br.rc.unesp.contapalavras;

import br.rc.unesp.contapalavras.util.ContadorPalavras;
import java.util.Scanner;

/**
 *
 * @author aluno
 */
public class ContaPalavras {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        System.out.println("Insira o texto a ser analisado: ");
        String texto = scn.nextLine();
        scn.close();
        
        ContadorPalavras cont = new ContadorPalavras(texto);
        cont.contaOcorrencias();
        cont.exibirRelacao();
    }
}
