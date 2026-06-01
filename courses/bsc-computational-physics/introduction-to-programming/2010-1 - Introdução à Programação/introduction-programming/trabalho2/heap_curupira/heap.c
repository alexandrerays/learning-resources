#include <stdio.h>
#include <stdlib.h>

void mantemheapmax(long int *a, long int i, long int compheap){
    long int esq,dir,mai,men,temp;
    esq=2*i+1;
    dir=2*i+2;
    if (esq < compheap && a[esq]>a[i])
        mai=esq;
    else
        mai=i;
    if (dir < compheap && a[dir]>a[mai])
        mai=dir;
    if (mai != i){
        temp=a[i];
        a[i]=a[mai];
        a[mai]=temp;
        mantemheapmax(a,mai,compheap);
    }
}

void constroiheapmax(long int *a, long int a_lenght){
    long int compheap=a_lenght;
    long int i;
    for(i=a_lenght/(2-1);i>=0;i--)
        mantemheapmax(a,i,compheap);
}

void heapsort(long int *a, long int a_lenght){
    long int i, compheap, temp;
    compheap=a_lenght;
    constroiheapmax(a,a_lenght);
    for(i=a_lenght-1;i>0; i--){
        temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        compheap--;
        mantemheapmax(a,0,compheap);
    }
}

void randomizar (int *v, int n){
    int i=0;
    for (;i<n;i++)
        v[i]= rand() % 20;
}

void criar (int *v, int n){
    srand(time(NULL));
    int i=0;
    for (;i<n;i++)
        v[i]= i;
}

void imprimir (int *v, int n){
    int i=0;
    for (;i<n;i++)
        printf("%d ", v[i]);
}


int main(){
    int n;
    scanf("%d", &n);
    int *v;
    v=(int*)malloc(n*sizeof(int));
    randomizar(v,n);
//    imprimir(v,n);
//    printf("\n");
    heapsort(v,n);
//    imprimir(v,n);
    free(v);
    return(0);
}
