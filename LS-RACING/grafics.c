/***********************************************
*
* @Propòsit: Mostrar per la pantalla gràfica tot lo que ens demanen a fer.
* @Autor/s: Marc Postils i Narcís Cisquella
* @Data de creació: 14/05/20
* @Data de l’última modificació: 04/07/20
*
************************************************/

#include "grafics.h"

/***********************************************
*
* @Finalitat: Insertar les fotografies dels boxes, pneumatics, boxes, etc a la pantalla gràfica i escriure tota la informació del panell a la pantalla gràfica.
* @Paràmetres: in: cat = estructura que utilitzem per tenir tant el número de categories, el nom de les categories, número de peces i noms de peces,
 *                       per després pintar a la finestra gràfica el nom de la categoria i peça corresponent.
 *             in: i = enter que anira recorrent per les diferents categories.
 *             in: j = enter que anira recorrent per les diferents peces.
 *             in: peca_actual = estrucutura on guardem el nom i el número de la peça que tinguem a la configuracio actual.
* @Retorn: ----
*
************************************************/
void drawPanellConfig (Categoria *cat, int i, int j, PecaActual *peca_actual) {
    int k = 0, y = 440;

    //Surt d'Allegro passats uns segons de carregar aquesta fotografia ja que té gran dimensió.
    ALLEGRO_BITMAP *boxes = al_load_bitmap("../boxes.png");
    al_draw_scaled_bitmap(boxes, 0, 0, al_get_bitmap_width(boxes), al_get_bitmap_height(boxes), 0, 0,
                          al_get_bitmap_width(boxes) / 1.2, al_get_bitmap_height(boxes) / 1.3, 0);

    if (strcmp(cat[i].nom_categoria, "Neumaticos") == 0) {
        ALLEGRO_BITMAP *neumaticos = al_load_bitmap("../neumaticos.png");
        al_draw_scaled_bitmap(neumaticos, 0, 0, al_get_bitmap_width(neumaticos), al_get_bitmap_height(neumaticos), 983,
                              150, al_get_bitmap_width(neumaticos) / 5, al_get_bitmap_height(neumaticos) / 3.5, 0);
    }

    if (strcmp (cat[i].nom_categoria, "Aero frontal") == 0) {
        ALLEGRO_BITMAP *aero_frontal = al_load_bitmap ("../aero_frontal.jpg");
        al_draw_scaled_bitmap (aero_frontal, 0, 0, al_get_bitmap_width(aero_frontal), al_get_bitmap_height(aero_frontal), 978, 114,
                               al_get_bitmap_width(aero_frontal) / 35, al_get_bitmap_height(aero_frontal) / 10.5, 0);
    }

    if (strcmp(cat[i].nom_categoria, "Aero zona media") == 0) {
        ALLEGRO_BITMAP *aero_media = al_load_bitmap("../aero_media.png");
        al_draw_scaled_bitmap(aero_media, 0, 0, al_get_bitmap_width(aero_media), al_get_bitmap_height(aero_media), 983, 142,
                              al_get_bitmap_width(aero_media) / 8.5, al_get_bitmap_height(aero_media) / 5.5, 0);
    }

    if (strcmp(cat[i].nom_categoria, "Aero posterior") == 0) {
        ALLEGRO_BITMAP *aero_posterior = al_load_bitmap("../aero_posterior.png");
        al_draw_scaled_bitmap(aero_posterior, 0, 0, al_get_bitmap_width(aero_posterior), al_get_bitmap_height(aero_posterior), 992, 122,
                              al_get_bitmap_width(aero_posterior) / 13, al_get_bitmap_height(aero_posterior) / 3.5, 0);
    }

    if (strcmp(cat[i].nom_categoria, "Gasolina") == 0) {
        ALLEGRO_BITMAP *gasolina = al_load_bitmap("../gasolina.png");
        al_draw_scaled_bitmap(gasolina, 0, 0, al_get_bitmap_width(gasolina), al_get_bitmap_height(gasolina), 983, 154,
                              al_get_bitmap_width(gasolina) / 4.6, al_get_bitmap_height(gasolina) / 3, 0);
    }

    if (strcmp(cat[i].nom_categoria, "Motor") == 0) {
        ALLEGRO_BITMAP *motor = al_load_bitmap("../motor.png");
        al_draw_scaled_bitmap(motor, 0, 0, al_get_bitmap_width(motor), al_get_bitmap_height(motor), 988, 151,
                              al_get_bitmap_width(motor) / 3.8, al_get_bitmap_height(motor) / 2.6, 0);
    }

    al_draw_filled_rectangle(950, 170, 980, 200, LS_allegro_get_color(WHITE)); //esquerra
    al_draw_filled_triangle(950, 140, 950, 230, 920, 185, LS_allegro_get_color(WHITE));

    al_draw_filled_rectangle(1050, 170, 1080, 200, LS_allegro_get_color(WHITE)); //dreta
    al_draw_filled_triangle(1080, 140, 1080, 230, 1110, 185, LS_allegro_get_color(WHITE));

    al_draw_filled_rectangle(1000, 110, 1030, 140, LS_allegro_get_color(WHITE)); //amunt
    al_draw_filled_triangle(970, 110, 1060, 110, 1015, 80, LS_allegro_get_color(WHITE));

    al_draw_filled_rectangle(1000, 230, 1030, 260, LS_allegro_get_color(WHITE)); //avall
    al_draw_filled_triangle(970, 260, 1060, 260, 1015, 290, LS_allegro_get_color(WHITE));


    //Donem l'ordre d'escriure el text de benvinguda
    al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 1000, 25, 0, "%s", cat[i].nom_categoria);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 1160, 130, 0, "%s",
                  cat[i].peces[j].nom_peca);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 1160, 160, 0, "VELOCITAT:");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 1290, 160, 0, "%d",
                  cat[i].peces[j].velocitat);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 1160, 190, 0, "ACCELERACIO:");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 1315, 190, 0, "%d",
                  cat[i].peces[j].acceleracio);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 1160, 220, 0, "CONSUM:");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 1255, 220, 0, "%d", cat[i].peces[j].consum);
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 1160, 250, 0, "FIABILITAT:");
    al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 1300, 250, 0, "%d",
                  cat[i].peces[j].fiabilitat);

    al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 920, 400, 0, "CONFIGURACIO ACTUAL");

    while (k < cat[0].num_categories) {
        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 920, y, 0, "%s:", cat[k].nom_categoria);
        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 1120, y, 0, "%s",
                      peca_actual[k].nom_peca_actual);
        k++;
        y = y + 20;
    }

    k = 0;
    //Pintem la pantalla de la finestra grafica
    LS_allegro_clear_and_paint(BLACK);
}

