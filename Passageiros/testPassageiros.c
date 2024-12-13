#include <stdio.h>
#include <ctype.h>
#include <locale.h>
#include "../munit/munit.h"
#include "../munit/munit.c"
#include "cadastrarPassageiros.c"

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


static MunitResult test_verificarEspacosBrancos(const MunitParameter params[], void *data)
{
    const char *input;
    int expected;

    (void)data; // Não estamos usando o campo user_data no momento

    // Obtendo os parâmetros
    input = munit_parameters_get(params, "input");
    expected = atoi(munit_parameters_get(params, "expected"));

    // Validação: chamamos verificarEspacosBrancos e comparamos o resultado com o valor esperado
    if (verificarEspacosBrancos(input) != expected)
        return MUNIT_FAIL;

    return MUNIT_OK;
}

// Definir os parâmetros para o teste
static char *input_params[] = {
    "   ",   // Apenas espaços
    "Bom", // Contém texto
    "",      // String vazia
    "\t\n",  // Tabulação e nova linha
    " Opa",  // Espaços seguidos de texto
    NULL};

static char *expected_params[] = {
    "1", // Esperado: 1 para apenas espaços ou string vazia/tabulação/nova linha
    "0", // Esperado: 0 para qualquer string com texto
    NULL};

// Definir o conjunto de parâmetros
static MunitParameterEnum test_params[] = {
    {"input", input_params},
    {"expected", expected_params},
    {NULL, NULL}};

// Teste de inicialização para o cadastro de passageiro
static MunitResult test_add_passageiro(const MunitParameter params[], void *data)
{
    n = 0;

    add("Wesley", "Rua do capa, 157", "40028922", 1);

    // Verificar se os dados foram cadastrados corretamente
    munit_assert_int(n, ==, 1);
    printf("OK: Número de passageiros verificado corretamente.\n");

    munit_assert_string_equal(passageiros[0].nome, "Wesley");
    printf("OK: Nome do passageiro verificado corretamente.\n");

    munit_assert_string_equal(passageiros[0].endereco, "Rua do capa, 157");
    printf("OK: Endereço do passageiro verificado corretamente.\n");

    munit_assert_string_equal(passageiros[0].telefone, "40028922");
    printf("OK: Telefone do passageiro verificado corretamente.\n");

    munit_assert_int(passageiros[0].fidelidade, ==, 1);
    printf("OK: Status de fidelidade do passageiro verificado corretamente.\n");

    return MUNIT_OK;
}

// Array de testes
static MunitTest tests[] = {
    {"/test_verificarEspacosBrancos", test_verificarEspacosBrancos, NULL, NULL, MUNIT_TEST_OPTION_NONE, test_params},
    {"/test_add_passageiro", test_add_passageiro, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}};

// Suite de testes
static const MunitSuite suite = {
    "/passageiros_tests", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE};

// Main para executar os testes
int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "pt_BR.utf8"); // Para aceitar caracteres especiais no printf

    return munit_suite_main(&suite, NULL, argc, argv);
}