#include<stdio.h>
#include<stdlib.h>

int soma(int x, int y)
{
    //printf("a soma e: %d", (x+y));
    return(x+y);
    }
    
main(){
       int n1, n2;
       printf("entre com n1\n");
       scanf("%d", &n1);
       printf("entre com n2\n");
       scanf("%d", &n2);
       printf("%d\n", soma(n1,n2));
       
       system("pause");
       }
