#include <stdio.h>
#include <stdlib.h>


void mostra_lugar(int poltronas[][5])
{    
     int i, j;
     
     for(i=0; i<4; i++)
     {
              for(j=0; j<5; j++)
              {
                       printf("%6d", poltronas[i][j]);
              }
              printf("\n");
     }
}


void lugares(int poltronas[][5])
{
     int i, j;
     
          for(i=0; i<4; i++)
     {
                 for(j=0; j<5; j++)
                 {
                          poltronas[i][j]=0;
                 }
     }
}

void compra_lugar(int poltronas[][5], int opcao)
{
     int i, j, assento, fileira;
     
     if(opcao==1)
     {
                 printf("CLASSO EXECUTIVA:");
                 while(fileira<1 || fileira>3)
                 {
                     printf("\n\nQual fileira deseja comprar (1, 2, 3, 4)?\n");
                     scanf("%d", &fileira);
                 
                     if(fileira<1 || fileira>3)
                        printf("\nLugar inexistente!\n");
                 }
                 
                 while(assento<1 || assento>2)
                 {
                     printf("\nQual acento deseja comprar (1, 2)?\n");      
                     scanf("%d", &assento);
                 
                     if(assento<1 || assento>2)
                       printf("\nAssento invalido!\n");
                 }
                 
                 if(poltronas[fileira-1][assento-1]==1)
                 {
                     system("cls");
                     printf("Lugar ocupado!!!\n\n");
                 }
                 else
                 {
                     system("cls");
                     printf("Lugar comprado!\n\n");
                     printf("Voce adquiriu uma passagem da classe executiva, na poltrona %d-%d\n\n\n\n", fileira, assento);
                     poltronas[fileira-1][assento-1]=1;
                 }
     } 
     
     if(opcao==2)
     {
                 printf("CLASSO ECONOMICA:");
                 while(fileira<1 || fileira>4)
                 {
                    printf("\n\nQual fileira deseja comprar (1, 2, 3, 4)?\n");
                    scanf("%d", &fileira);
                 
                    if(fileira<1 || fileira>4)
                       printf("\nLugar inexistente!\n");
                 }
                 
                 while(assento<2 || assento>4)
                 {
                    printf("\nQual acento deseja comprar (2, 3, 4)?\n");      
                    scanf("%d", &assento);
                 
                    if(assento<2 || assento>4)
                       printf("\nAssento invalido!\n");
                 }
                 
                 if(poltronas[fileira-1][assento-1]==1)
                 {
                    system("cls");
                    printf("Lugar ocupado!!!\n\n");
                 }
                 else
                 {
                    system("cls");
                    printf("Lugar comprado!\n");
                    printf("Voce adquiriu uma passagem da classe economica, na poltrona %d-%d\n\n\n\n", fileira, assento);
                    poltronas[fileira-1][assento-1]=1;
                 }
     }
}

int main(int argc, char *argv[])
{
    
    int opcao=5, assentos[4][5], i, j;
    
    lugares(assentos);
    
    printf(">> SISTEMA DE RESERVA DE PASSAGENS AEREAS <<\n\n\n");
    
    
    while(opcao!=0)
    {
      opcao=5;
      while(opcao!=0 && opcao!=1 && opcao!=2 && opcao!=3)
      {
          printf("Por favor, pressione '1' para classe executiva.\n");
          printf("Por favor, pressione '2' para classe economica.\n");
          printf("Por favor, pressione '3' para mostrar os lugares.\n");
          printf("Por favor, pressione '0' para sair.\n");
          scanf("%d", &opcao);
          system("cls");
      
          if(opcao!=0 && opcao!=1 && opcao!=2 && opcao!=3)
             printf("Opcao invalida\n\n");
      }
  
      printf("\n");
      
      if(opcao!=0)
         mostra_lugar(assentos);
      printf("\n");
      compra_lugar(assentos, opcao);   
    }
    system("cls");
    
    printf("Saindo...\n\n");
  
  system("PAUSE");	
  return 0;
}
