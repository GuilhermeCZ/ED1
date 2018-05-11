#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
   int info;
   struct lista *prox;
}Lista; 

#define MAX 110

Lista *separa(Lista* l, int n);

Lista *init(){
	return NULL;
}

Lista *addLista(Lista *l, int n){
	Lista *novo, *aux;
	if (l == NULL)
	{
		novo = (Lista *) malloc (sizeof(Lista));
		if(novo == NULL) return l;
		novo->info = n;
		novo->prox = NULL;
		return novo;
	}else{
		for (aux = l; aux->prox != NULL; aux = aux->prox);
		novo = (Lista *) malloc (sizeof(Lista));
		if(novo == NULL) return l;
		novo->info = n;
		novo->prox = l;
		return novo;
	}
	return l;
}

void imprime(Lista *l){
	Lista *aux;
	for (aux = l; aux != NULL; aux = aux->prox)
	{
		printf("%d\n", aux->info);
	}
}




int main (){
	Lista *l = init(), *l2 = init();
	int i;

	for (i = 0; i < MAX; ++i)
	{
		l = addLista(l, rand()%MAX);
	}
	imprime(l);
	printf("\n");
	l2 = separa(l, 15);
	imprime(l);
	printf("\n");
	imprime(l2);
	return 1;
}


Lista *separa(Lista* l, int n) {
	//implementar
}



