#ifndef PROYECTO_CARREGARFITXERS_H
#define PROYECTO_CARREGARFITXERS_H

#define LIST_NO_ERROR 0
#define LIST_ERROR_FULL 1			// Error, the list is full.
#define LIST_ERROR_EMPTY 2			// Error, the list is empty.
#define LIST_ERROR_MALLOC 3			// Error, a malloc failed.
#define LIST_ERROR_END 4			// Error, the POV is at the end.

#include <stdio.h>
#include <string.h>
#include "sortedlist.h"

typedef struct {
    char nom_peca[26];
    int velocitat;
    int acceleracio;
    int consum;
    int fiabilitat;
} Peces;

typedef struct {
    char nom_categoria[26];
    Peces *peces;
    int num_peces;
    int num_categories;
} Categoria;

typedef struct {
    char nom_pilot[26];
    int dorsal;
    char nom_escuderia[26];
    int velocitat;
    int acceleracio;
    int consum;
    int fiabilitat;
    int reflexes;
    int condicio_fisica;
    int temperament;
    int gestio_pneumatics;
} Corredors;

typedef struct {
    int velocitat;
    int acceleracio;
    int consum;
    int fiabilitat;
} Base;

typedef struct{
    int num_peca_actual;
    char nom_peca_actual[26];
} PecaActual;

void carregarFitxer1 (FILE *f, Categoria **cat);
int carregarFitxer2 (FILE *g, SortedList *list, Info *info);
void carregarFitxer3 (FILE *h, Corredors **corr);
Base carregarFitxer4 (FILE *l);

#endif //PROYECTO_CARREGARFITXERS_H
