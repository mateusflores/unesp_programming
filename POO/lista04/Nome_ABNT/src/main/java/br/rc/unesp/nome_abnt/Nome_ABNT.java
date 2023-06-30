/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Project/Maven2/JavaApp/src/main/java/${packagePath}/${mainClassName}.java to edit this template
 */

package br.rc.unesp.nome_abnt;

import util.ConversorABNT;

/**
 *
 * @author aluno
 */
public class Nome_ABNT {

    public static void main(String[] args) {
        ConversorABNT c = new ConversorABNT("João da Costa Silva");
        
        System.out.printf("Nome: %s\nFormato ABNT: %s", c.getName(),c.generateABNT());
    }
}
