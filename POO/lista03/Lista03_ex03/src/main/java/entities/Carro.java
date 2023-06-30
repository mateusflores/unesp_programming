/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package entities;

/**
 *
 * @author aluno
 */
public class Carro {
    private String nome;
    private String modelo;
    private int anoProjeto;
    private double valorCusto;

    public Carro(String nome, String modelo, int anoProjeto, double valorCusto) {
        this.nome = nome;
        this.modelo = modelo;
        this.anoProjeto = anoProjeto;
        this.valorCusto = valorCusto;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getModelo() {
        return modelo;
    }

    public void setModelo(String modelo) {
        this.modelo = modelo;
    }

    public int getAnoProjeto() {
        return anoProjeto;
    }

    public void setAnoProjeto(int anoProjeto) {
        this.anoProjeto = anoProjeto;
    }

    public double getValorCusto() {
        return valorCusto;
    }

    public void setValorCusto(double valorCusto) {
        this.valorCusto = valorCusto;
    }
    
    
}
