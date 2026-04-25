#include<stdio.h>
#include<stdlib.h>

//o programa verifica se um determinado elemento existe em um vetor, se existe, retornar a posicao
//usar recursao

/*int verifica(*pv, e){
    
    if(*pv==e)
              return(1);
    else
              return(0);
    
    
    }*/
    
    
    
    
main(){
       int x=0;
       int vet[10]={4,3,17,7,3,19};
       
       printf("entre com x\n");
       scanf("%d", &x);
       
       for(int i=0; i<10; i++);
       {
       if(vet[i]==x)
       printf("o elemento %d se encontra no vetor\n, posicao: %d", x, v[i]);
       else
       printf("o elemento %d nao se encontra no vetor\n", x);
       }
       
       //verifica(vet,x);
       
       //printf("o elemento %d existe no vetor", x);
       
       //printf("o elemento %d nao existe no vetor", x);
       
       
       system("pause");
       
       }    
