// intercalacaoBalanceada.c
#include "intercalacaoBalanceada.h"

char *lerBytes (FILE *arquivo, int mRegistros)
{
	char *bytes = malloc(mRegistros * 32 * sizeof(char));
	size_t i;

	if((i = fread(bytes, 32 * sizeof(char), mRegistros, arquivo)) !=
	   32 * sizeof(char) * mRegistros)
	{
		char *walker; 

		walker = bytes + i;

		// Consertar condiçao em que a funçao nao consegue ler m Registros.
	}

	return bytes;
}

void intercalacaoBalanceada (FILE *arquivo, int mRegistros, int ordem)
{
	FILE *arquivoSaida;

	int nBlocos = 0;
	

}
