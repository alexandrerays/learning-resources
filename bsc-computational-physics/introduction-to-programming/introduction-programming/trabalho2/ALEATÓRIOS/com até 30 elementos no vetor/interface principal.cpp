#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>
/*SEGUNDO TRABALHO DE LINGUAGEM C
ALEXANDRE RAY DA SILVA - FÍSICA COMPUTACIONAL 2010*/

//FUNÇÃO BUBBLE SORT
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

//FUNCAO SELECTION SORT
void selection(int n, int v[]) {
int i, j, min, x;
     for (i = 0;  i < n-1; i++) {
         min = i;
             for (j = i+1; j < n; j++)
                  if (v[j] < v[min]) min = j;
                  x = v[i]; v[i] = v[min]; v[min] = x;
                  }
}

//FUNCAO INSERTION
void insertion (int n, int v[]) {
int i, j, x;
    for (j = 1; j < n; j++) {
    x = v[j];
    for (i = j-1; i >= 0 && v[i] > x; i--)
        v[i+1] = v[i];
               v[i+1] = x;
               }
}






int gerar_vetor(int *pv, int qtde){
    int i=0;    
    for(i=0; i<qtde; i++)
    pv[i]=rand()%30;    
    
    }
    
int imprimir_vetor(int *pv, int qtde){
    int i=0;
    for(i=0; i<qtde; i++)
    printf("%d ", pv[i]);
    }


main(){
       
       int opcao=0; 
       int vet[30];
       int qtde_elementos=0;
       
       printf("Entre com a quantidade de elementos do vetor: ");
       scanf("%d", &qtde_elementos);
       
       gerar_vetor(vet, qtde_elementos);
       imprimir_vetor(vet, qtde_elementos);
       
       printf("\n\n");
       
       
       printf("Escolha o algoritimo de ordenacao:\n\n");
       
       printf("1. Bubble Sort\n");
       printf("2. Selection\n");
       printf("3. Insertion\n");
       printf("4. Quick Sort\n");
       printf("5. Heap Sort\n");
       
       scanf("%d", &opcao);
       
       
       while(opcao!=1 && opcao!=2 && opcao!=3 && opcao!=4 && opcao!=5){
            printf("Opcao inexistente!Tente novamente\n\n");
            
            
            printf("Escolha o algoritimo de ordenacao:\n\n");
       
            printf("1. Bubble Sort\n");
            printf("2. Selection\n");
            printf("3. Insertion\n");
            printf("4. Quick Sort\n");
            printf("5. Heap Sort\n");
       
            scanf("%d", &opcao);
            
            }
            
            switch(opcao){
                          case 1:{//bubble sort
                               printf("\n");
                               
                                 bubble(vet, qtde_elementos);  
                                 
                                 printf("A sequencia ordenada e:\n");
                                 for(int z=0; z<qtde_elementos; z++)
                                 printf("%d ", vet[z]);

                               }
                               break;
                          case 2: //selection sort
                               printf("\n");
                               
                               selection(qtde_elementos,vet);
                               
                               printf("A sequencia ordenada e:\n");
                               for(int z=0; z<qtde_elementos; z++)
                               printf("%d ", vet[z]);
                               
                               
                               break;
                          case 3: //insertion sort
                               printf("\n");
                               
                               insertion(qtde_elementos,vet);
                               
                               printf("A sequencia ordenada e:\n");
                               for(int z=0; z<qtde_elementos; z++)
                               printf("%d ", vet[z]);
                               
                               
                              
                               break;
                          case 4: //quick sort                              
                               printf("\n");
                               
                               
                               
                               break;
                          case 5: //heap sort
                               printf("\n");
                               
                               
                               
                               break;                    
                 
                     }
    
       getch();
       }
