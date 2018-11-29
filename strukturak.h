//
// Created by Heni on 2018. 11. 10..
//

#ifndef HF_STRUKTURAK_H
#define HF_STRUKTURAK_H

typedef struct Etel {
    char neve[64];
    int ara;
}Etel;

typedef struct Menu{
    Etel *eloetel;
    Etel *foetel;
    Etel *desszert;
    Etel *ital;
    int eloetel_hossz;
    int foetel_hossz;
    int desszert_hossz;
    int ital_hossz;
}Menu;

typedef struct Rendeles {
    Etel *ertek;
    struct Rendeles *kov;
} Rendeles;

typedef struct egy_Asztal {
    int szama;
    int ferohelye;
    char helye[64];
    Rendeles *rendelese;
} egy_Asztal;




#endif //HF_STRUKTURAK_H
