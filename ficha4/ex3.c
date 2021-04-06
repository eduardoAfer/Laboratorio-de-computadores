#include <stdio.h>
#include <stdlib.h>
//#include <conio.h>




int* readarray(int n){
    int i;
int v[n];
for (i=0; i<n; i++){
scanf("%d", v+i); }
return v; }


int* somaarrays(int *a, int *b, int n) {
    int *arr;
    arr = allocArray();

    for(int i = 0; i < n; i++) arr[i] = a[i] + b[i];
    return arr;
}
void printarray(int *v, int n){
    for(int i = 0; i < n; i++) printf("%d\n", v[i]);
}
/*
int* allocArray() {
    int arr[10];
    return arr;
}
*/

int main(){
    int n;
   int *va, *vb, *vr;
   scanf("%d\n", &n);
    va = readarray(n);
    vb = readarray(n);
    vr = somaarrays(va, vb, n);
    printarray(va, n); 
    printarray(vb, n); 
    printarray(vr, n);
    return 0;
}