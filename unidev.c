#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int addv1(*v){
  int i;
  printf("quantos valores deseja adcionar a V1? ");
  scanf("%d", &i);

  for (int j; j < i; j++) {
      scanf("%d", (*v+j));
  }

}

int addv2(*v){
  int i;
  printf("quantos valores deseja adcionar a V2? ");
  scanf("%d", &i);

  for (int j; j < i; j++) {
      scanf("%d", (*v+j));
  }

}

int* uniao(int *v1, int n1, int *v2, int n2){
  int temp1, temp2=0;
  int *v3 = (int*)malloc((n1+n2)*sizeof(int));

  for(temp1=0; temp1<n1; temp1++){
    *(v3+temp1) = *(v1+temp1);
  }
  for (temp1=n1; temp1 < (n1+n2); temp1++) {
    *(v3+temp1) = *(v1+temp2);
    temp2++;
  }
}

int main(){
  int *v1, *v2, *v3;
  int i, j, k;




}
