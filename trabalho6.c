#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#define TAM 50

typedef struct _nodo{
  int valor;
  struct _nodo *proximo; //amazena o endereço da proxima struct
  struct _nodo *anterior; //armazena o endereço da estrutura anterior
}tp_nodo;

typedef struct _lista{
  int nItens;
  tp_nodo *primeiro; //endereço da primeira estrutura cadastrada
  tp_nodo *ultimo; //endereço da ultima estrutura cadastrada
}tp_lista;

tp_lista *initial(tp_lista *list){
  list->primeiro = NULL;
  list->ultimo = NULL;
  list->nItens = 0;

  return list;
}


tp_lista *push(tp_lista *list){
  tp_nodo *novo= (tp_nodo *) malloc(sizeof(tp_nodo));

  list->nItens++; //toda vez que for inserir um produto, aumenta a quantidade total de itens na Lista
  if(list->nItens == 1){ //se for o primeiro item da lista
    list->primeiro = novo; //ele é o primeiro da lista
    novo->anterior = NULL; //o anterior a ele é NULL
  }
  else{ //se ele não for o primeiro da lista
    novo->anterior = list->ultimo; //o ultimo inserido é o anterior a ele
    list->ultimo->proximo = novo; //o proximo do ultimo produto inserido é o novo produto
  }

  list->ultimo = novo; //o novo produto é sempre o ultimo
  novo->proximo = NULL; //o proximo é cadastrado como NULL,

  int a;

  printf("\nInsercao de novo nodo.\nDigite o VALOR do nodo:  ");
  scanf("%d", &a);

  //passando os valores lidos para o nodo
  novo->valor = a;

  return list;
}

//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------

tp_lista *pop(tp_lista *l){
  int code;

  if(l->nItens == 0){ //se a quantidade total de itens for 0 nao existe nenhum item cadastrado
    printf("LISTA VAZIA!\n");
    return l;
  }

  tp_nodo *foco = l->primeiro; //variavel auxiliar
  tp_nodo *AUX = NULL;
  printf("\nDigite valor referente ao nodo que será apagado: ");
  scanf("%d", &code);

  while (code != foco->valor) {
    if(foco->proximo == NULL){
      goto apaga;
    }
    else{
      AUX=foco;
      foco=foco->proximo;
    }
  }

  apaga: ;
  if(code == foco->valor){//se achou o nodo que eu quero apagar
    if(foco == l->primeiro && foco == l->ultimo){//se houver apenas um produto
      l->primeiro = NULL;
      l->ultimo = NULL;
    }
    else if(foco == l->primeiro && foco != l->ultimo){//se for o primeiro da Lista
      l->primeiro = foco->proximo;
      AUX = foco->proximo;
      AUX->anterior = NULL;
    }
    else if(foco != l->primeiro && foco != l->ultimo){//se estiver no meio da Lista
      AUX->proximo = foco->proximo;
      foco = foco->proximo;
      foco->anterior = AUX;
    }
    else if(foco != l->primeiro && foco == l->ultimo){//se for o ultimo da Lista
      AUX->proximo = NULL;
      l->ultimo = foco->anterior;
    }

    l->nItens--;//diminui a quantidade de itens na lista em 1
  }
  else{ //se nao achou o produto
    printf("Valor não encontrado!\nRetornando ao menu principal!");
    return l;
  }

}

//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------

void show(tp_lista *l){
  tp_nodo *foco;
  foco = l->primeiro;
  int i;

  system("clear");
  printf("Lista:\n");
  for(i=1; i<=l->nItens; i++){
    if (l->primeiro == NULL) {
      printf("Lista Vazia\n");
      break;
    }
    printf("%d\n", foco->valor);
    foco=foco->proximo;
  }
}

