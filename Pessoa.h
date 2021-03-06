#define MAX_SIZE 1000

typedef struct PESSOA {

    char nome[255];
    char sexo[2];
    char rg[15];
    char cpf[15];
    char telefone[15];
    char endereco[255];
    char profissao[255];
    int prioridade;
    int idade;

} PESSOA;

typedef struct Lista {
    PESSOA item[MAX_SIZE];
    int pos_livre;
} LISTA;

void inserePessoaArquivo(LISTA *l) {
    FILE* f;
    char path[255];

    scanf("%s", &path);
    f = fopen(path, "r");

    if(f == NULL) {
        printf("Nao foi possivel abrir o arquivo\n");
    }

    while(!feof(f)) {
        char str[255];
        char delim[] = ";";
        char *ptr;

        fscanf(f, "%s", &str);

        ptr = strtok(str, delim);
        strcpy(pessoa.nome, ptr);

        ptr = strtok(NULL, delim);
        pessoa.idade = atoi(ptr);

        ptr = strtok(NULL, delim);
        strcpy(pessoa.sexo, ptr);

        ptr = strtok(NULL, delim);
        strcpy(pessoa.rg, ptr);

        ptr = strtok(NULL, delim);
        strcpy(pessoa.cpf, ptr);

        ptr = strtok(NULL, delim);
        strcpy(pessoa.telefone, ptr);

        ptr = strtok(NULL, delim);
        strcpy(pessoa.endereco, ptr);

        ptr = strtok(NULL, delim);
        strcpy(pessoa.profissao, ptr);

        ptr = strtok(NULL, delim);
        pessoa.prioridade = atoi(ptr);

        push(l, pessoa);
    }

}

/**
* Insere o registro de uma pessoa a partir de inputs do usuario no final do array Pessoa
**/
void inserePessoa(LISTA *l)
{
    char nome[255];
    char rg[15];
    char cpf[15];
    char telefone[15];
    char endereco[255];
    char profissao[255];

    PESSOA pessoa;

    // Faz a inserção do nome
    printf("Insira o nome\n");
    gets(nome);
    while( ! validaNome(nome) ) {
        printf("Insira um nome valido\n");
        gets(nome);
    }
    strcpy(pessoa.nome, nome);

    // Faz a inserção da idade
    printf("Insira a idade\n");
    scanf("%d", &pessoa.idade);
    while( ! validaIdade(pessoa.idade) ) {
        printf("Insira uma idade valida\n");
        scanf("%d", &pessoa.idade);
    }

    // Faz a inserção do sexo
    printf("Insira o sexo\n");
    scanf(" %c", &pessoa.sexo);
    while( ! validaSexo(pessoa.sexo) ) {
        printf("Insira um sexo valido\n");
        scanf(" %c", &pessoa.sexo);
    }
    getchar();

    // Faz a inserção do RG
    printf("Insira o RG\n");
    gets(rg);
    while( ! validaRG(rg) ) {
        printf("Insira um RG valido\n");
        gets(rg);
    }
    strcpy(pessoa.rg, rg);

    // Faz a inserção do CPF
    printf("Insira o CPF com apenas digitos\n");
    gets(cpf);
    while( ! validaCPF(cpf) ) {
        printf("Insira um CPF valido (11 digitos)\n");
        gets(cpf);
    }
    strcpy(pessoa.cpf, cpf);

    // Faz a inserção do telefone
    printf("Insira o numero de telefone\n");
    gets(telefone);
    strcpy(pessoa.telefone, telefone);

    // Faz a inserção do endereco
    printf("Insira o endereco\n");
    gets(endereco);
    strcpy(pessoa.endereco, endereco);

    // Faz a inserção da profissao
    printf("Insira a profissao\n");
    gets(profissao);
    strcpy(pessoa.profissao, profissao);

    // Faz a inserção da prioridade
    printf("Insira o grupo de prioridade da pessoa (entre 1 e 5)\n");
    scanf("%d", &pessoa.prioridade);
    while( ! validaPrioridade(pessoa.prioridade) ) {
        printf("Insira uma prioridade valida, entre 1 e 5\n");
        scanf("%d", &pessoa.prioridade);
    }

    getchar();
    push(l, pessoa);
}

/**
 *  Cria uma lista de pessoas vazia
 *
 *  @return Pessoa lista vazia
 **/
LISTA* criaLista() {
    LISTA * nova_lista = (LISTA*) malloc(sizeof(LISTA));
    nova_lista->pos_livre = 0;
    return nova_lista;
}

/**
 *  Insere um elemento no final de uma lista
 *
 * @param LISTA Lista para inserir o elemento
 * @param PESSOA Elemento para inserir no final da lista
 *
 * @return int 1 Se inserido com sucesso
 **/
int push(LISTA *l, PESSOA p) {
    if ( l->pos_livre >= MAX_SIZE ) {
        return 0;

    } else {
        l->item[l->pos_livre] = p;
        l->pos_livre += 1;

        return 1;
    }
}

