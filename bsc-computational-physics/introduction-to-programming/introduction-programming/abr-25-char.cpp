#include<stdio.h>
#include<stdlib.h>

main(){
       char ch[10];       
       printf("entre com um char\n");
       scanf("%c", ch);
       
       for(int i=0;ch[i]!='\0';i++)
             
       printf("o segundo caracter e:\n %c", ch[1]);
       
       system("pause");
       }
