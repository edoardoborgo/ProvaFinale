#include "../include/BoardManager.h"

int movePlayer(int actualPosition, int shift){
    static constexpr int arrayLength = 28;
    int newPosition;
    if(actualPosition+shift >= arrayLength){
        newPosition=(actualPosition+shift) % arrayLength;
        //giro completo dell'array, ritiro un premio per il passaggio
        throw completeTurnException(newPosition);
    }else{
        newPosition=actualPosition+shift;
    }
    return newPosition;
}

char getLetter(int index){
    char letter=' ';
    if(index>=1 && index<=8)
        letter = 'A';
    else if(index>=15 && index <=22)
        letter = 'H';
    else if(index<15 && index >8){
        letter = char('A'+index-8);
    }else if(index>22){
        letter =  char('H'-(index-22));
    }
    return letter;
}

int getNumber(int index){
    int number=0;
    if(index>=1 && index<=8)
        number = index;
    else if(index>=15 && index <=22)
        number = index;
    else if(index<15 && index >8){
        number = 8;
    }else if(index>22){
        number = 1;
    }
    return number;
}