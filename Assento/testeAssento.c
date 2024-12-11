#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "../munit/munit.h"
#include "../munit/munit.c"

#define MAX_ASSENTOS 10000

typedef struct dadosAssentos
{
    int numeroAssento;
    int codVoo;
    int status;
} Assento;

int i;
Assento grupo[MAX_ASSENTOS];
int totalAssento = 0;
int cdVoo[50];

int verificarAssento(int numeroAssento, int codV)
{
    for (i = 0; i < totalAssento; i++)
    {
        if (grupo[i].numeroAssento == numeroAssento && grupo[i].codVoo == codV)
            return 1;
    }
    return 0;
}

int cadastrarAssento()
{
    if (totalAssento >= MAX_ASSENTOS)
    {
        printf("Número máximo de assentos atingido!\n");
        return 0;
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

// Teste sem assento cadastrado
static MunitResult test_verificarAssento_vazio(const MunitParameter params[], void *data)
{
    totalAssento = 0;
    int result = verificarAssento(17, 05);
    munit_assert_int(result, ==, 0);
    return MUNIT_OK;
}

// Teste para cadastrar assento;
static MunitResult test_cadastrarAssento(const MunitParameter params[], void *data)
{
    totalAssento = 0;

   const char* numeroAssento_param = munit_parameters_get(params, "numeroAssento");
    const char* codVoo_param = munit_parameters_get(params, "codVoo");

    int numeroAssento = atoi(numeroAssento_param);
    int codVoo = atoi(codVoo_param);

    if (numeroAssento < 0 || codVoo < 0) {
        munit_assert_int(numeroAssento, <, 0);
        munit_assert_int(codVoo, <, 0);
        return MUNIT_OK;
    }

    grupo[totalAssento].numeroAssento = numeroAssento;
    grupo[totalAssento].codVoo = codVoo;
    grupo[totalAssento].status = 0;
    totalAssento++;

    munit_assert_int(grupo[0].numeroAssento, ==, numeroAssento);
    munit_assert_int(grupo[0].codVoo, ==, codVoo);
    munit_assert_int(grupo[0].status, ==, 0);

    return MUNIT_OK;
}

static char *numeroAssento_params[] = {
    "-1",
    "0",
    "17",
    NULL
};
static char *codVoo_params[] = {
    "-5",
    "0",
    "5",
    NULL
};

static MunitParameterEnum test_params[] = {
    {"numeroAssento", numeroAssento_params},
    {"codVoo", codVoo_params},
    {NULL, NULL}};

// Teste de assento duplicado

static MunitResult test_cadastrarAssento_duplicado(const MunitParameter params[], void *data)
{
    totalAssento = 1;
    grupo[0].numeroAssento = 17;
    grupo[0].codVoo = 05;

    int result = verificarAssento(17, 05);
    munit_assert_int(result, ==, 1);
    return MUNIT_OK;
}

// Teste de limite atingido

static MunitResult test_cadastrarAssento_limite(const MunitParameter params[], void *data)
{
    totalAssento = MAX_ASSENTOS;
    int r = cadastrarAssento();
    munit_assert_int(r, ==, 0);
    return MUNIT_OK;
}

// Conjunto de testes
static MunitTest tests[] = {
    {"/test_verificarAssento_vazio", test_verificarAssento_vazio, NULL, NULL, MUNIT_TEST_OPTION_NONE},
    {"/test_cadastrarAssento", test_cadastrarAssento, NULL, NULL, MUNIT_TEST_OPTION_NONE},
    {"/test_cadastrarAssento_duplicado", test_cadastrarAssento_duplicado, NULL, NULL, MUNIT_TEST_OPTION_NONE},
    {"/test_cadastrarAssento_limite", test_cadastrarAssento_limite, NULL, NULL, MUNIT_TEST_OPTION_NONE},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE}};

// Suite de testes
static const MunitSuite suite = {
    "/menu_tests", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE};

// Função principal para rodar os testes
int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Portuguese");

    return munit_suite_main(&suite, NULL, argc, argv);
}