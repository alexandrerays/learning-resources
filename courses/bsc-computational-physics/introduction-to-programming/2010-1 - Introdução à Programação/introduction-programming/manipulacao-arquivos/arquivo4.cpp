#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

main(){
       FILE *fp;
       char str[100];
       
       
       if((fp=fopen("ray.txt","a"))==NULL){
       //se der erro o ponteiro retorna um valor nulo
                  
                  printf("erro ao tentar abrir o arquivo") ;             
                  exit(1);                         
                                           
       }
       else{
                    if(strlen(str)>1){
                    printf("Entre com uma string: ");       
                    gets(str);
                    fputs(str, fp); /*coloca str dentro do arquivo
                    apontado pelo ponteiro fp*/
                    putc('\n',fp); //pula uma linha dentro do arquivo
       
                    printf("\narquivo implementado com sucesso!");
       
                    }
                    fclose(fp);
       
       }
       
       
       
       
              
       
       
       getch();
       }
