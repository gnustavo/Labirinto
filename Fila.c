#include "Basico.h"
#include "Fila.h"

Fila * constroiFila (unsigned int cap) // capacidade
{
	Fila * f = (Fila*) malloc (sizeof(Pilha));
	f->elem = (ElemFila*) malloc (cap*sizeof(ElemFila));
	f->topo = -1;
	f->capacidade = cap;
	return f;
}

void destroiFila (Fila* f) // passagem por referência
{
    free(f->elem);
	free(f);
}

boolean filaVazia (Fila f)
{
    return topo == -1;
}

boolean filaCheia (Fila f)
{
    return topo == capacidade - 1;
}

boolean enfileira (Fila* f, // passagem por referência
              ElemFila e)
{
	int i;
    if (f->topo < capacidade - 1) {
		f->topo++;
		for(i = f->topo; i > 0; i--) {
			f->elem[i] = f->elem[i-1];
		}
		f->elem[0] = e;
		return true;
	}
	return false;
}

ElemPilha desenfileira (Fila* f, ElemPilha* e) // passagem por referência
{
    if (f->topo > -1) {
		*e  = f->elem[f->topo];
		f->topo--;
		return true;
	}
	return false;
}
