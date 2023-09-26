/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package br.rc.unesp.contapalavras.util;

/**
 *
 * @author aluno
 */
public class RelacaoPalavras {
    private String palavra;
    private int ocorrencias;

    public RelacaoPalavras(String palavra, int ocorrencias) {
        this.palavra = palavra;
        this.ocorrencias = ocorrencias;
    }

    public String getPalavra() {
        return palavra;
    }

    public void setPalavra(String palavra) {
        this.palavra = palavra;
    }

    public int getOcorrencias() {
        return ocorrencias;
    }

    public void setOcorrencias(int ocorrencias) {
        this.ocorrencias = ocorrencias;
    }
    
    public void adicionarOcorrencia() {
        this.ocorrencias++;
    }
}
