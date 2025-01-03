#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

#define MAX_ASSENTOS 100
#define MAX_PASSAGEIROS 99

typedef struct dadosAssentos
{
    int IDpessoa;
    int numeroAssento;
    int codVoo;
    int status; // 0: Livre, 1: Ocupado
} Assento;

typedef struct cadastroPassageiro
{
    int id;
    char nome[40];
    char endereco[40];
    char telefone[20];
    int fidelidade; // 1: Sim, 2: Não
    int pontos;
} Passageiro;

int i;
Assento grupo[MAX_ASSENTOS];
int totalAssento = 0;
int cdVoo[50];

Passageiro passageiros[MAX_PASSAGEIROS];
int n = 0; // Contador de passageiros

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

    Passageiro novo_passageiro;
    novo_passageiro.id = n + 1;

    do
    {
        setbuf(stdin, 0);
        printf("Digite o nome: ");
        fgets(novo_passageiro.nome, sizeof(novo_passageiro.nome), stdin);
        novo_passageiro.nome[strcspn(novo_passageiro.nome, "\n")] = '\0'; // Remove a quebra de linha
    } while (verificarEspacosBrancos(novo_passageiro.nome));

    do
    {
        setbuf(stdin, 0);
        printf("Digite o endereco: ");
        fgets(novo_passageiro.endereco, sizeof(novo_passageiro.endereco), stdin);
        novo_passageiro.endereco[strcspn(novo_passageiro.endereco, "\n")] = '\0'; // Remove a quebra de linha
    } while (verificarEspacosBrancos(novo_passageiro.endereco));

    do
    {
        setbuf(stdin, 0);
        printf("Digite o telefone: ");
        fgets(novo_passageiro.telefone, sizeof(novo_passageiro.telefone), stdin);
        novo_passageiro.telefone[strcspn(novo_passageiro.telefone, "\n")] = '\0'; // Remove a quebra de linha
    } while (verificarEspacosBrancos(novo_passageiro.telefone));

    do
    {
        printf("Digite a fidelidade\n"
               "[1]Sim\n"
               "[2]Nao\n");
        scanf("%d", &novo_passageiro.fidelidade);
    } while (novo_passageiro.fidelidade != 1 && novo_passageiro.fidelidade != 2);

    passageiros[n] = novo_passageiro;
    n++; // Incrementa o contador de passageiros

    printf("\nPassageiro cadastrado\n");
    printf("ID: %d\n", passageiros[n - 1].id);
    printf("Nome: %s\n", passageiros[n - 1].nome);
    printf("Endereco: %s\n", passageiros[n - 1].endereco);
    printf("Telefone: %s\n", passageiros[n - 1].telefone);
    printf("Fidelidade: %s\n", (passageiros[n - 1].fidelidade == 1) ? "Sim" : "Nao");
}

int verificarAssento(int numeroAssento, int codV)
{
    for (i = 0; i < totalAssento; i++)
    {
        if (grupo[i].numeroAssento == numeroAssento && grupo[i].codVoo == codV)
            return 1;
    }
    return 0;
}

int verificarReservaPassageiro(int codPassageiro, int codVoo) {
    for (int i = 0; i < totalAssento; i++) {
        if (grupo[i].codVoo == codVoo && grupo[i].status == 1) {
            // Verificar se o assento está ocupado pelo passageiro
            for (int j = 0; j < n; j++) {
                if (passageiros[j].id == codPassageiro) {
                    printf("Passageiro com ID %d já possui o assento %d reservado no voo %d.\n", 
                            codPassageiro, grupo[i].numeroAssento, codVoo);
                    return 1;
                }
            }
        }
    }
    printf("Passageiro com ID %d não possui reservas no voo %d.\n", codPassageiro, codVoo);
    return 0;
}

int verificarPassageiro(int id)
{
    for (int j = 0; j < n; j++)
    {
        if (passageiros[j].id == id)
            return 1;
    }
    return 0;
}

void cadastrarAssento()
{
    if (totalAssento >= MAX_ASSENTOS)
    {
        printf("Número máximo de assentos atingido!\n");
        return;
    }
    int numAssento, codVoo;
    printf("Digite o número do assento: ");
    scanf("%d", &numAssento);
    if (numAssento < 0)
    {
        printf("Número do assento inválido!\n");
        return;
    }
    printf("Digite o código do voo: ");
    scanf("%d", &codVoo);
    if (codVoo < 0 || codVoo > 50)
    {
        printf("Código do voo inválido!\n");
        return;
    }
    if (verificarAssento(numAssento, codVoo))
    {
        printf("Assento já cadastrado!\n");
        return;
    }

    grupo[totalAssento].numeroAssento = numAssento;
    grupo[totalAssento].codVoo = codVoo;
    grupo[totalAssento].status = 0;
    totalAssento++;
    printf("Assento cadastrado com sucesso!\n");
}

