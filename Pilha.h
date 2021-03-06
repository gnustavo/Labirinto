#include "Migalha.h"

typedef
    struct
    {
        Migalha **migalha; // vetor
        int capacidade, topo;
    }
    Pilha;

extern Pilha * constroiPilha (unsigned int cap); // capacidade

extern void destroiPilha (Pilha * p); // passagem por referencia

extern boolean pilhaVazia (Pilha * p);

extern boolean pilhaCheia (Pilha * p);

extern boolean empilha (Pilha * p, // passagem por referencia
                        Migalha *m);

extern Migalha * desempilha (Pilha * p); // passagem por referencia

extern Migalha * topo (Pilha * p); // passagem por referencia

