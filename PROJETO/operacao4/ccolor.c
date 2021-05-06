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
    if(argc == 6){
        imagem = fopen(argv[4], "r");
        output = fopen(argv[5], "w");
    }
    else if(argc == 4){
        imagem = stdin;
        output = stdout;
    }
    else if(argc == 5){
        imagem  = fopen(argv[4], "r");
        output = stdout;
    }
    if(!stdin || !stdout){
        printf("ERROR"); 
        exit(1);
    } 
    
   
    int mudaR = atoi(argv[1]);
    int mudaG = atoi (argv[2]);
    int mudaB = atoi(argv[3]);
    

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
                printf("%d", c);



   for(int m = 0; m < altura; m++){
       for(int n = 0; n < largura; n++){

           matrix[m][n].r += mudaR;
           if(matrix[m][n].r > maxColor) matrix[m][n].r = maxColor;
           else if(matrix[m][n].r < 0) matrix[m][n].r = 0;
        
            matrix[m][n].g += mudaG;
           if(matrix[m][n].g > maxColor) matrix[m][n].g = maxColor;
           else if(matrix[m][n].g + mudaG < 0) matrix[m][n].g = 0;
           
            matrix[m][n].b += mudaB;
            if(matrix[m][n].b  > maxColor) matrix[m][n].b = maxColor;
            else if(matrix[m][n].b  < 0) matrix[m][n].b = 0;
           
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
