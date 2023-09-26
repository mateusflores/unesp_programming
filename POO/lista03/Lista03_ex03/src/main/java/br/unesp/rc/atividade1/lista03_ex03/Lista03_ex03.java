/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Project/Maven2/JavaApp/src/main/java/${packagePath}/${mainClassName}.java to edit this template
 */

package br.unesp.rc.atividade1.lista03_ex03;

import entities.Carro;
import entities.Montadora;
import sistema.GestaoNomes;
import sistema.MarcaCarro;

/**
 *
 * @author aluno
 */
public class Lista03_ex03 {

    public static void main(String[] args) {
        Carro c1 = new Carro("Uno", "1.0", 2015, 60000.00);
        Carro c2 = new Carro("Argo", "1.5", 2018, 70000.00);
        Carro c3 = new Carro("Pulse", "1.2", 2012, 90000.00);
        Carro c4 = new Carro("Ranger", "2.0", 2019, 50000.00);
        Carro c5 = new Carro("Ka", "1.0", 2005, 20000.00);
        Carro c6 = new Carro("Maverick", "1.7", 2022, 60000.00);
        Carro c7 = new Carro("Maverick", "1.6", 2011, 30000.00);
        
        
        Montadora m1 = new Montadora("Fiat", "EUA");
        Montadora m2 = new Montadora("Ford", "EUA");
        
        GestaoNomes gestao = new GestaoNomes();
        gestao.addCarro(new MarcaCarro(c1, m1));
        gestao.addCarro(new MarcaCarro(c2, m1));
        gestao.addCarro(new MarcaCarro(c3, m1));
        gestao.addCarro(new MarcaCarro(c4, m2));
        gestao.addCarro(new MarcaCarro(c5, m2));
        gestao.addCarro(new MarcaCarro(c6, m2));
        gestao.addCarro(new MarcaCarro(c7, m2));
        
        
        
        gestao.exibirNomes();
    }
}
