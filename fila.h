// FILA - FIFO: First In First Out
// O primeiro item que entrar é o primeiro a sair

typedef struct no_fila {
    INFO info;
    struct no_fila *prox;
}   NO_FILA;

typedef struct fila {
    int tam;
    NO_FILA *inicio;
    NO_FILA *fim;
}   FILA;

// Assinaturas
void FILA_inicia(FILA *);
bool FILA_vazia(FILA *, bool);
void FILA_enfileirar(FILA *, INFO);
INFO FILA_get_primeiro(FILA *);
INFO FILA_desemfilelar(FILA *);
void FILA_imprime(FILA *);
void FILA_drop(FILA *);


void FILA_inicia(FILA *f)
{
    f->tam = 0;
    f->inicio = NULL;
    f->fim = NULL;
}

bool FILA_vazia(FILA *f, bool exibir_mensagem)
{
    if(f->tam == 0 && f->inicio == NULL && f->fim == NULL) {
        if(exibir_mensagem) printf("\nFila Vazia...\n");
        return true;
    }

    return false;
}


// Insere NÓs na FILA pelo ponteiro *fim
void FILA_enfileirar(FILA *f, INFO x)
{
    NO_FILA *novo = (NO_FILA *) malloc(sizeof(NO_FILA));

    // Valida se o espaço em memoria foi alocado
    if(novo == NULL) {
        printf("\nMemória Insulficiente! - [enfileirar()]\n");
        return;
    }

    novo->info = x;

    // O *prox do NOVO NÓ deve ir NULL, pois é novo ultimo NO da FILA
    novo->prox = NULL;

    // Caso primeira inserção, os dois ponteiros *inicio e *fim, devem 
    // apontar para novo NO.
    if(FILA_vazia(f, false)) {
        f->inicio = novo;
        f->fim = novo;
    }
    else {
        // O *prox do atual ultimo NO da FILA, deve apontar para o NOVO NÓ
        f->fim->prox = novo;

        // O *fim da FILA aponta para o NOVO NÓ.
        f->fim = novo;
    }

    // Importante!, atualizar o tamanho da FILA
    f->tam++;
}


// Retorna dados do PRIMEIRO NO da FILA
INFO FILA_get_primeiro(FILA *f)
{
    if(FILA_vazia(f, true)) return INFO_default_value();

    return f->inicio->info;
}


// Remove sempre o PRIMEIRO NO da FILA
INFO FILA_desemfilelar(FILA *f)
{
    if(FILA_vazia(f, true)) return INFO_default_value();

    // *aux aponta para o que o *inicio da FILA aponta
    NO_FILA *aux = f->inicio;

    // Copia dados para retorno
    INFO x = f->inicio->info;

    if(f->inicio == f->fim) {
        aux->prox = NULL;
        f->inicio = NULL;
        f->fim = NULL;
    }
    else {
        // O *inicio deve apontar para o SEGUNDO NO da FILA
        f->inicio = f->inicio->prox;

        // Desconecta o PRIMEIRO NO da FILA
        aux->prox = NULL;
    }

    f->tam--;
    free(aux);

    return x;
}


// Imprime do INICIO ao FIM da FILA
void FILA_imprime(FILA *f)
{
    if(FILA_vazia(f, true)) return;

    NO_FILA *aux = f->inicio;

    printf("\nImprimindo Fila...\n\n");

    while(aux != NULL) {
        printf("SENHA [ %d ]  Nome [ %s ]\n", aux->info.ID, aux->info.nome);
        aux = aux->prox;
    }

    printf("\nTAM = %d\n", f->tam);
}


void FILA_drop(FILA *f)
{
    if(FILA_vazia(f, true)) return;

    printf("\nDrop Fila...\n\n");

    NO_FILA *aux = f->inicio;

    // Percorre FILA liberando memoria do *inicio ao *fim
    while(aux != NULL) {
        f->inicio = f->inicio->prox;
        aux->prox = NULL;
        free(aux);
        f->tam--;
        aux = f->inicio;
    }

    // Reset FILA *inicio ao *fim, para novas inserções pos drop
    FILA_inicia(f);
}