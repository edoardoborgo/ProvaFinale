
#ifndef PROVAFINALE_BOARDBOXBLANK_H
#define PROVAFINALE_BOARDBOXBLANK_H

#include "BoardBox.h"

class BoardBoxBlank : public BoardBox{

public:
    BoardBoxBlank();
    BoardBoxBlank(char typeCharacter_);
    std::string getBoxType() override;
    char getTypeCharacter() override;
    void action(Player* actualPlayer) override;
    void eraseOwner() override;
    Player* getOwner() override;
    std::string toString() override;

protected:

private:

};

#endif //PROVAFINALE_BOARDBOXBLANK_H