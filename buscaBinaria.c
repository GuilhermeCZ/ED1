#include <stdio.h>
#include <stdlib.h>
#define MAX 10

// x => valor buscar | v[] => vetor ordenado | e => limite inferior (esquerda) | d => limite superior (direita)
int PesquisaBinaria (int x, int v[], int e, int d) {
 int meio = (e + d)/2;
 if (v[meio] == x) { return meio; } // foi encontrado o valor procurado
 if (e >= d){ return -1; } // não encontrado
 else
    if (v[meio] < x){
      return PesquisaBinaria(x, v, meio+1, d); // chama a si mesma caso o valor esteja abaixo do valor do meio
    }
    else {
      return PesquisaBinaria(x, v, e, meio-1); // chama a si mesma caso o valor esteja acima do valor do meio
    }
}

void bubble(int a, int *b) {
  for (int i = a-1; i >=1 ; i--) {
    for (int j = 0; j < i; j++) {
      if (b[j] > b[j+1]) {
        int tmp = b[j];
        b[j] = b[j+1];
        b[j+1] = tmp;
      }
    }
  }
}

int main() {
  int vetor[MAX], n=0, i=0, result=0;

  for (i = 0; i < MAX; i++) {
    vetor[i] = 0;
  }
  for (i = 0; i < MAX; i++) {
    printf("Posição %d: ", i);
    scanf ("%d", &vetor[i]);

  }
  bubble(MAX, vetor);
  printf("Ordenado: \n");
  for (i = 0; i < MAX; i++) {
    printf("Posição %d: %d\n", i, vetor[i]);
  }
  printf("Qual numero deseja buscar? ");
  scanf("%d", &n);

  ((result = PesquisaBinaria(n, vetor, 0, MAX)) != -1) ? (printf("%d\n", result)) : (printf("Não foi encontrado\n"));
  return 0;
}
