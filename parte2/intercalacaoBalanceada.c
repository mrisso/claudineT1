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


int enchePaginas (registro **mem, long mRegistros, FILE *arquivo)
{
	registro *aux;
	long i,j;
	
	for(i = 0; i < mRegistros; i++)
	{
		if((aux = lerBytes(arquivo)) == NULL) {
			for(j = i; j < mRegistros; j++)
			{
				mem[j] = NULL;
			}

			return 1;
		}

		mem[i] = aux;
	}

	return 0;
}


int compar (const void *reg1, const void * reg2)
{
	registro *registro1 = *(registro * const *) reg1;
	registro *registro2 = *(registro * const *) reg2;

	if(registro1 == NULL)
		return 1;

	if(registro2 == NULL)
		return -1;

	return registro1->chave - registro2->chave;
}


int contaDigitos (long num)
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


FILE *abrirArqSaida (long num)
{
	char *string = malloc((1 + contaDigitos(num) + STR_ARQ_SAIDA_TAM) *
						  sizeof(char));

	sprintf(string, "saidas/saida%li", num);

	FILE *arquivoSaida = fopen(string, "w+");

	free(string);

	return arquivoSaida;
}


void abrirArqEntrada(FILE **vetArq, long low, long lim)
{
	long i;
	
	for(i = 0; i <= (lim - low); i++)
	{
		char *nome = malloc((1 + contaDigitos(low + i + 1) + STR_ARQ_SAIDA_TAM) *
							sizeof(char));

		sprintf(nome, "saidas/saida%li", (low + i + 1));
		vetArq[i] = fopen(nome, "rb");
		free(nome);
	}
}


void descarregarPaginas (FILE *arquivo, long mRegistros, registro **mem)
{
	long i;

	for(i = 0; i < mRegistros; i++)
	{
		if(mem[i] != NULL)
		{
			fwrite(mem[i],sizeof(registro),1,arquivo);
		}
	}
}


long minimo (long n1, long n2)
{
	if(n1 <= n2)
		return n1;
	
	return n2;
}

int comparacaoR (registro r1, registro r2)
{
	return r1.chave - r2.chave;
}


void apagaArquivoSaida(long num)
{
	char *nome = malloc((1 + contaDigitos(num) + STR_ARQ_SAIDA_TAM) *
						sizeof(char));

	sprintf(nome, "saidas/saida%li", num);

	remove(nome);

	free(nome);
}


void renomearArquivo(long num, char *nome)
{
	char *nomeAntigo = malloc((1 + contaDigitos(num) + STR_ARQ_SAIDA_TAM) *
						sizeof(char));

	sprintf(nomeAntigo, "saidas/saida%li", num);

	rename(nomeAntigo, nome);

	free(nomeAntigo);
}


void intercala (FILE **vetArquivoEntrada, long low, long lim, FILE *arqSaida, registro **mem)
{
	long i, j, aux, arqID;
	long ordem = lim - low + 1;
	registro *menor = NULL;

	j = aux = 0;

	for(i = 0; i < ordem; i++)
	{
		mem[i] = lerBytes(vetArquivoEntrada[i]);
		if(mem[i] != NULL)
		{
			menor = mem[i];
			arqID = i;
		}
	}

	while(aux < ordem)
	{
		aux = 0;

		for(j = 0; j < ordem; j++)
		{
			if(mem[j] != NULL)
			{
				if(comparacaoR(*menor, *mem[j]) >= 0)
				{
					menor = mem[j];
					arqID = j;
				}
			}

			else
				aux++;
		}

		if(aux >= ordem)
			break;

		fwrite(menor, sizeof(registro), 1, arqSaida);

		mem[arqID] = lerBytes(vetArquivoEntrada[arqID]);

		for(i = 0; i < ordem; i++)
		{
			if(mem[i] != NULL)
			{
				menor = mem[i];
				break;
			}
		}
	}
}


void intercalacaoBalanceada (char *nomeArquivo, long mRegistros, long ordem, char *nomeArquivoSaida)
{
	FILE *arquivo = fopen(nomeArquivo, "r");
	FILE *arquivoSaida;
	FILE *vetArquivoEntrada[ordem];

	registro **mem = malloc(mRegistros * sizeof(registro*));

	long nBlocos = 0;
	long fim, low, high, lim, i;

	do
	{
		nBlocos++;
		fim = enchePaginas(mem, mRegistros, arquivo);
		// Ordenar com quicksort
		qsort(mem, mRegistros, sizeof(registro*), compar);
		arquivoSaida = abrirArqSaida(nBlocos);
		descarregarPaginas(arquivoSaida,mRegistros,mem);
		fclose(arquivoSaida);
	} while(!fim);

	fclose(arquivo);

	low = 0;
	high = nBlocos;

	while(low < high - 1)
	{
		lim = minimo((low + ordem - 1), high);
		abrirArqEntrada(vetArquivoEntrada,low,lim);
		high++;
		arquivoSaida = abrirArqSaida(high);
		intercala(vetArquivoEntrada,low,lim,arquivoSaida,mem);
		fclose(arquivoSaida);

		for(i = 0; i < (lim - low + 1); i++)
		{
			fclose(vetArquivoEntrada[i]);
			apagaArquivoSaida(i + low + 1);
		}

		low += ordem;
	}

	renomearArquivo(high, nomeArquivoSaida);
	free(mem);
}