/***********************************************
*
* @Finalitat: Configurar el panell de configuracio i implementar diferents funcionalitats si apretem la flexa cap amunt, avall, dreta, esquerra
 *            i fer que sigui circular.
* @Paràmetres: in: cat = estructura que utilitzem per tenir tant el número de categories, el nom de les categories, número de peces i noms de peces,
 *                       per després pintar a la finestra gràfica el nom de la categoria i peça corresponent.
 *             in: peca_actual = estrucutura on guardem el nom i el número de la peça que tinguem a la configuracio actual.
* @Retorn: ----
*
************************************************/
void graficaPanellConfig (Categoria *cat, PecaActual *peca_actual) {
    int nSortir = 0;
    int i = 0, j = 0, new_cat = 0, new_pec = 0, first_time = 0;

    //Inicialitzem Allegro
    LS_allegro_init(1350, 625, "Proyecto");

    //Bucle infinit del joc
    while (!nSortir) {
        if (LS_allegro_key_pressed(ALLEGRO_KEY_ESCAPE)) {
            nSortir = 1;
        }

        //Escoltem el teclat esperant la tecla ESC
        if (LS_allegro_key_pressed (ALLEGRO_KEY_DOWN)) {
            if ((cat[0].num_categories - 1) == i) {
                i = 0;
                j = 0;
                new_cat = 1;
            } else {
                i++;
                j = 0;
                new_cat = 1;
            }
        }

        if (LS_allegro_key_pressed (ALLEGRO_KEY_UP)) {
            if (i == 0) {
                i = (cat[0].num_categories - 1);
                j = 0;
                new_cat = 1;
            } else {
                i--;
                j = 0;
                new_cat = 1;
            }
        }

        if (LS_allegro_key_pressed (ALLEGRO_KEY_RIGHT)) {
            if ((cat[i].num_peces - 1) == j) {
                j = 0;
                new_pec = 1;
            } else {
                j++;
                new_pec = 1;
            }
        }

        if (LS_allegro_key_pressed (ALLEGRO_KEY_LEFT)) {
            if (j == 0) {
                j = (cat[i].num_peces - 1);
                new_pec = 1;
            } else {
                j--;
                new_pec = 1;
            }
        }
        if (first_time == 0) {
            peca_actual[0].num_peca_actual = j;
            strcpy(peca_actual[0].nom_peca_actual, cat[0].peces[0].nom_peca);
            first_time = 1;
        } else {
            if (new_cat == 1) {
                peca_actual[i].num_peca_actual = j;
                strcpy(peca_actual[i].nom_peca_actual, cat[i].peces[j].nom_peca);
                new_cat = 0;
            }

            if (new_pec == 1) {
                peca_actual[i].num_peca_actual = j;
                strcpy(peca_actual[i].nom_peca_actual, cat[i].peces[j].nom_peca);
                new_pec = 0;
            }
        }

        drawPanellConfig (cat, i, j, peca_actual);
    }

    //Tanquem la finestra grafica
    LS_allegro_exit();
}

