
#ifndef PROVAFINALE_PLAYER_H
#define PROVAFINALE_PLAYER_H

class Player{

public:
    Player(){};
    Player(int playerType, int playerNumber);
    Player(const Player &other);
    int throwDices();
    void deposit(int value);
    void withdraw(int value);

    int getMoney();
    int getPlayerNumber();
    virtual int getPlayerType(){ return 0; };
    virtual bool takeDecision(){ return false;};
    void setPosition(int position);
    int getPosition();

protected:
    int money;
    int playerNumber;
    int playerType; // 1-PC  2-HUMAN
    int actualPosition = 0;

private:

};

#endif //PROVAFINALE_PLAYER_H