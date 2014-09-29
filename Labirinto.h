typedef
    struct
    {
        int linhas;
        int colunas;
        char matriz[][];
        Pilha * migalhas;
        Migalha * migalha;
    }
    Labirinto;

extern Labirinto * constroiLabirinto(char arquivo[]);

extern void destroiLabirinto(Labirinto * l);

extern char[] toString();
