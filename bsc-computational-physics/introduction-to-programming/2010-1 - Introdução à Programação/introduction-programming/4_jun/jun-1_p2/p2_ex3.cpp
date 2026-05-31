#include<stdio.h>
#include<conio.h>


int produto(int a, int b){
    int r=0;
    if(a==1)
    r=b;
    else if(b==1)
    r=a;
    else if(a==0||b==0)
    r=0;
    else
    r=a+(produto(a,b-1));
    
    return(r); 
        
    }



main(){
       
       int x=0, y=0;
       
       printf("Entre com a: ");scanf("%d",&x);
       printf("Entre com b: ");scanf("%d", &y);
       
       printf("O produto e: %d", produto(x,y));
       
       
       
       
       getch();       
       }
