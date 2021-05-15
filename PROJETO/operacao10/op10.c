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
int altura1;
int largura1;
int maxColor1;

int altura2;
int largura2;
int maxColor2;

int altura1e2;
int largura1e2;
int maxColor1e2;


void cabeca(FILE* f1){
    char str[3];
    fgets(str, 3, f1);
    fscanf(f1, "%d %d", &largura1, &altura1);
    fscanf(f1, "%d", &maxColor1);
}

void cabeca2(FILE* f1, FILE* f2){
    char str[3];
    fgets(str, 3, f1);
    fprintf(f2, "%s\n", str);
    fscanf(f1, "%d %d", &largura2, &altura2);
    largura1e2 = largura1 + largura2;
    if(altura1 < altura2) altura1e2 = altura1;
    else altura1e2 = altura2;
    fprintf(f2,"%d %d\n", altura1e2, largura1e2);
    fscanf(f1, "%d", &maxColor2);
    if(maxColor1 < maxColor2) maxColor1e2 = maxColor1e2;
    else maxColor1e2 = maxColor1;
    fprintf(f2,"%d\n",maxColor1e2);
}


int max(int i, int j){
    if(i < j) return j;
    return i;
}

int min(int i, int j){
    if(i > j) return j;
    return i;
}

int main(int argc, char *argv[])
{
      FILE *imagem;
      FILE *imagem2;
      FILE *output;
    //abertura dos arquivos enciados como parâmetros
    if(argc == 4){
        imagem = fopen(argv[1], "r");
        imagem2 = fopen(argv[2], "r");
        output = fopen(argv[3], "w");
    }
    else if(argc == 1){
        imagem = stdin;
        imagem2 = stdin; 
        output = stdout;
    }
    else if(argc == 3){
        imagem  = fopen(argv[1], "r");
        imagem2  = fopen(argv[2], "r");
        output = stdout;
    }
     else if(argc == 2){
        imagem  = fopen(argv[1], "r");
        imagem2  = stdin;
        output = stdout;
    }
    if(!stdin || !stdout){
        printf("ERROR"); 
        exit(1);
    } 

    cabeca(imagem);
    cabeca2(imagem2, output);
    

    struct pixel matrix1[altura1][largura1];
    struct pixel matrix2[altura2][largura2];
    struct pixel matrixTotal[altura1e2][largura1e2];

    int c;
    for (int i = 0; i < altura1e2; i++)
    {
        for (int j = 0; j < largura1; j++)
        {

            fscanf(imagem, "%d", &c);
            matrixTotal[i][j].r = c;
            fscanf(imagem, "%d", &c);
            matrixTotal[i][j].g = c;
            fscanf(imagem, "%d", &c);
            matrixTotal[i][j].b = c;
        }
    }

    for (int i = 0; i < altura1e2; i++)
        {
            for (int j = largura1; j < largura1e2; j++)
            {

                fscanf(imagem2, "%d", &c);
                matrixTotal[i][j].r = c;
                fscanf(imagem2, "%d", &c);
                matrixTotal[i][j].g = c;
                fscanf(imagem2, "%d", &c);
                matrixTotal[i][j].b = c;
            }
        }  
   
  
   for(int i = 0; i< altura1e2; i++){
       for(int j = 0; j< largura1e2; j++){
            fprintf(output, "%d %d %d\n", matrixTotal[i][j].r,  matrixTotal[i][j].g,  matrixTotal[i][j].b );
       }
   }
   
  
    fclose(imagem);
    fclose(output);

    return 0;
}
