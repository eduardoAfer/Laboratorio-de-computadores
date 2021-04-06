#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
void ccaract(*arg){
    printf("%d", strnlen(arg));
}
*/
int main(int argc, char* argv[]){
    
    int total = 0;
    for(int i = 1; i <= argc ; i++){

    total += atoi(argv[i]);
      if(i == argc -1) printf("total = %d\n", total); 
    }


    return 0;

 }

  /*
   *  argc: número de argumentos da linha de comandos (incluindo o nome do
executável)
   *  argv[]: vector com os argumentos (cadeias de caracteres) passados na
linha de comandos:
* argv[0] - corresponde ao nome do executável
* argv[1] - corresponde ao primeiro argumento
* ...
* argv[argc-1] - corresponde ao último argumento * argv[argc] - tem valor NULL
*/
// completar programa...