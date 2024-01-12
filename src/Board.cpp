#include "../include/Board.h"
#include "../include/BoardBoxProperty.h"
#include "../include/BoardBoxBlank.h"
#include "../include/BoardManager.h"
#include "../include/Pc.h"
#include "../include/Human.h"
#include <algorithm>
#include <iostream>
#include <initializer_list>
#include <random>



void Board::move(){
    int shift = listPlayer[playerRound]->throwDices(); //TODO sistemare playerRound
    int actualPosition = listPosition[playerRound];

    int newPosition;
    try{
        newPosition = movePlayer(actualPosition, shift);
    }catch(completeTurn& e){
        newPosition = e.getNewPosition();
        //accredito di 20 fiorini al giocatore attuale
        listPlayer[playerRound]->deposit(5);
    }
    listPosition[playerRound]=newPosition;

    //se 'blank' esegue il metodo action vuoto, se 'property' esegue il metodo action che gestisce le meccaniche di gioco
    //interrompe il turno se un giocatore finisce i soldi, eccezione sollevata da withdraw nel momento in cui bisogna pagare l'affitto ad un altro giocatore
    try{
        listBox[listPosition[playerRound]]->action(listPlayer[playerRound]);
    }catch(outOfMoney& e){
        //actualPlayer ha terminato i soldi
        deletePlayer(listPlayer[playerRound]);
    }

    std::cout<<"Soldi: "<<listPlayer[playerRound]->getMoney()<<" mossa numero: "<<maxRounds<<std::endl;

    //decremento il numero di turni nelle partite tra PC dopo ogni turno
    if(gameMode==1){
        passedRound();
    }
}

void Board::deletePlayer(Player* actualPlayer){
    for(int i=0; i<28; i++){
        if(listBox[i]->getOwner()==actualPlayer)
            listBox[i]->eraseOwner();
    }

    //modificare l'array
    Player* appoPlayer = listPlayer[playerRound];
    for(int i=playerRound; i<3-1-(4-activePlayers); i++){
        listPlayer[i]=listPlayer[i+1];
    }
    listPlayer[3-(4-activePlayers)] = appoPlayer;

    int appoPosition = listPosition[playerRound];
    for(int i=playerRound; i<3-1-(4-activePlayers); i++){
        listPosition[i]=listPosition[i+1];
    }
    listPosition[3-(4-activePlayers)] = appoPosition;
    playerRound--;
    activePlayers--;
    std::cout<<"Eliminato player:"<<actualPlayer->getPlayerNumber()<<std::endl;
}

int Board::getLength() {
    return sizeof(listBox) / sizeof(listBox[0]);
}

//da fare solo se non c'è stato un morto nel turno precedente
void Board::nextPlayerRound(){
    playerRound = (playerRound+1)%activePlayers;
}

Board::Board(int gameType){
    Player* p = new Pc(1);
    Player* pp = new Pc(2);
    Player* ppp = new Pc(3);
    Player* pppp;

    if(gameType == 1){
        pppp = new Pc(4);
        gameMode = 1;

    } else if( gameType == 2){
        pppp = new Human(4);
        gameMode = 2;
    }

    setPlayersOrder(p, pp, ppp, pppp);
    assignBoxType();

}

void Board::setPlayersOrder(Player* p, Player* pp, Player* ppp, Player* pppp){
    int arrD[4];

    Player* arrP[]= {p,pp,ppp,pppp};

    std::cout << "I giocatori tirano i dadi per decidere l'ordine di gioco:" << std::endl;

    for(int i=0; i<4; i++){
        arrD[i] = arrP[i]->throwDices();
    }

    int vSize=0;
    do{
        std::vector<int> index;
        index.clear();
        vSize=0;

        for (int i = 0; i < 3; ++i) {
            for (int j = i + 1; j < 4; ++j) {
                if (arrD[i] == arrD[j]) {
                    // Gli elementi sono uguali, registra gli indici
                    auto trovato = std::find(index.begin(), index.end(), arrD[i]);
                    // Verifica se l'elemento è stato trovato
                    if (trovato == index.end()) {
                        index.push_back(i);
                        vSize++;
                    }
                    trovato = std::find(index.begin(), index.end(), arrD[j]);
                    if (trovato == index.end()) {
                        index.push_back(j);
                        vSize++;
                    }
                }
            }
        }

        if(index.capacity()!=0){
            std::cout << "I giocatori ";
            for(int i=0; i<index.capacity(); i++){
                std::cout << arrP[index[i]]->getPlayerNumber() << ", ";
            }
            std::cout << " hanno ottenuto lo stesso numero, quindi ritirano i dadi" << std::endl;

            for(int i=0; i<index.capacity(); i++){
                arrD[index[i]] = arrP[index[i]]->throwDices();
            }
        }
    }while (vSize != 0);

    for (int i = 0; i < 4 - 1; ++i) {
        for (int j = 0; j < 4 - i - 1; ++j) {
            if (arrD[j] < arrD[j + 1]) {
                // Scambia gli elementi se non sono in ordine
                std::swap(arrD[j], arrD[j + 1]);
                std::swap(arrP[j], arrP[j + 1]);
            }
        }
    }

    addPlayer({arrP[0], arrP[1], arrP[2], arrP[3]});
}

