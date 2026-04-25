#include<stdio.h>
#include<conio.h>

void InsereEmHeap (int m, int v[]) {
int f = m+1;
while /*X*/ (f > 1 && v[f/2] < v[f]) {
int t = v[f/2]; v[f/2] = v[f]; v[f] = t;
f = f/2;
}
}

void SacodeHeap (int m, int v[]) {
int t, f = 2;
while /*X*/ (f <= m) {
if (f < m && v[f] < v[f+1]) ++f;
if (v[f/2] >= v[f]) break;
t = v[f/2]; v[f/2] = v[f]; v[f] = t;
f *= 2;
}
}


void heapsort (int n, int v[]) {
     int m;
     for (m = 1; m < n; m++)
         InsereEmHeap (m, v);
                      for (m = n; /*X*/ m > 1; m--) {
                      int t = v[1]; v[1] = v[m]; v[m] = t;
                      SacodeHeap (m-1, v);
                      }
}



main(){
       
       
       int vet[5]={2,4,8,7,1};
       int num=6;
       
       
       
       heapsort(num,vet);
       
       
       
       getch();
       }
