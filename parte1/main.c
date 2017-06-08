#include "intercalacaoBalanceada.h"

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		printf("Uso: %s <arquivo-para-ordenacao> <arquivo-de-saida>\n", argv[0]);
		return 1;
	}
	
	FILE *arqEntrada = fopen("input","w+");
	FILE *arqTexto = fopen("Chaves.txt","r");

	registro aux[22];
	int i;

	for(i = 0; i < 22; i++)
	{
		fscanf(arqTexto, "%c\n", &aux[i].chave);
	}

	fwrite(aux, sizeof(registro), 22, arqEntrada);

	fclose(arqEntrada);
	fclose(arqTexto);

	intercalacaoBalanceada(argv[1], 3, 2,argv[2]);

	return 0;
}
