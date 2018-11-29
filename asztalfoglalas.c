//
// Created by Heni on 2018. 11. 18..
//

#include <stdio.h>
#include "asztalfoglalas.h"

typedef struct Foglalas{
    char datum[12];
    char nev[64];
    char idopont[6];
}Foglalas;

void asztalfoglalas(){
    printf("\nAsztalfoglalások\n\n");

    int szam;
    printf("1. Új foglalás megadása\n");
    printf("2. Asztalfoglalások listázása\n");
    printf("3. Visszalépés\n");
    printf("Kérem válasszon ezen menüpontok közül:");

    scanf("%d", &szam);
    if(szam < 1 || szam > 3)
        printf("Érvénytelen a bemenet, kérem próbálja újra!");

    if (szam == 1)
        foglalas_megadasa();
    if(szam == 2)
        foglalasok_listazasa();
    if(szam == 3)
        return;

}

void foglalas_megadasa(){
    printf("\n");

    Foglalas egy_foglalas;
    printf("Foglalási adatok: \n");
    printf("Milyen névre szól a foglalás:");
    scanf("\n%[^\n]", egy_foglalas.nev);
    printf("Dátuma:");
    scanf("%s", egy_foglalas.datum); //datumot szokozok nélkul kell megadni
    printf("Mikorra:");
    scanf("%s", egy_foglalas.idopont);

    FILE *file = fopen ("asztalfoglalasok.dat", "awt");         //hozzáírja az eddigi asztalfoglalásokhoz
    if(file)
        fprintf(file, "%s;%s;%s\n", egy_foglalas.nev, egy_foglalas.datum, egy_foglalas.idopont);
    else
        printf("Nem lehet beolvasni");
    fclose(file);
}

void foglalasok_listazasa(){
    FILE *file = fopen("asztalfoglalasok.dat", "rt");       //fájlból beolvasás
    if(!file) {
        printf("Nincsenek foglalt asztalok\n");
        return;
    }
    char sor[64];
    printf("\n");
    printf(" %17s | %11s  | %8s|\n", "Foglalás neve", "Dátum", "Időpont");
    printf("-------------------------------------------\n");
    while (fscanf(file, "%[^\n]\n", sor) != EOF){
        char nev[64], datum[64], ido[64];
        sscanf(sor,"%[^;];%[^;];%[^;]",nev,datum,ido);
        printf("%17s | %11s | %6s |\n",nev, datum, ido);
    }
    fclose(file);
}