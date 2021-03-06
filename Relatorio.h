void geraRelatorioVacinas(LISTA_VACINA * vacinas)
{
    if ( vacinas->pos_livre == 0 ) {
        printf("Lista de vacinas esta vazia, registre pelo menos uma vacina.\n");
    }

    FILE *arq;
    arq = fopen("relatorio-vacinas.txt", "w");

    int i;

    for ( i = 0; i < vacinas->pos_livre; i++ ) {
        fwrite("Nome da vacina: ", 1, 16, arq);
        fwrite(vacinas->item[i].nome, 1, strlen(vacinas->item[i].nome), arq);
        fwrite("\n", 1, 1, arq);

        fwrite("Numero de dose no estoque: ", 1, 27, arq);

        char str[10];
        memset(str, '\0', 10);
        sprintf(str,"%d",vacinas->item[i].estoque);
        fwrite(str, sizeof(char), strlen(str), arq);
        fwrite("\n", 1, 1, arq);
    }

    printf("Relatorio gerado com sucesso.\n");

    fclose(arq);
}

void geraRelatorioVacinadoDose1(LISTA_VACINACAO * vacinacao)
{
    if ( vacinacao->pos_livre == 0 ) {
        printf("Lista de vacinacao esta vazia, registre pelo menos uma vacinacao.\n");
    }

    int i;
    for ( i = 0; i < vacinacao->pos_livre; i++ ) {
        
    }
}