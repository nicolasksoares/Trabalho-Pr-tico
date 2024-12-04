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
    float tarifa;
    int hora;
    int data;
    char origem[100];
    char destino[100];
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

    // Registrando os dados de cada voo
    for (i = 0; i < quantidade; i++) {
        printf("\nRegistrando dados do voo %d \n", i + 1);

        getchar();

        // Inserção da origem do voo
        printf("Insira a origem do voo: \n");
        fgets(voo[i].origem, 100, stdin);
        voo[i].origem[strcspn(voo[i].origem, "\n")] = '\0'; 

        // Inserção do destino do voo
        printf("Insira o destino do voo: \n");
        fgets(voo[i].destino, 100, stdin);
        voo[i].destino[strcspn(voo[i].destino, "\n")] = '\0'; 

        // Inserção do código do piloto
        printf("Insira o id do piloto para o voo id = %d: \n", voo[i].id_Voo);
        scanf("%d", &voo[i].id_Piloto);

        // Inserção do código do copiloto
        printf("Insira o id do Copiloto para o voo id = %d: \n", voo[i].id_Voo);
        scanf("%d", &voo[i].id_Copiloto);

        // Inserção do código do comissário
        printf("Insira o id do Comissario para o voo id = %d: \n", voo[i].id_Voo);
        scanf("%d", &voo[i].id_Comissario);

        // Inserção do status do voo
        printf("Insira se o voo id = %d esta ativo ou inativo: \n", voo[i].id_Voo);
        scanf("%s", voo[i].status);

        // Inserção da tarifa do voo
        printf("Insira a tarifa do voo id = %d: \n", voo[i].id_Voo);
        scanf("%f", &voo[i].tarifa);
    }

    // Exibindo os dados de cada voo
    for (i = 0; i < quantidade; i++) {
        printf("\nVoo %d: id = %d\n"
               "Origem: %s\n"
               "Destino: %s\n"
               "Piloto: id = %d\n"
               "Copiloto: id = %d\n"
               "Comissario: id = %d\n"
               "Status do voo: %s\n"
               "Tarifa: %.2f\n", 
               i + 1, voo[i].id_Voo, voo[i].origem, voo[i].destino, 
               voo[i].id_Piloto, voo[i].id_Copiloto, voo[i].id_Comissario,
               voo[i].status, voo[i].tarifa);
    }

    return 0;
}
