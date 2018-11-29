//
// Created by Heni on 2018. 11. 22..
//

#include <stdio.h>
#include <stdlib.h>
#include "szamla_kiallitasa.h"


void szamla_kiallitasa(egy_Asztal *asztaltomb, int *hossz) {
    int szam;
    printf("Hányas asztal: ");
    scanf("%d", &szam);
    if (szam > *hossz)
        printf("Ilyenre nincs lehetőség :(");
    else {
        egy_Asztal *megtalalt_asztal = NULL;
        for (int i = 0; i < *hossz; i++) {
            if (asztaltomb[i].szama == szam) {
                megtalalt_asztal = &asztaltomb[i];
                break;
            }
        }
        if (!megtalalt_asztal) {
            printf("Sajnos nincs ilyen asztal :(");
            return;
        }
        printf("\n");
        printf("Számla:\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        Rendeles *futo = megtalalt_asztal->rendelese;
        int osszeg = 0;
        while(futo){
            printf("%s, %10d Ft\n", futo->ertek->neve,futo->ertek->ara);
            osszeg += futo->ertek->ara;

            Rendeles *ideiglenes = futo->kov;
            free(futo);
            futo = ideiglenes;
        }
        megtalalt_asztal->rendelese = NULL;     //miután kiirtuk nullara allitjuk
        printf("----------------------------------------\n");
        printf("Összeg: %d Ft\n ", osszeg);
    }

    }
