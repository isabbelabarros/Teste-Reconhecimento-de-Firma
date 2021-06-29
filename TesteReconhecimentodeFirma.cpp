#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/* Isabela */

/* Objetivo: Desenvolver um programa para emissão de etiquetas de reconhecimento de firmas. Deverá solicitar os dados, salvá-los e imprimi-los na tela, simulando uma etiqueta. */

#define MAX 50
#define CPF 12

typedef struct pessoa{
	char nome[MAX];
	char cpf[CPF];
}Pessoa[MAX];

typedef struct reconhecimento{
	int dia;
	int mes;
	int ano;
	char tipo;
	int qtde;
	char isento;
	Pessoa pessoa;
	int qtd;
}Reconhecimento;

typedef struct no{
	Reconhecimento novo;
	no *anterior;
	no *proximo;
}No;

typedef struct lista{
	No *primeiro;
	No *ultimo;
}Lista;

//Função que devolve uma referência para a lista
Lista *inicializa(){
	lista *lista = (Lista *)malloc(sizeof(Lista));
	lista->primeiro = NULL;
	lista->ultimo = NULL;
	return lista;
}

//Função que exibe a etiqueta na tela
void exibeEtiqueta(Lista *lista, No *ptr){
	int i, j;
	system("cls");
	for(i=0;i<ptr->novo.qtde;i++){
		printf("-----------------------------------------------\n");
		printf ("RECONHECIMENTO DE FIRMAS\n");
		if(ptr->novo.tipo == 'A' && ptr->novo.isento == 'S'){
			printf("Reconheço por autenticidade a(s) firma(s) de:\n");
			for(j=0;j<=ptr->novo.qtd;j++){
				if((j+1)%3 == 0 && j<=ptr->novo.qtd-1 && j>0){
					printf("%s\n", ptr->novo.pessoa[j].nome);
					printf("Pará de Minas, %i/%i/%i\n", ptr->novo.dia, ptr->novo.mes, ptr->novo.ano);
					printf("Isento de Emolumentos\n");
					printf("-----------------------------------------------\n\n");
					printf("-----------------------------------------------\n");
					printf ("RECONHECIMENTO DE FIRMAS\n");
					printf("Reconheço por autenticidade a(s) firma(s) de:\n");
				}else{
					printf("%s\n", ptr->novo.pessoa[j].nome);
				}	
			}
			printf("Pará de Minas, %i/%i/%i\n", ptr->novo.dia, ptr->novo.mes, ptr->novo.ano);
			printf("Isento de Emolumentos\n");
			printf("-----------------------------------------------\n\n");
		}else if(ptr->novo.tipo == 'A' && ptr->novo.isento == 'N'){
			printf("Reconheço por autenticidade a(s) firma(s) de:\n");
			for(j=0;j<=ptr->novo.qtd;j++){
				if((j+1)%3 == 0 && j<=ptr->novo.qtd-1 && j>0){
					printf("%s\n", ptr->novo.pessoa[j].nome);
					printf("Pará de Minas, %i/%i/%i\n", ptr->novo.dia, ptr->novo.mes, ptr->novo.ano);
					printf("Isento de Emolumentos\n");
					printf("-----------------------------------------------\n\n");
					printf("-----------------------------------------------\n");
					printf ("RECONHECIMENTO DE FIRMAS\n");
					printf("Reconheço por autenticidade a(s) firma(s) de:\n");
				}else{
					printf("%s\n", ptr->novo.pessoa[j].nome);
				}	
			}
			printf("Pará de Minas, %i/%i/%i\n", ptr->novo.dia, ptr->novo.mes, ptr->novo.ano);
			printf("Emolumento cobrado\n");
			printf("-----------------------------------------------\n\n");
		}else if(ptr->novo.tipo == 'B' && ptr->novo.isento == 'S'){
			printf("Reconheço por semelhança a(s) firma(s) de:\n");
			for(j=0;j<=ptr->novo.qtd;j++){
				if((j+1)%3 == 0 && j<=ptr->novo.qtd-1 && j>0){
					printf("%s\n", ptr->novo.pessoa[j].nome);
					printf("Pará de Minas, %i/%i/%i\n", ptr->novo.dia, ptr->novo.mes, ptr->novo.ano);
					printf("Isento de Emolumentos\n");
					printf("-----------------------------------------------\n\n");
					printf("-----------------------------------------------\n");
					printf ("RECONHECIMENTO DE FIRMAS\n");
					printf("Reconheço por autenticidade a(s) firma(s) de:\n");
				}else{
					printf("%s\n", ptr->novo.pessoa[j].nome);
				}	
			}
			printf("Pará de Minas, %i/%i/%i\n", ptr->novo.dia, ptr->novo.mes, ptr->novo.ano);
			printf("Isento de Emolumentos\n");
			printf("-----------------------------------------------\n\n");
		}else if(ptr->novo.tipo == 'B' && ptr->novo.isento == 'N'){
			printf("Reconheço por semelhança a(s) firma(s) de:\n");
			for(j=0;j<=ptr->novo.qtd;j++){
				if((j+1)%3 == 0 && j<=ptr->novo.qtd-1 && j>0){
					printf("%s\n", ptr->novo.pessoa[j].nome);
					printf("Pará de Minas, %i/%i/%i\n", ptr->novo.dia, ptr->novo.mes, ptr->novo.ano);
					printf("Isento de Emolumentos\n");
					printf("-----------------------------------------------\n\n");
					printf("-----------------------------------------------\n");
					printf ("RECONHECIMENTO DE FIRMAS\n");
					printf("Reconheço por autenticidade a(s) firma(s) de:\n");
				}else{
					printf("%s\n", ptr->novo.pessoa[j].nome);
				}	
			}
			printf("Pará de Minas, %i/%i/%i\n", ptr->novo.dia, ptr->novo.mes, ptr->novo.ano);
			printf("Emolumento cobrado\n");
			printf("-----------------------------------------------\n\n");
		}	
	}
}

