#include<stdio.h>
#include<stdio.h>
#include<conio.h>
//o programa verifica o valor maximo e minimo de um vetor
int verifica(int v[], int *max, int *min){
       for(int i=0; i<=6; i++){
               if(v[i]>v[i-1])
               *max=v[i];
               }
       for(int i=0; i<=6; i++){
               if(v[i]<v[i-1])
               *min=v[i];
               }
    }

main(){
       int vetor[10]={10,40,50,5,15,45,90};
       int maximo=0;
       int minimo=0;

       verifica(vetor, &maximo, &minimo);

       printf("%d %d", maximo, minimo);

       getch();
       }
