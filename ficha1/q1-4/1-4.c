#include <stdio.h>
#include <stdlib.h>

int compara(const void *a, const void *b){
    return ( *(int*)a - *(int*)b );
}


int repetidos(int vec[], unsigned size){
    int i = 0, flag = 0;
    qsort(vec, size, sizeof(int), compara);
    
    for(; i < size -1; i++){
        if(vec[i] == vec[i+1]) flag = 1;
    }
    return flag;
}

int main(){

    int arr[6] = {4,2,6,7,8,2};


    printf("%d", repetidos(arr, 6));

    return 0;
}