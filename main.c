#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#include "Pessoa.h"
#include "Prioridade.h"

/**
* Funcao main
**/
int main()
{
    char entrada;
    entrada = 'a';

    LISTA * povo;
    povo = criaLista();

    LISTA_PRIORIDADE * prioridade;
    prioridade = criaListaPrioridade();

    while ( entrada != '0' ) {

        printf("\n");
        printf("\n");

        // Imprime o menu
        printf("0 - Sair\n");
        printf("1 - Registrar uma pessoa\n");
        printf("2 - Remover uma pessoa\n");
        printf("3 - Liberar grupo de prioridade\n");
        printf("\n");

        scanf("%c", &entrada);
        getchar();

        if ( entrada == '1' ) {
            inserePessoa(povo);
        }

        if ( entrada == '2' ) {
            removePessoa(povo);
        }

        if ( entrada == '3' ) {
            int id_prioridade;
            printf("Insira o grupo de prioridade que deseja liberar (digito entre 1 e 5)\n");
            scanf("%d", &id_prioridade);
            while( ! validaPrioridades(id_prioridade) ) {
                printf("Insira um grupo de prioridade valido (digito entre 1 e 5)\n");
                scanf("%d", &id_prioridade);
            }
            getchar();
            liberaGrupo(prioridade, id_prioridade);
        }

        int i;
        for ( i = 0; i < povo->pos_livre; i++ ) {
            printf("ID pessoa: %d\n", i);
            printf("%s\n", povo->item[i].nome);
            printf("%s\n", povo->item[i].cpf);
            printf("%d\n", povo->item[i].prioridade);
            printf("\n\n");
        }
    }

    free(povo);
    free(prioridade);

    return 1;
}
