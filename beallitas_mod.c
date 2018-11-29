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

void beallitas_mod(egy_Asztal** asztaltomb,int *hossz, Menu* menutomb) {
    printf("\nBeállítás mód\n\n");

    int szam;
    printf("1. Asztalok megadása\n");
    printf("2. Menü megadása\n");
    printf("3. Fájlból beolvasás\n");
    printf("4. Visszalépés a főmenübe\n");
    printf("Kérem válasszon ezen menüpontok közül: ");
    scanf("%d", &szam);

    if (szam < 1 || szam > 4)
        printf("Érvénytelen a bemenet, kérem próbálja újra!");

    if (szam == 1)
        *asztaltomb = asztalok_megadasa(hossz);
    if (szam == 2)
        *menutomb = menu_megadasa();
    if(szam == 3)
        fajlbol_olvasas(asztaltomb,hossz,menutomb);
    if (szam == 4)
        return;
}

void fajlbol_olvasas(egy_Asztal** asztaltomb,int *hossz, Menu* menutomb) {
    int szam;
    printf("\n");
    printf("1. Asztalok beolvasása\n");
    printf("2. Menü beolvasása\n");
    printf("3. Visszalépés\n");
    printf("Kérem válasszon ezen menüpontok közül:");
    scanf("%d", &szam);

    if(szam < 1 || szam > 3)
        printf("Érvénytelen a bemenet, kérem próbálja újra! ");

    if(szam == 1)
        *asztaltomb = asztalok_beolvas(hossz);
    if(szam == 2)
        *menutomb = menu_beolvas();
    if(szam == 3)
        return;
}
