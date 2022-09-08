// Mateus Gomes Flores
#include <stdio.h>

int main() {
    int i = 0, quantDados, semExtensao = 0, somaExtensao = 0;
    float media;

    printf("\nInforme quantos dados pretende informar: ");
    scanf("%d", &quantDados);

    int ra[quantDados], atividadesExtensao[quantDados], atividadesPesquisa[quantDados];


    for (i; i < quantDados; i++) {
        if (quantDados-i-1 != 0) {
            printf("\nInforme os dados do aluno %d (depois, mais %d) - RA: ", i+1, quantDados-i-1);
        } else {
            printf("\nInforme os dados do aluno %d (ultimo) - RA: ", i+1);
        }
        scanf("%d", &ra[i]);
        printf("\nInforme a CH de extensao: ");
        scanf("%d", &atividadesExtensao[i]);
        printf("\nInforme a CH de pesquisa: ");
        scanf("%d", &atividadesPesquisa[i]);
    }

    for (i = 0; i <quantDados; i++) {
        if (atividadesExtensao[i] == 0) {   // Calculando quantos alunos nao fizeram horas de extensao
            semExtensao++;
        }

        somaExtensao = somaExtensao + atividadesExtensao[i];    // Obtendo a soma das horas de extensao para posteriormente calcular a media
    }

    media = (somaExtensao/quantDados);      // Calculo da media

    printf("\n\n---DADOS DAS ATIVIDADES---");
    printf("\n\n=> %d alunos nao fizeram atividades de extensao. ", semExtensao);
    printf("\n=> A media de AC em extensao eh: %.2f horas", media);
    printf("\n\nAlunos que completaram 210 horas de AC:\n");
    printf("\n---------\n");
    printf("|  RA   |\n");
    printf("|-------|\n");
    for (i = 0; i < quantDados; i++) {
        if ((atividadesExtensao[i] + atividadesPesquisa[i]) >= 210) {
            printf("|  %d  |\n", ra[i]);
        }
    }
    printf("---------\n");
}