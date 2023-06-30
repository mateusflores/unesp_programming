package br.unesp.rc.lista02.exercicio02.modelo;

import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Prof. Dr. Frank J. Affonso
 */
public class Carrinho {

    private long idCarrinho;
    private List<Item> itens = new ArrayList<>();
    private Cliente cliente;

    public Carrinho() {
    }

    public Carrinho(long idCarrinho, List<Item> itens, Cliente cliente) {
        this.idCarrinho = idCarrinho;
        this.itens = itens;
        this.cliente = cliente;
    }

    public long getIdCarrinho() {
        return idCarrinho;
    }

    public void setIdCarrinho(long idCarrinho) {
        this.idCarrinho = idCarrinho;
    }

    public List<Item> getItens() {
        return itens;
    }

    public void setItens(List<Item> itens) {
        this.itens = itens;
    }
    
    public void addItens(Item item) {
        boolean existe = false;
        
        for (Item i : this.itens){
            if (i.getProduto().getCodigo().equals(item.getProduto().getCodigo())){
                i.setQuantidade(i.getQuantidade() + item.getQuantidade());
                existe = true;
            }
        }
        
        if (! existe){            
            this.itens.add(item);
        }
        
    }

    public Cliente getCliente() {
        return cliente;
    }

    public void setCliente(Cliente cliente) {
        this.cliente = cliente;
    }

    @Override
    public String toString() {
        double total = 0;
        
        StringBuilder sb = new StringBuilder();
        sb.append("---").append("\n");
        sb.append("idCarrinho=").append(idCarrinho).append("\n");
        sb.append(cliente).append("\n");
        sb.append("Itens:").append("\n");
        for (Item i : this.getItens()){
            total += i.getQuantidade() * i.getValorVenda();            
            sb.append("-->").append(i).append("\n");
        }
        sb.append("---").append("\n");
        sb.append("TOTAL : ").append(total);
                
        return sb.toString();
    }

}
