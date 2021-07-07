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

void cabeca(FILE* f1, FILE* f2, int qntPixel){
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
    
    int qntPixel = atoi(argv[1]); 
    int mudaR = atoi(argv[2]);
    int mudaG = atoi (argv[3]);
    int mudaB = atoi(argv[4]);
    
    struct pixel matrix[altura][largura];

    cabeca(imagem, output, qntPixel);



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


     int controlador = 0;
    int pint = 0;
    for (int i = 0; i < altura; i++)
    {   pint = 0;
        controlador = 0;
        for (int j = 0; j < largura; j++)
        {        
          if(controlador == qntPixel){
              controlador = 0;
              if(pint == 1) pint = 0;
              else pint = 1;

          }  
        if(pint == 1){
            matrix[i][j].r = mudaR;
            matrix[i][j].g = mudaG;
            matrix[i][j].b = mudaB;
        }
        controlador++;

          
        }
    }


    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura ; j++)
        {
            fprintf(output, "%d %d %d\n", matrix[i][j].r, matrix[i][j].g, matrix[i][j].b);
           
        }
    }

    fclose(imagem);
    fclose(output);

    return 0;
}
