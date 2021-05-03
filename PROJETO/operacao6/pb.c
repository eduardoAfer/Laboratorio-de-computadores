#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#define MAX 20

struct pixel
{
    int r;
    int g;
    int b;
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
    //abertura dos arquivos enciados como parâmetros
    FILE *imagem = fopen(argv[1], "r");

    FILE *output = fopen(argv[2], "w");


    //caso haja erro na abertura dos arquivos informa e fecha o programa
    if (!imagem)
    {
        printf("Erro na abertura da imagem");
        exit(1);
    }
    if (!output)
    {
        printf("Erro na abertura do arquivo destino");
        exit(1);
    }

    cabeca(imagem, output);

    struct pixel matrix[altura][largura];

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


   
    
   for(int m = 0; m < altura; m++){
       for(int n = 0; n < largura; n++){
           int G = matrix[m][n].r * 0.2126 + matrix[m][n].g * 0.7152 + matrix[m][n].b * 0.0722;
           matrix[m][n].r = G;
           matrix[m][n].g = G;
           matrix[m][n].b = G;
            }
       }    
   
   for(int i = 0; i< altura; i++){
       for(int j = 0; j< largura; j++){
            fprintf(output, " %d %d %d\n", matrix[i][j].r,  matrix[i][j].g,  matrix[i][j].b );
       }
   }  
    fclose(imagem);
    fclose(output);

    return 0;
}
