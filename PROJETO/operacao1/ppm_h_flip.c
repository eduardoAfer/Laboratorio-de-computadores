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
                matrix[i][j].g = c;
                fscanf(imagem, "%d", &c);
                matrix[i][j].b = c;
                //printf("%d", matrix[i][j].r);
            }
        }
        int larguraAux = largura;
        for(int i = 0; i < altura; i++){
            larguraAux = largura -1;
            for(int j = 0; j < larguraAux; j++){

                struct pixel temp = matrix[i][j];
                matrix[i][j] = matrix[i][larguraAux];
                matrix[i][larguraAux] = temp;

                larguraAux--;
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
