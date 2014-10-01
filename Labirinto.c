#include <stdio.h>
#include <stdlib.h>
#include "Labirinto.h"

#define MINDIM 3
#define MAXDIM 80

static Coordenada leDimensoes(FILE *file) 
{
    unsigned int linha, coluna;
    int matches = fscanf(file, "%u %u ", &linha, &coluna);
    if (matches != 2) 
    {
        fprintf(stderr, "Sintaxe incorreta na primeira linha do arquivo.\n");
        exit(1);
    }
    if (linha < MINDIM || coluna < MINDIM || linha > MAXDIM || coluna > MAXDIM) 
    {
        fprintf(stderr, "As dimensoes do labirinto devem estar entre %d e %d.\n", MINDIM, MAXDIM);
        exit(1);
    }
    return constroiCoordenada(linha, coluna);
}

static boolean validaLinha(char *linha, int tam) 
{
    int i;
    
    /* Primeira e última posição podem ser [EMS]. */
    for (i=0; i<tam; i+=tam-1) 
    /* Não entendeu como funciona a linha acima? Pergunte-me como! :-) */
    {
        switch (linha[i]) 
        {
        case 'E':
        case 'M':
        case 'S':
            break;
        default:
            return false;
        }
    }

    /* As posições internas podem ser [ M]. */
    for (i=1; i<tam-1; ++i) 
    {
        switch (linha[i]) 
        {
        case 'M':
        case ' ':
            break;
        default:
            return false;
        }
    }

    return true;
}

static boolean validaLinhaExtrema(char *linha, int tam) 
{
    int i;
    
    /* Primeira e última posição têm que ser [M]. */
    if (linha[0] != 'M' || linha[tam-1] != 'M')
    {
        return false;
    }

    /* As posições internas podem ser [EMS]. */
    for (i=1; i<tam-1; ++i) 
    {
        switch (linha[i]) 
        {
        case 'E':
        case 'M':
        case 'S':
            break;
        default:
            return false;
        }
    }

    return true;
}

static boolean validaEntradaSaida(char **matriz, Coordenada dim, Coordenada *entrada)
{
    int i, j;
    int E=0;
    int S=0;

    for (i=0; i<dim.lin; i+=dim.lin-1) 
    /* Não entendeu como funciona a linha acima? Pergunte-me como! :-) */
    {
        for (j=1; j<dim.col-1; ++j)
        {
            switch (matriz[i][j]) 
            {
            case 'E':
                E++;
                *entrada = constroiCoordenada(i, j);
                break;
            case 'S':
                S++;
                break;
            }
        }
    }

    for (j=0; j<dim.col; j+=dim.col-1) 
    /* Não entendeu como funciona a linha acima? Pergunte-me como! :-) */
    {
        for (i=1; i<dim.lin-1; ++i)
        {
            switch (matriz[i][j]) 
            {
            case 'E':
                E++;
                break;
            case 'S':
                S++;
                break;
            }
        }
    }

    return (E == 1) && (S == 1);
}

static char **leMatriz(FILE *arquivo, Coordenada dim, Coordenada *entrada) 
{
    char **matriz = (char**) malloc (dim.lin * sizeof(char*));
    char *linha;
    int  i, newline;

    for (i=0; i < dim.lin; ++i) 
    {
        matriz[i] = (char*) malloc (dim.col * sizeof(char));
        linha = fgets(matriz[i], dim.col, arquivo);
        if (linha == NULL) 
        {
            fprintf(stderr, "Erro ao ler a linha %d do labirinto.\n", i);
            exit(1);
        }
        if (!validaLinha(linha, dim.col)) 
        {
            fprintf(stderr, "Erro de sintaxe na linha %d do labirinto.\n", i);
            exit(1);
        }
        newline = fgetc(arquivo);
        if (newline != EOF && newline != '\n')
        {
            fprintf(stderr, "A linha %d é maior do que o especificado.\n", i);
            exit(1);
        }
    }

    if (!validaLinhaExtrema(matriz[0], dim.col) || !validaLinhaExtrema(matriz[dim.lin-1], dim.col)) 
    {
        fprintf(stderr, "Erro de sintaxe na primeira e/ou na última linha do labirinto.\n");
        exit(1);
    }

    if (!validaEntradaSaida(matriz, dim, entrada))
    {
        fprintf(stderr, "Deve haver uma entrada e uma saída, apenas.\n");
        exit(1);
    }

    return matriz;
}

