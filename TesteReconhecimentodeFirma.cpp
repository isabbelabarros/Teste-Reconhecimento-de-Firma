#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

/* Isabela */

/* Objetivo: Desenvolver um programa para emiss�o de etiquetas de reconhecimento de firmas. Dever� solicitar os dados, salv�-los e imprimi-los na tela, simulando uma etiqueta. */

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

//Fun��o que devolve uma refer�ncia para a lista
Lista *inicializa(){
	lista *lista = (Lista *)malloc(sizeof(Lista));
	lista->primeiro = NULL;
	lista->ultimo = NULL;
	return lista;
}

//Fun��o que exibe a etiqueta na tela
void exibeEtiqueta(Lista *lista, No *ptr){
	int i, j;
	system("cls");
	for(i=0;i<ptr->novo.qtde;i++){
		printf("-----------------------------------------------\n");
		printf ("RECONHECIMENTO DE FIRMAS\n");
		if(ptr->novo.tipo == 'A' && ptr->novo.isento == 'S'){
			printf("Reconhe�o por autenticidade a(s) firma(s) de:\n");
			for(j=0;j<=ptr->novo.qtd;j++){
				if((j+1)%3 == 0 && j<=ptr->novo.qtd-1 && j>0){
					printf("%s\n", ptr->novo.pessoa[j].nome);
					printf("Par� de Minas, %i/%i/%i\n", ptr->novo.dia, ptr->novo.mes, ptr->novo.ano);
					printf("Isento de Emolumentos\n");
					printf("-----------------------------------------------\n\n");
					printf("-----------------------------------------------\n");
					printf ("RECONHECIMENTO DE FIRMAS\n");
					printf("Reconhe�o por autenticidade a(s) firma(s) de:\n");
				}else{
					printf("%s\n", ptr->novo.pessoa[j].nome);
				}	
			}
			printf("Par� de Minas, %i/%i/%i\n", ptr->novo.dia, ptr->novo.mes, ptr->novo.ano);
			printf("Isento de Emolumentos\n");
			printf("-----------------------------------------------\n\n");
		}else if(ptr->novo.tipo == 'A' && ptr->novo.isento == 'N'){
			printf("Reconhe�o por autenticidade a(s) firma(s) de:\n");
			for(j=0;j<=ptr->novo.qtd;j++){
				if((j+1)%3 == 0 && j<=ptr->novo.qtd-1 && j>0){
					printf("%s\n", ptr->novo.pessoa[j].nome);
					printf("Par� de Minas, %i/%i/%i\n", ptr->novo.dia, ptr->novo.mes, ptr->novo.ano);
					printf("Isento de Emolumentos\n");
					printf("-----------------------------------------------\n\n");
					printf("-----------------------------------------------\n");
					printf ("RECONHECIMENTO DE FIRMAS\n");
					printf("Reconhe�o por autenticidade a(s) firma(s) de:\n");
				}else{
					printf("%s\n", ptr->novo.pessoa[j].nome);
				}	
			}
			printf("Par� de Minas, %i/%i/%i\n", ptr->novo.dia, ptr->novo.mes, ptr->novo.ano);
			printf("Emolumento cobrado\n");
			printf("-----------------------------------------------\n\n");
		}else if(ptr->novo.tipo == 'B' && ptr->novo.isento == 'S'){
			printf("Reconhe�o por semelhan�a a(s) firma(s) de:\n");
			for(j=0;j<=ptr->novo.qtd;j++){
				if((j+1)%3 == 0 && j<=ptr->novo.qtd-1 && j>0){
					printf("%s\n", ptr->novo.pessoa[j].nome);
					printf("Par� de Minas, %i/%i/%i\n", ptr->novo.dia, ptr->novo.mes, ptr->novo.ano);
					printf("Isento de Emolumentos\n");
					printf("-----------------------------------------------\n\n");
					printf("-----------------------------------------------\n");
					printf ("RECONHECIMENTO DE FIRMAS\n");
					printf("Reconhe�o por autenticidade a(s) firma(s) de:\n");
				}else{
					printf("%s\n", ptr->novo.pessoa[j].nome);
				}	
			}
			printf("Par� de Minas, %i/%i/%i\n", ptr->novo.dia, ptr->novo.mes, ptr->novo.ano);
			printf("Isento de Emolumentos\n");
			printf("-----------------------------------------------\n\n");
		}else if(ptr->novo.tipo == 'B' && ptr->novo.isento == 'N'){
			printf("Reconhe�o por semelhan�a a(s) firma(s) de:\n");
			for(j=0;j<=ptr->novo.qtd;j++){
				if((j+1)%3 == 0 && j<=ptr->novo.qtd-1 && j>0){
					printf("%s\n", ptr->novo.pessoa[j].nome);
					printf("Par� de Minas, %i/%i/%i\n", ptr->novo.dia, ptr->novo.mes, ptr->novo.ano);
					printf("Isento de Emolumentos\n");
					printf("-----------------------------------------------\n\n");
					printf("-----------------------------------------------\n");
					printf ("RECONHECIMENTO DE FIRMAS\n");
					printf("Reconhe�o por autenticidade a(s) firma(s) de:\n");
				}else{
					printf("%s\n", ptr->novo.pessoa[j].nome);
				}	
			}
			printf("Par� de Minas, %i/%i/%i\n", ptr->novo.dia, ptr->novo.mes, ptr->novo.ano);
			printf("Emolumento cobrado\n");
			printf("-----------------------------------------------\n\n");
		}	
	}
}

