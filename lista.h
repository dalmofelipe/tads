// LISTA SIMPLESMENTE ENCADEADA

typedef struct no_lista {
    INFO info;
    struct no_lista *prox;
}   NO_LISTA;

typedef struct lista {
    int tam;
    NO_LISTA *inicio, *fim;
}   LISTA;


// Assinaturas
void LISTA_inicia(LISTA *);
bool LISTA_vazia(LISTA *, bool);
void LISTA_add_inicio(LISTA *, INFO);
void LISTA_add_fim(LISTA *, INFO);
void LISTA_add_posicao(LISTA *, INFO, int);
INFO LISTA_get_info(LISTA *, int);
int  LISTA_buscar_info(LISTA *, INFO);
INFO LISTA_remove_inicio(LISTA *);
INFO LISTA_remove_fim(LISTA *);
INFO LISTA_remover_busca(LISTA *, INFO);
INFO LISTA_remover_posicao(LISTA *, int);
void LISTA_prioridade_maxima(LISTA *, int);
void LISTA_prioridade_minima(LISTA *, int);
void LISTA_prioridade_salto(LISTA *, int, int);
void LISTA_imprime(LISTA *);
void LISTA_drop(LISTA *);


void LISTA_inicia(LISTA *l)
{
    l->tam = 0;
    l->inicio = NULL;
    l->fim = NULL;
}


bool LISTA_vazia(LISTA *l, bool exibir_mensagem)
{
    if(l->tam == 0 && l->inicio == NULL && l->fim == NULL) {
        if(exibir_mensagem) printf("\nLista Simples Vazia...\n");
        return true;
    }

    return false;
}


void LISTA_add_inicio(LISTA *l, INFO x)
{
    NO_LISTA *novo = (NO_LISTA *) malloc(sizeof(NO_LISTA));

    // Valida se o espaço em memoria foi alocado
    if(novo == NULL) {
        printf("\nMemória Insulficiente! - [add_inicio_lista()]\n");
        return;
    }

    novo->info = x;
    
    if(LISTA_vazia(l, false)) {
        l->inicio = novo;
        l->fim = novo;
        novo->prox = NULL;
    }
    else {
        novo->prox = l->inicio;
        l->inicio = novo;
    }

    l->tam++;
}


void LISTA_add_fim(LISTA *l, INFO x)
{
    NO_LISTA *novo = (NO_LISTA *) malloc(sizeof(NO_LISTA));

    // Valida se o espaço em memoria foi alocado
    if(novo == NULL) {
        printf("\nMemória Insulficiente! - [add_fim_lista()]\n");
        return;
    }

    novo->info = x;
    
    if(LISTA_vazia(l, false)) {
        l->inicio = novo;
        l->fim = novo;
        novo->prox = NULL;
    }
    else {
        novo->prox = NULL;
        l->fim->prox = novo;
        l->fim = novo;
    }

    l->tam++;
}


void LISTA_add_posicao(LISTA *l, INFO x, int posicao)
{
    NO_LISTA *novo = (NO_LISTA *) malloc(sizeof(NO_LISTA));
    
    // Valida se o espaço em memoria foi alocado
    if(novo == NULL) {
        printf("\nMemória Insulficiente! - [add_posicao_lista()]\n");
        return;
    }

    if(posicao <= 1) LISTA_add_inicio(l, x); 
    else if(posicao >= l->tam) LISTA_add_fim(l, x); 
    else {
        NO_LISTA *aux = l->inicio;

        INFO temp;

        // *aux se posiciona no NO anterior da posicao desejada
        for(int i = 1; i < posicao -1; i++) aux = aux->prox;

        // adiciona novo NO pelo *aux->prox
        novo->info = x;
        novo->prox = aux->prox;
        aux->prox = novo;
        l->tam++;
    }
}


INFO LISTA_get_info(LISTA *l, int posicao)
{
    if(LISTA_vazia(l, true)) return INFO_default_value();

    if(posicao <= 1) return l->inicio->info;
    else if(posicao >= l->tam) return l->fim->info;
    else {
        NO_LISTA *aux = l->inicio;

        // posiciona ponteiro *aux exatamente no NO que contem a informação
        for(int i = 1; i < posicao; i++) aux = aux->prox;
        
        return aux->info;
    }
}


