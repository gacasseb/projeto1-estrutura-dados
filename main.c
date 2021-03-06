#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#include "Pessoa.h"
#include "Prioridade.h"
#include "Vacina.h"
#include "Vacinacao.h"
#include "Relatorio.h"

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

    LISTA_VACINACAO * vacinacao;
    vacinacao = criaListaVacinacao();

    while ( entrada != '0' ) {

        printf("---------------------------------------- MENU ----------------------------------------\n\n");

        // Imprime o menu
        printf("0 - Sair\n");
        printf("1 - Registrar uma pessoa\n");
        printf("2 - Registrar pessoa por arquivo\n");
        printf("3 - Remover uma pessoa\n");
        printf("4 - Liberar grupo de prioridade\n");
        printf("5 - Registrar uma vacina\n");
        printf("6 - Alterar estoque de uma vacina\n");
        printf("7 - Registrar uma vacinacao\n");
        printf("8 - Relatorios\n");
        printf("9 - Visualizar\n");
        printf("\n");

        scanf("%c", &entrada);
        getchar();

        if ( entrada == '1' ) {
            inserePessoa(povo);
        }

        if ( entrada == '2' ) {
            inserePessoaArquivo(povo);
        }

        if ( entrada == '3' ) {
            removePessoa(povo);
        }

        if ( entrada == '4' ) {
            registraPrioridade(prioridade);
        }

        if ( entrada == '5' ) {
            registraVacina(vacinas);
        }
        
        if ( entrada == '6' ) {
            alteraEstoque(vacinas);
        }

        if ( entrada == '7' ) {
            registraVacinacao(vacinacao, povo, vacinas, prioridade);
        }

        if ( entrada == '8' ) {
            relatorios(vacinas, vacinacao, povo);
        }

        if ( entrada == '9' ) {
            visualizar(povo, vacinas);
        }
    }

    free(povo);
    free(prioridade);
    free(vacinas);
    free(vacinacao);

    return 1;
}

/**
 * Gerencia o menu de relatorios
 * 
 * @param LISTA_VACINA lista_vacinas ponteiro para a lista de vacinas
 * @param LISTA_VACINACAO lista_vacinas ponteiro para a lista de vacinacao
 * @param LISTA lista_vacinas ponteiro para a lista de pessoas
 */
void relatorios(LISTA_VACINA * lista_vacinas, LISTA_VACINACAO * lista_vacinacao, LISTA * lista_pessoas)
{
    printf("\n");
    printf("---------------------------------------- RELATORIOS ----------------------------------------\n\n");

    char entrada;
    entrada = 'a';

    while ( entrada != '0' ) {

        printf("0 - Voltar\n");
        printf("1 - Gerar relatorio de vacinas\n");
        printf("2 - Gerar relatorio de vacinados com a primeira dose\n");
        printf("3 - Gerar relatorio de vacinados com a segunda dose\n");
        printf("4 - Gerar relatorio de nao vacinados agrupados pelo grupo prioritario\n");
        printf("5 - Gerar relatorio de numero de habitantes por grupo prioritario\n");


        scanf("%c", &entrada);
        getchar();

        if ( entrada == '1' ) {
            geraRelatorioVacinas(lista_vacinas);
        }

        if ( entrada == '2' ) {
            geraRelatorioVacinadoDose1(lista_vacinacao);
        }

        if ( entrada == '3' ) {
            geraRelatorioVacinadoDose2(lista_vacinacao);
        }

        if ( entrada == '4' ) {
            geraRelatorioNaoVacinados(lista_pessoas);
        }

        if ( entrada == '5' ) {
            geraRelatorioPrioritario(lista_pessoas);
        }
    }
}

/**
 * Gerencia o menu visualizar
 * 
 * @param LISTA povo lista_vacinas ponteiro para a lista de pessoas
 * @param LISTA_VACINA lista_vacinas ponteiro para a lista de vacinas
 */
visualizar(LISTA *povo, LISTA_VACINA * vacinas)
{
    char entrada;
    entrada = 'a';
    printf("\n");
    printf("---------------------------------------- VISUALIZAR ----------------------------------------\n\n");
    while( entrada != '0' ) {

        printf("0 - Voltar\n");
        printf("1 - Registro de pessoas\n");
        printf("2 - Registro de vacinas\n");

        scanf("%c", &entrada);
        getchar();

        if ( entrada == '1' ) {
            showPessoas(povo);
        }

        if ( entrada == '2' ) {
            showVacinas(vacinas);
        }
    }
}
