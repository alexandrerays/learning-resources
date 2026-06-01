#include<stdio.h>
#include<conio.h>
//IMPRIME 'A' QUANDO UMA STRING TIVER UM ESPAÇO EM BRANCO

/*char sub(char *s){
     int i=0;
     for(i=0; s[i]!='\0'; i++){
               if(s[i]==' ')
               s[i]='A';               
               }  
               
              return(s[i]);              
               
                  
     }*/

main(){
       
       char string[30];
       
       printf("Entre com um nome: ");
       gets(string);
       
       //sub(string);
       
      for(int i=0; string[i]!='\0'; i++){
               if(string[i]==' ')
               string[i]='A';               
               }  
               
      for(int i=0; string[i]!='\0'; i++){
               printf("%c", sub(string));
               }
               
 
       getch();
       }
