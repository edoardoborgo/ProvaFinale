

#ifndef PROVAFINALE_BOARDBOXLUX_H
#define PROVAFINALE_BOARDBOXLUX_H

#include "BoardBox.h"

class BoardBoxLux : public BoardBox{

public:
    BoardBoxLux(int price) : BoardBox(price, 3){};
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

#endif //PROVAFINALE_BOARDBOXLUX_H
