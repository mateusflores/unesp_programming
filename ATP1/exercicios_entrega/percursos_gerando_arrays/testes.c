#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
   float soma = 10.0, aux = 3.0;
   float media, mediaTruncada;

   mediaTruncada = (soma/(soma%aux))/aux;
   printf("\n\n%f\n\n", mediaTruncada);
   media = 5.0/2.0;
   printf("%.2f\n\n", media);
}