// LISTA SIMPLESMENTE ENCADEADA

typedef struct no_lst_dupla {
    INFO info;
    struct no_lst_dupla *prox;
    struct no_lst_dupla *anterior;
}   NO_LST_DUPLA;

typedef struct lista {
    int tam;
    NO_LST_DUPLA *inicio, *fim;
}   LST_DUPLA;


// Assinaturas
void LST_DUPLA_inicia(LST_DUPLA *);
bool LST_DUPLA_vazia(LST_DUPLA *, bool);
void LST_DUPLA_add_inicio(LST_DUPLA *, INFO);
void LST_DUPLA_add_fim(LST_DUPLA *, INFO);
void LST_DUPLA_add_posicao(LST_DUPLA *, INFO, int);
INFO LST_DUPLA_get_info(LST_DUPLA *, int);
int  LST_DUPLA_buscar_posicao_info(LST_DUPLA *, INFO, bool);
INFO LST_DUPLA_remove_inicio(LST_DUPLA *);
INFO LST_DUPLA_remove_fim(LST_DUPLA *);
INFO LST_DUPLA_remover_info(LST_DUPLA *, INFO);
INFO LST_DUPLA_remover_posicao(LST_DUPLA *, int);
void LST_DUPLA_prioridade_maxima(LST_DUPLA *, int);
void LST_DUPLA_prioridade_minima(LST_DUPLA *, int);
void LST_DUPLA_prioridade_salto(LST_DUPLA *, int, int);
void LST_DUPLA_imprime(LST_DUPLA *, bool);
void LST_DUPLA_drop(LST_DUPLA *);


void LST_DUPLA_inicia(LST_DUPLA *ld)
{
    ld->tam = 0;
    ld->inicio = NULL;
    ld->fim = NULL;
}


bool LST_DUPLA_vazia(LST_DUPLA *ld, bool exibir_mensagem)
{
    if(ld->tam == 0 && ld->inicio == NULL && ld->fim == NULL) {
        if(exibir_mensagem) printf("\nLista Simples Vazia...\n");
        return true;
    }

    return false;
}


void LST_DUPLA_add_inicio(LST_DUPLA *ld, INFO x)
{
    NO_LST_DUPLA *novo = (NO_LST_DUPLA *) malloc(sizeof(NO_LST_DUPLA));

    if(novo == NULL) {
        printf("\nMemória Insulficiente! - [add_inicio_lista()]\n");
        return;
    }

    novo->info = x;
    
    if(LST_DUPLA_vazia(ld, false)) {
        ld->inicio = novo;
        ld->fim = novo;
        novo->prox = NULL;
        novo->anterior = NULL;
    }
    else {
        novo->prox = ld->inicio;
        novo->anterior = NULL;
        ld->inicio->anterior = novo;
        ld->inicio = novo;
    }

    ld->tam++;
}


void LST_DUPLA_add_fim(LST_DUPLA *ld, INFO x)
{
    NO_LST_DUPLA *novo = (NO_LST_DUPLA *) malloc(sizeof(NO_LST_DUPLA));

    // Valida se o espaço em memoria foi alocado
    if(novo == NULL) {
        printf("\n[LST_DUPLA_add_fim] Memória Insulficiente!\n");
        return;
    }

    novo->info = x;
    
    if(LST_DUPLA_vazia(ld, false)) {
        ld->inicio = novo;
        ld->fim = novo;
        novo->prox = NULL;
        novo->anterior = NULL;
    }
    else {
        novo->prox = NULL;
        novo->anterior = ld->fim;
        ld->fim->prox = novo;
        ld->fim = novo;
    }

    ld->tam++;
}


 
// Adiciona novo NO na LST_DUPLA, de acordo com a posição (zero-index) informada
// @param *ld Endereço de memória para LST_DUPLA
// @param x INFO que será inserida na lista
// @param posicao Valor inteiro zero index que indica posição a ser inserida
void LST_DUPLA_add_posicao(LST_DUPLA *ld, INFO x, int posicao)
{
    NO_LST_DUPLA *novo = (NO_LST_DUPLA *) malloc(sizeof(NO_LST_DUPLA));
    
    if(novo == NULL) {
        printf("\n[LST_DUPLA_add_posicao] Memória Insulficiente!\n");
        return;
    }

    if(posicao <= 0) LST_DUPLA_add_inicio(ld, x);
    else if(posicao >= ld->tam) LST_DUPLA_add_fim(ld, x);
    else {
        NO_LST_DUPLA *aux = ld->inicio;

        for(int i = 0; i < posicao; i++) aux = aux->prox;

        novo->info = x;

        // entrelaça ponteiros anterior ao novo NO
        aux->anterior->prox = novo;
        novo->anterior = aux->anterior;
        
        // entrelaça ponteiros posterior ao novo NO
        novo->prox = aux;
        aux->anterior = novo;

        ld->tam++;
    }
}


