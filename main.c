#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "beallitas_mod.h"
#include "felhasznalo_mod.h"

#ifdef _WIN32

#include <windows.h>

#endif

int main(void) {

//forras: infoc
#ifdef _WIN32
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
#endif

    EGY_DARAB_Asztal* asztal_lista;
    while (true) {
        printf("Heni étterme");
        printf("\n\n");

        int szam;
        printf("1. Beállítás mód\n");
        printf("2. Felhasználó mód\n");
        printf("3. Teljes kilépés\n");
        printf("Kérem válasszon ezen menüpontok közül: ");
        scanf("%d", &szam);

        if (szam < 1 || szam > 3)
            printf("Érvénytelen a bemenet, kérem próbálja újra! ");
        //system("cls"); //only on windows

        if (szam == 1)
            //TODO REMOVE NULL!!!
            beallitas_mod(&asztal_lista, NULL);
        if (szam == 2)
            felhasznalo_mod();
        if (szam == 3)
            return 0;
    }

}
