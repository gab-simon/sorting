#include "ordenacao.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

void getNome(char nome[])
{
	strncpy(nome, "Gabriel Simon Batista Ribeiro\nBruno Fuchs Santos da Silva", MAX_CHAR_NOME);
	nome[MAX_CHAR_NOME - 1] = '\0';
}

unsigned int getGRR()
{
	return 20210575;
}

unsigned int getGRR1()
{
	return 20211775;
}

unsigned int getGRR();
unsigned int getGRR1();

// Utilitarios

void preencherAleatorio(int vetor[], int numPos, int maxVal)
{
	for (int i = 0; i < numPos; i++)
		vetor[i] = rand() % maxVal;
}

void imprimirVetor(int vetor[], int tamVetor)
{
	printf("[");
	for (int i = 0; i < tamVetor; i++)
	{
		printf(" %d ", vetor[i]);
	}
	printf("]\n");
}

int troca(int vetor[], int a, int b)
{
	int x;

	x = vetor[a];
	vetor[a] = vetor[b];
	vetor[b] = x;

	return x;
}

int trocaBus(int vetor[], int x, int a, int b, int *numComparacoes)
{
	if (b < a)
		return b;

	*numComparacoes += 1;

	if (x >= vetor[b])
		return b;

	return trocaBus(vetor, x, a, b - 1, numComparacoes);
}

void trocaSub(int vetor[], int a, int b)
{
	int aux = vetor[a];

	vetor[a] = vetor[b];
	vetor[b] = aux;
}

// BuscaSequencial

int buscaSequencial(int vetor[], int tam, int valor, int *numComparacoes)
{
	if (0 > tam)
		return -1;

	numComparacoes += 1;
	if (vetor[tam] == valor)
		return tam;

	return buscaSequencial(vetor, tam - 1, valor, numComparacoes);
}

// BuscaBinaria

int buscaBinariaWow(int vetor[], int a, int b, int x, int *numComparacoes)
{
	if (a > b)
		return -1;

	int meio = floor((a + b) / 2);

	(*numComparacoes)++;

	if (x == vetor[meio])
		return meio;

	if (x < vetor[meio])
		return buscaBinariaWow(vetor, a, meio - 1, x, numComparacoes);

	return buscaBinariaWow(vetor, meio + 1, b, x, numComparacoes);
}

int buscaBinaria(int vetor[], int tam, int valor, int *numComparacoes)
{
	if (0 > tam)
		return -1;

	*numComparacoes += 1;

	return buscaBinariaWow(vetor, 0, tam - 1, valor, numComparacoes);
}

// InsertionSort

int insertion(int vetor[], int a, int b, int *numComparacoes)
{
	int i = b;

	int m = trocaBus(vetor, vetor[b], a, b - 1, numComparacoes);

	while (i > m + 1)
	{
		troca(vetor, i, i - 1);
		i--;
	}
	return *vetor;
}

int insertionSortWow(int vetor[], int a, int b, int *numComparacoes)
{
	if (a >= b)
		return -1;

	insertionSortWow(vetor, a, b - 1, numComparacoes);
	insertion(vetor, a, b, numComparacoes);

	return *numComparacoes;
}

int insertionSort(int vetor[], int tam)
{
	int numComparacoes = 0;
	return insertionSortWow(vetor, 0, tam - 1, &numComparacoes);
}

// SelectionSort

int buscaMenorIndice(int vetor[], int a, int b, int indiceM, int comparado, int *numComparacoes)
{
	if (a >= b)
		return indiceM;

	*numComparacoes += 1;

	if (vetor[indiceM] >= vetor[a])
		indiceM = a;

	return buscaMenorIndice(vetor, a + 1, b, indiceM, comparado, numComparacoes);
}

int selectionSortWow(int vetor[], int a, int b, int *numComparacoes)
{
	if (a == b)
		return *numComparacoes;

	int indiceMenor = a;

	indiceMenor = buscaMenorIndice(vetor, indiceMenor + 1, b, indiceMenor, indiceMenor, numComparacoes);
	trocaSub(vetor, indiceMenor, a);

	selectionSortWow(vetor, a + 1, b, numComparacoes);

	return *numComparacoes;
}

int selectionSort(int vetor[], int tam)
{
	int numComparacoes = 0;
	int m = 0;
	return selectionSortWow(vetor, m, tam, &numComparacoes);
}

// MergeSort

void copiar(int vetor[], int u[], int a, int b)
{
	int i = a;
	int j = 0;

	if (a >= b)
		return;

	while (i <= b)
	{
		vetor[i] = u[j];
		i++;
		j++;
	}
}

