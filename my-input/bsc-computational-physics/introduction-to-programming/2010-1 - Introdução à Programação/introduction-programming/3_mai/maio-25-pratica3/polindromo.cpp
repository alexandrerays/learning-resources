#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
//DETERMINA SE UMA STRING É UM POLÍNDROMO EX: KAIAK
//USAR PONTEIROS E FUNÇÕES


main(){
       char s[30];
       char r[30];
       int cont=0;
       
        for(int i=0;r[i]!='\0';i++) {
       r[i]='\0';
       //printf("[%c]\n", r[i]);
       }
       
       printf("Entre com uma string: ");
       gets(s);
       
      
       
       for(int i=0;s[i]!='\0';i++) //CONTA STRINGS
       cont++;
       
       for(int i=0; s[i]!='\0'; i++){
               s[i]=r[cont];
               
               cont--;
               
               printf("[%c]\n", r[cont]);
                        
       
       }
  
       
       
       
       //printf("%d", cont);
       
       getch();
      

       }
