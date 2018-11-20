//
// Created by Heni on 2018. 11. 08..
//

#ifndef HF_MENU_MEGADASA_H
#define HF_MENU_MEGADASA_H

#include <stdio.h>
#include "strukturak.h"

Menu menu_megadasa();
Etel *etel_beolvas(char *kerdes, int *db);
void mentes_fajlba(FILE *file, char *tipus, int db, Etel *lista);
Menu menu_beolvas();

#endif //HF_MENU_MEGADASA_H
