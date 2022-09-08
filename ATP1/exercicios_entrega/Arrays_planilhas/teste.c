#include <stdio.h>
int main() {
    int array[10], i = 0;
    
    for (i; i < 10; i++) {
        if (i % 2 == 0) {
            array[i] = i;
        } else {
            array[i] = 0;
        }
    }

    for (i = 0; i < 10; i++) {
        printf("%d", array[i]);
    }
}

// se for org e M
// 