/***********************************************
*
* @Finalitat: Calcular el temps  segons els clocs del ordinador 0.5 segons cada cop.
* @Paràmetres: in: temp = float on guardem el temps.
* @Retorn: retorna el float temp que es la suma de temp mes 0.5 segons.
*
************************************************/
float tempo (float temp) {
    float time1, time0;
    time0 = (float) clock();

    // Calculem la diferència de temps i transformem a secs.
    while ((time1 - time0) / (float) (CLOCKS_PER_SEC) < 0.5) {
        time1 = (float) clock();
    }

    temp = 0.5 + temp;

    return temp;
}

/***********************************************
*
* @Finalitat: Calcular el temps  segons els clocs del ordinador 1 segon cada cop.
* @Paràmetres: in: avancar = float on guardem el temps.
* @Retorn: retorna el float avancar que es la suma d'avancar més 1 segons.
*
************************************************/
float tempo2 (float avancar) {

    float time1, time0;

    time0 = (float) clock();

    // Calculem la diferència de temps i transformem a segons.
    while ((time1 - time0) / (float) (CLOCKS_PER_SEC) < 1) {
        time1 = (float) clock();
    }

    avancar = avancar + 1;

    return avancar;
}

/****************************************************************************
 *
* @Finalitat: Mostar la pantalla grafica del semàfor, depenent el temps s'aniran encen els respectius semàfors.
* @Paràmetres: ----
* @Retorn: ----
*
****************************************************************************/
void graficaSemafor () {
    int nSortir = 0;
    float time1 = 0.0, time0 = 0.0, temp;
    int cops = 0, trobat1 = 0, trobat2 = 0, trobat3 = 0, trobat4 = 0, trobat5 = 0;

    while (!nSortir) {
        //Escoltem el teclat esperant la tecla ESC
        if (LS_allegro_key_pressed(ALLEGRO_KEY_ESCAPE)) {
            nSortir = 1;
        }

        al_draw_filled_rectangle(700, 130, 600, 495, LS_allegro_get_color(BLACK)); //mig
        al_draw_filled_circle(649, 185, 30, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(649, 270, 30, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(649, 355, 30, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(649, 440, 30, LS_allegro_get_color(GRAY)); //abaix

        al_draw_filled_rectangle(575, 130, 475, 495, LS_allegro_get_color(BLACK)); //segon
        al_draw_filled_circle(524, 185, 30, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(524, 270, 30, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(524, 355, 30, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(524, 440, 30, LS_allegro_get_color(GRAY));

        al_draw_filled_rectangle(825, 130, 725, 495, LS_allegro_get_color(BLACK)); //quart
        al_draw_filled_circle(774, 185, 30, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(774, 270, 30, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(774, 355, 30, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(774, 440, 30, LS_allegro_get_color(GRAY));

        al_draw_filled_rectangle(450, 130, 350, 495, LS_allegro_get_color(BLACK)); //primer
        al_draw_filled_circle(399, 185, 30, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(399, 270, 30, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(399, 355, 30, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(399, 440, 30, LS_allegro_get_color(GRAY));

        al_draw_filled_rectangle(950, 130, 850, 495, LS_allegro_get_color(BLACK)); //ultim
        al_draw_filled_circle(899, 185, 30, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(899, 270, 30, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(899, 355, 30, LS_allegro_get_color(GRAY));
        al_draw_filled_circle(899, 440, 30, LS_allegro_get_color(GRAY));

        temp = tempo(temp);

        if (temp == 1.5 || trobat1 == 1) {
            al_draw_filled_circle(399, 355, 30, LS_allegro_get_color(RED));
            al_draw_filled_circle(399, 440, 30, LS_allegro_get_color(RED));
            trobat1 = 1;
        }

        if (temp == 2.5 || trobat2 == 1) {
            al_draw_filled_circle(524, 355, 30, LS_allegro_get_color(RED));
            al_draw_filled_circle(524, 440, 30, LS_allegro_get_color(RED));
            trobat2 = 1;
        }

        if (temp == 3.5 || trobat3 == 1) {
            al_draw_filled_circle(649, 355, 30, LS_allegro_get_color(RED));
            al_draw_filled_circle(649, 440, 30, LS_allegro_get_color(RED));
            trobat3 = 1;
        }

        if (temp == 4.5 || trobat4 == 1) {
            al_draw_filled_circle(774, 355, 30, LS_allegro_get_color(RED));
            al_draw_filled_circle(774, 440, 30, LS_allegro_get_color(RED));
            trobat4 = 1;
        }

        if (temp == 5.5 || trobat5 == 1) {
            al_draw_filled_circle(899, 355, 30, LS_allegro_get_color(RED));
            al_draw_filled_circle(899, 440, 30, LS_allegro_get_color(RED));
            trobat5 = 1;
        }

        if (temp == 7.5) {
            trobat1 = 0, trobat2 = 0, trobat3 = 0, trobat4 = 0, trobat5 = 0;
        }

        if (temp == 8) {
            nSortir = 1;
        }

        //Pintem la pantalla de la finestra grafica
        LS_allegro_clear_and_paint(WHITE);
    }
}

/****************************************************************************
*
* @Finalitat: Mostar la pantalla grafica de la cursa, calcular el temps de cada cotxe i quan avançan per segon en la carrera i en consequencia
*             determinar l'ordre d'arribada.
* @Paràmetres: in: pilot = estructura on més endavant guardarem la informacio que introdueix l'usuari per pantalla.
*              in: e = element on tenim la informació de cada GP de la llista.
*              in: peca_actual = estrucutura on guardarem el nom i el número de la peça que tinguem a la configuracio actual.
*              in: base = estructura on tenim la informació base dels cotxes del últim fitxer.
*              in: cat = estructura on guardarem la informació del fitxer de peces
*              in: corr = estructura on tenim la informació dels corredors del fitxer de corredors.
*              in: fc = estructura on guardarem la informació del final de cada cursa (temps, punts, etc.)
* @Retorn: ----
*
****************************************************************************/
void graficaCursa (Pilot *pilot, Info e, PecaActual *peca_actual, Base base, Categoria *cat, Corredors *corr, FinalCursa *fc) {
    int nSortir = 0, i = 0, avancar = 0;
    int b = 0, j = 0, y = 0, velocitat = 0, sumaVelocitat = 0, acceleracio = 0, sumaAcceleracio = 0, consum = 0, sumaConsum = 0, fiabilitat = 0, sumaFiabilitat = 0;
    int sumatotal = 0, num_pitstop = 0, coeficient_habilitat = 0;
    int tempsBaseSegons = 0, resta1, resta2, resta3, resta4, sumaresta, tempsPitStopsFinal, tempsTotalNosaltres;
    int premR, premP = 0, radio_correcte = 0, radio_incorrecte = 0, cops_pitstop = 0, temps_al_pitstop = 0;
    int num_pitstopCorredors = 0, tempsPitStopsFinalCorredors = 0, x_final[NUM_PILOTS], dist_final[NUM_PILOTS];
    float temp2;

    // Del nostre Pilot sumem la base del cotxe i de les diferents peces selecionades en l'opcio 1.
    // Per després poder fer la suma de les diferències entre el nostre cotxe i el Gp.
    sumaVelocitat = sumaVelocitat + base.velocitat;
    sumaAcceleracio = sumaAcceleracio + base.acceleracio;
    sumaConsum = sumaConsum + base.consum;
    sumaFiabilitat = sumaFiabilitat + base.fiabilitat;

    for (b = 0; b < 6; b++) {
        sumaVelocitat = sumaVelocitat + cat[b].peces[peca_actual[b].num_peca_actual].velocitat;
        sumaAcceleracio = sumaAcceleracio + cat[b].peces[peca_actual[b].num_peca_actual].acceleracio;
        sumaConsum = sumaConsum + cat[b].peces[peca_actual[b].num_peca_actual].consum;
        sumaFiabilitat = sumaFiabilitat + cat[b].peces[peca_actual[b].num_peca_actual].fiabilitat;
    }

    tempsBaseSegons = (int) (60 * e.t_base);
    resta1 = abs(e.velocitat - sumaVelocitat);
    resta2 = abs(e.acceleracio - sumaAcceleracio);
    resta3 = abs(e.consum - sumaConsum);
    resta4 = abs(e.fiabilitat - sumaFiabilitat);
    sumaresta = resta1 + resta2 + resta3 + resta4;

    // Calculem el número de pitstops depenen el consum del nostre cotxe.
    if (sumaConsum > e.consum) {
        num_pitstop = e.n_pitstop + 1;
    } else {
        num_pitstop = e.n_pitstop - 1;
    }

    tempsTotalNosaltres = tempsBaseSegons + sumaresta;
    // Només ens queda restar el coeficient d'habilitat.
    coeficient_habilitat = ((pilot->reflexes + pilot->condicioFisica + pilot->temperament + pilot->gestioPneumatics) / 4) / 2;
    tempsTotalNosaltres = tempsTotalNosaltres - coeficient_habilitat;
    fc[0].temps = tempsBaseSegons + sumaresta - coeficient_habilitat;
    fc[0].num_dorsal = pilot->dorsal;
    fc[0].num_pilot = 0;
    strcpy (fc[0].nom_pilot, pilot->nomPilot);
    j = 0;
    resta1 = 0, resta2 = 0, resta3 = 0, resta4 = 0, sumaresta = 0;

    // Sumem la diferència entre les estadístiques de cada corredor i el Gp.
    // Per així tindre el temps de cada corredor mitjançant la suma base + la dif d'estadistiques - coeficient d'habilitats + el temps dels pit stops.
    while (j < NUM_PILOTS - 1) {
        resta1 = abs(e.velocitat - corr[j].velocitat);
        resta2 = abs(e.acceleracio - corr[j].acceleracio);
        resta3 = abs(e.consum - corr[j].consum);
        resta4 = abs(e.fiabilitat - corr[j].fiabilitat);
        sumaresta = resta1 + resta2 + resta3 + resta4;
        coeficient_habilitat = ((corr[j].reflexes + corr[j].condicio_fisica + corr[j].temperament + corr[j].gestio_pneumatics) / 4) /2;

        if (e.consum < corr[j].consum) {
            num_pitstopCorredors = e.n_pitstop + 1;
        } else {
            num_pitstopCorredors = e.n_pitstop - 1;
        }

        tempsPitStopsFinalCorredors = (e.t_pitstop) * num_pitstopCorredors;
        fc[j+1].temps = tempsBaseSegons + sumaresta - coeficient_habilitat + tempsPitStopsFinalCorredors;
        fc[j+1].num_dorsal = corr[j].dorsal;
        fc[j+1].num_pilot = j + 1;
        strcpy (fc[j+1].nom_pilot, corr[j].nom_pilot);
        j++;
        num_pitstopCorredors = 0, tempsPitStopsFinalCorredors = 0;
    }

    i = 0;
    while (i < NUM_PILOTS) {
        x_final[i] = 0;
        dist_final[i] = 0;
        i++;
    }

    i = 0;
    while (i < NUM_PILOTS) {
        x_final[i] = (830 / fc[i].temps);
        i++;
    }

    while (!nSortir) {
        // Realitzem les diferents operacions per tal de sumar els pitstop depenen de si prem R i P o nomeés P i les seves divereses penalitzacions
        // només al nostre pilot.
        if (LS_allegro_key_pressed(ALLEGRO_KEY_R)) {
            premR = 1;
        }

        if (LS_allegro_key_pressed(ALLEGRO_KEY_P) && radio_correcte < num_pitstop) {
            premP = 1;
            cops_pitstop = cops_pitstop + 1;

            if (premR == 1) {
                radio_correcte = radio_correcte + 1;
                fc[0].temps = fc[0].temps + e.t_pitstop;
            } else {
                radio_incorrecte = radio_incorrecte + 1;
            }
        }

        // No les posem en un bucle ja que no ens quedaven quadrades amb els cotxes
        al_draw_line(930, 48, 100, 48, LS_allegro_get_color(BLACK), 3);
        al_draw_line(930, 112.5, 100, 112.5, LS_allegro_get_color(BLACK), 3);
        al_draw_line(930, 177, 100, 177, LS_allegro_get_color(BLACK), 3);
        al_draw_line(930, 240, 100, 240, LS_allegro_get_color(BLACK), 3);
        al_draw_line(930, 305, 100, 305, LS_allegro_get_color(BLACK), 3);
        al_draw_line(930, 368, 100, 368, LS_allegro_get_color(BLACK), 3);
        al_draw_line(930, 431, 100, 431, LS_allegro_get_color(BLACK), 3);
        al_draw_line(930, 495, 100, 495, LS_allegro_get_color(BLACK), 3);

        avancar = tempo2(avancar);

        if (dist_final[0] >= 880) { //930
            nSortir = 1;
        }

        if (premP == 1) {
            temps_al_pitstop = temps_al_pitstop + avancar - (avancar - 1);
            ALLEGRO_BITMAP *cotxe = al_load_bitmap("../cotxe.png");
            al_draw_scaled_bitmap(cotxe, 0, 0, al_get_bitmap_width(cotxe), al_get_bitmap_height(cotxe), dist_final[0], 35,
                                  al_get_bitmap_width(cotxe) / 1.5, al_get_bitmap_height(cotxe) / 1.7, 0);
            if (temps_al_pitstop == e.t_pitstop) {
                temps_al_pitstop = 0;
                premP = 0;
            }
        } else {
            if (dist_final[0] < 880) {
                dist_final[0] = 100 + x_final[0] * (avancar - (cops_pitstop * e.t_pitstop));
                ALLEGRO_BITMAP *cotxe = al_load_bitmap("../cotxe.png");
                al_draw_scaled_bitmap(cotxe, 0, 0, al_get_bitmap_width(cotxe), al_get_bitmap_height(cotxe), dist_final[0],
                                      35, al_get_bitmap_width(cotxe) / 1.5, al_get_bitmap_height(cotxe) / 1.7, 0);
            }
        }

        i = 1;
        y = 99.5;
        while (i < NUM_PILOTS) {
            if (dist_final[i] < 880) {
                dist_final[i] = 100 + x_final[i] * avancar;
                ALLEGRO_BITMAP *cotxe2 = al_load_bitmap("../cotxe.png");
                al_draw_scaled_bitmap (cotxe2, 0, 0, al_get_bitmap_width(cotxe2), al_get_bitmap_height(cotxe2),
                                      dist_final[i], y,al_get_bitmap_width(cotxe2) / 1.5, al_get_bitmap_height(cotxe2) / 1.7, 0);
            } else {
                ALLEGRO_BITMAP *cotxe2 = al_load_bitmap("../cotxe.png");
                al_draw_scaled_bitmap (cotxe2, 0, 0, al_get_bitmap_width(cotxe2), al_get_bitmap_height(cotxe2),
                                      dist_final[i], y,al_get_bitmap_width(cotxe2) / 1.5, al_get_bitmap_height(cotxe2) / 1.7, 0);
            }
            y = y + 64.5;
            i++;
        }

        al_draw_filled_rectangle(1003, 550, 0, 700, LS_allegro_get_color(BLACK)); //abaix
        al_draw_filled_rectangle(1350, 0, 1005, 700, LS_allegro_get_color(BLACK)); //dreta
        // Ho podriem fer un un bucle pero sino no quedavem tots alineats amb la linea de la cursa i el cotxe.
        al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(BLACK), 20, 37, 0, "%d", fc[0].num_dorsal);
        al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(BLACK), 20, 102, 0, "%d", fc[1].num_dorsal);
        al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(BLACK), 20, 165, 0, "%d", fc[2].num_dorsal);
        al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(BLACK), 20, 227, 0, "%d", fc[3].num_dorsal);
        al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(BLACK), 20, 294, 0, "%d", fc[4].num_dorsal);
        al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(BLACK), 20, 359, 0, "%d", fc[5].num_dorsal);
        al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(BLACK), 20, 420, 0, "%d", fc[6].num_dorsal);
        al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(BLACK), 20, 484, 0, "%d", fc[7].num_dorsal);

        al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 1030, 25, 0, "PILOT");
        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 1045, 55, 0, "NOM");
        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), 1050, 75, 0, "%s", pilot->nomPilot);
        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 1045, 95, 0, "ESCUDERIA");
        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), 1050, 115, 0, "%s",
                      pilot->nomEscuderia);
        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 1045, 135, 0, "DORSAL");
        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), 1050, 155, 0, "%d", pilot->dorsal);
        al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 1030, 180, 0, "COTXE");
        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 1045, 210, 0, "VELOCITAT");
        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), 1050, 230, 0, "%d", sumaVelocitat);
        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 1045, 250, 0, "ACCELERACIO");
        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), 1050, 270, 0, "%d", sumaAcceleracio);
        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 1045, 290, 0, "CONSUM");
        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), 1050, 310, 0, "%d", sumaConsum);
        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 1045, 330, 0, "FIABILITAT");
        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(YELLOW), 1050, 350, 0, "%d", sumaFiabilitat);
        //al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 1030, 570, 0, "%d", avancar);
        al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 1163, 390, 0, "%d", avancar);
        al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 1030, 570, 0, "STOPS: %d / %d",
                      radio_correcte, num_pitstop);

        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 25, 585, 0, "RADIO (R)");
        al_draw_textf(LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 835, 585, 0, "PIT STOP (P)");

        //Pintem la pantalla de la finestra grafica
        LS_allegro_clear_and_paint(WHITE);
    }

    // Obtenim el temps total del nostre pilot, si li falten pitstops, sumem la multiplicació del temps de pit stop *5 com a penalització per cada cada vegada que no hagi entrat
    // I per cada cop que ha entrat a pitstop sense donarli prèviament a la radio, també li sumem aquell temps.
    while (radio_correcte < num_pitstop) {
        radio_correcte = radio_correcte + 1;
        fc[0].temps = fc[0].temps + (5 * e.t_pitstop);
    }

    fc[0].temps = fc[0].temps + (radio_incorrecte * e.t_pitstop);
}

