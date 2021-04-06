#include <stdio.h>
#include <stdlib.h>



char c;

int main(int argc, char* argv[]){
    int begin = 0, m, n, max_color;
    

    FILE* p1 = fopen(argv[1], "r");
    FILE* p2 = fopen(argv[2],"w");

    c = fgetc(p1);
    while(c != '\n'){
        fputc(p2, c);
        c = fgets(p1);
    }
    fputc(p2, "\n");

    fscanf(p1, &m);
    fscanf(p2, &n);
    fscanf(p1, &max_color);

    int pixel[m*n][m];

    int final = n-1;

    c = fgets(p1);
    while(c == '#'){
        while( 1 == 1){
            c = fgets(p1);
            if(c == '\n'){
                c = fgets(p1);
                break;
            }
        }
    }
    //criação da matriz
    for(int i = 0; i < m*n; i++){
        for(int j; j < m; j++){
            if(c == '#'){
                while(c != '\n'){
                    c = c
                }
            }
            int inteiro;
            fscanf(p1, &inteiro);
            pixel[i][j] = inteiro;
            while(c != ' '){
                c = fgets(p1);
                break;
            }
        }
    }







    return 0;
}