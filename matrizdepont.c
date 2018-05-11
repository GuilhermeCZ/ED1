#include <stdio.h>
#include <stdlib.h>

int main(){
  int i, k;
  float **mat;
  float m=5, n=5;

  mat=(float**) malloc( m * sizeof(float*));
  for (i=0; i <= m; i++){
    mat[i] = (float**) malloc ( n * sizeof(float*));
    printf("mat[%.lf]\n", mat[i]);
    for (k = 0; k <= n; k++) {
      printf("mat[%p]\n", mat[k]);
    }
    printf("\n");
  }
  return 0;
}
