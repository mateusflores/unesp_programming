#include <stdio.h>
#include <stdlib.h>

int fatorial(int n) {
    if (n == 0)
        return 1;
    else {
        return n * fatorial(n-1);
    }
}

int fib(int n) {
    if (n == 0 || n == 1)
        return n;
    else if (n >=2) 
        return fib(n-2) + fib(n-1);
}

int multAdicao(int a, int b) {
    if (a == 0 || b == 0)
        return 0;
    if (b > 1)
        return a + multAdicao(a, b-1);
}

int main() {
    int n = 6;
    printf("Fatorial de %d eh %d\n", n, fatorial(n));
    printf("Fibonacci de %d eh %d\n", n, fib(n));
    
    int a = 6, b = 5;
    printf("%d x %d = %d\n", a, b, multAdicao(a, b));
}