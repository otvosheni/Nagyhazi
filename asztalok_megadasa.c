//
// Created by Heni on 2018. 11. 08..
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "asztalok_megadasa.h"
#include "strukturak.h"

egy_Asztal *asztalok_megadasa(int *hossz) {
    printf("\nAsztalok megadása: \n\n");

    int db;
    printf("Hány asztal van az étteremben:");
    scanf("%d", &db);

    *hossz = db;

    egy_Asztal *asztaltomb = (egy_Asztal *) malloc(sizeof(egy_Asztal) * db);
            //dinamikus tömb lefoglalása, amelyben az asztalok adatai vannak
    for (int i = 0; i < db; i++) {
        int ferohelyek;
        char elhelyezkedes[64];
        printf("Hány férőhelyes a(z) %d. asztal: ", i + 1);
        scanf("%d", &ferohelyek);
        printf("Hol van a(z) %d. asztal: ", i + 1);
        scanf("\n%[^\n]", elhelyezkedes); //addig olvas be ameddig nincs sorvég jel

        egy_Asztal asztal;
        asztal.szama = i + 1;
        asztal.ferohelye = ferohelyek;
        asztal.rendelese = NULL;        //ez majd a rendeléseknél fontos
        strcpy(asztal.helye, elhelyezkedes);
        asztaltomb[i] = asztal;         //itt adom át az egyes asztalokat a tömbnek
    }

    FILE *file = fopen("asztal.dat", "wt");        //fájlba kiírás
    fprintf(file, "%d\n", db);
    for (int i = 0; i < db; i++) {
        egy_Asztal a = asztaltomb[i];
        fprintf(file, "%d;%s\n", a.ferohelye, a.helye);
    }
    fclose(file);

    return asztaltomb;
}

egy_Asztal *asztalok_beolvas(int *hossz){        //fajlbol beolvasas
    int db;
    FILE *file = fopen("asztal.dat", "rt");
    if(!file) {
        printf("Nem tudom beolvasni!");
        return NULL;
    }
    fscanf(file, "%d\n", &db);

    *hossz = db;

    egy_Asztal *asztaltomb = (egy_Asztal *) malloc(sizeof(egy_Asztal) * db);

    for(int i=0; i < db; i++){
        egy_Asztal* a = &asztaltomb[i];
        a->szama = i + 1;
        a->rendelese = NULL;
        fscanf(file, "%d;%s\n", &(a->ferohelye), a->helye);
    }
    return asztaltomb;
}