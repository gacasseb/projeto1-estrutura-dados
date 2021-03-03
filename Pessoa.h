typedef struct Pessoa{

    char nome[255];
    char sexo[1];
    char rg[15];
    char cpf[15];
    char telefone[15];
    char endereco[255];
    char profissao[255];
    int prioridade;

}Pessoa;

Pessoa Povo[10];

int teste() {
    Pessoa Povo[10];
    // StrCpy para atribuir uma string em uma struct
    strcpy(Povo[2].nome, "teste hehe");
}

/**
* Insere o registro de uma pessoa a partir de inputs do usuário
**/
void setPessoa()
{
    printf("Insira o grupo de prioridade da pessoa (entre 1 e 5)\n");
    scanf("%d", &Povo[0].prioridade);
    while( !validaPrioridade(Povo[0].prioridade) ) {
        printf("Insira uma prioridade válida, entre 1 e 5\n");
        scanf("%d", &Povo[0].prioridade);
    }
}

/**
* Faz a validação da string nome
*
* @return integer 1 se validado com succeso
**/
int validaNome()
{
    return 1;
}

/**
* Faz a validação do sexo, pode ser um char 'M' para masculino e 'F' para feminino
*
* @param char sexo[1] Caractere que representa o sexo da pessoa
*
* @return integer 1 Se o sexo for válido
**/
int validaSexo(char sexo[1])
{
    if ( sexo == 'M' || sexo == 'F' ) {
        return 1;
    }

    return 0;
}

/**
* Faz a validação da prioridade, se for entre 1 e 5 é válido
*
* @param integer prioridade
*
* @return integer 1 Se o sexo for válido
**/
int validaPrioridade(int prioridade)
{
    if ( prioridade >= 1 && prioridade <= 5 ) {
        return 1;
    }

    return 0;
}
