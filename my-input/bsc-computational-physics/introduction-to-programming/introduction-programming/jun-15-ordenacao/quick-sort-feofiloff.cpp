#include<stdio.h>
#include<conio.h>

int Separa (int p, int r, int v[]) {
    int c, j, k, t;
    c = v[r]; j = p;
    for (k = p; /*A*/ k < r; k++)
    if (v[k] <= c) {
    t = v[j], v[j] = v[k], v[k] = t;
    j++;
    }
    v[r] = v[j], v[j] = c;
return j;
}


void Quicksort (int p, int r, int v[]) {
     int j;
     if (p < r) {
     j = Separa (p, r, v);
     Quicksort (p, j - 1, v);
     Quicksort (j + 1, r, v);
     }
}

