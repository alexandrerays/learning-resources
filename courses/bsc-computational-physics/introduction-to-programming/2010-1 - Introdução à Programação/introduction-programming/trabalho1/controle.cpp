#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//************************************************************************************************************
//*************************************************Colocar pessoa na classe **********************************
//************************************************************************************************************
void ass(int classe, int L[4][5])

{

if (classe==1)   
                {  
                   int h=0, q=0;
                              
                      for(int i=0; i<4; i++)
                        {
                            for (int j=0; j<2 && h<1; j++)
                              {
                                      if (L[i][j]==0) {
                                                         L[i][j]=1;
														 printf("\n __________________________________");
														 printf("\n|Fila: %d Acento:%d                  |",i+1,j+1);
														 printf("\n|Localizado na Classe Executiva.   |");
														 printf("\n|Agradecemos a preferencia         |");
                                                         printf("\n|__________________________________|");
                                                         h=1;
                                                       } 
                               }
                        }	 
                     if (h==0)
                     {    
                        printf("\n\nNao ha mais lugares na classe executiva, deseja lugar na classe economica?\n");
                        printf("\n\n1 - SIM , 2 - NAO\n");
                        scanf("%d",&q);
                                if (q==1)      
                                      ass(2,L);
                                if (q==2)
                                {
                                     printf("O Proximo Voo sai daqui ha 3 horas!");      
                                }   
                     }                
                }  
if (classe==2)   
                {  
                   int h=0, q=0;
                        for(int i=0; i<4; i++)
                  {
                          for (int j=2; j<5 && h<1; j++)
                              {
                                      if (L[i][j]==0) {
                                                         L[i][j]=1;
                                                         printf("\n __________________________________");
                                                         printf("\n|Fila: %d Acento:%d                  |",i+1,j+1);
													     printf("\n|Localizado na Classe Economica.   |");
														 printf("\n|Agradecemos a preferencia         |");
                                                         printf("\n|__________________________________|");
                                                         h=1;
                                                       } 
                               }
							 
                   }
                   
                if (h==0)
                    {    
                      printf("\n\nNao ha mais lugares na classe economica, deseja lugar na classe executiva?");
                      printf("\n\n1 - SIM , 2 - NAO\n");
                      scanf("%d",&q);
                              if (q==1)      
                                 ass(1,L);
                              if (q==2)
                                 printf("O Proximo Voo sai daqui ha 3 horas!");      
                     } 
                }  
 
                
}

//************************************************************************************************************
//************************************************************************************************************
main()

{
           
 int L[4][5];
 int classe;
 int k=0;
 
 for(int i=0; i<4; i++)
         {
              for (int j=0; j<5; j++)
                  L[i][j]=0;
                  }
do{

              
         

             printf("\n\nPor favor, pressione 1 para \"classe executiva\"\n");
             printf("\nPor favor, pressione 2 para \"classe economica\"\n");
             printf("\nPor favor, pressione 3 para \"sair do programa\"\n");
             scanf("%d",&classe);
                          
 if (classe==3)
    return 0;
                
ass(classe, L);			 

             
getchar();            

}while(k==0);
      
}
