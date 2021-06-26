#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pixel{
    int r, g, b;
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



int main(int argc, char *argv[]){
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
        
        for (int i = 0; i < altura; i++){ //importa pixel do arquivo para matriz
            for (int j = 0; j < largura; j++){

                fscanf(imagem, "%d", &c);
                matrix[i][j].r = c;        
                fscanf(imagem, "%d", &c);
                matrix[i][j].g = 0;
                fscanf(imagem, "%d", &c);
                matrix[i][j].b = 0;
            }
        }
        

        for(int i = 0; i < altura; i++){
            for(int j = 0; j < largura; j++){
                fprintf(output, "%d %d %d\n", matrix[i][j].r, matrix[i][j].g, matrix[i][j].b );
            }
        }

        
        fclose(imagem);
        fclose(output);
        

    return 0;
}
