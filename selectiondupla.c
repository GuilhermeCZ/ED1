#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <time.h>
#define MAX 50

int autocod = MAX+1;
int vcods[10000], Ncod = 1;

typedef struct _produto{ //criação de uma struct tipo produto
  int cod;
  char nome[MAX];
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

int gcod() {
  srand(time(NULL));
  autocod = (rand()%10000) + 1;
  // autocod--;
  return autocod;
}


tp_nodo *push(tp_nodo *nodo, tp_lista *list){
  tp_nodo *new = (tp_nodo*) malloc(sizeof(tp_nodo));
  list->size++; // adiciona a tamano, ou quantidade de itens da lista

  if (list->size == 1){ // Caso for o primeiro elemento da lista
    new->prev = NULL;    // coloca a anterior sendo o NULL
    list->first = new;  // ele é o primeiro da lista
  } else {
    new->prev = list->last;   // colcoa o anterior como sendo o ultimo recebido
    nodo->next = new;         // o proximo sempre será o que esta sendo criado agora
  }
  list->last = new; // o ultmo elemento e sempre o que esta sendo inserido

  int codigo;
  char name[MAX];
  float price;

  if (!new) { // caso nao seja possivel alocar memoria ele sai da alocação
    printf("Sem memoria disponivel!\n");
    list->size--;
    exit(1);
  } else {
    int count = list->size;
    vcods[Ncod] = (gcod()); // verificação para nao repetir de numero
    codigo = vcods[Ncod];
    for (int i = 1; i <= count; i++) {
      if (codigo == vcods[i]) {
        // printf("achou %d\n", i);
        codigo = (gcod());
        i=1;
      }
      if (i == count) {
        // printf("passou\n");
        Ncod++;
      }
    }// --------------------- Fim da verificação
    // codigo = gcod();
    printf("Qual o Codigo do produto: %d\n", codigo);
    // printf("Qual o Codigo do produto: ");
    // scanf("%d", &codigo);
    printf("Qual o nome do produto: ");
    __fpurge(stdin);
    fgets(name, MAX, stdin);
    printf("Qual o valor do produto: ");
    scanf("%f", &price);

    new->info.cod = codigo;
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
      ant->prev = NULL; // o ponteiro para o nodo anterior se torna nulo
    }
    else if(foco != list->first && foco != list->last){//se estiver no meio da Lista
      ant->next = foco->next; // o anterior recebe o ponteiro do proximo
      foco = foco->next; // o foco se torna o proximo item da lista
      foco->prev = ant; // o anterior do proximo recebe o anterior
    }
    else if(foco != list->first && foco == list->last){//se for o ultimo da Lista
      ant->next = NULL; // o proximo do nodo anterior recebe nulo
      list->last = foco->prev; // o ultimo rebe o anterior do foco
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

tp_lista *troca(tp_nodo *foco, tp_nodo *menor, tp_nodo *proxM, tp_nodo *proxF, tp_nodo *antM, tp_nodo *antF) {
  printf("troca\n");
  foco->next = proxM;
  (foco->next != NULL)  ? (printf("Fnext: %d\n", foco->next->info.cod)) : (printf("Fnext: NULL\n"));
  menor->next = proxF;
  (menor->next != NULL) ? (printf("Mnext: %d\n", menor->next->info.cod)) : (printf("Mnext: NULL\n"));
  foco->prev = antM;
  (foco->prev != NULL)  ? (printf("Fprev: %d\n", foco->prev->info.cod)) : (printf("Fprev: NULL\n"));
  menor->prev = antF;
  (menor->prev != NULL) ? (printf("Mprev: %d\n", menor->prev->info.cod)) : (printf("Mprev: NULL\n"));
  // printf(" focoN: %d\n focoP: %d\n MenorN: %d\n MenorP: %d\n", foco->next->info.cod, foco->prev->info.cod,
  // menor->next->info.cod, menor->prev->info.cod);
}

tp_lista *reapontera(tp_nodo *foco, tp_nodo *menor, tp_nodo *proxM, tp_nodo *proxF, tp_nodo *antM, tp_nodo *antF) {
  printf("reapontera\n");
  (proxF  != NULL) ? (proxF->prev = menor) : (proxF  = NULL);
  (proxF  != NULL) ? (printf("Fnext->prev: %d\n", proxF->prev->info.cod)) : (printf("Fnext->prev: NULL\n"));
  (antF   != NULL) ? (antF->next = menor)  : (antF   = NULL);
  (antF   != NULL) ? (printf("Fprev->next: %d\n", antF->next->info.cod)) : (printf("Fprev->next: NULL\n"));
  (proxM  != NULL) ? (proxM->prev = foco)  : (proxM  = NULL);
  (proxM  != NULL) ? (printf("Mnext->prev: %d\n", proxM->prev->info.cod)) : (printf("Mnext->prev: NULL\n"));
  (antM   != NULL) ? (antM->next = foco)   : (antM   = NULL);
  (antM   != NULL) ? (printf("Mprev->next: %d\n", antM->next->info.cod)) : (printf("Mprev->next: NULL\n"));
}

tp_lista selectsort(tp_lista *list) {
  tp_nodo *foco, *percorre, *antM, *proxM, *ultimo;
  tp_nodo *antF, *proxF, *position, *menor, *lastM;
  int pos = 0, count = 0, pom = 0;

  count = list->size;
  pos = 1;
  pom = 1;
  do {
    for (position = list->first; position != NULL; position = position->next ) {
      foco = position;
      (foco->prev != NULL) ? (antF = foco->prev)  : (antF = NULL);
      (foco->next != NULL) ? (proxF = foco->next) : (proxF = NULL);
      if (foco->prev != NULL)  printf("Fprev: %d\n", antF->info.cod);
      printf(" F: %d\n", foco->info.cod);
      if (foco->next != NULL)  printf("Fnext: %d\n", proxF->info.cod);
      menor = position;
      for (percorre = position; percorre != NULL; percorre = percorre->next) {
        printf(" P: %d\n", percorre->info.cod);
        if (percorre->info.cod < foco->info.cod) {
          if (percorre->info.cod < menor->info.cod) {
            menor = percorre;
            lastM = menor;
            // pom = pos;
          }
          (menor->next != NULL) ? (proxM = menor->next) : (proxM = NULL);
          (menor->prev != NULL) ? (antM = menor->prev)  : (antM = NULL);
          if (menor->prev != NULL)  printf("Mprev: %d\n", antM->info.cod);
          printf(" M: %d\n", menor->info.cod);
          if (menor->next != NULL)  printf("Mnext: %d\n", proxM->info.cod);
        }
        printf("\n\n");
      }
      if (foco != menor && menor != NULL) {
        tp_nodo *auxF, *auxM;
        auxF = foco;
        auxM = menor;
        if (pom == 1) {
          list->first = menor;
        }
        if (pom == count) {
          list->last = foco;
        }
        if (foco->next->info.cod == menor->info.cod) { // se um está do lado do outro
          (menor->next != NULL) ? (foco->next = proxM) : (foco->next = NULL);
          (foco->prev  != NULL) ? (menor->prev = antF) : (menor->prev = NULL);
          (menor->next != NULL) ? (menor->next->prev = foco) : (NULL);
          (foco->prev  != NULL) ? (foco->prev->next = menor) : (NULL);
          menor->next = foco;
          foco->prev = menor;
          // getchar();
          goto pass;
        }
        reapontera(foco, menor, proxM, proxF, antM, antF);
        troca(foco, menor, proxM, proxF, antM, antF);
        // getchar();
      }
      pass: ;
      pom++;
      menor = NULL;
    }
    pos++;
  } while(pos <= count+1);
}

void insetsort(tp_lista *list) {

  tp_nodo *foco, *i, *proximo, *ultimo;
  int cod, cont;

  for (foco = list->first->next; foco != NULL; foco=proximo) {
    proximo = foco->next;
    cod  = foco->info.cod;
    i = foco->prev;
    cont = 0;
    ultimo = NULL;
    while (i != NULL && i->info.cod > cod) { // percorre os valores da lista
      ultimo = i; // sempre armazena o valor do anterior
      i = i->prev;// faz ele ir voltanto
      cont++; // a contagem vai aumentando
    }
    if (cont >= 1) {
      if (foco->next != NULL) {
        foco->next->prev = foco->prev;
      }
      if (foco->prev != NULL) {
        foco->prev->next = foco->next;
      }
      if (i == NULL) { // Percorreu todos e nao achou menor que ele, insere no inicio da lista
        ultimo->prev = foco;
        list->first = foco;
        foco->next = ultimo;
        foco->prev = i;
      } else {
        foco->prev = i;
        foco->next = i->next;
        i->next = foco;
        foco->next->prev = foco;
      }
    }
  }
}

void bubblesort(tp_lista *list) {

    int tam = list->size;
    tp_nodo *nodo1, *foco;
    printf("%d\n", tam);
    for (int i = 0; i < tam; i++) {
        nodo1 = list->first;
        foco = list->first->next;
        for (int j = 0; j < tam; j++) {
          if(nodo1->info.cod > foco->info.cod) {
              foco->prev = nodo1->prev;
              nodo1->prev = foco;
              nodo1->next = foco->next;
              foco->next = nodo1;
              if (foco->prev != NULL) { // se ouver algo antes precisa reaponterar para o foco
                foco->prev->next = foco;
              }else{
                foco->prev = NULL;
              }
              if (nodo1->next != NULL) {
                nodo1->next->prev = nodo1;
              } else {
                nodo1->next = NULL;
              }
          }
          foco = nodo1->next;
          nodo1 = foco->next;
        }
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
            " 4 - Ordenar por selection sort\n"
            " 5 - Ordenar por insertion sort\n"
            " 6 - Ordenar por Bubble sort\n"
            " 7 - Limpa dados\n"
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
        printf("Ordenado por Selection Sort:\n\n");
        selectsort(lista);
        // imprime(nodo, lista);
      break;
      case 5:
        system("clear");
        printf("Ordenado por Insertion Sort:\n\n");
        insetsort(lista);
        imprime(nodo, lista);
      break;
      case 6:
        system("clear");
        printf("Ordenado por Bubble Sort:\n\n");
        bubblesort(lista);
        imprime(nodo, lista);
      break;
      case 7:
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
