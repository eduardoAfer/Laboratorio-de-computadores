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
    FILE *imagem;
    FILE *output;
    //abertura dos arquivos enciados como parâmetros
    if(argc == 3){
        imagem = fopen(argv[1], "r");
        output = fopen(argv[2], "w");
    }
    else if(argc == 1){
        imagem = stdin;
        output = stdout;
    }
    else if(argc == 2){
        imagem  = fopen(argv[1], "r");
        output = stdout;
    }
    if(!stdin || !stdout){
        printf("ERROR"); 
        exit(1);
    } 
    cabeca(imagem, output);

    struct pixel matrix[altura][largura];
    struct pixel matrix2[altura][largura];


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
   
   for(int i = 0; i< altura; i++){
       for(int j = 0; j< largura; j++){
            if(i == 0 || i == altura - 1 || j == 0 || j == largura - 1){
                matrix2[i][j].r = 0;
                matrix2[i][j].g = 0;
                matrix2[i][j].b = 0;
            }  
            else{

                int cor =( 8* matrix[i][j].r ) - (matrix[i - 1][j - 1].r + matrix[i -1 ][j].r  + matrix[i - 1][j + 1].r  + matrix[i][j-1].r  +
                                                 matrix[i][j +1].r  + matrix[i +1][j-1].r  + matrix[i+1][j].r  + matrix[i+1][j+1].r );
                if(cor < 0) cor = 0;
                if(cor > maxColor) cor = maxColor;
                matrix2[i][j].r = cor;
                matrix2[i][j].g = cor;
                matrix2[i][j].b = cor;

            }         
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
