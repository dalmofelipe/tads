
typedef struct info {
    int ID;
    char nome[MAXBUFF];
}   INFO;

INFO reset_info() 
{
    INFO i;
    i.ID = -999;
    strcpy(i.nome, "---");
    return i;
}

INFO set_info(int id, char *nome) 
{
    INFO i;
    i.ID = id;
    strcpy(i.nome, nome);
    return i;
}

INFO set_info_interativo(char *titulo) 
{
    INFO i;

    printf("\n%s:\n", titulo);
    printf("ID >>> ");
    scanf("%d", &i.ID);

    clear_buffer();

    printf("NOME >>> ");
    fgets(i.nome, sizeof(i.nome), stdin);

    return i;
}