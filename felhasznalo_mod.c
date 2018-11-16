//
// Created by Heni on 2018. 11. 14..
//

#include <stdio.h>
#include <stdlib.h>
#include "felhasznalo_mod.h"

void felhasznalo_mod(){
    printf("Felhasználó mód\n\n");

    int szam;
    printf("1. Asztalfoglalás\n");
    printf("2. Rendelés megadása\n");
    printf("3. Számla kiállítása\n");
    printf("4. Visszalépés a főmenübe\n");
    printf("Kérem válasszon ezen menüpontok közül:");
    scanf("%d", &szam);

    if(szam < 1 || szam >4)
        printf("Érvénytelen a bemenet, kérem próbálja újra");
    //system("cls");

    if(szam == 1);
        //asztalfoglalas();
    if(szam == 2);
        //rendeles_megadasa();
    if(szam == 3);
        //szamla_kiallitasa();
    if(szam == 4)
        return;
}