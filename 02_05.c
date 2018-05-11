#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#define TAM 50

typedef struct _produto{//criação de uma struct tipo produto
  int cod;
  char nome[TAM];
  float preco;
}tp_produto;

typedef struct _node{
  tp_produto produto;
  struct nodo *prox;
}tp_nodo;

tp_nodo *push(tp_nodo *x){ //INSERE UM NOVO PRODUTO NA LISTA
  tp_nodo *novo= (tp_nodo *) malloc(sizeof(tp_nodo));
  int a;
  char b[50];
  float c;

  printf("Insercao de novo produto.\nDigite o CODIGO do produto:  ");
  scanf("%d\n", &a);
  printf("Digite o NOME do produto:  ");
  __fpurge(stdin);
  fgets(b, 50, stdin);
  printf("Digite o VALOR do produto:  ");
  scanf("%f\n", &c);
  printf("Cadastro encerrado!\n\n\n");

  novo->produto.cod=a;
  strcpy(novo->produto.nome, b);
  novo->produto.preco=c;
  novo->prox=x;

  return novo;
}


tp_nodo *pop(tp_nodo *x){ //APAGA O ULTIMO PRODUTO SE A LISTA NAO ESTIVER VAZIA

    if ((vazio(x)==1)) {
      printf("Fila vazia.\n" );
      return x;
    }
    else
      return x->prox;
}

int vazio(tp_nodo *x){
  if ((x->produto.cod)==NULL || (x->produto.nome)==NULL || (x->produto.preco)==NULL) {
    return 1;
  }
  else{
    return 0;
  }
}


void show(tp_nodo *x){
  do {
    printf("\nCODIGO: %d\n", x->produto.cod);
    printf("NOME: %s\n", x->produto.nome);
    printf("VALOR: %f\n", x->produto.preco);
    x=x->prox;
  } while(x!=NULL);
}

void main(){
  int x=999;
  tp_nodo *p = NULL;

  do {
    printf("Escolha uma Opcao:\n"
           "1 - Inserir produto\n"
           "2 - Remover produto\n"
           "3 - Imprimir produtos\n"
           "0 - Sair\n"
           "Opcao: ");
    scanf("%d", &x);

    switch (x) {
      case 1:  //push
        p=push(p);
      case 2: //pop
        p=pop(p);

      case 3: //show
        show(p);
      case 0: //exit
        printf("O programa será encerrado.\n" );
        //exit(1);
        break;
      default:
        printf("Opcao invalida\n");

    }

  } while(x!=0);

}
