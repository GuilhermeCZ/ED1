#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

typedef struct {
	char nome[50];
	char endereco[100];
	int matricula;
}estudante;

int main() {
	int a;
	char j[100], k[50];
	estudante *p;

	printf("Digite o tamanho de alocação que deseja: ");
	scanf("%d", &a);

	p = (estudante *)malloc((a*sizeof(estudante)));

	for(int y=0; y < a; y++){
		printf("Digite o nome do estudante\n");
		getchar();
		fgets(j,50, stdin);
		strcpy((p+y)->nome, j);

		printf("Digite o endereço do estudante\n");
		__fpurge(stdin);
		fgets(j,100, stdin);
		strcpy((p+y)->endereco, j);

		printf("Digite a matricula do estudante\n");
		__fpurge(stdin);
		scanf("%d", &(p+y)->matricula);
	}
	puts("\n");
	for (int i = 0; i < a; i++){
		printf("Nome do estudante: %s", (p+i)->nome);
		printf("Endereço do estudante: %s", (p+i)->endereco);
		printf("Matricula do estudante: %d\n\n", (p+i)->matricula);
	}
	free(p);
	return 0;
}
