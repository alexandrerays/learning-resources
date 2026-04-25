#include<stdio.h>
#include<stdlib.h>
#include <math.h>
float A, B, C;
int Flag;
main(){
       puts("escreva A");
       scanf("%f", &A);
       B=10-pow(A,2);
       C=2*B+4*A/3;
       Flag=(C>=(B-1+C*2));
       printf("Resultados = %d\n, %f\n, %f\n, %f\n", Flag, A, B, C);
       system("pause");
       }
