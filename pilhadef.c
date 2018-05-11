#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 50

typedef struct _produto{ //criação de uma struct tipo produto
  int cod;
  char nome[TAM];
  float preco;
}tp_produto;

typedef struct _pilha{ // cria a pilha
  tp_produto *info;
  struct pilha *prox;
}tp_pilha;

tp_pilha *push(tp_pilha *topo){
  int codigo;
  char name[TAM];
  float price;

  tp_produto *novo=(tp_produto*)malloc(sizeof(tp_produto));

  if(!novo){
    printf("Sem memoria disponivel!\n");
    return topo;
  }else{
    printf("Código do Produto: ");
    scanf("%d", &codigo);
    printf("Nome do Produto: ");
    __fpurge(stdin);
    fgets(name, TAM, stdin);
    printf("Preço do Produto: ");
    scanf("%f", &price);

    (novo->prox+novo->info).cod = codigo;
    strcpy ((novo->prox+novo->info.nome), codigo);
    (novo->prox+novo->info).preco = price;
    return novo;
  }
}

tp_pilha *pop(tp_pilha *topo){
  if (topo->prox == NULL) {
    printf("Pilha Vazia\n");
    exit(1);
  } else {
    tp_pilha *last = topo->prox,
    *penultimo = topo;

    while(last->prox != NULL){
      penultimo = last;
      last = last->prox;
    }

    penultimo->prox = NULL;
    return last;
  }
}

tp_pilha *imprime(tp_pilha *topo){
  tp_pilha *tmp;
  tmp = topo->prox;
  if (topo->prox == NULL) {
    printf("Pilha Vazia\n");
    exit(1);
  } else {
    while( tmp != NULL){
      printf("%d\n", tmp->info.cod);
      printf("%s", tmp->info.nome);
      printf("%2f\n", tmp->info.preco);
      tmp = tmp->prox;
    }
  }
}

int main() {
  int op;
  tp_pilha *pilha = NULL;

  do {
    printf( "Qual opção deseja fazer?\n"
            " 1 - Inserer na Pilha (PUSH)\n"
            " 2 - Remover da Pilha (POP)\n"
            " 3 - Imprimir dados da Pilha\n"
            " 0 - Sair\n"
            "Opção: ");
    scanf("%d", &op);


    switch (op) {
      case 1:
        system("clear");
        pilha = push(pilha);
      break;
      case 2:
        system("clear");
        pilha = pop(pilha);
      break;
      case 3:
        system("clear");
        pilha = imprimi(pilha);
      break;
      case 0:
        printf("Você Saiu!\n");
      break;
      default:
        printf("Opção nao encontrada, Tente novamene\n");
      break;
    }
  } while(op != 0);
  return 0;
}
