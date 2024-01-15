
#ifndef PROVAFINALE_BOARDMANAGER_H
#define PROVAFINALE_BOARDMANAGER_H

#include "../include/exceptions.h"

int movePlayer(int actualPosition, int shift);

//ottiene la lettera per indicizzare la casella
char getLetter(int index);
//ottiene il numero per indicizzare la casella
int getNumber(int index);



#endif //PROVAFINALE_BOARDMANAGER_H