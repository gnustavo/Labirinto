#include "Pilha.h"

typedef
    struct
    {
        Coordenada  dimensoes;
        char        **matriz;
        Pilha       *migalhas;
    }
    Labirinto;

extern Labirinto * constroiLabirinto(char *arquivo);

extern void destroiLabirinto(Labirinto * l);

extern char * labirintoToString(Labirinto * l);

extern void anda(Labirinto * l);

extern boolean chegou(Labirinto * l);
