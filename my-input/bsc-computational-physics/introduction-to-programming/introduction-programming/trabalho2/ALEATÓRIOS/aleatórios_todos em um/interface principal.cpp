/*SEGUNDO TRABALHO DE LINGUAGEM C
ALEXANDRE RAY DA SILVA - FÍSICA COMPUTACIONAL 2010*/

#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

//FUNÇÃO BUBBLESORT 
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

//FUNCAO SELECTIONSORT
void selection(int n, int v[]) {
int i, j, min, x;
     for (i = 0;  i < n-1; i++) {
         min = i;
             for (j = i+1; j < n; j++)
                  if (v[j] < v[min]) min = j;
                  x = v[i]; v[i] = v[min]; v[min] = x;
                  }
}

//FUNCAO INSERTIONSORT
void insertion (int n, int v[]) {
int i, j, x;
    for (j = 1; j < n; j++) {
    x = v[j];
    for (i = j-1; i >= 0 && v[i] > x; i--)
        v[i+1] = v[i];
               v[i+1] = x;
               }
}

//FUNÇÕES DO QUICKSORT
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

//FUNÇÕES DO HEAPSORT
void mantemHeapMax ( long int *A, long int i, long int compHeap){
     long int esq, dir, maior, menor, temp;
     esq= 2*i+1; //esquerda(i);
     dir= 2*i+2; //diereita(i);
     if (esq<compHeap && A[esq]>A[i])
        maior= esq;
     else
        maior= i;
     if(dir<compHeap && A[dir]>A[maior])
        maior=dir;
     if(maior != i){
              // trocar A[i] <==> A[maior]
              temp=A[i];
              A[i]=A[maior];
              A[maior]=temp;
              // Ajusta a posiçao de maior, se incorreta
              mantemHeapMax(A, maior, compHeap);
              }
}
void constroiHeapMax(long int *A, long int A_length){
     long int compHeap=A_length;
     for(long int i=(A_length)/2-1;i>=0;i--)
         mantemHeapMax(A,i,compHeap);
         }

void heapSort(long int *A, long int A_length){
     long int i, compHeap, temp;
     //constroi o heap máximo do arranjo todo
     compHeap=A_length;
     constroiHeapMax(A, compHeap);
     for(i=A_length-1;i>0;i--){
                               //troca A[0] <==> A[i]
                               temp=A[0];
                               A[0]=A[i];
                               A[i]=temp;
                               //diminui o heap, pois A[i] está posicionado
                               compHeap--;
                               mantemHeapMax(A,0,compHeap);
                               }
     }

//CALCULA TEMPO_BUBBLESORT
int calcula_bubble(int vetor[], int numero){
    
       int j=0, i=0;   
       double inicio, fim, tempo_gasto, tempo_total=0;
       srand(time(NULL));

       for (j=1; j<11; j++){
           for(i=0; i<numero; i++){
                    vetor[i] = rand()%numero;
                    }
                    inicio = (double) clock()/CLOCKS_PER_SEC;
       
                    bubble(vetor, numero);
       
       fim = (double) clock() / CLOCKS_PER_SEC;
       tempo_gasto = fim - inicio;
       printf("\nTempo gasto no conjunto %d com %d elementos: %f\n", j, i, tempo_gasto);
       tempo_total = tempo_gasto;
       }       
}                                                    

//CALCULA TEMPO_SELECTIONSORT
int calcula_selection(int vetor[], int numero){
    
       int j=0, i=0;   
       double inicio, fim, tempo_gasto, tempo_total=0;
       srand(time(NULL));

       for (j=1; j<11; j++){
           for(i=0; i<numero; i++){
                    vetor[i] = rand()%numero;
                    }
                    inicio = (double) clock()/CLOCKS_PER_SEC;
       
                    selection(numero, vetor);       
       fim = (double) clock() / CLOCKS_PER_SEC;
       tempo_gasto = fim - inicio;
       printf("\nTempo gasto no conjunto %d com %d elementos: %f\n", j, i, tempo_gasto);
       tempo_total = tempo_gasto;
       }       
} 

