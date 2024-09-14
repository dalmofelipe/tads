#include "commons.h"
#include "info.h"
#include "lista.h"

int main(int argc, char **args)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    printf("\nLISTA SIMPLESMENTE ENCADEADA\n");

    LISTA compras;
    LISTA_inicia(&compras);

    INFO x;
    int pos = -1;

    // Preenche mantendo ordem LISTA adicionando itens pelo FIM
    x = INFO_set_value(100, "100 primeiro"); LISTA_add_fim(&compras, x);
    x = INFO_set_value(200, "200 segundo"); LISTA_add_fim(&compras, x);
    x = INFO_set_value(300, "300 terceiro"); LISTA_add_fim(&compras, x);
    x = INFO_set_value(400, "400 quarto"); LISTA_add_fim(&compras, x);
    x = INFO_set_value(500, "500 quinto"); LISTA_add_fim(&compras, x);
    x = INFO_set_value(600, "600 sexto"); LISTA_add_fim(&compras, x);
    x = INFO_set_value(700, "700 sétimo"); LISTA_add_fim(&compras, x);
    x = INFO_set_value(800, "800 oitávo"); LISTA_add_fim(&compras, x);
    x = INFO_set_value(900, "900 nono"); LISTA_add_fim(&compras, x);

    x = INFO_set_interativo("Usuário, preencha os dados que serão inseridos no início da LISTA");
    LISTA_add_inicio(&compras, x);

    LISTA_imprime(&compras);


    printf("\nAlterando prioridades de NOs da LISTA...");
    printf("\nAtenção aos indices a cada alteração!");
    
    LISTA_prioridade_maxima(&compras, 1); // Vai para o inicio da LISTA
    LISTA_prioridade_maxima(&compras, 5);
    LISTA_prioridade_maxima(&compras, 9); // do ultimo NO para o primeiro

    LISTA_prioridade_minima(&compras, 6); // Vai para o fim da LISTA
    LISTA_prioridade_minima(&compras, 8);
    LISTA_prioridade_minima(&compras, 0); // do primeiro NO para ultimo

    LISTA_prioridade_salto(&compras, 0, 9);
    LISTA_prioridade_salto(&compras, 9, 8); // invalido!
    LISTA_prioridade_salto(&compras, 8, 1);
    LISTA_prioridade_salto(&compras, 9, -2);
    LISTA_prioridade_salto(&compras, 5, 5);
    LISTA_prioridade_salto(&compras, 5, 6);

    LISTA_imprime(&compras);


    // Obter dados pelo indice
    x = LISTA_get_info(&compras, 3);
    printf("\n[LISTA_get_info]: INFO do 3o NO >>> ID: %d, Nome: %s", x.ID, x.nome);


    // Busca/pesquisando por informação (INFO)
    x = INFO_set_value(10, "Camisa"); // INFO: Camisa com ID 10
    pos = LISTA_buscar_posicao_info(&compras, x); // -1 não encontrou nenhum dado!

    if (pos >= 0) {
        printf("\n[LISTA_buscar_posicao_info] ");
        printf("INFO encontrada no %do NO >>> ID: %d, Nome: %s", pos, x.ID, x.nome);
    } else {
        printf("\n[LISTA_buscar_posicao_info] ");
        printf("A INFO[%d, %s], não encontrada na LISTA\n", x.ID, x.nome);
    }


    // Remoção de INFO
    x = LISTA_remove_inicio(&compras);
    printf("\n[LISTA_remove_inicio]\nNO removido do INICIO >>> ID: %d, Nome: %s\n", x.ID, x.nome);
    
    x = LISTA_remove_fim(&compras);
    printf("\n[LISTA_remove_fim]\nNO removido do FIM >>> ID: %d, Nome: %s\n", x.ID, x.nome);

    x = INFO_set_value(333, "Terceira pos"); // Esta INFO não existe na LISTA
    x = LISTA_remover_info(&compras, x); // Retorna INFO_default_value
    printf("\n[LISTA_remover_info]\nNO removido por busca de INFO >>> ID: %d, Nome: %s\n", x.ID, x.nome);

    INFO i700 = INFO_set_value(700, "700 sétimo");
    x = LISTA_remover_info(&compras, i700);
    printf("\n[LISTA_remover_info]\nNO removido por busca de INFO >>> ID: %d, Nome: %s\n", x.ID, x.nome);

    x = LISTA_remover_posicao(&compras, 2);
    printf("\n[LISTA_remover_posicao]\nNO removido por POSIÇÃO >>> ID: %d, Nome: %s\n\n", x.ID, x.nome);

    LISTA_imprime(&compras);


    // Limpa memoria alocada, retornando a lista para configuração inicial
    LISTA_drop(&compras);

    LISTA_imprime(&compras);

    return 0;
}
