#include <stdio.h>

int comparar(char *str1, char *str2){
    while(*str1 == *str2 && *str1 != '\0' && *str2 != '\0'){
        str1++;
        str2++;
    }
    if(*str1 == '\0' && *str2 == '\0') return 1;
    return 0;
}

int main(){

    char vec1[15] = "Portugal";
    char vec2[15] = "Portugal";
    char vec3[15] = "Porto";

    printf("%d",comparar(vec1, vec2));
    printf("%d",comparar(vec2, vec3));    

    return 0;
}