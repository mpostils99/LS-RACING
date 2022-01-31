/***********************************************
*
* @Propòsit: classificar el menú en un mateix modul on apareixen les quatre diferents opcions.
* @Autor/s: Marc Postils i Narcís Cisquella.
* @Data de creació: 20/04/20
* @Data de l’última modificació: 03/07/20
*
************************************************/

#include "menu.h"
#include "bidirectionalist.h"

/****************************************************************************
 *
 * @Finalitat: Implementar la opcio 2 en aquest procediment per a que sigui més entendible.
 * @Paràmetres: in: quantitat = enter extret del fitxer de GPs que ens indica el número de GPs que hi ha.
 *              in: list = llista ordenada on tenimla informació dels GPs del fitxer de GPs.
 *              in: pilot = estructura on tenim la informació del nostre pilot.
 *              in: peca_actual = estrucutura on tenim el nom i el número de la peça que tinguem a la configuracio actual.
 *              in: base = estructura on tenim la informació base dels cotxes del últim fitxer.
 *              in: cat = estructura on tenim la informació de les categories i peces del fitxer de peces.
 *              in: corr = estructura on tenim la informació dels corredors del fitxer de corredors.
 *              in: num_GP = enter que indica el número de GP.
 *              in: list_carreres = llista bidireccional on guardarem la classificacio final de cada GP.
 * @Retorn: ----
 *
 ****************************************************************************/
void opcio2 (int quantitat, SortedList *list, Pilot *pilot, PecaActual *peca_actual, Base base, Categoria *cat,
             Corredors *corr, int *num_GP, BidirectionalListCarreres *list_carreres) {
    int i = 0, pos = 0;
    Info e;
    int punts[NUM_PILOTS] = {25, 18, 15, 10, 8, 6, 5, 3};
    SortedListCarrera list_carrera;
    FinalCursa *fc;
    FinalCursa aux, copy;

    fc = (FinalCursa *) malloc(sizeof (FinalCursa) * NUM_PILOTS);
    if (fc == NULL) {
        printf ("Error del malloc.\n");
    } else {
        while (i < NUM_PILOTS) {
            fc[i].punts = 0;
            i++;
        }
        if (*num_GP < quantitat) {
            e = SORTEDLIST_get (list);
            list_carrera = SLCarrera_create ();
            graficaGPs (e, pilot, peca_actual, base, cat, corr, fc);
            i = 0;

            while (i < NUM_PILOTS) {
                fc[i].num_Gp = *num_GP;
                strcpy (fc[i].nom_GP, e.nom);
                SLCarrera_sortedAdd (&list_carrera, fc[i]);
                i++;
            }
            i = 0;
            SLCarrera_goToHead (&list_carrera);

            while (i < NUM_PILOTS) {
                aux = SLCarrera_get (&list_carrera);
                copy.punts = punts[i];
                copy.num_dorsal = aux.num_dorsal;
                copy.num_pilot = aux.num_pilot;
                copy.temps = aux.temps;
                copy.num_Gp = aux.num_Gp;
                strcpy (copy.nom_pilot, aux.nom_pilot);
                strcpy (copy.nom_GP, aux.nom_GP);
                fc[i] = copy;
                i++;
                SLCarrera_next (&list_carrera);
            }
            i = 0;
            SLCarrera_destroy (&list_carrera);
            list_carrera = SLCarrera_create ();

            while (i < NUM_PILOTS) {
                SLCarrera_sortedAdd(&list_carrera, fc[i]);
                i++;
            }

            pos = SLCarrera_findPosition (&list_carrera, fc[0]);
            graficaPosicio (pos, *pilot);
            BIDIRECTIONALLIST_goToTail (list_carreres);
            BIDIRECTIONALLIST_addAfter (list_carreres, list_carrera);
            *num_GP = *num_GP + 1;
            SORTEDLIST_next (list);
        } else {
            printf ("\nJa has finalitzat la temporada.\n\n");
        }
    }
    free (fc);
}

/****************************************************************************
 *
 * @Finalitat: sumar el punts de cada GPs i guardar-los a la llista de temporada junt amb el dorsal i nom pilot per després mostrar-los.
 * @Paràmetres: in: list_carreres = llista bidireccional on tenim guardades la classificació final de cada GP.
 *              in: num_GP = enter que indica el número de GP.
 * @Retorn: retorna la list_temporada que es la llista ordenada per punts de la classificació de la temporada.
 *
 ****************************************************************************/
