#ifndef PROYECTO_SORTEDLIST_H
#define PROYECTO_SORTEDLIST_H

#include <stdio.h>
#include <stdlib.h>

#define LIST_NO_ERROR 0
#define LIST_ERROR_FULL 1			// Error, the list is full.
#define LIST_ERROR_EMPTY 2			// Error, the list is empty.
#define LIST_ERROR_MALLOC 3			// Error, a malloc failed.
#define LIST_ERROR_END 4			// Error, the POV is at the end.
#define NUM_PILOTS 8

typedef struct {
    int posicio;
    char nom[26];
    int velocitat;
    int acceleracio;
    int consum;
    int fiabilitat;
    float t_base;
    float t_pitstop;
    int n_pitstop;
} Info;

typedef struct n {
    Info info;
    struct n *next;
} Node;

typedef struct {
    int error;
    Node *head;
    Node *previous;
} SortedList;

typedef struct {
    int temps;
    int punts;
    int num_dorsal;
    int num_Gp;
    int num_pilot;
    char nom_pilot[26];
    char nom_GP[26];
} FinalCursa;

typedef struct n2 {
    FinalCursa fc;
    struct n2 *next;
} Node2;

typedef struct {
    int error;
    Node2 *head;
    Node2 *previous;
} SortedListCarrera;

typedef struct {
    int punts;
    int num_dorsal;
    int num_pilot;
    char nom_pilot[26];
} FinalTemporada;

typedef struct n_temporada {
    FinalTemporada ft;
    struct n_temporada *next;
} NodeTemporada;

typedef struct {
    int error;
    NodeTemporada *head;
    NodeTemporada *previous;
} SortedListTemporada;

SortedList SORTEDLIST_create ();
void LINKEDLIST_add (SortedList * list, Info *info);
void SORTEDLIST_sortedAdd (SortedList * list, Info *info);
void SORTEDLIST_remove (SortedList * list);
Info SORTEDLIST_get (SortedList * list);
int SORTEDLIST_isEmpty (SortedList list);
void 	SORTEDLIST_goToHead (SortedList * list);
void 	SORTEDLIST_next (SortedList * list);
int 	SORTEDLIST_isAtEnd (SortedList list);
void 	SORTEDLIST_destroy (SortedList * list);
int		SORTEDLIST_getErrorCode (SortedList list);

SortedListCarrera SLCarrera_create ();
void LINKEDLISTCarrera_add (SortedListCarrera * list_carrera, FinalCursa fc);
void SLCarrera_sortedAdd (SortedListCarrera * list_carrera, FinalCursa fc);
int SLCarrera_findPosition (SortedListCarrera *list_carrera, FinalCursa fc);
void SLCarrera_remove (SortedListCarrera * list_carrera);
FinalCursa SLCarrera_get (SortedListCarrera * list_carrera);
int SLCarrera_isEmpty (SortedListCarrera list_carrera);
void 	SLCarrera_goToHead (SortedListCarrera * list_carrera);
void 	SLCarrera_next (SortedListCarrera * list_carrera);
int 	SLCarrera_isAtEnd (SortedListCarrera list_carrera);
void 	SLCarrera_destroy (SortedListCarrera * list_carrera);
int		SLCarrera_getErrorCode (SortedListCarrera list_carrera);

SortedListTemporada SLTemporada_create ();
void LINKEDLISTTemporada_add (SortedListTemporada * list_temporada, FinalTemporada final_temp);
void SLTemporada_sortedAdd (SortedListTemporada * list_temporada, FinalTemporada final_temp);
int SLTemporada_findPosition (SortedListTemporada *list_temporada, FinalCursa fc);
void SLTemporada_remove (SortedListTemporada * list_temporada);
FinalTemporada SLTemporada_get (SortedListTemporada * list_temporada);
int SLTemporada_isEmpty (SortedListTemporada list_temporada);
void 	SLTemporada_goToHead (SortedListTemporada * list_temporada);
void 	SLTemporada_next (SortedListTemporada * list_temporada);
int 	SLTemporada_isAtEnd (SortedListTemporada list_temporada);
void 	SLTemporada_destroy (SortedListTemporada * list_temporada);
int		SLTemporada_getErrorCode (SortedListTemporada list_temporada);

#endif //PROYECTO_SORTEDLIST_H
