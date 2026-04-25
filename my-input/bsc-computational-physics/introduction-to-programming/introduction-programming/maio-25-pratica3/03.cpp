#include<stdio.h>
#include<conio.h>
//LIMPANDO UMA STRING OU IMPRIMINDO CARACTER POR CARACTER

main(){
       char s[10];  
        
       printf("entre com uma string: ");
       gets(s);
        
       for(int i=0;s[i]!='\0';i++){
       s[i]='\0';
       printf("[%c] ", s[i]);   
       }    

       getch();
       }
