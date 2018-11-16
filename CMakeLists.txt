cmake_minimum_required(VERSION 3.12)
project(HF C)

set(CMAKE_C_STANDARD 99)

add_executable(HF main.c beallitas_mod.c beallitas_mod.h asztalok_megadasa.c asztalok_megadasa.h menu_megadasa.c menu_megadasa.h strukturak.h felhasznalo_mod.c felhasznalo_mod.h)