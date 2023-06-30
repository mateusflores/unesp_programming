package br.unesp.rc.lista02.exercicio02.modelo;

/**
 *
 * @author Prof. Dr. Frank J. Affonso
 */
public class Produto {

    private String codigo;
    private String nome;
    private double preco;
    private double descontoMaximo;

    public Produto() {
    }

    public Produto(String codigo, String nome, double preco, double descontoMaximo) {
        this.codigo = codigo;
        this.nome = nome;
        this.preco = preco;
        this.descontoMaximo = descontoMaximo;
    }

    public String getCodigo() {
        return codigo;
    }

    public void setCodigo(String codigo) {
        this.codigo = codigo;
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public double getPreco() {
        return preco;
    }

    public void setPreco(double preco) {
        this.preco = preco;
    }

    public double getDescontoMaximo() {
        return descontoMaximo;
    }

    public void setDescontoMaximo(double descontoMaximo) {
        this.descontoMaximo = descontoMaximo;
    }

    @Override
    public String toString() {
        return "Produto{" + "codigo=" + codigo + ", nome=" + nome + ", preco=" + preco + ", descontoMaximo=" + descontoMaximo + '}';
    }

}
