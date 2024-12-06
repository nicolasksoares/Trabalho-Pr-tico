#include <stdio.h>
#include <ctype.h>
#include "../munit/munit.h"
#include "cadastrarPassageiros.c"

// Teste para verificarEspacosBrancos
static MunitResult test_verificarEspacosBrancos(const MunitParameter params[], void *data) {
    munit_assert(verificarEspacosBrancos("   ") == 1);  // Apenas espaços
    munit_assert(verificarEspacosBrancos("Hello") == 0); // Contém texto
    munit_assert(verificarEspacosBrancos("") == 1);      // String vazia
    munit_assert(verificarEspacosBrancos("\t\n") == 1);  // Tab e nova linha
    munit_assert(verificarEspacosBrancos("   X") == 0);  // Espaços e texto

    return MUNIT_OK;
}

// Teste de inicialização para o cadastro de passageiro
static MunitResult test_add_passageiro(const MunitParameter params[], void *data) {
    // Simulação do cadastro de um passageiro
    extern int n;  // Número de passageiros
    extern char nome[][40];
    extern char endereco[][40];
    extern char telefone[][20];
    extern int fidelidade[];

    // Resetar os dados antes de testar
    n = 0;

    // Chamar a função add_passageiro com dados simulados
    add_passageiro("Teste Nome", "Rua Teste, 123", "123456789", 1);

    // Verificar se os dados foram cadastrados corretamente
    munit_assert_string_equal(nome[n - 1], "Teste Nome");
    munit_assert_string_equal(endereco[n - 1], "Rua Teste, 123");
    munit_assert_string_equal(telefone[n - 1], "123456789");
    munit_assert_int(fidelidade[n - 1], ==, 1);

    return MUNIT_OK;
}

// Array de testes
static MunitTest tests[] = {
    { "/test_verificarEspacosBrancos", test_verificarEspacosBrancos, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_add_passageiro", test_add_passageiro, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

// Suite de testes
static const MunitSuite suite = {
    "/passageiros_tests", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

// Main para executar os testes
int main(int argc, char* argv[]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}
