//Mateus Gomes Flores
#include <stdio.h>

int main() {
    float atp1, atp2, ed1, ed2, media1, media2;

    printf("\nInforme a nota de ATP do candidato 1: ");
    scanf("%f", &atp1);
    printf("\nInforme a nota de ED do candidato 1: ");
    scanf("%f", &ed1);


    printf("\nInforme a nota de ATP do candidato 2: ");
    scanf("%f", &atp2);
    printf("\nInforme a nota de ED do candidato 2: ");
    scanf("%f", &ed2);

    media1 = (atp1+ed1)/2;
    media2 = (atp2+ed2)/2;

    if (media1>media2){
        printf("\nO melhor candidato é o candidato 1, seguido do 2.\n\n");
    } else if (media2>media1) {
        printf("\nO melhor candidato é o candidato 2, seguido do 1.\n\n");
    } else if (atp1>atp2) {
        printf("\nO melhor candidato é o candidato 1, seguido do 2.\n\n");
    } else if (atp2>atp1) {
        printf("\nO melhor candidato é o candidato 2, seguido do 1.\n\n");
    } else {
        printf("\nO melhor candidato é o candidato 1, seguido do 2.\n\n");
    }
}