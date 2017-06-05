// intercalacaoBalanceada.c
#include "intercalacaoBalanceada.h"

registro *lerBytes (FILE *arquivo)
{
	registro *bytes = malloc(sizeof(registro));

	if(fread(bytes, sizeof(registro), 1, arquivo) == 0)
	{
		free(bytes);
		return NULL;
	}

	return bytes;
}


int enchePaginas (registro *mem, int mRegistros, FILE *arquivo)
{
	registro *aux;
	
	for(int i = 0; i < mRegistros; i++)
	{
		if((aux = lerBytes(arquivo)) == NULL)
		{
			for(int j = i; j < mRegistros; j++)
			{
				mem[j].chave = (char)64; //Controle / 64 = @
			}

			return 1;
		}

		mem[i].chave = aux->chave;
		free(aux);
	}

	return 0;
}



void intercalacaoBalanceada (FILE *arquivo, int mRegistros, int ordem)
{
	FILE *arquivoSaida;

	registro *mem = malloc(mRegistros * sizeof(registro));

	int nBlocos = 0;
	int fim;

	do
	{
		nBlocos++;
		fim = enchePaginas(mem, mRegistros, arquivo);
		// ordenar memória interna (mem)
		// abrir arquivo de saída
		// escrever mem no arquivo
		// fechar arquivo
	} while(!fim);

	// Intercalar arquivos.
}
