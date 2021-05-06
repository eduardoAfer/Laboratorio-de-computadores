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



/*
void dimensaoMatrix(char c[]){
    int m2;
    char alturaChar[5] = {'\0'};
    char larguraChar[5] = {'\0'};

    for (int m = 0; c[m] != ' '; m++){

        larguraChar[m] = c[m];
        m2 = m;
    }
    m2 += 2;
    int j = 0;
    for (; c[m2] != ' '; m2++){

        alturaChar[j] = c[m2];
        j++;
    }
    

    altura = atoi(alturaChar);
    largura = atoi(larguraChar);
}

//lê e esceve apenas as informaçoes da cabeça do arquivo sem as cores e comentarios
void cabeca(FILE *in, FILE *out){
    int i = 0;
    char c[100];
    while (i < 3){

        fgets(c, 99, in);
        if (c[0] == '#') continue;
        else{
            if (i == 1) dimensaoMatrix(c); //atribui às variaveis largura e altura a dimensao linhas colunas da imagem

            for (int j = 0; c[j] != '\0'; j++){
                if (c[j] != '#'){
                    fputc(c[j], out);
                }
                else{
                    fputc('\n', out);
                    break;
                }
            }
        }
        i++;
    }
}
*/



int main(int argc, char *argv[]){
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
    int mudaG = atoi(argv[2]);
    int mudaB = atoi(argv[3]);

        cabeca(imagem, output);

        struct pixel matrix[altura][largura];

        int c;
        for (int i = 0; i < altura; i++){ //importa pixel do arquivo para matriz
            for (int j = 0; j < largura; j++){

                fscanf(imagem, "%d", &c);
                matrix[i][j].r = c;
                fscanf(imagem, "%d", &c);
                matrix[i][j].g = c;
                fscanf(imagem, "%d", &c);
                matrix[i][j].b = c;
                //printf("%d", matrix[i][j].r);
            }
        }
        for(int i = 0; i < altura; i++){
            for(int j = 0; j < largura; j++){

                matrix[i][j].r += mudaR;
                if(matrix[i][j].r > maxColor) matrix[i][j].r = maxColor;
                else if(matrix[i][j].r < 0) matrix[i][j].r = 0;

                matrix[i][j].g += mudaG;
                if(matrix[i][j].g > maxColor) matrix[i][j].g = maxColor;
                else if(matrix[i][j].g < 0) matrix[i][j].g = 0;

                matrix[i][j].b += mudaB;
                if(matrix[i][j].b > maxColor) matrix[i][j].b = maxColor;
                else if(matrix[i][j].b < 0) matrix[i][j].b = 0;

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
