#include <stdio.h>

void store_zeros(int *vecPtr, int n) {
    
    while(n > 0){
        *vecPtr = 0;
        ++vecPtr;
        n--;
    }
}

int main(){
    int n = 10;
    int vec[10] = {1,2,3,4,5,6,7,8,9,10};


    store_zeros(vec, n);

    for(int i = 0; i < n; i++) printf("%d", vec[i]);
    
    return 0;
}