SortedListTemporada obtenirTemporada (BidirectionalListCarreres *list_carreres, int num_GP) {
    SortedListTemporada list_temporada;
    SortedListCarrera list_carrera;
    list_temporada = SLTemporada_create ();
    FinalTemporada final_temp[NUM_PILOTS];
    FinalCursa ficur;
    int i = 0, j = 0;

    while (i < NUM_PILOTS) {
        final_temp[i].punts = 0;
        final_temp[i].num_pilot = i;
        i++;
    }

    i = 0;
    BIDIRECTIONALLIST_goToHead (list_carreres);
    while (i < num_GP && !BIDIRECTIONALLIST_isAtEnd (*list_carreres)) {
        list_carrera = BIDIRECTIONALLIST_get (list_carreres);
        SLCarrera_goToHead (&list_carrera);
        j = 0;
        while (j < NUM_PILOTS && !SLCarrera_isAtEnd (list_carrera)) {
            ficur = SLCarrera_get (&list_carrera);
            j++;
            final_temp[ficur.num_pilot].punts = final_temp[ficur.num_pilot].punts + ficur.punts;
            final_temp[ficur.num_pilot].num_dorsal = ficur.num_dorsal;
            strcpy (final_temp[ficur.num_pilot].nom_pilot, ficur.nom_pilot);
            SLCarrera_next (&list_carrera);
        }
        i++;
        BIDIRECTIONALLIST_next (list_carreres);
    }
    i = 0;
    while (i < NUM_PILOTS) {
        SLTemporada_sortedAdd (&list_temporada, final_temp[i]);
        i++;
    }

    return list_temporada;
}

/****************************************************************************
 *
 * @Finalitat: implementar i mostrar la pantalla gràfica de la classificació de cada cursa i si s'ha acabat el GP doncs de la temporada també
 *              i afegir funcionalitats a les lletres A i D.
 * @Paràmetres: in: list_carreres = llista bidireccional on tenim guardades la classificació final de cada GP.
 *              in: num_GP = enter que indica el número de GP.
 *              in: quantitat = enter extret del fitxer de GPs que ens indica el número de GPs que hi ha.
 * @Retorn: ----
 *
 ****************************************************************************/
void opcio3 (BidirectionalListCarreres *list_carreres, int num_GP, int quantitat) {
    int i_GP = 0, temporada = 0, nSortir = 0, key_D = 0;
    SortedListCarrera list_carrera;
    SortedListTemporada list_temporada;
    BIDIRECTIONALLIST_goToHead (list_carreres);

    while (i_GP < num_GP - 1) {
        BIDIRECTIONALLIST_next(list_carreres);
        //printf ("numgp: %d\n", num_GP);
        i_GP++;
    }

    list_carrera = BIDIRECTIONALLIST_get (list_carreres);

    //Inicialitzem Allegro
    LS_allegro_init (1350, 625, "Proyecto");

    while (!nSortir) {
        if (LS_allegro_key_pressed (ALLEGRO_KEY_ESCAPE)) {
            nSortir = 1;
        }

        if (temporada == 1) {
            graficaClassifiacioTemporada (&list_temporada);
        } else {
            graficaClassificacio (&list_carrera);
        }

        if (LS_allegro_key_pressed (ALLEGRO_KEY_D)) {
            key_D = 1;
        }

        if (key_D && (i_GP < num_GP - 1 || (i_GP < num_GP && num_GP == quantitat))) {
            BIDIRECTIONALLIST_next (list_carreres);
            i_GP++;
            list_carrera = BIDIRECTIONALLIST_get (list_carreres);
            temporada = 0;
        }

        if (LS_allegro_key_pressed (ALLEGRO_KEY_A) && i_GP > 0) {
            BIDIRECTIONALLIST_previous (list_carreres);
            i_GP--;
            list_carrera = BIDIRECTIONALLIST_get (list_carreres);
            temporada = 0;
        }

        if (key_D && i_GP == quantitat) { //fitxer de GP està
            list_temporada = obtenirTemporada(list_carreres, num_GP);
            temporada = 1;
        }

        key_D = 0;
    }

    //Tanquem la finestra grafica
    LS_allegro_exit();
}

/****************************************************************************
 *
 * @Finalitat: Crear un fitxer d'escriptura i escriure la classificació de cada GP.
 * @Paràmetres: in: p = fitxer on escriurem tota la informació.
 *              in: list_carreres = llista bidireccional on tenim guardades la classificació final de cada GP.
 *              in: num_GP = enter que indica el número de GP.
 *              in: quantitat = enter que indica la quantital de GPs existents.
 * @Retorn: ----
 *
 ****************************************************************************/
void opcio4 (FILE *p, BidirectionalListCarreres *list_carreres, int num_GP, int quantitat) {
    SortedListCarrera list_carrera;
    SortedListTemporada list_temporada;
    FinalCursa e;
    FinalTemporada t;
    int i = 0, j = 0, k = 0;

    BIDIRECTIONALLIST_goToHead (list_carreres);
    while (i < num_GP && !BIDIRECTIONALLIST_isAtEnd (*list_carreres)) {
        list_carrera = BIDIRECTIONALLIST_get (list_carreres);
        SLCarrera_goToHead (&list_carrera);
        e = SLCarrera_get (&list_carrera);
        fprintf (p, "Classificacio del %s\n", e.nom_GP);
        j = 0;
        while (j < NUM_PILOTS && !SLCarrera_isAtEnd (list_carrera)) {
            fprintf (p, "%d. %s amb %d segons. Punts: %d\n", j + 1, e.nom_pilot, e.temps, e.punts);
            j++;
            k = 0;
            if (k < NUM_PILOTS) {
                SLCarrera_next (&list_carrera);
                e = SLCarrera_get (&list_carrera);
                k++;
            }
        }
        i++;
        BIDIRECTIONALLIST_next (list_carreres);

        if (i == quantitat) {
            list_temporada = obtenirTemporada (list_carreres, num_GP);
            SLTemporada_goToHead (&list_temporada);
            j = 0;
            fprintf (p, "Classificacio Final de Temporada\n");
            while (j < NUM_PILOTS) {
                t = SLTemporada_get (&list_temporada);
                fprintf (p, "%d. %s amb dorsal %d. Punts: %d\n", j + 1, t.nom_pilot, t.num_dorsal, t.punts);
                j++;
                SLTemporada_next (&list_temporada);
            }
        }
    }
    fclose (p);
}

