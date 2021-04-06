#include <stdio.h>
#include <stdlib.h>

int sizeOfArray;

int compara(const void *a, const void *b){
    return ( *(int*)a - *(int*)b );
}


int filtrar_positivos(int vec[], int size){
    int i = 0, j = 0;

    qsort(vec, size, sizeof(int), compara); 
    for(; vec[i] <= 0 && i < size; i++);
    if(i == 0) return *vec; //caso nao tenha numeros neg 
    sizeOfArray = size - i;
    int vec_aux[sizeOfArray];
    for(; j < sizeOfArray - 1; j++){
        vec_aux[j] = vec[i];
        i++; 
    }
    vec = &vec_aux[0];
    return *vec;
}


int main(){

    int vec[6] = {-3, 7, -90, 0, 6, -1};


    filtrar_positivos(vec, 6);

    for(int i = 0; i < sizeOfArray; i++){
        printf("%d ", vec[i]);
    }

    return 0;
}