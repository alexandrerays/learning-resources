#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

main(){
       int i=1, j=2, k=3, n=2;
       float x=3.3, y=4.4;
       printf("\n%d", (i<j+3));
       printf("\n%d", (2*i-7<=j-8));
       printf("\n%d", (-x+y>=2.0*y));
       printf("\n%d", (i==y));
       printf("\n%d", (i<j && 2>=k));
       printf("\n%d", (i<j || j==4 || k==5));
       printf("\n%d", (x<=5.0 && x!=1.0 || i>j));
       printf("\n%d", (i || j-3 && 0));
       printf("\n%d", (-i+1 || j+2));
       printf("\n%d", (i && j));
       getchar();       
       }
