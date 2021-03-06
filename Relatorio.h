/**
 * Imprime o relatorio de vacinas
 * 
 * @param LISTA_VACINA * vacinas ponteiro para a estrutura de LISTA_VACINA
 */
void geraRelatorioVacinas(LISTA_VACINA * vacinas)
{
    // Verifica se a lista de vacinas eh vazia
    if ( vacinas->pos_livre == 0 ) {
        printf("Lista de vacinas esta vazia, registre pelo menos uma vacina.\n");
        return;
    }

    int i;

    printf("-------------------------------- RELATORIO VACINAS --------------------------------\n\n");

    // Percorre todos os registros de vacinas
    for ( i = 0; i < vacinas->pos_livre; i++ ) {
        printf("Nome da vacina: %s\n", vacinas->item[i].nome);
        printf("Numero de doses no estoque: %d\n", vacinas->item[i].estoque);
        printf("\n");
    }
    printf("\n");
    printf("\n");
}

/**
 * Imprime o relatorio de vacinados com a primeira dose
 * 
 * @param LISTA_VACINACAO * vacinacao ponteiro para a estrutura de LISTA_VACINACAO
 */
void geraRelatorioVacinadoDose1(LISTA_VACINACAO * vacinacao)
{
    // Verifica se a lista de vacinacao eh vazia
    if ( vacinacao->pos_livre == 0 ) {
        printf("Lista de vacinacao esta vazia, registre pelo menos uma vacinacao.\n");
        return;
    }

    printf("-------------------------------- RELATORIO DE PESSOAS QUE VACINOU COM A PRIMEIRA DOSE --------------------------------\n\n");

    int i;
    // Percorre todos os registros de vacinacao
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

/**
 * Imprime o relatorio de vacinados com a segunda dose
 * 
 * @param LISTA_VACINACAO * vacinacao ponteiro para a estrutura de LISTA_VACINACAO
 */
void geraRelatorioVacinadoDose2(LISTA_VACINACAO * vacinacao)
{
    // Verifica se a lista de vacinacao eh vazia
    if ( vacinacao->pos_livre == 0 ) {
        printf("Lista de vacinacao esta vazia, registre pelo menos uma vacinacao.\n");
        return;
    }

    printf("-------------------------------- RELATORIO DE PESSOAS QUE VACINOU COM A SEGUNDA DOSE --------------------------------\n\n");

    int i;
    // Percorre todos os registros de vacinacao
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

/**
 * Imprime o relatorio de nao vacinados, ordenados pelo grupo de prioridade
 * 
 * @param LISTA * l ponteiro para a estrutura de LISTA de pessoas
 */
void geraRelatorioNaoVacinados (LISTA *l) {

    // Verifica se a lista de pessoas esta vazia
    if ( l->pos_livre == 0 ) {
        printf("Lista de pessoas esta vazia, registre pelo menos uma pessoa.\n");
        return;
    }

    int i;

    printf("---------------------------- RELATORIO NAO VACINADOS ------------------------------\n\n");
    printf("Grupo prioriatario 1:\n");
    for ( i=0; i < l->pos_livre; i++ ) {
        if ( foundVacinacaoByCpf(l, l->item[i].cpf) ) {
            if( l->item[i].prioridade == 1)
                printf("'%s' do CPF: '%s' nao foi vacinado(a)\n", l->item[i].nome, l->item[i].cpf);
        }
    }

    printf("\n---------------------------------------------------------------------------------\n");
    printf("Grupo prioriatario 2:\n");
    for ( i=0; i < l->pos_livre; i++ ) {
        if ( foundVacinacaoByCpf(l, l->item[i].cpf) ) {
            if( l->item[i].prioridade == 2)
                printf("'%s' do CPF: '%s' nao foi vacinado(a)\n", l->item[i].nome, l->item[i].cpf);
        }
    }

    printf("\n---------------------------------------------------------------------------------\n");
    printf("Grupo prioriatario 3:\n");
    for ( i=0; i < l->pos_livre; i++ ) {
        if ( foundVacinacaoByCpf(l, l->item[i].cpf) ) {
            if( l->item[i].prioridade == 3)
                printf("'%s' do CPF: '%s' nao foi vacinado(a)\n", l->item[i].nome, l->item[i].cpf);
        }
    }

    printf("\n---------------------------------------------------------------------------------\n");
    printf("Grupo prioriatario 4:\n");
    for ( i=0; i < l->pos_livre; i++ ) {
        if ( foundVacinacaoByCpf(l, l->item[i].cpf) ) {
            if( l->item[i].prioridade == 4)
                printf("'%s' do CPF: '%s' nao foi vacinado(a)\n", l->item[i].nome, l->item[i].cpf);
        }
    }

    printf("\n---------------------------------------------------------------------------------\n");
    printf("Grupo prioriatario 5:\n");
    for ( i=0; i < l->pos_livre; i++ ) {
        if ( foundVacinacaoByCpf(l, l->item[i].cpf) ) {
            if( l->item[i].prioridade == 5)
                printf("'%s' do CPF: '%s' nao foi vacinado(a)\n", l->item[i].nome, l->item[i].cpf);
            }
    }
    printf("\n");
}

/**
 * Imprime o relatorio numero de habitantes por grupo prioritario
 * 
 * @param LISTA * l ponteiro para a estrutura de LISTA de pessoas
 */
void geraRelatorioPrioritario (LISTA *l) {

    // Verifica se a lista de pessoas esta vazia
    if ( l->pos_livre == 0 ) {
        printf("Lista de pessoas esta vazia, registre pelo menos uma pessoa.\n");
        return;
    }

    int i, g1=0, g2=0, g3=0, g4=0, g5=0;

    for(i=0; i < l->pos_livre; i++) {
        if(l->item[i].prioridade == 1) g1++;
        if(l->item[i].prioridade == 2) g2++;
        if(l->item[i].prioridade == 3) g3++;
        if(l->item[i].prioridade == 4) g4++;
        if(l->item[i].prioridade == 5) g5++;
    }

    printf("------------------------- RELATORIO NUMERO DE HABITANTES --------------------------\n\n");
    printf("Numero de habitantes registrados como grupo prioritario 1: %d\n", g1);
    printf("Numero de habitantes registrados como grupo prioritario 2: %d\n", g2);
    printf("Numero de habitantes registrados como grupo prioritario 3: %d\n", g3);
    printf("Numero de habitantes registrados como grupo prioritario 4: %d\n", g4);
    printf("Numero de habitantes registrados como grupo prioritario 5: %d\n", g5);
    printf("\n---------------------------------------------------------------------------------\n");
}