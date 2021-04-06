#include <stdio.h>
#include <ctype.h>

int contar_espacos(char *str){
    int acc = 0;

    while(*str != '\0'){
        if(isspace(*str)) acc++;
        ++str;
    }
    return 0;
}



int main(){

    char vec[50] = "eheu iuhiueh wuhwiu wuhwiuh wuhwiu wuih wriu u ";

    printf("total de espaços: %d", contar_espacos(vec));
    return 0;
}