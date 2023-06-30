package br.unesp.rc.lista02.exercicio02.modelo;

/**
 *
 * @author Prof. Dr. Frank J. Affonso
 */
public class Item {

    private int quantidade;
    private double valorVenda;
    private Produto produto;

    public Item() {
    }

    public Item(int quantidade, double valorVenda, Produto produto) {
        this.quantidade = quantidade;
        this.valorVenda = valorVenda;
        this.produto = produto;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }

    public double getValorVenda() {
        return valorVenda;
    }

    public void setValorVenda(double valorVenda) {
        this.valorVenda = valorVenda;
    }

    public Produto getProduto() {
        return produto;
    }

    public void setProduto(Produto produto) {
        this.produto = produto;
    }

    @Override
    public String toString() {
        return "Item{" + "quantidade=" + quantidade + ", valorVenda=" + valorVenda + ", produto=" + produto + '}';
    }

}
