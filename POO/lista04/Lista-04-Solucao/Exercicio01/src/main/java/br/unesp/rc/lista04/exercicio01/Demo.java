package br.unesp.rc.lista04.exercicio01;

import br.unesp.rc.lista04.exercicio01.utils.ABNTUtils;

/**
 *
 * @author frank
 */
public class Demo {

    public static void main(String[] args) {
        String[] nomes = {
            "Fulano da Silva Sauro",
            "Fulano Silva Sauro",
            "Frank José Affonso"
        };

        for (String nome : nomes) {
            System.out.println("Nome: " + nome);
            System.out.println("ABNT: " + ABNTUtils.nameToAbnt(nome));
            System.out.println("---");
        }
    }
}
