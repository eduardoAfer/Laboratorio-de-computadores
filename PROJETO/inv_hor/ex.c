#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000



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
    m2 += 2;
    int j = 0;
    for (; c[m2] != ' '; m2++)
    {

        alturaChar[j] = c[m2];
        j++;
    }

    altura = atoi(alturaChar);
    largura = atoi(larguraChar);
}

//lê e esceve apenas as informaçoes da cabeça do arquivo sem as cores e comentarios
void cabeca(FILE *in, FILE *out)
{
    int i = 0;
    char c[100];
    while (i < 3)
    {

        fgets(c, 600, in);

        if (c[0] == '#')
            continue;
        else
        {
            if (i == 1)
                dimensaoMatrix(c); //atribui às variaveis largura e altura a dimensao linhas colunas da imagem

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

    
    char c[9000];
    char mat[altura * largura][MAX];
    for (int i = 0; i < altura * largura; i++)
    {

        fgets(c, 8990, imagem);
        int m_ultimo;
        for (int m = 0; c[m] != '\0' && c[m] != '#'; m++)
        {
            //fputc(c[m], output);
            mat[i][m] = c[m];
            m_ultimo = m;
        }
        m_ultimo++;
        mat[i][m_ultimo] = '\n';
        //if(i != altura*largura ) fputc('\n', output);
    }
    int inicio  = 0;
    int final = largura -1;

    for(int i = 0; i < altura; i++){
        char temp[1][MAX];
        int j = inicio;
        int m = final;
        while (j < m)
        {
            for(int d = 0; mat[m][d] != '\0';d++){
                temp[0][d] = mat[m][d];
            }
            for(int d = 0; mat[j][d] != '\0';d++){
                mat[m][d] = mat[j][d];
            }
            for(int d = 0; temp[0][d] != '\0';d++){
                mat[j][d] = temp[0][d];
            }
            
            j++;
            m--;
        }
        for (int f = inicio; f <= final; f++)
        {
            fputs(mat[f], output);
           // fputc('\n', output);
        }
        inicio = final+1;
        final += largura;

    }

    //printf("%s", mat[3]);

    //flipH(mat, 0, largura - 1, output);




    // corpo(imagem, matrix);

    //printf("matrux = %s", matrix[3].linha);

    //printf("altura = %d\nlargura = %d", altura ,largura);
    //flipHor(matrix, 0, largura, output);

    fclose(imagem);
    fclose(output);

    return 0;
}
