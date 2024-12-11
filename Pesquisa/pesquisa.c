#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME 50

typedef struct {
    int idPassageiro;
    char nome[MAX_NOME];
} Passageiros;

// Função para limpar buffer do teclado
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// Função para registrar passageiros
void registrandoPassageiros(Passageiros *passageiros, int tam_passageiros) {
    for (int i = 0; i < tam_passageiros; i++) {
        passageiros[i].idPassageiro = i + 1;

        do {
            printf("Insira o nome do passageiro %d: \n", i + 1);
            if (i == 0) limparBuffer(); // Limpar buffer antes do primeiro `fgets`
            fgets(passageiros[i].nome, MAX_NOME, stdin);
            passageiros[i].nome[strcspn(passageiros[i].nome, "\n")] = '\0'; // Remove o '\n'

            if (strlen(passageiros[i].nome) == 0 || strspn(passageiros[i].nome, " ") == strlen(passageiros[i].nome)) {
                printf("Nome inválido. Tente novamente.\n");
            }
        } while (strlen(passageiros[i].nome) == 0 || strspn(passageiros[i].nome, " ") == strlen(passageiros[i].nome));
    }
}

// Função para buscar passageiros pelo nome
void buscarPassageiroPorNome(Passageiros *passageiros, int tam_passageiros, char *nomeBuscado) {
    printf("Resultados da busca pelo nome \"%s\":\n", nomeBuscado);
    int encontrado = 0;
    for (int i = 0; i < tam_passageiros; i++) {
        if (strcmp(passageiros[i].nome, nomeBuscado) == 0) {
            printf("Passageiro encontrado: ID: %d, Nome: %s\n", passageiros[i].idPassageiro, passageiros[i].nome);
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("Nenhum passageiro encontrado com o nome \"%s\".\n", nomeBuscado);
    }
}

// Função para buscar passageiros pelo ID
void buscarPassageiroPorID(Passageiros *passageiros, int tam_passageiros, int idBuscado) {
    for (int i = 0; i < tam_passageiros; i++) {
        if (passageiros[i].idPassageiro == idBuscado) {
            printf("Passageiro encontrado: ID: %d, Nome: %s\n", passageiros[i].idPassageiro, passageiros[i].nome);
            return;
        }
    }
    printf("Nenhum passageiro encontrado com o ID %d.\n", idBuscado);
}

// Função para listar todos os passageiros
void listarTodosPassageiros(Passageiros *passageiros, int tam_passageiros) {
    printf("\nLista de Passageiros:\n");
    for (int i = 0; i < tam_passageiros; i++) {
        printf("ID: %d, Nome: %s\n", passageiros[i].idPassageiro, passageiros[i].nome);
    }
}

// Função principal
int main() {
    int TAM_PASSAGEIROS;

    printf("Insira a quantidade de passageiros: \n");
    scanf("%d", &TAM_PASSAGEIROS);

    if (TAM_PASSAGEIROS <= 0) {
        printf("Quantidade inválida de passageiros. O programa será encerrado.\n");
        return 1;
    }

    // Alocação dinâmica para passageiros
    Passageiros *passageiros = malloc(TAM_PASSAGEIROS * sizeof(Passageiros));
    if (!passageiros) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    // Registrar passageiros
    registrandoPassageiros(passageiros, TAM_PASSAGEIROS);

    // Menu interativo
    int opcao;
    do {
        printf("\n--- Menu ---\n");
        printf("1. Listar todos os passageiros\n");
        printf("2. Buscar passageiro por nome\n");
        printf("3. Buscar passageiro por ID\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                listarTodosPassageiros(passageiros, TAM_PASSAGEIROS);
                break;
            case 2: {
                char nomeBuscado[MAX_NOME];
                printf("Digite o nome do passageiro para buscar: ");
                limparBuffer(); // Garante que o buffer esteja limpo
                fgets(nomeBuscado, MAX_NOME, stdin);
                nomeBuscado[strcspn(nomeBuscado, "\n")] = '\0';
                buscarPassageiroPorNome(passageiros, TAM_PASSAGEIROS, nomeBuscado);
                break;
            }
            case 3: {
                int idBuscado;
                printf("Digite o ID do passageiro para buscar: ");
                scanf("%d", &idBuscado);
                buscarPassageiroPorID(passageiros, TAM_PASSAGEIROS, idBuscado);
                break;
            }
            case 4:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    // Liberar memória
    free(passageiros);

    printf("Obrigado por usar o sistema. Até logo!\n");
    return 0;
}