void Board::addPlayer(std::initializer_list<Player*> lst){
    std::copy(lst.begin(), lst.end(), listPlayer);
}

void Board::assignBoxType(){
    for(int i=0; i<28; i++){
        if(i!=0 || i!=7 || i!=14 || i!=21)
            listBox[i]= new BoardBox();
    }

    listBox[0] = new BoardBoxBlank('P');
    listBox[7] = new BoardBoxBlank(' ');
    listBox[14] = new BoardBoxBlank(' ');
    listBox[21] = new BoardBoxBlank(' ');



    //1 std, 2 eco, 3 lusso

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> distLength(1,getLength()-1); // distribution in range [1, 6]

    int randomIndex;
    //assegnazione caselle economiche
    for(int i=0;i<8;i++){
        do{
            randomIndex = distLength(rng);
        }while(listBox[randomIndex]->getBoxType() != "");

        if (/*listBox[randomIndex] == nullptr||*/  listBox[randomIndex]->getBoxType() == ""){      //check che non abbia già un tipo
            listBox[randomIndex] = new BoardBoxProperty('E',6,3,3,2,4);
        }
    }

    //assegnazione caselle standard
    for(int i=0;i<10;i++){
        do{
            randomIndex = distLength(rng);
        }while(listBox[randomIndex]->getBoxType() != "");

        if (/*listBox[randomIndex] == nullptr||*/  listBox[randomIndex]->getBoxType() == "")      //check che non abbia già un tipo
            listBox[randomIndex] = new BoardBoxProperty('S',10, 5, 5, 4, 8);
    }


    //assegnazione caselle lusso
    for(int i=0;i<6;i++){
        do{
            randomIndex = distLength(rng);
        }while(listBox[randomIndex]->getBoxType() != "");
        if (/*listBox[randomIndex] == nullptr||*/  listBox[randomIndex]->getBoxType() == "")      //check che non abbia già un tipo
            listBox[randomIndex] = new BoardBoxProperty('L',20,10,10,7,14);
    }
}

void Board::show() {
    //output prima riga
    std::cout << "\t 1\t 2\t 3\t 4\t 5\t 6\t 7\t 8\nA";

    for(int i=0;i<8;i++){
        std::cout << "\t|" << listBox[i]->toString();
        for(int j=0;j<activePlayers;j++){
            if(listPosition[j] == i)
                std::cout << listPlayer[j]->getPlayerNumber(); //numero giocatore
        }
        std::cout << '|';
    }
    char lineIndex = 'B';
    int leftColumnIndex=27, rightColumnIndex=8;
    for(int i=0;i<6;i++){
        std::cout << std::endl << lineIndex << "\t|" << listBox[leftColumnIndex]->toString();
        for(int j=0;j<activePlayers;j++){
            if(listPosition[j] == leftColumnIndex)
                std::cout << j+1;
        }
        std::cout << "|\t\t\t\t\t\t\t|" << listBox[rightColumnIndex]->toString();
        for(int j=0;j<activePlayers;j++){
            if(listPosition[j] == rightColumnIndex)
                std::cout << listPlayer[j]->getPlayerNumber(); //numero giocatore
        }
        std::cout << "|";
        leftColumnIndex--;
        rightColumnIndex++;
        lineIndex++;
    }

    std::cout << std::endl << "H";
    for(int i=21;i>=14;i--){
        std::cout << "\t|" << listBox[i]->toString();
        for(int j=0;j<activePlayers;j++){
            if(listPosition[j] == i)
                std::cout << listPlayer[j]->getPlayerNumber(); //numero giocatore
        }
        std::cout << "|";
    }
    std::cout << std::endl;


    /*std::cout << "A\t\t|" << listBox[0] << "|\t\t|1|\t\t|2|\t\t|3|\t\t|4|\t\t|5|\t\t|6|\t\t|7|" << std::endl;
    std::cout << "B\t\t|" << listBox[27]->toString() << "|\t\t\t\t\t\t\t\t\t\t\t\t\t|8|\t" << std::endl;
    std::cout << "C\t\t|26|\t\t\t\t\t\t\t\t\t\t\t\t\t|9|\t" << std::endl;
    std::cout << "D\t\t|25|\t\t\t\t\t\t\t\t\t\t\t\t\t|10|\t" << std::endl;
    std::cout << "E\t\t|24|\t\t\t\t\t\t\t\t\t\t\t\t\t|11|\t" << std::endl;
    std::cout << "F\t\t|23|\t\t\t\t\t\t\t\t\t\t\t\t\t|12|\t" << std::endl;
    std::cout << "G\t\t|22|\t\t\t\t\t\t\t\t\t\t\t\t\t|13|\t" << std::endl;
    std::cout << "H\t\t|21|\t|20|\t|19|\t|18|\t|17|\t|16|\t|15|\t|14|" << std::endl;
     */
}

bool Board::endedGame(){
    //partite tra pc, controllo prima se il numero di round è maggiore di zero utilizzando il flag exit
    //exit=true mi indica che il gioco deve terminare quindi restituisco endedGame=true, cioè gioco finito e il while nel main si arresta
    if(gameMode==1 && exit)
        return true;

    std::cout<<"VIVI: "<<activePlayers;

    if(activePlayers==1)
        return true;
    else
        return false;
}

void Board::passedRound(){
    if(maxRounds>=1)
        maxRounds--;
    else
        exit=true;
}