#include "intercalacaoBalanceada.h"

int main(void)
{
	registro *aux = malloc(sizeof(registro));

	int i,j;
	long tam[3] = {pow(2,20),pow(2,21),pow(2,22)};
	FILE *arquivo[3] = {fopen("entrada20","w+"),fopen("entrada21","w+"),fopen("entrada22","w+")};

	struct timeval inicio, fim;
	int tmicro = 0;

	//Semente para números aleatórios
	srand(time(NULL));

	for(j = 0; j < 3; j++)
		for(i = 0; i < tam[j]; i++)
		{
			aux->chave = rand() % 100001; //gerando inteiros de 0 a 1 milhao
			fwrite(aux, sizeof(registro), 1, arquivo[j]);
		}

	for(j = 0; j < 3; j++)
		fclose(arquivo[j]);

	free(aux);

	//f = 2
		
	printf("f = 2\n");
	printf("n\t");
	printf("m = n/4\t\t");
	printf("m = n/16\t");
	printf("m = n/256\n");
	printf("2e20\t");

	//2e20
	
	gettimeofday(&inicio, NULL);
	intercalacaoBalanceada("entrada20", tam[0]/4, 2, "saida20");
	gettimeofday(&fim, NULL);
	tmicro = (int) (1000000 * (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec));

	printf("%d us\t",tmicro);

	gettimeofday(&inicio, NULL);
	intercalacaoBalanceada("entrada20", tam[0]/16, 2, "saida20");
	gettimeofday(&fim, NULL);
	tmicro = (int) (1000000 * (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec));

	printf("%d us\t",tmicro);

	gettimeofday(&inicio, NULL);
	intercalacaoBalanceada("entrada20", tam[0]/256, 2, "saida20");
	gettimeofday(&fim, NULL);
	tmicro = (int) (1000000 * (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec));

	printf("%d us\n",tmicro);
	printf("2e21\t");

	//2e21
	
	gettimeofday(&inicio, NULL);
	intercalacaoBalanceada("entrada21", tam[1]/4, 2, "saida21");
	gettimeofday(&fim, NULL);
	tmicro = (int) (1000000 * (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec));

	printf("%d us\t",tmicro);

	gettimeofday(&inicio, NULL);
	intercalacaoBalanceada("entrada21", tam[1]/16, 2, "saida21");
	gettimeofday(&fim, NULL);
	tmicro = (int) (1000000 * (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec));

	printf("%d us\t",tmicro);

	gettimeofday(&inicio, NULL);
	intercalacaoBalanceada("entrada21", tam[1]/256, 2, "saida21");
	gettimeofday(&fim, NULL);
	tmicro = (int) (1000000 * (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec));

	printf("%d us\n",tmicro);
	printf("2e22\t");

	//2e22

	gettimeofday(&inicio, NULL);
	intercalacaoBalanceada("entrada22", tam[2]/4, 2, "saida22");
	gettimeofday(&fim, NULL);
	tmicro = (int) (1000000 * (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec));

	printf("%d us\t",tmicro);

	gettimeofday(&inicio, NULL);
	intercalacaoBalanceada("entrada22", tam[2]/16, 2, "saida22");
	gettimeofday(&fim, NULL);
	tmicro = (int) (1000000 * (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec));

	printf("%d us\t",tmicro);

	gettimeofday(&inicio, NULL);
	intercalacaoBalanceada("entrada22", tam[2]/256, 2, "saida22");
	gettimeofday(&fim, NULL);
	tmicro = (int) (1000000 * (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec));

	printf("%d us\n",tmicro);

	//f = 3

	printf("f = 3\n");
	printf("n\t");
	printf("m = n/4\t\t");
	printf("m = n/16\t");
	printf("m = n/256\n");
	printf("2e20\t");

	//2e20
	
	gettimeofday(&inicio, NULL);
	intercalacaoBalanceada("entrada20", tam[0]/4, 3, "saida20");
	gettimeofday(&fim, NULL);
	tmicro = (int) (1000000 * (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec));

	printf("%d us\t",tmicro);

	gettimeofday(&inicio, NULL);
	intercalacaoBalanceada("entrada20", tam[0]/16, 3, "saida20");
	gettimeofday(&fim, NULL);
	tmicro = (int) (1000000 * (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec));

	printf("%d us\t",tmicro);

	gettimeofday(&inicio, NULL);
	intercalacaoBalanceada("entrada20", tam[0]/256, 3, "saida20");
	gettimeofday(&fim, NULL);
	tmicro = (int) (1000000 * (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec));

	printf("%d us\n",tmicro);
	printf("2e21\t");

	//2e21
	
	gettimeofday(&inicio, NULL);
	intercalacaoBalanceada("entrada21", tam[1]/4, 3, "saida21");
	gettimeofday(&fim, NULL);
	tmicro = (int) (1000000 * (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec));

	printf("%d us\t",tmicro);

	gettimeofday(&inicio, NULL);
	intercalacaoBalanceada("entrada21", tam[1]/16, 3, "saida21");
	gettimeofday(&fim, NULL);
	tmicro = (int) (1000000 * (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec));

	printf("%d us\t",tmicro);

	gettimeofday(&inicio, NULL);
	intercalacaoBalanceada("entrada21", tam[1]/256, 3, "saida21");
	gettimeofday(&fim, NULL);
	tmicro = (int) (1000000 * (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec));

	printf("%d us\n",tmicro);
	printf("2e22\t");

	//2e22

	gettimeofday(&inicio, NULL);
	intercalacaoBalanceada("entrada22", tam[2]/4, 3, "saida22");
	gettimeofday(&fim, NULL);
	tmicro = (int) (1000000 * (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec));

	printf("%d us\t",tmicro);

	gettimeofday(&inicio, NULL);
	intercalacaoBalanceada("entrada22", tam[2]/16, 3, "saida22");
	gettimeofday(&fim, NULL);
	tmicro = (int) (1000000 * (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec));

	printf("%d us\t",tmicro);

	gettimeofday(&inicio, NULL);
	intercalacaoBalanceada("entrada22", tam[2]/256, 3, "saida22");
	gettimeofday(&fim, NULL);
	tmicro = (int) (1000000 * (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec));

	printf("%d us\n",tmicro);

	//f = 4

	printf("f = 4\n");
	printf("n\t");
	printf("m = n/4\t\t");
	printf("m = n/16\t");
	printf("m = n/256\n");
	printf("2e20\t");

	//2e20
	
	gettimeofday(&inicio, NULL);
	intercalacaoBalanceada("entrada20", tam[0]/4, 4, "saida20");
	gettimeofday(&fim, NULL);
	tmicro = (int) (1000000 * (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec));

	printf("%d us\t",tmicro);

	gettimeofday(&inicio, NULL);
	intercalacaoBalanceada("entrada20", tam[0]/16, 4, "saida20");
	gettimeofday(&fim, NULL);
	tmicro = (int) (1000000 * (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec));

	printf("%d us\t",tmicro);

	gettimeofday(&inicio, NULL);
	intercalacaoBalanceada("entrada20", tam[0]/256, 4, "saida20");
	gettimeofday(&fim, NULL);
	tmicro = (int) (1000000 * (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec));

	printf("%d us\n",tmicro);
	printf("2e21\t");

	//2e21
	
	gettimeofday(&inicio, NULL);
	intercalacaoBalanceada("entrada21", tam[1]/4, 4, "saida21");
	gettimeofday(&fim, NULL);
	tmicro = (int) (1000000 * (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec));

	printf("%d us\t",tmicro);

	gettimeofday(&inicio, NULL);
	intercalacaoBalanceada("entrada21", tam[1]/16, 4, "saida21");
	gettimeofday(&fim, NULL);
	tmicro = (int) (1000000 * (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec));

	printf("%d us\t",tmicro);

	gettimeofday(&inicio, NULL);
	intercalacaoBalanceada("entrada21", tam[1]/256, 4, "saida21");
	gettimeofday(&fim, NULL);
	tmicro = (int) (1000000 * (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec));

	printf("%d us\n",tmicro);
	printf("2e22\t");

	//2e22

	gettimeofday(&inicio, NULL);
	intercalacaoBalanceada("entrada22", tam[2]/4, 4, "saida22");
	gettimeofday(&fim, NULL);
	tmicro = (int) (1000000 * (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec));

	printf("%d us\t",tmicro);

	gettimeofday(&inicio, NULL);
	intercalacaoBalanceada("entrada22", tam[2]/16, 4, "saida22");
	gettimeofday(&fim, NULL);
	tmicro = (int) (1000000 * (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec));

	printf("%d us\t",tmicro);

	gettimeofday(&inicio, NULL);
	intercalacaoBalanceada("entrada22", tam[2]/256, 4, "saida22");
	gettimeofday(&fim, NULL);
	tmicro = (int) (1000000 * (fim.tv_sec - inicio.tv_sec) + (fim.tv_usec - inicio.tv_usec));

	printf("%d us\n",tmicro);
	return 0;
}
