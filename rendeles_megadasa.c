//
// Created by Heni on 2018. 11. 22..
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>
#include "rendeles_megadasa.h"
#include "strukturak.h"

void egy_rendeles_megadasa(egy_Asztal *asztaltomb, int *hossz, Menu menu) {
    int szam;
    printf("Hányas asztal: ");      //egy asztal rendeléseit jegyzi meg
    scanf("%d", &szam);
    if (szam > *hossz)
        printf("Ilyenre nincs lehetőség :(");
    else {
        egy_Asztal *megtalalt_asztal = NULL;        //itt megkeressük a megadott asztalt
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
        Rendeles *eleje = megtalalt_asztal->rendelese;      //elso rendelesre mutato pointer
        printf("%d. asztal rendelése:\n", szam);
        bool vege = false;
        getchar();
        while (!vege) {
            char rendeles[128];
            printf("Írja be a rendelést: ");
            fgets(rendeles, 128, stdin);        //\n miatt ezt hasznaltam egy teljes sor beolvasásához

            if(strlen(rendeles) == 1)
                continue;

            if (strcmp(rendeles, "end\n") == 0)     //end-el kell jelezni hogy végeztünk
                vege = true;
            else {
                Etel *rendelt_etel = etel_leker(menu, rendeles);    //megnézi, hogy van e ilyen étel a menüben
                if (!rendelt_etel)
                    printf("Nincs ilyen étel a Menüben. :(\n");
                else {
                    Rendeles *uj = (Rendeles *) malloc(sizeof(Rendeles));
                    uj->kov = NULL;
                    uj->ertek = rendelt_etel;
                    if (eleje) {
                        Rendeles *futo = eleje;
                        while(futo->kov){       //megkeressük az lista végét
                            futo = futo->kov;
                        }
                        futo->kov = uj;
                    }
                    else
                        eleje = uj;
                }
            }
        }
        megtalalt_asztal->rendelese = eleje;

    }
}

Etel *etel_leker(Menu menu, char *szoveg) {     //ellenőrzi h egy megadott étel benne van e a menuben

    if (szoveg[strlen(szoveg) - 1] == 10)
        szoveg[strlen(szoveg) - 1] = 0; //ha az utolso karakter \n akkor azt levágja

    if(strlen(szoveg) == 0)
        return NULL;

    for (int i = 0; i < menu.eloetel_hossz; i++)
        if (strcmp(menu.eloetel[i].neve, szoveg) == 0)
            return &menu.eloetel[i];
    for (int i = 0; i < menu.foetel_hossz; i++)
        if (strcmp(menu.foetel[i].neve, szoveg) == 0)
            return &menu.foetel[i];
    for (int i = 0; i < menu.desszert_hossz; i++)
        if (strcmp(menu.desszert[i].neve, szoveg) == 0)
            return &menu.desszert[i];
    for (int i = 0; i < menu.ital_hossz; i++)
        if (strcmp(menu.ital[i].neve, szoveg) == 0)
            return &menu.ital[i];
    return NULL;
}
