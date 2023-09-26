#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct stackItem {
    char letter;
    struct stackItem *next;
} StackItem;

typedef struct stack {
    struct stack *top;
} Stack;

Stack* push(Stack *stk, char letter) {

}

Stack* pop(Stack *stk) {
    if (isEmpty(stk))
        return;
    
}

Stack* createStack() {
    Stack *aux = malloc(sizeof(StackItem));
    aux->top = NULL;
    return aux;
}

bool isEmpty(Stack *stk) {
    return (stk->top == NULL);
}

int main() {
    char word[30];
    puts("Enter a word or phrase. ('*' will remove the top item)");
    fgets(word, 30, stdin);



}