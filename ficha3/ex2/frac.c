#include <stdio.h>
#include <stdlib.h>
#include <math.h>>

typedef struct Frac{
    int numerador;
    int denominador;
    int sinal; 

}FRAC;

int mdc(int num1, int num2) {

    int resto;

    do {
        resto = num1 % num2;

        num1 = num2;
        num2 = resto;

    } while (resto != 0);

    return num1;
}


FRAC soma(FRAC f1, FRAC f2){
    FRAC f3;
    int denominador = mdc(f1.denominador, f2.denominador);
    int multF1 = mdc(f1.denominador, f2.denominador) / f1.denominador;
    int multF2 = mdc(f1.denominador, f2.denominador) / f2.denominador;
    
    int numerador = f1.numerador * f1.sinal * multF1 + f2.numerador * f2.sinal * multF2;
    f3.numerador = abs(numerador);
    f3.denominador = denominador;
    if(numerador < 0) f3.sinal = -1;
    else f3.sinal = 1;

    return f3; 
}

FRAC sub(FRAC f1, FRAC f2){
    FRAC f3;
    int denominador = mdc(f1.denominador, f2.denominador);
    int multF1 = mdc(f1.denominador, f2.denominador) / f1.denominador;
    int multF2 = mdc(f1.denominador, f2.denominador) / f2.denominador;
    
    int numerador = f1.numerador * f1.sinal * multF1 + f2.numerador * f2.sinal * multF2 * (-1);
    f3.numerador = abs(numerador);
    f3.denominador = denominador;
    if(numerador < 0) f3.sinal = -1;
    else f3.sinal = 1;
    
    return f3; 
}




FRAC simp(FRAC f){

    while(mdc(f.denominador, f.numerador) != 1){
        int divide = mdc(f.denominador, f.numerador);
        f.denominador /= divide;
        f.numerador /= divide;
    }
    return f;
}


FRAC mult(FRAC f1, FRAC f2){
    FRAC f3;

    f3.denominador = f1.denominador * f2.denominador;
    f3.numerador = f1.numerador * f2.numerador;
    f3 = simp(f3);

    return f3;
}

FRAC div(FRAC, FRAC){
    FRAC f3;

    f3.denominador = f1.denominador * f2.Numerador;
    f3.numerador = f1.numerador * f2.denominador;
    f3 = simp(f3);

    return f3;    
}


     



int main(){




    return 0;
}