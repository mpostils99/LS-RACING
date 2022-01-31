#ifndef PROYECTO_CONFIGURACIOCOTXE_H
#define PROYECTO_CONFIGURACIOCOTXE_H

#include <stdio.h>
#include <string.h>

typedef struct {
    char nomPilot[26];
    char nomEscuderia[26];
    int dorsal;
    int reflexes;
    int condicioFisica;
    int temperament;
    int gestioPneumatics;
} Pilot;

void configuracioCotxe (Pilot *pilot);

#endif //PROYECTO_CONFIGURACIOCOTXE_H
