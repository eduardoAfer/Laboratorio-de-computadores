#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200

struct quadro
{
    char linha[MAX];
};

//altura e largura da matriz
int altura;
int largura;

void dimensaoMatrix(char c[])
{
    int m2;
    char alturaChar[5];
    char larguraChar[5];

    for (int m = 0; c[m] != ' '; m++)
    {
        
        larguraChar[m] = c[m];
        m2 = m;
    }
    m2+=2;
    int j = 0;
    for (; c[m2] != ' '; m2++)
    {

        alturaChar[j] = c[m2];
        j++;
        
    }
    
    altura = atoi(alturaChar);
    largura = atoi(larguraChar);
   

}

//lê e esceve apenas as informaçoes da cabeça do arquivo sem as cores
void cabeca(FILE *in, FILE *out)
{
    int i = 0;
    char c[100];
    while (i < 3)
    {

        fgets(c, 99, in);

        if (c[0] == '#')
            continue;
        else
        {
            if (i == 1)
                dimensaoMatrix(c);

            for (int j = 0; c[j] != '\0'; j++)
            {
                if (c[j] != '#')
                {
                    fputc(c[j], out);
                }
                else
                {
                    fputc('\n', out);
                    break;
                }
            }
        }

        i++;
    }
}



int main(int argc, char *argv[])
{
    //abertura dos arquivos enciados como parâmetros
    FILE *imagem = fopen(argv[1], "r");

    FILE *output = fopen(argv[2], "w");

    //caso haja erro na abertura dos arquivos informa e fecha o programa
    if (!imagem)
    {
        printf("Erro na abertura da imagem");
        exit(1);
    }
    if (!output)
    {
        printf("Erro na abertura do arquivo destino");
        exit(1);
    }

    cabeca(imagem, output);
    

    struct quadro matrix[altura*largura];

    char c[300];
    for(int i = 0; i < altura*largura; i++){
        
            fgets(c, 299, imagem);
           
            for(int m = 0; c[m] != '\0' && c[m] != '#'; m++){
                //fputc(c[m], output);
                matrix[i].linha[m] = c[m];
            }
            //if(i != altura*largura ) fputc('\n', output);
            
    }
  
    

   // corpo(imagem, matrix);

    //printf("altura = %d\nlargura = %d", altura, largura);

    fclose(imagem);
    fclose(output);

    return 0;
}
