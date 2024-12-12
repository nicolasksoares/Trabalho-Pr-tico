#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "../munit/munit.h"
#include "../munit/munit.c"

#define MAX_PASSAGEIROS 99


typedef struct cadastroPassageiro {
    int id;
    char nome[40];
    char endereco[40];
    char telefone[20];
    int fidelidade;
    int pontos;
} Passageiro;

// Array de passageiros e contador
Passageiro passageiros[MAX_PASSAGEIROS];
typedef struct dadosAssentos {
    int idPassageiro;
    int numeroAssento;
    int codVoo;
    int status; // 0: Livre, 1: Ocupado
} Assento;

Assento assentos[99];
int totalAssento = 0;

// Função auxiliar para verificar se um assento existe
int verificarAssento(int numAssento, int codVoo) {
    for (int i = 0; i < totalAssento; i++) {
        if (assentos[i].numeroAssento == numAssento && assentos[i].codVoo == codVoo) {
            return 1; // Assento encontrado
        }
    }
    return 0; // Assento não encontrado
}

// Função auxiliar para verificar se um passageiro existe (simulação)
int verificarPassageiro(int idPassageiro) {
    return idPassageiro > 0; 
}

// Função principal para reservar um assento
int reserva(int numAssento, int codVoo, int codPassageiro) {
    if (totalAssento <= 0) {
        return 0; // Nenhum assento cadastrado
    }

    if (!verificarAssento(numAssento, codVoo)) {
        return 0; // Assento não encontrado
    }

    if (!verificarPassageiro(codPassageiro)) {
        return 0; // Passageiro não encontrado
    }

    for (int i = 0; i < totalAssento; i++) {
        if (assentos[i].numeroAssento == numAssento && assentos[i].codVoo == codVoo) {
            if (assentos[i].status == 0) {
                assentos[i].status = 1;
                assentos[i].idPassageiro = codPassageiro;
                return 1; // Sucesso
            } else {
                return -1; // Assento ocupado
            }
        }
    }
    return 0;
}

// Teste para reserva de assento livre
static MunitResult test_reservaAssentoLivre(const MunitParameter params[], void* data) {
    totalAssento = 1;
    assentos[0] = (Assento){0, 17, 5, 0};

    int result = reserva(17, 5, 1); 
    munit_assert_int(result, ==, 1); 
    munit_assert_int(assentos[0].status, ==, 1); 
    munit_assert_int(assentos[0].idPassageiro, ==, 1); // Passageiro correto associado
    return MUNIT_OK;
}

// Teste para reserva de assento ocupado
static MunitResult test_reservaAssentoOcupado(const MunitParameter params[], void* data) {
    totalAssento = 1;
    assentos[0] = (Assento){0, 17, 5, 1}; 

    int result = reserva(17, 5, 1); 
    munit_assert_int(result, ==, -1); 
    munit_assert_int(assentos[0].status, ==, 1); // Status continua ocupado
    return MUNIT_OK;
}

// Teste para reserva de assento não encontrado
static MunitResult test_reservaAssentoNaoEncontrado(const MunitParameter params[], void* data) {
    totalAssento = 1;
    assentos[0] = (Assento){0, 17, 5, 0};

    int result = reserva(18, 5, 1); 
    munit_assert_int(result, ==, 0); 
    munit_assert_int(assentos[0].status, ==, 0); // Status permanece livre
    int result2 = reserva(-5, 0, 1); 
    munit_assert_int(result2, ==, 0); // Status permanece livre
    int result3 = reserva(5, 0, 1);
    munit_assert_int(result3, ==, 0); // Status permanece livre
    return MUNIT_OK;
}

// Teste para reserva com passageiro não encontrado
static MunitResult test_reservaPassageiroNaoEncontrado(const MunitParameter params[], void* data) {
    totalAssento = 1;
    assentos[0] = (Assento){0, 17, 5, 0}; 

    int result = reserva(17, 5, -1); 
    munit_assert_int(result, ==, 0); 
    munit_assert_int(assentos[0].status, ==, 0); // Status permanece livre
    return MUNIT_OK;
}

// Suite de testes
static MunitTest tests[] = {
    {"/test_reservaAssentoLivre", test_reservaAssentoLivre, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/test_reservaAssentoOcupado", test_reservaAssentoOcupado, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/test_reservaAssentoNaoEncontrado", test_reservaAssentoNaoEncontrado, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/test_reservaPassageiroNaoEncontrado", test_reservaPassageiroNaoEncontrado, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

// Suite principal de testes para a função de reserva de assento
static const MunitSuite suite = {
    "/reserva-tests",
    tests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};

// Função principal para testar a função de reserva
int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Portuguese_Brazil.1252");
    return munit_suite_main(&suite, NULL, argc, argv);
}
