#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ORIGEM_DESTINO 100
#define MAX_STATUS 10

// Definindo um enum para os status do voo
typedef enum {
    ATIVO,
    INATIVO
} StatusVoo;

// Definindo a estrutura do voo
typedef struct {
    int id_Voo;
    int id_Piloto;
    int id_Copiloto;
    int id_Comissario;
    StatusVoo status;
    float tarifa;
    char origem[MAX_ORIGEM_DESTINO];
    char destino[MAX_ORIGEM_DESTINO];
} Voo;

// Função para obter uma string não vazia do usuário
void obterEntradaStringNaoVazia(char* buffer, size_t tamanho, const char* prompt) {
    while (1) {
        printf("%s", prompt);
        getchar();  // Limpar buffer do teclado
        fgets(buffer, tamanho, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';  // Remover o '\n' do final
        if (strlen(buffer) > 0) {
            return;
        }
        printf("Erro: a entrada não pode ser vazia. Tente novamente.\n");
    }
}

// Função para obter um número inteiro positivo
int obterEntradaInteiraPositiva(const char* prompt) {
    int valor;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &valor) == 1 && valor > 0) {
            return valor;
        }
        printf("Erro: insira um valor numérico positivo.\n");
        while (getchar() != '\n');  // Limpar o buffer
    }
}

// Função para obter um número de ponto flutuante positivo (tarifa)
float obterEntradaFloatPositivo(const char* prompt) {
    float valor;
    while (1) {
        printf("%s", prompt);
        if (scanf("%f", &valor) == 1 && valor > 0) {
            return valor;
        }
        printf("Erro: insira um valor numérico positivo.\n");
        while (getchar() != '\n');  // Limpar o buffer
    }
}

// Função para obter o status do voo (ativo ou inativo)
StatusVoo obterStatusVoo() {
    char status[MAX_STATUS];
    while (1) {
        printf("Insira o status do voo (ativo/inativo): ");
        scanf("%s", status);
        if (strcmp(status, "ativo") == 0) {
            return ATIVO;
        } else if (strcmp(status, "inativo") == 0) {
            return INATIVO;
        }
        printf("Erro: o status deve ser 'ativo' ou 'inativo'. Tente novamente.\n");
    }
}

// Função para registrar um voo
void registrarVoo(Voo *voo, int id) {
    voo->id_Voo = id;

    obterEntradaStringNaoVazia(voo->origem, sizeof(voo->origem), "Insira a origem do voo: ");
    obterEntradaStringNaoVazia(voo->destino, sizeof(voo->destino), "Insira o destino do voo: ");
    voo->id_Piloto = obterEntradaInteiraPositiva("Insira o id do piloto: ");
    voo->id_Copiloto = obterEntradaInteiraPositiva("Insira o id do copiloto: ");
    voo->id_Comissario = obterEntradaInteiraPositiva("Insira o id do comissário: ");
    voo->status = obterStatusVoo();
    voo->tarifa = obterEntradaFloatPositivo("Insira a tarifa do voo: ");
}

// Função para exibir os dados de um voo
void exibirVoo(const Voo *voo) {
    printf("\nVoo ID: %d\n", voo->id_Voo);
    printf("Origem: %s\n", voo->origem);
    printf("Destino: %s\n", voo->destino);
    printf("Piloto ID: %d\n", voo->id_Piloto);
    printf("Copiloto ID: %d\n", voo->id_Copiloto);
    printf("Comissário ID: %d\n", voo->id_Comissario);
    printf("Status: %s\n", voo->status == ATIVO ? "ativo" : "inativo");
    printf("Tarifa: %.2f\n", voo->tarifa);
}

// Função para validar e garantir que o número de voos seja válido
int obterQuantidadeDeVoos() {
    int quantidade;
    while (1) {
        quantidade = obterEntradaInteiraPositiva("Informe a quantidade de voos para serem registrados: ");
        if (quantidade > 0) {
            return quantidade;
        }
        printf("Erro: a quantidade de voos deve ser maior que 0.\n");
    }
}

int main() {
    int quantidade = obterQuantidadeDeVoos();

    // Alocar dinamicamente a memória para os voos
    Voo *voos = (Voo *)malloc(quantidade * sizeof(Voo));
    if (voos == NULL) {
        fprintf(stderr, "Erro: falha na alocação de memória.\n");
        return 1;
    }

    // Registrar os voos
    for (int i = 0; i < quantidade; i++) {
        printf("\n--- Registro do Voo %d ---\n", i + 1);
        registrarVoo(&voos[i], i + 1);
    }

    // Exibir os voos registrados
    printf("\n--- Dados dos Voos Registrados ---\n");
    for (int i = 0; i < quantidade; i++) {
        exibirVoo(&voos[i]);
    }

    // Liberar memória alocada
    free(voos);

    return 0;
}
