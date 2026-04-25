#include<stdio.h>

//funcoes
void ler_vetor(int v[], int n)
                   {
                   for(int i=0; i<n; i++)
                   scanf("%d", &v[i]);                   
                   }


int verifica (int v[], int x)
                  {
                  
                       
                  }

void inserir (int v[], int p, int n)
                  {
                  for(int i=0; i<n; i++)
                  v[p+1]=v[p];
                  v[p]=n;                       
                  }

void remover (int v[], int pos)
                  {
                  
                       
                  }

int somar(int v[], int)
                   {
                   
                   
                   }



int max(int v[])


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
                          
       
       system("pause");      
       
       
       
       } 
