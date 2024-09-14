#include "commons.h"
#include "info.h"
#include "pilha.h"

int main(int argc, char **args)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    printf("\nPILHA ENCADEADA\n");

    PILHA livros;
    PILHA_inicia(&livros);

    INFO x;

    x = INFO_set_interativo("Informe os dados do PRIMEIRO Livro");
    printf("\nEmpilhando o livro >>> %s\n", x.nome);
    PILHA_empilhar(&livros, x);


    x = INFO_set_value(100, "O Hobbit");
    PILHA_empilhar(&livros, x);

    x = INFO_set_value(200, "Harry Potter e a Pedra Filosofal");
    PILHA_empilhar(&livros, x);

    x = INFO_set_value(300, "O Senho dos Aneis");
    PILHA_empilhar(&livros, x);

    x = INFO_set_value(400, "As Crônicas de Gelo e Fogo");
    PILHA_empilhar(&livros, x);
    
    PILHA_imprime(&livros);


    PILHA_get_topo(&livros);
    

    x = PILHA_desempilhar(&livros);
    printf("\n\nDesempilhado -> COD: %d, NAME: %s", x.ID, x.nome);

    x = PILHA_desempilhar(&livros);
    printf("\nDesempilhado -> COD: %d, NAME: %s\n\n", x.ID, x.nome);

    PILHA_imprime(&livros);


    x = PILHA_get_topo(&livros);

    PILHA_drop(&livros);
    PILHA_imprime(&livros);

    return 0;
}