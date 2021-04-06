#include<stdio.h>
#include <stdlib.h>


int ContLinha(int a[4][10], int n){
    int ctrl[n], acc = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            acc += a[i][j];
        }
        ctrl[i-1] = acc;
        acc = 0;
    }
    for(int i = 0; i < n-1; i++){
        if(ctrl[i] != ctrl[i+1]) return __INT_MAX__;
    }
    return ctrl[0];
}

int ContColuna(int a[4][10], int n){
    int ctrl[n], acc = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            acc += a[j][i];
        }
        ctrl[i-1] = acc;
        acc = 0;
    }
    for(int i = 0; i < n-1; i++){
        if(ctrl[i] != ctrl[i+1]) return RAND_MAX;
    }
    return ctrl[0];
}

int contDiagonal(int a[4][10], int n){
    int ctrl[n], acc = 0;

    for(int i = 1; i <= n; i++) acc += a[i][i];
        ctrl[0] = acc;
        acc = 0;

    for(int i = n; i >= 1; i--) acc += a[i][i];
        ctrl[1] = acc;

    if(ctrl[1] != ctrl[0]) return RAND_MAX;
    
    return ctrl[0];

}

int magico(int a[4][10], int n){

if(ContLinha(a, n) == ContColuna(a, n) == contDiagonal(a, n)) return 1;
return 0;
}




int main(){

    int a[4][10] = {{2, 7, 6, 6, 8, 8, 8, 8, 8, 8},
                    {9, 5, 1, 8, 8, 8, 8, 8, 8, 8},
                    {4, 3, 8, 8, 8, 8, 8, 8, 8, 8},
                    {8, 8, 8, 8, 8, 8, 8, 8, 8, 8}};

    int n = 3;

    int r = magico(a, n);

   
    return 0;
}