#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include <math.h>
#define  MAX 5
#define TAM 50


typedef struct _pilha{
  int info[MAX];
  pilha *prox;
}pilha;

int contador_pilha;
int pilhamax = contador_pilha;

pilha *topo;

bool pilha_const(){
  topo=NULL;
  contador_pilha = 0;
}

bool pilha_empty(){
  if(topo==NULL) true;
  else false;
}

int pilha_size(){
  return contador_pilha;
}

bool push(int *val){
  pilha *newcel = (pilha*)malloc(sizeof(pilha));
  if (newcel==NULL) {
    return false;
  } else {
    if (pilha_full()) {
      printf("tente de novo, foi preciso realocar mais memoria\n");
      return false;
    } else {
      scanf("%d\n", &newcel->info);
      newcel->prox = topo;
      topo = newcel;
      contador_pilha++;
      return true;
    }
  }
}
bool pop(int &val){
  pilha *temp
  if (pilha_empty()) {
    return false;
  } else {
    val = topo->info;
    temp = topo;
    topo = topo->prox;

    temp->prox=NULL

    free(temp);
    contador_pilha--;
    return true;
  }
}

bool pilha_get(int &val){
  if (pilha_empty()) {
    return false;
  } else {
    val=topo->info;
  }
}

int main() {
  int i, val;

  do {
    printf("Qual opção deseja:\n 1 - Adcionar\n 2 - Remover\n 3 - Ver Pilha\n 4 - Tamanho da Pilha\n");
    printf(" 5 - sair\n");
    scanf("%d\n", &i);
    switch (i) {
      case 1:
        printf("Qual valor deseja inserir?\n");
        scanf("%d\n", val);
        push();
      case 2:
        printf("Removido o valor\n");
        pop();
      case 3:
        pilha_get();
      case 4:
        printf("O tamanho atualda pilha é: %d\n", pilha_size());
      case 5:
        printf("Você saiu\n");
        free(pilha);
      default:
        return 0;
    }
  } while(i!=5);
  return 0;
}
