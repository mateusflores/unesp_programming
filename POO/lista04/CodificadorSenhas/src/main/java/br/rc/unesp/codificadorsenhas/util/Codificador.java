/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package br.rc.unesp.codificadorsenhas.util;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

/**
 *
 * @author aluno
 */
public class Codificador {
    private StringBuilder caracteres;

    public Codificador() {
    }
    
    private String geraRandomChars() {
        Random rand = new Random();
        StringBuilder chars = new StringBuilder();
        for (int i=0; i<3; i++) {
            chars.append((char)(rand.nextInt(87) + 35));
        }
        return chars.toString();
    }
    
    // Retorna um novo caractere ao somar um número na tabela ASCII
    private void trocaChar(boolean flag) {
        if (flag == true) {
            for (int i = 0; i<caracteres.length(); i++) {
                caracteres.setCharAt(i, (char)((int)caracteres.charAt(i) + i + 1));
            }
        } else {
            for (int i = 0; i<caracteres.length(); i++) {
                caracteres.setCharAt(i, (char)((int)caracteres.charAt(i) - i - 1));
            }           
        }
    }
    
    // Adiciona letras aleatórias entre os caracteres
    private void addRandomChar(boolean flag) {
        String senhaAntiga = caracteres.toString();
        StringBuilder novaSenha = new StringBuilder();
        if (flag) {
            for (int i = 0; i<senhaAntiga.length(); i++) {
                novaSenha.append(geraRandomChars());
                novaSenha.append(senhaAntiga.charAt(i));
            }
        } else { 
            int cont = 0;
            for (int i = 0; i<senhaAntiga.length(); i++) {
                cont++;
                if (cont == 4) { 
                    novaSenha.append(senhaAntiga.charAt(i));
                    cont = 0;
                }
            }
        } 
        this.caracteres = novaSenha;
    }
    
    private void inverter () {
        this.caracteres.reverse();
    }
    
    public String codificarSenha(String senha) {
        this.caracteres = new StringBuilder(senha);
        trocaChar(true);
        addRandomChar(true);
        inverter();
        
        
        return caracteres.toString();
    }
    
    public String decodificarSenha(String senha) {
        caracteres = new StringBuilder(senha);
        inverter();
        addRandomChar(false);
        trocaChar(false);
       
        return caracteres.toString();
    }
}
