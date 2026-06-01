#include<stdio.h> // entradas e saidas
#include<stdlib.h> //system pause
#include<conio.h> // getch

main()
{
       int n=0, altas=0, baixas=0, pontos;
       scanf("%d",&pontos);
       while(pontos>=0)
       {
                        if(pontos>=100)
                                                               
                        altas++;
                        
                        else if(pontos<50)
                        
                        baixas++;
                        
       n++;
       scanf("%d", &pontos) ;
       }       
       printf("\n%d, %d, %d\n", n, baixas, altas);
       system("pause");
}

//o programa diz quantos numeros foram digitados 
// quantos numeros menor que 50
//quantos numeros maiores que 100
       
     
     
     
     
     
     
     
     
     
                          
                     
       
