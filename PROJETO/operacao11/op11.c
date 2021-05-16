#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 20

struct pixel
{
    int r;
    int g;
    int b;
};


struct ponto{
    int a,b;
};

//altura e largura da matriz
int altura;
int largura;
int maxColor;

void cabeca(FILE* f1, FILE* f2){

    char str[3];
    fgets(str, 3, f1);
    fprintf(f2, "%s\n", str);
    fscanf(f1, "%d %d", &largura, &altura);
    fprintf(f2,"%d %d\n",largura, altura);
    fscanf(f1, "%d", &maxColor);
    fprintf(f2,"%d\n",maxColor);
}

int main(int argc, char *argv[])
{
    FILE *imagem;
    FILE *output;
    //abertura dos arquivos enciados como parâmetros
    if(argc == 7){
        imagem = fopen(argv[5], "r");
        output = fopen(argv[6], "w");
    }
    else if(argc == 5){
        imagem = stdin;
        output = stdout;
    }
    else if(argc == 6){
        imagem  = fopen(argv[5], "r");
        output = stdout;
    }
    if(!stdin || !stdout){
        printf("ERROR"); 
        exit(1);
    } 

    struct ponto p1, p2;
     
    p1.a = atoi(argv[1]);
    p2.b = atoi(argv[2]);
    p2.a = atoi(argv[3]);
    p2.b = atoi(argv[4]);

    cabeca(imagem, output);

    int alturaMat2 = (p2.a - p1.a) + 1;
    int larguraMat2 = (p2.b - p1.b) +1;

    struct pixel matrix[altura][largura];
    struct pixel matrix2[alturaMat2][larguraMat2];


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
    
   for(int m = 0; m < alturaMat2; m++){
       for(int n = 0; n < larguraMat2; n++){

           matrix2[m][n] =  matrix[m + p1.a][n + p1.b];
       
            }
       }    
   
   for(int i = 0; i< altura; i++){
       for(int j = 0; j< largura; j++){
            fprintf(output, "%d %d %d\n", matrix2[i][j].r,  matrix2[i][j].g,  matrix2[i][j].b );
       }
   }  
    fclose(imagem);
    fclose(output);

    return 0;
}
