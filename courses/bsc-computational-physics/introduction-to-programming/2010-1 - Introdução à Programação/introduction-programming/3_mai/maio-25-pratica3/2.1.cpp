#include<conio.h>
#include<stdio.h>
//PREENCHER UM VETOR COM 10 NUMEROS

main(){
       float v[10];
       float soma=0;
       float media=0;
       
       for(int i=0; i<=9; i++){
               v[i]=0;
               }
       
       
       for(int i=0; i<=9; i++){
               printf("Entre com um numero: ");
               scanf("%f", &v[i]);      
               soma=soma+v[i];
                printf("%d ", soma);
               }
               
               
                
               
               
      
               
       media=soma/10;
       
       printf("media: %d", media);      
 
                /* IMPRIME OS ELEMENTOS
                for(int i=0; i<=9; i++){
                printf("%f\n", v[i]);       
                }*/

       
       getch();
    
       }
