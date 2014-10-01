typedef
    struct
    {
         int lin;
         int col;
    }
    Coordenada;

extern Coordenada constroiCoordenada(int linha, int coluna);

extern Coordenada somaCoordenada(Coordenada coordAtual, Coordenada coordNova);

extern Coordenada subtraiCoordenada(Coordenada coordAtual, Coordenada coordNova);

extern const Coordenada N;
extern const Coordenada S;
extern const Coordenada L;
extern const Coordenada O;
extern const Coordenada AQUI;

