#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#define num 50000


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
       
       
       int vet[num];
       int pivo=0;
       int i=0, j=0;
       
       
        //CÁLCULO DE TEMPO
       double inicio, fim, tempo_gasto, tempo_total=0;
       srand(time(NULL));

       for (j=0; j<10; j++){
           for(i=0; i<num; i++){
                            vet[i] = rand()%num;
                            }
       inicio = (double) clock()/CLOCKS_PER_SEC;
       
       quicksort(pivo, num,vet);
       
       fim = (double) clock() / CLOCKS_PER_SEC;
       tempo_gasto = fim - inicio;
       printf("\nTempo gasto no conj %d %f\n", j, tempo_gasto);
       tempo_total = tempo_gasto;
       }
       
       
       
       
       
       
       
       
       getch();
       }
