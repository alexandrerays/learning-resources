#include<stdio.h>
#include<stdlib.h>
/*int eCar(char c1,char c2)
{
    int r;
    if(c1==c2)
              r=1;
    else
              r=0;
    return(r);        
}*/

main(){
       //char s[50];
       char ca='\0';
       char cb='\0';
       printf("Ingrese o caracter 1:\n");
       scanf("%c", &ca);
       
       printf("Ingrese o caracter 2:\n");
       scanf("%c", &cb);
       
       
       printf("%c %c", ca, cb);
       
       /*if(eCar(ca, cb)==1)
           puts("caracter encontrado");
        else
           puts("caracter não encontrado");
           
       
*/       
 system("pause");
       }
