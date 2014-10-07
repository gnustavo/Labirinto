#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "Labirinto.h"

int main(int argc, char *argv[])
{
    Labirinto * l;
    int opt, usecs;
    char *lab;

    usecs = 0;
    while ((opt = getopt(argc, argv, "d:")) != -1) {
        switch (opt) {
        case 'd':
            usecs = atoi(optarg) * 1000;
            break;
        default: /* '?' */
            fprintf(stderr, "Uso: %s [-d msecs] ARQUIVO\n",
                    argv[0]);
            exit(EXIT_FAILURE);
        }
    }

    if (optind >= argc) {
        fprintf(stderr, "Falta nome do arquivo\n");
        exit(EXIT_FAILURE);
    }

    l = constroiLabirinto(argv[optind]);

    while(!chegou(l)) {
        anda(l);
        if (usecs != 0) 
        {
            usleep(usecs);
            system("clear");
            lab = labirintoToString(l);
            puts(lab);
            free(lab);
        }
    }

    system("clear");
    puts(labirintoToString(l));

    /* printar as coordenadas do caminho */

    exit(0);
}
