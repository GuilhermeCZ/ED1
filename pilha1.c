#include <stdio.h>
#include <stdlib.h>
#define  MAX 5

typedef struct _pilha{
  int info[MAX];
  int topo;
}tp_pilha;

void push(*p int k){
  int val;
  printf("Adicionar a posição %d o valor:", p->topo);
  scanf("%d", val);
  p->topo++;
  p->info[p->topo];
}

void pop(*p){
  p->topo--;
}

void display(){
  int i;
  for (i=0; i < MAX; i++){
    printf("Valor da posição %d tem o valor: %d\n", p->info[i]);
  }
}

int main(){
  int i, j, op = 0;
  void *p;
  _pilha.topo = -1;
  p = (int*) malloc(MAX, (sizeof (int)));
  while (i){
    printf("O que deseja fazer:\n 1 - Adcionar\n 2 - Remover\n 3 - Display\n 4 - Sair");
    scanf("%d", &op);
    if (op == 1) {
      if(*p->topo == 5){
        printf("p Cheia, precisa esvasiar\n");
      } else {
        push(*p);
      }
    } else if (op == 2){
      pop(*p);
    } else if (op == 3) {
      display();
    } else if (op == 4) {
      i == 0;
    } else {
      printf("Opção errada, tente novamente\n");
    }
  }
}
