#include <stdio.h>

int my_len(char *s) {
    char *tmp = s;

    while (*s != '\0') {
        s++;
    }
    
    return s-tmp;
}

int main() {
    char s[1024] = "Hello!";
    printf("%d\n", my_len(s));

}