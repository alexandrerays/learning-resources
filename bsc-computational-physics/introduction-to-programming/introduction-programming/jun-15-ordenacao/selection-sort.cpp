#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


void selecao(int v[], int n){
     int i, j, min;
     int x=0;
     
     for(i=0; i<n-1; i++){
              min=i;
              for(j=i+1; j<n; j++){
                         if(v[j]<v[min])
                         min=j;
                         x=v[i];
                         v[i]=v[min];
                         v[min]=x;
                         
                         }
              
              }
     
     }


main(){
       
       int vet[5]={4,2,6,4,8};
       //scanf("%d", &vet[5]);
       //printf("%d",vet[]);
       
       
       
       
       
       
       getch();
       }
