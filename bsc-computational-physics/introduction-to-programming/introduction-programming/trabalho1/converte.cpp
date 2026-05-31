#include <stdio.h>
#include <stdlib.h>

char converte(int i){
     char x='\0';
     //if (i==1)
     //x='a';
     //return(x);
     
     switch(i){
     case 3: x='a' ;
     //break;
     case 2: x='b';
     //break;
     
     return(x);
     }
     
main(){
       int y=3;       
       printf("%c\n", converte(y));
       printf("%c\n", converte(y-1));
       
       system("pause");
       }     
