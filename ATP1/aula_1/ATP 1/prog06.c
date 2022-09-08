#include <stdio.h>
int main() {

	float temperatura;
	printf("Digite uma temperatura em graus oF: ");
	scanf("%f", &temperatura);

	float celsius;
	celsius = (temperatura - 32.0) * 5.0 / 9.0;
	
	printf("O valor convertido da temperatura eh %f", celsius);
	
}