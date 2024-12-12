#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRIPULACAO 999

typedef struct {
    int id;
    char nome[25];
    int cargo; // 1: Piloto, 2: Copiloto, 3: Comissario
    char telefone[14];
} Tripulacao;

Tripulacao tripulacao[MAX_TRIPULACAO];
int quantidadeTripulacao = 0; 

void registrarTripulacao() {
    if (quantidadeTripulacao < MAX_TRIPULACAO) {
        Tripulacao novaTripulacao;

        novaTripulacao.id = quantidadeTripulacao + 1;

        getchar();

        printf("Digite o nome do tripulante: ");
        fgets(novaTripulacao.nome, sizeof(novaTripulacao.nome), stdin);
        novaTripulacao.nome[strcspn(novaTripulacao.nome, "\n")] = '\0';

        printf("Selecione o cargo do tripulante: \n");
        printf("[1] Piloto\n[2] Copiloto\n[3] Comissario\n");
        scanf("%d", &novaTripulacao.cargo);

        while (novaTripulacao.cargo < 1 || novaTripulacao.cargo > 3) {
            printf("Opcao invalida! Tente novamente.\n");
            printf("[1] Piloto\n[2] Copiloto\n[3] Comissario\n");
            scanf("%d", &novaTripulacao.cargo);
        }

        getchar(); // Limpa o buffer do teclado

        printf("Digite o telefone do tripulante: ");
        fgets(novaTripulacao.telefone, sizeof(novaTripulacao.telefone), stdin);
        novaTripulacao.telefone[strcspn(novaTripulacao.telefone, "\n")] = '\0';

        tripulacao[quantidadeTripulacao] = novaTripulacao;
        (quantidadeTripulacao)++;

        printf("Tripulacao registrada com sucesso!\n");
    } else {
        printf("Nao ha espaco suficiente para mais tripulantes.\n");
    }
}

void mostrarTripulacao() {
    if (quantidadeTripulacao == 0) {
        printf("Nao ha tripulantes registrados.\n");
        return;
    }

    printf("Lista de Tripulantes:\n");
    for (int i = 0; i < quantidadeTripulacao; i++) {
        printf("ID: %d\n", tripulacao[i].id);
        printf("Nome: %s\n", tripulacao[i].nome);

        printf("Cargo: ");
        switch (tripulacao[i].cargo) {
            case 1:
                printf("Piloto\n");
                break;
            case 2:
                printf("Copiloto\n");
                break;
            case 3:
                printf("Comissario\n");
                break;
            default:
                printf("Nao definido\n");
        }

        printf("Telefone: %s\n", tripulacao[i].telefone);
        printf("----------------------------\n");
    }
}

int main() {
    int opcao;

    // Menu principal
    while (1) {
        printf("\nEscolha uma opcao:\n"
               "[1] Cadastrar Tripulacao\n"
               "[2] Mostrar Tripulacao\n"
               "[3] Sair\n");
        scanf("%d", &opcao);

        // Verificar se a opcao e valida
        while (opcao != 1 && opcao != 2 && opcao != 3) {
            printf("Opcao invalida! Tente novamente.\n");
            scanf("%d", &opcao);
        }

        switch (opcao) {
            case 1:
                registrarTripulacao();
                break;
            case 2:
                mostrarTripulacao();
                break;
            case 3:
                printf("Saindo...\n");
                return 0;
            default:
                break;
        }
    }

    return 0;
}
