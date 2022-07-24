#ifndef ORDENACAO_H_
#define ORDENACAO_H_

#define MAX_CHAR_NOME 200

void getNome(char nome[]);

unsigned int getGRR();
unsigned int getGRR1();

void preencherAleatorio(int vetor[], int numPos, int maxVal);
void imprimirVetor(int vetor[], int tamVetor);

int troca(int vetor[], int a, int b);
int trocaBus(int vetor[], int x, int a, int b, int* numComparacoes);

int buscaSequencial(int vetor[], int tam, int valor, int* numComparacoes);

int buscaBinaria(int vetor[], int tam, int valor, int* numComparacoes);
int buscaBinariaWow(int vetor[], int a, int b, int x, int* numComparacoes);

int insertion(int vetor[], int a, int b, int* numComparacoes);
int insertionSortWow(int vetor[], int a, int b, int* numComparacoes);
int insertionSort(int vetor[], int tam);

int buscaMenorIndice(int vetor[], int a, int b, int indiceM, int comparado, int* numComparacoes);
int selectionSortWow(int vetor[], int a, int b, int* numComparacoes);
int selectionSort(int vetor[], int tam);

void copiar(int vetor[], int u[], int a, int b);
int merge(int vetor[], int u[], int a, int m, int b, int* numComparacoes);
int mergeSortWow(int vetor[], int u[], int a, int b, int* numComparacoes);
int mergeSort(int vetor[], int tam);

int particionar(int vetor[], int a, int b, int* numComparacoes);
int quickSortWow(int vetor[], int a, int b, int* numComparacoes);
int quickSort(int vetor[], int tam);

void AnaliseInsertionSort(int vetor[], int tam, int numComparacoes);
void AnaliseSelectionSort(int vetor[], int tam, int numComparacoes);
void AnaliseMergeSort(int vetor[], int tam, int numComparacoes);
void AnaliseQuickSort(int vetor[], int tam, int numComparacoes);

#endif // ORDENACAO_H_
