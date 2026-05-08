#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_NOME 50
#define TAM_EMAIL 50

#define TAM_CABECALHO ( (sizeof(int)*5) + (TAM_NOME * sizeof(char)) + (TAM_EMAIL * sizeof(char)) )

#define TAM_PESSOA ( sizeof(int) + (TAM_NOME * sizeof(char)) + (TAM_EMAIL * sizeof(char)) )

void* AdicionarPessoa(void *pBuffer) {
 
    int *opcao = (int *)pBuffer;
    int *total = opcao + 1; // Anda 4 bytes para frente
    int *i = total + 1;
    int *posEncontrada = i + 1;
    int *idadeTemp = posEncontrada + 1;
    char *nomeTemp = (char *)(idadeTemp + 1);
    char *emailTemp = nomeTemp + TAM_NOME;

    printf("Nome: ");
    scanf(" %49[^\n]", nomeTemp);
    printf("Idade: ");
    scanf("%d", idadeTemp);
    printf("Email: ");
    scanf(" %49[^\n]", emailTemp);

    *total = *total + 1; 

    pBuffer = realloc(pBuffer, TAM_CABECALHO + (*total * TAM_PESSOA));

    opcao = (int *)pBuffer;
    total = opcao + 1;
    i = total + 1;
    posEncontrada = i + 1;
    idadeTemp = posEncontrada + 1;
    nomeTemp = (char *)(idadeTemp + 1);
    emailTemp = nomeTemp + TAM_NOME;

    *i = *total - 1;
    char *registro = (char *)pBuffer + TAM_CABECALHO + (*i * TAM_PESSOA);

    int *idadeDestino = (int *)registro;
    char *nomeDestino = (char *)(idadeDestino + 1);
    char *emailDestino = nomeDestino + TAM_NOME;


    *idadeDestino = *idadeTemp;
    strcpy(nomeDestino, nomeTemp);
    strcpy(emailDestino, emailTemp);

    printf("\nPessoa adicionada com sucesso!\n\n");
    return pBuffer;
}

void* ListarTodos(void *pBuffer) {
    int *opcao = (int *)pBuffer;
    int *total = opcao + 1;
    int *i = total + 1;

    if (*total == 0) {
        printf("\nA agenda esta vazia.\n\n");
        return pBuffer;
    }

    printf("\n--- Lista de Contatos ---\n");
    for (*i = 0; *i < *total; *i = *i + 1) {

        char *registro = (char *)pBuffer + TAM_CABECALHO + (*i * TAM_PESSOA);
        
        int *idade = (int *)registro;
        char *nome = (char *)(idade + 1);
        char *email = nome + TAM_NOME;

        printf("[%d] Nome: %s | Idade: %d | Email: %s\n", *i + 1, nome, *idade, email);
    }
    printf("-------------------------\n\n");
    
    return pBuffer;
}

void* BuscarPessoa(void *pBuffer) {
    int *opcao = (int *)pBuffer;
    int *total = opcao + 1;
    int *i = total + 1;
    int *posEncontrada = i + 1;
    int *idadeTemp = posEncontrada + 1;
    char *nomeTemp = (char *)(idadeTemp + 1);

    if (*total == 0) {
        printf("\nA agenda esta vazia.\n\n");
        return pBuffer;
    }

    printf("Digite o nome para buscar: ");
    scanf(" %49[^\n]", nomeTemp);

    *posEncontrada = -1; 

    for (*i = 0; *i < *total; *i = *i + 1) {
        char *registro = (char *)pBuffer + TAM_CABECALHO + (*i * TAM_PESSOA);
        
        int *idade = (int *)registro;
        char *nome = (char *)(idade + 1);
        char *email = nome + TAM_NOME;

        if (strcmp(nome, nomeTemp) == 0) {
            printf("\nEncontrado: Nome: %s | Idade: %d | Email: %s\n\n", nome, *idade, email);
            *posEncontrada = *i;
            break;
        }
    }

    if (*posEncontrada == -1) {
        printf("\nPessoa nao encontrada.\n\n");
    }
    
    return pBuffer;
}

void* RemoverPessoa(void *pBuffer) {
    int *opcao = (int *)pBuffer;
    int *total = opcao + 1;
    int *i = total + 1;
    int *posEncontrada = i + 1;
    int *idadeTemp = posEncontrada + 1;
    char *nomeTemp = (char *)(idadeTemp + 1);

    if (*total == 0) {
        printf("\nA agenda esta vazia.\n\n");
        return pBuffer;
    }

    printf("Digite o nome da pessoa para remover: ");
    scanf(" %49[^\n]", nomeTemp);

    *posEncontrada = -1;

    for (*i = 0; *i < *total; *i = *i + 1) {
        char *registro = (char *)pBuffer + TAM_CABECALHO + (*i * TAM_PESSOA);
        int *idade = (int *)registro;
        char *nome = (char *)(idade + 1);

        if (strcmp(nome, nomeTemp) == 0) {
            *posEncontrada = *i;
            break;
        }
    }

    if (*posEncontrada != -1) {
        for (*i = *posEncontrada; *i < *total - 1; *i = *i + 1) {
            char *registroAtual = (char *)pBuffer + TAM_CABECALHO + (*i * TAM_PESSOA);
            char *registroProximo = (char *)pBuffer + TAM_CABECALHO + ((*i + 1) * TAM_PESSOA);

            int *idadeAtual = (int *)registroAtual;
            char *nomeAtual = (char *)(idadeAtual + 1);
            char *emailAtual = nomeAtual + TAM_NOME;

            int *idadeProximo = (int *)registroProximo;
            char *nomeProximo = (char *)(idadeProximo + 1);
            char *emailProximo = nomeProximo + TAM_NOME;

            *idadeAtual = *idadeProximo;
            strcpy(nomeAtual, nomeProximo);
            strcpy(emailAtual, emailProximo);
        }

        *total = *total - 1;
        pBuffer = realloc(pBuffer, TAM_CABECALHO + (*total * TAM_PESSOA)); 
        
        printf("\nPessoa removida com sucesso!\n\n");
    } else {
        printf("\nPessoa nao encontrada.\n\n");
    }

    return pBuffer;
}

int main() {

    void *pBuffer = malloc(TAM_CABECALHO);
    if (pBuffer == NULL) {
        printf("Erro de memoria!\n");
        return 1;
    }

    int *opcao = (int *)pBuffer;
    int *total = opcao + 1;
    
    *total = 0; 

    while (1) {
        printf("1- Adicionar Pessoa\n");
        printf("2- Remover Pessoa\n");
        printf("3- Buscar Pessoa\n");
        printf("4- Listar todos\n");
        printf("5- Sair\n");
        printf("Escolha: ");
        
    
        opcao = (int *)pBuffer; 
        scanf("%d", opcao);

        if (*opcao == 1) {
            pBuffer = AdicionarPessoa(pBuffer);
        } else if (*opcao == 2) {
            pBuffer = RemoverPessoa(pBuffer);
        } else if (*opcao == 3) {
            pBuffer = BuscarPessoa(pBuffer);
        } else if (*opcao == 4) {
            pBuffer = ListarTodos(pBuffer);
        } else if (*opcao == 5) {
            break;
        } else {
            printf("Opcao invalida!\n\n");
        }
    }

    free(pBuffer);
    return 0;
}