#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct aluno { // Declaração da estrutura de dados
	int ru;
	char nome[50];
	char email[80];
	struct aluno* proximo;
} cadastro;// Variável de controle

cadastro* ini_cad = NULL;

int op,c; // Declaração de variáveis globais
void cadastrar();
void pesquisar();

int main(int argc, char* argv[]) { // Programa principal

	do {// Imprime menu
		system("cls");

		printf("\n");
		printf("*********Cadastro*********\n");
		printf("*                        *\n");
		printf("* Escolha uma opcao      *\n");
		printf("* 1. Cadastrar Aluno     *\n");
		printf("* 2. Pesquisar Aluno     *\n");
		printf("* 3. Sair                *\n");
		printf("*                        *\n");
		printf("**************************\n");
		scanf_s("%d", &op);// Grava opçao do usuário
		switch (op) {
		
			case 1:
				cadastrar();// Chama função de cadastro

				break;

			case 2:
				pesquisar();// Chama função de pesquisa

				break;

			case 3:

				system("pause");// Encerra programa
				break;
			default:
				printf("Opcao Invalida...");
				break;
		}

	} while (op != 3);// Continua imprimindo menu enqunto a opção for diferente de sair




	return 0;
}

void cadastrar() {// Função de cadastro

	int cont; 
	cadastro* prox_cad;// inicializa variavel

	if (ini_cad == NULL) 
	{
		ini_cad = (cadastro*)malloc(sizeof(cadastro));//Libera memória
		ini_cad->proximo = NULL;
		if (ini_cad == NULL) exit(1);
	}
	prox_cad = ini_cad;

	while (1) {// Imprime os inputs paracadastro
		printf("Digite o RU:");
		scanf_s("%d", &prox_cad->ru);// Grava o input e aponta para o proximo input
		while ((c = getchar()) != '\n' && c != EOF) {} // limpando o buffer do teclado.
		printf("Digite o Nome:");
		scanf_s("%s", &prox_cad->nome, 50);// Grava o input e aponta para o proximo input
		while ((c = getchar()) != '\n' && c != EOF) {} // limpando o buffer do teclado.
		printf("Digite o email:");
		scanf_s("%s", &prox_cad->email, 80); // Grava o input e aponta para o proximo input
		while ((c = getchar()) != '\n' && c != EOF) {} // limpando o buffer do teclado.
		printf("\nContinuar cadastrando? \n 1 SIM e 0 NAO:");
		scanf_s("\n %d", &cont);
		while ((c = getchar()) != '\n' && c != EOF) {} // limpando o buffer do teclado.
		if (cont == 0) break;
		
		prox_cad->proximo = (cadastro*)malloc(sizeof(cadastro));
		prox_cad = prox_cad->proximo;
		prox_cad->proximo = NULL;
	}
	printf("\n");
}

void pesquisar() {// Função de pesquisa
	int ru_aux; // declaração de variável auxiliar
	char nome_aux[50];// declaração de variável auxiliar
	cadastro* prox_cad;//Inicializa variavel

	do {//Imprime menu de input
		printf("\n Digite parametro da pesquisa: \n1 RU : \n2 Nome :\n0 sair\n");
		scanf_s("%d", &op);
		while ((c = getchar()) != '\n' && c != EOF) {} // limpando o buffer do teclado.
		if (op == 0) break;//condicional para enceramento do input
		prox_cad = ini_cad;
		switch (op) {// Recebe prametro do input e chama a opção escolhida
		case 1:
			printf("\n Digite o RU do Aluno:");
			scanf_s("%d", &ru_aux);
			while ((c = getchar()) != '\n' && c != EOF) {} // limpando o buffer do teclado.
			while (prox_cad != NULL) {
				if (prox_cad->ru == ru_aux)
				{
					printf("ru: %d\n nome: %s\n email: %s", prox_cad->ru, prox_cad->nome, prox_cad->email);
					break;
				}
				prox_cad = prox_cad->proximo;
			}
			break;
		case 2:
			printf("\n Digite o nome do Aluno:");
			scanf_s("%s", nome_aux);
			while ((c = getchar()) != '\n' && c != EOF) {} // limpando o buffer do teclado.
			while (prox_cad != NULL) {
				if (strcmp(prox_cad->nome, nome_aux) == 0)
				{
					printf("ru: %d\n nome: %s\n email: %s", prox_cad->ru, prox_cad->nome, prox_cad->email);
					break;
				}
				prox_cad = prox_cad->proximo;
			}
			break;

		default:
			printf("\n****Opcao invalida*****");
			break;
		}
	} while (1);//Condicionais para chamada das funções
}