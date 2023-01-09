#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro()  //Função responsável por cadastrar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese");   //Definindo a linguagem para nova função
	
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];  
	char nome[40];
	char sobrenome[50];
	char cargo[40];
	//final criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf);  //Responsável por copiar os valores das string
	
	FILE *file;   // cria o arquivo com o dado
	file = fopen(arquivo, "w");  // cria o arquivo w o w significa escrever
	fprintf(file, "CPF: "); // escreve a palavra CPF no menu para servir de cabeçalho à resposta do sistema
	fprintf(file, cpf); // registra informação no arquivo - salva o valor da variável, no caso cpf
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo e a significa atualizar, inserir nova informação
	fprintf(file,"\n Nome: "); // pula uma linha para não juntar as informaçãoes e introduz o cabeçalho da próxima variável, Nome
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");  //coletando informação do usuário
	scanf("%s",nome); //mesmo da linha 19
	
	file = fopen(arquivo, "a"); //mesmo da linha 29
	fprintf(file,nome); // registra informação no arquivo - salva o valor da variável, no caso nome
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //mesmo da linha 29
	fprintf(file,"\n Sobrenome: "); // pula uma linha para não juntar as informaçãoes e introduz o cabeçalho da próxima variável, Sobrenome
	fclose(file); // fecha o arquivo

	printf("Digite o sobrenome a ser cadastrado: ");  //coletando informação do usuário
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); //mesmo da linha 29
	fprintf(file,sobrenome); // registra informação no arquivo - salva o valor da variável, no caso sobrenome
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //mesmo da linha 29
	fprintf(file,"\n Cargo: "); // pula uma linha para não juntar as informaçãoes e introduz o cabeçalho da próxima variável, Cargo
	fclose(file);	// fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");  //coletando informação do usuário
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); //mesmo da linha 29
	fprintf(file,cargo); // registra informação no arquivo - salva o valor da variável, no caso cargo
	fclose(file); // fecha o arquivo
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");   //Definindo a linguagem para nova função
	
	//inicio criação de variáveis/string
	char cpf[40];
	char conteudo[210];
	//final criação de variáveis/string
	
	printf("Digite o CPF a ser consultado: "); //Coletar informação do usuário para consulta no sistema
	scanf("%s",cpf);
	
	FILE *file; //abrir arquivo
	file = fopen(cpf,"r"); //referenciar arquivo e dar o comando r de leitura
	
	if(file == NULL) //loop para definir resposta em caso de inserção de informação inválida
	{
		printf("Não foi possível abrir o arquivo. Não localizado! \n"); //mensagem para o usuário
	}
	
	while(fgets(conteudo, 210, file) != NULL) //Condição de repetição do comando e seu limite de tentativas
	{
		printf("\nEssas são as informações do usuário: \n"); //Cabeçalho
		printf("%s", conteudo); //Informações encontradas
		printf("\n\n");
	}
	
	system("pause");
}
	
int deletar()
{
	setlocale(LC_ALL, "Portuguese");   //Definindo a linguagem para nova função
	
	//inicio criação de variáveis/string
	char cpf[40];
	//final criação de variáveis/string
	
	printf("Digite o CPF do usuário a ser deletado: "); //Coletar informação do usuário para deletar dados no banco
	scanf("%s",cpf);
	
	remove(cpf); //função para apagar dados no banco de dados
	
	FILE *file; //abrir arquivo
	file = fopen(cpf,"r"); //referenciar arquivo e dar o comando r de leitura
	
	if(file == NULL) //loop para definir resposta em caso de inserção de informação inválida
	{
		printf("O usuário não se encontra no sistema! \n");
		system("pause");
	}
	else  //Resposta para opção contrária, ou seja, inserção de informação válida
	{
		remove(cpf);
		printf("Usuário deletado! \n");
		system("pause");
	}
	
}


int main() //função principal. Sempre roda primeiro
	{
	int opcao=0;   //Definindo variáveis
	int laco=1;
		
	for(laco=1;laco=1;)
	{
		
		system("cls");   //limpa a tela
		
		setlocale(LC_ALL, "Portuguese");   //Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n");  //inicio do menu
		printf("Olá! Seja bem vinde ao Registro de Alunos da EBAC!\n\n");
		printf("\tEscolha a ação que deseja realizar no menu: \n\n");
		printf("\t\t1 - Registrar nomes \n");
		printf("\t\t2 - Consultar nomes \n");
		printf("\t\t3 - Deletar nomes \n\n");
		printf("\t\t4 - Sair do sistema\n\n");
		printf("\tEsse Software é de uso livre \n");
		printf("\tFeito por Gabriel Lavareda Campos \n\n");
		printf("Opção: ");   //fim do menu
	
		scanf("%d", &opcao);   //armazenando a escolha do usuário
	
		system("cls"); //responsável por limpar a tela
		
		switch(opcao)   //inicio da seleção do menu e inserção das funções com comandos para o sistema
		{
			case 1:
			registro(); //chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o cartório!");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponível\n");
			system("pause");
			break;
		}   //final da seleção
		
	}
}
