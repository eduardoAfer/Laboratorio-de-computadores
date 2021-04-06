#include <stdio.h>
#include <math.h>

struct Ponto{
	float x;
	float y;
}*PrtPonto;

typedef struct Ponto PONTO;

float distanciaEuclideana(PONTO p1, PONTO p2){ return sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2)); }

float distancia_total(PONTO percurso[], int size){
    float total = 0;
    for(int i = 0; i < size -1; i++){
       total += distanciaEuclideana(percurso[i], percurso[i+1]);
    }
    return total;
}

PONTO soma(PONTO p1, PONTO p2){
    PONTO pAux = p1;
    pAux.x = p1.x + p2.x;
    pAux.y = p1.y + p2.y;
    return pAux;
}

int main(){
    
	PONTO p1, p2, p3;
	PONTO caminho[] = {{0,0},{0,1}, {1,1},{4,5}};
	int size = 4;
	float dist;

	scanf("%f %f", &p1.x, &p1.y); // ler coordenada x e y de um ponto para p1
	scanf("%f %f", &p2.x, &p2.y); // ler coordenada x e y de um ponto para p2
	dist = distanciaEuclideana(p1,p2);
	p3 = soma(p1,p2);
	printf ("%f\n", dist); // imprimir distância euclideana entre os pontos p1 e p2
	printf ("%f %f\n", p3.x, p3.y); // imprimir vector soma dos vectores representados pelos pontos p1 e p2
	dist = distancia_total(caminho, size);
	printf ("%f\n", dist); // imprimir distância euclideana total dos segmentos do percurso
	return 0;
}