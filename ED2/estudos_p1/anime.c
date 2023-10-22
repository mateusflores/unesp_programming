#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "animes.dat"

FILE* createFile() {
    FILE* file = fopen(FILE_NAME, "wb+");
    if (file == NULL)
        exit(4);
    return file;
}

int main() {
    FILE* f = createFile();
    
    fclose(f);
}