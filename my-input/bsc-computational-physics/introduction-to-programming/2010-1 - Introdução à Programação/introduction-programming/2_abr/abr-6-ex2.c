#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

main(){
       char s[50];
       char c;
       int i;
       puts("digite uma string");
       gets(s);
       puts("caracter a ser removido");
       //gets(c);
        c=getch();
              
       for(i=0, s[i]!='c' &&s[i]!='\0', i++);
       
       //for(int i=0, s[i]!='\0', i++)
         if(s[i]=='\0')
         puts("caracter ñ encontrado");
         else
         for(i=0, s[i]!='0', i++)
               s[i]=s[i+1];
         puts(s);      
       //printf("%s\n", s);      
       system("pause");            
      
       
       
       }
       
       //o programa remove a string e de uma palavra digitada pelo usuário
