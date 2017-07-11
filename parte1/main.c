#include "intercalacaoBalanceada.h"

#define MAX_TAM 100

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		printf("Uso: %s <arquivo-para-ordenacao> <arquivo-de-saida>\n", argv[0]);
		return 1;
	}
	
	FILE *arqEntrada = fopen(argv[1],"w+");
	FILE *arqTexto = fopen("Chaves.txt","r");

	registro aux[MAX_TAM];
	int i = 0;

	while(1)
	{
		if(fscanf(arqTexto, "%c\n", &aux[i].chave) == EOF)
			break;
		i++;
	}

	fwrite(aux, sizeof(registro), i, arqEntrada);

	fclose(arqEntrada);
	fclose(arqTexto);

	intercalacaoBalanceada(argv[1], 3, 2,argv[2]);

	return 0;
}
