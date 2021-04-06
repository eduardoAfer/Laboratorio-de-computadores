#include <stdio.h>


void decompor(int total_seg, int *horas, int *mins, int *segs){
    *horas     = total_seg / 3600;
    total_seg %= 3600;
    *mins       = total_seg/60;
    total_seg %= 3600;
    *segs      = total_seg; 
}




int main(){

    int total_seg = 86456, h, m, s;

    decompor(total_seg, &h, &m, &s);

    printf("total de segundos %d\n%d:%d:%d\n", total_seg, h, m, s);

    return 0;

}