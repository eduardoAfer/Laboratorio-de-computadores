#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX 1000

typedef struct {
    int red;
    int green;
    int blue;
} Pixel;

typedef struct {
    int magic_number;
    int lines;
    int columns;
    int max_value;
    Pixel** data;
} PPM_Image;



FILE* openFile(char* s, char *operation){  
    FILE* res;
    res=fopen(s, operation);
    if (res == NULL) exit(2);
    else return res;
}

void printStruct(PPM_Image image, FILE *output){
    fprintf(output, "P%d\n", image.magic_number);  
    fprintf(output, "%d ", image.columns);
    fprintf(output, "%d\n", image.lines); 
    fprintf(output, "%d\n", image.max_value); 
    for(int i=0; i<image.lines; i++){
        for(int j=0; j<image.columns; j++){
           fprintf(output, "%d %d %d\n", image.data[i][j].red, image.data[i][j].green, image.data[i][j].blue);
        }
    }
    fclose(output);
}

int charToInt(char *num){
    int numInt;
    sscanf(num, "%d", &numInt);
    return numInt;
}

int nextNumber(FILE *f){
    char number[MAX]={'\0'}, comments[MAX], ch;
    ch=fgetc(f); 
    while(!(ch >= '0' && ch<='9')){
        if(ch=='#') fgets(comments, MAX, f);
        ch=fgetc(f);
    }
    for(int i=0; ch >= '0' && ch <= '9'; i++){
        if(ch >= '0' && ch<='9') number[i]=ch;
        ch=fgetc(f);
    }
    return charToInt(number);
}

PPM_Image createStruct(FILE *img){
    PPM_Image imgStruct;
    imgStruct.magic_number=nextNumber(img);
    imgStruct.columns=nextNumber(img); 
    imgStruct.lines=nextNumber(img);
    imgStruct.max_value=nextNumber(img);
    imgStruct.data = (Pixel **)malloc(imgStruct.lines * sizeof(Pixel*));
    for (int i = 0; i < imgStruct.lines; ++i) {
        imgStruct.data[i] = (Pixel *)malloc(imgStruct.columns * sizeof(Pixel));
    }
    for(int i=0; i<imgStruct.lines; i++){
        for(int j=0; j<imgStruct.columns; j++){
            imgStruct.data[i][j].red=nextNumber(img);
            imgStruct.data[i][j].green=nextNumber(img);
            imgStruct.data[i][j].blue=nextNumber(img);
        }
    }
    fclose(img);
    return imgStruct;
}


void ppm_overlay(float alpha,PPM_Image overlay, PPM_Image image, FILE *output, int y, int x){
    PPM_Image imgRes=image;
    imgRes.data = (Pixel **)malloc(imgRes.lines * sizeof(Pixel*));
    for(int i = 0; i < imgRes.lines; ++i) {
        imgRes.data[i] = (Pixel *)malloc(imgRes.columns * sizeof(Pixel));
    }
    imgRes=image;
    for(int iRes=x, iOvr=0; iRes<imgRes.lines && iOvr<overlay.lines; iRes++, iOvr++){
        for(int jRes=y, jOvr=0; jRes<imgRes.columns && jOvr<overlay.columns; jRes++, jOvr++){
            imgRes.data[iRes][jRes].red = alpha * overlay.data[iOvr][jOvr].red + ((1 - alpha)*imgRes.data[iRes][jRes].red);
            imgRes.data[iRes][jRes].green = alpha * overlay.data[iOvr][jOvr].green + ((1 - alpha)*imgRes.data[iRes][jRes].green);
            imgRes.data[iRes][jRes].blue = alpha * overlay.data[iOvr][jOvr].blue + ((1 - alpha)*imgRes.data[iRes][jRes].blue);
        }
    }
    printStruct(imgRes, output);
}

void ppm_overlayMain(int argc, char *argv[]){
    FILE *fileInput1=openFile(argv[4], "r"), *fileInput2, *fileOutput;
    float alpha = atof(argv[1]);

    switch(argc){
        case 4:
            fileInput2=stdin;
            fileOutput=stdout;
            ppm_overlay(alpha, createStruct(fileInput1), createStruct(fileInput2), fileOutput, charToInt(argv[1]),  charToInt(argv[2]));
            break;
        case 5:
            fileInput2=openFile(argv[5], "r");
            fileOutput=stdout;
            ppm_overlay(alpha,createStruct(fileInput1), createStruct(fileInput2), fileOutput, charToInt(argv[1]),  charToInt(argv[2]));
            break;
        default:
            fileInput2=openFile(argv[5], "r");
            fileOutput=openFile(argv[6], "w");
            ppm_overlay(alpha,createStruct(fileInput1), createStruct(fileInput2), fileOutput, charToInt(argv[1]),  charToInt(argv[2]));
            break;
    }
}


int main(int argc, char* argv[]){
   
            ppm_overlayMain(argc, argv);
        
        
    
    return 0;
}