void listarAssento()
{
    if (totalAssento == 0)
    {
        printf("Nenhum assento cadastrado!\n");
        return;
    }
    for (i = 0; i < totalAssento; i++)
    {
        printf("Número do assento: %d\n", grupo[i].numeroAssento);
        printf("Código do voo: %d\n", grupo[i].codVoo);
        printf("Status: %s\n", grupo[i].status == 0 ? "Livre" : "Ocupado");
    }
}

void reserva() {
    if (totalAssento <= 0) {
        printf("Nenhum assento cadastrado!\n");
        return;
    }

    int numAssento, codVoo, codPassageiro;
    printf("Digite o número do assento para reserva: ");
    scanf("%d", &numAssento);
    printf("Digite o código do voo para reserva: ");
    scanf("%d", &codVoo);
    printf("Digite o código do passageiro para reserva (0 para cadastrar novo): ");
    scanf("%d", &codPassageiro);

    // Registrar passageiro se não estiver cadastrado
    if (codPassageiro == 0) {
        if (n >= MAX_PASSAGEIROS) {
            printf("Limite de passageiros atingido! Não é possível cadastrar um novo passageiro.\n");
            return;
        }
        printf("Cadastrando novo passageiro...\n");
        add(); // Chama a função para adicionar um novo passageiro
        codPassageiro = passageiros[n - 1].id; // Obtém o ID do último passageiro cadastrado
    }

    // Verificar se o assento existe
    if (!verificarAssento(numAssento, codVoo)) {
        printf("Assento ou voo não encontrados!\n");
        return;
    }

    // Verificar se o passageiro já possui reserva
    if (verificarReservaPassageiro(codPassageiro, codVoo)) {
        return;
    }

    // Realizar a reserva
    for (i = 0; i < totalAssento; i++) {
        if (grupo[i].numeroAssento == numAssento && grupo[i].codVoo == codVoo) {
            if (grupo[i].status == 0) {
                grupo[i].status = 1;
                grupo[i].IDpessoa = codPassageiro; // Vincula o ID do passageiro ao assento
                printf("Assento reservado com sucesso para o passageiro ID %d!\n", codPassageiro);
                return;
            } else {
                printf("Assento já está ocupado!\n");
                return;
            }
        }
    }
}

void lerPassageiros()
{
    if (n == 0)
    {
        printf("Nenhum passageiro cadastrado!\n");
        return;
    }

    for (int i = 0; i < n; i++)
    {
        printf("ID: %d\n", passageiros[i].id);
        printf("Nome: %s\n", passageiros[i].nome);
        printf("Endereco: %s\n", passageiros[i].endereco);
        printf("Telefone: %s\n", passageiros[i].telefone);
        printf("Fidelidade: %s\n", passageiros[i].fidelidade == 1 ? "Sim" : "Nao");
    }
}

int continua()
{
    int opcao;
    printf("Deseja continuar?\n[1] Sim\n[2] Não\n");
    scanf("%d", &opcao);
    return opcao;
}

void assento()
{
    int opcao;
    do
    {
        printf("Menu:\n"
               "[1] Cadastrar Assento\n"
               "[2] Listar Assento\n"
               "[3] Sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            cadastrarAssento();
            break;
        case 2:
            listarAssento();
            break;
        case 3:
            printf("Saindo do menu de assentos...\n");
            break;
        default:
            printf("Opção inválida!\n");
        }
    } while (opcao != 3);
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int op, r;
    do
    {
        do
        {
            printf("Escolha uma opcao\n"
                   "[1] Cadastrar Passageiro\n"
                   "[2] Cadastrar Tripulacao\n"
                   "[3] Cadastrar Voo\n"
                   "[4] Cadastrar Assento\n"
                   "[5] Reserva\n"
                   "[6] Baixa em reserva\n"
                   "[7] Pesquisa\n"
                   "[8] Programa de fidelidade\n");
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
        case 4:
            assento();
            break;
        case 5:
            reserva();
            break;
        default:
            printf("Opção inválida!\n");
            break;
        }
        r = continua();
    } while (r != 2);

    lerPassageiros();
    getchar();
    return 0;
}
