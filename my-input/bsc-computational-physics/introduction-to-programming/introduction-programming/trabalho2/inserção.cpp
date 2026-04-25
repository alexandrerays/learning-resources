#include<stdio.h>
#include<conio.h>

int main()

{

   int i, j,x;

   int vetor[5];

 

   printf("Vetor desordenado...\n");

 

   for(i=0;i<5;i++)
{

      printf("num: ");

      scanf("%i",&vetor[i]);

   }

 

   for (j=1;j<5;j++)

   {

       x = vetor[j];

      i = j - 1;

 

      while((i>=0) && (vetor[i]>x))

      {

             vetor[i+1] = vetor[i];

             i = i - 1;

      }

        vetor[i+1] = x;

   }

 

   printf("\nVetor ordenado...\n");

   for(i=0;i<5;i++)

      printf("Vetor[%2d]: %3d\n",i+1,vetor[i]);

 

getch();

}
