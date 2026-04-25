#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define num 100000


void selection(int n, int v[]) {
int i, j, min, x;
     for (i = 0;  i < n-1; i++) {
         min = i;
             for (j = i+1; j < n; j++)
                  if (v[j] < v[min]) min = j;
                  x = v[i]; v[i] = v[min]; v[min] = x;
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
       
       selection(num, vet);
       
       fim = (double) clock() / CLOCKS_PER_SEC;
       tempo_gasto = fim - inicio;
       printf("\nTempo gasto no conj %d %f\n", j, tempo_gasto);
       tempo_total = tempo_gasto;
       }
       
      
   
       getchar();
       }
