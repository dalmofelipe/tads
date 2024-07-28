#include "commons.h"
#include "info.h"
#include "fila.h"

int main(int argc, char **args)
{
    printf("\nFILA ENCADEADA\n");

    FILA banco;
    inicia_fila(&banco);

    INFO x;

    x = set_info_interativo("Informe o PRIMEIRO(A) da FILA");
    enfileirar(&banco, x);

    x = set_info(222, "Segundo");
    enfileirar(&banco, x);

    x = set_info(333, "Terceiro");
    enfileirar(&banco, x);

    x = set_info(444, "Quarto");
    enfileirar(&banco, x);

    x = set_info(555, "Quinto");
    enfileirar(&banco, x);

    imprime_fila(&banco);


    x = desemfilelar(&banco);
    printf("\nDesenfilerado >>> SENHA [ %d ]  Nome [ %s ]\n", x.ID, x.nome);


    x = consulta_fila(&banco);
    printf("\nPrimerio da FILA >>> SENHA [ %d ]  Nome [ %s ]\n\n", x.ID, x.nome);


    drop_fila(&banco);
    imprime_fila(&banco);
    

    x = set_info(111, "Primeiro");
    enfileirar(&banco, x);

    x = set_info(222, "Segundo");
    enfileirar(&banco, x);

    x = set_info(333, "Terceiro");
    enfileirar(&banco, x);

    imprime_fila(&banco);
        
    return 0;
}