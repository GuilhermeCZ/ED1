#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
#define TAM 50

int gcod = 0;

typedef struct _produto { //criação de uma struct tipo produto
  int cod;
  char nome[TAM];
  float preco;
}tp_produto;

typedef struct _nodo {
  tp_produto info;
  struct _nodo *next;
}tp_nodo;

typedef struct _fila {
  int size;
  tp_nodo *first;
  tp_nodo *last;
}tp_fila;

tp_fila *push(tp_fila *fil){
  tp_nodo *new = (tp_nodo*)malloc(sizeof(tp_nodo));
  fil->size++;

  if (fil->size == 1){ // Caso for o primeiro elemento da lista
    fil->first = new;  // ele é o primeiro da lista
  } else {
    fil->last->next = new;   // colcoa o ultimo que aponta pro proximo o novo recebido
  }
  fil->last = new; // o ultmo elemento e sempre o que esta sendo inserido
  new->next = NULL; // e o novo proximo recebe null

  int codigo;
  char name[TAM];
  float price;

  if (!new) {
    printf("Sem memoria disponivel!\n");
    exit(1);
  } else {
    fil->size++; // adiciona a tamano, ou quantidade de itens da lista
    gcod++;
    printf("Qual o Codigo do produto: %d\n", gcod);
    printf("Qual o nome do produto: ");
    __fpurge(stdin);
    fgets(name, TAM, stdin);
    printf("Qual o valor do produto: ");
    scanf("%f", &price);

    new->info.cod = gcod;
    strcpy(new->info.nome, name);
    new->info.preco = price;
    return fil;
  }
}

tp_fila *pop(tp_fila *fil){ //função para remover o item da lista
  fil->first = fil->first->next;  // o primeiro recebe o proximo do primeiro
                                  // assim excluindo o primeiro da lista
  fil->size--; // diminui o tamanho da lista
  return fil;
}

tp_nodo imprime(tp_nodo *nodo, tp_fila *fil){
  int i=0;
  foco = nodo;
  do {
    if (fil->size == 0) {
      printf("Lista Vaiza\n");
      break;
    }
    ++i;
    printf("Codigo: %d\n", foco->info.cod);
    printf("Nome:   %s", foco->info.nome);
    printf("Preço: %.2f\n\n", foco->info.preco);
    fil = fil->next;
    foco = foco->next;
  } while(i <= fil->size);
}

tp_fila *clear(tp_fila *fil){
  fil->size = 0;
  fil->first = NULL;
  fil->last = NULL;
}

void main(){
  tp_fila *fila;
  clear(fila);
  fila->size = 0;
  int i;

  do {
    printf( "Qual operação deseja realizar\n"
            " 1 - Adicionar (PUSH)\n"
            " 2 - Remover (POP)\n"
            " 3 - Exibir dados\n"
            " 4 - Limpa dados\n"
            " 0 - Sair\n"
            "Opção: ");
    scanf("%d", &i);

    switch (i) {
      case 1:
        system("clear");
        printf("Push:\n");
        fila = push(fila);
        system("clear");
      break;
      case 2:
        system("clear");
        printf("POP:\n");
        fila = pop(fila);
        printf("\n\n");
      break;
      case 3:
        system("clear");
        printf("Dados: \n");
        fila = imprime(fila);
        printf("\n\n");
      break;
      case 4:
        system("clear");
        clear(fila);
        fila = imprime(fila);
        printf("\n\n");
      break;
      case 0:
        exit(2);
      break;
      default:
        printf("Opação incorreta, tente novamente\n");
      break;
    }
  } while(i!=0);
  //free(lista);
  free(fila);
}
