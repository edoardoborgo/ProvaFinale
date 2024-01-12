
#ifndef PROVAFINALE_HUMAN_H
#define PROVAFINALE_HUMAN_H

#include "Player.h"

class Human : public Player{

public:
    Human(int playerNumber) : Player(2, playerNumber){};
    int getPlayerType() override;

protected:

private:
};

#endif //PROVAFINALE_HUMAN_H