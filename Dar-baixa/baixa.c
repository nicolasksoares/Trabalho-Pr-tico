void darBaixa()
{
    int numAssento, codVoo;
    printf("Digite o número do assento: ");
    scanf("%d", &numAssento);
    printf("Digite o código do voo: ");
    scanf("%d", &codVoo);
    // Verificar se o assento existe
    if (!verificarAssento(numAssento, codVoo))
    {
        printf("Assento ou voo não encontrados!\n");
        return;
    }
    // Realizar a baixa
    for (i = 0; i < totalAssento; i++)
    {
        if (grupo[i].numeroAssento == numAssento && grupo[i].codVoo == codVoo)
        {
            if (grupo[i].status == 1)
            {
                grupo[i].status = 0;
                printf("Assento baixado com sucesso!\n");
                return;
            }
            else
            {
                printf("Assento não está reservado!\n");
                return;
            }
        }
    }
}