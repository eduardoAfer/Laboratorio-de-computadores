#include <stdio.h>
#include <stdlib.h>


void esp(char *s){
    for(int i = 0; s[i] != '\0'; i++){
        if((s[i] >= 'A' || s[i] <= 'Z') && (s[i] >= 'a' || s[i] <= 'z') );
        else s[i] = ' ';
    }
}

void print(char *s){
    for(int i = 0; s[i] != '\0'; i++) printf("%d", s[i]);

}
int main(){
    char *s;

    scanf("%s", s);

    esp(s);
    print(s);
}