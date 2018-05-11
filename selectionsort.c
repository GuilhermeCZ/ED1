#include <stdio.h>
#include <stdlib.h>
#define MAX 15

void selection(int a, int*v) {
  int temp, aux;
  for (int i = 0; i < a-1; i++) {
    aux = i; //atribui a comparação de inicio do vetor
    for (int j = (i+1); j < a; j++) {
      if (v[j] < v[aux]) {
        aux = j; // caso o valor encontrado seja menor que o primeiro, o aux recebe o endereço do novo menor valor
      }
    }
    if (i != aux) { // se as posições sao diferentes ele pode efetuar a troca
      temp = v[i];
      v[i] = v[aux];
      v[aux] = temp;
    }
    printf("----\n");
    for (int k = 0; k < a; k++) {
      printf("%d", v[k]);
      printf("\n");
    }
  }
}

int main() {
  int i = MAX;
  int v[MAX];
  for (int k = 0; k < MAX; ++k)	{
		v[k] =(rand()%MAX);
	}
  selection(i, v);
  printf("Vetor ordenado:\n");
  for (int j = 0; j < MAX; j++) {
    printf("%d", v[j]);
    printf("\n");
  }
  return 0;
}
