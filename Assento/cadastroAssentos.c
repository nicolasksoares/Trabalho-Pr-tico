#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define MAX_ASSENTOS 100

typedef struct dadosAssentos{
    int numeroAssento;
    int codVoo;
    int status;
} Assento;

int i;
Assento grupo[MAX_ASSENTOS];
int totalAssento = 0;
int cdVoo[50];

int verificarAssento(int numeroAssento, int codV)
{
    for (i = 0; i < totalAssento; i++){
        if (grupo[i].numeroAssento == numeroAssento && grupo[i].codVoo == codV)
            return 1;
    }
    return 0;
}

void cadastrarAssento()
{
    if (totalAssento >= MAX_ASSENTOS){
        printf("Número máximo de assentos atingido!\n");
        return;
    }
    int numAssento, codVoo;
    printf("Digite o número do assento: ");
    scanf("%d", &numAssento);
    if (numAssento < 0){
        printf("Número do assento inválido!\n");
        return;
    }
    printf("Digite o código do voo: ");
    scanf("%d", &codVoo);
    if (codVoo < 0 || codVoo > 50){
        printf("Código do voo inválido!\n");
        return;
    }
    if (verificarAssento(numAssento, codVoo)){
        printf("Assento já cadastrado!\n");
        return;
    }

    grupo[totalAssento].numeroAssento = numAssento;
    grupo[totalAssento].codVoo = codVoo;
    grupo[totalAssento].status = 0;
    totalAssento++;
    printf("Assento cadastrado com sucesso!\n");
}

void listarAssento()
{
    if (totalAssento == 0){
        printf("Nenhum assento cadastrado!\n");
        return;
    }
    for (i=0; i < totalAssento; i++){
        printf("Número do assento: %d\n", grupo[i].numeroAssento);
        printf("Código do voo: %d\n", grupo[i].codVoo);
        printf("Status: %s\n", grupo[i].status == 0? "Livre" : "Ocupado");
        printf("-----------------------------\n");
    }
}

int main(void){
    setlocale(LC_ALL, "pt_BR.utf8");

    int opcao;
    do{
        printf("Menu:\n"
                "[1] Cadastrar Assento\n"
                "[2] Listar Assento\n"
                "[3] Sair\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                cadastrarAssento();
                break;
            case 2:
                listarAssento();
                break;
            case 3:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida!\n");}
    } while(opcao!=3);
    getchar();
    return 0;
}