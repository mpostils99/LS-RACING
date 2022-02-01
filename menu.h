#ifndef PROYECTO_MENU_H
#define PROYECTO_MENU_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "configuracioCotxe.h"
#include "carregarFitxers.h"
#include "grafics.h"
#include "sortedlist.h"
#include "LS_allegro.h"

void menu (Pilot *pilot, Categoria *cat, PecaActual *peca_actual, int quantitat, SortedList *list, Info info, Base base, Corredors *corr);

#endif //PROYECTO_MENU_H
