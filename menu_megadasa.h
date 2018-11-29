//
// Created by Heni on 2018. 11. 08..
//

#ifndef HF_MENU_MEGADASA_H
#define HF_MENU_MEGADASA_H

#include <stdio.h>
#include "strukturak.h"

Menu menu_megadasa();
Etel *etel_beolvas(char *eteltipus, int *db);
void mentes_fajlba(FILE *file, char *tipus, int db, Etel *lista);
Menu menu_beolvas();
Etel *menutipus_beolvas(FILE *file, int *hossz);

#endif //HF_MENU_MEGADASA_H
