/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package br.rc.unesp.contapalavras.util;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author aluno
 */
public class ContadorPalavras {
    private String texto;
    private List<RelacaoPalavras> ocorrencias = new ArrayList<>();

    public ContadorPalavras(String texto) {
        this.texto = texto;
    }

    public String getTexto() {
        return texto;
    }

    public void setTexto(String texto) {
        this.texto = texto;
    }
    
    private boolean verificaOcorrencia(String palavra) {
        for (int i = 0; i < ocorrencias.size(); i++) {
            if (palavra.equals(ocorrencias.get(i).getPalavra())) {
                ocorrencias.get(i).adicionarOcorrencia();
                return false;
            }
        }
        return true;
    }
    
    public void contaOcorrencias() {
        String palavras[] = this.texto.split(" ");
        
        for (int i=0; i<palavras.length; i++) {
            if (verificaOcorrencia(palavras[i].toLowerCase()) && palavras[i].length() > 2)
                ocorrencias.add(new RelacaoPalavras(palavras[i].toLowerCase(), 1));
        }
    }
    
    public void exibirRelacao() {
        System.out.println("Ocorrência de palavras no texto:");
        for (int i=0; i<ocorrencias.size(); i++) {
            System.out.printf("Palavra: %s | Ocorrência: %d\n", ocorrencias.get(i).getPalavra(), ocorrencias.get(i).getOcorrencias());
        }
    }
    
}
