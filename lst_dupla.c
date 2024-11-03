#include "commons.h"
#include "info.h"
#include "lst_dupla.h"

int main(int argc, char **args)
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    printf("\nLISTA DUPLAMENTE ENCADEADA\n");

    LST_DUPLA empresas;
    LST_DUPLA_inicia(&empresas);

    INFO x;
    int pos = -1;

    // Preenche mantendo ordem LISTA adicionando itens pelo FIM
    x = INFO_set_value(100, "Tesla");               LST_DUPLA_add_fim(&empresas, x);
    x = INFO_set_value(200, "Apple");               LST_DUPLA_add_fim(&empresas, x);
    x = INFO_set_value(300, "Microsoft");           LST_DUPLA_add_fim(&empresas, x);
    x = INFO_set_value(400, "Google");              LST_DUPLA_add_fim(&empresas, x);
    x = INFO_set_value(500, "SpaceX");              LST_DUPLA_add_fim(&empresas, x);
    x = INFO_set_value(600, "Embraer");             LST_DUPLA_add_fim(&empresas, x);
    x = INFO_set_value(700, "Boston Dynamics");     LST_DUPLA_add_fim(&empresas, x);
    x = INFO_set_value(800, "NVIDIA");              LST_DUPLA_add_fim(&empresas, x);
    x = INFO_set_value(900, "Amazon");              LST_DUPLA_add_fim(&empresas, x);

    // x = INFO_set_interativo("Usuário, informe o nome de uma empresa");
    // LST_DUPLA_add_inicio(&empresas, x);

    printf("\nIMPRIMINDO DO INICIO AO FIM");
    LST_DUPLA_imprime(&empresas, false);

    // printf("\nIMPRIMINDO DO FIM AO INICIO");
    // LST_DUPLA_imprime(&empresas, true);


    // LST_DUPLA_prioridade_maxima(&empresas, 6);
    // LST_DUPLA_prioridade_maxima(&empresas, 7);
    // LST_DUPLA_prioridade_maxima(&empresas, 8);

    // LST_DUPLA_imprime(&empresas, false);

    // LST_DUPLA_prioridade_minima(&empresas, 3);
    // LST_DUPLA_prioridade_minima(&empresas, 4);
    // LST_DUPLA_prioridade_minima(&empresas, 5);
    // LST_DUPLA_prioridade_minima(&empresas, 0);
    // LST_DUPLA_prioridade_minima(&empresas, 0);
    // LST_DUPLA_prioridade_minima(&empresas, 0);

    // LST_DUPLA_imprime(&empresas, false);

    LST_DUPLA_prioridade_deslocamento(&empresas, 0, 8);
    LST_DUPLA_prioridade_deslocamento(&empresas, 0, 5);
    LST_DUPLA_imprime(&empresas, false);

    LST_DUPLA_prioridade_deslocamento(&empresas, 8, -8);
    LST_DUPLA_prioridade_deslocamento(&empresas, 8, -7);
    LST_DUPLA_imprime(&empresas, false);

    LST_DUPLA_prioridade_deslocamento(&empresas, 5, 2);
    LST_DUPLA_imprime(&empresas, false);

    LST_DUPLA_prioridade_deslocamento(&empresas, 5, -4);
    LST_DUPLA_imprime(&empresas, false);


    // Obter dados pelo indice
    x = LST_DUPLA_get_info(&empresas, 3);
    printf("\n[LST_DUPLA_get_info]: INFO do 3o NO >>> ID: %d, Nome: %s", x.ID, x.nome);


/*
    // Busca/pesquisando por informação (INFO)
    x = INFO_set_value(10, "Camisa"); // INFO: Camisa com ID 10
    pos = LST_DUPLA_buscar_posicao_info(&empresas, x, true); // -1 não encontrou nenhum dado!

    if (pos >= 0) {
        printf("\n[LST_DUPLA_buscar_posicao_info] ");
        printf("INFO encontrada no %do NO >>> ID: %d, Nome: %s", pos, x.ID, x.nome);
    } else {
        printf("\n[LST_DUPLA_buscar_posicao_info] ");
        printf("A INFO[%d, %s], não encontrada na LISTA\n", x.ID, x.nome);
    }

    // Remoção de INFO
    x = LST_DUPLA_remove_inicio(&empresas);
    printf("\n[LST_DUPLA_remove_inicio]\nNO removido do INICIO >>> ID: %d, Nome: %s\n", x.ID, x.nome);
    
    x = LST_DUPLA_remove_fim(&empresas);
    printf("\n[LST_DUPLA_remove_fim]\nNO removido do FIM >>> ID: %d, Nome: %s\n", x.ID, x.nome);

    x = INFO_set_value(333, "Terceira pos"); // Esta INFO não existe na LISTA
    x = LST_DUPLA_remover_info(&empresas, x); // Retorna INFO_default_value
    printf("\n[LST_DUPLA_remover_info]\nNO removido por busca de INFO >>> ID: %d, Nome: %s\n", x.ID, x.nome);

    INFO microsoft = INFO_set_value(300, "Microsoft");
    x = LST_DUPLA_remover_info(&empresas, microsoft);
    printf("\n[LST_DUPLA_remover_info]\nNO removido por busca de INFO >>> ID: %d, Nome: %s\n", x.ID, x.nome);

    x = LST_DUPLA_remover_posicao(&empresas, 2);
    printf("\n[LST_DUPLA_remover_posicao]\nNO removido por POSIÇÃO >>> ID: %d, Nome: %s\n\n", x.ID, x.nome);

    LST_DUPLA_imprime(&empresas, false);
*/

    // Limpa memoria alocada, retornando a lista para configuração inicial
    LST_DUPLA_drop(&empresas);

    LST_DUPLA_imprime(&empresas, false);

    return 0;
}
