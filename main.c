#include <stdio.h>
#include "Pessoa.h"

/**
* Fun��o main
**/
int main()
{
    char entrada;

    while ( entrada != '0' ) {

        // Imprime o menu
        printf("0 - Sair\n");
        printf("1 - Inserir uma pessoa\n");
        printf("\n");

        scanf("%c", &entrada);

        if ( entrada == '1' ) {
            setPessoa();
        }
    }

    return 1;
}
