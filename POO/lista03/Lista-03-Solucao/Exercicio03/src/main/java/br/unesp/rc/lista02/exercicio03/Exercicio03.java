package br.unesp.rc.lista02.exercicio03;

import br.unesp.rc.lista02.exercicio03.modelo.Carro;
import br.unesp.rc.lista02.exercicio03.modelo.Montadora;
import br.unesp.rc.lista02.exercicio03.repositorio.CarroRepositorio;
import br.unesp.rc.lista02.exercicio03.repositorio.MontadoraRepositorio;

/**
 *
 * @author Prof. Dr. Frank J. Affonso
 */
public class Exercicio03 {

    public static void main(String[] args) {
        /**
         * Inicializando o sistema com três montadoras e um carro para cada
         * montadora
         */
        inicializar();
        System.out.println("Após inicialização");
        CarroRepositorio.listarTodos();
        MontadoraRepositorio.listarTodas();

        /**
         * Adicionando um carro para cada montadora
         */
        cenarioAcionaCarroSemNomesRepetidos();
        System.out.println("Após adição de novos carros");
        CarroRepositorio.listarTodos();
        MontadoraRepositorio.listarTodas();

        /**
         * Tentando cadastrar um carro com nome existente!
         */
        cenarioNomeRepetido();
        System.out.println("Após tentativa de carros com nomes repetidos");
        CarroRepositorio.listarTodos();
        MontadoraRepositorio.listarTodas();
    }

    private static void inicializar() {
        Carro carro1 = new Carro("Celta", "LT", 2000, 12.000);
        Carro carro2 = new Carro("Fusca", "1000", 1960, 5.000);
        Carro carro3 = new Carro("Uno", "Mile", 2000, 12.000);

        Montadora montadora1 = new Montadora("Chevrolet", "EUA");
        if (!CarroRepositorio.consultar(carro1.getNome())) {
            montadora1.addCarro(carro1);
            MontadoraRepositorio.cadastrar(montadora1);
            CarroRepositorio.cadastrarNome(carro1.getNome());
        } else {
            System.out.println("Carro existe no registro de carro!");
        }

        Montadora montadora2 = new Montadora("Volkswagem", "Alemanha");
        if (!CarroRepositorio.consultar(carro2.getNome())) {
            montadora2.addCarro(carro2);
            MontadoraRepositorio.cadastrar(montadora2);
            CarroRepositorio.cadastrarNome(carro2.getNome());
        } else {
            System.out.println("Carro existe no registro de carro!");
        }
        Montadora montadora3 = new Montadora("Fiat", "Itália");
        if (!CarroRepositorio.consultar(carro3.getNome())) {
            montadora3.addCarro(carro3);
            MontadoraRepositorio.cadastrar(montadora3);
            CarroRepositorio.cadastrarNome(carro3.getNome());
        } else {
            System.out.println("Carro existe no registro de carro!");
        }
    }

    private static void cenarioAcionaCarroSemNomesRepetidos() {
        Carro carro4 = new Carro("Prisma", "LTZ", 2005, 18.000);
        Montadora montadora1 = MontadoraRepositorio.consultar("Chevrolet");
        if (montadora1 != null) {
            if (!CarroRepositorio.consultar(carro4.getNome())) {
                montadora1.addCarro(carro4);
                MontadoraRepositorio.adicionarCarro(montadora1);
                CarroRepositorio.cadastrarNome(carro4.getNome());
            } else {
                System.out.println("Carro existe no registro de carro!");
            }
        } else {
            System.out.println("Montadora não encontrada!");
        }

        Carro carro5 = new Carro("Gol", "1000", 1990, 8.000);
        Montadora montadora2 = MontadoraRepositorio.consultar("Volkswagem");
        if (montadora2 != null) {
            if (!CarroRepositorio.consultar(carro5.getNome())) {
                montadora2.addCarro(carro5);
                MontadoraRepositorio.adicionarCarro(montadora2);
                CarroRepositorio.cadastrarNome(carro5.getNome());
            } else {
                System.out.println("Carro existe no registro de carro!");
            }
        } else {
            System.out.println("Montadora não encontrada!");
        }

        Carro carro6 = new Carro("Tempra", "XE", 1990, 10.000);
        Montadora montadora3 = MontadoraRepositorio.consultar("Fiat");
        if (montadora3 != null) {
            if (!CarroRepositorio.consultar(carro6.getNome())) {
                montadora3.addCarro(carro6);
                MontadoraRepositorio.adicionarCarro(montadora3);
                CarroRepositorio.cadastrarNome(carro6.getNome());
            } else {
                System.out.println("Carro existe no registro de carro!");
            }
        } else {
            System.out.println("Montadora não encontrada!");
        }
    }

    private static void cenarioNomeRepetido() {
        // Carro existente no registro de carros.
        Carro carro7 = new Carro("Uno", "Mile", 2000, 12.000);

        System.out.println("Tentando inserir o carro: ");
        System.out.println(carro7);
        
        Montadora montadora7 = MontadoraRepositorio.consultar("Fiat");        
        if (montadora7 != null) {
            if (!CarroRepositorio.consultar(carro7.getNome())) {
                montadora7.addCarro(carro7);
                MontadoraRepositorio.cadastrar(montadora7);
                CarroRepositorio.cadastrarNome(carro7.getNome());
            } else {
                System.out.println("Carro existe no registro de carro!");
            }
        } else {
            System.out.println("Montadora não encontrada!");
        }
    }

}
