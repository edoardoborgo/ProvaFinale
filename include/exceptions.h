
#ifndef TESTCIRCULARARRAY_EXCEPTIONS_H
#define TESTCIRCULARARRAY_EXCEPTIONS_H

#include <exception>

class completeTurn : public std::exception{
    public:
        completeTurn(int newPosition_) : newPosition(newPosition_){};
        int getNewPosition(){return newPosition;}
    private:
        int newPosition;
};

class outOfMoney : public std::exception{
    public:
        outOfMoney(Player* actualPlayer_) : actualPlayer(actualPlayer_) {};
    private:
        Player* actualPlayer;
};

#endif //TESTCIRCULARARRAY_EXCEPTIONS_H
