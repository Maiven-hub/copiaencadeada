#include<stdio.h>
#include<stdlib.h>

typedef struct node {
	int valor;
	struct node* prox;
} NODE;

typedef struct {
	NODE* inicio;
	NODE* fim;	
} LISTA;

void inserir(LISTA* lista, int valor) {
	// INSERIR NO FIM
	NODE* novo = (NODE*) malloc(sizeof(NODE));
	novo->valor = valor;
	novo->prox = NULL;
	
	if(lista->inicio == NULL) {
		lista->inicio = novo;
		lista->fim = novo;
	} else {
		lista->fim->prox = novo;
		lista->fim = novo;
	}
}

void remover(LISTA* lista) {
	if(lista->inicio != NULL) {
		// APAGAR O IN�CIO
		NODE* apagar = lista->inicio;
		
		if(lista->inicio == lista->fim)
			lista->fim = NULL;
		
		lista->inicio = apagar->prox;
		
		free(apagar);
	}
}

void copiaLista(LISTA* lista1, LISTA* lista2) {
  
    lista2->inicio = lista1->inicio;
    
    printf("COPIA DA LISTA\n");
		NODE* aux = lista2->inicio;
	  while(aux != NULL) {
		printf("%d\n", aux->valor);
		aux = aux->prox;
	}
	
  
	
}

int main() {
	LISTA minhaLista;
	LISTA minhaLista2;
	
	minhaLista.fim = NULL;
	minhaLista.inicio = NULL;
	
	inserir(&minhaLista, 1);
	inserir(&minhaLista, 2);
	inserir(&minhaLista, 3);
	inserir(&minhaLista, 4);
  
	copiaLista(&minhaLista,&minhaLista2);
  
	printf("MINHA LISTA\n");
	NODE* aux = minhaLista.inicio;
	while(aux != NULL) {
		printf("%d\n", aux->valor);
		aux = aux->prox;
	}
	return 1;
}
