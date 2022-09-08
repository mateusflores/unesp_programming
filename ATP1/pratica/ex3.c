#include <stdio.h>
int main() {
    int dia;
    printf("Digite o número do dia da semana (de 1 a 7)\n");
    scanf("%d", &dia);

    switch (dia){
        case 1: printf("Domingo\n\n");
        break;
        case 2: printf("Segunda\n\n");
        break;
        case 3: printf("Terça\n\n");
        break;
        case 4: printf("Quarta\n\n");
        break;
        case 5: printf("Quinta\n\n");
        break;
        case 6: printf("Sexta\n\n");
        break;
        case 7: printf("Sábado\n\n");
        break;
    }
}