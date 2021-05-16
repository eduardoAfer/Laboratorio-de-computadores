#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#define MAX 20



struct pixel{
    int r, g, b;
};


//altura e largura da matriz
int altura;
int largura;
int maxColor;

int altura2;
int largura2;
int maxColor2;

void cabeca1(FILE* f1, FILE* f2){
    char str[3];
    fgets(str, 3, f1);
    fprintf(f2, "%s\n", str);
    fscanf(f1, "%d %d", &largura, &altura);
    fprintf(f2,"%d %d\n",largura, altura);
    fscanf(f1, "%d", &maxColor);
    fprintf(f2,"%d\n",maxColor);
}


void cabeca2(FILE* f1){
    char str[3];
    fgets(str, 3, f1);
    fscanf(f1, "%d %d", &largura2, &altura2);
    fscanf(f1, "%d", &maxColor2);
}


int main(int argc, char *argv[])
{
    FILE *imagem;
    FILE *imagem2;
    FILE *output;
    //abertura dos arquivos enciados como parâmetros
    if(argc == 6){
        imagem = fopen(argv[4], "r");
        imagem2 = fopen(argv[3], "r");
        output = fopen(argv[5], "w");
    }
    else if(argc == 3){
        imagem2 = stdin;
        imagem = stdin;
        output = stdout;
    }
    else if(argc == 4){
        imagem  = fopen(argv[4], "r");
        imagem2 = fopen(argv[3], "r");
        output = stdout;
    }
    if(!stdin || !stdout){
        printf("ERROR"); 
        exit(1);
    } 

    int x = atoi(argv[1]);
    int y = atoi(argv[2]);



    cabeca1(imagem, output);
    cabeca2(imagem2);

    struct pixel matrix[altura][largura];
    struct pixel matrix2[altura2][largura2];


    int c;
    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
        {

            fscanf(imagem, "%d", &c);
            matrix[i][j].r = c;
            fscanf(imagem, "%d", &c);
            matrix[i][j].g = c;
            fscanf(imagem, "%d", &c);
            matrix[i][j].b = c;
        }
    }
    int d;
     for (int i = 0; i < altura2; i++)
    {
        for (int j = 0; j < largura2; j++)
        {

            fscanf(imagem2, "%d", &d);
            matrix2[i][j].r = d;
            fscanf(imagem2, "%d", &d);
            matrix2[i][j].g = d;
            fscanf(imagem2, "%d", &d);
            matrix2[i][j].b = d;
        }
    }


   
    for(int i = x; i < altura || i < altura2; i++){
        for(int j = y; j< largura || j < largura2; j++){
            matrix[i][j] = matrix2[i -x][j- y];

        }
    }


   for(int i = 0; i< altura; i++){
       for(int j = 0; j< largura; j++){
            fprintf(output, "%d %d %d\n", matrix[i][j].r,  matrix[i][j].g,  matrix[i][j].b );

       }
   }

  
    fclose(imagem);
    fclose(output);

    return 0;
}
