// intercalacaoBalanceada.h

#include <stdio.h>
#include <stdlib.h>

typedef struct tipoRegistro
{
	char chave;
	char outros[31];
} registro;

registro *lerBytes (FILE *);

int enchePaginas (registro *, int, FILE *);

void intercalacaoBalanceada (FILE *, int, int);
