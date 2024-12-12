#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../munit/munit.c"
#include "../munit/munit.h"

#define MAX_TRIPULACAO 999

typedef struct {
    int id;
    char nome[25];
    int cargo; // 1: Piloto, 2: Copiloto, 3: Comissario
    int telefone;
} Tripulacao;

Tripulacao tripulacao[MAX_TRIPULACAO];
int quantidadeTripulacao = 0; 

void registrarTripulacao(char *nome, int cargo, int telefone) {
    if (quantidadeTripulacao < MAX_TRIPULACAO) {
        if (telefone < 0) {
            printf("Erro: Telefone nao pode ser negativo.\n");
            return;
        }

        int telefoneDigitos = snprintf(NULL, 0, "%d", telefone);
        if (telefoneDigitos < 8) {
            printf("Erro: Telefone deve ter no minimo 8 digitos.\n");
            return;
        }

        if (cargo < 1 || cargo > 3) {
            printf("Erro: Cargo invalido.\n");
            return;
        }

        Tripulacao novaTripulacao;
        novaTripulacao.id = quantidadeTripulacao + 1;

        strncpy(novaTripulacao.nome, nome, sizeof(novaTripulacao.nome) - 1);
        novaTripulacao.cargo = cargo;
        novaTripulacao.telefone = telefone;

        tripulacao[quantidadeTripulacao] = novaTripulacao;
        quantidadeTripulacao++;
    }
}

static MunitResult test_cargos(const MunitParameter params[], void* user_data) {
    quantidadeTripulacao = 0; 

    registrarTripulacao("Ana", 1, 12345678);  // Piloto
    registrarTripulacao("Carlos", 2, 87654321); // Copiloto
    registrarTripulacao("Maria", 3, 11223344);  // Comissário
    registrarTripulacao("Pedro", 0, 23456789);  // Inexistente
    registrarTripulacao("Joao", -5, 12345678);  // Inexistente
    registrarTripulacao("Maria", 17, 98765432);  // Inexistente

    // Verifica os cargos
    munit_assert_int(tripulacao[0].cargo, ==, 1);
    munit_assert_int(tripulacao[1].cargo, ==, 2);
    munit_assert_int(tripulacao[2].cargo, ==, 3);
    munit_assert_int(tripulacao[3].cargo, ==, 0);
    munit_assert_int(tripulacao[4].cargo, ==, 0);
    munit_assert_int(tripulacao[5].cargo, ==, 0);

    return MUNIT_OK;
};

static MunitResult test_registrar_tripulacao(const MunitParameter params[], void* user_data) {

    registrarTripulacao("Joao", 1, 12345678);

    munit_assert_int(quantidadeTripulacao, ==, 1);
    munit_assert_int(tripulacao[0].id, ==, 1);
    munit_assert_string_equal(tripulacao[0].nome, "Joao");
    munit_assert_int(tripulacao[0].cargo, ==, 1);
    munit_assert_int(tripulacao[0].telefone, ==, 12345678);

    return MUNIT_OK;
}


static MunitResult test_registrar_telefone_invalido(const MunitParameter params[], void* user_data) {
    quantidadeTripulacao = 0;

    registrarTripulacao("Maria", 2, -12345678);
    munit_assert_int(quantidadeTripulacao, ==, 0);

    registrarTripulacao("Carlos", 3, 1234);
    munit_assert_int(quantidadeTripulacao, ==, 0);

    registrarTripulacao("Pedro", 1, 40028922);
    munit_assert_int(quantidadeTripulacao, ==, 1);

    return MUNIT_OK;
}

static MunitTest tests[] = {
    { "/test_registrar_tripulacao", test_registrar_tripulacao, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_cargos", test_cargos, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_registrar_telefone_invalido", test_registrar_telefone_invalido, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite suite = {
    "/tripulacao_tests", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}
