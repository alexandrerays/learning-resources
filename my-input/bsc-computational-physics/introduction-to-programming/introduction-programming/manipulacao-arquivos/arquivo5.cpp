#include<stdio.h>
#include<conio.h>//getche()

main(){
       int n;
       FILE *p1;
       FILE *p2;
       FILE *p3;
       
       printf("Quantos arquivos do tipo txt quer criar: ");
       scanf("%d",&n);
       
       //ABRE O ARQUIVO SOMENTE SE ELE EXISTIR
       p1=fopen("arquivo1.txt","r+b");
       
       //CRIA O ARQUIVO OU ABRE SE ELE JA EXISTIR E DESTRÓI O CONTEÚDO
       for(int i=1; i<n; i++)
       p2=fopen("arquivo2.txt","w+b");
       
       //CRIA O ARQUIVO OU ABRE SE ELE JA EXISTIR E NÃO DESTRÓI O CONTEÚDO
       p3=fopen("arquivo3.txt","a+b");
       
       
       
       getche();
       }
