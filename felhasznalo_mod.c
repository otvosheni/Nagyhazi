//
// Created by Heni on 2018. 11. 14..
//

#include <stdio.h>
#include <stdlib.h>
#include "felhasznalo_mod.h"
#include "asztalfoglalas.h"
#include "rendeles_megadasa.h"
#include "szamla_kiallitasa.h"

void felhasznalo_mod(egy_Asztal *asztaltomb,int *hossz, Menu menu){
    printf("\nFelhasználó mód\n\n");

    int szam;
    printf("1. Asztalfoglalás\n");
    printf("2. Rendelés megadása\n");
    printf("3. Számla kiállítása\n");
    printf("4. Visszalépés a főmenübe\n");
    printf("Kérem válasszon ezen menüpontok közül:");
    scanf("%d", &szam);

    if(szam < 1 || szam >4)
        printf("Érvénytelen a bemenet, kérem próbálja újra");

    if(szam == 1)
        asztalfoglalas();
    if(szam == 2)
        egy_rendeles_megadasa(asztaltomb,hossz,menu);
    if(szam == 3)
        szamla_kiallitasa(asztaltomb, hossz);
    if(szam == 4)
        return;
}