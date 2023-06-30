package br.unesp.rc.lista02.exercicio01;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 *
 * @author Prof. Dr. Frank J. Affonso
 */
public class Exercicio01 {

    public static void main(String[] args) {
        int[] values = {10, 2, 4, 1, 5, 3, 9, 8, 7, 6};
        List<Integer> numeros = new ArrayList<>();

        for (int numero : values) {
            numeros.add(numero);
        }
        
        System.out.println("---");
        List<Integer> copy = new ArrayList<>(numeros);
        System.out.println("LISTA: " + numeros);
        
        Collections.sort(numeros);
        System.out.println("LISTA: " + numeros);
        System.out.println("---");
        
        System.out.println("COPY: " + copy);
        Collections.sort(copy, Collections.reverseOrder());
        System.out.println("COPY: " + copy);
        System.out.println("---");
        
    }
}
