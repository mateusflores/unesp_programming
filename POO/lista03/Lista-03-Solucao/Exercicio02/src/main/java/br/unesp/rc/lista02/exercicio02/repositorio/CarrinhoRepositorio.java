package br.unesp.rc.lista02.exercicio02.repositorio;

import br.unesp.rc.lista02.exercicio02.modelo.Carrinho;
import br.unesp.rc.lista02.exercicio02.modelo.Item;
import br.unesp.rc.lista02.exercicio02.modelo.Produto;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/**
 *
 * @author Prof. Dr. Frank J. Affonso
 */
public class CarrinhoRepositorio {
    
    private static List<Carrinho> carrinhos = new ArrayList<>();

    private CarrinhoRepositorio() {
    }
    
    public static void cadastrar(Carrinho carrinho){
        carrinhos.add(carrinho);
    }
            
    public static void listarTodos(){
        for (Carrinho c : carrinhos){
            System.out.println(c);
        }
    }
    
    public static Carrinho getCarrinhoPorID(long idCarrinho){
        Carrinho carrinho = null;
        
        Iterator iteratorCarrinho = carrinhos.iterator();
        
        while (iteratorCarrinho.hasNext()) {
            Carrinho carrinhoExistente = (Carrinho) iteratorCarrinho.next();
            if (carrinhoExistente.getIdCarrinho() == idCarrinho){
                carrinho = carrinhoExistente;
            }
        }
        
        return carrinho;
    }
    
    public static boolean removerProduto(long idCarrinho, Produto produtoRemover){
        boolean b = false;
        
        Iterator iteratorCarrinho = carrinhos.iterator();
        
        while (iteratorCarrinho.hasNext()) {
            Carrinho carrrinho = (Carrinho) iteratorCarrinho.next();
            if (carrrinho.getIdCarrinho() == idCarrinho){
                List<Item> itensCarrinho = carrrinho.getItens();
                Iterator iteratorItem = itensCarrinho.iterator();
                
                while (iteratorItem.hasNext() && b == false) {
                    Item item = (Item) iteratorItem.next();
                    if (item.getProduto().getNome().equals(produtoRemover.getNome())){
                        iteratorItem.remove();
                        b = true;
                    }                    
                }
            }
        }
        
        return b;
    }
    
}
