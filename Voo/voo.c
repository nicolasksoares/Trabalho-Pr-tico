#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int id_Voo;
    int id_Piloto;
    int id_Copiloto;
    int id_Comissario;
    char status[10];
    int tarifa;
    int hora;
    int data;
    char nome[100];
} VOO;

int main() {
    int i = 0, quantidade = 0;

    printf("Informe a quantidade de voos para serem registrados: \n");
    scanf("%d", &quantidade);

    if (quantidade <= 0) {
        printf("Quantidade de voos inválida.\n");
        return 1;
    }

    VOO voo[quantidade];

    // Atribuindo o id de cada voo
    for (i = 0; i < quantidade; i++) {
        voo[i].id_Voo = i + 1;
    }

    for (i=0;i<quantidade;i++) {
        printf("\nRegistrando dados do voo %d \n",i+1);

    // Inserção do código do piloto
        printf("Insira o id do piloto:\n", voo[i].id_Voo);
        scanf("%d", &voo[i].id_Piloto);

    // Inserção do código do copiloto
        printf("Insira o id do Copiloto:\n", voo[i].id_Voo);
        scanf("%d", &voo[i].id_Copiloto);

    // Inserir do código do comissário
        printf("Insira o id do Comissario:\n", voo[i].id_Voo);
        scanf("%d", &voo[i].id_Comissario);      

        printf("Insira se o voo id = %d esta ativo ou inativo \n", voo[i].id_Voo);
        scanf("%s",voo[i].status);  

    }
    printf("\n");

    // Exibindo os dados de cada voo
    for (i=0; i<quantidade;i++) {
        printf("\nVoo %d: id = %d\n"
               "Piloto: id = %d\n"
               "Copiloto: id = %d\n"
               "Comissario: id = %d\n"
               "Status do voo: %s\n"
               "Tarifa:\n", 
               i + 1, voo[i].id_Voo, voo[i].id_Piloto, voo[i].id_Copiloto, voo[i].id_Comissario,
               voo[i].status, voo[i].tarifa);
    }

    return 0;
}
