typedef
    struct
    {
         int X;
         int Y;
    }
    Coordenada;

extern Coordenada * constroiCoordenada(int abscissa, int ordenada);

extern void destroiCoordenada(Coordenada * c);

extern Coordenada * somaCoordenada(Coordenada * coordAtual, Coordenada * coordNova);

extern const Coordenada N;
