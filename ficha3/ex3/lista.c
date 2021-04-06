
#include <stdio.h>
#include <stdlib.h>

#define MAX_LISTA 100;

struct pessoa{
    char* nome;
    char* telefone;
};
typedef struct pessoa PESSOA;

PESSOA lista[100];

lista[] = {{"rui", "226664441"}, {"ana", "214444444"}};
int n = 2; // Número de pessoas da lista


int pesquisa(char *pal){
    for(int i = 0; i < n; i++){
        if(lista[i].nome == *pal) return i;
    }
    return -1;
}

int pesqui(int i, char *pal){
     for(int j = i; j < n; j++){
        if(lista[j].nome == *pal) return j;
    }
    return -1;   
}

void tel(char *pal){
    if(pesqui(0, &pal) == -1){
        printf("não exixte!");
    }
    else{
        printf("%d", lista[pesqui(0, &pal)].telefone);
    }
}


int main(){



    char *pal =  "rui";
    int pesquisa(&pal);
    int pesqui(0, &pal);
    int tel(&pal);

    return 0;
}

