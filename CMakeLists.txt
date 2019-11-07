cmake_minimum_required(VERSION 3.12)
project(dfjkhalf C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(dfjkhalf
        asztalfoglalas.c
        asztalfoglalas.h
        asztalok_megadasa.c
        asztalok_megadasa.h
        beallitas_mod.c
        beallitas_mod.h
        felhasznalo_mod.c
        felhasznalo_mod.h
        main.c
        menu_megadasa.c
        menu_megadasa.h
        rendeles_megadasa.c
        rendeles_megadasa.h
        strukturak.h
        szamla_kiallitasa.c
        szamla_kiallitasa.h)
