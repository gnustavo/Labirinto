#include "Basico.h"
#include "Coordenada.h"

typedef
    struct
    {
        Coordenada * elem; // vetor
        unsigned int capacidade, topo;
    }
    Fila;


extern Fila * constroiFila (unsigned int cap); // capacidade

extern void destroiFila (Fila * f); // passagem por referencia

extern boolean filaVazia (Fila * f);

extern boolean filaCheia (Fila * f);

extern boolean enfileira (Fila * f, // passagem por referencia
                          Coordenada c);

extern boolean desenfileira (Fila * f, Coordenada *c); // passagem por referencia

