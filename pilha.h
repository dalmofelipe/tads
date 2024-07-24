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

// Assinaturas de procedimentos e funções
void inicia_pilha(PILHA *);
bool pilha_vazia(PILHA *);
void empilhar(PILHA *, INFO);
INFO desempilhar(PILHA *);
void imprime_pilha(PILHA *);
void drop_pilha(PILHA *);


// Aloca dados de inicialização da Pilha sem nó cabeça!
void inicia_pilha(PILHA *p)
{
    p->tam = 0;
    p->topo = NULL;
}


// Sempre valida o TAM e o ponteiro TOPO para definir se 
// a pilha esta vazia
bool pilha_vazia(PILHA *p)
{
    if(p->tam == 0 && p->topo == NULL) {
        printf("\nPilha vazia...\n");
        return true;
    }

    return false;
}


void empilhar(PILHA *p, INFO x)
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


// Função para desempilhar o NO que esta no TOPO da PILHA
// Return: Retorna a informação (INFO) do NO removido
INFO desempilhar(PILHA *p)
{
    INFO x = reset_info();

    if(!pilha_vazia(p))
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
void imprime_pilha(PILHA *p) 
{
    if(pilha_vazia(p)) return;
   
    NO_PILHA *aux = p->topo;

    printf("\nImprimindo Pilha...\n\nTOPO -> ");

    while(aux != NULL) {
        printf("ID: %d, Nome: %s\n\t", aux->info.ID, aux->info.nome);
        aux = aux->prox;
    }

    printf("TAM = %d\n", p->tam);
}


void drop_pilha(PILHA *p)
{
    if(pilha_vazia(p)) return;
   
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
