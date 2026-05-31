/*  Trabalho 7 de SCC-0201 - ICC 2
 *  Aluno: Guilherme Ramos Oliveira NroUSP: 6908006
 *  Turma A - Professor Moacir
 *  Data: 26-10-2013
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//Marsaglia Normal Random Variables
double nextGaussian()
{
    static int count = 0;
    static double nextGaussianVal;
    double firstGaussianVal, v1, v2, s, multiplier;

    if (count == 0) {
       do {
           v1 = 2 * rand() - 1;   // between -1.0 and 1.0
           v2 = 2 * rand() - 1;   // between -1.0 and 1.0
           s = v1 * v1 + v2 * v2;
        } while (s >= 1 || s == 0);
        multiplier = sqrt(-2 * log(s)/s);
        nextGaussianVal = v2 * multiplier;
        firstGaussianVal = v1 * multiplier;
        count = 1;
        return firstGaussianVal;
    }

    count = 0;
    return nextGaussianVal;
}

int main()
{
    int m,i, custo, registro[10000000];

    scanf("%d", &m);
    for(i=0; i<m; i++)
    {
        scanf("%d",registro[i]);
    }
    scanf("%d", &custo);
    return 0;
}
