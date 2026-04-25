/* Tipos de operações - 13, 10, 6, 3 */

#include <stdio.h>

int main() {
       int v=0, x=1, y=2, z=3;
       v+=x+y;
       x*=y=z+1;
       z%=v+v+v;
       v+=x+=y+=2;       
       printf("%d, %d, %d, %d\n", v, x, y, z);
}