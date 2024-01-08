
#ifndef PROVAFINALE_PLAYER_H
#define PROVAFINALE_PLAYER_H

class Player{

public:
    Player(int playerType);
    int throwDices();
    void deposit(int value);

    int getMoney();
    void setMoney(int value);
    int getPlayerNumber();
    virtual int getPlayerType();

protected:
    int money;
    int playerNumber;
    int playerType; // 1-PC  2-HUMAN

private:

};

#endif //PROVAFINALE_PLAYER_H