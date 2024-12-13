#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "../munit/munit.c"
#include "../munit/munit.h"

#define CHAR_MAX 100
#define MAX_ASSENTOS 9999
#define MAX_PASSAGEIROS 9999
#define MAX_TRIPULACAO 9999
#define MAX_VOOS 999

typedef struct dadosAssentos
{
    int idPassageiro;
    int numeroAssento;
    int codVoo;
    int status; // 0: Livre, 1: Ocupado
} Assento;

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

typedef struct cadastroPassageiro {
    int id;
    char nome[CHAR_MAX];
    char endereco[CHAR_MAX];
    char telefone[CHAR_MAX];
    int fidelidade; // 1: Sim, 2: Não
    int pontos;
} Passageiro;

typedef struct {
    int id;
    char nome[25];
    int cargo; // 1: Piloto, 2: Copiloto, 3: Comissário
    char telefone[CHAR_MAX]; 
} Tripulacao;

int totalVoos = 0;
int quantidadeTripulacao = 3; // Número de tripulantes
int totalAssento = 0;
Tripulacao tripulacao[MAX_TRIPULACAO] = {
    {1, "Neymar", 1, "40028922"},
    {2, "Lionel Messi", 2, "987654321"},
    {3, "Cristiano Ronaldo", 3, "1122334455"}
};
int n=3;
Passageiro passageiros[MAX_PASSAGEIROS] = {
    {1, "Wesley", "Rua 170", "987654321", 1, 100},
    {2, "Pedro", "Avenida 051, 789", "123456789", 1, 200},
    {3, "Maria", "Rua 017, 123", "321654987", 2, 150}
};
Assento grupo[MAX_ASSENTOS];
Voo voos[MAX_VOOS];

int buscarPassageiro(int opcao, const char* busca) {
    if (opcao == 1) { 
        int encontrado = 0;
        for (int i = 0; i < n; i++) {
            if (strstr(passageiros[i].nome, busca)) {
                return 1; 
            }
        }
        return 0; 
    } else if (opcao == 2) {
        int codigoBusca = atoi(busca);
        int encontrado = 0;
        for (int i = 0; i < n; i++) {
            if (passageiros[i].id == codigoBusca) {
                return 1; 
            }
        }
        return 0; 
    }
    return 0; // Opção inválida
}

int buscarTripulante(int opcao, char *input) {
    if (opcao == 1) { 
        int encontrado = 0;
        for (int i = 0; i < quantidadeTripulacao; i++) {
            if (strstr(tripulacao[i].nome, input)) {
               return 1;
            }
        }
        if (!encontrado) {
           return 0;
        }
    } else if (opcao == 2) {  // Busca por código
        int codigoBusca = atoi(input);
        int encontrado = 0;
        for (int i = 0; i < quantidadeTripulacao; i++) {
            if (tripulacao[i].id == codigoBusca) {
                return 1;
            }
        }
        if (!encontrado) {
            return 0;
        }
    } else {
        return 0;
    }
}

int verificarPassageiro(int codigoPassageiro) {
    for (int i = 0; i < n; i++) {
        if (passageiros[i].id == codigoPassageiro) {
            return 1; // Passageiro encontrado
        }
    }
    return 0; // Passageiro não encontrado
}

int listarVoosPassageiro(int codigoPassageiro) {
    if (!verificarPassageiro(codigoPassageiro)) {
        printf("Passageiro não encontrado.\n");
        return 0; // Passageiro não encontrado
    }

    int encontrado = 0;
    printf("\nVoos do Passageiro ID %d:\n", codigoPassageiro);
    for (int i = 0; i < totalAssento; i++) {
        if (grupo[i].status == 1 && grupo[i].idPassageiro == codigoPassageiro) {
            for (int j = 0; j < totalVoos; j++) {
                if (grupo[i].codVoo == voos[j].id) {
                    printf("Voo ID: %d, Origem: %s, Destino: %s, Data: %s, Hora: %s, Tarifa: %.2f\n",
                        voos[j].id, voos[j].origem, voos[j].destino, voos[j].data, voos[j].hora, voos[j].tarifa);
                    encontrado = 1;
                }
            }
        }
    }

    if (!encontrado) {
        printf("Nenhum voo encontrado para este passageiro.\n");
    }

    return 1; // Listagem concluída
}

