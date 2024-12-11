#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

// Definições de constantes
#define CHAR_MAX 100
#define MAX_ASSENTOS 9999
#define MAX_PASSAGEIROS 9999
#define MAX_TRIPULACAO 9999
#define MAX_ORIGEM_DESTINO 100
#define MAX_VOOS 999

// Estruturas de dados
typedef struct dadosAssentos
{
    int numeroAssento;
    int codVoo;
    int status; // 0: Livre, 1: Ocupado
} Assento;

typedef struct cadastroPassageiro
{
    int id;
    char nome[CHAR_MAX];
    char endereco[CHAR_MAX];
    char telefone[CHAR_MAX];
    int fidelidade; // 1: Sim, 2: Não
    int pontos;
} Passageiro;

typedef struct {
    int id;
    char nome[CHAR_MAX];
    char cargo[CHAR_MAX];
    char telefone[CHAR_MAX];
} Tripulacao;

typedef enum {
    ATIVO,
    INATIVO
} StatusVoo;


typedef struct {
    int id_Voo;
    int id_Piloto;
    int id_Copiloto;
    int id_Comissario;
    StatusVoo status;
    float tarifa;
    char origem[CHAR_MAX];
    char destino[CHAR_MAX];
} Voo;

// Variáveis globais
Assento grupo[MAX_ASSENTOS];
Passageiro passageiros[MAX_PASSAGEIROS];
Tripulacao tripulacao[MAX_TRIPULACAO];
Voo voos[MAX_VOOS];
int quantidadeTripulacao = 0; 
int totalAssento = 0;
int totalVoos = 0; 
int n = 0; // Contador de passageiros

// Funções auxiliares
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

int verificarAssento(int numeroAssento, int codV)
{
    for (int i = 0; i < totalAssento; i++)
    {
        if (grupo[i].numeroAssento == numeroAssento && grupo[i].codVoo == codV)
            return 1;
    }
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

// Funções principais



void addPassageiro()
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
               "[1] Sim\n"
               "[2] Não\n");
        scanf("%d", &novo_passageiro.fidelidade);
    } while (novo_passageiro.fidelidade != 1 && novo_passageiro.fidelidade != 2);

    if (novo_passageiro.fidelidade == 1)
    {
        do
        {
            printf("Digite a quantidade de pontos: ");
            scanf("%d", &novo_passageiro.pontos);
            if (novo_passageiro.pontos < 0)
                printf("Pontos inválidos. Por favor, insira um número positivo.\n");
        } while (novo_passageiro.pontos < 0);
    }
    else
    {
        novo_passageiro.pontos = 0;
    }

    passageiros[n] = novo_passageiro;
    n++; // Incrementa o contador de passageiros

    printf("\nPassageiro cadastrado\n");
    printf("ID: %d\n", passageiros[n - 1].id);
    printf("Nome: %s\n", passageiros[n - 1].nome);
    printf("Endereco: %s\n", passageiros[n - 1].endereco);
    printf("Telefone: %s\n", passageiros[n - 1].telefone);
    printf("Fidelidade: %s\n", (passageiros[n - 1].fidelidade == 1) ? "Sim" : "Não");
}

