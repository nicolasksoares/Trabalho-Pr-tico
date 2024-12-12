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
    int idPassageiro;
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
    char nome[25];
    int cargo; // 1: Piloto, 2: Copiloto, 3: Comissario
    int telefone;
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
int i;
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

        printf("Digite o telefone do tripulante (apenas numeros, minimo 8 digitos): ");
        scanf("%d", &novaTripulacao.telefone);

        // Validar telefone
        while (novaTripulacao.telefone < 0 || novaTripulacao.telefone / 10000000 == 0) {
            printf("Telefone invalido! Deve ter pelo menos 8 digitos e nao ser negativo.\n");
            printf("Digite o telefone novamente: ");
            scanf("%d", &novaTripulacao.telefone);
        }

        tripulacao[quantidadeTripulacao] = novaTripulacao;
        quantidadeTripulacao++;

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

        printf("Telefone: %d\n", tripulacao[i].telefone);
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

// void cadastrarVoo()
// {
//     int opc;
//     while (1){
//         printf("\nEscolha uma opcao:\n"
//                 "[1] Cadastrar Voo\n"
//                 "[2] Listar Voo\n"
//                 "[3] Sair\n");
//         scanf("%d", &opc);
//         while (opc != 1 && opc != 2 && opc != 3) {
//             printf("Opcao invalida! Tente novamente.\n");
//             scanf("%d", &opc);
//         }
//         switch (opc) {
//             case 1:
//                 registrarVoo();
//                 break;
//             case 2:
//                 listarVoo();
//                 break;
//             case 3:
//                 printf("Saindo do menu de cadastrar voo...\n");
//                 break;
//             default:
//                 break;
//         }
//         if (opc == 3) {
//             return;
//         }
//     }

// }

int validarTripulante(int id) {
    for (int i = 0; i < quantidadeTripulacao; i++) {
        if (tripulacao[i].id == id) {
            return 1;
        }
    }
    return 0;
}

// void registrarVoo() {
//     if (totalVoos >= MAX_ASSENTOS) {
//         printf("Número máximo de voos atingido!\n");
//         return;
//     }

//     voos.id_Voo = totalVoos + 1;

//     getchar(); // Limpa o buffer do teclado

//     // Entrada de origem
//     printf("Insira a origem do voo: ");
//     fgets(voos.origem, sizeof(voos.origem), stdin);
//     voos.origem[strcspn(voos.origem, "\n")] = '\0';

//     // Entrada de destino
//     printf("Insira o destino do voo: ");
//     fgets(voos.destino, sizeof(voos.destino), stdin);
//     voos.destino[strcspn(voos.destino, "\n")] = '\0';

//     // Seleção do piloto
//     do {
//         printf("Insira o ID do piloto: ");
//         scanf("%d", &voos.id_Piloto);
//         if (!validarTripulante(voos.id_Piloto)) {
//             printf("Erro: piloto não encontrado. Tente novamente.\n");
//         }
//     } while (!validarTripulante(voos.id_Piloto));

//     // Seleção do copiloto
//     do {
//         printf("Insira o ID do copiloto: ");
//         scanf("%d", &voos.id_Copiloto);
//         if (!validarTripulante(voos.id_Copiloto)) {
//             printf("Erro: copiloto não encontrado. Tente novamente.\n");
//         }
//     } while (!validarTripulante(voos.id_Copiloto));

//     // Seleção do comissário
//     do {
//         printf("Insira o ID do comissário: ");
//         scanf("%d", &voos.id_Comissario);
//         if (!validarTripulante(voos.id_Comissario)) {
//             printf("Erro: comissário não encontrado. Tente novamente.\n");
//         }
//     } while (!validarTripulante(voos.id_Comissario));

//     // Entrada do status do voo
//     printf("Insira o status do voo (1 para Ativo, 0 para Inativo): ");
//     scanf("%d", (int *)&voos.status);

