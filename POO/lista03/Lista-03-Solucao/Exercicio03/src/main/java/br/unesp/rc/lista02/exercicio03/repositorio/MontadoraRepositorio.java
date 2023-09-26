package br.unesp.rc.lista02.exercicio03.repositorio;

import br.unesp.rc.lista02.exercicio03.modelo.Carro;
import br.unesp.rc.lista02.exercicio03.modelo.Montadora;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Prof. Dr. Frank J. Affonso
 */
public class MontadoraRepositorio {
    
    private static List<Montadora> montadoras = new ArrayList<>();
    
    private MontadoraRepositorio() {
        
    }
    
    public static void cadastrar(Montadora montadora) {
        montadoras.add(montadora);
    }
    
    public static Montadora consultar(String nome) {
        Montadora montadora = null;
        
        for (Montadora m : montadoras){
            if (m.getNome().equals(nome)){                
                montadora = m;
            }
        }
        
        return montadora;
    }
    
    public static void adicionarCarro(Montadora montadora) {
        //-------------------------------------------
        // Consultado se o carro existe
        //-------------------------------------------
        List<Carro> carros = montadora.getCarros();
        int achou = 0;
        for (Carro c : carros) {            
            if (CarroRepositorio.consultar(c.getNome())) {
                achou = 1;                
            }
        }
        if (achou == 0) {
            for (Montadora m : montadoras) {
                if (m.getNome().equals(montadora.getNome())) {
                    m.addCarro(montadora.getCarros());
                }
            }
        }
    }
    
    public static void listarTodas() {
        System.out.println("---");
        for (Montadora m : montadoras) {
            System.out.println(m);
        }
        System.out.println("---");
    }
}
