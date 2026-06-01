#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#define n 10000
//IMPRIME DE FORMA ORDENADA UM VETOR DE n ELEMENTOS
//ORDENA UM VETOR JA ORDENADO DE 100, 1.000, 10.000 ELEMENTOS

void bubble( int v[], int qtd )
{
  int i;
  int j;
  int aux;
  int k = qtd - 1 ;

  for(i = 0; i < qtd; i++)
  {
     for(j = 0; j < k; j++)
     {
        if(v[j] > v[j+1])
        {
            aux = v[j];
        v[j] = v[j+1];
        v[j+1]=aux;
        }
     }
     k--;
  }
}

main(){   
       int vet[n];       
       int i=0, j=0;
       int t=0;
       
       
       //insere valores no vetor
       for(t=0; t<n; t++){
       vet[t]=t;
       }
       
      
       
       //CÁLCULO DE TEMPO
       double inicio, fim, tempo_gasto, tempo_total=0;
       srand(time(NULL));

       for (j=1; j<11; j++){
           for(i=0; i<n; i++){
                            vet[i] = rand()%n;
                            }
       inicio = (double) clock()/CLOCKS_PER_SEC;
       
       bubble(vet, n);
       
       
       fim = (double) clock() / CLOCKS_PER_SEC;
       tempo_gasto = fim - inicio;
       printf("\nTempo gasto no conjunto [%d] [%d]: %f\n", j, i, tempo_gasto);
       tempo_total = tempo_gasto;
       }
       
           
       
       getch();
       }
