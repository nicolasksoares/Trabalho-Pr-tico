typedef struct dadosAssentos
{
    int idPassageiro;
    int numeroAssento;
    int codVoo;
    int status; // 0: Livre, 1: Ocupado
} Assento;

int i;
Assento assentos[99];
int totalAssento = 0;

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
        if (assentos[i].numeroAssento == numAssento && assentos[i].codVoo == codVoo)
        {
            if (assentos[i].status == 1)
            {
                assentos[i].status = 0;
                assentos[i].idPassageiro = 0;  // Limpar o ID do passageiro
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