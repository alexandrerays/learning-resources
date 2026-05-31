#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

/*void troca(){
     
     
     
     
     }*/


main(){
       
       int vet[5]={6,5,8,2,3};
       int aux=0;
       int i=0;
       
       //LÊ VETOR
       while(vet[i]<vet[i-1]){
                              
                              
                              
                              }
       
       for(i=0; i<5; i++){               
       
                    //TESTE
                    if(vet[i]==vet[i+1])
                    printf("nada 1 ");
                    else if(vet[i]<vet[i+1])
                    printf("nada 2 ");
                    else       
                    //TROCA
                    aux=vet[i];
                    vet[i]=vet[i+1];
                    vet[i+1]=aux;
                    }
       
       printf("%d ", vet[i+1]);
       
              
     
       getch();
       }
