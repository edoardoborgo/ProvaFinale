#include "../include/BoardManager.h"

int movePlayer(int actualPosition, int shift){
    static constexpr int arrayLength = 28;
    int newPosition;
    if(actualPosition+shift >= arrayLength){
        newPosition=(actualPosition+shift) % arrayLength;
        //giro completo dell'array, ritiro un premio per il passaggio
        throw completeTurn(newPosition);
    }else{
        newPosition=actualPosition+shift;
    }
    return newPosition;
}