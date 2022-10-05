#include <stdlib.h>   
#include <stdio.h>
typedef struct {
    int x;
    short int y;
} DATA;
void vesgo(DATA* d) {  
    d->x++;
    d->y--;
}
void vizinho(DATA* d) {   
    (d-1)->x = 1000;
    (d-1)->y = 100;
}
int main(int argc, char** argv) {  
    DATA ar[3];
    vizinho(&ar[1]);
    DATA* b;        
    b =  malloc(sizeof(DATA));
    if ( b != NULL ) {
        b->x = 7; b->y = 3;
        vesgo(b);  
        free(b);
    }

    printf("\n%d\n\n", b -> x);
    printf("\n%d\n\n", b -> y);

}