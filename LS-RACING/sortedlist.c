/***********************************************
*
* @Propòsit: Tenir ja implementades les diferents funcionalitats de la sortedlist.
* @Autor/s: Marc Postils i Narcís Cisquella
* @Data de creació: 25/04/20
* @Data de l’última modificació: 30/06/20
*
************************************************/

#include "sortedlist.h"

/****************************************************************************
 *
 * @Finalitat: crear una llista ordenada buida.
 * @Paràmetres: ---
 * @Retorn: retorna la llista ordenada buida.
 *
 ****************************************************************************/
SortedList SORTEDLIST_create () {
    SortedList list;

    list.head = (Node*) malloc (sizeof (Node));
    if (NULL != list.head) {
        list.head->next = NULL;
        list.previous = list.head;
        list.error = LIST_NO_ERROR;
    }
    else {
        list.error = LIST_ERROR_MALLOC;
    }

    return list;
}

/****************************************************************************
 *
 * @Finalitat: afegir a la llista ordenada l'element, en aquesta cas info, que es on es troba la informació de cada GP.
 * @Paràmetres: (in/out) list = llista ordenada on afegim l'element info.
 *				(in) info = l'element que afegim a la llista ordenada.
 * @Retorn: ---
 *
 ****************************************************************************/
void LINKEDLIST_add (SortedList * list, Info *info) {
    Node *new_node = (Node*) malloc (sizeof (Node));
    if (new_node != NULL) {
        new_node->info = *info;
        new_node->next = list->previous->next;
        list->previous->next = new_node;
        list->previous = new_node;
    }
}

/****************************************************************************
 *
 * @Finalitat: afegir l'elemt info a la llista ordenada i ordenar-la segons la posició en el calendari.
 * @Paràmetres: (in/out) list = llista ordenada on afegim l'element info.
 *				(in) info = l'element que afegim a la llista ordenada.
 * @Retorn: ---
 *
 ****************************************************************************/
void SORTEDLIST_sortedAdd (SortedList *list, Info *info) {
    int trobat = 0;
    Info pos;

    SORTEDLIST_goToHead(list);
    while (!SORTEDLIST_isAtEnd(*list) && !trobat) {
        pos = SORTEDLIST_get(list);
        if (info->posicio > pos.posicio) {
            SORTEDLIST_next(list);
        }
        else {
            trobat = 1;
        }
    }
    LINKEDLIST_add(list, info);
}

/****************************************************************************
 *
 * @Finalitat: eliminar l'element que es trobi al pov.
 * @Paràmetres: (in/out) list = llista ordenada on eliminarem l'element info.
 * @Retorn: ---
 *
 ****************************************************************************/
void SORTEDLIST_remove (SortedList * list) {
    Node *aux = NULL;
    if (SORTEDLIST_isAtEnd (*list)) {
        list->error = LIST_ERROR_END;
    }
    else {
        aux = list->previous->next;
        list->previous->next = list->previous->next->next;
        free (aux);
        list->error = LIST_NO_ERROR;
    }
}

/****************************************************************************
 *
 * @Finalitat: obtenir l'element que es trobi en el pov.
 * @Paràmetres: (in/out) list = llista ordenada d'on extreurem l'element.
 * @Retorn: retorna l'element que es troba en el pov.
 *
 ****************************************************************************/
Info SORTEDLIST_get (SortedList *list) {
    Info element;

    if (SORTEDLIST_isAtEnd (*list)) {
        list->error = LIST_ERROR_END;
    }
    else {
        element = list->previous->next->info;
        list->error = LIST_NO_ERROR;
    }

    return element;
}

/****************************************************************************
 *
 * @Objective: saber si la llista ordenada està buida o no.
 * @Parameters: (in) list = llista ordenada on mirarem si conté algun element.
 * @Return: retorna cert si la llista ordenada està buida.
 *
 ****************************************************************************/
int SORTEDLIST_isEmpty (SortedList list) {
    return NULL == list.head->next;
}

