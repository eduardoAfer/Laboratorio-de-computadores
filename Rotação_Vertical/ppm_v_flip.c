#include <stdio.h>
#include <stdlib.h>

struct pixel
{
    int r, g, b;
};

int rows;
int cols;
int maxColor;


//send to the output the inverse of PPM image
void ppm_v_flip(FILE* in,FILE* out){
    int ppmPixelData;
    struct pixel matrix[rows][cols];


    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            fscanf(in, "%d", &ppmPixelData);
            matrix[i][j].r = ppmPixelData;
            fscanf(in, "%d", &ppmPixelData);
            matrix[i][j].g = ppmPixelData;
            fscanf(in, "%d", &ppmPixelData);
            matrix[i][j].b = ppmPixelData;
        }
    }
    int acc = 0;
    for(int j = 0; j < cols; j++){
        //printf("%d\n", j);
        int up = 0;
        int down = rows -1;
        while(up != down){
            acc++;
            printf("acc = %d up = %d dow = %d  SOMA = %d\n", acc, up, down, up-down);
            
            struct pixel temp = matrix[up][j];
            matrix[up][j] = matrix[down][j];
            matrix[down][j] = temp; 
            up++;
            down--;
        }
    }

     for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
         fprintf(out, "%d %d %d\n", matrix[i][j].r, matrix[i][j].g, matrix[i][j].b);
        }
    }

}


//take the head of ppm image and export to output
void headPPMImg(FILE *in, FILE *out)
{
    char str[3];
    fgets(str, 3, in);
    fprintf(out, "%s\n", str);
    fscanf(in, "%d %d", &cols, &rows);
    fprintf(out, "%d %d\n", cols, rows);
    fscanf(in, "%d", &maxColor);
    fprintf(out, "%d\n", maxColor);
}








int main(int argc, char *argv[]){

    FILE *input;
    FILE *output;

     if (argc == 3)
    {
        input = fopen(argv[1], "r");
        output = fopen(argv[2],"w");
    }
    else if (argc == 2)
    {
        input = fopen(argv[1], "r");
        output = stdout;
    }
    else if (argc == 1)
    {
        input = stdin;
        output = stdout;
    }
    if(!stdin || !stdout){
        printf("ERROR"); 
        exit(1);
    } 

    headPPMImg(input, output);   
    ppm_v_flip(input, output);

    fclose(input);
    fclose(output);

    return 0;
}
