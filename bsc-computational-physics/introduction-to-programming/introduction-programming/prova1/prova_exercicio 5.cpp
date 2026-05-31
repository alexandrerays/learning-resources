#include<stdio.h>
#include<stdlib.h>

main(){
       int x=0;
       float temp;
       float r=0;
       
       puts("Conversor de temperatura\n\n");
       puts("escolha uma opcao");
       do
                     {
                     puts("(2) celsius para hahrenheit\n");
                     puts("(1) fahrenheit para celsius\n");
                     puts("(3) sair\n");
                     scanf("%d", &x);
                     }
                     while((x<1)||(x>3)); 
                     switch(x){
                               //puts("escolha uma temp");
                               case 1:
                                    puts("escolha uma temp em fahrenheit");
                                    scanf("%f", &temp);
                                    r=(temp-32)/1.8;
                                    break;
                               case 2:
                                    puts("escolha uma temp em celsius");
                                    scanf("%f", &temp);
                                    r=1.8*temp+32;
                                    break;
                               case 3:
                                    puts("vá se ferrar");
                                    break;      
                               } 
                               printf("%f", r);     
       system("pause");
       }
