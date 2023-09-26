package br.unesp.rc.lista02.exercicio03.repositorio;

import java.util.LinkedHashSet;
import java.util.Set;

/**
 *
 * @author Prof. Dr. Frank J. Affonso
 */
public class CarroRepositorio {

    private static Set<String> nomes = new LinkedHashSet<>();

    private CarroRepositorio() {
    }

    public static void cadastrarNome(String nome) {
        nomes.add(nome);
    }

    public static boolean consultar(String nome) {
        boolean b = false;

        if (nomes.contains(nome)) {
            b = true;
        }

        return b;
    }

    public static void listarTodos() {
        System.out.println("-----------------------");
        System.out.println("Registro de Carros");
        System.out.println("-----------------------");
        for (String s : nomes) {
            System.out.println("Nome: " + s);
        }
        System.out.println("-----------------------");
    }

}
