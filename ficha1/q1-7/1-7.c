#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compara( const void *a, const void *b) {
  return *(char*)a - *(char*)b;
}


void ordenar(char str[]){
    qsort(str, strlen(str), sizeof(char), compara);
}

int main(){

    char str[10] = "olamundo";

    ordenar(str);

    //for(int i = 0; str[i] != '\0'; i++)
    printf("%s",str);
    return 0;
}