#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
#define TAM 50

int gcod = 0; // codigo dos produtos é gerado automaticamente

typedef struct _produto{ //criação de uma struct tipo produto
  int cod;
  char nome[TAM];
  float preco;
}tp_produto;

typedef struct _nodo {  // cria a struct de posicionamento e acesso
  tp_produto info;      // ponteiro que contem todas as informações do produto
  struct _nodo *next;   // ponteiro para o proximo elemento
  struct _nodo *prev;   // ponteiro para o elemento anterior
}tp_nodo;

typedef struct _lista { // Struct para coordenar o incio e final da lista
  int size;             // mantem o tamanho da lista;
  tp_nodo *first;       // endereço do primeiro elemento
  tp_nodo *last;        // endereço do ultimo elemento
}tp_lista;

tp_nodo *push(tp_nodo *nodo, tp_lista *list){
  tp_nodo *new = (tp_nodo*) malloc(sizeof(tp_nodo));
  list->size++; // adiciona a tamano, ou quantidade de itens da lista

  if (list->size == 1){ // Caso for o primeiro elemento da lista
    new->prev = new;    // coloca a anterior sendo o NULL
    list->first = new;  // ele é o primeiro da lista
  } else {
    list->last->next = new;   // o proximo sempre será o que esta sendo criado agora
    new->prev = list->last;   // colcoa o anterior como sendo o ultimo recebido
    new->next = list->first;  // o novo->proximo aponta para o primeiro da lista
  }
  list->last = new; // o ultmo elemento e sempre o que esta sendo inserido

  int codigo;
  char name[TAM];
  float price;

  if (!new) { // caso nao seja possivel alocar memoria ele sai da alocação
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

    return new;
  }
}

tp_lista *pop(tp_lista *list){
    int pcode;

  if(list->size == 0){ //se a quantidade total de itens for 0 nao existe nenhum item cadastrado
    printf("Lista Vazia!\n");
    return list;
  }

  tp_nodo *foco = list->first;  // variavel auxiliar
  tp_nodo *ant = NULL;          // varial para ser o anterior
  printf("\nDigite o codigo do produto a ser apagado: ");
  scanf("%d", &pcode);

  while (pcode != foco->info.cod) {
    if(foco->next == NULL){
      goto pop; // continua para pop
    }
    else{
      ant=foco; // para avançãr na lista
      foco=foco->next; // foco recebe o proximo
    }
  }

  pop: ;
  if(pcode == foco->info.cod){//se achou o produto que eu quero apagar
    if(foco == list->first && foco == list->last){//se houver apenas um produto
      list->first = NULL; // zera o primeiro lista
      list->last = NULL; // zera o ultimo dalsita
    }
    else if(foco == list->first && foco != list->last){//se for o first da Lista
      list->first = foco->next; // o primeiro se torna o proximo
      ant = foco->next; // o anterior se torna o proximo
      ant->prev = list->last; // o ponteiro para o nodo anterior se torna nulo
      list->last->next = ant;
    }
    else if(foco != list->first && foco != list->last){//se estiver no meio da Lista
      ant->next = foco->next; // o anterior recebe o ponteiro do proximo
      foco = foco->next; // o foco se torna o proximo item da lista
      foco->prev = ant; // o anterior do proximo recebe o anterior
    }
    else if(foco != list->first && foco == list->last){//se for o ultimo da Lista
      ant->next = list->first; // o proximo do nodo anterior recebe o primeiro
      list->last = ant; // o ultimo rebe o anterior do foco
      list->last->next = list->first; // o proximo do ultimo recebe o primeiro
    }
    else if(list->size == 1){
      list->last = list->first;
      foco->prev = foco;
      foco->next = foco;
    }

    list->size--;//diminui a quantidade de itens na lista em 1
  }
  else{ //se nao achou o produto
    printf("\nproduto não encontrado!\n");
    return list;
  }

}

tp_nodo *imprime(tp_nodo *nodo, tp_lista *list){
  int i;
  tp_nodo *focus;
  focus = list->first;

  if (list->size == 0) {
    printf("Lista vazia\n");
  }
  for (i = 1; i <= list->size; i++){
    printf("Código do produto: %d\n", focus->info.cod);
    printf("Nome do produto: %s", focus->info.nome);
    printf("Preço do produto: %.2f\n\n", focus->info.preco);
    focus = focus->next;
  }
}

tp_lista *clear(tp_lista *list){
  list->size   = 0;
  list->first  = NULL;
  list->last   = NULL;
  return list;
}

void main(){
  tp_nodo   *nodo = NULL;
  tp_lista  *lista;
  clear(lista);
  system("clear");
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
        nodo = push(nodo, lista);
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
        imprime(nodo, lista);
        printf("\n\n");
      break;
      case 4:
        system("clear");
        nodo = NULL;
        lista = clear(lista);
        imprime(nodo, lista);
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
  free(nodo);
}
