#include "intercalacaoBalanceada.h"

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		printf("Uso: %s <n-registros> <arq-saida>\n", argv[0]);
		printf("Em que o número de registros será igual a 2^n.\n");
		return 1;
	}

	registro *aux = malloc(sizeof(registro));

	int i;
	long tam = pow(2,atoi(argv[1]));
	FILE *arquivo = fopen("entrada","w+");

	//Semente para números aleatórios
	srand(time(NULL));

	for(i = 0; i < tam; i++)
	{
		aux->chave = rand() % 1000001; //gerando inteiros de 0 a 1 milhao
		fwrite(aux, sizeof(registro), 1, arquivo);
	}

	free(aux);
		
	intercalacaoBalanceada("entrada", 2, tam/4, argv[2]);

	return 0;
}
