package br.unesp.rc.lista02.exercicio03.modelo;

/**
 *
 * @author Prof. Dr. Frank J. Affonso
 */
public class Carro {

    private String nome;
    private String modelo;
    private int anoFabricao;
    private double valorCusto;

    public Carro() {
    }

    public Carro(String nome, String modelo, int anoFabricao, double valorCusto) {
        this.nome = nome;
        this.modelo = modelo;
        this.anoFabricao = anoFabricao;
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

    public int getAnoFabricao() {
        return anoFabricao;
    }

    public void setAnoFabricao(int anoFabricao) {
        this.anoFabricao = anoFabricao;
    }

    public double getValorCusto() {
        return valorCusto;
    }

    public void setValorCusto(double valorCusto) {
        this.valorCusto = valorCusto;
    }

    @Override
    public String toString() {
        return "Carro{" + "nome=" + nome + ", modelo=" + modelo + ", anoFabricao=" + anoFabricao + ", valorCusto=" + valorCusto + '}';
    }

}
