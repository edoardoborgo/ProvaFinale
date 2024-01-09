
#ifndef PROVAFINALE_BOARDBOXBLANK_H
#define PROVAFINALE_BOARDBOXBLANK_H

#include "BoardBox.h"

class BoardBoxBlank : public BoardBox{

    public:
    BoardBoxBlank(){};
        BoardBoxBlank(char typeCharacter_) : BoardBox("blank", typeCharacter_){}
        std::string getBoxType() override{ return boxType; }

        char getTypeCharacter() override {return typeCharacter; };
        void action(Player* actualPlayer) override{}
        void eraseOwner() override{};
        Player* getOwner() override{ return nullptr; };

    std::string toString() override{
        return " ";
    }

    protected:

    private:

};

#endif //PROVAFINALE_BOARDBOXBLANK_H
