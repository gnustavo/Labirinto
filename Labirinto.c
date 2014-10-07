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
    int j;
    
    /* Primeira e última posição podem ser [EMS]. */
    for (j=0; j<tam; j+=tam-1) 
    /* Não entendeu como funciona a linha acima? Pergunte-me como! :-) */
    {
        switch (linha[j]) 
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
    for (j=1; j<tam-1; ++j) 
    {
        switch (linha[j]) 
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
    int j;
    
    /* Primeira e última posição têm que ser [M]. */
    if (linha[0] != 'M' || linha[tam-1] != 'M')
    {
        return false;
    }

    /* As posições internas podem ser [EMS]. */
    for (j=1; j<tam-1; ++j) 
    {
        switch (linha[j]) 
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
                *entrada = constroiCoordenada(i, j);
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
        matriz[i] = (char*) malloc ((dim.col+1) * sizeof(char));
        linha = fgets(matriz[i], dim.col+1, arquivo);
        if (linha == NULL) 
        {
            fprintf(stderr, "Erro ao ler a linha %d do labirinto.\n", i);
            exit(1);
        }
        newline = fgetc(arquivo);
        if (newline != EOF && newline != '\n')
        {
            fprintf(stderr, "A linha %d é maior do que o especificado.\n", i);
            exit(1);
        }
    }

    for (i=1; i < dim.lin-1; ++i) 
    {
        if (!validaLinha(matriz[i], dim.col)) 
        {
            fprintf(stderr, "Erro de sintaxe na linha %d do labirinto.\n", i);
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

boolean chegou(Labirinto * l)
{
    Migalha *migalha = topo(l->migalhas);
    if (migalha == NULL)
        return false;
    else
        return l->matriz[migalha->posAtual.lin][migalha->posAtual.col] == 'S';
}

void anda(Labirinto * l)
{
    Migalha *migalha;
    Coordenada *dir;
    Coordenada proxPos;
    
    migalha = topo(l->migalhas);
    if (migalha == NULL)
    {
        fprintf(stderr, "Labirinto sem saída.\n");
        exit(1);
    }

    while (dir = proximaDirecao(&(migalha->direcoes)))
    {
        proxPos = somaCoordenada(migalha->posAtual, *dir);
            
        switch (l->matriz[proxPos.lin][proxPos.col]) {
        case ' ':
            l->matriz[proxPos.lin][proxPos.col] = '*';
            /* falls through */
        case 'S':
            empilha(l->migalhas, constroiMigalha(migalha->posAtual, proxPos));
            return;
        default:
            break;
        }
    }

    l->matriz[migalha->posAtual.lin][migalha->posAtual.col] = '-';

    desempilha(l->migalhas);
    destroiMigalha(migalha);

    return;
}

char * labirintoToString(Labirinto * l)
{
    int i;
    char *linha;

    char * string = (char*) malloc (l->dimensoes.lin * (l->dimensoes.col + 1) * sizeof(char) + 1);

    for (
         i=0, linha=string;
         i<l->dimensoes.lin;
         ++i, linha += (l->dimensoes.col + 1)
         )
    {
        sprintf(linha, "%*s\n", l->dimensoes.col, l->matriz[i]);
    }

    *linha = '\0';

    return string;
}
