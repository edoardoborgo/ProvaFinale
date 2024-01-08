
#ifndef PROVAFINALE_BOARDBOX_H
#define PROVAFINALE_BOARDBOX_H

class BoardBox{

    public:
        virtual int getType();
        virtual int getHouseType();
        virtual int getPrice();
    protected:
        BoardBox(int price, int type);
        int boxType;

    int houseType = 0;
protected:
        int price;

};

#endif //PROVAFINALE_BOARDBOX_H
