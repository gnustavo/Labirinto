typedef
    struct
    {
        Coordenada posAtual;
        Fila * direcoes;
    }
    Migalha;

extern Migalha * constroiMigalha(Coordenada posicaoAtual, Fila * dir);

extern void destroiMigalha(Migalha * m);
