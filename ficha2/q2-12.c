#include <stdio.h>
#include <stdlib.h>

char *procurar(char *str, char ch){
    while(*str != ch && *str != '\0'){
        str++;
    }
    if(*str != '\0') return str;
    return NULL;
}

int main(){
    char ch = 'B';
    char vec[15] = "moro em Braga";
    char vec2[15] = "moro no Porto";

    printf("%p\n", procurar(vec, ch));
    printf("%p\n", procurar(vec2, ch));
    return 0;
}