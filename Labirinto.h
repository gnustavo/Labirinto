#include "Pilha.h"

typedef
    struct
    {
        int linhas;
        int colunas;
        char **matriz;
        Pilha * migalhas;
    }
    Labirinto;

extern Labirinto * constroiLabirinto(char *arquivo);

extern void destroiLabirinto(Labirinto * l);

extern char * toString();

extern void anda(Labirinto * l);

extern boolean chegou(Labirinto * l);
