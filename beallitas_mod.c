//
// Created by Heni on 2018. 11. 08..
//

#include <stdio.h>
#include <stdlib.h>
#include "beallitas_mod.h"
#include "asztalok_megadasa.h"
#include "menu_megadasa.h"
#include "strukturak.h"

#ifdef _WIN32

#include <windows.h>

#endif
void fajlbol_olvasas(EGY_DARAB_Asztal** asztal, Etel*** etel) {
    int szam;
    printf("1. Asztalok beolvasása\n");
    printf("2. Menü beolvasása\n");
    printf("3. Visszalépés\n");
    printf("Kérem válasszon ezen menüpontok közül:");
    scanf("%d", &szam);

    if(szam < 1 || szam > 3)
        printf("Érvénytelen a bemenet, kérem próbálja újra! ");

    EGY_DARAB_Asztal* a;
    if(szam == 1)
        *asztal = asztalok_beolvas();
    if(szam == 2)
       ;// menu_beolvas();
    if(szam == 3)
        return;
}


void beallitas_mod(EGY_DARAB_Asztal** asztal, Etel*** etelek) {
    printf("Beállítás mód\n\n");

    int szam;
    printf("1. Asztalok megadása\n");
    printf("2. Menü megadása\n");
    printf("3. Fájlból beolvasás\n");
    printf("4. Visszalépés a főmenübe\n");
    printf("Kérem válasszon ezen menüpontok közül: ");
    scanf("%d", &szam);
    //system("cls"); // only on windows

    if (szam != 1 && szam != 2 && szam != 3)
        printf("Érvénytelen a bemenet, kérem próbálja újra!");

    if (szam == 1) {
        EGY_DARAB_Asztal* a;
        a = asztalok_megadasa();
        *asztal = a;
    }
    if (szam == 2)
        menu_megadasa();
    if(szam == 3)
        fajlbol_olvasas(asztal,etelek);
    if (szam == 4)
        return;
}
