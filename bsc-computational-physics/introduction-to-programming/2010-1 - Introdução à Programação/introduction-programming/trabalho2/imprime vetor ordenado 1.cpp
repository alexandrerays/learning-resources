#include<stdio.h>
#include<conio.h>
#define n 20
//IMPRIME DE FORMA ORDENADA UM VETOR DE n ELEMENTOS
main(){   
       int vet[n];
       int x=1;
       
       //insere valores no vetor
       for(int i=0; i<n; i++){
       vet[i]=x;
       x++;
       }
       
       //imprime vetor
       for(int i=0; i<n; i++)
       printf("%d\n", vet[i]);      
       
       getch();
       }
