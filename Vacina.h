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