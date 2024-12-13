#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "../munit/munit.h"
#include "../munit/munit.c"

#define CHAR_MAX 100
#define MAX_PASSAGEIROS 100

typedef struct cadastroPassageiro
{
    int id;
    char nome[CHAR_MAX];
    char endereco[CHAR_MAX];
    char telefone[CHAR_MAX];
    int fidelidade; // 1: Sim, 2: Não
    int pontos;
} Passageiro;

Passageiro passageiros[MAX_PASSAGEIROS];

void acumularPontos(int idPassageiro)
{
    for (int i = 0; i < MAX_PASSAGEIROS; i++)
    {
        if (passageiros[i].id == idPassageiro && passageiros[i].fidelidade == idPassageiro == 1)
        {
            passageiros[i].pontos += 10; // Adiciona 10 pontos por voo
            //printf("10 pontos adicionados ao passageiro %s (ID: %d). Total: %d pontos.\n",
                   //passageiros[i].nome, idPassageiro, passageiros[i].pontos);
            return;
        }
    }
    printf("Erro: Passageiro com ID %d não encontrado.\n", idPassageiro);
}

// Função para consultar pontos de fidelidade pelo ID
int consultarPontos(int idPassageiro)
{
    for (int i = 0; i < MAX_PASSAGEIROS; i++)
    {
        if (passageiros[i].id == idPassageiro && passageiros[i].fidelidade == idPassageiro == 1)
        {
            //printf("Passageiro %s (ID: %d) possui %d pontos de fidelidade.\n",
                   //passageiros[i].nome, idPassageiro, passageiros[i].pontos);
            return passageiros[i].pontos;
        }
    }
    return 0;
    printf("Erro: Passageiro com ID %d não encontrado.\n", idPassageiro);
}

int fidelidade(int opcao)
{
    switch (opcao)
        {
        case 1:
            return 1;
        case 2:
            return 1;
        case 3:
           return 1;
        default:
            return 0;
        }
}

static char* input_params[] ={
    "-1", 
    "0",
    "1",
    "2",
    "3",
    "17",
    NULL
};

static char* expected_params[] = {
    "1",
    NULL
};

static MunitParameterEnum test_params[] = {
    { "input", input_params},
    { "expected", expected_params},
    {NULL, NULL}
};

static MunitResult test_menu(const MunitParameter params[], void *data){
   const char *input_str = munit_parameters_get(params, "input");
   int input = atoi(input_str);
   const char *expected_str = munit_parameters_get(params, "expected");
   int expected = atoi(expected_str);

   munit_assert_int(fidelidade(input), ==, expected);
   return MUNIT_OK;
};

static MunitResult test_acumular_pontos(const MunitParameter params[], void *data){
    passageiros[0].id = 1;
    passageiros[0].fidelidade = 1;
    passageiros[0].pontos = 0;

    acumularPontos(1);
    munit_assert_int(passageiros[0].pontos, ==, 10);

    passageiros[1].id = 2;
    passageiros[1].pontos = 10;
    acumularPontos(-5);
    munit_assert_int(passageiros[1].pontos, ==, 10);
    acumularPontos(0);
    munit_assert_int(passageiros[1].pontos, ==, 10);
    return MUNIT_OK;
}

static MunitResult tests_consultar_pontos(const MunitParameter params[], void *data){
    passageiros[0].id = 1;
    passageiros[0].fidelidade = 1;
    passageiros[0].pontos = 10;
    int pontos = consultarPontos(1);
    munit_assert_int(pontos, ==, 10);

    int pontos_nulos = consultarPontos(0);
    munit_assert_int(pontos_nulos, ==, 0);

    int pontos_negativo = consultarPontos(-1);
    munit_assert_int(pontos_negativo, ==, 0);

    return MUNIT_OK;
}

static MunitTest test[]={
    {"/test_menu", test_menu, NULL, NULL, MUNIT_TEST_OPTION_NONE, test_params},
    {"/test_acumular_pontos", test_acumular_pontos, NULL, NULL, MUNIT_TEST_OPTION_NONE},
    {"/test_consultar_pontos", tests_consultar_pontos, NULL, NULL, MUNIT_TEST_OPTION_NONE},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

static MunitTest suite = {
    "Fidelidade_tests",
    test,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char *argv[]){
    return munit_suite_main(&suite, NULL, argc, argv);
}