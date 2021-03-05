#define MAX_TAM 6

typedef struct PRIORIDADE {
    int liberado;
} PRIORIDADE;

typedef struct LISTA_PRIORIDADE {
    PRIORIDADE grupo[MAX_TAM];
    int pos_livre;
} LISTA_PRIORIDADE;

LISTA_PRIORIDADE lista;

LISTA_PRIORIDADE * criaListaPrioridade() {
    LISTA_PRIORIDADE * nova_lista = (LISTA_PRIORIDADE *) malloc(sizeof(LISTA_PRIORIDADE));
    int i;
    // Preenche o array de prioridades
    for ( i = 1; i < MAX_TAM; i++ ) {
        nova_lista->grupo[i].liberado = 0;
    }

    return nova_lista;
}

/**
 * Libera um grupo de prioridade para a vacinacao
 * 
 * @param LISTA_PRIORIDADE
 * @param int id o Id do grupo de prioridade que vai ser liberado
 * 
 * @return int 1 se o grupo for liberado com sucesso
 **/
int liberaGrupo(LISTA_PRIORIDADE * l, int id)
{
    if ( id == 1 ) {
        l->grupo[id].liberado = 1;
        printf("Grupo de prioridade %d liberado com sucesso.\n", id);
        return 1;
    }
    if ( id >= 2 && id <= 5 ) {
        if ( isEnabled(l, id-1) ) {
            l->grupo[id].liberado = 1;
            printf("Grupo de prioridade %d liberado com sucesso.\n", id);
            return 1;
        } else {
            printf("Grupo de prioridade %d nao foi liberado pois o grupo de prioridade %d nao esta liberado\n", id, id-1);
            return 0;
        }
    }

    return 0;
}

/**
 * Verifica se um grupo de prioridade esta liberado
 * 
 * @param LISTA_PRIORIDADE
 * @param int id o Id do grupo de prioridade que vai ser verificado
 **/
int isEnabled(LISTA_PRIORIDADE * l, int id){

    if ( l->grupo[id].liberado == 1 ) {
        return 1;
    }

    return 0;
}

/**
 * Verifica se o grupo de prioridade eh valido
 * 
 * @param int id
 * 
 * @return int 1 se for valido
 **/
int validaPrioridades(int id)
{
    // Se o id estiver entre 1 e 5
    if ( id >= 1 && id <= 5 ) {
        return 1;
    }

    return 0;
}
