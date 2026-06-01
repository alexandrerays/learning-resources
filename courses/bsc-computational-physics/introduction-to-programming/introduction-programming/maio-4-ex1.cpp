#include<stdio.h>
#include<stdlib.h>

main(){
       int *pv, i=0;
       int v[]={1,2,3,4,5};
       
       
       for(pv=&v[4]; i>=0; i--, pv--)
       printf("%d\n", *pv);
       
       system("pause");      
       
       
       }
