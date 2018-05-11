#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TAM 50

typedef struct produto{//criação de uma struct tipo produto
  int cod;
  char nome[TAM];
  float preco;
};
typedef struct produto *prd ;

struct Node{
  int topo;
  struct produto *prox;
};
typedef struct Node *pi;

int size;

int menu(void);
void inicia(pi *PILHA);
void opcao(pi *PILHA, int op);
void exibe(pi *PILHA);
void libera(pi *PILHA);
void push(pi *PILHA);
pi *pop(pi *PILHA);

int main(void) {
  pi *PILHA = (pi *) malloc(sizeof(pi));
  if(!PILHA){
    printf("Sem memoria disponivel!\n");
    exit(1);
  }else{
    inicia(PILHA);
    int opt;

    do{
      opt=menu();
      opcao(PILHA,opt);
    }while(opt);

    free(PILHA);
    return 0;
  }
}

void inicia(pi *PILHA) {
  PILHA->prox = NULL;
  size=0;
}

int menu(void) {
  int opt;

  printf("Escolha a opcao\n");
  printf("0. Sair\n");
  printf("1. PUSH\n");
  printf("2. POP\n");
  printf("3. Exibir PILHA\n");
  printf("4. Zerar PILHA\n");
  printf("Opcao: "); scanf("%d", &opt);

  return opt;
}

void opcao(pi *PILHA, int op) {
  pi *tmp;
  switch(op){
    case 0:
    libera(PILHA);
    break;

    case 1:
    push(PILHA);
    break;

    case 2:
    tmp= pop(PILHA);
    if(tmp != NULL)
    printf("Retirado: %3d\n\n", tmp->topo);
    break;

    case 3:
    exibe(PILHA);
    break;

    case 4:
    libera(PILHA);
    inicia(PILHA);
    break;
    default:
    printf("Comando invalido\n\n");
  }
}

int vazia(pi *PILHA)
{
  if(PILHA->prox == NULL)
    return 1;
  else
    return 0;
}

pi *aloca() {
  prd *novo=(prd*)malloc(sizeof(prd));
  if(!novo){
    printf("Sem memoria disponivel!\n");
    exit(1);
  }else{
    printf("Código do Produto: "); scanf("%d", &(novo->num+novo->prd)->cod);
    printf("Nome do Produto: "); scanf("%s", &(novo->num+novo->prd)->nome);
    printf("Preço do Produto: "); scanf("%d", &(novo->num+novo->prd)->preco);

    return novo;
  }
}

void exibe(pi *PILHA) {
  if(vazia(PILHA)){
    printf("PILHA vazia!\n\n");
  return ;
  }

  pi *tmp;
  tmp = PILHA->prox;
  printf("PILHA:");
  while( tmp != NULL){
    printf("%5d", tmp->topo);
    tmp = tmp->prox;
  }
  printf("\n        ");
  int count;
  for(count=0 ; count < size ; count++)
    printf("  ^  ");
    printf("\nOrdem:");
  for(count=0 ; count < size ; count++)
    printf("%5d", count+1);
    printf("\n\n");
}

void libera(pi *PILHA) {
  if(!vazia(PILHA)){
    pi *proxNode,
    *atual;

    atual = PILHA->prox;
    while(atual != NULL){
      proxNode = atual->prox;
      free(atual);
      atual = proxNode;
    }
  }
}

void push(pi *PILHA) {
  pi *novo=aloca();
  novo->prox = NULL;

  if(vazia(PILHA))
    PILHA->prox=novo;
  else{
    pi *tmp = PILHA->prox;

  while(tmp->prox != NULL)
    tmp = tmp->prox;

    tmp->prox = novo;
  }
  size++;
}

pi *pop(pi *PILHA) {
  if(PILHA->prox == NULL){
    printf("PILHA ja vazia\n\n");
    return NULL;
  }else{
    pi *ultimo = PILHA->prox,
    *penultimo = PILHA;

    while(ultimo->prox != NULL){
      penultimo = ultimo;
      ultimo = ultimo->prox;
    }

    penultimo->prox = NULL;
    size--;
    return ultimo;
  }
}
