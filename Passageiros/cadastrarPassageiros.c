#include <stdio.h>
#include <stdlib.h>

#define MAX_PASSAGEIROS 999

// Estruturas para armazenar as informações dos passageiros
int id[MAX_PASSAGEIROS];
char nome[MAX_PASSAGEIROS][40];
char endereco[MAX_PASSAGEIROS][40];
char telefone[MAX_PASSAGEIROS][20];
int fidelidade[MAX_PASSAGEIROS];
int pontos[MAX_PASSAGEIROS];

int n = 0;

int verificarEspacosBrancos(const char *str)
{
    // Percorrer a string e verificar se algum caractere não é espaço
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
        return;}

    id[n] = n + 1;
    printf("Adicionar passageiro\n");

    do
    {
        setbuf(stdin, 0);
        printf("Digite o nome: ");
        fgets(nome[n], sizeof(nome), stdin);
        if (verificarEspacosBrancos(nome[n]))
        {
            printf("Nome invalido!\n");
        }
    } while (verificarEspacosBrancos(nome[n]));

    do
    {
        setbuf(stdin, 0);
        printf("Digite o endereco: ");
        fgets(endereco[n], sizeof(endereco), stdin);
        if (verificarEspacosBrancos(endereco[n])){
            printf("Endereco invalido!\n");}
    } while(verificarEspacosBrancos(endereco[n]));

    do{
        setbuf(stdin, 0);
        printf("Digite o telefone: ");
        fgets(telefone[n], sizeof(telefone), stdin);
        if(verificarEspacosBrancos(telefone[n])){
            printf("Telefone invalido!\n");
        }
    } while(verificarEspacosBrancos(telefone[n]));

    do
    {
        printf("Digite a fidelidade\n"
               "[1]Sim\n"
               "[2]Nao\n");
        scanf("%d", &fidelidade[n]);
        if (fidelidade[n] != 1 && fidelidade[n] != 2)
        {
            printf("Digite de 1 a 2!\n");
        }
    } while (fidelidade[n] != 1 && fidelidade[n] != 2);

    printf("\nPassageiro cadastrado\n");
    printf("ID: %d\n", id[n]);
    printf("Nome: %s", nome[n]);
    printf("Endereco: %s", endereco[n]);
    printf("Telefone: %s", telefone[n]);
    if (fidelidade[n] == 1)
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
        printf("Nome: %s", nome[i]);
        printf("Endereco: %s", endereco[i]);
        printf("Telefone: %s", telefone[i]);
        if (fidelidade[i] == 1)
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
