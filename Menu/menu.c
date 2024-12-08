#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int op, r;
    do
    {
        do
        {
            printf("Escolha uma opcao\n"
                   "[1]Cadastrar Passageiro\n"
                   "[2]Cadastrar Tripulacao\n"
                   "[3]Cadastrar Voo\n"
                   "[4]Cadastrar Assento\n"
                   "[5]Reserva\n"
                   "[6]Baixa em reserva\n"
                   "[7]Pesquisa\n"
                   "[8]Programa de fidelidade\n");
            scanf("%d", &op);
            if (op > 8 || op < 0)
            {
                printf("Digite de 1 a 8!\n");
            }
        } while (op > 8 || op < 0);
        switch (op)
        {
        case 1:
            add();
            break;
        default:
            printf("Opcao invalida!\n");
            break;
        }
        r = continua();
    } while (r != 1);
    lerPassageiros();
    getchar();
    return 0;
}