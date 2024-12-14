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
    int telefone;
    int fidelidade; // 1: Sim, 2: Não
    int pontos;
} Passageiro;

typedef struct {
    int id;
    char nome[25];
    int cargo; // 1: Piloto, 2: Copiloto, 3: Comissario
    int telefone;
} Tripulacao;

typedef struct {
    int id;
    char data[CHAR_MAX];
    char hora[CHAR_MAX];
    char origem[CHAR_MAX];
    char destino[CHAR_MAX];
    int idAviao;
    int idPiloto;
    int idCopiloto;
    int idComissario;
    int status; // 1 para Ativo, 2 para Inativo
    float tarifa;
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
int obterTelefone() {
    int telefone;
    while (1) {
        printf("Digite o telefone do passageiro (apenas números, mínimo 8 dígitos): ");
        telefone = obterInteiro("");  

        // Validar se o telefone tem pelo menos 8 dígitos e não é negativo
        int numDigitos = 0;
        int tempTelefone = telefone;

        if (telefone < 0) {
            printf("Erro: O telefone não pode ser negativo.\n");
            continue;
        }

        // Contar o número de dígitos
        while (tempTelefone > 0) {
            tempTelefone /= 10;
            numDigitos++;
        }

        if (numDigitos >= 8) {
            break;  // Telefone válido
        } else {
            printf("Erro: O telefone deve ter pelo menos 8 dígitos.\n");
        }
    }

    return telefone;
}


void obterString(char mensagem[], char destino[]) {
    while (1) {
        printf("%s", mensagem);
        fgets(destino, CHAR_MAX, stdin);
        destino[strcspn(destino, "\n")] = '\0';

        // Verifica se a string não está vazia e se contém apenas letras
        int valido = 1;
        for (int i = 0; destino[i] != '\0'; i++) {
            if (!isalpha(destino[i]) && destino[i] != ' ') {  // Permite espaços
                valido = 0;
                break;
            }
        }

        // Se válido, sai do loop, caso contrário, pede novamente
        if (strlen(destino) > 0 && valido) {
            break;
        } else {
            printf("Erro: O nome deve conter apenas letras e espaços. Tente novamente.\n");
        }
    }
}

void obterString2(char mensagem[], char destino[]) {
    while (1) {
        printf("%s", mensagem);
        fgets(destino, CHAR_MAX, stdin);
        destino[strcspn(destino, "\n")] = '\0';  // Remove o '\n' no final da string

        // Permitimos que o campo não seja vazio, mas não validamos mais os espaços internos
        if (strlen(destino) > 0) {
            break;
        }

        printf("Erro: O valor não pode ser vazio. Tente novamente.\n");
    }
}
// Função para obter um número inteiro positivo
int obterInteiro(char mensagem[]) {
    int valor;
    while (1) {
        printf("%s", mensagem);
        if (scanf("%d", &valor) == 1 && valor > 0) {
            getchar();
            return valor;
        }
        printf("Erro: Insira um número inteiro positivo.\n");
        while (getchar() != '\n');
    }
}

// Função para obter um número decimal positivo
float obterFloat(char mensagem[]) {
    float valor;
    while (1) {
        printf("%s", mensagem);
        if (scanf("%f", &valor) == 1 && valor > 0) {
            getchar();
            return valor;
        }
        printf("Erro: Insira um número decimal positivo.\n");
        while (getchar() != '\n');
    }
}

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

    do {
        obterString("Digite o nome: ", novo_passageiro.nome);
    } while (verificarEspacosBrancos(novo_passageiro.nome));

    do
    {
        setbuf(stdin, 0);
        printf("Digite o endereco: ");
        fgets(novo_passageiro.endereco, sizeof(novo_passageiro.endereco), stdin);
        novo_passageiro.endereco[strcspn(novo_passageiro.endereco, "\n")] = '\0';
    } while (verificarEspacosBrancos(novo_passageiro.endereco));

        novo_passageiro.telefone = obterTelefone();

    do
    {
        printf("Digite a fidelidade\n"
               "[1] Sim\n"
               "[2] Não\n");
        novo_passageiro.fidelidade = obterInteiro(": ");
    } while (novo_passageiro.fidelidade != 1 && novo_passageiro.fidelidade != 2);

    if (novo_passageiro.fidelidade == 1)
    {
        do
        {
            novo_passageiro.pontos = obterInteiro("Digite a quantidade de pontos: ");
            if (novo_passageiro.pontos < 0)
                printf("Pontos inválidos. Por favor, insira um número positivo.\n");
        } while (novo_passageiro.pontos < 0);
    }
    else
    {
        novo_passageiro.pontos = 0;
    }

    passageiros[n] = novo_passageiro;
    n++;

    printf("\nPassageiro cadastrado\n");
    printf("ID: %d\n", passageiros[n - 1].id);
    printf("Nome: %s\n", passageiros[n - 1].nome);
    printf("Endereco: %s\n", passageiros[n - 1].endereco);
    printf("Telefone: %d\n", passageiros[n - 1].telefone);
    printf("Fidelidade: %s\n", (passageiros[n - 1].fidelidade == 1) ? "Sim" : "Não");
    printf("Pontos: %d\n", passageiros[n - 1].pontos);
}

