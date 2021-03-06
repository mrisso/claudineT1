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


int enchePaginas (registro **mem, int mRegistros, FILE *arquivo)
{
	registro *aux;
	int i,j;
	
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


FILE *abrirArqSaida (int num, int print)
{
	char *string = malloc((1 + contaDigitos(num) + STR_ARQ_SAIDA_TAM) *
						  sizeof(char));

	sprintf(string, "saida%d", num);

	if(print)
	{
		printf("Abrindo arquivo de saída: %s\n", string);
	}

	FILE *arquivoSaida = fopen(string, "w+");

	free(string);

	return arquivoSaida;
}


void abrirArqEntrada(FILE **vetArq, int low, int lim)
{
	int i;
	
	for(i = 0; i <= (lim - low); i++)
	{
		char *nome = malloc((1 + contaDigitos(low + i + 1) + STR_ARQ_SAIDA_TAM) *
							sizeof(char));

		sprintf(nome, "saida%d", (low + i + 1));
		if(access(nome, F_OK) != -1) // Verificar se arquivo existe
		{
			//Mostrar arquivos de entrada usados no momento
			printf("Abrindo arquivo de entrada: %s\n", nome);
			//Mostrar Conteúdo dos Arquivos
			imprimirArquivo(nome);
			vetArq[i] = fopen(nome, "rb");
		}
		else
			vetArq[i] = NULL;

		free(nome);
	}
}


void descarregarPaginas (FILE *arquivo, int mRegistros, registro **mem)
{
	int i;

	for(i = 0; i < mRegistros; i++)
	{
		if(mem[i] != NULL)
		{
			fwrite(mem[i],sizeof(registro),1,arquivo);
		}
	}
}


int minimo (int n1, int n2)
{
	if(n1 <= n2)
		return n1;
	
	return n2;
}

int comparacaoR (registro r1, registro r2)
{
	return r1.chave - r2.chave;
}


void apagaArquivoSaida(int num)
{
	char *nome = malloc((1 + contaDigitos(num) + STR_ARQ_SAIDA_TAM) *
						sizeof(char));

	sprintf(nome, "saida%d", num);

	remove(nome);

	free(nome);
}


void renomearArquivo(int num, char *nome)
{
	char *nomeAntigo = malloc((1 + contaDigitos(num) + STR_ARQ_SAIDA_TAM) *
						sizeof(char));

	sprintf(nomeAntigo, "saida%d", num);

	rename(nomeAntigo, nome);

	free(nomeAntigo);
}


void imprimirArquivo(char *nome)
{
	FILE *arquivo = fopen(nome, "r");
	registro *aux = malloc(sizeof(registro));
	size_t i = 1;

	printf("Coteúdo: ");
	while(1)
	{
		i = fread(aux,sizeof(registro),1,arquivo);	
		if(i != 0)
		{
			printf("%c ", aux->chave);
		}

		else
		{
			printf("\n");
			break;
		}
	}
}


void imprimirNArquivo(int num)
{
	char *nome = malloc((1 + contaDigitos(num) + STR_ARQ_SAIDA_TAM) *
						sizeof(char));

	sprintf(nome, "saida%d", num);

	imprimirArquivo(nome);

	free(nome);
}
	


void imprimirMemoria(registro **mem, int mRegistros)
{
	int i;

	for(i = 0; i < mRegistros; i++)
	{
		if(mem[i] != NULL)
		{
			printf("%c ", mem[i]->chave);
		}
	}
	printf("\n");
}


void intercala (FILE **vetArquivoEntrada, int low, int lim, FILE *arqSaida, registro **mem)
{
	int i, j, aux, arqID;
	int ordem = lim - low + 1;
	registro *menor = NULL;

	j = aux = 0;

	for(i = 0; i < ordem; i++)
	{
		if(vetArquivoEntrada[i] != NULL)
		{
			mem[i] = lerBytes(vetArquivoEntrada[i]);
		}

		else
			mem[i] =  NULL;
		
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


void intercalacaoBalanceada (char *nomeArquivo, int mRegistros, int ordem, char *nomeArquivoSaida)
{
	FILE *arquivo = fopen(nomeArquivo, "r");
	FILE *arquivoSaida;
	FILE *vetArquivoEntrada[ordem];

	registro **mem = malloc(mRegistros * sizeof(registro*));

	int nBlocos = 0;
	int fim, low, high, lim, i;

	printf("Conteúdo dos Blocos Ordenados:\n");
	do
	{
		nBlocos++;
		fim = enchePaginas(mem, mRegistros, arquivo);
		// Ordenar com quicksort
		qsort(mem, mRegistros, sizeof(registro*), compar);
		imprimirMemoria(mem, mRegistros);
		arquivoSaida = abrirArqSaida(nBlocos,0); //Sem impressao
		descarregarPaginas(arquivoSaida,mRegistros,mem);
		fclose(arquivoSaida);
	} while(!fim);
	printf("\n");

	fclose(arquivo);

	low = 0;
	high = nBlocos;

	while(low < high - 1)
	{
		lim = minimo((low + ordem - 1), high);
		high++;

		//Mostra o conteúdo de Low, Lim e High
		printf("Low: %i\nLim: %i\nHigh: %i\n",low, lim, high);

		abrirArqEntrada(vetArquivoEntrada,low,lim);
		arquivoSaida = abrirArqSaida(high,1); //Com impressao
		intercala(vetArquivoEntrada,low,lim,arquivoSaida,mem);
		fclose(arquivoSaida);

		//Mostra conteúdo do arquivo de saída
		imprimirNArquivo(high);

		for(i = 0; i < (lim - low + 1); i++)
		{
			fclose(vetArquivoEntrada[i]);
			apagaArquivoSaida(i + low + 1);
		}

		low += ordem;
		printf("\n");
	}

	renomearArquivo(high, nomeArquivoSaida);
	free(mem);
}
