#ifndef ORDENACAO_H_
#define ORDENACAO_H_

#define MAX_CHAR_NOME 50

void getNome(char nome[]);

unsigned int getGRR();

void preencherAleatorio(int vetor[], int numPos, int maxVal);
void imprimirVetor(int vetor[], int tamVetor);

int troca(int vetor[], int a, int b);
int trocaBus(int vetor[], int x, int a, int b, int* numComparacoes);

int buscaSequencial(int vetor[], int tam, int valor, int* numComparacoes);

int buscaBinaria(int vetor[], int tam, int valor, int* numComparacoes);
int buscaBinaria2(int vetor[], int a, int b, int x, int* numComparacoes);

int* insertion(int vetor[], int a, int b, int* numComparacoes);
int insertion2(int vetor[], int a, int b, int* numComparacoes);
int insertionSort(int vetor[], int tam);

int buscaM(int vetor[], int a, int b, int indiceM, int comparado, int* numComparacoes);
int selection2(int vetor[], int a, int b, int* numComparacoes);
int selectionSort(int vetor[], int tam);

void copiar(int vetor[], int u[], int a, int b);
int merge(int vetor[], int u[], int a, int m, int b, int* numComparacoes);
int mergeSort2(int vetor[], int u[], int a, int b, int* numComparacoes);
int mergeSort(int vetor[], int tam);

int particionar(int vetor[], int a, int b, int* numComparacoes);
int quickSort2(int vetor[], int a, int b, int* numComparacoes);
int quickSort(int vetor[], int tam);

double AnaliseQuickSort(int vetor[], int tam, int *numComparacoes);

#endif // ORDENACAO_H_