/****************************************************************************
 *
 * @Finalitat: moure el pov al primer element de la llista.
 * @Paràmetres: (in/out) list = llista ordenada on moure el pov al inici.
 * @Retorn: ---
 *
 ****************************************************************************/
void SORTEDLIST_goToHead (SortedList * list) {
    list->previous = list->head;
}

/****************************************************************************
 *
 * @Finalitat: moure el pov al següent element de la llista ordenada.
 *
 * @Paràmetres: (in/out) list = llista ordenada per moure el pov.
 * @Retorn: ---
 *
 ****************************************************************************/
void SORTEDLIST_next (SortedList *list) {
    if (SORTEDLIST_isAtEnd (*list)) {
        list->error = LIST_ERROR_END;
    }
    else {
        list->previous = list->previous->next;
        list->error = LIST_NO_ERROR;
    }
}

/****************************************************************************
 *
 * @Finalitat: saber si el pov està situat després de l'últim element.
 * @Paràmetres: (in) list = llista ordenada per comprovar si està al final.
 * @Retorn: retorna cert si el pov està després de l'últim element de la llista ordenada.
 *
 ****************************************************************************/
int SORTEDLIST_isAtEnd (SortedList list) {
    return NULL == list.previous->next;
}

/****************************************************************************
 *
 * @Finalitat: eliminar tots els elements de la llista i allibera la memòria dinàmica.
 * @Paràmetres: (in/out) list = llista ordenada que destruïm.
 * @Retorn: ---
 *
 ****************************************************************************/
void SORTEDLIST_destroy (SortedList * list) {
    Node * aux;
    while (NULL != list->head) {
        aux = list->head;
        list->head = list->head->next;
        free (aux);
    }
    list->head = NULL;
    list->previous = NULL;
}

/****************************************************************************
 *
 * @Finalitat: saber si s'ha produït algun tipus d'error durant el procés.
 * @Paràmetres: (in) list = llista ordenada on comprovem si hi ha hagut algun error.
 * @Retorn: retorna un codi d'error de la llista de constants definides.
 *
 ****************************************************************************/
int	SORTEDLIST_getErrorCode (SortedList list) {
    return list.error;
}

/****************************************************************************
 *
 * @Finalitat: crear una llista ordenada buida.
 * @Paràmetres: ---
 * @Retorn: retorna la llista ordenada buida.
 *
 ****************************************************************************/
SortedListCarrera SLCarrera_create () {
    SortedListCarrera list_carrera;

    list_carrera.head = (Node2*) malloc (sizeof (Node2));
    if (NULL != list_carrera.head) {
        list_carrera.head->next = NULL;
        list_carrera.previous = list_carrera.head;
        list_carrera.error = LIST_NO_ERROR;
    }
    else {
        list_carrera.error = LIST_ERROR_MALLOC;
    }

    return list_carrera;
}

/****************************************************************************
 *
 * @Finalitat: afegir a la llista ordenada l'element, en aquesta cas info, que es on es troba la informació de cada GP.
 * @Paràmetres: (in/out) list = llista ordenada on afegim l'element info.
 *				(in) info = l'element que afegim a la llista ordenada.
 * @Retorn: ---
 *
 ****************************************************************************/
void LINKEDLISTCarrera_add (SortedListCarrera * list_carrera, FinalCursa fc) {
    Node2 *new_node = (Node2*) malloc (sizeof (Node2));
    if (new_node != NULL) {
        new_node->fc = fc;
        new_node->next = list_carrera->previous->next;
        list_carrera->previous->next = new_node;
        list_carrera->previous = new_node;
    }
}

/****************************************************************************
 *
 * @Finalitat: afegir l'elemt info a la llista ordenada i ordenar-la segons la posició en el calendari.
 * @Paràmetres: (in/out) list = llista ordenada on afegim l'element info.
 *				(in) info = l'element que afegim a la llista ordenada.
 * @Retorn: ---
 *
 ****************************************************************************/
