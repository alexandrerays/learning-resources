//#include <stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

 
inline void troca(int* a, int* b)
{
  int aux = *a;
  *a = *b;
  *b = aux;
}
 
void bubbleSort (int *primeiro, int *ultimo) 
{
  bool naoTrocou;
  int *posAtual;
  for (; ultimo > primeiro; --ultimo)
  {
    naoTrocou = true;
    for (posAtual = primeiro; posAtual < ultimo; ++posAtual)
    {
      if (*posAtual > *(posAtual+1))
      {
        troca (posAtual, posAtual+1);
        naoTrocou = false;
      }
    }
    if (naoTrocou) return;
  }
}
