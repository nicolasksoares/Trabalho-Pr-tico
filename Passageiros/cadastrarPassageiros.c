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
int n = 0; // Declarando n como um contador global de passageiros

int verificarEspacosBrancos(const char *str)
{
    while (*str)
    {
        if (!isspace(*str))
        {
            return 0;
        }
        str++;
    }
    return 1;
}

void add(const char* nome_input, const char* endereco_input, const char* telefone_input, int fidelidade_input)
{
    if (n >= MAX_PASSAGEIROS)
    {
        printf("Limite de passageiros atingido!\n");
        return;
    }

    // Preenche os dados do passageiro
    Passageiro novo_passageiro;
    novo_passageiro.id = n + 1;

    if (nome_input == NULL) { // Se não for um teste, solicita a entrada do usuário
        do {
            setbuf(stdin, 0);
            printf("Digite o nome: ");
            fgets(novo_passageiro.nome, sizeof(novo_passageiro.nome), stdin);
        } while (verificarEspacosBrancos(novo_passageiro.nome));
    } else { // Usa os valores do teste
        strncpy(novo_passageiro.nome, nome_input, sizeof(novo_passageiro.nome) - 1);
        novo_passageiro.nome[sizeof(novo_passageiro.nome) - 1] = '\0';
    }

    if (endereco_input == NULL) {
        do {
            setbuf(stdin, 0);
            printf("Digite o endereco: ");
            fgets(novo_passageiro.endereco, sizeof(novo_passageiro.endereco), stdin);
        } while (verificarEspacosBrancos(novo_passageiro.endereco));
    } else {
        strncpy(novo_passageiro.endereco, endereco_input, sizeof(novo_passageiro.endereco) - 1);
        novo_passageiro.endereco[sizeof(novo_passageiro.endereco) - 1] = '\0';
    }

    if (telefone_input == NULL) {
        do {
            setbuf(stdin, 0);
            printf("Digite o telefone: ");
            fgets(novo_passageiro.telefone, sizeof(novo_passageiro.telefone), stdin);
        } while (verificarEspacosBrancos(novo_passageiro.telefone));
    } else {
        strncpy(novo_passageiro.telefone, telefone_input, sizeof(novo_passageiro.telefone) - 1);
        novo_passageiro.telefone[sizeof(novo_passageiro.telefone) - 1] = '\0';
    }

    if (fidelidade_input == -1) { 
        do {
            printf("Digite a fidelidade\n"
                   "[1]Sim\n"
                   "[2]Nao\n");
            scanf("%d", &novo_passageiro.fidelidade);
        } while (novo_passageiro.fidelidade != 1 && novo_passageiro.fidelidade != 2);
    } else {
        novo_passageiro.fidelidade = fidelidade_input;
    }

    passageiros[n] = novo_passageiro;
    n++; // Incrementa o contador de passageiros

    printf("\nPassageiro cadastrado\n");
    printf("ID: %d\n", passageiros[n - 1].id);
    printf("Nome: %s\n", passageiros[n - 1].nome);
    printf("Endereco: %s\n", passageiros[n - 1].endereco);
    printf("Telefone: %s\n", passageiros[n - 1].telefone);
    printf("Fidelidade: %s\n", (passageiros[n - 1].fidelidade == 1) ? "Sim" : "Nao");
}

int continua()
{
    int r;
    printf("Deseja continuar?\n"
           "[1]Sim\n"
           "[2]Nao\n");
    scanf("%d", &r);
    if (r != 1)
    {
        printf("Programa encerrado\n");
        return 1;
    }
    return 0;
}

void lerPassageiros()
{
    int i;
    printf("Passageiros cadastrados\n");
    for (i = 0; i < n; i++)
    {
        printf("ID: %d\n", passageiros[i].id);
        printf("Nome: %s", passageiros[i].nome);
        printf("Endereco: %s", passageiros[i].endereco);
        printf("Telefone: %s", passageiros[i].telefone);
        if (passageiros[i].fidelidade == 1)
        {
            printf("Fidelidade: Sim\n");
        }
        else
        {
            printf("Fidelidade: Nao\n");
        }
    }
}

/* Função para rodar o código principal, não alterada */
/*int main()
{
    int op, r;
    do
    {
        do
        {
            printf("Escolha uma opcao\n"
                   "[1]Cadastrar Passageiro\n"
                   "[2]Cadastrar Tripulacao\n"
                   "[3]Cadastrar Voo\n"
                   "[4]Cadastrar Assento\n"
                   "[5]Reserva\n"
                   "[6]Baixa em reserva\n"
                   "[7]Pesquisa\n"
                   "[8]Programa de fidelidade\n");
            scanf("%d", &op);
            if (op > 8 || op < 0)
            {
                printf("Digite de 1 a 8!\n");
            }
        } while (op > 8 || op < 0);
        switch (op)
        {
        case 1:
            add();
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
        r = continua();
    } while (r != 1);
    lerPassageiros();
    getchar();
    return 0;
}*/
