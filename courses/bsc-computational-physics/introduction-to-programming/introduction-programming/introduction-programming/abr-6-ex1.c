//substitui a por b e b por a em uma palavra informada
#include <stdio.h>
#include <stdlib.h>

main()
{
       char s[50];
       int i=0;
       puts("digite uma palavra");
       gets(s);
       for(int i=0; s[i]!='\0'; i++)
               if (s[i]=='a') 
               s[i]='b';      
       puts("a string convertida:");
       printf("%s\n", s);     //%s = é uma string  
       //system("pause");
}
       
       

