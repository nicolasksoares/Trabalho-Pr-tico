#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_PASSAGEIROS 99

// Definindo a struct para armazenar os dados dos passageiros
typedef struct cadastroPassageiro{
    int id;
    char nome[40];
    char endereco[40];
    char telefone[20];
    int fidelidade;
    int pontos;
} Passageiro;

// Array de passageiros
Passageiro passageiros[MAX_PASSAGEIROS];
int n = 0;

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

void add()
{
    if (n >= MAX_PASSAGEIROS)
    {
        printf("Limite de passageiros atingido!\n");
        return;
    }

    // Preenche os dados do passageiro
    Passageiro novo_passageiro;
    novo_passageiro.id = n + 1;
    printf("Adicionar passageiro\n");

    do
    {
        setbuf(stdin, 0);
        printf("Digite o nome: ");
        fgets(novo_passageiro.nome, sizeof(novo_passageiro.nome), stdin);
        if (verificarEspacosBrancos(novo_passageiro.nome))
        {
            printf("Nome invalido!\n");
        }
    } while (verificarEspacosBrancos(novo_passageiro.nome));

    do
    {
        setbuf(stdin, 0);
        printf("Digite o endereco: ");
        fgets(novo_passageiro.endereco, sizeof(novo_passageiro.endereco), stdin);
        if (verificarEspacosBrancos(novo_passageiro.endereco))
        {
            printf("Endereco invalido!\n");
        }
    } while (verificarEspacosBrancos(novo_passageiro.endereco));

    do
    {
        setbuf(stdin, 0);
        printf("Digite o telefone: ");
        fgets(novo_passageiro.telefone, sizeof(novo_passageiro.telefone), stdin);
        if (verificarEspacosBrancos(novo_passageiro.telefone))
        {
            printf("Telefone invalido!\n");
        }
    } while (verificarEspacosBrancos(novo_passageiro.telefone));

    do
    {
        printf("Digite a fidelidade\n"
               "[1]Sim\n"
               "[2]Nao\n");
        scanf("%d", &novo_passageiro.fidelidade);
        if (novo_passageiro.fidelidade != 1 && novo_passageiro.fidelidade != 2)
        {
            printf("Digite de 1 a 2!\n");
        }
    } while (novo_passageiro.fidelidade != 1 && novo_passageiro.fidelidade != 2);

    // Adiciona o novo passageiro ao array
    passageiros[n] = novo_passageiro;

    printf("\nPassageiro cadastrado\n");
    printf("ID: %d\n", passageiros[n].id);
    printf("Nome: %s", passageiros[n].nome);
    printf("Endereco: %s", passageiros[n].endereco);
    printf("Telefone: %s", passageiros[n].telefone);
    if (passageiros[n].fidelidade == 1)
    {
        printf("Fidelidade: Sim\n");
    }
    else
    {
        printf("Fidelidade: Nao\n");
    }
    n++;
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

int main()
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
}
