#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#include "Pessoa.h"
#include "Prioridade.h"
#include "Vacina.h"

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

    LISTA_VACINA * vacinas;
    vacinas = criaListaVacina();

    while ( entrada != '0' ) {

        printf("\n");
        printf("\n");

        // Imprime o menu
        printf("0 - Sair\n");
        printf("1 - Registrar uma pessoa\n");
        printf("2 - Remover uma pessoa\n");
        printf("3 - Liberar grupo de prioridade\n");
        printf("4 - Registrar uma vacina\n");
        printf("7 - Visualizar\n");
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

        if ( entrada == '4' ) {
            registraVacina(vacinas);
        }

        if ( entrada == '7' ) {
            visualizar(vacinas);
        }
    }

    free(povo);
    free(prioridade);

    return 1;
}

visualizar(LISTA_VACINA * vacinas)
{
    char entrada;
    entrada = 'a';
    printf("\n");
    printf("---------------------------------------- VISUALIZAR ----------------------------------------\n\n");
    while( entrada != '0' ) {

        printf("0 - Voltar\n");
        printf("1 - Registro de vacinas\n");

        scanf("%c", &entrada);
        getchar();

        if ( entrada == '1' ) {
            showVacinas(vacinas);
        }
    }
}
