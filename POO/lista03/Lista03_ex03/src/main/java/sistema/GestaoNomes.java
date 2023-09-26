/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package sistema;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

/**
 *
 * @author aluno
 */
public class GestaoNomes {
    private Map<String, MarcaCarro> nomesCarros = new HashMap<>();

    public GestaoNomes() {
    }
    
    public boolean addCarro(MarcaCarro mc) {
        Set<String> keyNomes = nomesCarros.keySet();
        for (String m : keyNomes) {
            if (mc.getCarro().getNome().equals(m)) {
                System.out.println("Não foi possível inserir o veículo " + 
                        mc.getCarro().getNome() 
                        + "\nO nome já existe.");
                return false;
            }
        }
        nomesCarros.put(mc.getCarro().getNome(), mc);
        return true;
    }
    
    public void exibirNomes() {
        Set<String> keyNomes = nomesCarros.keySet();
        int i = 1;
        for (String nome : keyNomes) {
            System.out.println("---- " + i + "º" + "ENTRADA ----");
            i++;
            System.out.println("Montadora: " + nomesCarros.get(nome).getMontadora().getNome() +
                    "\nNome do Carro: " + nomesCarros.get(nome).getCarro().getNome() +
                    "\nAno de fabricação: " + nomesCarros.get(nome).getCarro().getAnoProjeto() +
                    "\nModelo: " + nomesCarros.get(nome).getCarro().getModelo() +
                    "\nCusto de fabricação: " + nomesCarros.get(nome).getCarro().getValorCusto());
        }
    }
}
