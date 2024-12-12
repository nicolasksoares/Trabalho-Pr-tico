
// Função para buscar passageiros pelo nome ou código
void buscarPassageiro()
{
    int opcao;
    printf("Pesquisar Passageiro:\n[1] Pelo Nome\n[2] Pelo Código\nEscolha uma opção: ");
    scanf("%d", &opcao);

    if (opcao == 1)
    {
        char nomeBusca[CHAR_MAX];
        getchar(); 
        printf("Digite o nome do passageiro: ");
        fgets(nomeBusca, sizeof(nomeBusca), stdin);
        nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

        int encontrado = 0;
        for (int i = 0; i < n; i++)
        {
            if (strstr(passageiros[i].nome, nomeBusca))
            {
                printf("ID: %d\nNome: %s\nEndereco: %s\nTelefone: %s\nFidelidade: %s\n\n",
                       passageiros[i].id, passageiros[i].nome, passageiros[i].endereco,
                       passageiros[i].telefone, passageiros[i].fidelidade == 1 ? "Sim" : "Não");
                encontrado = 1;
            }
        }

        if (!encontrado)
        {
            printf("Nenhum passageiro encontrado com este nome informado.\n");
        }
    }
    else if (opcao == 2)
    {
        int codigoBusca;
        printf("Digite o código do passageiro: ");
        scanf("%d", &codigoBusca);

        int encontrado = 0;
        for (int i = 0; i < n; i++)
        {
            if (passageiros[i].id == codigoBusca)
            {
                printf("ID: %d\nNome: %s\nEndereco: %s\nTelefone: %s\nFidelidade: %s\n\n",
                       passageiros[i].id, passageiros[i].nome, passageiros[i].endereco,
                       passageiros[i].telefone, passageiros[i].fidelidade == 1 ? "Sim" : "Não");
                encontrado = 1;
                break;
            }
        }

        if (!encontrado)
        {
            printf("Nenhum passageiro encontrado com o código informado.\n");
        }
    }
    else
    {
        printf("Opção inválida.\n");
    }
}

// Função para buscar membros da tripulação pelo nome ou código
void buscarTripulante()
{
    int opcao;
    printf("Pesquisar Tripulante:\n[1] Pelo Nome\n[2] Pelo Código\nEscolha uma opção: ");
    scanf("%d", &opcao);

    if (opcao == 1)
    {
        char nomeBusca[CHAR_MAX];
        getchar(); // Limpa o buffer do teclado
        printf("Digite o nome do tripulante: ");
        fgets(nomeBusca, sizeof(nomeBusca), stdin);
        nomeBusca[strcspn(nomeBusca, "\n")] = '\0';

        int encontrado = 0;
        for (int i = 0; i < quantidadeTripulacao; i++)
        {
            if (strstr(tripulacao[i].nome, nomeBusca))
            {
                printf("ID: %d\nNome: %s\nCargo: %s\nTelefone: %s\n\n",
                       tripulacao[i].id, tripulacao[i].nome, tripulacao[i].cargo, tripulacao[i].telefone);
                encontrado = 1;
            }
        }

        if (!encontrado)
        {
            printf("Nenhum tripulante encontrado com o este nome.\n");
        }
    }
    else if (opcao == 2)
    {
        int codigoBusca;
        printf("Digite o código do tripulante: ");
        scanf("%d", &codigoBusca);

        int encontrado = 0;
        for (int i = 0; i < quantidadeTripulacao; i++)
        {
            if (tripulacao[i].id == codigoBusca)
            {
                printf("ID: %d\nNome: %s\nCargo: %s\nTelefone: %s\n\n",
                       tripulacao[i].id, tripulacao[i].nome, tripulacao[i].cargo, tripulacao[i].telefone);
                encontrado = 1;
                
            }
        }

        if (!encontrado)
        {
            printf("Nenhum tripulante encontrado.\n");
        }
    }
    else
    {
        printf("Opção inválida.\n");
    }
}

// Função para listar todos os voos de um passageiro
void listarVoosPassageiro()
{
    int codigoPassageiro;
    printf("Digite o código do passageiro: ");
    scanf("%d", &codigoPassageiro);

    if (!verificarPassageiro(codigoPassageiro))
    {
        printf("Passageiro não encontrado.\n");
        return;
    }

    int encontrado = 0;
    printf("\nVoos do Passageiro ID %d:\n", codigoPassageiro);
    for (int i = 0; i < totalAssento; i++)
    {
        if (grupo[i].status == 1 && grupo[i].IDpessoa == codigoPassageiro)
        {
            for (int j = 0; j < totalVoos; j++)
            {
                if (grupo[i].codVoo == voos[j].id_Voo)
                {
                    printf("Voo ID: %d\nOrigem: %s\nDestino: %s\nTarifa: %.2f\n\n",
                           voos[j].id_Voo, voos[j].origem, voos[j].destino, voos[j].tarifa);
                    encontrado = 1;
                }
            }
        }
    }

    if (!encontrado)
    {
        printf("Nenhum voo encontrado para este passageiro.\n");
    }
}

// Menu de pesquisa
void pesquisa()
{
    int opcao;
    do
    {
        printf("\nMenu de Pesquisa:\n"
               "[1] Buscar Passageiro\n"
               "[2] Buscar Tripulante\n"
               "[3] Listar Voos de Passageiro\n"
               "[4] Sair\n"
               "Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            buscarPassageiro();
            break;
        case 2:
            buscarTripulante();
            break;
        case 3:
            listarVoosPassageiro();
            break;
        case 4:
            printf("Saindo do menu de pesquisa...\n");
            break;
        default:
            printf("Opção inválida!\n");
        }
    } while (opcao != 4);
}