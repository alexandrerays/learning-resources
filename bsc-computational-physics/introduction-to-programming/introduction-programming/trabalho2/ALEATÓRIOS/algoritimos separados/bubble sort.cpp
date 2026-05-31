#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define n 100000

//ALGORITIMO BUBBLE SORT
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
       int j=0, i=0;
     
       
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
       
       
       
       
       getchar();   
       getchar();
       }
