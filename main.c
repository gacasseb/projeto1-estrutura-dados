#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#include "Prioridade.h"
#include "Pessoa.h"

/**
* Funcao main
**/
int main()
{
    char entrada;
    entrada = 'a';

    LISTA * povo;
    povo = criaLista();

    while ( entrada != '0' ) {

        // Imprime o menu
        printf("0 - Sair\n");
        printf("1 - Inserir uma pessoa\n");
        printf("\n");

        scanf("%c", &entrada);
        getchar();

        if ( entrada == '1' ) {
            inserePessoa(povo);
        }
    }

    return 1;
}
