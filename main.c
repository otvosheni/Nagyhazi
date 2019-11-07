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
    SetConsoleCP(65001);        //az ékezetes betűk miatt
    SetConsoleOutputCP(65001);
#endif

    egy_Asztal* asztaltomb = (egy_Asztal*) malloc(sizeof(egy_Asztal));
    int hossz;
    Menu menu_lista;
    bool bevanolvasva = false;          //hogy ne lehessen az adatok beolvasasa nelkul a felhasználó módba lépni
    while (true) {
        printf("\nHeni étterme");
        printf("\n\n");

        int szam;
        printf("1. Beállítás mód\n");
        printf("2. Felhasználó mód\n");
        printf("3. Teljes kilépés\n");
        printf("Kérem válasszon ezen menüpontok közül: ");
        scanf("%d", &szam);

        switch(szam){
            case 1: beallitas_mod(&asztaltomb,&hossz,&menu_lista);
                bevanolvasva = true;
                break;
            case 2:if (bevanolvasva)
                    felhasznalo_mod(asztaltomb, &hossz,menu_lista);
                else
                    printf("Nincsenek beolvasva az adatok. Kérem először olvassa be az adatokat a beállítás módban.\n");
                break;
            case 3: break;
            default: printf("Érvénytelen a bemenet, kérem próbálja újra! ");
        }
        //if (szam < 1 || szam > 3)
           // printf("Érvénytelen a bemenet, kérem próbálja újra! ");

        //if (szam == 1){
           // beallitas_mod(&asztaltomb,&hossz,&menu_lista);
           // bevanolvasva = true;
        //}
        //if (szam == 2) {
          //  if (bevanolvasva)
            //    felhasznalo_mod(asztaltomb, &hossz,menu_lista);
           // else
             //   printf("Nincsenek beolvasva az adatok. Kérem először olvassa be az adatokat a beállítás módban.\n");
        //}
        //if (szam == 3)
        //  return 0;
    }

}