/****************************************************************************
 *
 * @Finalitat: Implementar i mostrar la pantalla gràfica de benvinguda al GP i després la del semàfor i la de la cursa.
 * @Paràmetres: in: e = element on tenim la informació de cada GP de la llista.
 *              in: pilot = estructura on tenim la informació del nostre pilot.
 *              in: peca_actual = estrucutura on tenim el nom i el número de la peça que tinguem a la configuracio actual.
 *              in: base = estructura on tenim la informació base dels cotxes del últim fitxer.
 *              in: cat = estructura on tenim la informació de les categories i peces del fitxer de peces.
 *              in: corr = estructura on tenim la informació dels corredors del fitxer de corredors.
 *              in: fc = estructura on guardarem la informació del final de cada cursa (temps, punts, etc.)
 * @Retorn: ----
 *
 ****************************************************************************/
void graficaGPs (Info e, Pilot *pilot, PecaActual *peca_actual, Base base, Categoria *cat, Corredors *corr, FinalCursa *fc) {
    int nSortir = 0;

    //Inicialitzem Allegro        /
    LS_allegro_init(1350, 625, "Proyecto");

    //Bucle infinit del joc
    while (!nSortir) {
        if (LS_allegro_key_pressed(ALLEGRO_KEY_R)) {
            graficaSemafor ();
            graficaCursa (pilot, e, peca_actual, base, cat, corr, fc);
            nSortir = 1;
        }

        al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 370, 170, 0, "BENVINGUT AL %s",
                      e.nom);
        al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 450, 250, 0, "VELOCITAT:");
        al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 690, 250, 0, "%d", e.velocitat);
        al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 450, 290, 0, "ACCELERACIO:");
        al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 730, 290, 0, "%d", e.acceleracio);
        al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 450, 330, 0, "CONSUM:");
        al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 620, 330, 0, "%d", e.consum);
        al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 450, 370, 0, "%s", "FIABILITAT:");
        al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 710, 370, 0, "%d", e.fiabilitat);
        al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 370, 500, 0,"PULSA R PER COMENCAR LA CARRERA");

        LS_allegro_clear_and_paint(BLACK);
    }
}

