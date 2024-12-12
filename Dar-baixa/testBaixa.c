#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "../munit/munit.h"
#include "../munit/munit.c"

typedef struct dadosAssentos
{
    int idPassageiro;
    int numeroAssento;
    int codVoo;
    int status; // 0: Livre, 1: Ocupado
} Assento;

int i;
Assento assentos[99];
int totalAssento = 0;

int verificarAssento(int numeroAssento, int codV)
{
    for (i = 0; i < totalAssento; i++)
    {
        if (assentos[i].numeroAssento == numeroAssento && assentos[i].codVoo == codV)
            return 1;
    }
    return 0;
}

void darBaixa(int numAssento, int codVoo)
{
    // Verificar se o assento existe
    if (!verificarAssento(numAssento, codVoo))
    {
        printf("Assento ou voo não encontrados!\n");
        return;
    }
    // Realizar a baixa
    for (i = 0; i < totalAssento; i++)
    {
        if (assentos[i].numeroAssento == numAssento && assentos[i].codVoo == codVoo)
        {
            if (assentos[i].status == 1)
            {
                assentos[i].status = 0;
                assentos[i].idPassageiro = 0;  // Limpar o ID do passageiro
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

static MunitResult test_darBaixa (const MunitParameter params[], void *data)
{
    totalAssento = 3;
    assentos[0] = (Assento){1, 17, 5, 1}; // Ocupaddo
    assentos[1] = (Assento){2, 22, 5, 0}; // Livre
    assentos[2] = (Assento){3, 27, 5, 1}; // Ocupado

    darBaixa(17, 5);
    munit_assert_int(assentos[0].status, ==, 0); // Assento 17 do voo 5 baixado
    darBaixa(22, 5);
    munit_assert_int(assentos[1].status, ==, 0); // Tenta dar baixa em assento livre
    darBaixa(29, 9);
    munit_assert_int(assentos[2].status, ==, 1); // Dar baixa em assento inexistente
    
    return MUNIT_OK;
};

static MunitTest tests[] = {
    { "darBaixa", test_darBaixa, NULL, NULL, MUNIT_TEST_OPTION_NONE },
    { NULL, NULL, NULL, NULL, 0 }
};

static const MunitSuite suite = {
    "DarBaixa_tests",
    tests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};

int main (int argc, char *argv[])
{
    setlocale(LC_ALL, "pt_BR.utf8");

    return munit_suite_main(&suite, NULL, argc, argv);
}