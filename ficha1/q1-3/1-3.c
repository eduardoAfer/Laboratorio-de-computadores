#include <stdio.h>
#include <string.h>
#include <math.h>

int decimal(char str[]){
  //expoente recebe o tamanho do array str menos 1
 int exp  = strlen(str) - 1;
 int digit, num = 0, i = 0;

//varrer o array para formar o digit e o retornar
 for(;str[i] != '\0'; i++){
     digit = str[i] - '0';
     //10 na potencia exp 
     int mult = pow(10, exp);
     num += digit*mult;
     exp--; 
 }
 return num;
}


int main(){
    
  printf("%d", decimal("54321"));

  return 0;
}