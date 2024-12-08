#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "../munit/munit.h"
#include "../munit/munit.c"

// Função menu com entrada programática
int menu(int op)
{
    if (op < 1 || op > 8) {
        return 1;  // Entrada inválida
    }

    // Processamento das opções válidas
    switch (op) {
    case 1:
        printf("Cadastrar Passageiro\n");
        break;
    case 2:
        printf("Cadastrar Tripulação\n");
        break;
    case 3:
        printf("Cadastrar Voo\n");
        break;
    case 4:
        printf("Cadastrar Assento\n");
        break;
    case 5:
        printf("Reserva\n");
        break;
    case 6:
        printf("Baixa em reserva\n");
        break;
    case 7:
        printf("Pesquisa\n");
        break;
    case 8:
        printf("Programa de fidelidade\n");
        break;
    }

    return 0;  // Sucesso
}

// Função de teste para verificar o menu
static MunitResult test_verificarMenu(const MunitParameter params[], void *data)
{
    int input;
    int expected;

    // Recuperar os parâmetros e convertê-los de string para inteiro
    input = atoi(munit_parameters_get(params, "input"));

    expected = atoi(munit_parameters_get(params, "expected"));

    // Teste do comportamento do menu
    if (menu(input) != expected) {
        return MUNIT_FAIL;
    }

    return MUNIT_OK;
}

// Arrays de parâmetros de teste com valores como strings
static char* input_params[] = {
    "-5",  // Inválido (menor que 1)
    "0",   // Inválido (fora do intervalo)
    "1",   // Válido
    "2",   // Válido
    "3",   // Válido
    "4",   // Válido
    "5",   // Válido
    "6",   // Válido
    "7",   // Válido
    "8",   // Válido
    "20",  // Inválido (maior que 8)
    NULL
};

static char* expected_params[] = {
    "0", // Válidos
    NULL
};

// Definindo os parâmetros de entrada e esperado
static MunitParameterEnum test_params[] = {
    { "input", input_params },
    { "expected", expected_params },
    { NULL, NULL }
};

// Conjunto de testes
static MunitTest tests[] = {
    {"/test_verificarMenu", test_verificarMenu, NULL, NULL, MUNIT_TEST_OPTION_NONE, test_params},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

// Suite de testes
static const MunitSuite suite = {
    "/menu_tests", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

// Função principal para rodar os testes
int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Portuguese");

    return munit_suite_main(&suite, NULL, argc, argv);
}