//Cadastrar tripulaçõa
void registrarTripulacao(Tripulacao tripulacao[], int *quantidadeTripulacao) {
    if (*quantidadeTripulacao < MAX_TRIPULACAO) {
        Tripulacao novaTripulacao;

        novaTripulacao.id = *quantidadeTripulacao + 1;

        getchar();

        printf("Digite o nome do tripulante: ");
        fgets(novaTripulacao.nome, sizeof(novaTripulacao.nome), stdin);
        novaTripulacao.nome[strcspn(novaTripulacao.nome, "\n")] = '\0';

        printf("Digite o cargo do tripulante: ");
        fgets(novaTripulacao.cargo, sizeof(novaTripulacao.cargo), stdin);
        novaTripulacao.cargo[strcspn(novaTripulacao.cargo, "\n")] = '\0';

        printf("Digite o telefone do tripulante: ");
        fgets(novaTripulacao.telefone, sizeof(novaTripulacao.telefone), stdin);
        novaTripulacao.telefone[strcspn(novaTripulacao.telefone, "\n")] = '\0';

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

void cadastrarTripulacao() {
    int opcao;

    // Menu principal
    while(1){
        printf("\nEscolha uma opcao:\n"
               "[1] Cadastrar Tripulacao\n"
               "[2] Mostrar Tripulacao\n"
               "[3] Sair\n");
        scanf("%d", &opcao);

        // Verificar se a opção é válida
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
                printf("Saindo do menu de cadastrar tripulação...\n");
                break;
            default:
                break;
        }
    if (opcao == 3) {
        return;
    }}
}

void cadastrarVoo()
{
    int opc;
    while (1){
        printf("\nEscolha uma opcao:\n"
                "[1] Cadastrar Voo\n"
                "[2] Listar Voo\n"
                "[3] Sair\n");
        scanf("%d", &opc);
        while (opc != 1 && opc != 2 && opc != 3) {
            printf("Opcao invalida! Tente novamente.\n");
            scanf("%d", &opc);
        }
        switch (opc) {
            case 1:
                registrarVoo();
                break;
            case 2:
                listarVoo();
                break;
            case 3:
                printf("Saindo do menu de cadastrar voo...\n");
                break;
            default:
                break;
        }
        if (opc == 3) {
            return;
        }
    }

}

int validarTripulante(int id) {
    for (int i = 0; i < quantidadeTripulacao; i++) {
        if (tripulacao[i].id == id) {
            return 1;
        }
    }
    return 0;
}

void registrarVoo() {
    if (totalVoos >= MAX_ASSENTOS) {
        printf("Número máximo de voos atingido!\n");
        return;
    }

    voos.id_Voo = totalVoos + 1;

    getchar(); // Limpa o buffer do teclado

    // Entrada de origem
    printf("Insira a origem do voo: ");
    fgets(voos.origem, sizeof(voos.origem), stdin);
    voos.origem[strcspn(voos.origem, "\n")] = '\0';

    // Entrada de destino
    printf("Insira o destino do voo: ");
    fgets(voos.destino, sizeof(voos.destino), stdin);
    voos.destino[strcspn(voos.destino, "\n")] = '\0';

    // Seleção do piloto
    do {
        printf("Insira o ID do piloto: ");
        scanf("%d", &voos.id_Piloto);
        if (!validarTripulante(voos.id_Piloto)) {
            printf("Erro: piloto não encontrado. Tente novamente.\n");
        }
    } while (!validarTripulante(voos.id_Piloto));

    // Seleção do copiloto
    do {
        printf("Insira o ID do copiloto: ");
        scanf("%d", &voos.id_Copiloto);
        if (!validarTripulante(voos.id_Copiloto)) {
            printf("Erro: copiloto não encontrado. Tente novamente.\n");
        }
    } while (!validarTripulante(voos.id_Copiloto));

    // Seleção do comissário
    do {
        printf("Insira o ID do comissário: ");
        scanf("%d", &voos.id_Comissario);
        if (!validarTripulante(voos.id_Comissario)) {
            printf("Erro: comissário não encontrado. Tente novamente.\n");
        }
    } while (!validarTripulante(voos.id_Comissario));

    // Entrada do status do voo
    printf("Insira o status do voo (1 para Ativo, 0 para Inativo): ");
    scanf("%d", (int *)&voos.status);

    // Entrada da tarifa
    printf("Insira a tarifa do voo: ");
    scanf("%f", &voos.tarifa);

    // Adiciona o novo voo à lista
    voos[totalVoos] = voos;
    totalVoos++;

    printf("Voo registrado com sucesso!\n");
}

void listarVoo() {
    if (totalVoos == 0) {
        printf("Nenhum voo registrado.\n");
        return;
    }

    printf("\nLista de Voos Registrados:\n");
    for (int i = 0; i < totalVoos; i++) {
        printf("\nID do Voo: %d\n", voos[i].id_Voo);
        printf("Origem: %s\n", voos[i].origem);
        printf("Destino: %s\n", voos[i].destino);
        printf("ID Piloto: %d\n", voos[i].id_Piloto);
        printf("ID Copiloto: %d\n", voos[i].id_Copiloto);
        printf("ID Comissário: %d\n", voos[i].id_Comissario);
        printf("Status: %s\n", voos[i].status == ATIVO ? "Ativo" : "Inativo");
        printf("Tarifa: %.2f\n", voos[i].tarifa);
        printf("----------------------------\n");
    }
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
    for (int i = 0; i < totalAssento; i++)
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


void darBaixa()
{
    int numAssento, codVoo;
    printf("Digite o número do assento: ");
    scanf("%d", &numAssento);
    printf("Digite o código do voo: ");
    scanf("%d", &codVoo);
    if (!verificarAssento(numAssento, codVoo))
    {
        printf("Assento ou voo não encontrados!\n");
        return;
    }

    for (int i = 0; i < totalAssento; i++)
    {
        if (grupo[i].numeroAssento == numAssento && grupo[i].codVoo == codVoo)
        {
            if (grupo[i].status == 1)
            {
                grupo[i].status = 0;
                printf("Assento baixado com sucesso!\n");
                return;
            }
            else
            {
                printf("Assento não está reservado!\n");
                return;
            }
        }
    }
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
        printf("Fidelidade: %s\n", passageiros[i].fidelidade == 1 ? "Sim" : "Não");
    }
}

// Função principal
int main()
{
    setlocale(LC_ALL, "pt_BR.utf8");
    int op;
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
               "[8] Programa de fidelidade\n"
               "[9] Sair\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            addPassageiro();
            break;
        case 2:
            cadastrarTripulacao();
            break;
        case 3:
            cadastrarVoo();
        case 4:
            assento();
            break;
        case 5:
            reserva();
            break;
        case 6:
            darBaixa();
            break;
        case 9:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opção inválida!\n");
        }
    } while (op != 9);

    return 0;
}
