
#ifndef PROVAFINALE_PC_H
#define PROVAFINALE_PC_H

#include "Player.h"

class Pc : public Player{

    public:
        Pc() : Player(1){};
        int getPlayerType() override;

    protected:

    private:
};

#endif //PROVAFINALE_PC_H