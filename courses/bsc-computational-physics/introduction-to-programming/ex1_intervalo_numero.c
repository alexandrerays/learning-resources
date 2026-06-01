/*
Entrada: Sequência de números
Saída: Intervalo em que o número está e quantos números foram passados de entrada
*/

#include <stdio.h>

int main() {
      int n = 0, maiores = 0, menores = 0, meio = 0, numero;
      printf("Entre com uma sequência de números ou -1 para sair: \n");
      scanf("%d", &numero);
      while (numero >= 0) {
            if (numero < 50)                                             
                  menores++;
            else if (numero >= 50 && numero < 100)
                  meio++;            
            else if (numero >= 100)
                  maiores++;
            n++;
            scanf("%d", &numero) ;
      }
      printf("\nResultado do programa:\n");
      printf("Qtde de números: %d\n\nMenor que 50: %d\nEntre 50 e 100: %d\nMaiores que 100: %d\n", n, menores, meio, maiores);
}