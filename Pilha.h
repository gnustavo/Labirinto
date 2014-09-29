typedef
    struct
    {
        Migalha * migalha; // vetor
        unsigned int capacidade, topo;
    }
    Pilha;

extern Pilha * constroiPilha (unsigned int cap); // capacidade

extern void destroiPilha (Pilha * p); // passagem por referencia

extern boolean pilhaVazia (Pilha p);

extern boolean pilhaCheia (Pilha p);

extern void empilha (Pilha * p, // passagem por referencia
                     Migalha m)

extern boolean desempilha (Pilha * p); // passagem por referencia