//Função que insere um reconhecimento novo
void insereReconhecimento(Lista *lista, Reconhecimento novo){
	int i, j;
	char opcao = 'S';
	No *no = (No *)malloc(sizeof(No));
	no->novo.qtd = 0;
	printf("DATA:\n");
	printf("Dia: ");
	fflush(stdin);
	scanf("%i", &no->novo.dia);
	while(no->novo.dia<=0 || no->novo.dia>31){
		printf("Dia inválido! Digite o dia correto, por gentileza (de 1 a 31).\n");
		printf("Dia: ");
		fflush(stdin);
		scanf("%i", &no->novo.dia);
	}
	printf("Mês: ");
	fflush(stdin);
	scanf("%i", &no->novo.mes);
	while(no->novo.mes<=0 || no->novo.mes>12){
		printf("Mês inválido! Digite o mês correto, por gentileza (de 1 a 12).\n");
		printf("Mês: ");
		fflush(stdin);
		scanf("%i", &no->novo.mes);
	}
	printf("Ano: ");
	fflush(stdin);
	scanf("%i", &no->novo.ano);
	printf("Tipo (Digite [A] para Autenticidade e [B] para Semelhança): ");
	fflush(stdin);
	scanf("%c", &no->novo.tipo);
	while(no->novo.tipo != 'A' && no->novo.tipo != 'B' && no->novo.tipo != 'a' && no->novo.tipo != 'b'){
		printf("Opção inválida! Digite a opção correta, por gentileza.\n");
		printf("Tipo (Digite [A] para Autenticidade e [B] para Semelhança): ");
		fflush(stdin);
		scanf("%c", &no->novo.tipo);
	}
	printf("Quantidade de etiquetas: ");
	scanf("%i", &no->novo.qtde);
	printf("É isento? [S/N] ");
	fflush(stdin);
	scanf("%c", &no->novo.isento);
	while(no->novo.isento != 'S' && no->novo.isento != 'N' && no->novo.isento != 's' && no->novo.isento != 'n'){
		printf("Opção inválida! Digite a opção correta, por gentileza.\n");
		printf("É isento? [S/N] ");
		fflush(stdin);
		scanf("%c", &no->novo.isento);
	}
	printf ("Nome: ");
	fflush(stdin);
	scanf ("%[^\n]s", no->novo.pessoa[no->novo.qtd].nome);
	printf ("CPF (somente números): ");
	fflush(stdin);
	scanf ("%s", &no->novo.pessoa[no->novo.qtd].cpf);
	printf("Deseja adicionar mais um nome? [S/N] ");
	fflush(stdin);
	scanf("%c", &opcao);
	while(opcao != 'S' && opcao != 'N' && opcao != 's' && opcao != 'n'){
		printf("Opção inválida! Digite a opção correta, por gentileza.\n");
		printf("Deseja adicionar mais um nome? [S/N] ");
		fflush(stdin);
		scanf("%c", &opcao);
	}
	while(opcao == 'S' || opcao == 's'){
		no->novo.qtd++;
		printf ("Nome: ");
		fflush(stdin);
		scanf ("%[^\n]s", no->novo.pessoa[no->novo.qtd].nome);
		printf ("CPF (somente números): ");
		fflush(stdin);
		scanf ("%s", &no->novo.pessoa[no->novo.qtd].cpf);
		fflush(stdin);
		printf("Deseja adicionar mais um nome? [S/N] ");
		fflush(stdin);
		scanf("%c", &opcao);
			while(opcao != 'S' && opcao != 'N' && opcao != 's' && opcao != 'n'){
			printf("Opção inválida! Digite a opção correta, por gentileza.\n");
			printf("Deseja adicionar mais um nome? [S/N] ");
			fflush(stdin);
			scanf("%c", &opcao);
		}
	}
	//A próxima posição recebe NULL
	no->proximo = NULL;
	//Se não houver ninguém cadastrado, adiciona o reconhecimento na 1ª posição
	if(lista->primeiro == NULL){
		lista->primeiro = no;
	//Se não...
	}else{
		//... o nó que estava no fim da fila precisa apontar para o nó que foi adicionado (novo fim da fila). 
		lista->ultimo->proximo = no;
	}
	//O final sempre vai ser o último reconhecimento cadastrado.
	lista->ultimo = no;
	exibeEtiqueta(lista, no);
}

