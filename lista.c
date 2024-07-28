#include "commons.h"
#include "info.h"
#include "lista.h"

int main(int argc, char **args)
{
    printf("\nLISTA SIMPLESMENTE ENCADEADA\n");

    LISTA compras;
    LISTA_inicia(&compras);

    INFO x;
    int pos = -1;

    x = INFO_set_interativo("O que devo comprar primeiro");
    LISTA_add_inicio(&compras, x);

    x = INFO_set_value(12, "Chinelo"); LISTA_add_inicio(&compras, x);
    x = INFO_set_value(1000, "Meias"); LISTA_add_fim(&compras, x);
    x = INFO_set_value(10, "Camisa"); LISTA_add_inicio(&compras, x);
    x = INFO_set_value(333, "Terceira pos"); LISTA_add_posicao(&compras, x, 3);
    x = INFO_set_value(999, "Item na ultima posicao"); LISTA_add_posicao(&compras, x, 5);
    x = INFO_set_value(111, "Item na primeira posicao"); LISTA_add_posicao(&compras, x, 1);
    
    LISTA_imprime(&compras);

    x = LISTA_get_info(&compras, 3);
    printf("\nINFO do 3o NO >>> ID: %d, Nome: %s\n", x.ID, x.nome);

    x = INFO_set_value(10, "Camisa");
    pos = LISTA_buscar_info(&compras, x);
    printf("\nINFO encontrada no %do NO >>> ID: %d, Nome: %s\n", pos, x.ID, x.nome);

    x = LISTA_remove_inicio(&compras);
    printf("\nNO removido do INICIO >>> ID: %d, Nome: %s\n", x.ID, x.nome);
    x = LISTA_remove_fim(&compras);
    printf("\nNO removido do FIM >>> ID: %d, Nome: %s\n", x.ID, x.nome);

    x = INFO_set_value(333, "Terceira pos");
    x = LISTA_remover_busca(&compras, x);
    printf("\nNO removido por BUSCA >>> ID: %d, Nome: %s\n", x.ID, x.nome);

    x = INFO_set_value(12, "Chinelo");
    x = LISTA_remover_posicao(&compras, 2);
    printf("\nNO removido por POSIÇÃO >>> ID: %d, Nome: %s\n", x.ID, x.nome);

    LISTA_imprime(&compras);

    LISTA_drop(&compras);

    LISTA_imprime(&compras);

    return 0;
}
