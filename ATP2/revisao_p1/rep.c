#include <stdio.h>

int my_pow(int a, int b) {
    int pow = 1;
    for (int i=0; i<b; i++) {
        pow *= a;
    }

    return pow;
}

int quant_alg(int n) {
    int i = 0, num = n;

    while (num >= 1) {
        i++;
        num /= 10;
    }

    return i;
}

int main() {
    int a = 123, alg[1024], pot = 1;
    int i = quant_alg(a) - 1;

    while (i < quant_alg(a)) {
        alg[i] = a % my_pow(10, pot) - ;
        pot++;
        i--;
    }

    for (i=0; i<quant_alg(a); i++) {
        printf("\n%do num: %d\n", i+1, alg[i]);
    }
}