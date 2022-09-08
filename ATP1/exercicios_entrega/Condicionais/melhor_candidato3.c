//Mateus Gomes Flores
#include <stdio.h>

int main() {
    float atp1, atp2, atp3, ed1, ed2, ed3, media1, media2, media3;

    printf("\nInforme a nota de ATP do candidato 1: ");
    scanf("%f", &atp1);
    printf("\nInforme a nota de ED do candidato 1: ");
    scanf("%f", &ed1);

    printf("\nInforme a nota de ATP do candidato 2: ");
    scanf("%f", &atp2);
    printf("\nInforme a nota de ED do candidato 2: ");
    scanf("%f", &ed2);

    printf("\nInforme a nota de ATP do candidato 3: ");
    scanf("%f", &atp3);
    printf("\nInforme a nota de ED do candidato 3: ");
    scanf("%f", &ed3);

    media1 = (atp1+ed1)/2;
    media2 = (atp2+ed2)/2;
    media3 = (atp3+ed3)/2;

    if (media1>media2 && media1>media3 && media2!=media3){
        if (media2>media3){
            printf("\n\nO melhor candidato eh o candidato 1, seguido do candidato 2, seguido do candidato 3.\n\n");
        } else{
            printf("\n\nO melhor candidato eh o candidato 1, seguido do candidato 3, seguido do candidato 2.\n\n");
        }
    } else if (media2>media3 && media2>media1 && media1!=media3){
        if (media1>media3){
            printf("\n\nO melhor candidato eh o candidato 2, seguido do candidato 1, seguido do candidato 3.\n\n");
        } else{
            printf("\n\nO melhor candidato eh o candidato 2, seguido do candidato 3, seguido do candidato 1.\n\n");
        }
    } else if (media3>media1 && media3>media2 && media1!=media2){
        if (media1>media2){
            printf("\n\nO melhor candidato eh o candidato 3, seguido do candidato 1, seguido do candidato 2.\n\n");
        } else{
            printf("\n\nO melhor candidato eh o candidato 3, seguido do candidato 2, seguido do candidato 1.\n\n");
        }
    } else if (media1==media2 && media1!=media3){     //Casos em que duas medias sao iguais
        if (media3>media1) {
            if (atp1>=atp2) {
                printf("\n\nO melhor candidato eh o candidato 3, seguido do candidato 1, seguido do candidato 2.\n\n");
            } else {
                printf("\n\nO melhor candidato eh o candidato 3, seguido do candidato 2, seguido do candidato 1.\n\n");
            }
        } else if (media1>media3) {             
            if (atp1>=atp2) {
                printf("\n\nO melhor candidato eh o candidato 1, seguido do candidato 2, seguido do candidato 3.\n\n");
            } else {
                printf("\n\nO melhor candidato eh o candidato 2, seguido do candidato 1, seguido do candidato 3.\n\n");
            }
        }
    } else if (media1==media3 && media1!=media2){
        if (media2>media1) {
            if (atp1>=atp3) {
                printf("\n\nO melhor candidato eh o candidato 2, seguido do candidato 1, seguido do candidato 3.\n\n");
            } else {
                printf("\n\nO melhor candidato eh o candidato 2, seguido do candidato 3, seguido do candidato 1.\n\n");
            }
        } else if (media1>media2) {             
            if (atp1>=atp3) {
                printf("\n\nO melhor candidato eh o candidato 1, seguido do candidato 3, seguido do candidato 2.\n\n");
            } else {
                printf("\n\nO melhor candidato eh o candidato 3, seguido do candidato 1, seguido do candidato 2.\n\n");
            }
        }
    } else if (media2==media3 && media2!=media1){
        if (media1>media2) {
            if (atp2>=atp3) {
                printf("\n\nO melhor candidato eh o candidato 1, seguido do candidato 2, seguido do candidato 3.\n\n");
            } else {
                printf("\n\nO melhor candidato eh o candidato 1, seguido do candidato 3, seguido do candidato 2.\n\n");
            }
        } else if (media2>media1) {             
            if (atp2>=atp3) {
                printf("\n\nO melhor candidato eh o candidato 2, seguido do candidato 3, seguido do candidato 1.\n\n");
            } else {
                printf("\n\nO melhor candidato eh o candidato 3, seguido do candidato 2, seguido do candidato 1.\n\n");
            }
        }
    } else {            //Condicao em que todas as medias sao iguais, criterio de desempate == nota de atp
        if (atp1>atp2 && atp1>atp3 && atp2>atp3) {
            printf("\n\nO melhor candidato eh o candidato 1, seguido do candidato 2, seguido do candidato 3\n\n");
        } else if (atp1>atp2 && atp1>atp3 && atp3>atp2){
            printf("\n\nO melhor candidato eh o candidato 1, seguido do candidato 3, seguido do candidato 2\n\n");
        } else if (atp2>atp3 && atp3>atp1){
            printf("\n\nO melhor candidato eh o candidato 2, seguido do candidato 3, seguido do candidato 1\n\n");
        } else if (atp2>atp3 && atp1>atp3){
            printf("\n\nO melhor candidato eh o candidato 2, seguido do candidato 1, seguido do candidato 3\n\n");
        } else if (atp1>atp2) {
            printf("\n\nO melhor candidato eh o candidato 3, seguido do candidato 1, seguido do candidato 2\n\n");
        } else if (atp2>atp1) {
            printf("\n\nO melhor candidato eh o candidato 3, seguido do candidato 2, seguido do candidato 1\n\n");
        } else {
            printf("\n\nO melhor candidato eh o candidato 1, seguido do candidato 2, seguido do candidato 3\n\n");  //Caso medias e nota de atp sejam iguais, criterio de desempate eh candidato 1, seguido de candidato 2, seguido de candidato 3
        }
    }
}           