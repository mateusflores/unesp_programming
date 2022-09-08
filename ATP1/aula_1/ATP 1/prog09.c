#include <stdio.h>

struct saude {
	char* nome;
	int idade;
	float altura;
	float peso;
};

int main() {

	struct saude ficha001;
	ficha001.nome = "Mateus";
	ficha001.idade = 22;
	ficha001.altura = 1.79;
	ficha001.peso = 90;
		
}