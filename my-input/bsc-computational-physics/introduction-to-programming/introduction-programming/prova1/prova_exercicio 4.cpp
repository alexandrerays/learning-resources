#include<stdio.h>
#include<stdlib.h>
#include<math.h>

main(){
       float pi=0;
       int n=0;
       for(n=0; n<=1000; n++)
       pi=pi + (4*pow(-1,n)/(2*n+1));           
       printf("%f\n", pi);
       system("pause");       
       }
       
