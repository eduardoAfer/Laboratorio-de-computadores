#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(int argc, char* argv[]){
    FILE *fp, *f2;
    fp = fopen(argv[1], "r");
    f2 = fopen(argv[2], "w"); 

    if(!fp || !f2){
        printf("Erro na abertura");
        exit(1);
    }

    char c = fgetc(fp);
    int acc = 0;
    while(c != EOF){
        if(c != ' ') acc++;
        c = fgetc(fp);
    }
    if(acc == 1) fprintf(f2, "O ficheiro tem 1 caractere");
    else fprintf(f2, "O ficheiro tem %d caractere", acc);

   

    fclose(fp);
    fclose(f2);

    return 0;
}


