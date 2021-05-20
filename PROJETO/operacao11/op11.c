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
int alturaMat2;
int larguraMat2;

void cabeca(FILE* f1, FILE* f2){

    char str[3];
    fgets(str, 3, f1);
    fprintf(f2, "%s\n", str);
    fscanf(f1, "%d %d", &largura, &altura);
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
    p1.b = atoi(argv[2]);
    p2.a = atoi(argv[3]);
    p2.b = atoi(argv[4]);

    cabeca(imagem, output);


    // casos em que os pontos pedidos estao fora da imagem 
  /*  if(p1.a < 0) p1.a = 0;
    if(p1.a >= altura) p1.a = altura - 1;
    if(p1.b < 0) p1.b = 0;
    if(p1.b >= largura) p1.b = largura -1;

*/

    if(p2.a >= altura) alturaMat2 = altura - p1.a;
    else alturaMat2 = p2.a - p1.a +1;


    if(p2.b >= largura) alturaMat2 = altura - p1.b;
    else alturaMat2 = p2.b - p1.b +1;
/*
    if(p2.a < 0) p2.a = 0;
    if(p2.a >= altura) p2.a = altura - 1;
    if(p2.b < 0) p2.b = 0;
    if(p2.b >= largura) p2.b = largura -1;

*/
    alturaMat2 = (p2.b - p1.b) +1;
    larguraMat2 = (p2.a - p1.a) + 1;

    fprintf(output,"%d %d\n",larguraMat2, alturaMat2);
    fscanf(imagem, "%d", &maxColor);
    fprintf(output,"%d\n",maxColor);


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
   
   for(int i_r = 0, i_Img = p1.a; i_r < alturaMat2 && i_Img < altura; i_r++, i_Img++){
       for(int j_r = 0, j_Img = p1.b; j_r < larguraMat2 && j_Img < largura; j_r++, j_Img++){

           matrix2[i_r][j_r] =  matrix[i_Img][j_Img];
       
            }
       }    
   
   for(int i = 0; i< alturaMat2; i++){
       for(int j = 0; j< larguraMat2; j++){
            fprintf(output, "%d %d %d\n", matrix2[i][j].r,  matrix2[i][j].g,  matrix2[i][j].b );
       }
   }  
    fclose(imagem);
    fclose(output);

    return 0;
}
