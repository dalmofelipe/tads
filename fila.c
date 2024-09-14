#include "commons.h"
#include "info.h"
#include "fila.h"

int main(int argc, char **args)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    printf("\nFILA ENCADEADA\n");

    FILA banco;
    FILA_inicia(&banco);

    INFO x;

    x = INFO_set_interativo("Informe o PRIMEIRO(A) da FILA");
    FILA_enfileirar(&banco, x);

    x = INFO_set_value(222, "Segundo");
    FILA_enfileirar(&banco, x);

    x = INFO_set_value(333, "Terceiro");
    FILA_enfileirar(&banco, x);

    x = INFO_set_value(444, "Quarto");
    FILA_enfileirar(&banco, x);

    x = INFO_set_value(555, "Quinto");
    FILA_enfileirar(&banco, x);

    FILA_imprime(&banco);


    x = FILA_desemfilelar(&banco);
    printf("\nDesenfilerado >>> SENHA [ %d ]  Nome [ %s ]\n", x.ID, x.nome);


    x = FILA_get_primeiro(&banco);
    printf("\nPrimerio da FILA >>> SENHA [ %d ]  Nome [ %s ]\n\n", x.ID, x.nome);


    FILA_drop(&banco);
    FILA_imprime(&banco);
    

    x = INFO_set_value(111, "Primeiro");
    FILA_enfileirar(&banco, x);

    x = INFO_set_value(222, "Segundo");
    FILA_enfileirar(&banco, x);

    x = INFO_set_value(333, "Terceiro");
    FILA_enfileirar(&banco, x);

    FILA_imprime(&banco);
        
    return 0;
}