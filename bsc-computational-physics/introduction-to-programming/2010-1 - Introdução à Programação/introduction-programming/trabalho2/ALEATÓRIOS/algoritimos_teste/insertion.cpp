#include<stdio.h>
#include<conio.h>
#define num 8


void insertion (int n, int v[]) {
int i, j, x;
    for (j = 1; j < n; j++) {
    x = v[j];
    for (i = j-1; i >= 0 && v[i] > x; i--)
        v[i+1] = v[i];
               v[i+1] = x;
               }
}


main(){
       
       
       int vet[]={2,4,8,7,1,6,3,3};
       
       
       insertion(num,vet);
       
       for(int z=0; z<num; z++)
       printf("%d ",vet[z]);
       
       
       
       getch();
       }
