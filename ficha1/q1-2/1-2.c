#include <stdio.h>
#include <string.h>


int palidromo(char str[]){
    int flag = 0;
    int i  = 0;
    int j = strlen(str) - 1;
    
    for(; str[i] != '\0'; i++){
        if(str[i] != str[j]) flag = 1;
        j--;
    }
    return flag;
}


int main(){

printf("%d\n", palidromo("ana"));
printf("%d\n", palidromo("mar"));
return 0;

}