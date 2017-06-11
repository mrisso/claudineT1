// intercalacaoBalanceada.h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define STR_ARQ_SAIDA_TAM 5 // Saída tem 5 letras.

typedef struct tipoRegistro
{
	char chave;
	char outros[31];
} registro;

registro *lerBytes (FILE *);

int enchePaginas (registro **, int, FILE *);

int compar (const void *, const void *);

int contaDigitos (int);

FILE *abrirArqSaida(int, int);

void abrirArqEntrada(FILE **, int, int);

void descarregarPaginas (FILE *, int, registro **);

int minimo (int, int);

int comparacaoR (registro, registro);

void apagaArquivoSaida(int);

void renomearArquivo(int, char*);

void imprimirArquivo(char *);

void imprimirNArquivo(int);

void imprimirMemoria(registro **, int);

void intercala (FILE**, int, int, FILE*, registro**);

void intercalacaoBalanceada (char *, int, int, char *);
