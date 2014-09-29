#include "Labirinto.h"

Labirinto * constroiLabirinto(char arq[])
{
    FILE * arquivo = fopen(arq, "r");
    int i = 0;
    int j = 0;
    Labirinto * l = (Labirinto*) malloc (sizeof(Labirinto));
    char chr = getc(arquivo);
    char lin[2] = (char*) malloc (sizeof(char)); // char *linha[2] ?
    int linhas;
    char col[2] = (char*) malloc (sizeof(char)); // char *coluna[2] ?
    int colunas;

    while (chr != ' ') {
        lin[i] = chr;
        chr = getc(arquivo);
        i++;
    }
    while (chr != '\n') {
        col[j] = chr;
        chr = getc(arquivo);
        j++;
    }

    linhas = atoi(lin);
    colunas = atoi(col);

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

    fclose(arquivo);
}

void destroiLabirinto(Labirinto * l)
{
    free(l->matriz);
    free(l);
}

char[] toString(Pilha* p)
{

}