/****************************************************************************
*
* @Finalitat: Mostrar la pantalla gràfica de la posició del nostre pilot a la cursa.
* @Paràmetres: in: pos = enter que indica la posició del nostre pilot.
*              in: pilot = estructura tenim la informacio del nostre pilot.
* @Retorn: ----
*
*****************************************************************************/
void graficaPosicio (int pos, Pilot pilot) {
    int nSortir = 0;

    while (!nSortir) {
        if (LS_allegro_key_pressed(ALLEGRO_KEY_ENTER)) {
            nSortir = 1;
        }
        al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 380, 170, 0, "%s HA FINALITZAT",
                      pilot.nomPilot);
        al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 420, 200, 0, "EN LA POSICIO %d", pos);
        al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 310, 260, 0,
                      "PULSA ENTER PER TORNAR AL MENU");

        LS_allegro_clear_and_paint(BLACK);
    }
    //Tanquem la finestra grafica
    LS_allegro_exit();
}

/****************************************************************************
*
* @Finalitat: Mostrar la pantalla gràfica de la posició del nostre pilot i dels corredors de cada gran premi, amb el nom,
*             temps i punts otorgats.
* @Paràmetres: in: list_carrera = llista ordenada per temps de menor a major on guardem la classificació de cada GP.
* @Retorn: ----
*
*****************************************************************************/
void graficaClassificacio (SortedListCarrera *list_carrera) {
    int i = 0, y = 100;
    FinalCursa e;

    SLCarrera_goToHead(list_carrera);
    e = SLCarrera_get(list_carrera);
    al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 100, 50, 0, "CLASSIFIACIO DE %s", e.nom_GP);
    while (i < NUM_PILOTS) {
        al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 100, y, 0, "%d. %s (%d S) - %d PUNTS",
                      i + 1, e.nom_pilot, e.temps, e.punts);
        y = y + 50;
        i++;
        if (i < NUM_PILOTS) {
            SLCarrera_next(list_carrera);
            e = SLCarrera_get(list_carrera);
        }
    }

    LS_allegro_clear_and_paint(BLACK);
}

/****************************************************************************
*
* @Finalitat: Mostrar la pantalla gràfica de la posició de total de les carreres del nostre pilot i corredors
*             amb el seu nom, dorsal i la suma de punts de totes les carreres.
* @Paràmetres: in: list_temporada = llista ordenada per punts de més a menys on tenim la classificació de la temporada.
* @Retorn: ----
*
****************************************************************************/
void graficaClassifiacioTemporada (SortedListTemporada *list_temporada) {
    int i = 0, y = 100;
    FinalTemporada e;

    al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 100, 50, 0,
                  "CLASSIFIACIO DE FINAL DE TEMPORADA");
    SLTemporada_goToHead (list_temporada);
    while (i < NUM_PILOTS) {
        e = SLTemporada_get (list_temporada);
        al_draw_textf(LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), 100, y, 0, "%d. %s (%d) - %d PUNTS",
                      i + 1, e.nom_pilot, e.num_dorsal, e.punts);
        i++;
        y = y + 50;
        SLTemporada_next (list_temporada);
    }

    LS_allegro_clear_and_paint(BLACK);
}