void removePessoa(LISTA *l)
{
    if ( isEmpty(l) ) {
        printf("Erro - Nao ha registro de pessoas, por favor registre uma pessoa");
        return 0;
    }
    char cpf[15];
    // Faz a inserção do CPF
    printf("Insira o CPF apenas com digitos para remover uma pessoa\n");
    strcpy(cpf, gets(cpf));
    while( ! validaCPF(cpf) ) {
        printf("Insira um CPF valido (11 digitos)\n");
        gets(cpf);
    }

    if ( removeByCpf(l, cpf) ) {
        printf("Pessoa removida com sucesso.");
    }
}

/**
 * Remove uma pessoa dado um cpf
 *
 * @param LISTA *l
 * @param char cpf Numero de cpf da pessoa que vai ser removida
 *
 * @return integer 1 se removido com sucesso
 **/
int removeByCpf(LISTA *l, char *cpf) {
    int pos, i;
    // Entra caso a lista seja vazia
    if ( isEmpty(l) ) {
        printf("Erro: chamada função remove com uma lista vazia");
        return 0;
    }
    pos = foundByCpf(l, cpf);
    if ( pos >= 0 ) {
        for ( i = pos; i < l->pos_livre; i++) {
            l->item[pos] = l->item[pos+1];
        }
        l->pos_livre--;
        return 1;
    }

    return 0;
}

/**
 * Procura por uma pessoa na lista dado o CPF
 *
 * @param LISTA *l
 * @param char cpf Cpf que vai ser buscado
 *
 * @return int numero da posicao da pessoa na lista
 **/
int foundByCpf( LISTA*l, char *cpf ) {
    if ( isEmpty(l) ) {
        printf("Erro: chamada funcao buscaCPF com uma lista de pessoas vazia, registre uma pessoa\n");
        return -1;
    }
    int pos = 0;

    while( pos < l->pos_livre && (strcmp(cpf, l->item[pos].cpf) != 0) )
        pos++;

    if (pos == l->pos_livre) {
        printf("Erro: CPF nao encontrado\n");
        return -1;
    }

    return pos;
}

/**
 * @param LISTA *l retorna se uma lista da struct LISTA eh vazia
 *
 * @return int 1 se for vazia
 **/
int isEmpty(LISTA *l) {
    if ( l->pos_livre == 0 ) {
        return 1;
    }

    return 0;
}

/**
* Faz a validacao da string nome
*
* @return integer 1 se validado com succeso
**/
int validaNome(char nome[255])
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
 * Faz a validacao da idade, obrigatorio ser entre 0 e 125
 **/
int validaIdade(int idade)
{
    if ( idade >= 0 && idade <= 125 ) {
        return 1;
    }

    return 0;
}

/**
* Faz a valida��o do sexo, pode ser um char 'M' para masculino e 'F' para feminino
*
* @param char sexo[1] Caractere que representa o sexo da pessoa
*
* @return integer 1 Se o sexo for v�lido
**/
int validaSexo(char sexo[1])
{
    if ( sexo == 'M' || sexo == 'F' || sexo == 'm' || sexo == 'f' ) {
        return 1;
    }

    return 0;
}

/**
* Faz a valida��o da prioridade, se for entre 1 e 5 � v�lido
*
* @param integer prioridade
*
* @return integer 1 Se o sexo for v�lido
**/
int validaPrioridade(int prioridade)
{
    if ( prioridade >= 1 && prioridade <= 5 ) {
        return 1;
    }

    return 0;
}

/**
* Faz a validacao do RG, se contem apenas digitos e tamanho igual a 9
*
* @param char rg
*
* @return integer 1 se o rg for valido
**/
int validaRG(char rg[15])
{
    if ( strlen(rg) != 9 ) {
        return 0;
    }

    int i;
    for( i = 0; i < strlen(rg); i++ ) {
        if( !isdigit(rg[i]) ) return 0;
    }

    return 1;
}

/**
* Faz a validacao do CPF, se contem apenas digitos e tamanho igual a 11
*
* @param char cpf
*
* @return integer 1 se o cpf for valido
**/
int validaCPF(char cpf[15])
{
    int i;

    if ( strlen(cpf) != 11 ) {
        return 0;
    }

    for ( i = 0; i<strlen(cpf); i++ ) {
        if ( ! isdigit(cpf[i]) ) return 0;
    }

    return 1;
}

/**
 * @param telefone
 *
 * @return integer 1 se o telefone for valido
 **/
int validaTelefone(char telefone[15]) {

    if ( strlen(telefone) < 8 || strlen(telefone) > 13 ) {
        return 0;
    }

    int i;

    for ( i = 0; i < strlen(telefone) ; i++ ) {
        if ( ! isdigit(telefone[i]) ) {
            return 0;
        }
    }

    return 1;
}
