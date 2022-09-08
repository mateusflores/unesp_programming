// Mateus Gomes Flores
#include <stdio.h>

int main() {
    int numeroItens = 0, i = 0, quantidadeOrganicos = 0, quantCenouraUsual = 0;
    float pesoTotal = 0, maiorPreco = -1000, somaPrecoCenoura = 0, menorPrecoUsual = 10000, gastoHortaMagica = 0;
    char prodUsualMenorPreco;

    printf("\nInforme quantos quantos itens pretende informar: ");
    scanf("%d", &numeroItens);

    char fornecedor[numeroItens], tipo_produto[numeroItens], nome_produto[numeroItens], listaCompras[numeroItens];
    float peso[numeroItens], preco[numeroItens];

    for (i; i < numeroItens; i++) {
        if (numeroItens-i-1 != 0) {             
            printf("\nInforme o Item %d (depois mais %d)\n", i+1, numeroItens-i-1);
        } else {
            printf("\nInforme o Item %d (ultimo)\n", i+1);
        }

        printf("=> Fornecedor: [H para Horta Magica, M para Momento da Colheita, N para Natureza ecologica]: ");
        scanf("\n%c", &fornecedor[i]);
        printf("=> Informe se eh organico: [O para organico e U para usual]: ");
        scanf("\n%c", &tipo_produto[i]);
        printf("=> Informe o produto: [A para abobrinha, B para brocolis, C para cenoura]: ");
        scanf("\n%c", &nome_produto[i]);
        printf("=> Informe a quantidade adquirida (em gramas): ");
        scanf("%f", &peso[i]);
        printf("=> Informe o preco por quilo: ");
        scanf("%f", &preco[i]);
    }

    for (i = 0; i < numeroItens; i++) {
        pesoTotal = pesoTotal + peso[i];    // Somando o peso total dos produtos

        if (maiorPreco < preco[i]) {        // Checando qual o maior preco 
            maiorPreco = preco[i];
        }

        if (tipo_produto[i] == 'O') {       // Verificando a quantidade de produtos organicos inseridos
            quantidadeOrganicos++;
        }

        if ((tipo_produto[i] == 'U') && (nome_produto[i] == 'C')){      // Obtendo soma do preco e quantidade de cenouras usuais para posteriormente calcular a media de preco
            somaPrecoCenoura = somaPrecoCenoura + preco[i];
            quantCenouraUsual++;
        }

        if ((tipo_produto[i] == 'U') && (preco[i] < menorPrecoUsual)) {     // Checando o menor preco de um produto usual
            menorPrecoUsual = preco[i];
            prodUsualMenorPreco = nome_produto[i];
        }

        if (fornecedor[i] == 'H') {                             // Somando o total gasto na Horta magica
            gastoHortaMagica = gastoHortaMagica + preco[i];
        }

        if ((tipo_produto[i] == 'O') && (fornecedor[i] == 'M')) {   // Guarda o nome do produto em uma lista de compras, caso o produto seja organico e seja fornecido pela 'Momento Colheita'
            listaCompras[i] = nome_produto[i];
        } 
    }

    printf("\n---INFORMACOES SOBRE OS DADOS INSERIDOS---");
    printf("\nO peso total dos produtos adquiridos eh: %.2f gramas", pesoTotal);
    printf("\nO produto mais caro custa R$ %.2f", maiorPreco);
    printf("\nA quantidade total de produtos organicos adquiridos foi: %d produtos", quantidadeOrganicos);

    if (quantCenouraUsual == 0) {
        printf("\nNao houve compra de cenoura usual, logo nao eh possivel calcular a media");
    } else {
        printf("\nA media do preco da cenoura não organica foi de R$ %.2f", (somaPrecoCenoura/quantCenouraUsual));
    }
    
    switch (prodUsualMenorPreco) {
        case 'A':   
            printf("\nO produto usual mais barato eh a abobrinha, custando R$ %.2f", menorPrecoUsual);
            break;
        case 'B':
            printf("\nO produto usual mais barato eh o brocolis, custando R$ %.2f", menorPrecoUsual);
            break;
        case 'C':
            printf("\nO produto usual mais barato eh a cenoura, custando R$ %.2f", menorPrecoUsual);
            break;
    }

    printf("\nO valor total gasto na Horta magica foi de R$ %.2f", gastoHortaMagica);
    printf("\nLista de compras de produtos organicos no 'Momento de Colheita' para a proxima semana:\n");

    for (i = 0; i < numeroItens; i++) {
        switch (listaCompras[i]) {
            case 'A': 
                printf("- Abobrinha\n");
                break;
            case 'B':
                printf("- Brocolis\n");
                break;
            case 'C':
                printf("- Cenoura\n");
                break;
        }
    }
}