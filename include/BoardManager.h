
#ifndef PROVAFINALE_BOARDMANAGER_H
#define PROVAFINALE_BOARDMANAGER_H

int movePlayer(int playerPosition, int shift, int length){
    if(playerPosition+shift>=length)
        return (playerPosition+shift)%length;
    else
        return playerPosition+shift;
}

#endif //PROVAFINALE_BOARDMANAGER_H
