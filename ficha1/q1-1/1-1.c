#include <stdio.h>

int conta_maiores(int vec[], int size, int val){
    int i = 0, acc = 0;
    for(; i < size; i++){
        if(vec[i] > val) acc++;
    }
    return acc;
}


int main(){
    int vec[4] = {1,6,8,3};

    printf("%d", conta_maiores(vec, 4, 1));

    return 0;
}