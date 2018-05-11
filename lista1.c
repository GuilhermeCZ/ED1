#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
#define TAM 50

int gcod = 0;

typedef struct produto{ //criação de uma struct tipo produto
  int cod;
  char nome[TAM];
  float preco;
}tp_produto;

typedef struct Node{
  tp_produto info;
  struct node *prox;
}tp_node;

tp_node *push(tp_node *NODO){
  tp_node *new = (tp_node*)malloc(sizeof(tp_node));

  int codigo;
  char name[TAM];
  float price;

  if (!new) {
    printf("Sem memoria disponivel!\n");
    exit(1);
  } else {
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
    new->prox = NODO;
    return new;
  }
}

tp_node *pop(tp_node *NODO){ //função para remover o item da lista
  if (NODO == NULL) {
    printf("A lista está vazia\n");
    return NODO;
  }
  int pcode;
  tp_node *ant = NULL; // ponteiro para identificar o ant
  tp_node *aux = NODO;
  printf("Digite o codigo do produto a ser removido: ");
  scanf("%d", &pcode);

  while (pcode != aux->info.cod) {
    if (aux->prox == NULL) {
      goto next;
    } else {
      ant = aux;
      aux = aux->prox;
    }
  }
  next: ;
  if(pcode == aux->info.cod){ //SE ACHOU O CODIGO
    if (ant == NULL && aux->prox == NULL) { //SE EXISTIR APENAS UM NODO E ELE FOR EXCLUIDO A LISTA FICA VAZIA
      NODO = aux->prox; // Tua função retorna um tipo nodo, então retornanto 0 ou 1 dará warnings,
                        // pra garantir, melhor retornar o nodo.
    }
    else if (ant == NULL && NODO->prox !=NULL) { // SE FOR O PRIMEIRO ELEMENTO E HOUVER MAIS
      NODO = NODO->prox;  // Aqui fiz um ajuste tbm, fica mais fácil
                          // reaponteirar aqui dentro e retornar o nodo encadeado
                          // já, pra não dar maiores confusões
    }
    else if (ant!=NULL && NODO->prox==NULL) { // SE FOR O ULTIMO ELEMENTO ANTES DO
      ant->prox=NULL;                         // FIM DA LISTA O PENULTIMO ELEMENTO APONTA PARA NULL
    }
    else if (ant!=NULL && NODO->prox!=NULL) { // SE FOR UM ELEMENTO DO MEIO DA LISTA
      ant->prox = aux->prox;
    }
  }
  else{ // SE NAO ACHOU O CODIGO
    printf("\nCódigo do Produto nao Encontrado!!!\n" );
  }
  return NODO;  // Comentário Doglas: Perceba que a lista atualizada precisa ser retornada,
                // para que caso você insira um novo nó ou exclua, as coisas estejam em ordem.
}

void imprime(tp_node *NODO){
  do {
    if (NODO == NULL) {
      printf("Lista Vaiza\n");
      break;
    }
    printf("Codigo: %d\n", NODO->info.cod);
    printf("Nome:   %s", NODO->info.nome);
    printf("Preço: %.2f\n\n", NODO->info.preco);
    NODO = NODO->prox;
  } while(NODO != NULL);
}

void main(){
  tp_node *lista = NULL;
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
        lista = push(lista);
        system("clear");
      break;
      case 2:
        system("clear");
        printf("POP:\n");
        lista = pop(lista);
        printf("\n\n");
      break;
      case 3:
        system("clear");
        printf("Dados: \n");
        imprime(lista);
        printf("\n\n");
      break;
      case 4:
        system("clear");
        lista = NULL;
        imprime(lista);
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
  free(lista);
}
