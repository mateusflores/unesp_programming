#include <stdio.h>

int main() {
    int num1, num2;
    printf("\nDigite dois números: \n");
    scanf("%d %d", &num1, &num2);

    if (num1>num2) {
        printf("\n%d é maior que %d\n\n", num1, num2);
    } else{
        printf("%d é maior que %d\n\n", num2, num1);
    }

}