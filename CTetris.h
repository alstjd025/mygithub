#pragma once

#define color_normal "\033[30m"
#define color_black "\033[0m"
#define color_red  "\033[31m"
#define color_green "\033[32m"
#define color_yellow "\033[33m"
#define color_blue "\033[34m"
#define color_magenta "\033[35m"
#define color_cyan "\033[36m"
#define b_color_black "\033[40m"

#include "Tetris.h"

class CTetris : public Tetris {
    public:
        static std::vector<Matrix> setofCBlockObjects;
        Matrix* iCScreen;
        Matrix* oCScreen;
        Matrix currCBlk;
        Matrix tempBlk;
        int* arrayscreen;
        
        
        CTetris(int cy, int cx);
        ~CTetris();
        static void init(int *setofBlockArrays[], int MAX_BLK_TYPES, int MAX_BLK_DEGREES);
        TetrisState accept(int key);
        void deleteFullLines();
};