INFO LST_DUPLA_get_info(LST_DUPLA *ld, int posicao)
{
    if(LST_DUPLA_vazia(ld, true)) return INFO_default_value();

    if(posicao <= 0) return ld->inicio->info;
    else if(posicao >= ld->tam) return ld->fim->info;
    else {
        NO_LST_DUPLA *aux = ld->inicio;

        for(int i = 0; i < posicao; i++) aux = aux->prox;
        
        return aux->info;
    }
}


// Busca indice (zero-index) da INFO
// @param *ld Endereço de memória para LST_DUPLA
// @param x INFO que será inserida na lista
// @param reverso Valor booleano para executar busca do fim para o inicio da LST_DUPLA
// @return Retorna o indice (zero-index) da INFO se encontrada, caso contrário retorná -1.
int LST_DUPLA_buscar_posicao_info(LST_DUPLA *ld, INFO x, bool reverso)
{
    if(LST_DUPLA_vazia(ld, true)) return -1;

    int contador = (reverso) ? ld->tam -1 : 0;

    NO_LST_DUPLA *aux = (reverso) ? ld->fim : ld->inicio;

    while(aux != NULL) {
        if(INFO_is_equal(aux->info, x)) return contador;

        if(reverso) {
            aux = aux->anterior;
            contador--;
        } 
        else {
            aux = aux->prox;
            contador++;
        }
    }

    return -1;
}


INFO LST_DUPLA_remove_inicio(LST_DUPLA *ld)
{
    if(LST_DUPLA_vazia(ld, true)) return INFO_default_value();

    NO_LST_DUPLA *aux = ld->inicio;

    ld->inicio = ld->inicio->prox; // *inicio foi para o segundo NO
    ld->inicio->anterior = NULL; // O ponteiro anterior do segundo NO deve ir para NULL
    aux->prox = NULL; // *aux com primeiro NO isolado!

    INFO x = aux->info;
    free(aux); // Libera memória da estrutura do NO
    ld->tam--; // !!! IMPORTANTE, atualizar o tamanho da lista

    return x;
}


INFO LST_DUPLA_remove_fim(LST_DUPLA *ld)
{
    if(LST_DUPLA_vazia(ld, true)) return INFO_default_value();

    NO_LST_DUPLA *aux = ld->fim;
    
    ld->fim = ld->fim->anterior;
    ld->fim->prox = NULL;
    aux->anterior = NULL;
    
    INFO x = aux->info;
    free(aux);
    ld->tam--;

    return x;
}


// Remove por busca de INFO. 
// Critério de igualdade, segue implementação de INFO_is_equal
// Retorna a INFO encontrada. Caso contrário, retorna INFO_default_value
INFO LST_DUPLA_remover_info(LST_DUPLA *ld, INFO x)
{
    INFO i = INFO_default_value();

    if(LST_DUPLA_vazia(ld, true)) return i;

    if(INFO_is_equal(ld->inicio->info, x)) return LST_DUPLA_remove_inicio(ld);
    else if(INFO_is_equal(ld->fim->info, x)) return LST_DUPLA_remove_fim(ld);
    else 
    {
        NO_LST_DUPLA *aux = ld->inicio;

        while(aux != ld->fim) 
        {
            if(INFO_is_equal(aux->info, x)) {
                aux->anterior->prox = aux->prox;
                aux->prox->anterior = aux->anterior;
                aux->prox = NULL;
                aux->anterior = NULL;

                i = aux->info;
                free(aux);
                ld->tam--;
                break;
            }
            aux = aux->prox;
        }
    }
    return i;
}


