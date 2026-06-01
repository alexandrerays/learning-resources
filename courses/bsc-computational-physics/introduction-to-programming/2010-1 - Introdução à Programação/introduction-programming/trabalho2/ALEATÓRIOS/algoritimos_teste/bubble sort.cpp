#include<stdio.h>
#include<conio.h> //bubble sort
#include<time.h>
#define n 5

void bubble( int v[], int qtd )
{
  int i;
  int j;
  int aux;
  int k = qtd - 1 ;//porque ñ se pode comparar o ultimo elemento com o próximo

  for(i = 0; i < qtd; i++)
  {
     for(j = 0; j < k; j++)
     {
           
           /*Enquando v[j]>v[j+1], acontecerá a troca, senão
           voltara no primeiro for*/
        if(v[j] > v[j+1])
        {
            aux = v[j];
        v[j] = v[j+1];
        v[j+1]=aux;
        }
     }
     k--;/*cada vez que passar por aqui, um maior elemento toma 
     umas das posições finais*/
  }
}

main(){
    
             
       int vet[]={4,3,1,2,5};
       /*
       1.{3,4,1,2,5}
       2.{3,1,4,2,5}
       3.{3,1,4,2,5}
       4.{3,1,2,4,5}
       5.{3,1,2,4,5}
       
       1.{1,3,2,4,5}   
       1.{1,2,3,4,5}  
       1.{1,2,3,4,5}
       1.{1,2,3,4,5}
       
       
       
       */
       
       bubble(vet,n);
       
       for(int z=0; z<n; z++)
       printf("[%d] %d\n", z, vet[z]);
       
 
       
       getch();
       }
