//
// Created by Heni on 2018. 11. 08..
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "menu_megadasa.h"
#include "strukturak.h"

Etel *etel_beolvas(char *kerdes, int *db){
    printf("%s",kerdes);
    int etelek_db = 0; //feltételezzük hogy először nulla db ételünk és és majd ezt mindig növeljük eggyel

    Etel *etelek; //ez egy etelek lista

    bool vege = false;
    int sorszam = 1;
    while(!vege) {
        char neve[64];
        printf("%d. Neve:", sorszam);
        scanf("\n%[^\n]", neve);
        if(strcmp(neve, "end") == 0)
            vege = true;
        else{
            int ara;
            printf("%d. Ára(Ft):", sorszam);
            scanf("%d", &ara);
            Etel *etelek_temp = (Etel*) malloc(sizeof(Etel)*(etelek_db+1)); //lefoglaltunk egy új tömböt
            for(int i=0; i<etelek_db; i++){
                etelek_temp[i] = etelek[i];//regiből atpakoljuk az ujba a tombok elemeit
            }
            Etel* uj_etel = &etelek_temp[etelek_db+1-1];
            strcpy(uj_etel->neve, neve);
            uj_etel->ara = ara;

            etelek_db ++;
            sorszam ++;

            free(etelek);
            etelek = etelek_temp;//itt csak a pointereket állítgatom
        }
    }
    *db = etelek_db;
    return etelek;
}
void mentes_fajlba(FILE *file, char *tipus, int db, Etel *lista){
    fprintf(file, "%s;%d\n",tipus,db);
    for (int i = 0; i < db; i++) {
        Etel kaja = lista[i];
        fprintf(file, "%s;%d\n", kaja.neve, kaja.ara);
    }
}

Menu* menu_beolvas() {
    FILE *file = fopen ("menu.dat", "rt");
    if (!file) {
        printf("Nem tudom beolvasni");
        return NULL;
    }

}

void menu_megadasa(){
    printf("Menü megadása:\n\n");

    int eloetelek_db;
    int foetelek_db;
    int desszertek_db;
    int italok_db;

    Etel *eloetelek = etel_beolvas("Előételek: \n", &eloetelek_db);
    Etel *foetelek = etel_beolvas("Főételek: \n", &foetelek_db);
    Etel *desszertek = etel_beolvas("Desszertek: \n ", &desszertek_db);
    Etel *italok = etel_beolvas("Italok: \n ", &italok_db);


    FILE *file = fopen("menu.dat", "wt");
    mentes_fajlba(file,"eloetelek",eloetelek_db,eloetelek);
    mentes_fajlba(file,"foetelek", foetelek_db, foetelek);
    mentes_fajlba(file,"desszertek", desszertek_db, desszertek);
    mentes_fajlba(file,"italok", italok_db,italok);

    fclose(file);

    int szam;
    printf("Ha végzett, akkor nyomja meg a 3-as gombot, hogy visszamehessen a főmenübe\n");
    scanf("%d", &szam);
    //system("cls");

    if (szam == 3)
        return;

}