INFO LST_DUPLA_remover_posicao(LST_DUPLA *ld, int posicao)
{
    INFO i = INFO_default_value();

    if(LST_DUPLA_vazia(ld, true)) return i;

    if(posicao <= 1) return LST_DUPLA_remove_inicio(ld);
    else if(posicao >= ld->tam) return LST_DUPLA_remove_fim(ld);
    else 
    {
        NO_LST_DUPLA *aux = ld->inicio;

        for(int c = 0; c < posicao; c++) aux = aux->prox;

        aux->anterior->prox = aux->prox;
        aux->prox->anterior = aux->anterior;
        aux->prox = NULL;
        aux->anterior = NULL;
        
        i = aux->info;
        free(aux);
        ld->tam--;
    }
    
    return i;
}

//*
//
// Desloca o NO ALVO para o INICIO da LISTA
//
// @param *l Endereço de memoria para LISTA
// @param idx_alvo Inteiro que indica posicão do ALVO
// @return Sem retorno
void LST_DUPLA_prioridade_maxima(LST_DUPLA *ld, int idx_alvo)
{
    if(LST_DUPLA_vazia(ld, true) || ld->tam == 1) return;

    // range vai do 1 até o ultimo NO da LISTA
    if(idx_alvo < 1 || idx_alvo > ld->tam -1) {
        printf("\n[LISTA_prioridade_maxima] Indice Inválido. ");
        printf("Informe um indice entre 1 e %d\n", ld->tam -1);
        return;
    }

    NO_LST_DUPLA *p_alvo = ld->fim;

    // Caso especial, para indice ld->tam -1, FIM da LISTA utimo NO
    if(idx_alvo == ld->tam -1) {
        ld->fim = ld->fim->anterior;
        ld->fim->prox = NULL;
        p_alvo->anterior = NULL;
        p_alvo->prox = ld->inicio;
        ld->inicio->anterior = p_alvo;
        ld->inicio = p_alvo;
        return;
    }

    p_alvo = ld->inicio->prox; // deve começar no segundo NO
    for(int a = 1; a < idx_alvo; a++) p_alvo = p_alvo->prox;

    p_alvo->anterior->prox = p_alvo->prox;
    p_alvo->prox->anterior = p_alvo->anterior;
    p_alvo->prox = ld->inicio;
    p_alvo->anterior = NULL;
    ld->inicio->anterior = p_alvo;
    ld->inicio = p_alvo;
}


//
// Desloca o NO ALVO para o FIM da LISTA
//
// @param *l Endereço de memoria para LISTA
// @param idx_alvo Inteiro que indica posicão do ALVO
// @return Sem retorno
void LST_DUPLA_prioridade_minima(LST_DUPLA *ld, int idx_alvo)
{
    if(LST_DUPLA_vazia(ld, true) || ld->tam == 1) return;

    // range vai do 0 até o pernultimo NO da LISTA
    if(idx_alvo < 0 || idx_alvo > ld->tam -2) {
        printf("\n\\[nLISTA_prioridade_minima] Indice Inválido. ");
        printf("Informe uma indice entre 0 e %d\n", ld->tam -2);
        return;
    }

    NO_LST_DUPLA *p_alvo = ld->inicio;

    // Caso especial, para indice 0, INICIO da LISTA
    if(idx_alvo == 0) {
        ld->inicio = ld->inicio->prox;
        ld->inicio->anterior = NULL;
        p_alvo->prox = NULL;
        p_alvo->anterior = ld->fim;
        ld->fim->prox = p_alvo;
        ld->fim = p_alvo;
        return;
    }

    p_alvo = ld->inicio->prox; // deve começar no segundo NO
    for(int a = 1; a < idx_alvo; a++) p_alvo = p_alvo->prox;

    p_alvo->anterior->prox = p_alvo->prox;
    p_alvo->prox->anterior = p_alvo->anterior;
    p_alvo->prox = NULL;
    p_alvo->anterior = ld->fim;
    ld->fim->prox = p_alvo;
    ld->fim = p_alvo;
}


