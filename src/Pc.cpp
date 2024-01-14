#include "../include/Pc.h"

int Pc::getPlayerType(){
    return playerType;
}

bool Pc::takeDecision(){
    srand(time(NULL));
    if(rand()%101<=decisionRate)
        return true;
    else
        return false;
}