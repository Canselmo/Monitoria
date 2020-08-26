#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

typedef struct ArvoreBinaria
{
	int valor;
	struct ArvoreBinaria* esq;
	struct ArvoreBinaria* dir;
}No;

No* NoRaiz = NULL;

void inserir(No** NoRaiz, int valor);
int menu();
void preOrdem(No* NoRaiz);
void emOrdem(No* NoRaiz);
void posOrdem(No* NoRaiz);

int main(void) {
	setlocale(LC_ALL, "Portuguese");
	while (menu() == 1);
	return 0;
}

int menu() {
	int op = 0;
	int valor;
	system("cls");
	printf("--------------- Menu de opções ---------------");
	printf("\n1-Inserir elemento");
	printf("\n2-Imprimir elementos pré-ordem");
	printf("\n3-Imprimir elementos em ordem");
	printf("\n4-Imprimir elementos pós-ordem");
	printf("\n0-Sair");
	printf("\n----------------------------------------------");
	printf("\nOpção: "); scanf("%d", &op);
	switch (op) {
	case 0: {
		return 0;
	}
	case 1: {
		printf("\nValor: "); scanf("%d", &valor);
		inserir(&NoRaiz, valor);
		printf("\nElemento inserido com sucesso \n");
		system("pause");
		break;
	}
	case 2: {
		preOrdem(NoRaiz);
		printf("\n");
		system("pause");
		break;
	}
	case 3: {

		break;
	}
	case 4: {
		break;
	}
	}
	printf("retornado1");
	return 1;
}

void inserir(No** NoRaiz, int valor)
{
	if (*NoRaiz == NULL)
	{
		*NoRaiz = (No*)malloc(sizeof(No));
		(*NoRaiz)->esq = NULL;
		(*NoRaiz)->dir = NULL;
		(*NoRaiz)->valor = valor;
	}
	else
	{
		if (valor < ((*NoRaiz)->valor))
		{
			inserir(&((*NoRaiz)->esq), valor);
		}
		else
		{
			inserir(&((*NoRaiz)->dir), valor);
		}
	}
}
void preOrdem(No* NoRaiz) {
	if (NoRaiz == NULL) return;
	printf("- %d ", NoRaiz->valor);
	preOrdem(NoRaiz->esq);
	preOrdem(NoRaiz->dir);
}
