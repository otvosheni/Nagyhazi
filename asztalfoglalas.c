//
// Created by Heni on 2018. 11. 18..
//

#include <stdio.h>
#include "asztalfoglalas.h"

typedef struct Foglalas{
    char datum[11];
    char nev[64];
    char idopont[6];
}Foglalas;

void foglalasok_listazasa(){
    FILE *file = fopen("asztalfoglalasok.dat", "rt");
    Foglalas egy_foglalas;
    while (fscanf(file, "%[^;];%s;%s\n", egy_foglalas.nev, egy_foglalas.datum, egy_foglalas.idopont)!= EOF){
        printf("Foglalás neve, dátuma, időpontja: %s,%s,%s\n", egy_foglalas.nev, egy_foglalas.datum,egy_foglalas.idopont);
    }
    fclose(file);
}


void foglalas_megadasa(){

    Foglalas egy_foglalas;
    printf("Foglalási adatok: \n");
    printf("Milyen névre szól a foglalás:");
    scanf("\n%[^\n]", egy_foglalas.nev);
    printf("Dátuma:");
    scanf("%s", egy_foglalas.datum); //datumot szokozok nélkul kell megadni
    printf("Mikorra:");
    scanf("%s", egy_foglalas.idopont);

    FILE *file = fopen ("asztalfoglalasok.dat", "awt");
    if(file)
        fprintf(file, "%s;%s;%s\n", egy_foglalas.nev, egy_foglalas.datum, egy_foglalas.idopont);
    else
        printf("Nem lehet elmenteni basszameg");
    fclose(file);
}

void asztalfoglalas(){
    printf("Asztalfoglalások\n\n");

    int szam;
    printf("1. Új foglalás megadása\n");
    printf("2. Asztalfoglalások listázása\n");
    printf("3. Visszalépés\n");
    printf("Kérem válasszon ezen menüpontok közül:");

    scanf("%d", &szam);
    if(szam < 1 && szam > 3)
        printf("Érvénytelen a bemenet, kérem próbálja újra!");

    if (szam == 1)
        foglalas_megadasa();
    if(szam == 2)
        foglalasok_listazasa();
    if(szam == 3)
        return;

}


