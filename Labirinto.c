#include <stdio.h>
#include <stdlib.h>
#include "Labirinto.h"

static Coordenada leDimensoes(File *file) 
{
    unsigned int linha, coluna;
    int matches = fscanf(file, "%u %u ", &linha, &coluna);
    if (matches != 2) 
    {
        fprintf(stderr, "Sintaxe incorreta na primeira linha do arquivo.\n");
        exit(1);
    }
    return constroiCoordenada(linha, coluna);
}

Labirinto * constroiLabirinto(char *arq)
{
    FILE * arquivo;
    int i = 0;
    int j = 0;
    Labirinto * l = (Labirinto*) malloc (sizeof(Labirinto));
    char chr = getc(arquivo);
    char lin[2] = (char*) malloc (sizeof(char)); // char *linha[2] ?
    int linhas;
    char col[2] = (char*) malloc (sizeof(char)); // char *coluna[2] ?
    int colunas;

    Coordenada dimensoes;
    Coordenada entrada;
    Coordenada saida;
    Coordenada posicaoAtual;
    Fila direcoes;
    Pilha caminho;
    Migalha migalha;
    int i = 0;
    int j = 0;
    PontoCardeal frenteAtual;
    PontoCardeal esqAtual;
    PontoCardeal dirAtual;

    arquivo = fopen(arq, "r");
    if (arquivo == NULL) {
        fprintf(stderr, "Não foi possível abrir o arquivo %s.\n", arq);
        exit(1);
    }

    dimensoes = leDimensoes(arquivo);

    

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