void SLCarrera_sortedAdd (SortedListCarrera *list_carrera, FinalCursa fc) {
    int trobat = 0;
    FinalCursa temp;

    SLCarrera_goToHead(list_carrera);
    while (!SLCarrera_isAtEnd(*list_carrera) && !trobat) {
        temp = SLCarrera_get(list_carrera);
        if (fc.temps >= temp.temps) {
            SLCarrera_next(list_carrera);
        }
        else {
            trobat = 1;
        }
    }
    LINKEDLISTCarrera_add (list_carrera, fc);
}

int SLCarrera_findPosition (SortedListCarrera *list_carrera, FinalCursa fc) {
    int pos = 1;
    FinalCursa temp;

    SLCarrera_goToHead(list_carrera);
    while (!SLCarrera_isAtEnd(*list_carrera)) {
        temp = SLCarrera_get(list_carrera);
        if (temp.num_pilot == 0) {  //fc.num_pilot == temp.num_pilot
            return pos;
        }
        SLCarrera_next(list_carrera);
        pos++;
    }
    return -1;
}

/****************************************************************************
 *
 * @Finalitat: eliminar l'element que es trobi al pov.
 * @Paràmetres: (in/out) list = llista ordenada on eliminarem l'element info.
 * @Retorn: ---
 *
 ****************************************************************************/
void SLCarrera_remove (SortedListCarrera *list_carrera) {
    Node2 *aux = NULL;
    if (SLCarrera_isAtEnd(*list_carrera)) {
        list_carrera->error = LIST_ERROR_END;
    }
    else {
        aux = list_carrera->previous->next;
        list_carrera->previous->next = list_carrera->previous->next->next;
        free (aux);
        list_carrera->error = LIST_NO_ERROR;
    }
}

/****************************************************************************
 *
 * @Finalitat: obtenir l'element que es trobi en el pov.
 * @Paràmetres: (in/out) list = llista ordenada d'on extreurem l'element.
 * @Retorn: retorna l'element que es troba en el pov.
 *
 ****************************************************************************/
FinalCursa SLCarrera_get (SortedListCarrera *list_carrera) {
     FinalCursa element;

    if (SLCarrera_isAtEnd(*list_carrera)) {
        list_carrera->error = LIST_ERROR_END;
    }
    else {
        element = list_carrera->previous->next->fc;
        list_carrera->error = LIST_NO_ERROR;
    }

    return element;
}

/****************************************************************************
 *
 * @Objective: saber si la llista ordenada està buida o no.
 * @Parameters: (in) list = llista ordenada on mirarem si conté algun element.
 * @Return: retorna cert si la llista ordenada està buida.
 *
 ****************************************************************************/
int SLCarrera_isEmpty (SortedListCarrera list_carrera) {
    return NULL == list_carrera.head->next;
}

/****************************************************************************
 *
 * @Finalitat: moure el pov al primer element de la llista.
 * @Paràmetres: (in/out) list = llista ordenada on moure el pov al inici.
 * @Retorn: ---
 *
 ****************************************************************************/
void SLCarrera_goToHead (SortedListCarrera *list_carrera) {
    list_carrera->previous = list_carrera->head;
}

/****************************************************************************
 *
 * @Finalitat: moure el pov al següent element de la llista ordenada.
 *
 * @Paràmetres: (in/out) list = llista ordenada per moure el pov.
 * @Retorn: ---
 *
 ****************************************************************************/
void SLCarrera_next (SortedListCarrera *list_carrera) {
    if (SLCarrera_isAtEnd(*list_carrera)) {
        list_carrera->error = LIST_ERROR_END;
    }
    else {
        list_carrera->previous = list_carrera->previous->next;
        list_carrera->error = LIST_NO_ERROR;
    }
}

/****************************************************************************
 *
 * @Finalitat: saber si el pov està situat després de l'últim element.
 * @Paràmetres: (in) list = llista ordenada per comprovar si està al final.
 * @Retorn: retorna cert si el pov està després de l'últim element de la llista ordenada.
 *
 ****************************************************************************/
int SLCarrera_isAtEnd (SortedListCarrera list_carrera) {
    return NULL == list_carrera.previous->next;
}

/****************************************************************************
 *
 * @Finalitat: eliminar tots els elements de la llista i allibera la memòria dinàmica.
 * @Paràmetres: (in/out) list = llista ordenada que destruïm.
 * @Retorn: ---
 *
 ****************************************************************************/
