#include<stdio.h>
//#include<conio.h>

main(){
       int vet[10]={7,5,8,2,0};
       int *pf;
       pf=&vet[2];
       printf("\n1: %d",*pf);     
       printf("\n2: %d",vet[0]);
       printf("\n3: %d",*(pf++));
       printf("\n4: %d",*pf);
       printf("\n5: %d",*(pf+1));
       printf("\n6: %d",(*pf)++);
       printf("\n7: %d",*pf);
       printf("\n8: %d",*(pf-2));
       printf("\n9: %d",*pf--);
       printf("\n10: %d",*pf);
       
       getchar();      
       
       
       }
