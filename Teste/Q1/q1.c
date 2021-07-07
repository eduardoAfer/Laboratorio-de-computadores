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
    int media_R = 0, media_G = 0, media_B = 0;
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
                media_R += c;        
                fscanf(imagem, "%d", &c);
                matrix[i][j].g = c;
                media_G += c;
                fscanf(imagem, "%d", &c);
                matrix[i][j].b = c;
                media_B += c;
            }
        }

        media_R = media_R/(altura * largura);
        media_G = media_G/(altura * largura);
        media_B = media_B/(altura * largura);
    
        if(media_R > media_G && media_R > media_B){

            for (int i = 0; i < altura; i++){ //importa pixel do arquivo para matriz
                for (int j = 0; j < largura; j++){

                    matrix[i][j].g = 0;
                    matrix[i][j].b = 0;
                }
            }
        }
         if(media_G > media_R && media_G > media_B){
            for (int i = 0; i < altura; i++){ //importa pixel do arquivo para matriz
                for (int j = 0; j < largura; j++){

                    matrix[i][j].r = 0;
                    matrix[i][j].b = 0;
                }
            }
        }
         if(media_B > media_R && media_B > media_G ){

            for (int i = 0; i < altura; i++){ //importa pixel do arquivo para matriz
                for (int j = 0; j < largura; j++){

                    matrix[i][j].r = 0;
                    matrix[i][j].g = 0;
                }
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
