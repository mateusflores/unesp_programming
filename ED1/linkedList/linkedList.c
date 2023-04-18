#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num;
    List *next;
} List;

List* addNumber(List* node, int n) {
    int flag = 0;

    while (flag == 0) {
    if (node->next == NULL) {
            node->next = malloc(sizeof(List));
            node->next = n;
            node->next = NULL;
            flag++;
        }
    else
        *node = node->next;
    }

}

int main() { 
    List *list;
    addNumber(list, 3);
    addNumber(list, 5);

    while(list->next != NULL)
        printf(" %d ", &list->num);

}