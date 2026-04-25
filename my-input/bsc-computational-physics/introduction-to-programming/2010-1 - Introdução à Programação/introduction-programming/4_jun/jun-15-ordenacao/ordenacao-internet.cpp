#include <stdio.h>

int quantidade(void);

int  main(){
	register int 	i,
					j;
	int				q;
	q = quantidade(); //quantidade de numeros de entrada
	int num[q];
	int temp;

	//Recebe os valores digitados
	for (i=0;i<q;i++){
		printf("Entre com o numero %d :",i+1);
		scanf("%d",&num[ i ]);
	}

	//Ordena valores valores do vetor num em ordem crescente
	for(j=q;j>0;j--){
		for(i=0;i<j;i++){
			if(num[ i ]>num[i+1]){
				temp = num[ i ];
				num[ i ] = num[i+1];
				num[i+1] = temp;
			}
		}
	}

	//Imprime o vetor ja ordenado
	puts("\n");
	for (i=0;i<q;i++){
		printf(" %d",num[ i ]);
	}
}

int quantidade(void){
	int num;

	puts("Entre com a quantidade de numeros que deseja ordenar: ");
	scanf("%d",&num);
	return num;
}


	//Ordena valores valores do vetor num em ordem crescente
	for(j=q;j>0;j--){
		for(i=0;i<j;i++){
			if(num[ i ]>num[i+1]){
				temp = num[ i ];
				num[ i ] = num[i+1];
				num[i+1] = temp;
			}
		}
	}

	//Imprime o vetor ja ordenado
	puts("\n");
	for (i=0;i<q;i++){
		printf(" %d",num[ i ]);
	}
}

int quantidade(void){
	int num;

	puts("Entre com a quantidade de numeros que deseja ordenar: ");
	scanf("%d",&num);
	return num;
}
