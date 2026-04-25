#include<stdio.h>
#include<conio.h>

int ler_notas(int *pv, int qtde){
              for(int i=0; i<qtde; i++){
                          printf("Entre com uma nota: ");
                          scanf("%d",&pv[i]);                              
                      }                                  
              }
              
int calcula_media(int *pv, int qtde){
                  float media=0;
                  int soma=0;
                  
                  for(int i=0; i<qtde; i++){
                          soma=soma+pv[i];
                          }                
                
                
                }       
              

main(){
              
       int *vet;
       int n=0;
       
       printf("Entre com a quantidade de notas: ");
       scanf("%d", &n);
       
       vet=(int*)malloc(n*sizeof(int));
       
       ler_notas(vet,n);
       
       //calcula_media(p,n);
       
       printf("%d", calcula_media(vet,n));
       
       
       
       getch()
       }