//Função que exclui um reconhecimento
void excluiReconhecimento(Lista *lista){
	int j;
	No *anterior = NULL;
    No *atual = lista->primeiro;
    char cpfreconhecimento[CPF];
    if(atual==NULL){
		printf ("Não há reconhecimentos cadastrados.\n");
	}else{
	    printf("CPF do reconhecimento a ser excluído (somente números): ");
	    fflush(stdin);
	    scanf("%s", cpfreconhecimento);
	    fflush(stdin);    
		while(atual != NULL && (strcmp(atual->novo.pessoa[j].cpf, cpfreconhecimento) != 0)){
			j = 0;
			while(j<atual->novo.qtd && (strcmp(atual->novo.pessoa[j].cpf, cpfreconhecimento) != 0)){
				j++;
			}
			if((strcmp(atual->novo.pessoa[j].cpf, cpfreconhecimento) != 0)){
				anterior = atual;
				atual = atual->proximo;
			}
		}
	    if(atual==NULL){
	        printf("CPF não encontrado.\n"); 
	     //Se o reconhecimento a ser excluído for o primeiro da lista, a primeira posição recebe o valor da próxima posição
		}else{
			if(anterior==NULL && atual->proximo != NULL){
		  		printf("Registro do reconhecimento excluído com sucesso.\n"); 
		    	lista->primeiro = atual->proximo;
		 	//Se não for, a posição do reconhecimento que será excluído recebe a próxima posição
		 	}else if(anterior == NULL){
		 		lista->primeiro = NULL;
		 		lista->ultimo = NULL;
		 		printf("Registro do reconhecimento excluído com sucesso.\n");
			}else{
				//A posição atual recebe o próximo
				anterior->proximo = atual->proximo;
		    	printf("Registro do reconhecimento excluído com sucesso.\n");
			}
	 	}
	 	free(atual);
	}
}

//Função reimprime uma etiqueta
void reimprimeReconhecimento(Lista *lista){
	int i = 0, tamanho = 0, cont;
	No *ptr = lista->primeiro;
	char reimprimereconhecimento[CPF];
	if(ptr==NULL){
		printf ("Não há reconhecimentos cadastrados.\n");
	}else{
		printf ("Você deseja reimprimir o reconhecimento vinculado a qual CPF? (Somente números) ");
		scanf ("%s", &reimprimereconhecimento);
		fflush(stdin);
		while(ptr != NULL){
			cont = 0;
			while(cont<ptr->novo.qtd && (strcmp(ptr->novo.pessoa[cont].cpf, reimprimereconhecimento) != 0)){
				cont++;
			}
				if((strcmp(ptr->novo.pessoa[cont].cpf, reimprimereconhecimento) == 0)){
					tamanho = ptr->novo.qtde-1;
					printf("Você deseja imprimir quantas etiquetas? ");
					scanf("%i", &ptr->novo.qtde);
					exibeEtiqueta(lista, ptr);
					break;
				}else{
					ptr = ptr->proximo;
				}
			if(ptr == NULL){
				printf("Reconhecimento não encontrado.\n");
			}
		}
	}
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	Reconhecimento novo;
	char opcao = 'S', escolha;
	Lista *lista = inicializa();
	do{
		system("cls");
		printf("*** LISTA DE OPÇÕES - CARTÓRIO DO RECONHECIMENTO DO BRASIL ***\n");
		printf("Digite a opção desejada:\n");
		printf("a. Novo Reconhecimento de Firma\n");
		printf("b. Excluir Reconhecimento de Firma\n");
		printf("c. Reimprimir etiqueta\n");
		printf("d. Finalizar o programa\n\n");
		scanf ("%c", &escolha);
		fflush(stdin);
		switch(escolha){
			case 'a':
				insereReconhecimento(lista, novo);
			break;
			case 'b':
				excluiReconhecimento(lista);
				break;
			case 'c':
				reimprimeReconhecimento(lista);
				break;
			case 'd':
				printf ("Programa finalizado.\n");
				exit(0);
				break;
			default:
				printf ("Opção inválida!\n");
			break;
		}
		printf ("Deseja realizar uma nova operação?(S/N)\n");
		fflush(stdin);
		scanf ("%c", &opcao);
		fflush(stdin);
	} while (opcao == 'S' || opcao == 's');
	system("pause");
	return 0;
}