//     // Entrada da tarifa
//     printf("Insira a tarifa do voo: ");
//     scanf("%f", &voos.tarifa);

//     // Adiciona o novo voo à lista
//     voos[totalVoos] = voos;
//     totalVoos++;

//     printf("Voo registrado com sucesso!\n");
// }

// void listarVoo() {
//     if (totalVoos == 0) {
//         printf("Nenhum voo registrado.\n");
//         return;
//     }

//     printf("\nLista de Voos Registrados:\n");
//     for (int i = 0; i < totalVoos; i++) {
//         printf("\nID do Voo: %d\n", voos[i].id_Voo);
//         printf("Origem: %s\n", voos[i].origem);
//         printf("Destino: %s\n", voos[i].destino);
//         printf("ID Piloto: %d\n", voos[i].id_Piloto);
//         printf("ID Copiloto: %d\n", voos[i].id_Copiloto);
//         printf("ID Comissário: %d\n", voos[i].id_Comissario);
//         printf("Status: %s\n", voos[i].status == ATIVO ? "Ativo" : "Inativo");
//         printf("Tarifa: %.2f\n", voos[i].tarifa);
//         printf("----------------------------\n");
//     }
// }

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

int verificarReservaPassageiro(int idPassageiro, int codVoo)
{
    for (int i = 0; i < totalAssento; i++)
    {
        // Verifica se o assento já está reservado pelo passageiro no voo informado
        if (grupo[i].idPassageiro == idPassageiro && grupo[i].codVoo == codVoo)
        {
            printf("O passageiro ID %d já possui reserva no voo %d.\n", idPassageiro, codVoo);
            return 1; // Retorna 1 indicando que a reserva já existe
        }
    }
    return 0; // Retorna 0 indicando que a reserva não foi encontrada
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
        addPassageiro(); // Chama a função para adicionar um novo passageiro
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
                grupo[i].idPassageiro = codPassageiro; // Vincula o ID do passageiro ao assento
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

void buscarPassageiro()
{
    int opcao;
    printf("Pesquisar Passageiro:\n[1] Pelo Nome\n[2] Pelo Código\nEscolha uma opção: ");
    scanf("%d", &opcao);

    if (opcao == 1)
    {
        char nomeBusca[CHAR_MAX];
        getchar(); // Limpa o buffer do teclado
        printf("Digite o nome do passageiro: ");
        fgets(nomeBusca, sizeof(nomeBusca), stdin);
        nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

        int encontrado = 0;
        for (int i = 0; i < n; i++)
        {
            if (strstr(passageiros[i].nome, nomeBusca))
            {
                printf("ID: %d\nNome: %s\nEndereco: %s\nTelefone: %s\nFidelidade: %s\n\n",
                       passageiros[i].id, passageiros[i].nome, passageiros[i].endereco,
                       passageiros[i].telefone, passageiros[i].fidelidade == 1 ? "Sim" : "Não");
                encontrado = 1;
            }
        }

        if (!encontrado)
        {
            printf("Nenhum passageiro encontrado com o nome informado.\n");
        }
    }
    else if (opcao == 2)
    {
        int codigoBusca;
        printf("Digite o código do passageiro: ");
        scanf("%d", &codigoBusca);

        int encontrado = 0;
        for (int i = 0; i < n; i++)
        {
            if (passageiros[i].id == codigoBusca)
            {
                printf("ID: %d\nNome: %s\nEndereco: %s\nTelefone: %s\nFidelidade: %s\nPontos: %d\n",
                       passageiros[i].id, passageiros[i].nome, passageiros[i].endereco,
                       passageiros[i].telefone, passageiros[i].fidelidade == 1 ? "Sim" : "Não", passageiros[i].pontos);
                encontrado = 1;
                break;
            }
        }

        if (!encontrado)
        {
            printf("Nenhum passageiro encontrado com o código informado.\n");
        }
    }
    else
    {
        printf("Opção inválida.\n");
    }
}

// Função para buscar membros da tripulação pelo nome ou código
void buscarTripulante()
{
    int opcao;
    printf("Pesquisar Tripulante:\n[1] Pelo Nome\n[2] Pelo Código\nEscolha uma opção: ");
    scanf("%d", &opcao);

    if (opcao == 1)
    {
        char nomeBusca[CHAR_MAX];
        getchar(); // Limpa o buffer do teclado
        printf("Digite o nome do tripulante: ");
        fgets(nomeBusca, sizeof(nomeBusca), stdin);
        nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

        int encontrado = 0;
        for (int i = 0; i < quantidadeTripulacao; i++)
        {
            if (strstr(tripulacao[i].nome, nomeBusca))
            {
                printf("ID: %d\nNome: %s\nCargo: %s\nTelefone: %s\n\n",
                       tripulacao[i].id, tripulacao[i].nome, tripulacao[i].cargo, tripulacao[i].telefone);
                encontrado = 1;
            }
        }

        if (!encontrado)
        {
            printf("Nenhum tripulante encontrado com o nome informado.\n");
        }
    }
    else if (opcao == 2)
    {
        int codigoBusca;
        printf("Digite o código do tripulante: ");
        scanf("%d", &codigoBusca);

        int encontrado = 0;
        for (int i = 0; i < quantidadeTripulacao; i++)
        {
            if (tripulacao[i].id == codigoBusca)
            {
                printf("ID: %d\nNome: %s\nCargo: %s\nTelefone: %s\n\n",
                       tripulacao[i].id, tripulacao[i].nome, tripulacao[i].cargo, tripulacao[i].telefone);
                encontrado = 1;
                break;
            }
        }

        if (!encontrado)
        {
            printf("Nenhum tripulante encontrado com o código informado.\n");
        }
    }
    else
    {
        printf("Opção inválida.\n");
    }
}

// Função para listar todos os voos de um passageiro
void listarVoosPassageiro()
{
    int codigoPassageiro;
    printf("Digite o código do passageiro: ");
    scanf("%d", &codigoPassageiro);

    if (!verificarPassageiro(codigoPassageiro))
    {
        printf("Passageiro não encontrado.\n");
        return;
    }

    int encontrado = 0;
    printf("\nVoos do Passageiro ID %d:\n", codigoPassageiro);
    for (int i = 0; i < totalAssento; i++)
    {
        if (grupo[i].status == 1 && grupo[i].idPassageiro == codigoPassageiro)
        {
            for (int j = 0; j < totalVoos; j++)
            {
                if (grupo[i].codVoo == voos[j].id_Voo)
                {
                    printf("Voo ID: %d\nOrigem: %s\nDestino: %s\nTarifa: %.2f\n\n",
                           voos[j].id_Voo, voos[j].origem, voos[j].destino, voos[j].tarifa);
                    encontrado = 1;
                }
            }
        }
    }

    if (!encontrado)
    {
        printf("Nenhum voo encontrado para este passageiro.\n");
    }
}

// Menu de pesquisa
void pesquisa()
{
    int opcao;
    do
    {
        printf("\nMenu de Pesquisa:\n"
               "[1] Buscar Passageiro\n"
               "[2] Buscar Tripulante\n"
               "[3] Listar Voos de Passageiro\n"
               "[4] Sair\n"
               "Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            buscarPassageiro();
            break;
        case 2:
            buscarTripulante();
            break;
        case 3:
            listarVoosPassageiro();
            break;
        case 4:
            printf("Saindo do menu de pesquisa...\n");
            break;
        default:
            printf("Opção inválida!\n");
        }
    } while (opcao != 4);
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
            //cadastrarVoo();
        case 4:
            assento();
            break;
        case 5:
            reserva();
            break;
        case 6:
            darBaixa();
            break;
        case 7:
            pesquisa();
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
