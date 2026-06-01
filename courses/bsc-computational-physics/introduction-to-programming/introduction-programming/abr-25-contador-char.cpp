#include<stdio.h>
#include<stdlib.h>

main(){
       int i, cont=0;
       char str[50];
       
       printf("entre com uma string\n");
       //scanf("%c", &str);  NÃO FUNCIONA
       gets(str);
       
       for(i=0; str[i]!='\0'; i=i+1) // vai ler todos os caracteres da string
       {
                if(str[i]=='a')  //se o caracter for = a soma um no contador
                //{
                cont=cont+1;      //contador
                //str[i]=='s';
                //}
                }
                
       printf("o numero de caracteres A e: %d\n", cont);
       
       system("pause");     
       
       
       }
