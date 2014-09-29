typedef
    struct
    {
        char info;
    }
    ElemFila

typedef
    struct
    {
        ElemFila * elem; // vetor
        unsigned int capacidade, topo;
    }
    Fila;


extern void constroiFila (unsigned int cap); // capacidade

extern void destroiFila (Fila * f); // passagem por referencia

extern boolean filaVazia (Fila f).

extern boolean filaCheia (Fila f);

externt void enfileira (Fila * f, // passagem por referencia
                        ElemFila e);

extern ElemPilha desenfileira (Fila * f); // passagem por referencia
