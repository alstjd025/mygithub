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
        int iScreenDx;
        int iScreenDy;
        int idxBlockDegree;
        int MAX_BLK_TYPES;
        int* arrayscreen;
        bool juststarted;
        TetrisState state;
    
        Tetris(int dy, int dx);
        Tetris(int* setofBlockarrays);
        static void init(int* setOfBlaockArrays[], int MAX_BLK_TYPES, int MAX_BLK_DEGREES);
        TetrisState accept(int key);
        int* createArrayscreen();
        void deletefulllines();
        
};

