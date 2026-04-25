#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define num 100000


void insertion (int n, int v[]) {
int i, j, x;
    for (j = 1; j < n; j++) {
    x = v[j];
    for (i = j-1; i >= 0 && v[i] > x; i--)
        v[i+1] = v[i];
               v[i+1] = x;
               }
}


main(){
       
       
       int vet[num];
       int i=0, j=0;
       
       //CÁLCULO DE TEMPO
       double inicio, fim, tempo_gasto, tempo_total=0;
       srand(time(NULL));

       for (j=0; j<10; j++){
           for(i=0; i<num; i++){
                            vet[i] = rand()%num;
                            }
       inicio = (double) clock()/CLOCKS_PER_SEC;
       
       insertion(num, vet);
       
       fim = (double) clock() / CLOCKS_PER_SEC;
       tempo_gasto = fim - inicio;
       printf("\nTempo gasto no conj %d %f\n", j, tempo_gasto);
       tempo_total = tempo_gasto;
       }
       
       
       
       
       
       
       getchar();
       }
