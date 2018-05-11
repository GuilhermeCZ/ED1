#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 15

void selection(int a, int*v) {
  int aux, i, j;
  for (i = 0; i < a; i++) {
    aux = v[i]; // atribui aux para comparação de inicio do vetor
    j = i-1; // j recebe o anterior, para poder comparar se é menor
    while ((j >= 0) && aux < v[j]) { // enquanto j for maior/igual que 0 e o aux for menor que o valor em questão;
      v[j+1] = v[j]; // o proximo recebe o maior, o passando pra frente e trazendo o menor pra trás
      j = j-1; // j vai voltando para refazer as comparações e passar os valores pra frente
    }
    v[j+1] = aux; // a posição v[j] recebe o valor de v[i]

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
  srand(time(NULL));
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
