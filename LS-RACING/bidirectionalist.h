#ifndef PROYECTO_BIDIRECTIONALIST_H
#define PROYECTO_BIDIRECTIONALIST_H

#include <stdlib.h>
#include "sortedlist.h"

#define LIST_NO_ERROR 0
#define LIST_ERROR_EMPTY 2			// Error, the list_carreres is empty.
#define LIST_ERROR_MALLOC 3			// Error, a malloc failed.
#define LIST_ERROR_END 4			// Error, the POI is at the tail.
#define LIST_ERROR_START 5			// Error, the POI is at the head.
#define LIST_ERROR_INVALID 6		// Error, the POI is on a phantom node.

typedef struct _Node {
    SortedListCarrera list_carrera;
    struct _Node * next;
    struct _Node * previous;
} NodeBL;

typedef struct {
    int error;
    NodeBL * head;
    NodeBL * tail;
    NodeBL * poi;
} BidirectionalListCarreres;

BidirectionalListCarreres BIDIRECTIONALLIST_create();
void	BIDIRECTIONALLIST_addBefore(BidirectionalListCarreres * list_carreres, SortedListCarrera list_carrera);
void	BIDIRECTIONALLIST_addAfter (BidirectionalListCarreres * list_carreres, SortedListCarrera list_carrera);
SortedListCarrera	BIDIRECTIONALLIST_get(BidirectionalListCarreres * list_carreres);
void	BIDIRECTIONALLIST_remove(BidirectionalListCarreres * list_carreres);
int		BIDIRECTIONALLIST_isEmpty(BidirectionalListCarreres list_carreres);
int 	BIDIRECTIONALLIST_isValid(BidirectionalListCarreres list_carreres);
void	BIDIRECTIONALLIST_goToHead(BidirectionalListCarreres * list_carreres);
void	BIDIRECTIONALLIST_next(BidirectionalListCarreres * list_carreres);
void	BIDIRECTIONALLIST_goToTail(BidirectionalListCarreres * list_carreres);
void	BIDIRECTIONALLIST_previous(BidirectionalListCarreres * list_carreres);
void 	BIDIRECTIONALLIST_destroy(BidirectionalListCarreres * list_carreres);
int		BIDIRECTIONALLIST_getErrorCode(BidirectionalListCarreres list_carreres);
int BIDIRECTIONALLIST_isAtEnd (BidirectionalListCarreres list_carreres);

#endif //PROYECTO_BIDIRECTIONALIST_H
