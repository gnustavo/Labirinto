
#include "Basico.h"
#include "Pilha.h"

Pilha * constroiPilha (unsigned int cap) // capacidade
{
	Pilha * p = (Pilha*) malloc (sizeof(Pilha));
	p->migalha = (Migalha*) malloc (cap*sizeof(Migalha));
	p->topo = -1;
	p->capacidade = cap;
	return p;
}

void destroiPilha (Pilha* p) // passagem por referência
{
	free(p->migalha);
	free(p);
}

boolean pilhaVazia (Pilha p)
{
    return topo == -1;
}

boolean pilhaCheia (Pilha p)
{
    return topo == capacidade - 1;
}

boolean empilha (Pilha * p, // passagem por referência
              ElemPilha e)
{
    if (p->topo < capacidade - 1) {
		p->topo++;
		p->migalha[p->topo] = e;
		return true;
	}
	return false;
}

boolean desempilha (Pilha * p, Migalha * m) // passagem por referência
{
    if (p->topo > -1) {
		*m = p->migalha[p->topo];
		p->topo--;
		return true;
	}
	return false;
}
