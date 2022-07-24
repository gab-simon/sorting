#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "ordenacao.h"

int main(){
	srand(time(NULL));
	char nome[MAX_CHAR_NOME];
	int idxBusca;
	int numComp;

	long int tamVetor = 1000;
	int* vetor = malloc(tamVetor * sizeof(int));
	if(vetor == NULL){
		printf("Falha fatal. Impossível alocar memoria.");
		return 1;
	}
	preencherAleatorio(vetor, tamVetor, 10);
	

	getNome(nome);
	printf("Trabalho de %s\n", nome);
	printf("GRR %u\n", getGRR());
	printf("Todos os algoritmos foram baseados nos slides passados em aula!\n\n");
	
	clock_t start, end;
    double total;
	start = clock();
	
		numComp = insertionSort(vetor, tamVetor);
		printf("Comparações insertionSort = [%d]\n\n", numComp);
		numComp = selectionSort(vetor, tamVetor);
		printf("Comparações selectionSort = [%d]\n\n", numComp);
		numComp = mergeSort(vetor, tamVetor);
		printf("Comparações mergeSort = [%d]\n\n", numComp);
		numComp = quickSort(vetor, tamVetor);
		printf("Comparações quickSort = [%d]\n\n", numComp);
		
		imprimirVetor(vetor, tamVetor);
		printf("\n");

	end = clock();
	total = ((double)end - start)/CLOCKS_PER_SEC;
	printf("Tempo total: %f \n", total);

	idxBusca = buscaSequencial(vetor, tamVetor, 5, &numComp);
	printf("buscaSequencial Índice: %d Número de Comparações %d \n", idxBusca, numComp);
	printf("\n");

	idxBusca = buscaBinaria(vetor, tamVetor, 500, &numComp);
	printf("buscaSequencial Índice: %d Número de Comparações %d \n", idxBusca, numComp);
	printf("\n");

	
	free(vetor);
	vetor = NULL;

	return 0;
}
