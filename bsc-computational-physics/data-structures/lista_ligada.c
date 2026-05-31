#include <stdio.h>
#include <stdlib.h>

typedef struct No_st{
    int numero;
    struct No_st *prox;
}No;

No * cria_lista(){     // Função do tipo apontador para lista, i.e., o tipo de função tem de ser igual ao tipo que retorna
    No * novo,*aux;
    novo = (No *) malloc( sizeof( No ));   /*Aloca memória do tamanho de uma célula*/
    if(novo == NULL) exit(0);    /* Se não alocar memória significa que não há memoria disponível, logo deve sair*/        
    novo->prox = NULL;         /*Como esta deve ser a primeira função a ser executada, esta célula vazia aponta para NULL*/    
    aux= novo; /*Para retornar o aux com o endereço da célula vazia, deve ser corrigido o valor do mesmo*/
    printf("Lista criada com sucesso!\n");
    return (aux); /*Retorna o aux*/
}

No * inserirNoInicio(No * raiz, int numero){
    No * novo, *aux;
    aux = raiz;
    novo = (No *) malloc( sizeof(No) );
    if(novo == NULL) exit(0);     
    novo->numero = numero;
    novo->prox = aux->prox;
    aux->prox = novo;
    return(aux);
}

void removerNoInicio(No *raiz){
    No *aux;
    if(raiz == NULL)
        printf("\nA lista ja esta vazia");
    else{
        aux = raiz->prox;
        raiz->prox = aux->prox;
        free(aux);
    }
}

// void removerNoFim(struct No **raiz){
//     if(*raiz == NULL)
//         printf("\nA lista ja esta vazia");
//     else{
//         struct No *auxFrente, *auxTras=NULL;
//         auxFrente = *raiz;
//         while(auxFrente->prox != NULL){
//             auxTras = auxFrente;
//             auxFrente = auxFrente->prox;
//         }

//         if(auxTras != NULL)
//             auxTras->prox = NULL;

//         free(auxFrente);
//     }
// }

void inserirNoFim(No **raiz, int numero){
    No *novo;
    novo = (No *) malloc(sizeof(No));
    if(novo == NULL) exit(0);
    novo->numero = numero;
    novo->prox = NULL;
    
    if(*raiz == NULL){
        *raiz = novo;
    }else{
        No *aux;
        aux = *raiz;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
        *raiz = aux;
    }
}

void imprimeElementosLista(No * raiz) {
    if (raiz != NULL) {
        printf ("%d\n", raiz->numero);
        imprimeElementosLista(raiz->prox);
    }
}
void imprimeElementosListaIterativa(No * raiz) {
    No *p;
    for (p = raiz; p != NULL; p = p->prox) 
        printf ("%d\n", p->numero);
}

int main(void){
    No * raiz;

    raiz = (No *) malloc( sizeof(No) ); 
    raiz = cria_lista();
    raiz = inserirNoInicio(raiz, 23);
    raiz = inserirNoInicio(raiz, 234);
    raiz = inserirNoInicio(raiz, 32);
    // raiz = inserirNoFim(&raiz, 100);
    imprimeElementosListaIterativa(raiz);

}