void SLCarrera_destroy (SortedListCarrera * list_carrera) {
    Node2 *aux;
    while (NULL != list_carrera->head) {
        aux = list_carrera->head;
        list_carrera->head = list_carrera->head->next;
        free (aux);
    }
    list_carrera->head = NULL;
    list_carrera->previous = NULL;
}

/****************************************************************************
 *
 * @Finalitat: saber si s'ha produït algun tipus d'error durant el procés.
 * @Paràmetres: (in) list = llista ordenada on comprovem si hi ha hagut algun error.
 * @Retorn: retorna un codi d'error de la llista de constants definides.
 *
 ****************************************************************************/
int	SLCarrera_getErrorCode (SortedListCarrera list_carrera) {
    return list_carrera.error;
}

SortedListTemporada SLTemporada_create () {
    SortedListTemporada list_temporada;

    list_temporada.head = (NodeTemporada*) malloc (sizeof (NodeTemporada));
    if (NULL != list_temporada.head) {
        list_temporada.head->next = NULL;
        list_temporada.previous = list_temporada.head;
        list_temporada.error = LIST_NO_ERROR;
    }
    else {
        list_temporada.error = LIST_ERROR_MALLOC;
    }

    return list_temporada;
}

void LINKEDLISTTemporada_add (SortedListTemporada *list_temporada, FinalTemporada ft) {
    NodeTemporada *new_node = (NodeTemporada*) malloc (sizeof (NodeTemporada));
    if (new_node != NULL) {
        new_node->ft = ft;
        new_node->next = list_temporada->previous->next;
        list_temporada->previous->next = new_node;
        list_temporada->previous = new_node;
    }
}

void SLTemporada_sortedAdd (SortedListTemporada *list_temporada, FinalTemporada ft) {
    int trobat = 0;
    FinalTemporada punt;

    SLTemporada_goToHead(list_temporada);
    while (!SLTemporada_isAtEnd(*list_temporada) && !trobat) {
        punt = SLTemporada_get(list_temporada);
        if (ft.punts < punt.punts) {
            SLTemporada_next(list_temporada);
        }
        else {
            trobat = 1;
        }
    }
    LINKEDLISTTemporada_add (list_temporada, ft);
}

void SLTemporada_remove (SortedListTemporada *list_temporada) {
    NodeTemporada *aux = NULL;
    if (SLTemporada_isAtEnd(*list_temporada)) {
        list_temporada->error = LIST_ERROR_END;
    }
    else {
        aux = list_temporada->previous->next;
        list_temporada->previous->next = list_temporada->previous->next->next;
        free (aux);
        list_temporada->error = LIST_NO_ERROR;
    }
}

FinalTemporada SLTemporada_get (SortedListTemporada *list_temporada) {
    FinalTemporada element;

    if (SLTemporada_isAtEnd(*list_temporada)) {
        list_temporada->error = LIST_ERROR_END;
    }
    else {
        element = list_temporada->previous->next->ft;
        list_temporada->error = LIST_NO_ERROR;
    }

    return element;
}

void SLTemporada_goToHead (SortedListTemporada *list_temporada) {
    list_temporada->previous = list_temporada->head;
}

void SLTemporada_next (SortedListTemporada *list_temporada) {
    if (SLTemporada_isAtEnd(*list_temporada)) {
        list_temporada->error = LIST_ERROR_END;
    }
    else {
        list_temporada->previous = list_temporada->previous->next;
        list_temporada->error = LIST_NO_ERROR;
    }
}

int SLTemporada_isAtEnd (SortedListTemporada list_temporada) {
    return NULL == list_temporada.previous->next;
}

void SLTemporada_destroy (SortedListTemporada * list_temporada) {
    NodeTemporada *aux;
    while (NULL != list_temporada->head) {
        aux = list_temporada->head;
        list_temporada->head = list_temporada->head->next;
        free (aux);
    }
    list_temporada->head = NULL;
    list_temporada->previous = NULL;
}


