void acumularPontos(int idPassageiro)
{
    for (int i = 0; i < MAX_PASSAGEIROS; i++)
    {
        if (passageiros[i].id == idPassageiro)
        {
            passageiros[i].pontos += 10; // Adiciona 10 pontos por voo
            printf("10 pontos adicionados ao passageiro %s (ID: %d). Total: %d pontos.\n",
                   passageiros[i].nome, idPassageiro, passageiros[i].pontos);
            return;
        }
    }
    printf("Erro: Passageiro com ID %d não encontrado.\n", idPassageiro);
}

// Função para consultar pontos de fidelidade pelo ID
void consultarPontos(int idPassageiro)
{
    for (int i = 0; i < MAX_PASSAGEIROS; i++)
    {
        if (passageiros[i].id == idPassageiro)
        {
            printf("Passageiro %s (ID: %d) possui %d pontos de fidelidade.\n",
                   passageiros[i].nome, idPassageiro, passageiros[i].pontos);
            return;
        }
    }
    printf("Erro: Passageiro com ID %d não encontrado.\n", idPassageiro);
}

void fidelidade()
{
    int opcao;
    do
    {
        printf("\nMenu de Programa de Fidelidade:\n"
               "[1] Consultar pontos de fidelidade\n"
               "[2] Acumular pontos\n"
               "[3] Sair\n"
               "Escolha uma opção: ");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            int idPassageiro;
            printf("Digite o ID do passageiro: ");
            scanf("%d", &idPassageiro);
            consultarPontos(idPassageiro);
            break;
        case 2:
            int idPassageiro2;
            printf("Digite o ID do passageiro: ");
            scanf("%d", &idPassageiro2);
            acumularPontos(idPassageiro2);
            break;
        case 3:
            printf("Saindo do menu de programa de fidelidade...\n");
            break;
        default:
            printf("Opção inválida!\n");
        }
    } while (opcao != 3);
}