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
int  LISTA_buscar_posicao_info(LISTA *, INFO);
INFO LISTA_remove_inicio(LISTA *);
INFO LISTA_remove_fim(LISTA *);
INFO LISTA_remover_info(LISTA *, INFO);
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


// Retorna o INDEX da posição do NO encontrado. 
// Caso contrario, retorna -1 se nenhum dado foi encontrado
int LISTA_buscar_posicao_info(LISTA *l, INFO x)
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

// Remove por busca de INFO. 
// Critério de igualdade, segue implementação de INFO_is_equal
// Retorna a INFO encontrada. Caso contrário, retorna INFO_default_value
INFO LISTA_remover_info(LISTA *l, INFO x)
{
    INFO i = INFO_default_value();

    if(LISTA_vazia(l, true)) return i;

    if(INFO_is_equal(l->inicio->info, x)) return LISTA_remove_inicio(l);
    else if(INFO_is_equal(l->fim->info, x)) return LISTA_remove_fim(l);
    else 
    {
        NO_LISTA *aux_busca = l->inicio->prox;
        NO_LISTA *aux_remocao = l->inicio;

        while(aux_busca != l->fim)
        {
            // printf("\naux_busca->info.ID: %d, x.ID: %d\n", aux_busca->info.ID, x.ID);

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


//
// Desloca o NO ALVO para o INICIO da LISTA
//
// @param *l Endereço de memoria para LISTA
// @param idx_alvo Inteiro que indica posicão do ALVO
// @return Sem retorno
void LISTA_prioridade_maxima(LISTA *l, int idx_alvo)
{
    if(LISTA_vazia(l, true) || l->tam == 1) return;

    // range vai do 1 até o ultimo NO da LISTA
    if(idx_alvo < 1 || idx_alvo > l->tam -1) {
        printf("\n[LISTA_prioridade_maxima] Indice Inválido. ");
        printf("Informe um indice entre 1 e %d\n", l->tam -1);
        return;
    }

    NO_LISTA *p_alvo = NULL;
    NO_LISTA *p_anterior = NULL;

    // Caso especial, para indice l->tam -1, FIM da LISTA utimo NO
    if(idx_alvo == l->tam -1) 
    {
        p_alvo = l->fim;
        p_anterior = l->inicio;

        // posiciona ponteiro anterio, no penultimo NO
        while(p_anterior->prox != l->fim) p_anterior = p_anterior->prox;

        l->fim = p_anterior;
        p_anterior->prox = NULL;
        p_alvo->prox = l->inicio;
        l->inicio = p_alvo;
        return;
    }

    p_alvo = l->inicio->prox;
    p_anterior = l->inicio;

    // Posiciona ponteiro p_alvo no NO ALVO
    for(int a = 1; a < idx_alvo; a++) {
        p_alvo = p_alvo->prox;
        p_anterior = p_anterior->prox;
    }

    p_anterior->prox = p_alvo->prox;
    p_alvo->prox = l->inicio;
    l->inicio = p_alvo;
}


//
// Desloca o NO ALVO para o FIM da LISTA
//
// @param *l Endereço de memoria para LISTA
// @param idx_alvo Inteiro que indica posicão do ALVO
// @return Sem retorno
void LISTA_prioridade_minima(LISTA *l, int idx_alvo)
{
    if(LISTA_vazia(l, true) || l->tam == 1) return;

    // range vai do 0 até o pernultimo NO da LISTA
    if(idx_alvo < 0 || idx_alvo > l->tam -2) {
        printf("\n\\[nLISTA_prioridade_minima] Indice Inválido. ");
        printf("Informe uma indice entre 0 e %d\n", l->tam -2);
        return;
    }

    NO_LISTA *p_alvo = l->inicio;

    // Caso especial, para indice 0, INICIO da LISTA
    if(idx_alvo == 0) {
        l->inicio = l->inicio->prox;
        p_alvo->prox = NULL;
        l->fim->prox = p_alvo;
        l->fim = p_alvo;
        return;
    }

    p_alvo = l->inicio->prox;
    NO_LISTA *p_anterior = l->inicio;

    for(int a = 1; a < idx_alvo; a++) {
        p_alvo = p_alvo->prox;
        p_anterior = p_anterior->prox;
    }

    p_anterior->prox = p_alvo->prox;
    p_alvo->prox = l->fim->prox;
    l->fim->prox = p_alvo;
    l->fim = p_alvo;
}


//
// Desloca o NO ALVO de acordo com SALTO informado.
//
// Se SALTO negativo, NO ALVO salta em direção ao INICIO da LISTA
//
// Se SALTO positivo, NO ALVO salta em direção ao FIM da LISTA
// @param *l Endereço de memoria para LISTA
// @param idx_alvo Inteiro que representa ALVO
// @param salto Inteiro que representa SALTO diferente de zero
// @return Sem retorno
void LISTA_prioridade_salto(LISTA *l, int idx_alvo, int salto)
{
    // A LISTA não pode esta vazia, o SALTO deve ser diferente de zero
    if(LISTA_vazia(l, true) || l->tam == 1 || salto == 0) return;

    // O INDEX_ALVO deve esta no intervalo do tamanho da LISTA
    if(idx_alvo < 0 || idx_alvo > l->tam -1) return;

    int idx_destino = idx_alvo + salto;

    // Apos calculo de posicao do DESTINO deve esta no intervalo do tamanho da LISTA
    if(idx_destino < 0 || idx_destino > l->tam -1) {
        printf("\n[LISTA_prioridade_salto]: IDX_DESTINO fora do range da LISTA\n");
        return;
    }

    NO_LISTA *p_alvo = l->inicio;
    NO_LISTA *p_destino = l->inicio;
    NO_LISTA *aux_fim = NULL;
    NO_LISTA *aux_destino = NULL;

    INFO temp;

    for(int a = 0; a < idx_alvo; a++) p_alvo = p_alvo->prox;
    for(int d = 0; d < idx_destino; d++) p_destino = p_destino->prox;

    if(p_alvo == p_destino) return;

    // se extremos, troca de INFOs. MODIFICA estrutura
    if(p_alvo == l->inicio && p_destino == l->fim) {
        l->inicio = l->inicio->prox;
        p_alvo->prox = NULL;
        l->fim->prox = p_alvo;
        l->fim = p_alvo;
        return;
    }

    // se extremos, troca de INFOs. MODIFICA estrutura
    if(p_alvo == l->fim && p_destino == l->inicio) {
        // posiciona um ponteiro aux no penultimo NO (Lista Simplesmente Encadeada!)
        aux_fim = l->inicio;
        while(aux_fim->prox != l->fim) aux_fim = aux_fim->prox;

        l->fim = aux_fim;
        l->fim->prox = NULL;
        p_alvo->prox = l->inicio;
        l->inicio = p_alvo;
        return;
    }

    // quandos os ponteiros são vizinhos, apenas troca as INFOs.
    // Não modifica estrutura
    if(p_alvo->prox == p_destino || p_destino->prox == p_alvo) {
        temp = p_alvo->info;
        p_alvo->info = p_destino->info;
        p_destino->info = temp;
        return;
    }


    // p_alvo == inicio, destino é um NO interno, não vizinho, e não fim
    // altera estrutura de NOs
    if(p_alvo == l->inicio 
            && (p_destino != p_alvo->prox || p_destino != l->fim)) {
        l->inicio = l->inicio->prox;
        p_alvo->prox = p_destino->prox;
        p_destino->prox = p_alvo;
        return;
    }

    // p_alvo == fim, destino é um NO interno, não vizinho, e não inicio
    // altera estrutura de NOs
    if(p_alvo == l->fim 
            && (p_destino->prox != p_alvo || p_destino != l->inicio)) {
        // posiciona um ponteiro aux no penultimo NO (Lista Simplesmente Encadeada!)
        aux_fim = l->inicio;
        while(aux_fim->prox != l->fim) aux_fim = aux_fim->prox;
        
        l->fim = aux_fim;
        l->fim->prox = NULL;

        // posiciona um ponteiro aux anterior ao destino (Lista Simplesmente Encadeada!)
        aux_destino = l->inicio;
        while(aux_destino->prox != p_destino) aux_destino = aux_destino->prox;

        p_alvo->prox = p_destino;
        aux_destino->prox = p_alvo;       
        return;
    }
}


void LISTA_imprime(LISTA *l)
{
    if(LISTA_vazia(l, true)) return;

    NO_LISTA *aux = l->inicio;

    printf("\nImprimindo Lista Simples...\n\n");

    while(aux != NULL)
    {
        printf("ID: %-7.0d  Nome: %s\n", aux->info.ID, aux->info.nome);
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
