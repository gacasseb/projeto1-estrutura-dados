#define MAX_SIZE 1000

typedef struct PESSOA {

    char nome[255];
    char sexo[10];
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
    scanf(" %s", &pessoa.sexo);
    while( ! validaSexo(pessoa.sexo) ) {
        printf("Insira um sexo valido\n");
        scanf(" %s", &pessoa.sexo);
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

    // Verifica se este cpf ja foi cadastrado
    if ( foundByCpf(l, cpf) >= 0 ) {
        printf("Uma pessoa com este CPF ja foi cadastrada.\n");
        return;
    }

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

    printf("Pessoa registrada com sucesso.\n");
}

/**
*  Faz a leitura das strings do arquivo texto e as separa
*
* @param str  String a ser dividida
* @param delim  Um caracter delimitador que indica onde deve se separar a string
*
* @return Um ponteiro para o a primeira ocorrencia do caracter delim
**/
char *rstr (char *str, char const *delim)
{
  static char *src = NULL;
  char *p, *ret = 0;

  if (str != NULL)
    src = str;

  if (src == NULL)
    return NULL;

  if ((p = strpbrk (src, delim)) != NULL) {
    *p  = 0;
    ret = src;
    src = ++p;
   }
    else if (*src) {
        ret = src;
        src = NULL;
    }
    return ret;
}

/**
* Insere o registro de uma ou mais pessoas a partir de um arquivo texto
**/
void inserePessoaArquivo(LISTA *l) {
    FILE* f;
    char path[255];
    char idade[10];
    char prioridade[10];

    //Scaneia o caminho do arquivo
    printf("Entre com o caminho do arquivo: ");
    gets(path);
    f = fopen(path, "r");

    if(f == NULL) {
        printf("Nao foi possivel abrir o arquivo\n");
    }


    while(!feof(f)) {
        PESSOA pessoa;
        char str[255];
        char delim[] = ";";
        char *ptr;

        fgets(str, 1000, f);

        ptr = rstr(str, delim);
        strcpy(pessoa.nome, ptr);

        ptr = rstr(NULL, delim);
        pessoa.idade = atoi(ptr);

        ptr = rstr(NULL, delim);
        strcpy(pessoa.sexo, ptr);

        ptr = rstr(NULL, delim);
        strcpy(pessoa.rg, ptr);

        ptr = rstr(NULL, delim);
        strcpy(pessoa.cpf, ptr);

        ptr = rstr(NULL, delim);
        strcpy(pessoa.telefone, ptr);

        ptr = rstr(NULL, delim);
        strcpy(pessoa.endereco, ptr);

        ptr = rstr(NULL, delim);
        strcpy(pessoa.profissao, ptr);

        ptr = rstr(NULL, delim);
        pessoa.prioridade = atoi(ptr);

        if(!validaNome(pessoa.nome)) {
            printf("Pessoa do CPF: '%s' nao foi registrada(Nome Invalido '%s')\n", pessoa.cpf, pessoa.nome);
            continue;
        }

        else if(!validaIdade(pessoa.idade)) {
            printf("Pessoa do CPF: '%s' nao foi registrada(Idade Invalida '%d')\n", pessoa.cpf, pessoa.idade);
            continue;
        }
        else if(!validaSexo(pessoa.sexo)) {
            printf("Pessoa do CPF: '%s' nao foi registrada(Sexo Invalido '%s')\n", pessoa.cpf, pessoa.sexo);
            continue;
        }
        else if(!validaRG(pessoa.rg)) {
            printf("Pessoa do CPF: '%s' nao foi registrada(RG Invalido '%s')\n", pessoa.cpf, pessoa.rg);
            continue;
        }
        else if(!validaCPF(pessoa.cpf)) {
            printf("Pessoa chamada: '%s' nao foi registrada(CPF Invalido '%s')\n", pessoa.nome, pessoa.cpf);
            continue;
        }
        else if(!validaPrioridade(pessoa.prioridade)) {
            printf("Pessoa do CPF: '%s' nao foi registrada(Prioridade Invalida '%d')\n", pessoa.cpf, pessoa.prioridade);
            continue;
        }
        push(l, pessoa);
    }

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

/**
 *  Remove uma pessoa da lista
 * 
 *  @param LISTA *l ponteiro para estrutura do tipo LISTA de pessoas
 */
void removePessoa(LISTA *l)
{
    if ( isEmpty(l) ) {
        printf("Erro - Nao ha registro de pessoas.\n");
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
        printf("Pessoa removida com sucesso.\n");
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
            l->item[i] = l->item[i+1];
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
        return -1;
    }
    int pos = 0;

    while( pos < l->pos_livre && (strcmp(cpf, l->item[pos].cpf) != 0) )
        pos++;

    if (pos == l->pos_livre) {
        // printf("Erro: CPF nao encontrado\n");
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
 * Verifica se uma string contem apenas digitos
 **/
int validaDigito(char str[10])
{
    int i;
    for( i = 0; i < strlen(str); i++ ) {
        if( !isdigit(str[i]) ) return 0;
    }

    return 1;
}

 /* Imprime todos os registros de pessoas.
 * 
 *  @param LISTA *l
 */
void showPessoas(LISTA *l) {
    if ( isEmpty(l) ) {
        printf("A lista de pessoas esta vazia, por favor, registre uma pessoa\n");
        return;
    }

    int i;
    printf("---------------------------------------- PESSOAS REGISTRADAS ----------------------------------------\n\n");
    for ( i = 0; i < l->pos_livre; i++ ) {
        printf("id: %d\n", i);
        printf("Nome: %s\n", l->item[i].nome);
        printf("CPF: %s\n", l->item[i].cpf);
        printf("idade: %d\n", l->item[i].idade);
        printf("grupo de prioridade: %d\n", l->item[i].prioridade);
        printf("\n");
    }

    printf("\n");
    printf("\n");
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
int validaSexo(char sexo[10])
{
    if ( strcmp(sexo, "F") == 0 ) {
        return 1;
    }
    else if ( strcmp(sexo, "M") == 0 ) {
            return 1;
         }
    else if ( strcmp(sexo, "m") == 0 ) {
            return 1;
         }
    else if ( strcmp(sexo, "f") == 0 ) {
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
    if ( (strlen(rg) != 3) || (strlen(rg) != 9) == 0 ) {
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

    if ( (strlen(telefone)) < 8 || (strlen(telefone) > 13 ) ) {
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
