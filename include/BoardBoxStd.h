

#ifndef PROVAFINALE_BOARDBOXSTD_H
#define PROVAFINALE_BOARDBOXSTD_H

#include "BoardBox.h"

class BoardBoxStd : public BoardBox{

public:
    BoardBoxStd(int price) : BoardBox(price, 1){};
    int getType() override{
        return boxType;
    }
    int getHouseType() override{
        return houseType;
    }
private:

};

#endif //PROVAFINALE_BOARDBOXSTD_H
