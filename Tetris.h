#pragma once
#include "Matrix.h"
#include <vector>
#include <cmath>


enum TetrisState { Running, NewBlock, Finished };

class Tetris {
    public:
        Matrix* oScreen;
        static int iScreenDw;
        static std::vector<Matrix> setofBlockObjects;
        static int myMAX_BLK_DEGREES;
        static int myMAX_BLK_TYPES;
        TetrisState state;
        int iScreenDx;
        int iScreenDy;
        int idxBlockDegree;
        int* arrayscreen;
        bool juststarted;
    
        Tetris(int dy, int dx);
        Tetris(int* setofBlockarrays);
        static void init(int* setOfBlaockArrays[], int MAX_BLK_TYPES, int MAX_BLK_DEGREES);
        TetrisState accept(int key);
        int* createArrayscreen();
        void deletefulllines();
        
};

