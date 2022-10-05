#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    bool sinal;
    unsigned short int mag;
} SMINT;

SMINT* soma(SMINT *a, SMINT *b) {
    SMINT* val = (SMINT*) malloc(sizeof(SMINT));
    val->sinal = false;
    if (a->sinal == false && b->sinal == false) {
        val->mag = a->mag + b->mag;
    } else if (a->sinal == false && b->sinal == true) {
        val->mag = (a->mag - b->mag);
        if ((a->mag - b->mag) < 0) {
            val->sinal = true;
        }
    } else if (a->sinal == true && b->sinal == false) {
        val->mag = (b->mag - a->mag);
        if ((b->mag - a->mag) < 0) {
            val->sinal = true;
        }
    } else if (a->sinal == true && b->sinal == true) {
        val->mag = (a->mag + b->mag); 
        val->sinal = true;
    } 
    return val;
}

int main() {
    SMINT* num1 = (SMINT*) malloc(sizeof(SMINT));
    SMINT* num2 = (SMINT*) malloc(sizeof(SMINT));

    num1->sinal = true; num1->mag = 10;
    num2->sinal = false; num2->mag = 15;

    SMINT* res = soma(num1, num2);

    if (res->sinal) {
        printf("-");
    } else {
        printf("+");
    }

    printf("%d\n", res->mag);
}