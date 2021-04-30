#include "Tetris.h"

int Tetris::iScreenDw = 0;
std::vector<Matrix> Tetris::setofBlockObjects;

Tetris::Tetris(int dy, int dx){
    iScreenDy = dy;
    iScreenDx = dx;
    idxBlockDegree = 0;
    arrayscreen = createArrayscreen();

    iScreen = new Matrix(arrayscreen, dy, dx);
    oScreen = new Matrix(arrayscreen, dy, dx);
    juststarted = true;
};

Tetris::Tetris(int* setofBlockArrays){
    
};

void Tetris::init(int* setOfBlockArrays[], int MAX_BLK_TYPES, int MAX_BLK_DEGREES){
    int arrayBlk_maxsize = 0;
    std::vector<int> blockdxdy;
    for(int i=0; i<MAX_BLK_TYPES; i++){ 
        int k = 0;
        while(setOfBlockArrays[i*MAX_BLK_DEGREES][k] != -1){
            k++;
        }
        if (k > arrayBlk_maxsize)
            arrayBlk_maxsize = k;
        blockdxdy.push_back(sqrt(k));
    }
    iScreenDw = arrayBlk_maxsize;
    for (int i=0; i<MAX_BLK_TYPES; i++){
        for(int j=0; j<MAX_BLK_DEGREES; j++){   
            setofBlockObjects.push_back(new Matrix(setOfBlockArrays[i*MAX_BLK_DEGREES + j],
             blockdxdy[i], blockdxdy[i]));
        }
    }
    //initialize iscreenDw, setOfBlockObjects(Matrix)
};

TetrisState Tetris::accept(int key){
    state = TetrisState(Running);

    if(key >= '0' && key <= '6'){
        if (juststarted == false)
            deletefulllines();
        iScreen = new Matrix(oScreen);
        int idxBlockType = int(key);
        idxBlockDegree = 0;
        Matrix currBlk = setofBlockObjects[idxBlockType*MAX_BLK_TYPES + idxBlockDegree];
        return TetrisState(Running);
    }
    return TetrisState(Running);
};


int* Tetris::createArrayscreen(){
    
    int arrayScreenDx = iScreenDw * 2 + iScreenDx;
    int arrayScreenDy = iScreenDw + iScreenDy;
    int* arrayscreen = new int[arrayScreenDy * arrayScreenDx];
    int i = 0;
    for(; i<arrayScreenDy-iScreenDw; i++){
        int j = 0;
        for(; j<iScreenDw; j++)
            arrayscreen[i*arrayScreenDx +j] = 1;
        for(; j<iScreenDx-iScreenDw; j++)
            arrayscreen[i*arrayScreenDx +j] = 0;
        for(; j<iScreenDx; j++)
            arrayscreen[i*arrayScreenDx +j] = 1;
    }
    for(; i<iScreenDy; i++){
        for(int j=0; j<iScreenDx; i++){
            arrayscreen[i*arrayScreenDx + j] = 1;
        }
    }
    
    return arrayscreen;
};

void Tetris::deletefulllines(){
}
