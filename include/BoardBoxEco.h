
#ifndef PROVAFINALE_BOARDBOXECO_H
#define PROVAFINALE_BOARDBOXECO_H

#include "BoardBox.h"

class BoardBoxEco : public BoardBox{
    public:
        BoardBoxEco(int price) : BoardBox(price, 2){};
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

#endif //PROVAFINALE_BOARDBOXECO_H
