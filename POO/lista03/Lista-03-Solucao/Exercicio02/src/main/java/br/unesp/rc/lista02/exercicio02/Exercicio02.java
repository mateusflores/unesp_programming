package br.unesp.rc.lista02.exercicio02;

import br.unesp.rc.lista02.exercicio02.modelo.Carrinho;
import br.unesp.rc.lista02.exercicio02.modelo.Cliente;
import br.unesp.rc.lista02.exercicio02.modelo.Item;
import br.unesp.rc.lista02.exercicio02.modelo.Produto;
import br.unesp.rc.lista02.exercicio02.repositorio.CarrinhoRepositorio;
import br.unesp.rc.lista02.exercicio02.repositorio.ClienteRepositorio;
import br.unesp.rc.lista02.exercicio02.repositorio.ProdutoRepositorio;

/**
 *
 * @author Prof. Dr. Frank J. Affonso
 */
public class Exercicio02 {

    public static void main(String[] args) {
        /**
         * Inicializando os repositórios do sistema
         */
        inicializarSistema();

        /**
         * Cenário: criação de um carrinho para um cliente com dois itens
         */
        criarCarrinho();
        System.out.println("=============================================");
        System.out.println("=== CRIAÇÃO DO CARRINHO COM DOIS PRODUTOS ===");
        System.out.println("=============================================");
        CarrinhoRepositorio.listarTodos();
        System.out.println("=============================================");

        /**
         * Cenário: recuperação de carrinho e tentativa de inserção de um
         * produto que existe nesse carro.
         *
         * Resulado: apenas a quantidade desse produto deve ser incrementada.
         */
        Carrinho carrinho = CarrinhoRepositorio.getCarrinhoPorID(1);

        Produto produto2 = ProdutoRepositorio.consultarPorCodigo("345-4");
        Item item3 = new Item();
        item3.setQuantidade(5);
        item3.setValorVenda(20);
        item3.setProduto(produto2);

        carrinho.addItens(item3);
        System.out.println("=============================================");
        System.out.println("=== ADIÇÃO DO MESMO PRODUTO AO CARRINHO =====");
        System.out.println("=============================================");
        CarrinhoRepositorio.listarTodos();
        System.out.println("=============================================");

        /**
         * Cenário: remoção de um produto do carrinho.
         */
        // Aproveitando o carrinho do passo anterior;
        long idCarrinho = carrinho.getIdCarrinho();
        Produto produtoRemover = ProdutoRepositorio.consultarPorCodigo("234-4");
        CarrinhoRepositorio.removerProduto(idCarrinho, produtoRemover);

        System.out.println("=============================================");
        System.out.println("=== REMOÇÃO DE UM PRODUTO DO CARRINHO =======");
        System.out.println("=============================================");
        CarrinhoRepositorio.listarTodos();
        System.out.println("=============================================");
    }

    public static void inicializarSistema() {
        /**
         * Inicializando o repositorio de cliente
         */
        Cliente c1 = new Cliente("Java Man da Silva", "123");
        Cliente c2 = new Cliente("Java Man da Costa", "234");
        Cliente c3 = new Cliente("Java Man Ameiiida", "345");
        Cliente c4 = new Cliente("Java Man Alburque", "456");
        Cliente c5 = new Cliente("Java Man Pereiira", "567");

        ClienteRepositorio.cadastrar(c1);
        ClienteRepositorio.cadastrar(c2);
        ClienteRepositorio.cadastrar(c3);
        ClienteRepositorio.cadastrar(c4);
        ClienteRepositorio.cadastrar(c5);

        ClienteRepositorio.listarTodos();
        System.out.println("---");

        /**
         * Inicializando o reposito de produtos
         */
        Produto p1 = new Produto("234-4", "Caneta esferográfica azul", 2.0, 20);
        Produto p2 = new Produto("345-4", "Papel A4 - 500 folhas", 20, 10);
        Produto p3 = new Produto("456-4", "Pasta dura cores", 5.0, 20);
        Produto p4 = new Produto("567-4", "Caderno brochura 100 folhas", 10, 20);
        Produto p5 = new Produto("678-4", "Caderno espeiral 400 folhas", 30, 20);

        ProdutoRepositorio.cadastrar(p1);
        ProdutoRepositorio.cadastrar(p2);
        ProdutoRepositorio.cadastrar(p3);
        ProdutoRepositorio.cadastrar(p4);
        ProdutoRepositorio.cadastrar(p5);

        ProdutoRepositorio.listarTodos();
        System.out.println("---");
    }

    public static void criarCarrinho() {
        Carrinho carrinho = new Carrinho();
        carrinho.setIdCarrinho(1);

        // Acionando cliente ao carrinho
        Cliente cliente = ClienteRepositorio.consultarPorCpf("123");
        carrinho.setCliente(cliente);

        // Adicionando itens
        Produto produto1 = ProdutoRepositorio.consultarPorCodigo("234-4");
        Item item1 = new Item();
        item1.setQuantidade(2);
        item1.setValorVenda(2);
        item1.setProduto(produto1);

        Produto produto2 = ProdutoRepositorio.consultarPorCodigo("345-4");
        Item item2 = new Item();
        item2.setQuantidade(3);
        item2.setValorVenda(20);
        item2.setProduto(produto2);

        carrinho.addItens(item1);
        carrinho.addItens(item2);
        CarrinhoRepositorio.cadastrar(carrinho);
    }
}
