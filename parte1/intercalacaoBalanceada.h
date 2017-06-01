// intercalacaoBalanceada.h

#include <stdio.h>
#include <stdlib.h>

typedef struct tipoRegistro
{
	char chave;
	char outros[31];
} registro;

char *lerBytes (FILE *, int);

void intercalacaoBalanceada (FILE *, int, int);
