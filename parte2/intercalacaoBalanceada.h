// intercalacaoBalanceada.h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define STR_ARQ_SAIDA_TAM 12 // saídas/saida tem 12 letras.

typedef struct tipoRegistro
{
	int chave;
	char outros[28];
} registro;

registro *lerBytes (FILE *);

int enchePaginas (registro **, long, FILE *);

int compar (const void *, const void *);

int contaDigitos (long);

FILE *abrirArqSaida(long);

void abrirArqEntrada(FILE **, long, long);

void descarregarPaginas (FILE *, long, registro **);

long minimo (long, long);

int comparacaoR (registro, registro);

void apagaArquivoSaida(long);

void renomearArquivo(long, char*);

void intercala (FILE**, long, long, FILE*, registro**);

void intercalacaoBalanceada (char *, long, long, char *);
