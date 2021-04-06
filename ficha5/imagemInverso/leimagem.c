#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#define MAX 200

struct pixel
{
    char arr[MAX];
    
}*Ptrpixel;


int largura;
int altura; 


Ptrpixel invertImagem(struct pixel vetor, int tamanho){
    typedef struct pixel vetor_aux;
    int j = tamanho -1;
    for(int i = 0; i < j; i++){
        vetor_aux[i].arr = vetor[j].arr;
        j--;
    } 

    return vetor_aux;
}




int main(int argc, char *argv[])
{
    int i = 0;
    FILE *in = fopen(argv[1], "r");
    FILE *out = fopen(argv[2], "w");
    if (!in)
    {
        printf("erro no arquivo de leitura");
        exit(1);
    }
    if (!out)
    {
        printf("erro no arquivo de escrita");
    }
    while (i < 3)
    {
        char cabeca[70];
        fgets(cabeca, 67, in);
        if (cabeca[0] == '#') continue;

        else if(i == 1 && cabeca[0] != '#'){
            fscanf(in, "%d %d", &largura, &altura);
        }
        else
        {
            fputs(out, cabeca);
            i++;
        }
    }
     int h = largura * altura;

    typedef struct pixel vetor[h];

    while (!feof(in)|| i < h){
        char corpo[300];
        fgets(corpo, 290, in);
        if(corpo[0] == '#') continue;

        else{
            (*vetor[i]).arr = corpo;
            i++;
        }
    }

    inverteImagem(vetor, h);



    fclose(in);
    fclose(out);

    return 0;
}