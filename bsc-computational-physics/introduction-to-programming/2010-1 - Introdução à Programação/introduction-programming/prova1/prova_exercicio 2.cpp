# include <stdio.h>

    main(){
    int nUSP[10]={7,2,7,5,8};
    int i,j,aux;
    i=0;
    j=4;
    while(j>i){
      aux=nUSP;
      nUSP=nUSP[j];
      nUSP[j]=aux;
       i++;
       j--;
       }
  for (i=0 ;i<5;i=i+2)
  printf("%d",nUSP);
  getchar();
}
