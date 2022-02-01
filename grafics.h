#ifndef PROYECTO_GRAFICS_H
#define PROYECTO_GRAFICS_H

#include "LS_allegro.h"
#include "carregarFitxers.h"
#include "configuracioCotxe.h"
#include "sortedlist.h"
#include <time.h>
#include <stdio.h>

void graficaPanellConfig (Categoria *cat, PecaActual *peca_actual);
void graficaGPs (Info e, Pilot *pilot, PecaActual *peca_actual, Base base, Categoria *cat, Corredors *corr, FinalCursa *fc);
void graficaPosicio (int pos, Pilot pilot);
void graficaClassificacio (SortedListCarrera *list_carrera);
void graficaClassifiacioTemporada (SortedListTemporada *list_temp);

#endif //PROYECTO_GRAFICS_H
