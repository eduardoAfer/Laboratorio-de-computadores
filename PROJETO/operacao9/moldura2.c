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
    

    cabeca(imagem, output);

   // struct pixel matrix[altura][largura];
    struct pixel matrix2[altura + 2*qntPixel][largura + 2*qntPixel];
     for (int i = 0; i < altura + 2*qntPixel; i++)
    {
        for (int j = 0; j < largura + 2*qntPixel; j++)
        {            
            matrix2[i][j].r = mudaR;
            matrix2[i][j].g = mudaG;
            matrix2[i][j].b = mudaB;
        }
    }


    int c;
    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
        {

            fscanf(imagem, "%d", &c);
            matrix2[i+qntPixel][j+qntPixel].r = c;
            fscanf(imagem, "%d", &c);
            matrix2[i+qntPixel][j+qntPixel].g = c;
            fscanf(imagem, "%d", &c);
            matrix2[i+qntPixel][j+qntPixel].b = c;
        }
    }


    for (int i = 0; i < altura + 2*qntPixel; i++)
    {
        for (int j = 0; j < largura + 2*qntPixel; j++)
        {
            fprintf(output, "%d %d %d\n", matrix2[i][j].r, matrix2[i][j].g, matrix2[i][j].b);
           
        }
    }

    fclose(imagem);
    fclose(output);

    return 0;
}
