#include <stdio.h>
#include <stdlib.h>



struct {
    char t[200];
}tipo;

int main(){



    typedef struct tipo *mat[2][2];


    mat[0][0].t[0] = "edurdo d monida";


    printf("%s", mat[0][0].t);





    return 0;
}