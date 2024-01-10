
#ifndef PROVAFINALE_BOARDBOX_H
#define PROVAFINALE_BOARDBOX_H

#include <string>
#include "Player.h"

class BoardBox{

    public:
        BoardBox(){};
        void setBoxType(int boxType_){ boxType = boxType_; };
        virtual std::string getBoxType(){ return "";};
        virtual char getTypeCharacter(){ return ' '; };
        virtual void eraseOwner(){};
        virtual Player* getOwner(){ return nullptr; };
        virtual void action(Player* actualPlayer){};
        virtual std::string toString(){ return  "";};

    protected:
        BoardBox(std::string boxType_, char typeCharacter_) : boxType(boxType_), typeCharacter(typeCharacter_) {};
        std::string boxType; // property-proprietà  blank-vuota
        char typeCharacter; //per stampare tabellone

    private:
        int index;

};

#endif //PROVAFINALE_BOARDBOX_H