#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de locações de texto por região
#include <string.h>	//biblioteca respons[avel por cuidar das strings

int registro() //função responsável por cadastrar os usuários no sistema
{
	//Início da criação de variávies/strings
	char arquivo [40];
	char cpf [40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//Fim da criação de variávies/strings

	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a armazenar as strings - usado toda vez que quer salvar uma string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo - w = função de escrever (write)
	fprintf(file,cpf); //salvo o valor da variável
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
	file = fopen(cpf, "r"); // r= toda vez que quiser função de ler (read).
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado! \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;	
	file = fopen(cpf,"r");	
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema! \n");
		system("pause");
		
	}
	
	if(file != NULL)
	{
		printf("O usuário foi deletado com sucesso! \n");
		fclose(file);
		system("pause");
		
	}
	
}
	

int main()
{
	
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); // responsável por limpar a tela para o usuário ler sem muita "contaminação de informações
	
		setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem 
	
		printf("### Cartório da EBAC ### \n\n");
		printf ("Escolha a opção desejada do menu:\n\n");
		printf ("\t1 - Registrar nomes\n");
		printf ("\t2 - Consultar nomes\n");
		printf ("\t3 - Deletar nomes\n\n");
		printf ("Opção: ");
	
		scanf ("%d", &opcao);
	
		system("cls"); //funcao de limpar a tela para o usuário depois que ele digitar uma opção
		
		
		switch(opcao) //Início da seleção do menu
		{
			case 1:
			registro(); //chamada da função registro
			break;
			
			case 2:
			consulta(); //chamada da função consulta
			break;
			
			case 3:
			deletar(); //chamada da função deletar
			break;
			
			default:
			printf("Opção Inválida! \n");
			system("pause");
			break;
			
		} //Fim da seleção do menu

	}

}
