#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

/*void verifica(char *s){
     
     
     
     }*/

main(){
       
       char *string;
       int cont=0;              
      
       
       printf("Entre com uma string: ");
       scanf("%s",&string);
       
       //CONTA QUANTOS CARACTERES HÁ NA STRING
       for(int i=0; string[i]!='\0'; i++)
       cont++;
       
       printf("\n%d",cont);
       
       
       
       
       
       
       getch();
       }
