package br.unesp.rc.lista04.exercicio04;

import br.unesp.rc.lista04.exercicio04.modelo.Atributo;
import br.unesp.rc.lista04.exercicio04.modelo.Classe;
import br.unesp.rc.lista04.exercicio04.utils.GeradorUtils;
import java.util.Scanner;

/**
 *
 * @author frank
 */
public class Demo {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        Classe classe = new Classe();

        System.out.printf("Digite o nome do pacote: ");
        classe.setPacote(scan.nextLine());
        System.out.println();

        System.out.printf("Digite o nome da classe: ");
        classe.setNome(scan.nextLine());
        System.out.println();

        int n;
        System.out.printf("Entre com o número de atributos da classe: ");
        n =  Integer.parseInt(scan.nextLine());
        System.out.println();

        for (int i = 1; i <= n; i++) {
            Atributo atributo = new Atributo();

            System.out.println("-----------" + i + "-----------");

            System.out.printf("Modificador: ");
            atributo.setModificador(scan.nextLine());
            //System.out.println();

            System.out.printf("Tipo: ");
            atributo.setTipo(scan.nextLine());
            //System.out.println();

            System.out.printf("Nome: ");
            atributo.setNome(scan.nextLine());
            //System.out.println();

            classe.addAtributo(atributo);
        }

        System.out.println();
        System.out.println("-------------------------------------------");
        System.out.println(GeradorUtils.printaCodigo(classe));
        System.out.println("-------------------------------------------");
    }
}
