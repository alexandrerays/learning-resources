# include<stdio.h>
# include<stdlib.h>
# include<time.h>
# define N 100000

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

main(){
       long int j,i;
       long int v[N];
       long int *pV=v;

       //p/ cálculo do tempo
       double inicio,fim, tempo_gasto, tempo_total=0;
       srand(time(NULL));

       for (j=0;j<10;j++){
           for(i=0;i<N;i++){
                            v[i] = rand()%N;
                            }
       inicio = (double) clock()/CLOCKS_PER_SEC;
       heapSort(pV,N);
       fim = (double) clock()/CLOCKS_PER_SEC;
       tempo_gasto = fim - inicio;
       printf("\nTempo gasto no conj %d %f\n",j,tempo_gasto);
       tempo_total = tempo_gasto;
       }
       getchar();
       getchar();

       }
