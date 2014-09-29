#include <stdlib.h>
#include "Fila.h"

Fila * constroiFila (unsigned int cap) // capacidade
{
	Fila * f = (Fila*) malloc (sizeof(Fila));
	f->elem = (Coordenada*) malloc (cap*sizeof(Coordenada));
	f->topo = -1;
	f->capacidade = cap;
	return f;
}

void destroiFila (Fila* f) // passagem por referência
{
    free(f->elem);
	free(f);
}

boolean filaVazia (Fila *f)
{
    return f->topo == -1;
}

boolean filaCheia (Fila *f)
{
    return f->topo == f->capacidade - 1;
}

boolean enfileira (Fila * f, // passagem por referência
                   Coordenada c)
{
    int i;
    if (f->topo < f->capacidade - 1) {
        f->topo++;
        for(i = f->topo; i > 0; i--) {
            f->elem[i] = f->elem[i-1];
        }
        f->elem[0] = c;
        return true;
    }
    return false;
}

boolean desenfileira (Fila * f, Coordenada * c) // passagem por referência
{
    if (f->topo > -1) {
        *c  = f->elem[f->topo];
        f->topo--;
        return true;
    }
    return false;
}
