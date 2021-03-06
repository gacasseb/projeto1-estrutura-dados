void geraRelatorioVacinas(LISTA_VACINA * vacinas)
{
    if ( vacinas->pos_livre == 0 ) {
        printf("Lista de vacinas esta vazia, registre pelo menos uma vacina.\n");
        return;
    }

    int i;

    printf("-------------------------------- RELATORIO VACINAS --------------------------------\n\n");

    for ( i = 0; i < vacinas->pos_livre; i++ ) {

        printf("Nome da vacina: %s\n", vacinas->item[i].nome);
        printf("Numero de doses no estoque: %d\n", vacinas->item[i].estoque);
        printf("\n");
    }
    printf("\n");
    printf("\n");
}

void geraRelatorioVacinadoDose1(LISTA_VACINACAO * vacinacao)
{
    if ( vacinacao->pos_livre == 0 ) {
        printf("Lista de vacinacao esta vazia, registre pelo menos uma vacinacao.\n");
        return;
    }

    printf("-------------------------------- RELATORIO DE PESSOAS QUE VACINOU COM A PRIMEIRA DOSE --------------------------------\n\n");

    int i;
    for ( i = 0; i < vacinacao->pos_livre; i++ ) {
        if ( vacinacao->item[i].dose == 1 ) {
            printf("Nome: %s\n", vacinacao->item[i].nome_pessoa);
            printf("CPF: %s\n", vacinacao->item[i].cpf_pessoa);
            printf("\n");
        }
    }
    printf("\n");
    printf("\n");
}

void geraRelatorioVacinadoDose2(LISTA_VACINACAO * vacinacao)
{
    if ( vacinacao->pos_livre == 0 ) {
        printf("Lista de vacinacao esta vazia, registre pelo menos uma vacinacao.\n");
        return;
    }

    printf("-------------------------------- RELATORIO DE PESSOAS QUE VACINOU COM A SEGUNDA DOSE --------------------------------\n\n");

    int i;
    for ( i = 0; i < vacinacao->pos_livre; i++ ) {
        if ( vacinacao->item[i].dose == 2 ) {
            printf("Nome: %s\n", vacinacao->item[i].nome_pessoa);
            printf("CPF: %s\n", vacinacao->item[i].cpf_pessoa);
            printf("\n");
        }
    }
    printf("\n");
    printf("\n");
}