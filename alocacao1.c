#include <stdio.h>
#include <stdlib.h>

int main(){
	int a;
	int *p;

	printf("Digite o tamanho de alocação que deseja: ");
	scanf("%d", &a);

	p = (int *)calloc(a, (sizeof(int)));

	if(p){
		printf("Memoria alocada de tamanho %d\n", (a*4));
		free(p);
	}
	else{
		printf("Erro de memoria\n");
	}

	return 0;
}