/***********************************************
*
* @Finalitat: Mostrar per pantalla el menú amb les diferents opcions.
* @Paràmetres: in: pilot = estructura on més endavant guardarem la informacio que introdueix l'usuari per pantalla.
 *             in: cat = estructura on guardarem la informació del fitxer de peces.
 *             in: peca_actual = estrucutura on guardarem el nom i el número de la peça que tinguem a la configuracio actual.
 *             in: quantitat = enter que indica la quantitat de GPs que hi hi al fitxer de GPs.
 *             in: list = llista ordenada on guardem la informacio del fitxer de GPs, ordenada segons la posicio en el calendari.
 *             in: base = estructura on tenim la informació base dels cotxes del últim fitxer.
 *             in: corr = estructura on tenim la informació dels corredors del fitxer de corredors.
* @Retorn: ----
*
************************************************/
void menu (Pilot *pilot, Categoria *cat, PecaActual *peca_actual, int quantitat, SortedList *list, Info info, Base base,
          Corredors *corr) {
    char opcio[30];
    int opcio_int = 0, trobat = 0, opcio1_executat = 0, i = 0, j = 0, pos = 0, num_GP = 0, opcio2_executat = 0, opcio3_executat = 0, found = 0;
    FinalCursa *fc;
    BidirectionalListCarreres list_carreres;
    FILE *p;

    list_carreres = BIDIRECTIONALLIST_create();

    printf("Benvinguts a LSRacing!\n\n");

    do {
        if (trobat == 1) {
            printf("Error. Opcio no valida\n\n");
        }

        trobat = 0;
        printf("       1. Configurar cotxe\n");
        printf("       2. Cursa\n");
        printf("       3. Veure classificacio\n");
        printf("       4. Guardar temporada\n\n");
        printf("Quina opcio vols executar? ");
        fgets(opcio, 30, stdin);
        opcio[strlen(opcio) - 1] = '\0';

        while ((opcio[0] != '1' && opcio[0] != '2' && opcio[0] != '3' && opcio[0] != '4') &&
               (strcmp(opcio, "exit") != 0)) {
            printf("\nError. Opcio no valida\n\n");
            printf("       1. Configurar cotxe\n");
            printf("       2. Cursa\n");
            printf("       3. Veure classificacio\n");
            printf("       4. Guardar temporada\n\n");
            printf("Quina opcio vols executar? ");
            fgets(opcio, 30, stdin);
            opcio[strlen(opcio) - 1] = '\0';
        }

        opcio_int = atoi(opcio);

        switch (opcio_int) {
            case 1:
                if (!opcio1_executat) {
                    configuracioCotxe (pilot);
                    opcio1_executat = 1;
                    SORTEDLIST_goToHead(list);
                }

                graficaPanellConfig (cat, peca_actual);
                break;

            case 2:
                if (opcio1_executat) {
                    opcio2 (quantitat, list, pilot, peca_actual, base, cat, corr, &num_GP, &list_carreres);
                    opcio2_executat = 1;
                } else {
                    printf("\nEncara no has configurat el cotxe.\n\n");
                }
                break;

            case 3:
                if (opcio2_executat) {
                    opcio3 (&list_carreres, num_GP, quantitat);
                    opcio3_executat = 1;
                } else {
                    printf("\nLa temporada encara no ha comencat.\n\n");
                }
                break;

            case 4:
                if (opcio3_executat) {
                    // El fitxer el crea dins de la carpeta CMake.
                    p = fopen ("logTemporada.txt", "w");
                    if (p == NULL) {
                        printf ("Error. No s'ha pogut obrir el fitxer");
                    } else {
                        opcio4 (p, &list_carreres, num_GP, quantitat);
                    }
                } else {
                    printf ("\nLa temporada encara no ha comencat.\n\n");
                }
                break;

            default:
                trobat = 1;
                break;
        }
    } while (strcmp(opcio, "exit") != 0);

    printf("\nFins aviat!\n");
    //SLCarrera_destroy (&list_carrera);
    //SLTemporada_destroy (&list_temporada);
    BIDIRECTIONALLIST_destroy (&list_carreres);
}