#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRIPULACAO 999

typedef struct {
    int id;
    char nome[25];
    char cargo[25];
    char telefone[14];
} Tripulacao;

void registrarTripulacao(Tripulacao tripulacao[],int *quantidadeTripulacao){
    
    if (*quantidadeTripulacao < MAX_TRIPULACAO) {
        Tripulacao novaTripulacao;

        novaTripulacao.id = *quantidadeTripulacao + 1;   

        printf("Digite o nome da tripulacao: ");
        scanf("%s", novaTripulacao.nome);
        
        printf("Digite o cargo da tripulacao: ");
        scanf("%s", novaTripulacao.cargo);
        
        printf("Digite o telefone da tripulacao: ");
        scanf("%s", novaTripulacao.telefone);
        
        tripulacao[*quantidadeTripulacao] = novaTripulacao;
        (*quantidadeTripulacao)++;
        
        printf("Tripulacao registrada com sucesso!\n");
    } else {
        printf("Nao ha espaco suficiente para mais tripulantes.\n");
    }
}

void mostrarTripulacao(Tripulacao tripulacao[], int quantidadeTripulacao) {
    if (quantidadeTripulacao == 0) {
        printf("Nao ha tripulantes registrados.\n");
        return;
    }
    
    printf("Lista de Tripulantes:\n");
    for (int i = 0; i < quantidadeTripulacao; i++) {
        printf("ID: %d\n", tripulacao[i].id);
        printf("Nome: %s\n", tripulacao[i].nome);
        printf("Cargo: %s\n", tripulacao[i].cargo);
        printf("Telefone: %s\n", tripulacao[i].telefone);
        printf("----------------------------\n");
    }
}

int main(){
    Tripulacao tripulacao[MAX_TRIPULACAO];    
    int quantidadeTripulacao=0;
    int opcao;
    int i=0;

    printf("Informe a quantidade de tripulantes: \n");
    scanf("%d",&quantidadeTripulacao);
    
for (i = 0; i < quantidadeTripulacao; i++) {
    printf("Escolha uma opcao:\n"
           "[1] Cadastrar Tripulacao\n"
           "[2] Mostrar Tripulacao\n"
           "[3] Sair\n");
    scanf("%d", &opcao);

    while (opcao != 1 && opcao != 2 && opcao != 3) {
        printf("Opcao invalida! Tente novamente.\n");
        scanf("%d", &opcao);
    }

    switch (opcao) {
        case 1:
            registrarTripulacao(tripulacao, &quantidadeTripulacao);
            break;
        case 2:
            mostrarTripulacao(tripulacao, quantidadeTripulacao);
            break;
        case 3:
            printf("Saindo do programa.\n");
            return 0;
        default:
            break;
    }
}

    return 0;
}
