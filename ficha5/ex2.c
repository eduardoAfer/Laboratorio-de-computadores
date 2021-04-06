#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main(int argc, char* argv[]){
    FILE *f;
    f = fopen(argv[1], "r");

    char acc[20];

    while(fscanf(f, "%s", acc) != EOF){
        printf("%s\n", acc);
         
    }
    return 0;

}
