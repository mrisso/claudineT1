// intercalacaoBalanceada.h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_ARQ_SAIDA_TAM 5 // Saída tem 5 letras.

typedef struct tipoRegistro
{
	char chave;
	char outros[31];
} registro;

registro *lerBytes (FILE *);

int enchePaginas (registro *, int, FILE *);

int compar (const void *, const void *);

int contaDigitos (int);

FILE *abrirArqSaida(int);

void descarregarPaginas (FILE *, int, registro *);

void intercalacaoBalanceada (FILE *, int, int);