//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------
/*
tp_lista *InsertSort(tp_lista *l){
  tp_nodo *aux, foco, anteriorFOCO, verif;


  foco = l->primeiro;

  do {

    if(foco->anterior == NULL){ //primeiro da lista, mantém a posição
    }

    else if(foco->anterior)

  }while(foco != NULL);
}
*/
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------

tp_lista *SelectionSort(tp_lista *l){
  tp_nodo *foco, menor, position, AUX, teste;
  int tamanho = 1, i;

  AUX = NULL;
  position = l->primeiro;
///encontrando menor item
  do{
    for(i = 1; i < tamanho; i++){
      position = position->proximo;
    }
    teste = position;

    for(position; position != NULL; position = position->proximo){
        foco = position;
        if(foco->anterior == NULL){
          menor = foco;
          goto next;
        }
        if(foco->valor < menor->valor){
          menor = foco;
        }

        next: ;
    }


///-------removendo item da lista
    foco = l->primeiro;
    while (menor->valor != foco->valor) {
      if(foco->proximo == NULL){
        goto apaga;
      }
      else{
        AUX=foco;
        foco=foco->proximo;
      }
    }

    apaga: ;
    if(code == foco->valor){//se achou o nodo que eu quero apagar
      if(foco == l->primeiro && foco == l->ultimo){//se houver apenas um produto
        l->primeiro = NULL;
        l->ultimo = NULL;
      }
      else if(foco == l->primeiro && foco != l->ultimo){//se for o primeiro da Lista
        l->primeiro = foco->proximo;
        AUX = foco->proximo;
        AUX->anterior = NULL;
      }
      else if(foco != l->primeiro && foco != l->ultimo){//se estiver no meio da Lista
        AUX->proximo = foco->proximo;
        foco = foco->proximo;
        foco->anterior = AUX;
      }
      else if(foco != l->primeiro && foco == l->ultimo){//se for o ultimo da Lista
        AUX->proximo = NULL;
        l->ultimo = foco->anterior;
      }

///-----inserindo item na posição
      if(tamanho = 1){
        menor->anterior = NULL;
        menor->proximo = l->primeiro;
        menor->proximo->anterior = menor
        l->primeiro = menor;
      }
      else if(tamanho = l->nItens){
        l->ultimo->proximo = menor;
        menor->anterior = l->ultimo;
        meno->proximo = NULL;
        l->ultimo = menor;
      }
      else{
        menor->anterior = teste->anterior;
        menor->anterior->proximo = menor;
        menor->proximo = teste;
        teste->anterior = menor;
      }

    if (tamanho < l->nItens)
      tamanho++;
  }while(tamanho!=l-nItens);

  return (l);
}
//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------



void main() {
  tp_lista *l = (tp_lista *) malloc(sizeof(tp_lista));
  l = initial(l);

  int x;

  do {
    printf("Escolha uma Opcao:\n"
           "1 - Inserir elemento\n" //push
           "2 - Remover elemento\n" //pop
           "3 - Imprimir Lista\n" //show
           "4 - Ordenar via Insertion Sort\n"
           "5 - Ordenar via Selection Sort.\n"
           "6 - Ordenar via Quick Sort ou Merge Sort\n"
           "7 - Remover TODOS os elementos\n" //initial
           "0 - Sair\n"
           "Opcao: ");
    scanf("%d", &x);


    switch (x) {
      case 1:  //push
        l = push(l);
        break;

      case 2: //pop
        l=pop(l);
        break;

      case 3: //show
        show(l);
        break;
/*
      case 4:  //InsertSort
        l = InsertSort(l);
        break;
*/
      case 5:  //SelectSort
        l = SelectSort(l);
        break;
/*
      case 6: //Quick
        l = Quick(l);
        break;
*/
      case 7: //initial
        l = initial(l);
        break;

      case 0: //exit
        printf("O programa sera encerrado.\n" );
        break;

      default:
        printf("Opcao invalida\n");
        break;
    }
    printf("\n\n\n");
    getchar();
  } while(x!=0);
 free(l);
}