//Cadastrar tripulaçõa
void registrarTripulacao() {
    if (quantidadeTripulacao < MAX_TRIPULACAO) {
        Tripulacao novaTripulacao;

        novaTripulacao.id = quantidadeTripulacao + 1;

        getchar();

        do {
            obterString("Digite o nome: ", novaTripulacao.nome);
        } while (verificarEspacosBrancos(novaTripulacao.nome));

        printf("Selecione o cargo do tripulante: \n");
        printf("[1] Piloto\n[2] Copiloto\n[3] Comissario\n");
        novaTripulacao.cargo = obterInteiro("Digite o cargo: ");

        while (novaTripulacao.cargo < 1 || novaTripulacao.cargo > 3) {
            printf("Opcao invalida! Tente novamente.\n");
            printf("[1] Piloto\n[2] Copiloto\n[3] Comissario\n");
            scanf("%d", &novaTripulacao.cargo);
        }


        novaTripulacao.telefone = obterTelefone();

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


int validarTripulante(int id) {
    for (int i = 0; i < quantidadeTripulacao; i++) {
        if (tripulacao[i].id == id) {
            return 1;
        }
    }
    return 0;
}


// Função para validar a data
int validarData(char data[]) {
    int dia, mes, ano;
    if (sscanf(data, "%d/%d/%d", &dia, &mes, &ano) == 3 && ano > 1900 && ano <= 2100 && mes >= 1 && mes <= 12 && dia >= 1 && dia <= 31) {
        return 1;
    }
    printf("Data inválida. Tente novamente.\n");
    return 0;
}

// Função para validar a hora
int validarHora(char hora[]) {
    int horas, minutos;
    if (sscanf(hora, "%d:%d", &horas, &minutos) == 2 && horas >= 0 && horas < 24 && minutos >= 0 && minutos < 60) {
        return 1;
    }
    printf("Hora inválida. Tente novamente.\n");
    return 0;
}

// Função para verificar duplicidade de voo
int verificarDuplicidade(Voo voos[], int total, Voo novoVoo) {
    for (int i = 0; i < total; i++) {
        if (strcmp(voos[i].data, novoVoo.data) == 0 && strcmp(voos[i].hora, novoVoo.hora) == 0) {
            if (voos[i].idAviao == novoVoo.idAviao ||
                voos[i].idPiloto == novoVoo.idPiloto ||
                voos[i].idCopiloto == novoVoo.idCopiloto ||
                voos[i].idComissario == novoVoo.idComissario ||
                strcmp(voos[i].origem, novoVoo.origem) == 0 && strcmp(voos[i].destino, novoVoo.destino) == 0) {
                return 1;
            }
        }
    }
    return 0;
}

int verificarTripulanteCadastrado(int cargo, int idTripulante) {
    for (int i = 0; i < totalVoos; i++) {
        if ((cargo == 1 && voos[i].idPiloto == idTripulante) ||
            (cargo == 2 && voos[i].idCopiloto == idTripulante) ||
            (cargo == 3 && voos[i].idComissario == idTripulante)) {
            return 1;
        }
    }
    return 0;
}

// Função para verificar se o tripulante existe na lista
int verificarExistenciaTripulante(int idTripulante) {
    for (int i = 0; i < quantidadeTripulacao; i++) {
        if (tripulacao[i].id == idTripulante) {
            return 1;
        }
    }
    return 0; //
}


// Função para registrar um voo
void registrarVoo(int index) {
    Voo temp;
    do {
        obterString2("Insira a data do voo (DD/MM/AAAA): ", temp.data);
    } while (!validarData(temp.data));

    do {
        obterString2("Insira a hora do voo (HH:MM): ",temp.hora);
    } while (!validarHora(temp.hora));

    obterString("Insira a origem do voo: ",temp.origem);
    obterString("Insira o destino do voo: ",temp.destino);

temp.idAviao = obterInteiro("Insira o ID do avião: ");

    // Obter o ID do tripulante para os cargos de piloto, copiloto e comissário
    int idPiloto = obterInteiro("Insira o ID do piloto: ");
    int idCopiloto = obterInteiro("Insira o ID do copiloto: ");
    int idComissario = obterInteiro("Insira o ID do comissário: ");

    // Verificar se o tripulante existe
    if (!verificarExistenciaTripulante(idPiloto)) {
        printf("Erro: Piloto com ID %d não encontrado.\n", idPiloto);
        return;
    }

    if (!verificarExistenciaTripulante(idCopiloto)) {
        printf("Erro: Copiloto com ID %d não encontrado.\n", idCopiloto);
        return;
    }

    if (!verificarExistenciaTripulante(idComissario)) {
        printf("Erro: Comissário com ID %d não encontrado.\n", idComissario);
        return;
    }

    // Verificar se o tripulante já está cadastrado para o cargo correspondente
    if (verificarTripulanteCadastrado(1, idPiloto)) {
        printf("Piloto já cadastrado em outro voo.\n");
        return;
    }

    if (verificarTripulanteCadastrado(2, idCopiloto)) {
        printf("Copiloto já cadastrado em outro voo.\n");
        return;
    }

    if (verificarTripulanteCadastrado(3, idComissario)) {
        printf("Comissário já cadastrado em outro voo.\n");
        return;
    }

    // Atribuindo os IDs dos tripulantes ao voo
temp.idPiloto = idPiloto;
temp.idCopiloto = idCopiloto;
temp.idComissario = idComissario;

    do {
    temp.status = obterInteiro("Insira o status do voo ([1] Ativo / [2] Inativo): ");
        if (temp.status != 1 &&temp.status != 2) {
            printf("Status inválido. Tente novamente.\n");
        }
    } while (temp.status != 1 &&temp.status != 2);

temp.tarifa = obterFloat("Insira a tarifa do voo: ");

    if (verificarDuplicidade(voos, totalVoos,temp)) {
        printf("Erro: Voo duplicado. Insira os dados novamente.\n");
        registrarVoo(index);
    }
    temp.id=totalVoos+1;
    voos[index] = temp;
    totalVoos++;

}

// Função para exibir os dados de um voo
void exibirVoo(int index) {
    printf("\n--- Dados do Voo ---\n");
    printf("ID do Voo: %d\n",voos[index].id);
    printf("Data: %s\n", voos[index].data);
    printf("Hora: %s\n", voos[index].hora);
    printf("Origem: %s\n", voos[index].origem);
    printf("Destino: %s\n", voos[index].destino);
    printf("ID do Avião: %d\n", voos[index].idAviao);
    printf("ID do Piloto: %d\n", voos[index].idPiloto);
    printf("ID do Copiloto: %d\n", voos[index].idCopiloto);
    printf("ID do Comissário: %d\n", voos[index].idComissario);
    printf("Status: %s\n", voos[index].status == 1 ? "Ativo" : "Inativo");
    printf("Tarifa: %.2f\n", voos[index].tarifa);
}

// Função para exibir menu e gerenciar voos
void cadastrarVoo() {
    int opcao = 0;

    while (1) {
        printf("\n--- Menu de Voos ---\n");
        printf("[1] Registrar voo\n");
        printf("[2] Exibir voos registrados\n");
        printf("[3] Sair\n");
        opcao = obterInteiro("Escolha uma opção: ");

        switch (opcao) {
            case 1:
                if (totalVoos < MAX_VOOS) {
                    printf("\n--- Registro do Voo %d ---\n", totalVoos + 1);
                    voos[totalVoos].id = totalVoos + 1;
                    registrarVoo(totalVoos);
                } else {
                    printf("Limite máximo de voos atingido.\n");
                }
                break;
            case 2:
                printf("\n--- Voos Registrados ---\n");
                for (int i = 0; i < totalVoos; i++) {
                    exibirVoo(i);
                }
                break;
            case 3:
                printf("Saindo...\n");
                return;
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}

int verificarCodigoVoo(int codVoo) {
    for (int i = 0; i < totalVoos; i++) {
        if (voos[i].id == codVoo) {
            return 1;
        }
    }
    return 0;
}

void cadastrarAssento() {
    if (totalAssento >= MAX_ASSENTOS) {
        printf("Número máximo de assentos atingido!\n");
        return;
    }

    int numAssento, codVoo;
    printf("Digite o número do assento: ");
    scanf("%d", &numAssento);

    if (numAssento < 0) {
        printf("Número do assento inválido!\n");
        return;
    }

    printf("Digite o código do voo: ");
    scanf("%d", &codVoo);

    // Verificar se o código do voo está registrado
    if (!verificarCodigoVoo(codVoo)) {
        printf("Erro: Código de voo %d não registrado!\n", codVoo);
        return;
    }

    // Verificar se o voo está ativo (status == 1)
    if (voos[codVoo - 1].status != 1) {
        printf("Erro: O voo com código %d não está ativo.\n", codVoo);
        return;
    }

    // Verificar se o assento já está cadastrado para o voo
    if (verificarAssento(numAssento, codVoo)) {
        printf("Assento já cadastrado para esse voo!\n");
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
            return 1;
        }
    }
    return 0;
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
        addPassageiro();
        codPassageiro = passageiros[n - 1].id;
    }

    // Verificar se o passageiro existe
    if (!verificarPassageiro(codPassageiro)) {
    printf("Passageiro não encontrado! Cadastre o passageiro primeiro.\n");
    getchar();
    return;
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
                grupo[i].idPassageiro = codPassageiro;
                if (passageiros[i].fidelidade == 1){
                    passageiros[i].pontos += 10;
                    printf("Parabéns! Você é um assinante fidelidade.\n");
                    printf("Seu novo total de pontos é: %d\n", passageiros[i].pontos);}
                printf("Assento reservado com sucesso para o passageiro ID %d!\n", codPassageiro);
                printf("Você irá pagar: %.2f\n", voos[i].tarifa);
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
     if (totalAssento <= 0) {
        printf("Nenhum assento cadastrado!\n");
        return;
    }
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
                grupo[i].idPassageiro = 0;
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
        opcao = obterInteiro("Digite uma opção: ");
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
    int escolha;
    printf("Buscar passageiro por:\n");
    printf("[1] ID\n");
    printf("[2] Nome\n");
    escolha = obterInteiro("Digite a opção desejada: ");

    if (escolha == 1) {
        int idBuscado;
        idBuscado = obterInteiro("Digite o ID do passageiro que deseja buscar: ");

        int encontrado = 0;
        for (int i = 0; i < n; i++) {
            if (passageiros[i].id == idBuscado) {
                printf("\nPassageiro encontrado:\n");
                printf("ID: %d\n", passageiros[i].id);
                printf("Nome: %s\n", passageiros[i].nome);
                printf("Endereco: %s\n", passageiros[i].endereco);
                printf("Telefone: %d\n", passageiros[i].telefone);
                printf("Fidelidade: %s\n", (passageiros[i].fidelidade == 1) ? "Sim" : "Não");
                printf("Pontos: %d\n", passageiros[i].pontos);
                encontrado = 1;
                break;
            }
        }

        if (!encontrado) {
            printf("\nPassageiro com ID %d não encontrado!\n", idBuscado);
        }

    } else if (escolha == 2) {
        char nomeBuscado[CHAR_MAX];
        obterString("Digite o nome do passageiro que deseja buscar: ", nomeBuscado);

        int encontrado = 0;
        for (int i = 0; i < n; i++) {
            // Compara o nome buscado com o nome do passageiro
            if (strstr(passageiros[i].nome, nomeBuscado) != NULL) {
                printf("\nPassageiro encontrado:\n");
                printf("ID: %d\n", passageiros[i].id);
                printf("Nome: %s\n", passageiros[i].nome);
                printf("Endereco: %s\n", passageiros[i].endereco);
                printf("Telefone: %d\n", passageiros[i].telefone);
                printf("Fidelidade: %s\n", (passageiros[i].fidelidade == 1) ? "Sim" : "Não");
                printf("Pontos: %d\n", passageiros[i].pontos);
                encontrado = 1;
            }
        }

        if (!encontrado) {
            printf("\nNenhum passageiro com o nome '%s' encontrado!\n", nomeBuscado);
        }

    } else {
        printf("Opção inválida! Tente novamente.\n");
    }
}
// Função para buscar membros da tripulação pelo nome ou código
void buscarTripulante()
{
    int opcao;
    printf("Pesquisar Tripulante:\n[1] Pelo Nome\n[2] Pelo Código\n");
    opcao = obterInteiro("Escolha uma opção: ");

    if (opcao == 1)
    {
        char nomeBusca[CHAR_MAX];
        getchar();
        printf("Digite o nome do tripulante: ");
        fgets(nomeBusca, sizeof(nomeBusca), stdin);
        nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

        int encontrado = 0;
        for (int i = 0; i < quantidadeTripulacao; i++)
        {
            if (strstr(tripulacao[i].nome, nomeBusca))
            {
                printf("ID: %d\nNome: %s\nCargo: ", tripulacao[i].id, tripulacao[i].nome);

                // Exibe o cargo de forma descritiva
                switch (tripulacao[i].cargo)
                {
                    case 1: printf("Piloto\n"); break;
                    case 2: printf("Copiloto\n"); break;
                    case 3: printf("Comissário\n"); break;
                    default: printf("Indefinido\n");
                }

                printf("Telefone: %d\n\n", tripulacao[i].telefone);
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
                printf("ID: %d\nNome: %s\nCargo: ", tripulacao[i].id, tripulacao[i].nome);

                // Exibe o cargo de forma descritiva
                switch (tripulacao[i].cargo)
                {
                    case 1: printf("Piloto\n"); break;
                    case 2: printf("Copiloto\n"); break;
                    case 3: printf("Comissário\n"); break;
                    default: printf("Indefinido\n");
                }

                printf("Telefone: %d\n\n", tripulacao[i].telefone);
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
void listarVoosPassageiro() {
    int codigoPassageiro = obterInteiro("Digite o código do passageiro: ");

    printf("%d\n", codigoPassageiro);
    if (!verificarPassageiro(codigoPassageiro)) {
        printf("Passageiro não encontrado.\n");
        return;
    }

    int encontrado = 0;
    printf("\nVoos do Passageiro ID %d:\n", codigoPassageiro);
    for (int i = 0; i < totalAssento; i++) {
        if (grupo[i].status == 1 && grupo[i].idPassageiro == codigoPassageiro) {
            printf("Assento ID: %d\nVoo ID: %d\nStatus: %s\n\n",
                   grupo[i].idPassageiro, grupo[i].codVoo, grupo[i].status == 1? "Disponível" : "Reservado");
            for (int j = 0; j < totalVoos; j++) {
                if (grupo[i].codVoo == voos[j].id) {
                    printf("Voo ID: %d\nOrigem: %s\nDestino: %s\nTarifa: %.2f\n\n",
                           voos[j].id, voos[j].origem, voos[j].destino, voos[j].tarifa);
                    encontrado = 1;
                    break;
                }
            }
        }
    }

    if (!encontrado) {
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
               "[4] Sair\n");
        opcao = obterInteiro("Escolha uma opção: ");
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

// Função para consultar pontos de fidelidade pelo ID
void consultarPontos(int idPassageiro) {
    for (int i = 0; i < MAX_PASSAGEIROS; i++) {
        if (passageiros[i].id == idPassageiro && passageiros[i].fidelidade == 1) {
            printf("Passageiro %s (ID: %d) possui %d pontos de fidelidade.\n",
                   passageiros[i].nome, idPassageiro, passageiros[i].pontos);
            return;
        }
    }
    printf("Erro: Passageiro com ID %d não encontrado ou não possui fidelidade.\n", idPassageiro);
}

//Fidelidade
void fidelidade(){
    int opcao;
    do
    {
        printf("\nMenu de Programa de Fidelidade:\n"
               "[1] Consultar pontos de fidelidade\n"
               "[2] Sair\n");
        opcao = obterInteiro("Escolha uma opção: ");
        
        switch (opcao) {
            case 1: {
                // Bloco de código para a opção 1
                int idPassageiro;
                printf("Digite o ID do passageiro: ");
                scanf("%d", &idPassageiro);
                consultarPontos(idPassageiro);
                break;
            }
            case 2:
                printf("Saindo do menu de programa de fidelidade...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 2);
}

// Função principal
int main()
{
    setlocale(LC_ALL, "Portuguese");
    int op;
    printf("Bem vindo ao sistema\n");
    printf("Digite qualquer tecla para continuar\n");
    getchar();
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
        op = obterInteiro("Digite uma opcao: ");

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
            break;
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
        case 8:
            fidelidade();
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
