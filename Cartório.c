#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de loca��es de texto por regi�o
#include <string.h>	//biblioteca respons[avel por cuidar das strings

int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//In�cio da cria��o de vari�vies/strings
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//Fim da cria��o de vari�vies/strings

	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a armazenar as strings - usado toda vez que quer salvar uma string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo - w = fun��o de escrever (write)
	fprintf(file,cpf); //salvo o valor da vari�vel
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a"); // a= toda vez que quiser atualizar
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // r= toda vez que quiser fun��o de ler (read).
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;	
	file = fopen(cpf,"r");	
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema! \n");
		system("pause");
		
	}
	
	if(file != NULL)
	{
		printf("O usu�rio foi deletado com sucesso! \n");
		fclose(file);
		system("pause");
		
	}
	
}
	

int main()
{
	
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); // respons�vel por limpar a tela para o usu�rio ler sem muita "contamina��o de informa��es
	
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem 
	
		printf("### Cart�rio da EBAC ### \n\n");
		printf ("Escolha a op��o desejada do menu:\n\n");
		printf ("\t1 - Registrar nomes\n");
		printf ("\t2 - Consultar nomes\n");
		printf ("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema \n\n");
		printf ("Op��o: ");
	
		scanf ("%d", &opcao);
	
		system("cls"); //funcao de limpar a tela para o usu�rio depois que ele digitar uma op��o
		
		
		switch(opcao) //In�cio da sele��o do menu
		{
			case 1:
			registro(); //chamada da fun��o registro
			break;
			
			case 2:
			consulta(); //chamada da fun��o consulta
			break;
			
			case 3:
			deletar(); //chamada da fun��o deletar
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Op��o Inv�lida! \n");
			system("pause");
			break;
			
		} //Fim da sele��o do menu

	}

}
