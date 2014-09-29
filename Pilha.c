#include <stdlib.h>
#include "Basico.h"
#include "Pilha.h"

Pilha * constroiPilha (unsigned int cap) // capacidade
{
	Pilha * p = (Pilha*) malloc (sizeof(Pilha));
	p->migalha = (Migalha**) malloc (cap*sizeof(Migalha*));
	p->topo = -1;
	p->capacidade = cap;
	return p;
}

void destroiPilha (Pilha* p) // passagem por referência
{
	free(p->migalha);
	free(p);
}

boolean pilhaVazia (Pilha * p)
{
    return p->topo == -1;
}

boolean pilhaCheia (Pilha * p)
{
    return p->topo == p->capacidade - 1;
}

boolean empilha (Pilha * p, // passagem por referência
                 Migalha * m)
{
    if (p->topo < p->capacidade - 1) {
        p->topo++;
        p->migalha[p->topo] = m;
        return true;
    }
    return false;
}

boolean desempilha (Pilha * p, Migalha **m) // passagem por referência
{
    if (p->topo > -1) {
        *m = p->migalha[p->topo];
        p->topo--;
        return true;
    }
    return false;
}

boolean topo (Pilha * p, Migalha **m) // passagem por referência
{
    if (p->topo > -1) {
        *m = p->migalha[p->topo];
        return true;
    }
    return false;
}

