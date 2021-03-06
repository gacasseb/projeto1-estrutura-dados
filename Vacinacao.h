#define MAX_SIZE 100

typedef struct VACINACAO {
    char cpf_pessoa[255];
    char nome_pessoa[255];
    char nome_vacina[255];
    int dose;
    char data[15];
} VACINACAO;

typedef struct LISTA_VACINACAO {
    VACINACAO item[MAX_SIZE];
    int pos_livre;
} LISTA_VACINACAO;

/**
 *  Cria uma lista de pessoas vazia
 *
 *  @return Pessoa lista vazia
 **/
LISTA_VACINACAO* criaListaVacinacao()
{
    LISTA_VACINACAO * nova_lista = (LISTA_VACINACAO*) malloc(sizeof(LISTA_VACINACAO));
    nova_lista->pos_livre = 0;
    return nova_lista;
}

/**
 * Faz o registro de uma vacinacao
 * 
 * @param LISTA_VACINACAO * vacinacao 
 * @param LISTA_VACINACAO * pessoa
 * @param LISTA_VACINACAO * vacina
 */
void registraVacinacao(LISTA_VACINACAO * vacinacao, LISTA * pessoa, LISTA_VACINA * vacina, LISTA_PRIORIDADE * prioridade )
{
    char cpf[255];
    printf("Insira o CPF da pessoa a ser vacinada apenas com digitos.\n");
    gets(cpf);
    while( ! validaCPF(cpf) ) {
        printf("Insira um CPF valido (11 digitos)\n");
        gets(cpf);
    }

    int id_pessoa;
    id_pessoa = foundByCpf(pessoa, cpf);
    // Retorna caso nao encontre o registro de uma pessoa com o CPF inserido  
    if ( id_pessoa < 0 ) {
        printf("Nao foi encontrado registro com este CPF.\n");
        return;
    }

    // Verifica se o grupo de prioridade da pessoa esta liberado para a vacinacao
    if ( ! isEnabled(prioridade, pessoa->item[id_pessoa].prioridade) ) {
        printf("Grupo de prioridade nao liberado para vacinacao.\n");
        return;
    }

    char nome_vacina[255];
    printf("Insira o nome da vacina\n");
    gets(nome_vacina);
    while( ! validaNomeVacina(nome_vacina) ) {
        printf("Insira um nome valido (apenas letras)\n");
        gets(nome_vacina);
    }

    int pos_vacina;
    pos_vacina = foundVacinaByName(vacina, nome_vacina);
    // Retorna caso nao encontre o registro da vacina na lista de vacinas
    if ( pos_vacina < 0 ) {
        printf("Vacina nao encontrada.\n");
        return;
    }

    // Verifica se existe estoque da vacina para a vacinacao da pessoa
    if ( ! hasVacina(vacina->item[pos_vacina], nome_vacina) ) {
        return;
    }

    int pos_vacinacao;
    pos_vacinacao = foundVacinacaoByCpf(vacinacao, pessoa->item[id_pessoa].cpf);

    // Verifica se ja existe um registro de vacinacao para essa pessoa
    if ( pos_vacinacao >= 0 ) {
        // Verifica se a pessoa ja tomou as duas doses
        if ( vacinacao->item[pos_vacinacao].dose == 2 ) {
            printf("Essa pessoa ja foi vacinada com duas doses.\n");
            return;

        } else {

            vacinacao->item[pos_vacinacao].dose++;
        }

    } else {

        VACINACAO v;

        strcpy(v.cpf_pessoa, pessoa->item[id_pessoa].cpf);
        strcpy(v.nome_pessoa, pessoa->item[id_pessoa].nome);
        strcpy(v.nome_vacina, vacina->item[pos_vacina].nome);
        v.dose = 1;

        pushVacinacao(vacinacao, v);
    }

    // Diminui uma dose no estoque da vacina
    vacina->item[pos_vacina].estoque--;

    printf("Vacinacao registrada com sucesso\n");
}

/**
 *  Insere um elemento no final de uma lista
 *
 * @param LISTA_VACINACAO Lista para inserir o elemento
 * @param PESSOA Elemento para inserir no final da lista
 *
 * @return int 1 Se inserido com sucesso
 **/
int pushVacinacao(LISTA_VACINACAO *l, VACINACAO v) {
    if ( l->pos_livre >= MAX_SIZE ) {
        return 0;

    } else {
        l->item[l->pos_livre] = v;
        l->pos_livre += 1;

        return 1;
    }
}

/**
 *  Verifica se a lista de vacinacao eh vazia
 * 
 *  @param LISTA_VACINACAO *l
 * 
 *  @return int 1 se a lista esta vazia
 */
int isEmptyVacinacao( LISTA_VACINACAO *l )
{
    if ( l->pos_livre == 0 ) {
        return 1;
    }

    return 0;
}

/**
 * Procura por uma vacinacao pelo cpf da pessoa
 */
int foundVacinacaoByCpf( LISTA_VACINACAO *l, char *cpf ) {
    if ( isEmptyVacinacao(l) ) {
        return -1;
    }
    int pos = 0;

    while( pos < l->pos_livre && (strcmp(cpf, l->item[pos].cpf_pessoa) != 0) )
        pos++;

    if (pos == l->pos_livre) {
        return -1;
    }

    return pos;
}


