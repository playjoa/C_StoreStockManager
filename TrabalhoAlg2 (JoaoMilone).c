#include <stdio.h>

struct Produto{
	int idProd;
	char nomeProd[50];
	char precoProd[50];
	char qtdProd[50];
};

void menu(){

	printf("   \n");
	printf("	Bem vindo(a) ao Sistema de Estoque \n");
	printf("   \n");
	printf("  	Por favor, escolha o numero com acao desejada \n");
	printf("   \n");
	printf("	1 - Cadastrar Produto Novo \n");
	printf("	2 - Alterar Produto \n");
	printf("	3 - Excluir Produto \n");
	printf("	4 - Pesquisar Produto \n");
	printf("	5 - Verificar Estoque \n");
	printf("	6 - Sair! \n	");
}




void main()
{
int resposta, idProdCad=0, idProdBusca, i=0, b=0;
FILE *f=NULL;
struct Produto p[1000];


	f = fopen("Estoque.dat","wb");
	
	do
	{
		menu();
		scanf("%d", &resposta);
		
		if(resposta==1)
		{
			idProdCad++;
			
			printf("	Preencha os campos abaixo com as informacoes do produto de id:%d \n", idProdCad);
			
			p[idProdCad].idProd=idProdCad;
			printf("	Nome Produto: \n	");	
			scanf("%s", p[idProdCad].nomeProd);
			printf("	Preco do Produto (R$): \n	");
		    scanf("%s", p[idProdCad].precoProd);
			printf("	Qtd do Produto: \n	");
			scanf("%s", p[idProdCad].qtdProd);
			
			fwrite(&p[idProdCad], sizeof(p),1, f);

			printf("	Produto cadastrado com sucesso! \n	");
		
	
		}
		if(resposta==2)
		{
			printf("	Qual o id do Produto a ser alterado? \n	");
			scanf("%d", &idProdBusca);
			
			b=0;
			
			for(i=0; i<1000; i++)
			{
				if(idProdBusca==p[i].idProd && idProdBusca>0)
				{
					b=1;
				}
			}
			
			if(b==1)
			{
				printf("	Nome Atual: %s \n", p[idProdBusca].nomeProd);
				printf("	Preco Atual (R$): %s \n", p[idProdBusca].precoProd);
				printf("	Qtd em estoque Atual: %s \n", p[idProdBusca].qtdProd);
				
			    printf("	Preencha os campos abaixo com as novas informacoes \n	");
				printf("	Novo nome: \n	");
				scanf("%s", p[idProdBusca].nomeProd);
				printf("	Novo Preco (R$): \n	");
		        scanf("%s", p[idProdBusca].precoProd);
				printf("	Nova qtd: \n	");
			    scanf("%s", p[idProdBusca].qtdProd);
				
				fwrite(&p[idProdBusca], sizeof(p),1, f);
				
				printf("	Produto alterado com sucesso! \n");
			}
			else
			{
				printf("	Produto nao cadastrado! \n");
			}
			
		}
		if(resposta==3)
		{
			printf("	Qual o id do Produto a ser Excluido? \n	");
			scanf("%d", &idProdBusca);
			
			b=0;
			
			for(i=0; i<1000; i++)
			{
				if(idProdBusca==p[i].idProd  && idProdBusca>0)
				{
					b=1;
				}
			}
			
			if(b==1)
			{   
				p[idProdBusca].idProd=-1;

				
				printf("	Produto excluido com sucesso! \n");
			}
			else
			{
				printf("	Produto nao cadastrado! \n");
			}
		}
		if(resposta==4)
		{
			printf("	Qual o id do Produto a ser pesquisado? \n	");
			scanf("%d", &idProdBusca);
			
			b=0;
			
			for(i=0; i<1000; i++)
			{
				if(idProdBusca==p[i].idProd  && idProdBusca>0)
				{
					b=1;
				}
			}
			
			if(b==1)
			{
				printf("	ID: %d \n", p[idProdBusca].idProd);
				printf("	Nome: %s \n", p[idProdBusca].nomeProd);
				printf("	Preco (R$): %s \n", p[idProdBusca].precoProd);
				printf("	Qtd em estoque: %s \n", p[idProdBusca].qtdProd);
				
			}
			else
			{
				printf("	Produto nao cadastrado! \n");
			}
			
		}
		if(resposta==5)
		{
			printf("	Qual o id do Produto a verificar estoque? \n	");
			scanf("%d", &idProdBusca);
			
			b=0;
			
			for(i=0; i<1000; i++)
			{
				if(idProdBusca==p[i].idProd  && idProdBusca>0)
				{
					b=1;
				}
			}
			
			if(b==1)
			{
				printf("	Qtd em estoque de %s(s): %s \n",p[idProdBusca].nomeProd,p[idProdBusca].qtdProd);
			}
			else
			{
				printf("	Produto nao cadastrado! \n");
			}
		}	
		if(resposta>6 || resposta <1)
		{
			printf("	Opcao invalida, Por Favor Escolha outra! \n");
		}
	
	}while(resposta!=6);
	
	fclose(f);
}
