#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compara( const void *a, const void *b) {
  return *(char*)a - *(char*)b;
}


void ordenar(char str[]){
    qsort(str, strlen(str), sizeof(char), compara);

}

int anagramas(char str1[], char str2[]){
    if(strlen(str1) != strlen(str2)) return 0;
    ordenar(str1);
    ordenar(str2);
    for(int i = 0; str1[i] != '\0'; i++){
        if(str1[i] != str2[i]) return 0;
    }
    return 1;
}

int main(){

    char str1[10] = "roma";
    char str2[10] = "amor";
    char str3[10] = "mar";

    int r = anagramas(str1,str2);
    int r2 = anagramas(str1, str3);

    printf("r = %d\nr2 = %d", r, r2);

    return 0;
}