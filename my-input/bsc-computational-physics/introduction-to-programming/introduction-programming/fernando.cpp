#include<stdio.h>
#include<conio.h>
#define n 10

int verifica(int pv[]){
    int a[30];
    int b[30];
    int i=0, j=0, k=0;
    int cont_par=0, cont_impar=0;
    
    //varre o vetor e faz as atribuições
    for(i=0; i<n; i++){
            if(pv[i]%2!=0){  //impar                     
            a[j]=pv[i];
            j++;
            cont_impar++;   
                       
            }
         
            else if(pv[i]%2==0){   //par     
            b[k]=pv[i];
            k++;
            cont_par++;      
                        
            }//else          
                 
    }  //for    
       
    printf("vetor A(impar): ");        
    for(int j=0; j<cont_impar; j++)
         printf("%d ", a[j]);
          
    printf("\nvetor B(par): ");
    for(int k=0; k<cont_par; k++)
          printf("%d ", b[k]);
   
    }//funcao

main(){       
       int vet[10]={1,2,3,4,5,55,77,47,2,0};       
       verifica(vet);        
       getch();
       }
