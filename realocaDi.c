#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
int i=1, x=5, j=0, k=0, a=5;
int *p, *aux;

  p = (int *)calloc(x, (sizeof(int)));

  do{
    printf("Digite um numero para alocar: ");
    scanf("%d", &j);
    if (j==0) {
      printf("Saiu do programa\n");
      i=0;
    }
    else {
      if(k>=x){
        aux=(int *)realloc(p, (x+a)*sizeof(int));
        if(aux){
          p = aux;
          x = x+a;
          printf("realocado\n");
          free(aux);
        }
        else{
          printf("memoria insuficiente\n");
        }
        *(p+k) = j;
      }
      else{
        *(p+k) = j;
      }
      k++;
    }
    for (i = 0; i < x; i++) {
      printf("posição: %d - Conteudo: %d\n", i,*(p+i));
    }
  }while(j!=0);

  free(p);
	return 0;
}
