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

	return (int) registro1->chave - (int) registro2->chave;
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

	free(string);

	return arquivoSaida;
}


void abrirArqEntrada(FILE **vetArq, int low, int lim)
{
	int count = 0;
	for(int i = low; i <= lim; i++)
	{
		char *nome = malloc((contaDigitos(i) + STR_ARQ_SAIDA_TAM) *
							sizeof(char));

		sprintf(nome, "saida%d", i);
		vetArq[count] = fopen(nome, "r");
		count++;
		free(nome);
	}
}


void descarregarPaginas (FILE *arquivo, int mRegistros, registro *mem)
{
	int i;

	for(i = 0; i < mRegistros; i++)
	{
		if(mem[i].chave == (char) 64)
			break;
	}

	fwrite(mem,sizeof(registro),i,arquivo);
}


int minimo (int n1, int n2)
{
	if(n1 <= n2)
		return n1;
	
	return n2;
}


void intercalacaoBalanceada (char *nomeArquivo, int mRegistros, int ordem)
{
	FILE *arquivo = fopen(nomeArquivo, "r");
	FILE *arquivoSaida;
	FILE *vetArquivoEntrada[ordem];

	registro *mem = malloc(mRegistros * sizeof(registro));

	int nBlocos = 0;
	int fim, low, high, lim;

	do
	{
		nBlocos++;
		fim = enchePaginas(mem, mRegistros, arquivo);
		// Ordenar com quicksort
		qsort(mem, mRegistros, sizeof(registro), compar);
		arquivoSaida = abrirArqSaida(nBlocos);
		descarregarPaginas(arquivoSaida,mRegistros,mem);
		fclose(arquivoSaida);
	} while(!fim);

	fclose(arquivo);

	low = 0;
	high = nBlocos - 1;

	while(low < high)
	{
		lim = minimo((low + ordem - 1), high);
		abrirArqEntrada(vetArquivoEntrada,low,lim);
		high++;
		arquivoSaida = abrirArqSaida(high);
		//Intercalar
	}
}
