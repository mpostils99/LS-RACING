#include <stdio.h>
#include "configuracioCotxe.h"
#include "sortedlist.h"
#include "carregarFitxers.h"
#include "menu.h"

int main (int argc, char *argv[]) {
    FILE *f, *g, *h, *l;
    int trobat = 0;
    int i = 0, quantitat = 0;
    Categoria *cat;
    SortedList list;
    Pilot pilot;
    Corredors *corr;
    Base base;
    Info info;
    PecaActual *peca_actual;

    if (argc != 5) {
        printf("Error. El programa ha de rebre 4 arguments\n");
    } else {
        f = fopen (argv[1], "r");
        g = fopen (argv[2], "r");
        h = fopen (argv[3], "rb");
        l = fopen (argv[4], "rb");

        if (f == NULL || g == NULL || h == NULL || l == NULL) {
            trobat = 1;
            printf ("Error. Hi ha hagut un error durant el processat dels fitxers.");
            fclose (f);
            fclose (g);
            fclose (h);
            fclose (l);
        }

        if (feof (f) || feof (g) || feof (h) || feof (l)) {
            trobat = 1;
            printf ("Error. Hi ha un fitxer buit.");
        }

        if (!trobat) {
            carregarFitxer1 (f, &cat);
            peca_actual = (PecaActual *) malloc (sizeof (PecaActual) * cat[0].num_categories);

            if (peca_actual == NULL) {
                printf ("Error del malloc.\n");
            } else {
                for (i = 0; i < cat[0].num_categories; i++) {
                    peca_actual[i].num_peca_actual = 0;
                    strcpy(peca_actual[i].nom_peca_actual, "\0");
                }

                list = SORTEDLIST_create ();
                quantitat = carregarFitxer2 (g, &list, &info);
                carregarFitxer3 (h, &corr);
                base = carregarFitxer4 (l);
                menu (&pilot, cat, peca_actual, quantitat, &list, info, base, corr);
            }
            free (cat);
            free (corr);
            free (peca_actual);
            SORTEDLIST_destroy (&list);
        }
    }
    return 0;
}