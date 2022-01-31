/***********************************************
*
* @Propòsit: Fer la lectura dels quatre fitxers i guardar les dades, tot en un mateix mòdul per tal de tenir-ho ben estructurat.
* @Autor/s: Marc Postils i Narcís Cisquella.
* @Data de creació: 25/04/20
* @Data de l’última modificació: 04/07/20
*
************************************************/

#include "carregarFitxers.h"

/***********************************************
*
* @Finalitat: Llegir el fitxer de peces i guardar-lo correctament a la estructura de Categoria en arrays dinàmics.
* @Paràmetres: in: f = fitxer on està tota la informació de les peces.
*              in: cat = estructura que utilitzem per guardar la informació d'aquest fitxer.
* @Retorn: ----
*
************************************************/
void carregarFitxer1 (FILE *f, Categoria **cat) {
    Categoria *categoria = NULL;
    int num_cat = 0, num_peces = 0, i = 0, j = 0;
    int vel = 0, con = 0, fia = 0, acc = 0;
    char aux[26], aux2[5];

    fgets (aux2, 5, f);
    aux[strlen (aux) - 1] = '\0';
    num_cat = atoi (aux2);
    categoria = (Categoria *) malloc (sizeof (Categoria) * num_cat);

    if (categoria == NULL) {
        printf ("Error del malloc.\n");
    } else {
        while (i < num_cat) {
            categoria[i].num_categories = num_cat;
            j = 0;
            fgets (aux, 26, f); //nom categoria
            aux[strlen(aux) - 1] = 0;
            strcpy (categoria[i].nom_categoria, aux);
            fgets (aux2, 5, f); //num peces
            aux2[strlen(aux2) - 1] = 0;
            num_peces = atoi(aux2);
            categoria[i].peces = (Peces *) malloc (sizeof (Peces) * num_peces);

            if (categoria[i].peces == NULL) {
                printf("Error\n");
            } else {
                while (j < num_peces) {
                    categoria[i].num_peces = num_peces;
                    fgets (aux, 26, f); //nom peça
                    aux[strlen (aux) - 1] = 0;
                    strcpy (categoria[i].peces[j].nom_peca, aux);
                    fgets (aux2, 5, f); // velocitat
                    aux2[strlen (aux2) - 1] = 0;
                    vel = atoi (aux2);
                    categoria[i].peces[j].velocitat = vel;
                    fgets (aux2, 5, f); // acceleracio
                    aux2[strlen (aux2) - 1] = 0;
                    acc = atoi (aux2);
                    categoria[i].peces[j].acceleracio = acc;
                    fgets (aux2, 5, f); // consum
                    aux2[strlen (aux2) - 1] = 0;
                    con = atoi (aux2);
                    categoria[i].peces[j].consum = con;
                    fgets (aux2, 5, f); // fiabilitat
                    aux2[strlen(aux2) - 1] = 0;
                    fia = atoi (aux2);
                    categoria[i].peces[j].fiabilitat = fia;
                    j++;
                }
            }
            i++;
        }
        *cat = categoria;
    }
    //free (categoria);
    fclose (f);
}

/***********************************************
*
* @Finalitat: Llegir el fitxer de GPs i guardar-lo correctament a una llista ordenada.
* @Paràmetres: in: g = fitxer on està tota la informació dels GPs.
*              in: list = llista ordenada segons la posició en el calendari on guardarem la informació de tots els GPs.
*              in: info = és l'element de la llista ordenada.
* @Retorn: retorna la quantitat de GPs que hi ha en total al fitxer.
*
************************************************/
int carregarFitxer2 (FILE *g, SortedList *list, Info *info) {
    int quantitat = 0, i = 0;
    char brossa;

    fscanf (g, "%d", &quantitat);

    while (i < quantitat) {
        fscanf (g, "%d", &info->posicio);
        fscanf (g, "%c", &brossa);
        fgets (info->nom, 26, g);
        info->nom[strlen (info->nom) - 1] = '\0';
        fscanf (g, "%d", &info->velocitat);
        fscanf (g, "%d", &info->acceleracio);
        fscanf (g, "%d", &info->consum);
        fscanf (g, "%d", &info->fiabilitat);
        fscanf (g, "%f", &info->t_base);
        fscanf (g, "%f", &info->t_pitstop);
        fscanf (g, "%d", &info->n_pitstop);
        SORTEDLIST_sortedAdd (list, info);
        i++;
    }

    fclose (g);

    return quantitat;
}

/***********************************************
*
* @Finalitat: Llegir el fitxer binari de corredors i guardar-lo correctament en un array dinàmic (Corredors).
* @Paràmetres: in: h = fitxer on està tota la informació dels corredors.
*              in: corr = estructura on guardarem tota la informació dels corredors.
* @Retorn: ----
*
************************************************/
void carregarFitxer3 (FILE *h, Corredors **corr) {
    Corredors *corre;
    int i = 0;

    corre = (Corredors *) malloc (sizeof (Corredors) * 7);

    if (corre == NULL) {
        printf ("Error del malloc\n");
    } else {
        // Sabem que hi ha 7 sempre.
        while (!feof(h)) {
            fread (&corre[i], sizeof (Corredors), 7, h);
            i++;
        }
    }

    *corr = corre;
    //free (corre);
    fclose (h);
}

/***********************************************
*
* @Finalitat: Llegir el fitxer binari de la base dels cotxes i guardar-lo correctament a la estrucura anomenada Base.
* @Paràmetres: in: l = fitxer on està tota la informació de la base dels cotxes.
* @Retorn: retorna la informació de la base dels cotxes que hem guardat prèviament.
*
************************************************/
Base carregarFitxer4 (FILE *l) {
    Base base;
    int i = 0;

    fread (&base, sizeof (Base), 1, l);
    fclose (l);

    return base;
}
