#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    fprintf(f2,"%d %d\n",altura, largura);
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
  struct pixel matrix2[largura][altura];
  
    int indiceL = largura;
   for(int m = 0; m < largura; m++){
        indiceL--;
       for(int n = 0; n < altura; n++){
          matrix2[m][n] = matrix[n][indiceL];
          
       }     
   }
   for(int i = 0; i< largura; i++){
       for(int j = 0; j< altura; j++){
            fprintf(output, "%d %d %d\n", matrix2[i][j].r,  matrix2[i][j].g,  matrix2[i][j].b );
       }
   }
   
  
    fclose(imagem);
    fclose(output);

    return 0;
}
