#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "ordenacao.h"

int main()
{
	/* Cria uma nova seed de aleatorização */
	srand(time(NULL));

	int idxBusca;
	int buscas;
	int numComp = 0;
	char nameColaborators[MAX_CHAR_NOME];
	long int tamVetor;
	long int tamAleatorio;

	getNome(nameColaborators);
	printf("Trabalho de %s\n", nameColaborators);
	printf("GRR %u - %u \n", getGRR(), getGRR1());

	printf("\nTamanho para o vetor: ");
	scanf("%ld", &tamVetor);
	int *vetor = malloc(tamVetor * sizeof(long int));

	if (vetor == NULL)
	{
		printf("Falha fatal. Impossível alocar memoria.");
		return 1;
	}

	printf("\nAmplitude do vetor: ");
	scanf("%ld", &tamAleatorio);
	preencherAleatorio(vetor, tamVetor, tamAleatorio);

	printf("________________________________________________\n\n");

	clock_t start, end;
	double total;
	start = clock();

	numComp = insertionSort(vetor, tamVetor);
	printf("Comparações do InsertionSort = [%d]\n", numComp);

	preencherAleatorio(vetor, tamVetor, tamAleatorio);
	numComp = selectionSort(vetor, tamVetor);
	printf("Comparações do SelectionSort = [%d]\n", numComp);

	preencherAleatorio(vetor, tamVetor, tamAleatorio);
	numComp = mergeSort(vetor, tamVetor);
	printf("Comparações do MergeSort = [%d]\n", numComp);

	preencherAleatorio(vetor, tamVetor, tamAleatorio);
	numComp = quickSort(vetor, tamVetor);
	printf("Comparações do QuickSort = [%d]\n\n", numComp);

	end = clock();
	total = ((double)end - start) / CLOCKS_PER_SEC;

	printf("Tempo total: %f \n", total);

	printf("______________________TESTES____________________\n");
	printf("Teste InsertionSort: \n");
	AnaliseInsertionSort(vetor, tamVetor, 0);
	printf("\n");
	printf("Teste SelectionSort: \n");
	AnaliseSelectionSort(vetor, tamVetor, 0);
	printf("\n");
	printf("Teste MergeSort: \n");
	AnaliseMergeSort(vetor, tamVetor, 0);
	printf("\n");
	printf("Teste QuickSort: \n");
	AnaliseQuickSort(vetor, tamVetor, 0);
	printf("________________________________________________\n");

	preencherAleatorio(vetor, tamVetor, tamAleatorio);
	numComp = quickSort(vetor, tamVetor);
	imprimirVetor(vetor, tamVetor);

	printf("\nBuscar elemento: ");
	scanf("%d", &idxBusca);

	buscas = 0;
	numComp = 0;
	buscas = buscaBinaria(vetor, tamVetor, idxBusca, &numComp);
	printf("Busca Binaria Índice: [%d] Número de Comparações: [%d] \n", buscas, numComp);

	buscas = 0;
	numComp = 0;
	buscas = buscaSequencial(vetor, tamVetor, idxBusca, &numComp);
	printf("Busca Sequencial Índice: [%d] Número de Comparações: [%d] \n", buscas, numComp);

	free(vetor);
	vetor = NULL;

	return 0;
}
