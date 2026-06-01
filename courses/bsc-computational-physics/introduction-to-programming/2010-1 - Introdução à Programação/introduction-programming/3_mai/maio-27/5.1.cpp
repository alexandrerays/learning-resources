#include<stdio.h>
#include<conio.h>
//CONTA QUANTAS VOGAIS TEM NUMA STRING USANDO FUNÇÃO

int contador(char *s){ 
    int cont=0;
    for(int i=0; s[i]!='\0'; i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
            cont++;     
            }   
    
    return(cont);   
    }
    

main(){       
       char s[30];
       
       printf("Entre com a string: ");
       gets(s);      
       
       printf("%d ", contador(s));     
       
       getch();
       }
