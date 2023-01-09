#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro()  //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese");   //Definindo a linguagem para nova fun��o
	
	//inicio cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];  
	char nome[40];
	char sobrenome[50];
	char cargo[40];
	//final cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf);  //Respons�vel por copiar os valores das string
	
	FILE *file;   // cria o arquivo com o dado
	file = fopen(arquivo, "w");  // cria o arquivo w o w significa escrever
	fprintf(file, "CPF: "); // escreve a palavra CPF no menu para servir de cabe�alho � resposta do sistema
	fprintf(file, cpf); // registra informa��o no arquivo - salva o valor da vari�vel, no caso cpf
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // abre o arquivo e a significa atualizar, inserir nova informa��o
	fprintf(file,"\n Nome: "); // pula uma linha para n�o juntar as informa��oes e introduz o cabe�alho da pr�xima vari�vel, Nome
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");  //coletando informa��o do usu�rio
	scanf("%s",nome); //mesmo da linha 19
	
	file = fopen(arquivo, "a"); //mesmo da linha 29
	fprintf(file,nome); // registra informa��o no arquivo - salva o valor da vari�vel, no caso nome
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //mesmo da linha 29
	fprintf(file,"\n Sobrenome: "); // pula uma linha para n�o juntar as informa��oes e introduz o cabe�alho da pr�xima vari�vel, Sobrenome
	fclose(file); // fecha o arquivo

	printf("Digite o sobrenome a ser cadastrado: ");  //coletando informa��o do usu�rio
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a"); //mesmo da linha 29
	fprintf(file,sobrenome); // registra informa��o no arquivo - salva o valor da vari�vel, no caso sobrenome
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); //mesmo da linha 29
	fprintf(file,"\n Cargo: "); // pula uma linha para n�o juntar as informa��oes e introduz o cabe�alho da pr�xima vari�vel, Cargo
	fclose(file);	// fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");  //coletando informa��o do usu�rio
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); //mesmo da linha 29
	fprintf(file,cargo); // registra informa��o no arquivo - salva o valor da vari�vel, no caso cargo
	fclose(file); // fecha o arquivo
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");   //Definindo a linguagem para nova fun��o
	
	//inicio cria��o de vari�veis/string
	char cpf[40];
	char conteudo[210];
	//final cria��o de vari�veis/string
	
	printf("Digite o CPF a ser consultado: "); //Coletar informa��o do usu�rio para consulta no sistema
	scanf("%s",cpf);
	
	FILE *file; //abrir arquivo
	file = fopen(cpf,"r"); //referenciar arquivo e dar o comando r de leitura
	
	if(file == NULL) //loop para definir resposta em caso de inser��o de informa��o inv�lida
	{
		printf("N�o foi poss�vel abrir o arquivo. N�o localizado! \n"); //mensagem para o usu�rio
	}
	
	while(fgets(conteudo, 210, file) != NULL) //Condi��o de repeti��o do comando e seu limite de tentativas
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n"); //Cabe�alho
		printf("%s", conteudo); //Informa��es encontradas
		printf("\n\n");
	}
	
	system("pause");
}
	
int deletar()
{
	setlocale(LC_ALL, "Portuguese");   //Definindo a linguagem para nova fun��o
	
	//inicio cria��o de vari�veis/string
	char cpf[40];
	//final cria��o de vari�veis/string
	
	printf("Digite o CPF do usu�rio a ser deletado: "); //Coletar informa��o do usu�rio para deletar dados no banco
	scanf("%s",cpf);
	
	remove(cpf); //fun��o para apagar dados no banco de dados
	
	FILE *file; //abrir arquivo
	file = fopen(cpf,"r"); //referenciar arquivo e dar o comando r de leitura
	
	if(file == NULL) //loop para definir resposta em caso de inser��o de informa��o inv�lida
	{
		printf("O usu�rio n�o se encontra no sistema! \n");
		system("pause");
	}
	else  //Resposta para op��o contr�ria, ou seja, inser��o de informa��o v�lida
	{
		remove(cpf);
		printf("Usu�rio deletado! \n");
		system("pause");
	}
	
}


int main() //fun��o principal. Sempre roda primeiro
	{
	int opcao=0;   //Definindo vari�veis
	int laco=1;
		
	for(laco=1;laco=1;)
	{
		
		system("cls");   //limpa a tela
		
		setlocale(LC_ALL, "Portuguese");   //Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n");  //inicio do menu
		printf("Ol�! Seja bem vinde ao Registro de Alunos da EBAC!\n\n");
		printf("\tEscolha a a��o que deseja realizar no menu: \n\n");
		printf("\t\t1 - Registrar nomes \n");
		printf("\t\t2 - Consultar nomes \n");
		printf("\t\t3 - Deletar nomes \n\n");
		printf("\t\t4 - Sair do sistema\n\n");
		printf("\tEsse Software � de uso livre \n");
		printf("\tFeito por Gabriel Lavareda Campos \n\n");
		printf("Op��o: ");   //fim do menu
	
		scanf("%d", &opcao);   //armazenando a escolha do usu�rio
	
		system("cls"); //respons�vel por limpar a tela
		
		switch(opcao)   //inicio da sele��o do menu e inser��o das fun��es com comandos para o sistema
		{
			case 1:
			registro(); //chamada de fun��es
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o cart�rio!");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel\n");
			system("pause");
			break;
		}   //final da sele��o
		
	}
}
