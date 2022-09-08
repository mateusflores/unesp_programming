// Mateus Gomes Flores

#include <stdio.h>
int main() {
    int num = 1;

    for (num; num <= 100; num++) {
        if ((num % 3 == 0) && (num % 5 == 0)) {
            printf("FizzBuzz\n");
        } else if (num % 5 == 0) {
            printf("Buzz\n");
        } else if (num % 3 == 0) {
            printf("Fizz\n");
        } else {
            printf("%d\n", num);
        }
    }
}