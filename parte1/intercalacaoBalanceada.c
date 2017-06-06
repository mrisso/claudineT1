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


int compar (const void *reg1, const void * reg2)
{
	registro *registro1 = (registro *) reg1;
	registro *registro2 = (registro *) reg2;

	if(registro1->chave < registro2->chave)
		return 0;

	return 1;
}


int contaDigitos (int num)
{
	if(num == 0)
		return 1;

	int contador = 0;

	while(num != 0)
	{
		contador++;
		num /= 10;
	}

	return contador;
}


FILE *abrirArqSaida (int num)
{
	char *string = malloc((contaDigitos(num) + STR_ARQ_SAIDA_TAM) *
						  sizeof(char));

	sprintf(string, "saida%d", num);

	FILE *arquivoSaida = fopen(string, "w");
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
		// Ordenar com quicksort
		qsort(mem, mRegistros, sizeof(registro), compar);
		// abrir arquivo de saída
		// escrever mem no arquivo
		// fechar arquivo
	} while(!fim);

	// Intercalar arquivos.
}
