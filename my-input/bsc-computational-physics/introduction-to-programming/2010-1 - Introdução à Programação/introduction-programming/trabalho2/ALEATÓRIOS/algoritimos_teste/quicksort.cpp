#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#define num 5


int Separa (int p, int r, int v[]) {
    int c, j, k, t;
    c = v[r]; j = p;
    for (k = p; k < r; k++)
        if (v[k] <= c) {
        t = v[j], v[j] = v[k], v[k] = t;
        j++;
        }
     v[r] = v[j], v[j] = c;
     return j;
}

void quicksort (int p, int r, int v[]) {
     int j;
     if (p < r) {
        j = Separa (p, r, v);
        quicksort (p, j - 1, v);
        quicksort (j + 1, r, v);
     }
}




main(){
       
       
       int vet[num]={2,4,8,7,1};
       int pivo=0;
       
       
       
       
       quicksort(pivo, num,vet);
       
       for(int z=0; z<num; z++)
       printf("[%d] %d\n", z, vet[z]);
       
       
       
       getch();
       }
