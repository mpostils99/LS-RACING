/***********************************************
*
* @Propòsit: Tenir un mòdul a part per a que l'usuari introdueixi per pantalla les dades del pilot.
* @Autor/s: Marc Postils i Narcís Cisquella.
* @Data de creació: 23/04/20
* @Data de l’última modificació: 22/06/20
*
************************************************/

#include "configuracioCotxe.h"

/***********************************************
*
* @Finalitat: Guardar a la estructura Pilot la informació que l'usuari introdueix per pantalla.
* @Paràmetres: in: pilot = estructura on guardarem tota la informació del nostre pilot.
* @Retorn: ----
*
************************************************/
void configuracioCotxe (Pilot *pilot) {

    char nom[25], nom_escuderia[25], dorsal[5], reflexes[5], condicio_fisica[5], temperament[5], gestio_de_pneumatics[5];
    int valor_dorsal, error, i, valor_reflexes, valor_condicio_fisica, valor_temperament, valor_gestio_de_pneumatics;

    printf ("\nNom del pilot? ");
    fgets (nom, 26, stdin);
    nom[strlen (nom) - 1] = '\0';
    strcpy (pilot->nomPilot, nom);

    printf ("Nom de l'escuderia? ");
    fgets (nom_escuderia, 26, stdin);
    nom_escuderia[strlen (nom_escuderia) - 1] = '\0';
    strcpy (pilot->nomEscuderia, nom_escuderia);

    do {
        printf ("Dorsal? ");
        fgets (dorsal, 5, stdin);
        dorsal[strlen (dorsal) - 1] = '\0';
        error = 0;
        valor_dorsal = 0;

        //Utilitzem un for per recorrer per la cadena i comprobem que sigui un caràcter vàlid.
        for (i = 0; i < strlen (dorsal); i++) {
            if (dorsal[i] < '0' || dorsal[i] > '9')	{
                error = 1;
            }
        }

        if (error == 0) {
            for (i = 0; i < strlen (dorsal); i++) {
                //Aqui fem un ATOI creat per nosaltres
                valor_dorsal = (valor_dorsal*10) + (dorsal[i]-'0');
            }
        }

        //Comprovem que el valor de sigui vàlid.
        if (valor_dorsal < 1 || valor_dorsal > 99) {
            error = 1;
        }

        //Creeam una variable error per tal que quan entri aqui mostri error
        if (error == 1) {
            printf ("\nError, el dorsal ha de ser un enter entre 1 i 99.\n\n");
        }

    } while (error == 1);

    pilot->dorsal = valor_dorsal;

    do {
        printf ("Reflexes? ");
        fgets (reflexes, 5, stdin);
        reflexes[strlen (reflexes) - 1] = '\0';
        error = 0;
        valor_reflexes = 0;

        for (i = 0; i < strlen(reflexes); i++) {
            if (reflexes[i] < '0' || reflexes[i] > '9')	{
                error = 1;
            }
        }

        if (error == 0) {
            for (i = 0; i < strlen(reflexes); i++) {
                valor_reflexes = (valor_reflexes*10) + (reflexes[i]-'0');
            }
        }

        if (valor_reflexes < 0 || valor_reflexes > 10) {
            error = 1;
        }

        if (error == 1) {
            printf ("\nError, els reflexes ha de ser un enter entre 0 i 10.\n\n");
        }

    } while (error == 1);

    pilot->reflexes = valor_reflexes;

    do {
        printf ("Condicio fisica? ");
        fgets (condicio_fisica, 5, stdin);
        condicio_fisica[strlen (condicio_fisica) - 1] = '\0';
        error = 0;
        valor_condicio_fisica = 0;

        for (i = 0; i < strlen(condicio_fisica); i++) {
            if (condicio_fisica[i] < '0' || condicio_fisica[i] > '9') {
                error = 1;
            }
        }

        if (error == 0) {
            for (i = 0; i < strlen(condicio_fisica); i++) {
                valor_condicio_fisica = (valor_condicio_fisica*10) + (condicio_fisica[i]-'0');
            }
        }

        if (valor_condicio_fisica < 0 || valor_condicio_fisica > 10) {
            error = 1;
        }

        if (error == 1) {
            printf ("\nError, la condicio_fisica ha de ser un enter entre 0 i 10.\n\n");
        }

    } while (error == 1);

    pilot->condicioFisica = valor_condicio_fisica;

    do {
        printf ("Temperament? ");
        fgets (temperament, 5, stdin);
        temperament[strlen (temperament) - 1] = '\0';
        error = 0;
        valor_temperament = 0;

        for (i = 0; i < strlen (temperament); i++) {
            if (temperament[i] < '0' || temperament[i] > '9') {
                error = 1;
            }
        }

        if (error == 0) {
            for (i = 0; i < strlen (temperament); i++) {
                valor_temperament = (valor_temperament*10) + (temperament[i]-'0');
            }
        }

        if (valor_temperament < 0 || valor_temperament > 10) {
            error = 1;
        }

        if (error == 1) {
            printf ("\nError, el temperament  ha de ser un enter entre 0 i 10.\n\n");
        }

    } while (error == 1);
    pilot->temperament = valor_temperament;

    do {
        printf ("Gestio de pneumatics? ");
        fgets (gestio_de_pneumatics, 5, stdin);
        gestio_de_pneumatics[strlen (gestio_de_pneumatics) - 1] = '\0';
        printf ("\n");
        error = 0;
        valor_gestio_de_pneumatics = 0;

        for (i = 0; i < strlen (gestio_de_pneumatics); i++) {
            if (gestio_de_pneumatics[i] < '0' || gestio_de_pneumatics[i] > '9')	{
                error = 1;
            }
        }

        if (error == 0) {
            for (i = 0; i < strlen (gestio_de_pneumatics); i++) {
                valor_gestio_de_pneumatics = (valor_gestio_de_pneumatics*10) + (gestio_de_pneumatics[i]-'0');
            }
        }

        if (valor_gestio_de_pneumatics < 0 || valor_gestio_de_pneumatics > 10) {
            error = 1;
        }

        if (error == 1) {
            printf ("\nError, la gestio de pneumatics  ha de ser un enter entre 0 i 10.\n\n");

        }

    } while (error == 1);

    pilot->gestioPneumatics = valor_gestio_de_pneumatics;
}


