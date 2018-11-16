//
// Created by Heni on 2018. 11. 08..
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "asztalok_megadasa.h"
#include "strukturak.h"

EGY_DARAB_Asztal *asztalok_megadasa() {
    printf("Asztalok megadása: \n\n");

    int db;
    printf("Hány asztal van az étteremben:");
    scanf("%d", &db);

    EGY_DARAB_Asztal *asztalok = (EGY_DARAB_Asztal *) malloc(sizeof(EGY_DARAB_Asztal) * db);

    for (int i = 0; i < db; i++) {
        int ferohelyek;
        char elhelyezkedes[64];
        printf("Hány férőhelyes a(z) %d. asztal: ", i + 1);
        scanf("%d", &ferohelyek);
        printf("Hol van a(z) %d. asztal: ", i + 1);
        scanf("\n%[^\n]", elhelyezkedes); //addig olvas be ameddig nincs sorvég jel

        EGY_DARAB_Asztal asztal;
        asztal.szama = i + 1;
        asztal.ferohelye = ferohelyek;
        strcpy(asztal.helye, elhelyezkedes);
        asztalok[i] = asztal;
    }

    FILE *file = fopen("asztal.dat", "wt");
    fprintf(file, "%d\n", db);
    for (int i = 0; i < db; i++) {
        EGY_DARAB_Asztal a = asztalok[i];
        fprintf(file, "%d;%s\n", a.ferohelye, a.helye);
    }
    fclose(file);

    return asztalok;
}

EGY_DARAB_Asztal *asztalok_beolvas(){
    int db;
    FILE *file = fopen("asztal.dat", "rt");
    if(!file) {
        printf("Nem tudom beolvasni!");
        return NULL;
    }
    fscanf(file, "%d\n", &db);

    EGY_DARAB_Asztal *asztalok = (EGY_DARAB_Asztal *) malloc(sizeof(EGY_DARAB_Asztal) * db);

    for(int i=0; i < db; i++){
        EGY_DARAB_Asztal* a = &asztalok[i];
        a->szama = i + 1;
        fscanf(file, "%d;%s\n", &(a->ferohelye), a->helye);
    }
    return asztalok;
}