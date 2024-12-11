#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_PASSAGEIROS 99

// Definindo a struct para armazenar os dados dos passageiros
typedef struct cadastroPassageiro {
    int id;
    char nome[40];
    char endereco[40];
    char telefone[20];
    int fidelidade;
    int pontos;
} Passageiro;

// Array de passageiros e contador
Passageiro passageiros[MAX_PASSAGEIROS];
int n = 0; // Contador global de passageiros

// Função para verificar se a string contém apenas espaços em branco
int verificarEspacosBrancos(const char *str) {
    while (*str) {
        if (!isspace(*str)) {
            return 0;
        }
        str++;
    }
    return 1;
}

// Função para adicionar passageiros
void add() {
    if (n >= MAX_PASSAGEIROS) {
        printf("Limite de passageiros atingido!\n");
        return;
    }

    // Preenche os dados do passageiro
    Passageiro novo_passageiro;
    novo_passageiro.id = n + 1;

    // Solicitar o nome do passageiro
    do {
        setbuf(stdin, 0);
        printf("Digite o nome: ");
        fgets(novo_passageiro.nome, sizeof(novo_passageiro.nome), stdin);
        novo_passageiro.nome[strcspn(novo_passageiro.nome, "\n")] = '\0'; // Remove o '\n'
    } while (verificarEspacosBrancos(novo_passageiro.nome));

    // Solicitar o endereço
    do {
        setbuf(stdin, 0);
        printf("Digite o endereco: ");
        fgets(novo_passageiro.endereco, sizeof(novo_passageiro.endereco), stdin);
        novo_passageiro.endereco[strcspn(novo_passageiro.endereco, "\n")] = '\0'; // Remove o '\n'
    } while (verificarEspacosBrancos(novo_passageiro.endereco));

    // Solicitar o telefone
    do {
        setbuf(stdin, 0);
        printf("Digite o telefone: ");
        fgets(novo_passageiro.telefone, sizeof(novo_passageiro.telefone), stdin);
        novo_passageiro.telefone[strcspn(novo_passageiro.telefone, "\n")] = '\0'; // Remove o '\n'
    } while (verificarEspacosBrancos(novo_passageiro.telefone));

    // Solicitar fidelidade
    do {
        printf("Digite a fidelidade\n"
               "[1]Sim\n"
               "[2]Nao\n");
        scanf("%d", &novo_passageiro.fidelidade);
    } while (novo_passageiro.fidelidade != 1 && novo_passageiro.fidelidade != 2);

    do{
        printf("Digite a quantidade de pontos ");
        scanf("%d", &novo_passageiro.pontos);
        if(novo_passageiro.pontos < 0) printf("Pontos invalidos. Por favor, insira um numero positivo.\n");
    } while (novo_passageiro.pontos < 0)

    // Adicionar o passageiro ao array
    passageiros[n] = novo_passageiro;
    n++; // Incrementa o contador de passageiros

    // Exibir os dados do passageiro cadastrado
    printf("\nPassageiro cadastrado\n");
    printf("ID: %d\n", passageiros[n - 1].id);
    printf("Nome: %s\n", passageiros[n - 1].nome);
    printf("Endereco: %s\n", passageiros[n - 1].endereco);
    printf("Telefone: %s\n", passageiros[n - 1].telefone);
    printf("Fidelidade: %s\n", (passageiros[n - 1].fidelidade == 1) ? "Sim" : "Nao");
}

// Função para continuar o programa
int continua() {
    int r;
    printf("Deseja continuar?\n"
           "[1]Sim\n"
           "[2]Nao\n");
    scanf("%d", &r);
    if (r != 1) {
        printf("Programa encerrado\n");
        return 1;
    }
    return 0;
}

// Função para listar os passageiros cadastrados
void lerPassageiros() {
    int i;
    printf("Passageiros cadastrados\n");
    for (i = 0; i < n; i++) {
        printf("ID: %d\n", passageiros[i].id);
        printf("Nome: %s\n", passageiros[i].nome);
        printf("Endereco: %s\n", passageiros[i].endereco);
        printf("Telefone: %s\n", passageiros[i].telefone);
        printf("Fidelidade: %s\n", (passageiros[i].fidelidade == 1) ? "Sim" : "Nao");
    }
}

// Função principal
int main() {
    int op, r;
    do {
        do {
            printf("Escolha uma opcao\n"
                   "[1]Cadastrar Passageiro\n"
                   "[2]Exibir Passageiros\n");
            scanf("%d", &op);
            if (op < 1 || op > 2) {
                printf("Digite uma opcao valida!\n");
            }
        } while (op < 1 || op > 2);

        switch (op) {
            case 1:
                add();
                break;
            case 2:
                lerPassageiros();
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
        r = continua();
    } while (r != 1);

    return 0;
}
