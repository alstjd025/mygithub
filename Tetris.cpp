#include "Tetris.h"

int Tetris::iScreenDw = 0;
int Tetris::myMAX_BLK_TYPES = 0;
int Tetris::myMAX_BLK_DEGREES = 0;
std::vector<Matrix> Tetris::setofBlockObjects;

Tetris::Tetris(int dy, int dx){
    iScreenDy = dy;
    iScreenDx = dx;
    idxBlockDegree = 0;
    arrayscreen = createArrayscreen();
    oScreen = new Matrix(arrayscreen, dy+iScreenDw, dx+iScreenDw*2);
    juststarted = true;
    cout << "Print Basic Properties" << "\n";
    cout << "iScreenDy" << iScreenDy << "\n";
    cout << "iScreenDx" << iScreenDx << "\n";
    cout << "iScreenDw" << iScreenDw << "\n";
};

Tetris::Tetris(int* setofBlockArrays){

};

void Tetris::init(int* setOfBlockArrays[], int MAX_BLK_TYPES, int MAX_BLK_DEGREES){
    myMAX_BLK_DEGREES = MAX_BLK_DEGREES;
    myMAX_BLK_TYPES = MAX_BLK_TYPES;
    int arrayBlk_maxsize = 0;
    std::vector<int> blockdxdy;
    for(int i=0; i<MAX_BLK_TYPES; i++){ 
        int k = 0;
        while(setOfBlockArrays[i*MAX_BLK_DEGREES][k] != -1){
            k++;
        }
        if (k > arrayBlk_maxsize)
            arrayBlk_maxsize = sqrt(k);
        blockdxdy.push_back(sqrt(k));
    }
    iScreenDw = arrayBlk_maxsize;
    for (int i=0; i<MAX_BLK_TYPES; i++){
        for(int j=0; j<MAX_BLK_DEGREES; j++){   
            setofBlockObjects.push_back(Matrix(setOfBlockArrays[i*MAX_BLK_DEGREES + j],
             blockdxdy[i], blockdxdy[i]));
             cout << "blockdxdy " << blockdxdy[i] << "\n";
        }
    }
    //initialize iscreenDw, setOfBlockObjects(Matrix)
};

TetrisState Tetris::accept(int key){
    cout << "accept key : " << key << " " <<  char(key) << "\n";
    
    if(key >= int('0') && key <= int('6')){
        if (juststarted == false)
            deletefulllines();
        cout << "accept in \n";
        Matrix iScreen = oScreen;
        int idxBlockType = key;
        idxBlockDegree = 0;
        cout << setofBlockObjects[idxBlockType*myMAX_BLK_DEGREES + idxBlockDegree];
        cout << "\n";
        return TetrisState(Running);
    }
    else    
        cout << "false \n";
    
    return TetrisState(Running);
};


int* Tetris::createArrayscreen(){
    int arrayScreenDx = iScreenDw * 2 + iScreenDx;
    int arrayScreenDy = iScreenDw + iScreenDy;
    cout << arrayScreenDx  << " " << arrayScreenDy << "\n";
    int* arrayscreen = new int[arrayScreenDy * arrayScreenDx];
    for(int i=0; i<arrayScreenDy-iScreenDw; i++){
        for(int j=0; j<iScreenDw; j++)
            arrayscreen[i*arrayScreenDx +j] = 1;
        for(int j=iScreenDw; j<arrayScreenDx-iScreenDw; j++)
            arrayscreen[i*arrayScreenDx +j] = 0;
        for(int j=arrayScreenDx-iScreenDw; j<arrayScreenDx; j++)
            arrayscreen[i*arrayScreenDx +j] = 1;
    }
    for(int i=arrayScreenDy-iScreenDw; i<arrayScreenDy; i++){ //segfault
        for(int j=0; j<arrayScreenDx; j++){
            arrayscreen[i*arrayScreenDx + j] = 1;
        }
    }
    for(int i=0; i<arrayScreenDx*arrayScreenDy; i++)
    {
        cout << arrayscreen[i];
    }
    return arrayscreen;
};

void Tetris::deletefulllines(){
    return;
}
