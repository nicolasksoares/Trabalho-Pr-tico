#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int i;

int verificarAssento(int numeroAssento, int codV)
{
    for (i = 0; i < totalAssento; i++)
    {
        if (grupo[i].numeroAssento == numeroAssento && grupo[i].codVoo == codV)
            return 1;
    }
    return 0;
}

int verificarPassageiro(int id)
{
    for (i = 0; i < n; i++)
    {
        if (passageiros[i].id == id)
            return 1;
    }
    return 0;
}


void reserva()
{
    if (totalAssento <= 0)
    {
        printf("Nenhum assento cadastrado!\n");
        return;
    }

    int numAssento, codVoo, codPassageiro;
    printf("Digite o número do assento para reserva: ");
    scanf("%d", &numAssento);
    printf("Digite o código do voo para reserva: ");
    scanf("%d", &codVoo);
    printf("Digite o código do passageiro para reserva: ");
    scanf("%d", &codPassageiro);

    // Verificar se o assento existe
    if (!verificarAssento(numAssento, codVoo))
    {
        printf("Assento ou voo não encontrados!\n");
        return;
    }

    // Verificar se o passageiro existe
    if (!verificarPassageiro(codPassageiro))
    {
        printf("Passageiro não encontrado!\n");
        return;
    }

    // Realizar a reserva
    for (i = 0; i < totalAssento; i++)
    {
        if (grupo[i].numeroAssento == numAssento && grupo[i].codVoo == codVoo)
        {
            if (grupo[i].status == 0)
            {
                grupo[i].status = 1;
                printf("Assento reservado com sucesso!\n");
                grupo[i].idPassgaeiro = codPassageiro;
                return;
            }
            else
            {
                printf("Assento já está ocupado!\n");
                return;
            }
        }
    }
}