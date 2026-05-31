/* PRIMEIRO TRABALHO DE C - 18 DE MAIO DE 2010
ALEXANDRE RAY DA SILVA
FÍSICA COMPUTACIONAL */

#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

char converte(int x){    //funcao que converte 1 em a, 2 em b...
     char novo='\0';
     if (x == 1)
     novo = 'A';
     else if (x == 2)
     novo = 'B';                                
     else if (x == 3)
     novo = 'C';                                      
     else if (x == 4)
     novo = 'D';                                                 
     return(novo); } 
        
int limpa_matriz(int mat[][5]){
     for (int i=1; i<6;i++){
        for (int j=1;j<5;j++){ 
             mat[i][j] = 0; 
             //printf("[%d][%d]: %d\n",i,j,mat[i][j]); //verifica se a matriz esta limpa      
             }
             }             
     }  
          
main(){
int vet[4][5]; 
int tipo_classe = 0; 
int flag_sair1 = 0; 
int flag_sair2 = 0;      
int cont1=1; //contador da classe executiva
int cont2=1; //contador da classe economica  
int flag_fz=0;
                  
limpa_matriz(vet);      
                 
printf("Pressione 1 para Classe Executiva\nPressione 2 para Classe Economica\nOu qualquer numero diferente de 1 ou 2 para sair.\n");
scanf("%d", &tipo_classe);                    
                  
for(int loop=0; loop<20; loop++){ //loop que permite a alternancia entre os tipos de classe
        
if(tipo_classe<1 || tipo_classe>2){
printf("classe invalida\n");
printf("Saindo...\n\n");
loop=20;
}        
while (tipo_classe == 1){ 
                
                  flag_sair1 = 0;
                  for (int i=1;i<3;i++){ //colunas
                  for (int j=1;j<5;j++){ //linhas
                      
                      
                      if(vet[i][j] == 0 && flag_sair1 ==0){                                                
                                vet[i][j] = 1;
                                printf("\nCartao de embarque 1.%d:\nPoltrona %d%c,\nArea executiva\n\n",cont1,i,converte(j));  
                                printf("==========================================\n");
                                flag_sair1 =1;                              
                                cont1++;                                                       
                                     }   
                }} //fecha for
                //validações da classe executiva
                        if(cont1==9 && cont2==13){
                        printf("Nao ha mais lugares no aviao\nO proximo voo sai as 3hrs\n");
                        printf("==========================================\n");
                        system("pause");
                        }
                        
                        else if(cont1 == 9 && cont2<12){
                             printf("nao ha mais lugares na classe executiva\n");
                             printf("==========================================\n");
                             printf("OPCAO 1: CLASSE EXECUTIVA\nOPCAO 2: CLASSE ECONOMICA\n");
                             scanf("%d", &tipo_classe);}
                
                        else {printf("OPCAO 1: CLASSE EXECUTIVA\nOPCAO 2: CLASSE ECONOMICA\n");
                        scanf("%d", &tipo_classe);}          
                 
                 
} //WHILE TIPO_CLASSE = 1           
                 
while (tipo_classe == 2){            
                     
                     flag_sair2 = 0;          
                     for (int i=3;i<6;i++){ //colunas
                     for (int j=1;j<5;j++){ //linhas  
                                             
                               if(vet[i][j] == 0 && flag_sair2 == 0 ){
                    
                               vet[i][j] = 1;
                               printf("\nCartao de embarque 2.%d:\nPoltrona %d%c,\nArea economica\n\n",cont2,i,converte(j));
                               printf("==========================================\n");
                               flag_sair2 = 1;   
                               
                               cont2++;
                               }                          
                               
                        }}//fecha for
                    //validações da classe economica             
                        if(cont1==9 && cont2==13){
                        printf("Nao ha mais lugares no aviao\nO proximo voo sai as 3hrs\n");
                        printf("==========================================\n");
                        system("pause");
                        }
                        
                        else if(cont1 < 9 && cont2 == 13){
                             printf("nao ha mais lugares na classe economica\n");
                             printf("==========================================\n");
                             printf("OPCAO 1: CLASSE EXECUTIVA\nOPCAO 2: CLASSE ECONOMICA\n");
                             scanf("%d", &tipo_classe);}
                
                        else {printf("OPCAO 1: CLASSE EXECUTIVA\nOPCAO 2: CLASSE ECONOMICA\n");
                        scanf("%d", &tipo_classe);
                        }                      
                                 
} //fecha WHILE TIPO_CLASSE = 2        
                      
}//fecha loop         
                      
     system("pause");
     
}//fecha main