//CALCULA TEMPO_INSERTIONSORT
int calcula_insertion(int vetor[], int numero){
    
       int j=0, i=0;   
       double inicio, fim, tempo_gasto, tempo_total=0;
       srand(time(NULL));

       for (j=1; j<11; j++){
           for(i=0; i<numero; i++){
                    vetor[i] = rand()%numero;
                    }
                    inicio = (double) clock()/CLOCKS_PER_SEC;
       
                    insertion(numero, vetor);       
       fim = (double) clock() / CLOCKS_PER_SEC;
       tempo_gasto = fim - inicio;
       printf("\nTempo gasto no conjunto %d com %d elementos: %f\n", j, i, tempo_gasto);
       tempo_total = tempo_gasto;
       }       
} 

//CALCULA TEMPO_QUICKSORT
int calcula_quicksort(int vetor[], int numero){
       int pivo=0;
       int j=0, i=0;   
       double inicio, fim, tempo_gasto, tempo_total=0;
       srand(time(NULL));

       for (j=1; j<11; j++){
           for(i=0; i<numero; i++){
                    vetor[i] = rand()%numero;
                    }
                    inicio = (double) clock()/CLOCKS_PER_SEC;
       
                    quicksort(pivo, numero, vetor);       
       fim = (double) clock() / CLOCKS_PER_SEC;
       tempo_gasto = fim - inicio;
       printf("\nTempo gasto no conjunto %d com %d elementos: %f\n", j, i, tempo_gasto);
       tempo_total = tempo_gasto;
       }
       
} 

//CALCULA TEMPO_HEAPSORT
int calcula_heapsort(long int vetor[], long int numero){
       int pivo=0;
       long int j=0, i=0;   
       double inicio, fim, tempo_gasto, tempo_total=0;
       srand(time(NULL));

       for (j=1; j<11; j++){
           for(i=0; i<numero; i++){
                    vetor[i] = rand()%numero;
                    }
                    inicio = (double) clock()/CLOCKS_PER_SEC;
       
                    heapSort(vetor,numero);       
       fim = (double) clock() / CLOCKS_PER_SEC;
       tempo_gasto = fim - inicio;
       printf("\nTempo gasto no conjunto %d com %d elementos: %f\n", j, i, tempo_gasto);
       tempo_total = tempo_gasto;
       }
       
} 
       
void verifica_bubble(int qtd){
     switch(qtd){                                                      
           case 1:{//100                                                      
               int n=100;
               int v[n];
               calcula_bubble(v,n);                                          
           }
           break;
                                                           
           case 2:{//1000
               int n=1000;
               int v[n];
               calcula_bubble(v,n);                                               
           }
           break;
                                                           
           case 3:{//10000
               int n=10000;
               int v[n];
               calcula_bubble(v,n);                                                         
           }
           break;
                                                           
                                                           
           case 4:{//50000                                                           
               int n=50000;
               int v[n];
               calcula_bubble(v,n);
           }                                                           
           break;                                                           
                                                           
           case 5:{//100000                                                           
               int n=100000;
               int v[n];
               calcula_bubble(v,n);
           }                                                                
           break;
                                                  
     }//fecha switch
     
}//fecha função verifica_bubble

void verifica_selection(int qtd){
     switch(qtd){                                                      
            case 1:{//100
                int n=100;
                int v[n];
                calcula_selection(v,n);                                                     
            }
            break;
                                                           
            case 2:{//1000                                                      
                int n=1000;
                int v[n];
                calcula_selection(v,n);
            }
            break;
                                                           
            case 3:{//10000                                                      
                int n=10000;
                int v[n];
                calcula_selection(v,n);
            }
            break;
                                                           
                                                           
            case 4:{//50000                                                      
                int n=50000;
                int v[n];
                calcula_selection(v,n);
            }
            break;
                                                           
                                                           
            case 5:{//100000                                                      
                int n=100000;
                int v[n];
                calcula_selection(v,n);                                                                                                                
            }    
            break;
                                                  
      }//fecha switch
     
}//fecha função verifica_selection

void verifica_insertion(int qtd){
     switch(qtd){
                                                      
             case 1:{//100                                                      
                 int n=100;
                 int v[n];
                 calcula_insertion(v,n);
             }
             break;
                                                           
             case 2:{//1000                                                      
                 int n=1000;
                 int v[n];
                 calcula_insertion(v,n);
             }  
             break;
                                                           
             case 3:{//10000                                                      
                 int n=10000;
                 int v[n];
                 calcula_insertion(v,n);
             }
             break;
                                                           
                                                           
             case 4:{//50000                                                      
                 int n=50000;
                 int v[n];
                 calcula_insertion(v,n);
             }
             break;
                                                           
                                                           
             case 5:{//100000                                                      
                 int n=100000;
                 int v[n];
                 calcula_insertion(v,n);    
             }     
             break;
                                                  
      }//fecha switch
      
}//fecha função verifica_insertion

