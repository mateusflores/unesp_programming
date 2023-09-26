package br.unesp.rc.lista02.exercicio02.repositorio;

import br.unesp.rc.lista02.exercicio02.modelo.Cliente;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Prof. Dr. Frank J. Affonso
 */
public class ClienteRepositorio {

    private static List<Cliente> clientes = new ArrayList<>();

    private ClienteRepositorio() {
    }

    public static void cadastrar(Cliente cliente) {
        if (!clientes.contains(cliente)){
            clientes.add(cliente);
        }
    }
    
    public static Cliente consultarPorCpf(String cpf) {
        Cliente cliente = null;
        
        for (Cliente c : clientes){
            if (c.getCpf().equals(cpf)){
                cliente = c;
            }
        }
        
        return cliente;
    }
    
    public static void listarTodos() {
        for(Cliente c : clientes){
            System.out.println(c);
        }
    }

}
