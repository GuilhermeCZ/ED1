#include <stdio.h>
#include <stdlib.h>
#define MAX 15

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
  int i = MAX;
  int v[MAX];
  for (int k = 0; k < MAX; ++k)	{
		v[k] =(rand()%MAX);
	}
  bubble(i, v);
  printf("Vetor ordenado:\n");
  for (int j = 0; j < i; j++) {
    printf("%d", v[j]);
    printf("\n");
  }
  return 0;
}