int merge(int vetor[], int u[], int a, int m, int b, int *numComparacoes)
{
	int k = 0;
	int i, j, p;

	if (a >= b)
	{
		return -1;
	}

	i = a;
	j = m + 1;

	while (k < b - a + 1)
	{
		(*numComparacoes)++;
		if (j > b || (i <= m && vetor[i] <= vetor[j]))
		{
			p = i;
			i = i + 1;
		}
		else
		{
			p = j;
			j = j + 1;
		}

		u[k] = vetor[p];
		k = k + 1;
	}
	copiar(vetor, u, a, b);
	return *numComparacoes;
}

int mergeSortWow(int vetor[], int u[], int a, int b, int *numComparacoes)
{
	if (a >= b)
		return -1;

	int m = (a + b) / 2;

	mergeSortWow(vetor, u, a, m, numComparacoes);
	mergeSortWow(vetor, u, m + 1, b, numComparacoes);

	merge(vetor, u, a, m, b, numComparacoes);
	return *numComparacoes;
}

int mergeSort(int vetor[], int tam)
{
	int numComparacoes = 0;
	int *u;
	u = malloc(tam * sizeof(int));

	numComparacoes = mergeSortWow(vetor, u, 0, tam - 1, &numComparacoes);

	free(u);
	u = NULL;

	return numComparacoes;
}

// QuickSort

int particionar(int vetor[], int a, int b, int *numComparacoes)
{
	int x = vetor[b]; // pivo
	int m = a;
	for (int i = a; i < b; i++)
	{
		*numComparacoes += 1;
		if (vetor[i] <= x)
		{
			trocaSub(vetor, m, i);
			m += 1;
		}
	}
	trocaSub(vetor, m, b);
	return m;
}

int quickSortWow(int vetor[], int a, int b, int *numComparacoes)
{
	if (a >= b)
		return 1;

	int m = particionar(vetor, a, b, numComparacoes);
	quickSortWow(vetor, a, m - 1, numComparacoes);
	quickSortWow(vetor, m + 1, b, numComparacoes);

	return *numComparacoes;
}

int quickSort(int vetor[], int tam)
{
	int numComparacoes = 0;
	return quickSortWow(vetor, 0, tam - 1, &numComparacoes);
}

// Testes exaustivos de ordenação

void AnaliseInsertionSort(int vetor[], int tam, int numComparacoes)
{
	double analise = 0;
	clock_t start, end;

	for (int i = 0; i < 15; i++)
	{
		preencherAleatorio(vetor, tam, 100);
		start = clock();
		numComparacoes += insertionSort(vetor, tam);
		end = clock();

		analise += ((double)end - start) / CLOCKS_PER_SEC;
	}

	numComparacoes = numComparacoes / 15;
	analise = analise / 15;

	printf("Comparações totais: %d\n", numComparacoes);
	printf("Tempo médio: %f \n", analise);
}

void AnaliseSelectionSort(int vetor[], int tam, int numComparacoes)
{
	double analise = 0;
	clock_t start, end;

	for (int i = 0; i < 15; i++)
	{
		preencherAleatorio(vetor, tam, 100);
		start = clock();
		numComparacoes += selectionSort(vetor, tam);
		end = clock();

		analise += ((double)end - start) / CLOCKS_PER_SEC;
	}

	numComparacoes = numComparacoes / 15;
	analise = analise / 15;

	printf("Comparações totais: %d\n", numComparacoes);
	printf("Tempo médio: %f \n", analise);
}

void AnaliseMergeSort(int vetor[], int tam, int numComparacoes)
{
	double analise = 0;
	clock_t start, end;

	for (int i = 0; i < 15; i++)
	{
		preencherAleatorio(vetor, tam, 100);
		start = clock();
		numComparacoes += mergeSort(vetor, tam);
		end = clock();

		analise += ((double)end - start) / CLOCKS_PER_SEC;
	}

	numComparacoes = numComparacoes / 15;
	analise = analise / 15;

	printf("Comparações totais: %d\n", numComparacoes);
	printf("Tempo médio: %f \n", analise);
}

void AnaliseQuickSort(int vetor[], int tam, int numComparacoes)
{
	double analise = 0;
	clock_t start, end;

	for (int i = 0; i < 15; i++)
	{
		preencherAleatorio(vetor, tam, 100);
		start = clock();
		numComparacoes += quickSort(vetor, tam);
		end = clock();

		analise += ((double)end - start) / CLOCKS_PER_SEC;
	}

	numComparacoes = numComparacoes / 100;
	analise = analise / 15;

	printf("Comparações totais: %d\n", numComparacoes);
	printf("Tempo médio: %f \n", analise);
}
