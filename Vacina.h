#define MAX_SIZE 100

typedef struct VACINA {
    char nome[255];
    int estoque;
} VACINA;

typedef struct LISTA_VACINA {
    VACINA item[MAX_SIZE];
    int pos_livre;
} LISTA_VACINA;

/**
 *  Cria uma lista vazia de vacina
 * 
 * @return ponteiro para a lista de vacina
 **/
LISTA_VACINA * criaListaVacina()
{
    LISTA_VACINA * nova_lista = (LISTA_VACINA *) malloc(sizeof(LISTA_VACINA));
    nova_lista->pos_livre = 0;
    return nova_lista;
}

/**
 *  Solicita os dados para registrar a vacina
 * 
 *  @param LISTA_VACINA
 */
void registraVacina(LISTA_VACINA *l)
{
    VACINA vacina;

    char nome[255];
    printf("Insira o nome da vacina\n");
    gets(nome);
    while( ! validaNomeVacina(nome) ) {
        printf("Insira um nome valido (apenas letras)\n");
        gets(nome);
    }
    strcpy(vacina.nome, nome);

    if ( foundVacinaByName(l, nome) >= 0 ) {
        printf("Erro: Uma vacina com este nome ja foi registrada.\n");
        return;
    }

    // Faz a inserção da idade
    printf("Insira o estoque da vacina em digitos\n");
    scanf("%d", &vacina.estoque);
    while( ! validaEstoqueVacina(vacina.estoque) ) {
        printf("Insira o estoque da vacina em digitos (apenas numero inteiro positivo)\n");
        scanf("%d", &vacina.estoque);
    }
    getchar();

    pushVacina(l, vacina);
}

/**
 *  Insere um elemento no final de uma lista
 *
 * @param LISTA Lista para inserir o elemento
 * @param PESSOA Elemento para inserir no final da lista
 *
 * @return int 1 Se inserido com sucesso
 **/
int pushVacina(LISTA_VACINA *l, VACINA v) {
    if ( l->pos_livre >= MAX_SIZE ) {
        printf("A lista de vacinas esta cheia.\n");
        return 0;

    } else {
        l->item[l->pos_livre] = v;
        l->pos_livre += 1;

        return 1;
    }
}

/**
 *  Procura por uma vacina registrada pelo nome
 *
 *  @param LISTA_VACINA Lista de vacinas a ser procurada
 *  @param nome Nome a ser procurado na lista
 *
 *  @return A posiçao da vacina na lista se for encontrada
 **/


int foundVacinaByName( LISTA_VACINA *l, char *nome ) {
    if ( isEmptyVacinas(l) ) {
        return -1;
    }
    int pos = 0;

    while( pos < l->pos_livre && (strcmp(nome, l->item[pos].nome) != 0) )
        pos++;

    if (pos == l->pos_livre) {
        return -1;
    }

    return pos;
}

/**
 *  Altera estoque de vacinas
 *
 *  @param LISTA_VACINA Lista de vacinas a ser alterada
 *
 **/

void alteraEstoque( LISTA_VACINA *l )
{
    char nome[255];
    printf("Insira o nome da vacina\n");
    gets(nome);
    while( ! validaNomeVacina(nome) ) {
        printf("Insira um nome valido (apenas letras)\n");
        gets(nome);
    }
    int pos_vacina;
    pos_vacina = foundVacinaByName(l, nome);

    if ( pos_vacina >= 0 ) {

        int estoque;
        // Faz a inserção do estoque
        printf("Insira o estoque da vacina em digitos\n");
        scanf("%d", &estoque);
        while( ! validaEstoqueVacina(estoque) ) {
            printf("Insira o estoque da vacina em digitos (apenas numero inteiro positivo)\n");
            scanf("%d", &estoque);
        }
        getchar();

        l->item[pos_vacina].estoque = estoque;
        printf("Estoque da vacina alterado com sucesso.\n");
        
    } else {
        printf("Vacina nao encontrada.\n");
    }
}

/**
 *  Verifica se tem estoque para aplicar a vacina
 * 
 *  @param LISTA_VACINA *l
 *  @param char nome_vacina
 * 
 *  @return int 1 se existe estoque para a vacina
 */
int hasVacina( VACINA v, char *nome_vacina )
{
    if ( v.estoque > 0 ) {
        return 1;
    } else {
        printf("Nao existe estoque disponivel para a vacinacao desta vacina\n");
    }

    return 0;
}

/**
 * Imprime todos os registros de vacinas.
 * 
 *  @param LISTA_VACINA *l
 */
void showVacinas(LISTA_VACINA *l) {
    if ( isEmptyVacinas(l) ) {
        printf("A lista de vacinas esta vazia, por favor, registre uma vacina\n");
        return;
    }

    int i;
    printf("---------------------------------------- VACINAS REGISTRADAS ----------------------------------------\n\n");
    for ( i = 0; i < l->pos_livre; i++ ) {
        printf("Vacina id: %d\n", i);
        printf("Nome: %s\n", l->item[i].nome);
        printf("Estoque: %d\n", l->item[i].estoque);
        printf("\n");
    }

    printf("\n");
    printf("\n");
}

/**
 * Retorna true se a lista de vacinas estiver vazia
 */
int isEmptyVacinas(LISTA_VACINA *l) {
    if ( l->pos_livre == 0 ) {
        return 1;
    }

    return 0;
}

/**
 *  Valida o nome de uma vacina
 *
 *  @param nome Nome a ser validado
 *
 *  @return int 1 se for valido
 **/
int validaNomeVacina(char *nome)
{
    if ( nome[0] == '\0' ) return 0;

    int i;

    for ( i = 0; i < strlen(nome); i++) {
        if ( isdigit(nome[i]) ) {
            return 0;
        }
    }

    return 1;
}

/**
 * Faz a validacao do estoque da vacina
 */
int validaEstoqueVacina(int n)
{
    if ( n >= 0 ) {
        return 1;
    }

    return 0;
}