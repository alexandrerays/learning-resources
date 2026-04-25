#include<stdio.h>
#include<stdlib.h>

int rest(int m,int n){
    if(n==0)
      return m;
    else
    return (rest(n,m%n));
    }

main(){
    int m,n,x;
    puts("digite o valor 1");
    scanf("%d",&m);
    puts("digite o valor 2");
    scanf("%d",&n);
    x=rest(m,n);
    printf("%d \n",x);
    system("pause");
       }
