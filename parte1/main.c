#include "intercalacaoBalanceada.h"

void printFile(char *nome)
{
	FILE *arquivo = fopen(nome, "r");
	registro *aux = malloc(sizeof(registro));
	size_t i = 1;

	while(1)
	{
		i = fread(aux,sizeof(registro),1,arquivo);	
		if(i != 0)
		{
			printf("%c\n", aux->chave);
		}

		else
			break;
	}
}

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		printf("Uso: %s <arquivo-para-ordenacao> <arquivo-de-saida>\n", argv[0]);
		return 1;
	}
	
	FILE *arqEntrada = fopen(argv[1],"w+");
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

	printFile(argv[2]);

	return 0;
}
