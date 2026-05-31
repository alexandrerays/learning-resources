#include <stdio.h>

int main() {
    
    int d,m,a;
    int bissexto = 0;
    int ok = 0;
    
    printf("\n********* INCREMENTA 1 DIA **********");
    printf("\n\nInsira o dia: ");
    scanf("%d",&d);
    printf("\nInsira o mes: ");
    scanf("%d",&m);
    printf("\nInsira o ano: ");
    scanf("%d",&a);
    
    //verificao das entradas
    if((d<=0)||(d>31)||(m>12)||(m<=0)||(a<0)) {
                      printf("\n\nEntrada Invalida! \n\n");
                      getchar();
                      getchar();
                      return(0);
    }
    
    //verificacao para ano bissexto
    if((a%100)==0) {
                  
                  if((a%400)==0) bissexto = 1;
                                 
    } else if((a%4)==0) bissexto = 1;
    
    
   if(bissexto==0) { // para anos nao bissextos
                   if((m==2)&&(d>=29)) {
                                      printf("\n\nEm anos nao bissextos nao existe dia acima do dia 28 de fevereiro!");
                                      getchar();
                                      getchar();
                                      return(0);
                   }
                   if((m==2)&&(d==28)) {
                                      d = 1;
                                      m = 3;
                                      ok =1;
                   } 
   }else { // se o ano é bissexto
        if((m==2)&&(d==29)) {
                           d = 1;
                           m = 3;
                           ok =1;
        } else if((m==2)&&(d>=30)) { //erro para 30 e 31 de fevereiro
                                      printf("\n\n Não existe dia %d de fevereiro !",d);
                                      getchar();
                                      getchar();
                                      return(0);
        }
               
   } 
   
  
   
   //vericacao dos dias 31 e 30
   if(d==31) {
             //meses que nao tem o dia 31
             if((m!=1)&&(m!=3)&&(m!=5)&&(m!=7)&&(m!=8)&&(m!=10)&&(m!=12)) {
                                                                          printf("\nNao existe dia 31 no mes %d\n",m);
                                                                          getchar();
                                                                          getchar();
                                                                          return(0);
             }
             //meses que tem o dia 31, menos dezembro
             if((m==1)||(m==3)||(m==5)||(m==7)||(m==8)||(m==10)) {
                                                                 d = 1;
                                                                 m = m + 1;
                                                                 ok = 1;
             }
             //dezembro
             if(m==12) {
                       d = 1;
                       m = 1;
                       a = a+1;
                       ok = 1;
             }
   }
   
   if(d==30){
             //dia 30 em meses que vao ate o dia 30
             if((m==4)||(m==6)||(m==9)||(m==11)) {
                                                 d = 1;
                                                 m = m + 1;
                                                 ok = 1;
             } else { //dia 30 em meses que vao até 31
                    d = 31;
                    ok =1;
                    }
   } else { //qualquer dia que nao seja 30 ou 31 ou nao esteja no mes de fevereiro
          if(ok==0) d = d + 1;
   }
   

   printf("\n\n A nova data sera %d/%d%/%d\n\n",d,m,a); 
    
    getchar();
    getchar();
        
    
    return(0);
    
}
