#include <stdio.h>
#include <limits.h> 

void max_min(int vec[], int size, int *pmax, int *pmin){
    *pmax = INT_MIN;
    *pmin  = __INT_MAX__; 
    for(int i = 0; i < size; i++){
        if(vec[i] < *pmin) *pmin = vec[i];
        if(vec[i] > *pmax) *pmax = vec[i];
    }
}

int main(){

int vec[10] = {1,2,3,4,5,6,7,8,99,-1};
int max, min;

max_min(vec, 10, &max, &min);

printf("max = %d\nmin = %d", max, min);



    return 0;
}