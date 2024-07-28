
typedef struct info {
    int ID;
    char nome[MAXBUFF];
}   INFO;

INFO INFO_default_value() 
{
    INFO i;
    i.ID = -999;
    strcpy(i.nome, "---");
    return i;
}

INFO INFO_set_value(int id, char *nome) 
{
    INFO i;
    i.ID = id;
    strcpy(i.nome, nome);
    return i;
}

INFO INFO_set_interativo(char *titulo) 
{
    INFO i;

    printf("\n%s:\n", titulo);
    printf("ID >>> ");
    scanf("%d", &i.ID);
    clear_buffer();

    printf("NOME >>> ");
    fgets(i.nome, sizeof(i.nome), stdin);

    size_t length = strlen(i.nome);
    
    if (length > 0 && i.nome[length - 1] == '\n') {
        i.nome[length - 1] = '\0';
    }

    return i;
}

bool INFO_is_equal(INFO x, INFO y)
{
    if(x.ID == y.ID && strcmp(x.nome, y.nome) == 0) return true;

    return false;
}