//*
// Desloca o NO ALVO de acordo com SALTO informado.
//
// Se SALTO negativo, NO ALVO salta em direção ao INICIO da LISTA
//
// Se SALTO positivo, NO ALVO salta em direção ao FIM da LISTA
// @param *l Endereço de memoria para LISTA
// @param idx_alvo Inteiro que representa ALVO
// @param salto Inteiro que representa SALTO diferente de zero
// @return Sem retorno
void LST_DUPLA_prioridade_salto(LST_DUPLA *ld, int idx_alvo, int salto)
{
    // A LISTA não pode esta vazia, o SALTO deve ser diferente de zero
    if(LST_DUPLA_vazia(ld, true) || ld->tam == 1 || salto == 0) return;

    // O INDEX_ALVO deve esta no intervalo do tamanho da LISTA
    if(idx_alvo < 0 || idx_alvo > ld->tam -1) return;

    int idx_destino = idx_alvo + salto;

    // Apos calculo de posicao do DESTINO deve esta no intervalo do tamanho da LISTA
    if(idx_destino < 0 || idx_destino > ld->tam -1) {
        printf("\n[LISTA_prioridade_salto]: IDX_DESTINO fora do range da LISTA\n");
        return;
    }

    NO_LST_DUPLA *p_alvo = ld->inicio;
    NO_LST_DUPLA *p_destino = ld->inicio;

    INFO temp;

    for(int a = 0; a < idx_alvo; a++) p_alvo = p_alvo->prox;
    for(int d = 0; d < idx_destino; d++) p_destino = p_destino->prox;

    if(p_alvo == p_destino) return;

    // se extremos, MODIFICA estrutura
    if(p_alvo == ld->inicio && p_destino == ld->fim) {
        ld->inicio = ld->inicio->prox;
        ld->inicio->anterior = NULL;

        p_alvo->prox = NULL;
        p_alvo->anterior = ld->fim;
        
        ld->fim->prox = p_alvo;
        ld->fim = p_alvo;
        return;
    }

    // se extremos, desloca NO do *fim para *inicio, MODIFICA estrutura
    if(p_alvo == ld->fim && p_destino == ld->inicio) {
        ld->fim = ld->fim->anterior;
        ld->fim->prox = NULL;

        p_alvo->prox = ld->inicio;
        p_alvo->anterior = NULL;
        
        ld->inicio->anterior = p_alvo;
        ld->inicio = p_alvo;
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
    // altera estrutura de NOs, p_alvo é deslocado apos do p_destino
    if(p_alvo == ld->inicio 
            && (p_destino != p_alvo->prox || p_destino != ld->fim)) {
        ld->inicio = ld->inicio->prox;
        ld->inicio->anterior = NULL;

        p_destino->prox->anterior = p_alvo;
        p_alvo->prox = p_destino->prox;
        p_alvo->anterior = p_destino;
        p_destino->prox = p_alvo;
        return;
    }

    // p_alvo == fim, destino é um NO interno, não vizinho, e não inicio
    // altera estrutura de NOs
    if(p_alvo == ld->fim 
            && (p_destino->prox != p_alvo || p_destino != ld->inicio)) {
        ld->fim = ld->fim->anterior;
        ld->fim->prox = NULL;

        p_destino->anterior->prox = p_alvo;
        p_alvo->anterior = p_destino->anterior;
        p_alvo->prox = p_destino;
        p_destino->anterior = p_alvo;
        return;
    }
}
//*/

void LST_DUPLA_imprime(LST_DUPLA *ld, bool reverso)
{
    if(LST_DUPLA_vazia(ld, true)) return;

    NO_LST_DUPLA *aux = (reverso) ? ld->fim : ld->inicio;

    printf("\nImprimindo Lista Dupla...\n\n");

    while(aux != NULL)
    {
        printf("ID: %-7.0d  Nome: %s\n", aux->info.ID, aux->info.nome);

        if(reverso) aux = aux->anterior;
        else aux = aux->prox;
    }

    printf("\nTAM = %d\n\n", ld->tam);
}


void LST_DUPLA_drop(LST_DUPLA *ld)
{
    if(LST_DUPLA_vazia(ld, true)) return;

    NO_LST_DUPLA *aux = NULL;

    printf("\nDrop Lista Dupla...\n");

    while(true) 
    {
        aux = ld->inicio;

        printf("\n[DROP] INFO[ID:%-4d Nome:%s]", aux->info.ID, aux->info.nome);

        if(ld->inicio == ld->fim) {
            free(ld->inicio); // ultimo NO
            LST_DUPLA_inicia(ld);
            break;
        }

        ld->inicio = ld->inicio->prox;
        ld->inicio->anterior = NULL;
        ld->tam--;

        aux->prox = NULL;
        aux->anterior = NULL;
        free(aux);
    }
}
