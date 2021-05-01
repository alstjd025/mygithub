#include "CTetris.h"

void CTetris::init(int* setOfBlockArrays[], int MAX_BLK_TYPES, int MAX_BLK_DEGREES){
    Tetris::init(setOfBlockArrays, MAX_BLK_TYPES, MAX_BLK_DEGREES);
    
    for(int i=0; i<MAX_BLK_TYPES*MAX_BLK_DEGREES; i++){
        for(int k=0; k<MAX_BLK_DEGREES; k++){
            setofCBlockObjects.push_back(setofBlockObjects[i*MAX_BLK_DEGREES + k]); 
            setofCBlockObjects[i*MAX_BLK_DEGREES + k].mulc(i+1);
        }
    }
    return;
};

CTetris::CTetris(int cy, int cx){
    arrayscreen = createArrayscreen();
    iCScreen = new Matrix(arrayscreen, cy, cx);
    oCScreen = iCScreen;
    return;
};

TetrisState CTetris::accept(int key){
    if(key - '0' >= 0 && key - '0' <= 6){
        if (juststarted == false);
            deleteFullLines();
        iCScreen = new Matrix(oCScreen);
    }
    state = Tetris::accept(key);
    currCBlk = setofCBlockObjects[idxBlockType*myMAX_BLK_DEGREES + idxBlockDegree];
    tempBlk = iCScreen->clip(top, left, top+currCBlk.get_dy(), left+currCBlk.get_dy());
    tempBlk = tempBlk.add(&currCBlk);

    oCScreen = new Matrix(iCScreen);
    oCScreen->paste(&tempBlk, top, left);
    return state;
};

void CTetris::deleteFullLines(){
    return;
};