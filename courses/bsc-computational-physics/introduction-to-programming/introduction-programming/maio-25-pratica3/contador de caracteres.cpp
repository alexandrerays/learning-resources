#include<stdio.h>
#include<conio.h>
//CONTA QUANTOS CARACTERES TEM EM UMA STRING

main(){
       char s[30];
       int cont=0;
       
       printf("Entre com uma string: ");
       gets(s);
       
       for(int i=0;s[i]!='\0';i++) //VARRE A STRING
       cont++;
       
       printf("%d", cont);
       
       getch();
      

       }