//Fun��o que insere um reconhecimento novo
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
		printf("Dia inv�lido! Digite o dia correto, por gentileza (de 1 a 31).\n");
		printf("Dia: ");
		fflush(stdin);
		scanf("%i", &no->novo.dia);
	}
	printf("M�s: ");
	fflush(stdin);
	scanf("%i", &no->novo.mes);
	while(no->novo.mes<=0 || no->novo.mes>12){
		printf("M�s inv�lido! Digite o m�s correto, por gentileza (de 1 a 12).\n");
		printf("M�s: ");
		fflush(stdin);
		scanf("%i", &no->novo.mes);
	}
	printf("Ano: ");
	fflush(stdin);
	scanf("%i", &no->novo.ano);
	printf("Tipo (Digite [A] para Autenticidade e [B] para Semelhan�a): ");
	fflush(stdin);
	scanf("%c", &no->novo.tipo);
	while(no->novo.tipo != 'A' && no->novo.tipo != 'B' && no->novo.tipo != 'a' && no->novo.tipo != 'b'){
		printf("Op��o inv�lida! Digite a op��o correta, por gentileza.\n");
		printf("Tipo (Digite [A] para Autenticidade e [B] para Semelhan�a): ");
		fflush(stdin);
		scanf("%c", &no->novo.tipo);
	}
	printf("Quantidade de etiquetas: ");
	scanf("%i", &no->novo.qtde);
	printf("� isento? [S/N] ");
	fflush(stdin);
	scanf("%c", &no->novo.isento);
	while(no->novo.isento != 'S' && no->novo.isento != 'N' && no->novo.isento != 's' && no->novo.isento != 'n'){
		printf("Op��o inv�lida! Digite a op��o correta, por gentileza.\n");
		printf("� isento? [S/N] ");
		fflush(stdin);
		scanf("%c", &no->novo.isento);
	}
	printf ("Nome: ");
	fflush(stdin);
	scanf ("%[^\n]s", no->novo.pessoa[no->novo.qtd].nome);
	printf ("CPF (somente n�meros): ");
	fflush(stdin);
	scanf ("%s", &no->novo.pessoa[no->novo.qtd].cpf);
	printf("Deseja adicionar mais um nome? [S/N] ");
	fflush(stdin);
	scanf("%c", &opcao);
	while(opcao != 'S' && opcao != 'N' && opcao != 's' && opcao != 'n'){
		printf("Op��o inv�lida! Digite a op��o correta, por gentileza.\n");
		printf("Deseja adicionar mais um nome? [S/N] ");
		fflush(stdin);
		scanf("%c", &opcao);
	}
	while(opcao == 'S' || opcao == 's'){
		no->novo.qtd++;
		printf ("Nome: ");
		fflush(stdin);
		scanf ("%[^\n]s", no->novo.pessoa[no->novo.qtd].nome);
		printf ("CPF (somente n�meros): ");
		fflush(stdin);
		scanf ("%s", &no->novo.pessoa[no->novo.qtd].cpf);
		fflush(stdin);
		printf("Deseja adicionar mais um nome? [S/N] ");
		fflush(stdin);
		scanf("%c", &opcao);
			while(opcao != 'S' && opcao != 'N' && opcao != 's' && opcao != 'n'){
			printf("Op��o inv�lida! Digite a op��o correta, por gentileza.\n");
			printf("Deseja adicionar mais um nome? [S/N] ");
			fflush(stdin);
			scanf("%c", &opcao);
		}
	}
	//A pr�xima posi��o recebe NULL
	no->proximo = NULL;
	//Se n�o houver ningu�m cadastrado, adiciona o reconhecimento na 1� posi��o
	if(lista->primeiro == NULL){
		lista->primeiro = no;
	//Se n�o...
	}else{
		//... o n� que estava no fim da fila precisa apontar para o n� que foi adicionado (novo fim da fila). 
		lista->ultimo->proximo = no;
	}
	//O final sempre vai ser o �ltimo reconhecimento cadastrado.
	lista->ultimo = no;
	exibeEtiqueta(lista, no);
}

