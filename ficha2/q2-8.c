#include <stdio.h>

int mdc(int a, int b){
    int resto;

    while(resto != 0){
        resto = a % b;
        a = b;
        b = resto;
    }
  
    return a;
}


 void reduzir(int *pnum, int *pdenom){
     int divisor = mdc(*pnum, *pdenom);

     *pnum /= divisor;
     *pdenom /= divisor;

 }



int main(){
    int num, deno;

    printf("numerador e denominador\n");
    scanf("%d %d", &num, &deno);

    reduzir(&num, &deno); 

    printf("forma reduzida = %d/%d", num, deno);
}