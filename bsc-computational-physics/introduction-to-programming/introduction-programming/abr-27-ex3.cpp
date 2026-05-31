#include<stdio.h>
#include<stdlib.h>

//funcoes
void ler_vetor(int v[], int n)
                   {
                   for(int i=0; i<n; i++)
                   scanf("%d", &v[i]);    
                                  
                   }


void inserir (int v[], int p, int n)
                  {
                  for(int i=0; i<n; i++)
                  v[p+1]=v[p];
                  v[p]=n;   
                                     
                  }


//funcao principal
main(){
       
       int a[20];
       int posicao, elemento, num;
       
       //entrada de dados
       puts("entre com o numero de elementos");
       scanf("%d", &num);
       
       puts("entre com a posicao para substituir");
       scanf("%d", &posicao);
       
       puts("entre com o elemento");
       scanf("%d", &elemento);
       
       
       
       ler_vetor(a, num);
       
       inserir(a, posicao, num);
       printf("%d", a);
        
                          
       
       system("pause");      
       
       
       
       } 