//Fun��o que exclui um reconhecimento
void excluiReconhecimento(Lista *lista){
	int j;
	No *anterior = NULL;
    No *atual = lista->primeiro;
    char cpfreconhecimento[CPF];
    if(atual==NULL){
		printf ("N�o h� reconhecimentos cadastrados.\n");
	}else{
	    printf("CPF do reconhecimento a ser exclu�do (somente n�meros): ");
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
	        printf("CPF n�o encontrado.\n"); 
	     //Se o reconhecimento a ser exclu�do for o primeiro da lista, a primeira posi��o recebe o valor da pr�xima posi��o
		}else{
			if(anterior==NULL && atual->proximo != NULL){
		  		printf("Registro do reconhecimento exclu�do com sucesso.\n"); 
		    	lista->primeiro = atual->proximo;
		 	//Se n�o for, a posi��o do reconhecimento que ser� exclu�do recebe a pr�xima posi��o
		 	}else if(anterior == NULL){
		 		lista->primeiro = NULL;
		 		lista->ultimo = NULL;
		 		printf("Registro do reconhecimento exclu�do com sucesso.\n");
			}else{
				//A posi��o atual recebe o pr�ximo
				anterior->proximo = atual->proximo;
		    	printf("Registro do reconhecimento exclu�do com sucesso.\n");
			}
	 	}
	 	free(atual);
	}
}

//Fun��o reimprime uma etiqueta
void reimprimeReconhecimento(Lista *lista){
	int i = 0, tamanho = 0, cont;
	No *ptr = lista->primeiro;
	char reimprimereconhecimento[CPF];
	if(ptr==NULL){
		printf ("N�o h� reconhecimentos cadastrados.\n");
	}else{
		printf ("Voc� deseja reimprimir o reconhecimento vinculado a qual CPF? (Somente n�meros) ");
		scanf ("%s", &reimprimereconhecimento);
		fflush(stdin);
		while(ptr != NULL){
			cont = 0;
			while(cont<ptr->novo.qtd && (strcmp(ptr->novo.pessoa[cont].cpf, reimprimereconhecimento) != 0)){
				cont++;
			}
				if((strcmp(ptr->novo.pessoa[cont].cpf, reimprimereconhecimento) == 0)){
					tamanho = ptr->novo.qtde-1;
					printf("Voc� deseja imprimir quantas etiquetas? ");
					scanf("%i", &ptr->novo.qtde);
					exibeEtiqueta(lista, ptr);
					break;
				}else{
					ptr = ptr->proximo;
				}
			if(ptr == NULL){
				printf("Reconhecimento n�o encontrado.\n");
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
		printf("*** LISTA DE OP��ES - CART�RIO DO RECONHECIMENTO DO BRASIL ***\n");
		printf("Digite a op��o desejada:\n");
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
				printf ("Op��o inv�lida!\n");
			break;
		}
		printf ("Deseja realizar uma nova opera��o?(S/N)\n");
		fflush(stdin);
		scanf ("%c", &opcao);
		fflush(stdin);
	} while (opcao == 'S' || opcao == 's');
	system("pause");
	return 0;
}