void verifica_quicksort(int qtd){
     switch(qtd){                                     
           case 1:{//100
               int n=100;
               int v[n];
               calcula_quicksort(v,n);
           }
           break;
                                                           
           case 2:{//1000
               int n=1000;
               int v[n];
               calcula_quicksort(v,n);
           }                                            
           break;
                                                           
           case 3:{//10000
               int n=10000;
               int v[n];
               calcula_quicksort(v,n);
           }                                             
           break;                                                           
                                                           
           case 4:{//50000
               int n=50000;
               int v[n];
               calcula_quicksort(v,n);
           }                                               
           break;                                                           
                                                           
           case 5:{//100000
                int n=100000;
                int v[n];
                calcula_quicksort(v,n);
           }                                                    
           break;
      }//fecha switch
     
}//fecha função verifica_quicksort

void verifica_heapsort(int qtd){
     switch(qtd){
             case 1:{//100
                int n=100;
                long int v[n];
                long int *pV=v;
                calcula_heapsort(pV,n);
             }
             break;
                                                           
             case 2:{//1000
                 int n=1000;
                 long int v[n];
                 long int *pV=v;
                 calcula_heapsort(pV,n);
             }                                         
             break;
                                                           
             case 3:{//10000
                 int n=10000;
                 long int v[n];
                 long int *pV=v;
                 calcula_heapsort(pV,n);
             }                                       
             break;
                                                           
                                                           
             case 4:{//50000
                 int n=50000;
                 long int v[n];
                 long int *pV=v;
                 calcula_heapsort(pV,n);                                                           
             }                                      
             break;
                                                   
             case 5:{//100000
                 int n=100000;
                 long int v[n];
                 long int *pV=v;
                 calcula_heapsort(pV,n);                                         
             }                                              
             break;
                                                  
       }//fecha switch
}//fecha função verifica_heapsort

void imprime_qtde_elementos(){
     printf("Escolha a quantidade de elementos do vetor\n\n");
       printf("1. 100\n");
       printf("2. 1.000\n");
       printf("3. 10.000\n");
       printf("4. 50.000\n");
       printf("5. 100.000\n");  
     }
     
void imprime_opcoes(){       
       printf("Escolha o algoritimo de ordenacao:\n\n");       
       printf("1. Bubble Sort\n");
       printf("2. Selection\n");
       printf("3. Insertion\n");
       printf("4. Quick Sort\n");
       printf("5. Heap Sort\n");       
       }

main(){  
       //VARIAVEIS GLOBAIS     
       int opcao=0;        
       int qtde_elementos=0;
           
       imprime_qtde_elementos();
       scanf("%d", &qtde_elementos);
       
       //VALIDAÇÃO DA QUANTIDADE DE ELEMENTOS
       while(qtde_elementos!=1 && qtde_elementos!=2 && qtde_elementos!=3 && qtde_elementos!=4 && qtde_elementos!=5){
            printf("Opcao inexistente! Tente novamente\n\n");           
            imprime_qtde_elementos();       
            scanf("%d", &qtde_elementos);            
            }              
       printf("\n\n");       
       
       imprime_opcoes();       
       scanf("%d", &opcao);
       
       //VALIDAÇÃO DAS OPÇÕES
       while(opcao!=1 && opcao!=2 && opcao!=3 && opcao!=4 && opcao!=5){
            printf("Opcao inexistente! Tente novamente\n\n");           
            imprime_opcoes();       
            scanf("%d", &opcao);            
            }
//A função seguir verifica o tipo de ordenação
switch(opcao){
              case 1://bubble sort
              verifica_bubble(qtde_elementos); break;

              case 2://selection sort
              verifica_selection(qtde_elementos); break;
                               
              case 3://insertion sort
              verifica_insertion(qtde_elementos); break;
            
              case 4://quick sort                      
              verifica_quicksort(qtde_elementos); break;                          
                          
              case 5://heap sort
              verifica_heapsort(qtde_elementos); break;     
              }
                  
       getch();
       
}//fecha main