// retorna a posição do NO encontrado
int LISTA_buscar_info(LISTA *l, INFO x)
{
    if(LISTA_vazia(l, true)) return -1;

    int contador = 1;

    NO_LISTA *aux = l->inicio;

    while(aux != NULL) 
    {
        if(INFO_is_equal(aux->info, x)) return contador;
        aux = aux->prox;
        contador++;
    }

    return -1;
}


INFO LISTA_remove_inicio(LISTA *l)
{
    if(LISTA_vazia(l, true)) return INFO_default_value();

    NO_LISTA *aux = l->inicio;

    l->inicio = l->inicio->prox;
    aux->prox = NULL;

    INFO x = aux->info;
    free(aux);
    l->tam--;

    return x;
}


INFO LISTA_remove_fim(LISTA *l)
{
    if(LISTA_vazia(l, true)) return INFO_default_value();

    NO_LISTA *aux = l->inicio;

    // posiciona *aux no penultimo NO 
    while(aux->prox != l->fim) aux = aux->prox;
    
    l->fim = aux;
    aux = l->fim->prox;
    l->fim->prox = NULL;

    INFO x = aux->info;
    l->tam--;
    free(aux);

    return x;
}


INFO LISTA_remover_busca(LISTA *l, INFO x)
{
    if(LISTA_vazia(l, true)) return INFO_default_value();

    INFO i = INFO_default_value();

    if(INFO_is_equal(l->inicio->info, x)) return LISTA_remove_inicio(l);
    else if(INFO_is_equal(l->fim->info, x)) return LISTA_remove_fim(l);
    else 
    {
        NO_LISTA *aux_busca = l->inicio->prox;
        NO_LISTA *aux_remocao = l->inicio;

        while(aux_busca->prox != l->fim)
        {
            if(INFO_is_equal(aux_busca->info, x)) 
            {
                aux_remocao->prox = aux_busca->prox;
                aux_busca->prox = NULL;
                i = aux_busca->info;
                free(aux_busca);
                l->tam--;
                break;
            }

            aux_busca = aux_busca->prox;
            aux_remocao = aux_remocao->prox;
        }
    }
    
    return i;
}


INFO LISTA_remover_posicao(LISTA *l, int posicao)
{
    if(LISTA_vazia(l, true)) return INFO_default_value();

    INFO i = INFO_default_value();

    if(posicao <= 1) return LISTA_remove_inicio(l);
    else if(posicao >= l->tam) return LISTA_remove_fim(l);
    else 
    {
        NO_LISTA *aux_busca = l->inicio->prox;
        NO_LISTA *aux_remocao = l->inicio;

        for(int c = 2; c < posicao; c++)
        {
            aux_busca = aux_busca->prox;
            aux_remocao = aux_remocao->prox;
        }

        aux_remocao->prox = aux_busca->prox;
        aux_busca->prox = NULL;
        i = aux_busca->info;
        free(aux_busca);
        l->tam--;
    }
    
    return i;
}


void LISTA_prioridade_maxima(LISTA *, int posicao)
{
    return;
}


void LISTA_prioridade_minima(LISTA *, int posicao)
{
    return;
}


void LISTA_prioridade_salto(LISTA *, int posicao, int salto)
{
    return;
}


void LISTA_imprime(LISTA *l)
{
    if(LISTA_vazia(l, true)) return;

    NO_LISTA *aux = l->inicio;

    printf("\nImprimindo Lista Simples...\n\n");

    while(aux != NULL)
    {
        printf("ID: %d, Nome: %s\n", aux->info.ID, aux->info.nome);
        aux = aux->prox;
    }

    printf("\nTAM = %d\n\n", l->tam);
}


void LISTA_drop(LISTA *l)
{
    if(LISTA_vazia(l, true)) return;

    NO_LISTA *aux = l->inicio;

    printf("\nDrop Lista Simples...\n");

    while(aux != NULL)
    {
        l->inicio = l->inicio->prox;
        aux->prox = NULL;
        free(aux);
        aux = l->inicio;
    }

    // reorganiza ponteiros
    LISTA_inicia(l);
}
