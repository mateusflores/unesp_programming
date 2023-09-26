package br.unesp.rc.lista02.exercicio02.repositorio;

import br.unesp.rc.lista02.exercicio02.modelo.Produto;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Prof. Dr. Frank J. Affonso
 */
public class ProdutoRepositorio {
    
    private static List<Produto> produtos = new ArrayList<>();

    private ProdutoRepositorio() {
    }

    public static void cadastrar(Produto produto) {
        if (!produtos.contains(produto)){
            produtos.add(produto);
        }
    }
    
    public static Produto consultarPorCodigo(String codigo) {
        Produto produto = null;
        
        for (Produto p : produtos){
            if (p.getCodigo().equals(codigo)){
                produto = p;
            }
        }
        
        return produto;
    }
    
    public static void listarTodos() {
        for(Produto p : produtos){
            System.out.println(p);
        }
    }
    
}
