#include <stdio.h>

int main() {
    int n;
    float nota, media;
    media = 0;
   
   
   printf("\nDigite o numero de notas a serem lidas: ");
   scanf("%d",&n);
   for(int i=0; i<n; i++) {
           printf("Digite a nota: ");
           scanf("%f",&nota);
           media = media + nota;
   }
   
   media = media/n;
   
    
   printf("\n\nA media das notas eh %f", media);
    
    getchar();
    getchar();

    
    return(0);
    
}
