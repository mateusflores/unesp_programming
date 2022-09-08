#include <stdio.h>

int main() {
	char* nome;
	
	printf("\nDigite seu nome: ");
	scanf("%s", &nome);
	
	printf("Seu nome eh %s", &nome); 
	
}
