#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200

struct quadro
{
    char linha[MAX];
} QUADRO;

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

        fgets(c, 99, in);

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

void inverteIntervalo(struct quadro matrix[], FILE *out, int initial, int final)
{

    int j = final;
    int m = initial;

    while (j != m)
    {

        struct quadro temp;
        temp = matrix[m];
        matrix[j] = temp;
        matrix[m] = matrix[j];

        j--;
        m++;
    }
    for (int i = initial; i <= final; i++)
    {
        fputs(matrix[i].linha, out);
    }
}

int flipHor(struct quadro matrix[], int initial, int final, FILE *out)
{

    //printf("%s", matrix[0].linha);
    if (final >= largura * altura)
        return 1;

    else
    {

        inverteIntervalo(matrix, out, initial, final);
        initial = final + 1;
        final += largura;

        return flipHor(matrix, initial, final, out);
    }
}
/*

int  flipH(char mat[][], int inicio, int final, FILE *out)
{
    if (final >= largura * altura)
        return 1;
    else
    {
        char temp[final - inicio][MAX];
        int j = inicio;
        int m = final;
        while (j < m)
        {
            char temp[final - inicio][MAX] = mat[m];
            mat[m] = mat[j];
            mat[j] = temp;
            j++;
            m--;
        }
        for (int f = inicio; f <= final; f++)
        {
            fputs(&mat[f], out);
            fputc('\n', out);
        }
        inicio = final+1;
        final += largura;
        return flipH(mat, inicio, final, out);
    }
}*/

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

    struct quadro matrix[altura * largura];

    char c[300];
    char mat[altura * largura][MAX];
    for (int i = 0; i < altura * largura; i++)
    {

        fgets(c, 299, imagem);
        int m_ultimo;
        for (int m = 0; c[m] != '\0' && c[m] != '#'; m++)
        {
            //fputc(c[m], output);
            mat[i][m] = c[m];
            matrix[i].linha[m] = c[m];
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
