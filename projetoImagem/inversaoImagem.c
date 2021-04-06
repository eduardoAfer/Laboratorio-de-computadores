#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *imagem;
    FILE *invertida;
    char texto[100];
    int cont = 0, i, j;
    int matriz[50][150];
    imagem = fopen(argv[1], "r");
    invertida = fopen(argv[2], "w");
    while (!feof(imagem))
    {
        fgets(texto, 80, imagem);
        cont++;
        if (cont < 5)
        {
            fprintf(invertida, "%s", texto);
        }
    }
    cont = 0;
    rewind(imagem);
    while (!feof(imagem))
    {
        fgets(texto, 80, imagem);
        cont++;
        if (cont > 4)
        {
            for (i = 0; i < 50; i++)
            {
                for (j = 0; j < 150; j++)
                {
                    fscanf(imagem, "%d", &matriz[j]);
                    printf("%d\n", matriz[j]);
                }
            }
        } //fim do if
    }     //fim do while
    for (i = 49; i >= 0; i--)
    {
        for (j = 0; j < 150; j++)
        {
            fprintf(invertida, "%d\n", matriz[j]);
        }
    }
    fclose(imagem);
    fclose(invertida);
    return 0;
}