// Função de pesquisa
int pesquisa(int opcao) {
    switch (opcao) {
        case 1:
        case 2:
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
    "4",
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

   munit_assert_int(pesquisa(input), ==, expected);
   return MUNIT_OK;
};

static MunitResult test_buscarTripulante_nome(const MunitParameter params[], void *data){
    munit_assert_int(buscarTripulante(1, "Neymar"), ==, 1);   
    munit_assert_int(buscarTripulante(1, "Ney"), ==, 0);    
    return MUNIT_OK;
};

static MunitResult test_buscarTripulante_codigo(const MunitParameter params[], void *data){
    munit_assert_int(buscarTripulante(2, "1"), ==, 1);
    munit_assert_int(buscarTripulante(2, "99999"), ==, 0);
    munit_assert_int(buscarTripulante(3, "99999"), ==, 0);
    return MUNIT_OK;
};

static MunitResult test_buscarPassageiro_nome(const MunitParameter params[], void *data){
    munit_assert_int(buscarPassageiro(1, "Wesley"), ==, 1);
    munit_assert_int(buscarPassageiro(1, "Ma"), ==, 0);
    return MUNIT_OK;
};

static MunitResult test_buscarPassageiro_codigo(const MunitParameter params[], void *data){
    munit_assert_int(buscarPassageiro(2, "1"), ==, 1);
    munit_assert_int(buscarPassageiro(2, "99999"), ==, 0);
    munit_assert_int(buscarPassageiro(3, "333"), ==, 0);
    return MUNIT_OK;
};

static MunitResult test_listarVoosPassageiro(const MunitParameter params[], void *data) {
    // Preencher os assentos para o teste
    grupo[0] = (Assento){1, 10, 1, 1};  // Passageiro 1, Assento 10, Voo 1
    grupo[1] = (Assento){2, 12, 2, 1};  // Passageiro 2, Assento 12, Voo 2
    grupo[2] = (Assento){1, 15, 3, 1};  // Passageiro 1, Assento 15, Voo 3
    totalAssento = 3;  
    totalVoos = 3;     

    // Preencher os voos para o teste
    voos[0] = (Voo){1, "2024-12-20", "10:00", "São Paulo", "Rio de Janeiro", 101, 1, 2, 3, 1, 300.0};
    voos[1] = (Voo){2, "2024-12-21", "14:00", "Rio de Janeiro", "São Paulo", 102, 1, 2, 3, 1, 350.0};
    voos[2] = (Voo){3, "2024-12-22", "18:00", "São Paulo", "Salvador", 103, 1, 2, 3, 1, 400.0};

    munit_assert_int(listarVoosPassageiro(1), ==, 1);  

    munit_assert_int(listarVoosPassageiro(2), ==, 1);  

    munit_assert_int(listarVoosPassageiro(999), ==, 0); 

    munit_assert_int(listarVoosPassageiro(-5), ==, 0); 

    return MUNIT_OK;
};

static MunitTest tests[] = {
    {"/test_menu", test_menu, NULL, NULL, MUNIT_TEST_OPTION_NONE, test_params},
    {"/test_buscarTripulante_nome", test_buscarTripulante_nome, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/test_buscarTripulante_codigo", test_buscarTripulante_codigo, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/test_buscarPassageiro_nome", test_buscarPassageiro_nome, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/test_buscarPassageiro_codigo", test_buscarPassageiro_codigo, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/test_listarVoosPassageiro", test_listarVoosPassageiro, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

static MunitTest suite = {
    "Menu_tests",
    tests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE,
};

int main(int argc, char *argv[]){
    return munit_suite_main(&suite, NULL, argc, argv);
}
