#include <stdio.h>
#include <string.h>

int tamanho;

void inverter(char *str){
    int metade = tamanho / 2;
    char temp;
    int inicio = 0;

    while(metade > 0){
        temp = *(str + tamanho);
        *(str + tamanho) = *(str + inicio);
        *(str + inicio) = temp;  
        metade--;
    }
    

}

int main(){


    char vec[5] = "roma";
    tamanho = strlen(vec);


    inverter(vec);

    printf("%s",vec);
 
    return 0;
}