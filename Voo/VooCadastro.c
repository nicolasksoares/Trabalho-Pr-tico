#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING 100
#define MAX_VOOS 10  // Máximo de voos que podemos registrar

// Estrutura para armazenar informações do voo
typedef struct {
    int id;
    char data[MAX_STRING];
    char hora[MAX_STRING];
    char origem[MAX_STRING];
    char destino[MAX_STRING];
    int idAviao;
    int idPiloto;
    int idCopiloto;
    int idComissario;
    int status; // 1 para Ativo, 2 para Inativo
    float tarifa;
} Voo;

Voo voos[MAX_VOOS]; 
int totalVoos = 0;

// Função para obter uma string válida
void obterString(char mensagem[], char destino[]) {
    while (1) {
        printf("%s", mensagem);
        fgets(destino, MAX_STRING, stdin);
        destino[strcspn(destino, "\n")] = '\0'; 
        if (strlen(destino) > 0) {
            break;
        }
        printf("Erro: O valor não pode ser vazio. Tente novamente.\n");
    }
}

// Função para obter um número inteiro positivo
int obterInteiro(char mensagem[]) {
    int valor;
    while (1) {
        printf("%s", mensagem);
        if (scanf("%d", &valor) == 1 && valor > 0) {
            getchar(); 
            return valor;
        }
        printf("Erro: Insira um número inteiro positivo.\n");
        while (getchar() != '\n'); 
    }
}

// Função para obter um número decimal positivo
float obterFloat(char mensagem[]) {
    float valor;
    while (1) {
        printf("%s", mensagem);
        if (scanf("%f", &valor) == 1 && valor > 0) {
            getchar(); 
            return valor;
        }
        printf("Erro: Insira um número decimal positivo.\n");
        while (getchar() != '\n'); 
    }
}

// Função para validar a data
int validarData(char data[]) {
    int dia, mes, ano;
    if (sscanf(data, "%d/%d/%d", &dia, &mes, &ano) == 3 && ano > 1900 && ano <= 2100 && mes >= 1 && mes <= 12 && dia >= 1 && dia <= 31) {
        return 1;
    }
    printf("Data inválida. Tente novamente.\n");
    return 0;
}

// Função para validar a hora
int validarHora(char hora[]) {
    int horas, minutos;
    if (sscanf(hora, "%d:%d", &horas, &minutos) == 2 && horas >= 0 && horas < 24 && minutos >= 0 && minutos < 60) {
        return 1;
    }
    printf("Hora inválida. Tente novamente.\n");
    return 0;
}

// Função para verificar duplicidade de voo
int verificarDuplicidade(Voo voos[], int total, Voo novoVoo) {
    for (int i = 0; i < total; i++) {
        if (strcmp(voos[i].data, novoVoo.data) == 0 && strcmp(voos[i].hora, novoVoo.hora) == 0) {
            if (voos[i].idAviao == novoVoo.idAviao ||
                voos[i].idPiloto == novoVoo.idPiloto ||
                voos[i].idCopiloto == novoVoo.idCopiloto ||
                voos[i].idComissario == novoVoo.idComissario ||
                strcmp(voos[i].origem, novoVoo.origem) == 0 && strcmp(voos[i].destino, novoVoo.destino) == 0) {
                return 1; // Duplicidade encontrada
            }
        }
    }
    return 0;
}

// Função para registrar um voo
void registrarVoo(int index) {
    do {
        obterString("Insira a data do voo (DD/MM/AAAA): ", voos[index].data);
    } while (!validarData(voos[index].data));

    do {
        obterString("Insira a hora do voo (HH:MM): ", voos[index].hora);
    } while (!validarHora(voos[index].hora));

    obterString("Insira a origem do voo: ", voos[index].origem);
    obterString("Insira o destino do voo: ", voos[index].destino);

    voos[index].idAviao = obterInteiro("Insira o ID do avião: ");
    voos[index].idPiloto = obterInteiro("Insira o ID do piloto: ");
    voos[index].idCopiloto = obterInteiro("Insira o ID do copiloto: ");
    voos[index].idComissario = obterInteiro("Insira o ID do comissário: ");

    do {
        voos[index].status = obterInteiro("Insira o status do voo ([1] Ativo / [2] Inativo): ");
        if (voos[index].status != 1 && voos[index].status != 2) {
            printf("Status inválido. Tente novamente.\n");
        }
    } while (voos[index].status != 1 && voos[index].status != 2);

    voos[index].tarifa = obterFloat("Insira a tarifa do voo: ");

    if (verificarDuplicidade(voos, totalVoos, voos[index])) {
        printf("Erro: Voo duplicado. Insira os dados novamente.\n");
        registrarVoo(index);  // Tentar novamente para o mesmo índice
    }
}

// Função para exibir os dados de um voo
void exibirVoo(int index) {
    printf("\n--- Dados do Voo ---\n");
    printf("ID do Voo: %d\n", voos[index].id);
    printf("Data: %s\n", voos[index].data);
    printf("Hora: %s\n", voos[index].hora);
    printf("Origem: %s\n", voos[index].origem);
    printf("Destino: %s\n", voos[index].destino);
    printf("ID do Avião: %d\n", voos[index].idAviao);
    printf("ID do Piloto: %d\n", voos[index].idPiloto);
    printf("ID do Copiloto: %d\n", voos[index].idCopiloto);
    printf("ID do Comissário: %d\n", voos[index].idComissario);
    printf("Status: %s\n", voos[index].status == 1 ? "Ativo" : "Inativo");
    printf("Tarifa: %.2f\n", voos[index].tarifa);
}

// Função para exibir menu e gerenciar voos
void vooOpcoes() {
    int opcao = 0;

    while (1) {
        printf("\n--- Menu de Voos ---\n");
        printf("[1] Registrar voo\n");
        printf("[2] Exibir voos registrados\n");
        printf("[3] Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();  // Limpar o buffer de entrada

        switch (opcao) {
            case 1:
                if (totalVoos < MAX_VOOS) {
                    printf("\n--- Registro do Voo %d ---\n", totalVoos + 1);
                    voos[totalVoos].id = totalVoos + 1;
                    registrarVoo(totalVoos);  // Passando o índice em vez de ponteiro
                    totalVoos++;
                } else {
                    printf("Limite máximo de voos atingido.\n");
                }
                break;
            case 2:
                printf("\n--- Voos Registrados ---\n");
                for (int i = 0; i < totalVoos; i++) {
                    exibirVoo(i);  // Passando o índice em vez de ponteiro
                }
                break;
            case 3:
                printf("Saindo...\n");
                return;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }
}

int main() {
    vooOpcoes();
    return 0;
}