Labirinto * constroiLabirinto(char *arq)
{
    FILE * arquivo;
    Coordenada dimensoes;
    char **matriz;
    Coordenada entrada;
    Pilha *migalhas;
    Labirinto *labirinto;
    
    arquivo = fopen(arq, "r");
    if (arquivo == NULL) {
        fprintf(stderr, "Não foi possível abrir o arquivo %s.\n", arq);
        exit(1);
    }

    dimensoes = leDimensoes(arquivo);

    matriz = leMatriz(arquivo, dimensoes, &entrada);

    fclose(arquivo);
    
    migalhas = constroiPilha((dimensoes.lin-2)*(dimensoes.col-2)+2);

    empilha(migalhas, constroiMigalhaDaEntrada(entrada, dimensoes));

    labirinto = (Labirinto*) malloc (sizeof(Labirinto));

    labirinto->dimensoes = dimensoes;
    labirinto->matriz    = matriz;
    labirinto->migalhas  = migalhas;

    return labirinto;
}

void destroiLabirinto(Labirinto * l)
{
    int i;
    for (i=0; i<l->dimensoes.lin; ++i)
        free(l->matriz[i]);
    free(l->matriz);
    free(l);
}

/*
{
    int j = 0;
    Labirinto * l = (Labirinto*) malloc (sizeof(Labirinto));
    char chr = getc(arquivo);
    char lin[2] = (char*) malloc (sizeof(char)); // char *linha[2] ?
    int linhas;
    char col[2] = (char*) malloc (sizeof(char)); // char *coluna[2] ?
    int colunas;

    Coordenada entrada;
    Coordenada saida;
    Coordenada posicaoAtual;
    Fila direcoes;
    Migalha migalha;
    int i = 0;
    int j = 0;
    PontoCardeal frenteAtual;
    PontoCardeal esqAtual;
    PontoCardeal dirAtual;

    //achar a entrada E
    for (;;) {
        //primeira linha
        if (l->matriz[i][0] == 'E') {
            entrada = constroiCoordenada(i, 0);
            frenteAtual = S;
            esqAtual = L;
            dirAtual = O;
            break;
        }
        //última linha
        if (l->matriz[i][l->colunas - 1] == 'E') {
            entrada = constroiCoordenada(i, l->colunas - 1);
            frenteAtual = N;
            esqAtual = O;
            dirAtual = L;
            break;
        }
        //primeira coluna
        if (l->matriz[0][j] == 'E') {
            entrada = constroiCoordenada(0, j);
            frenteAtual = L;
            esqAtual = N;
            dirAtual = S;
            break;
        }
        //última coluna
        if (l->matriz[l->linhas - 1][j] == 'E') {
            entrada = constroiCoordenada(l->linhas - 1, j);
            frenteAtual = O;
            esqAtual = S;
            dirAtual = N;
            break;
        }

        i++;
        j++;
    }

    posicaoAtual = entrada;
    posicaoAtual = somaCoordenada(posicaoAtual, frenteAtual);

    if (l->matriz[posicaoAtual->X][posicaoAtual->Y] == 'M') {
        printf ('Labirinto sem saída')
    }

    //achar o caminho
    while(l->matriz[posicaoAtual->X + frenteAtual->X][posicaoAtual->Y + frenteAtual->Y] != 'S') {
        if (l->matriz[posicaoAtual->X + frenteAtual->X][posicaoAtual->Y + frenteAtual->Y] == ' ') {

        } else if (l->matriz[posicaoAtual->X + esqAtual->X][posicaoAtual->Y + esqAtual->Y] == ' ') {

        } else if (l->matriz[posicaoAtual->X + dirAtual->X][posicaoAtual->Y + dirAtual->Y] == ' ') {

        } else {
            //voltar (desempilhar, inverter frente, ...)
        }
    }

    // FIXME

    l->matriz = (char) malloc (linhas*colunas*sizeof(char));

    //acabou de ler o '\n' da primeira linha
    i = 0;
    j = 0;
    for(; chr != EOF; chr    = getc(arquivo), i++) {
        for(chr = getc(arquivo); chr != '\n'; chr = getc(arquivo), j++) {
            l->matriz[i][j] = chr;
        }
        j = 0;
    }

    l->linhas = i;
    l->colunas = j;
}

char[] toString(Pilha* p)
{

}
*/
