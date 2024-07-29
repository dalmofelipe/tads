// PILHA - FILO: First In Last Out
// O item primeiro que entrar é o ultimo a sair

typedef struct no_pilha {
    INFO info;
    struct no_pilha *prox;
}   NO_PILHA;

typedef struct pilha {
    int tam;
    NO_PILHA *topo;
}   PILHA;

// Assinaturas
void PILHA_inicia(PILHA *);
bool PILHA_vazia(PILHA *);
void PILHA_empilhar(PILHA *, INFO);
INFO PILHA_get_topo(PILHA *);
INFO PILHA_desempilhar(PILHA *);
void PILHA_imprime(PILHA *);
void PILHA_drop(PILHA *);


// Aloca dados de inicialização da Pilha sem nó cabeça!
void PILHA_inicia(PILHA *p)
{
    p->tam = 0;
    p->topo = NULL;
}


// Sempre valida o TAM e o ponteiro TOPO para definir se 
// a pilha esta vazia
bool PILHA_vazia(PILHA *p)
{
    if(p->tam == 0 && p->topo == NULL) {
        printf("\nPilha vazia...\n");
        return true;
    }

    return false;
}


void PILHA_empilhar(PILHA *p, INFO x)
{
    NO_PILHA *novo = (NO_PILHA *) malloc(sizeof(NO_PILHA));

    // Valida se o espaço em memoria foi alocado
    if(novo == NULL) {
        printf("\nMemória Insulficiente! - [empilhar()]\n");
        return;
    }

    // Atribui a informação dentro do NOVO NÓ.
    novo->info = x;

    // O ponteiro *prox do NOVO NÓ, aponta para o que o TOPO da PILHA aponta.
    novo->prox = p->topo;

    // O TOPO da pilha, agora deve apontar para o NOVO NÓ (novo item do topo)
    p->topo = novo;

    // Importante, atualizar o tamanho da PILHA
    p->tam++;
}

// Exibe e retorna a informação do TOPO da PILHA
INFO PILHA_get_topo(PILHA *p)
{
    if(PILHA_vazia(p)) return INFO_default_value();

    printf("\nConsulta Topo >>> ID[%d] Nome[%s]\n", 
        p->topo->info.ID, p->topo->info.nome);

    return p->topo->info;
}


// Função para desempilhar o NO que esta no TOPO da PILHA
// Return: Retorna a informação (INFO) do NO removido
INFO PILHA_desempilhar(PILHA *p)
{
    INFO x = INFO_default_value();

    if(!PILHA_vazia(p))
    {
        // Copia informação para retorno
        x = p->topo->info;

        // Cria um ponteiro Auxiliar que aponta para o que o TOPO da PILHA aponta
        NO_PILHA *aux = p->topo;
        
        // O TOPO da PILHA agora, deve apontar para NO abaixo do NO que esta no TOPO
        p->topo = p->topo->prox;

        // O ponteiro *aux é a referencia para o NO que será removido.
        // Assim, deve desconectar o NO que *aux aponta, direcionando 
        // o ponteiro *prox para NULL
        aux->prox = NULL;

        // Libera a referencia de memoria dos dados que *aux aponta
        free(aux);

        // Importante!, deve atualizar o tamanho da PILHA
        p->tam--;
    }

    // Se o processo de desempilhar ocorreu corretamente
    // os dados do NO seram retornados, caso contrário
    // retorna os valores default do reset_info
    return x;
}


// Imprime do TOPO para o primeiro NO inserido
void PILHA_imprime(PILHA *p)
{
    if(PILHA_vazia(p)) return;
   
    NO_PILHA *aux = p->topo;

    printf("\nImprimindo Pilha...\n\nTOPO -> ");

    while(aux != NULL) {
        printf("ID: %d, Nome: %s\n\t", aux->info.ID, aux->info.nome);
        aux = aux->prox;
    }

    printf("TAM = %d\n", p->tam);
}


void PILHA_drop(PILHA *p)
{
    if(PILHA_vazia(p)) return;
   
    NO_PILHA *aux;

    printf("\nDROP Pilha...\n");

    do {
        aux = p->topo;
        p->topo = p->topo->prox;
        aux->prox = NULL;
        free(aux);
    }   while(p->topo != NULL);

    p->tam = 0;
}
