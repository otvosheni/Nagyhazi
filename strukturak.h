//
// Created by Heni on 2018. 11. 10..
//

#ifndef HF_STRUKTURAK_H
#define HF_STRUKTURAK_H

typedef struct Rendeles {

} Rendeles;

typedef struct EGY_DARAB_Asztal {
    int szama;
    int ferohelye;
    char helye[64];
    Rendeles rendelese;
} EGY_DARAB_Asztal;

typedef struct Etel {
    char neve[64];
    int ara;
}Etel;

typedef struct Menu{
    Etel *eloetel;
    Etel *foetel;
    Etel *desszert;
    Etel *ital;
}Menu;
#endif //HF_STRUKTURAK_H
