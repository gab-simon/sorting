#include "ordenacao.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

void getNome(char nome[]){
	strncpy(nome, "Gabriel Simon Batista Ribeiro", MAX_CHAR_NOME);
	nome[MAX_CHAR_NOME-1] = '\0';
}

unsigned int getGRR(){
	return 20210575;
}

unsigned int getGRR();

void preencherAleatorio(int vetor[], int numPos, int maxVal){
	for(int i = 0; i < numPos; i++)
		vetor[i] = rand()%maxVal;
}

void imprimirVetor(int vetor[], int tamVetor){
	printf("[");
	for(int i=0; i < tamVetor; i++){
		printf(" %d ", vetor[i]);
	}
	printf("]\n");
}

int troca(int vetor[], int a, int b) {
	int x;

	x = vetor[a];
	vetor[a] = vetor[b];
	vetor[b] = x;

	return x;
}

void trocaSub(int vetor[], int a, int b) {
	int aux = vetor[a];
	
	vetor[a] = vetor[b];
	vetor[b] = aux;
}

int buscaSequencial(int vetor[], int tam, int valor, int* numComparacoes){
	if (0 > tam)
		return -1;

	numComparacoes += 1;
	if (vetor[tam] == valor)
		return tam;
	
	return buscaSequencial(vetor, tam-1, valor, numComparacoes);
}

int buscaBinaria2(int vetor[], int a, int b, int x,  int* numComparacoes){
	if (a > b)
		return -1;

	int meio = floor((a + b)/2);

	(*numComparacoes)++;

	if (x == vetor[meio])
		return meio;

	if (x < vetor[meio])
		return buscaBinaria2(vetor, a, meio-1, x, numComparacoes);

	return buscaBinaria2(vetor, meio+1, b, x, numComparacoes);
}

int buscaBinaria(int vetor[], int tam, int valor, int* numComparacoes) {
	*numComparacoes = 0;
	return buscaBinaria2(vetor, 0, tam-1, valor, numComparacoes);
}

int trocaBus(int vetor[], int x, int a, int b, int* numComparacoes) {
	if(b < a) 
		return b;

	*numComparacoes += 1;
	
	if(x >= vetor[b]) 
		return b;

	return trocaBus(vetor, x, a, b-1, numComparacoes);
}

int* insertion(int vetor[], int a, int b, int* numComparacoes) {
	int i = b;

	int m = trocaBus(vetor, vetor[b], a, b-1, numComparacoes);
	
	while(i > m + 1) {
		troca(vetor, i, i-1);
		i--;
	}
	return vetor;
}

int insertion2(int vetor[], int a, int b, int* numComparacoes) {
	if(a >= b)
		return -1;	
	
	insertion2(vetor, a, b-1, numComparacoes);
	insertion(vetor, a, b, numComparacoes);
	
	return *numComparacoes;
}

int insertionSort(int vetor[], int tam){	
	int numComparacoes = 0;
	return insertion2(vetor, 0, tam-1, &numComparacoes);
}

int buscaM(int vetor[], int a, int b, int indiceM, int comparado, int* numComparacoes) {
	if(a >= b) 
		return indiceM;
	
	*numComparacoes += 1;
	
	if(vetor[indiceM] >= vetor[a]) 
		indiceM = a;


	return buscaM(vetor, a+1, b, indiceM, comparado, numComparacoes);
}

int selection2(int vetor[], int a, int b, int* numComparacoes) {
	if(a == b)
		return *numComparacoes;
	
	int indiceM = a;
	
	indiceM = buscaM(vetor, indiceM+1, b, indiceM, indiceM, numComparacoes);	
	trocaSub(vetor, indiceM, a);

	selection2(vetor, a+1, b, numComparacoes);
	
	return *numComparacoes;	
}

int selectionSort(int vetor[], int tam){
	int numComparacoes = 0;
	int m = 0;
	return selection2(vetor, m, tam, &numComparacoes);
}

void copiar(int vetor[], int u[], int a, int b){
    int i = a;
    int j = 0;

	if(a >= b)
		return;

    while(i <= b) {
        vetor[i] = u[j];
        i++;
        j++;
    }
}

int merge(int vetor[], int u[], int a, int m, int b, int* numComparacoes){
	int k = 0;
	int i, j, p;

	if (a >= b){
		return -1;
	}

	i = a;
	j = m + 1;

	while (k < b-a+1){
		(*numComparacoes)++;
		if (j > b || (i <= m && vetor[i] <= vetor[j])){
			p = i;
			i = i + 1;
		}
		else{
			p = j;
			j = j + 1;
		}

		u[k] = vetor[p];
		k = k + 1;
	}
	copiar(vetor, u, a, b);
	return *numComparacoes;
}

int mergeSort2(int vetor[], int u[], int a, int b, int* numComparacoes){
	if (a >= b)
		return -1;

	int m = (a+b)/2;

	mergeSort2(vetor, u, a, m, numComparacoes);
	mergeSort2(vetor, u, m+1, b, numComparacoes);

	merge(vetor, u, a, m, b, numComparacoes);
	return *numComparacoes;
}

int mergeSort(int vetor[], int tam){
	int numComparacoes = 0;
	int* u;
	u = malloc(tam * sizeof(int));

	numComparacoes = mergeSort2(vetor, u, 0, tam-1, &numComparacoes);

	free(u);
	u = NULL;

	return numComparacoes;
}

int particionar(int vetor[], int a, int b, int *numComparacoes){
	int x = vetor[b]; //pivo
	int m = a;
	for (int i = a; i < b; i++){
		*numComparacoes += 1;
		if (vetor[i] <= x){
			trocaSub(vetor, m, i);
			m += 1;
		}
	}
	trocaSub(vetor, m, b);
	return m;
}

int quickSort2(int vetor[], int a, int b, int* numComparacoes){
	if (a >= b)
		return 1;

	int m = particionar(vetor, a, b, numComparacoes);
	quickSort2(vetor, a, m-1, numComparacoes);
	quickSort2(vetor, m+1, b, numComparacoes);

	return *numComparacoes;
}

int quickSort(int vetor[], int tam){
	int numComparacoes = 0;
	return quickSort2(vetor, 0, tam-1, &numComparacoes);
}

/*
Parou de funcionar (não funcionou com todos os Sorts), mas era o esqueleto de teste (ass. Gabriel Simon)

double AnaliseQuickSort(int vetor[], int tam, int *numComparacoes){
    double analise = 0;
    clock_t start, end;
    
    for(int i = 0; i < 15; i++){
        preencherAleatorio(vetor, tam, 40);
        start = clock();
        numComparacoes += quickSort(vetor, tam);
        end = clock();

        analise = ((double)end - start)/CLOCKS_PER_SEC;
    }

    *numComparacoes = *numComparacoes / 15;
    analise = analise / 15;
    
    return analise;
}
*/
