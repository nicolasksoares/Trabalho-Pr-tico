#include <stdio.h>
#include <ctype.h>
#include <locale.h>
#include "../munit/munit.h"
#include "../munit/munit.c"
#include "cadastrarPassageiros.c"

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