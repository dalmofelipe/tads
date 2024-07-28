#include "commons.h"
#include "info.h"
#include "pilha.h"

int main(int argc, char **args)
{
    printf("\nPILHA ENCADEADA\n");

    PILHA livros;
    inicia_pilha(&livros);

    INFO x;

    x = set_info_interativo("Informe os dados do PRIMEIRO Livro");
    printf("\nEmpilhando o livro >>> %s\n", x.nome);
    empilhar(&livros, x);


    x = set_info(100, "O Hobbit");
    empilhar(&livros, x);

    x = set_info(200, "Harry Potter e a Pedra Filosofal");
    empilhar(&livros, x);

    x = set_info(300, "O Senho dos Aneis");
    empilhar(&livros, x);

    x = set_info(400, "As Crônicas de Gelo e Fogo");
    empilhar(&livros, x);
    
    imprime_pilha(&livros);


    consulta_topo(&livros);
    

    x = desempilhar(&livros);
    printf("\n\nDesempilhado -> COD: %d, NAME: %s", x.ID, x.nome);

    x = desempilhar(&livros);
    printf("\nDesempilhado -> COD: %d, NAME: %s\n\n", x.ID, x.nome);

    imprime_pilha(&livros);


    x = consulta_topo(&livros);

    drop_pilha(&livros);
    imprime_pilha(&livros);

    return 0;
}