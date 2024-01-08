

#ifndef PROVAFINALE_BOARDBOXSTART_H
#define PROVAFINALE_BOARDBOXSTART_H

#include "BoardBox.h"

class BoardBoxStart : public BoardBox{

public:
    BoardBoxStart() : BoardBox(0, 0){};
    int getType() override{
        return boxType;
    }
    int getHouseType() override{
        return houseType;
    }
    int getPrice(){
        return price;
    }
private:

};

#endif //PROVAFINALE_BOARDBOXSTART_H
