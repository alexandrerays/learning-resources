#include<stdio.h>
#include<stdlib.h>

//o programa imprime o maior valor de um vetor utilizando recursao


int max(int *pv, int size){ // ponteiro que aponta para o vetor v 
    int x;
    if(size==1) //tamanho do vetor
              return(pv[0]); //criterio de parada
    else{
         x=max(pv, size-1); //chamada recursiva
                   if(x>pv[size-1])
                       return (x);
                   else
                       return (pv[size-1]);        
         }        
    
    }



main(){
       int v[10]={2,5,25,2,55,3,2,19};
       printf("o maior elemento de v e: %d\n", max(v, 10));
       
       system("pause");
       }
