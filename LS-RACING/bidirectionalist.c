/***********************************************
*
* @Propòsit: Tenir ja implementades les diferents funcionalitats de la bidireccionallist.
* @Autor/s: Marc Postils i Narcís Cisquella.
* @Data de creació: 15/05/20
* @Data de l’última modificació: 04/07/20
*
************************************************/

#include "bidirectionalist.h"

BidirectionalListCarreres BIDIRECTIONALLIST_create () {
    BidirectionalListCarreres list_carreres;

    list_carreres.head = NULL;
    // First phantom NodeBL creation
    list_carreres.head = (NodeBL*) malloc (sizeof (NodeBL));
    if (list_carreres.head != NULL) {
        list_carreres.tail = NULL;

        list_carreres.tail = (NodeBL*) malloc (sizeof (NodeBL));
        if (list_carreres.tail == NULL) {
            free(list_carreres.head);

            list_carreres.head = NULL;
            list_carreres.error = LIST_ERROR_MALLOC;
        }
        else {
            list_carreres.error = LIST_NO_ERROR;

            list_carreres.head->next = list_carreres.tail;
            list_carreres.head->previous = NULL;
            list_carreres.tail->next = NULL;
            list_carreres.tail->previous = list_carreres.head;
            list_carreres.poi = list_carreres.head;
        }
    }
    else {
        list_carreres.head = NULL;
        list_carreres.tail = NULL;
        list_carreres.poi  = NULL;
        list_carreres.error = LIST_ERROR_MALLOC;
    }

    return list_carreres;
}

void BIDIRECTIONALLIST_addBefore(BidirectionalListCarreres * list_carreres, SortedListCarrera list_carrera) {
    NodeBL * new_node = NULL;

    if (list_carreres->poi == list_carreres->head) {
        list_carreres->error = LIST_ERROR_INVALID;
    }
    else {
        new_node = (NodeBL*) malloc (sizeof (NodeBL));
        if (NULL == new_node) {
            list_carreres->error = LIST_ERROR_MALLOC;
        }
        else {
            list_carreres->error = LIST_NO_ERROR;

            new_node->list_carrera = list_carrera;
            new_node->next = list_carreres->poi;
            new_node->previous = list_carreres->poi->previous;

            list_carreres->poi->previous->next = new_node;
            list_carreres->poi->previous = new_node;
        }
    }
}

void BIDIRECTIONALLIST_addAfter (BidirectionalListCarreres * list_carreres,SortedListCarrera list_carrera) {
    NodeBL * new_node = NULL;

    if (list_carreres->poi == list_carreres->tail) {
        list_carreres->error = LIST_ERROR_INVALID;
    }
    else {
        new_node = (NodeBL*) malloc (sizeof (NodeBL));
        if (NULL == new_node) {
            list_carreres->error = LIST_ERROR_MALLOC;
        }
        else {
            list_carreres->error = LIST_NO_ERROR;

            new_node->list_carrera = list_carrera;
            new_node->next = list_carreres->poi->next;
            new_node->previous = list_carreres->poi;

            list_carreres->poi->next->previous = new_node;
            list_carreres->poi->next = new_node;
        }
    }
}

SortedListCarrera BIDIRECTIONALLIST_get(BidirectionalListCarreres * list_carreres) {
   SortedListCarrera list_carrera;

    if (BIDIRECTIONALLIST_isEmpty(*list_carreres)) {
        list_carreres->error = LIST_ERROR_EMPTY;
    } else {
        if (!BIDIRECTIONALLIST_isValid(*list_carreres))	{
            list_carreres->error = LIST_ERROR_INVALID;
        }
        else {
            list_carreres->error = LIST_NO_ERROR;
           list_carrera = list_carreres->poi->list_carrera;
        }
    }

    return list_carrera;
}

void BIDIRECTIONALLIST_remove(BidirectionalListCarreres * list_carreres) {
    NodeBL * aux = NULL;

    if (BIDIRECTIONALLIST_isEmpty(*list_carreres)) {
        list_carreres->error = LIST_ERROR_EMPTY;
    } else {
        if (!BIDIRECTIONALLIST_isValid(*list_carreres))	{
            list_carreres->error = LIST_ERROR_INVALID;
        }
        else {
            aux = list_carreres->poi;

            list_carreres->poi->previous->next = list_carreres->poi->next;
            list_carreres->poi->next->previous = list_carreres->poi->previous;

            list_carreres->poi = list_carreres->poi->next;
            free(aux);
        }
    }
}


int	BIDIRECTIONALLIST_isEmpty(BidirectionalListCarreres list_carreres) {
    return list_carreres.head->next == list_carreres.tail;
}


int BIDIRECTIONALLIST_isValid(BidirectionalListCarreres list_carreres) {
    return list_carreres.poi != list_carreres.head && list_carreres.poi != list_carreres.tail;
}

void BIDIRECTIONALLIST_goToHead(BidirectionalListCarreres * list_carreres) {
    list_carreres->poi = list_carreres->head->next;
}

void BIDIRECTIONALLIST_next(BidirectionalListCarreres * list_carreres) {
    if (list_carreres->poi == list_carreres->tail) {
        list_carreres->error = LIST_ERROR_END;
    }
    else {
        list_carreres->poi = list_carreres->poi->next;
    }
}

void BIDIRECTIONALLIST_goToTail(BidirectionalListCarreres * list_carreres) {
    list_carreres->poi = list_carreres->tail->previous;
}

void BIDIRECTIONALLIST_previous(BidirectionalListCarreres * list_carreres) {
    if (list_carreres->poi == list_carreres->head) {
        list_carreres->error = LIST_ERROR_START;
    }
    else {
        list_carreres->poi = list_carreres->poi->previous;
    }
}

void BIDIRECTIONALLIST_destroy(BidirectionalListCarreres * list_carreres) {
    while (list_carreres->head != NULL) {
        list_carreres->poi = list_carreres->head;
        list_carreres->head = list_carreres->head->next;
        free(list_carreres->poi);
    }
    list_carreres->tail = NULL;
    list_carreres->poi = NULL;
}

int BIDIRECTIONALLIST_isAtEnd (BidirectionalListCarreres list_carreres) {
    if (list_carreres.poi != list_carreres.tail) {
        return 0;
    } else {
        return 1;
    }
}
