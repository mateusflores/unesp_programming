package br.unesp.rc.lista02.exercicio03.modelo;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Prof. Dr. Frank J. Affonso
 */
public class Montadora {

    private String nome;
    private String pais;
    private List<Carro> carros = new ArrayList<>();

    public Montadora() {
    }

    public Montadora(String nome, String pais) {
        this.nome = nome;
        this.pais = pais;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getPais() {
        return pais;
    }

    public void setPais(String pais) {
        this.pais = pais;
    }

    public List<Carro> getCarros() {
        return carros;
    }

    public void setCarros(List<Carro> carros) {
        this.carros = carros;
    }

    public void addCarro(List<Carro> carros) {
        this.carros.addAll(carros);
    }

    public void addCarro(Carro carro) {
        this.carros.add(carro);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("Nome.......: ").append(this.nome).append("\n");
        sb.append("País.......: ").append(this.pais).append("\n");
        sb.append("Carros.....: ").append("\n");
        for (Carro c : this.getCarros()) {
            sb.append("--->").append(c).append("\n");
        }

        return sb.toString();
    }

}
