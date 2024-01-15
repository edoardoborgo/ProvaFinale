#include "../include/Board.h"
#include "../include/BoardBoxProperty.h"
#include "../include/BoardBoxBlank.h"
#include "../include/BoardManager.h"
#include "../include/Pc.h"
#include "../include/Human.h"
#include "../include/GlobalLogger.h"
#include <algorithm>
#include <iostream>
#include <initializer_list>
#include <random>
#include <sstream>

Board::Board(int gameType){
    //creazione di tre Computer che sono presenti in ogni partita indipendentemente dalla modalità di gioco scelta
    Player* p = new Pc(1);
    Player* pp = new Pc(2);
    Player* ppp = new Pc(3);
    Player* pppp;

    //dipendentemente dalla modalità scelta il quarto giocatore può essere un Computer o un Giocatore umano
    if(gameType == 1){
        pppp = new Pc(4);
        gameMode = 1;
    } else if( gameType == 2){
        pppp = new Human(4);
        gameMode = 2;
    }

    //lancio dei dadi per determinare l'ordine di gioco e inserire i giocatori in modo ordinato in listPlayer
    setPlayersOrder(p, pp, ppp, pppp);
    //disposizione in modo casuale delle caselle nel tabellone
    assignBoxType();
}

void Board::move(){
    //recupero il giocatore del turno attuale accedendo a listPlayer tramite playerRound, indice che varia tra 0 e activePlayers-1
    //Il giocatore attuale tira i dadi.
    int shift = listPlayer[playerRound]->throwDices();
    //recupero la posizione nel tabellone del giocatore del turno attuale accedendo a listPosition tramite playerRound
    int actualPosition = listPosition[playerRound];

    //gestione del passaggio dalla casella di Partenza con conseguente addebito di 20 fiorini
    int newPosition;
    try{
        newPosition = movePlayer(actualPosition, shift);
    }catch(completeTurnException& e){
        newPosition = e.getNewPosition();
        //accredito di 20 fiorini al giocatore attuale
        listPlayer[playerRound]->deposit(completeTurnPrize);
        //stampa a console i dettagli del turno attuale, log 1
        std::stringstream msg;
        msg<<"Giocatore "<<listPlayer[playerRound]->getPlayerNumber()<<" e' passato dal via e ha ritirato "<<completeTurnPrize<<" fiorini"<<std::endl;
        std::cout<<msg.str();
        //stampa su file i dettagli del turno attuale, log F1
        logger.log(msg.str());
    }
    //aggiorno la posizione nel tabellone del giocatore attuale
    listPosition[playerRound]=newPosition;
    //aggiorno la posizione del giocatore
    listPlayer[playerRound]->setPosition(newPosition);

    //stampa a console i dettagli del turno attuale, log 3
    std::stringstream msg;
    msg<<"Giocatore "<<listPlayer[playerRound]->getPlayerNumber()<<" e' arrivato alla casella "<<(newPosition+1)<<std::endl;
    std::cout<<msg.str();
    //stampa su file i dettagli del turno attuale, log F3
    logger.log(msg.str());

    //interrompe il turno se un giocatore finisce i fiorini, eccezione sollevata da withdraw nel momento in cui il giocatore attuale deve pagare l'affitto ad un altro giocatore non avendo abbastanza soldi
    try{
        //se la casella è di tipo 'blank' viene eseguito il metodo action vuoto, se è di tipo 'property' viene eseguito il metodo action che gestisce le meccaniche di gioco
        listBox[listPosition[playerRound]]->action(listPlayer[playerRound]);
    }catch(outOfMoneyException& e){
        //actualPlayer ha terminato i fiorini
        deletePlayer(listPlayer[playerRound]);
    }catch(showRequestException& e){
        show();
        listBox[listPosition[playerRound]]->action(listPlayer[playerRound]);
    }

    //stampa a console i dettagli del turno attuale
    std::cout<<"Fiorini: "<<listPlayer[playerRound]->getMoney()<<" giocatore numero: "<<listPlayer[playerRound]->getPlayerNumber()<<" mossa numero: "<<maxRounds;

    //passedRound per decrementare il numero di turni utili solo nelle partite tra quattro Computer, cioè gameMode=1
    if(gameMode==1){
        passedRound();
    }


    std::cout<<std::endl;
    //stampa a console i dettagli del turno attuale, log 8
    msg << "Giocatore " << listPlayer[playerRound]->getPlayerNumber() << " ha finito il turno"<<std::endl;
    std::cout<<msg.str();
    //stampa su file i dettagli del turno attuale, log F8
    logger.log(msg.str());
}


void Board::show() {
    //stampa output tabellone

    //intestazione riga tabellone
    std::cout << "\t 1\t 2\t 3\t 4\t 5\t 6\t 7\t 8\nA";

    //stampa caselle della riga orizzontale in alto
    for(int i=0;i<8;i++){
        std::cout << "\t|" << listBox[i]->toString();
        for(int j=0;j<activePlayers;j++){
            if(listPosition[j] == i){
                //stampa del numero del giocatore
                std::cout << listPlayer[j]->getPlayerNumber();
            }
        }
        std::cout << '|';
    }

    //stampa delle righe centrali
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

    //stampa caselle della riga orizzontale in basso
    std::cout << std::endl << "H";
    for(int i=21;i>=14;i--){
        std::cout << "\t|" << listBox[i]->toString();
        for(int j=0;j<activePlayers;j++){
            if(listPosition[j] == i){
                //stampa del numero del giocatore
                std::cout << listPlayer[j]->getPlayerNumber();
            }
        }
        std::cout << "|";
    }
    std::cout << std::endl;

    std::cout << "Lista case/alberghi di ciascun giocatore: " << std::endl;
    for(int i=0;i<activePlayers;i++){
        std::vector<int> boxPositionAlbergo;
        std::vector<int> boxPositionCasa;
        for(int j=0; j<getLength(); j++){
            if(listBox[j]->getOwner()==listPlayer[i]){
                if(listBox[j]->getPropertyLevel()==2)
                    boxPositionCasa.push_back(j);
                if(listBox[j]->getPropertyLevel()==3)
                    boxPositionAlbergo.push_back(j);
            }
        }
        std::cout << "Giocatore "<< listPlayer[i]->getPlayerNumber() << ": ";
        for(int j=0; j<boxPositionAlbergo.capacity(); j++)
            std::cout << getLetter(boxPositionAlbergo[j]+1) << getNumber(boxPositionAlbergo[j]+1) << " ";
        for(int j=0; j<boxPositionCasa.capacity(); j++)
            std::cout << getLetter(boxPositionCasa[j]+1) << getNumber(boxPositionCasa[j]+1) << " ";
        std::cout<<std::endl;
    }

    std::cout << "Fiorini posseduti da ciascun giocatore: " << std::endl;
    for(int i=0;i<activePlayers;i++){
        std::cout << "Giocatore " << listPlayer[i]->getPlayerNumber() << ": " << listPlayer[i]->getMoney() << std::endl;
    }
}

void Board::deletePlayer(Player* actualPlayer){
    //reset delle caselle possedute dal giocatore eliminato
    for(int i=0; i<28; i++){
        if(listBox[i]->getOwner()==actualPlayer)
            listBox[i]->eraseOwner();
    }

    //modifica dell'array contenente i giocatori della partita attuale
    //il giocatore eliminato viene portato alla fine dell'array, le prime posizioni sono quindi occupate dai giocatori ancora vivi
    //le ultime celle di listPlayer non vengono più utilizzate dato che playerRound assume come massimo valore activePLayers-1
    Player* appoPlayer = listPlayer[playerRound];
    for(int i=playerRound; i<4-1-(4-activePlayers); i++){
        listPlayer[i]=listPlayer[i+1];
    }
    listPlayer[3-(4-activePlayers)] = appoPlayer;

    //modifica dell'array contenente le posizioni dei giocatori della partita attuale
    //la posizione del giocatore eliminato viene portata alla fine dell'array, le prime posizioni sono quindi occupate dai giocatori ancora vivi
    //le ultime celle di listPosition non vengono più utilizzate dato che playerRound assume come massimo valore actualPLayers-1
    int appoPosition = listPosition[playerRound];
    for(int i=playerRound; i<4-1-(4-activePlayers); i++){
        listPosition[i]=listPosition[i+1];
    }
    listPosition[3-(4-activePlayers)] = appoPosition;

    //decremento playerRound per non far perdere il turno al giocatore successivo al giocatore eliminato dato che nell'array listPlayer vengono scambiati di posto
    playerRound--;
    //decremento il numero di giocatori attivi
    activePlayers--;

    //stampa a console i dettagli del turno attuale, log 9
    std::stringstream msg;
    msg << "Giocatore " << actualPlayer->getPlayerNumber() << " e' stato eliminato"<<std::endl;
    std::cout << msg.str();
    //stampa su file i dettagli del turno attuale, log F9
    logger.log(msg.str());
}

void Board::nextPlayerRound(){
    //aggiorna l'indice del giocatore del turno attuale
    playerRound = (playerRound+1)%activePlayers;
}

void Board::assignBoxType(){
    //creo le caselle, ancora prive di tipo
    for(int i=0; i<28; i++){
        listBox[i]= new BoardBox();
    }

    //assegnazione delle caselle angolari
    //una casella Partenza
    listBox[0] = new BoardBoxBlank('P');
    //tre caselle Vuote
    listBox[7] = new BoardBoxBlank(' ');
    listBox[14] = new BoardBoxBlank(' ');
    listBox[21] = new BoardBoxBlank(' ');

    //generazione numero casuale in [1, 27], non considero indice 0 perché ha già un tipo assegnato (casella di partenza)
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> distLength(1,getLength()-1);

    int randomIndex;

    //assegnazione di 8 caselle economiche
    for(int i=0;i<8;i++){
        //genero un nuovo indice se quello precedentemente generato è già occupato da una casella
        do{
            randomIndex = distLength(rng);
        }while(listBox[randomIndex]->getBoxType() != "");

        //assegnazione casella di tipo economico
        listBox[randomIndex] = new BoardBoxProperty('E',6,3,3,2,4);

    }

    //assegnazione di 10 caselle standard
    for(int i=0;i<10;i++){
        //genero un nuovo indice se quello precedentemente generato è già occupato da una casella
        do{
            randomIndex = distLength(rng);
        }while(listBox[randomIndex]->getBoxType() != "");

        //assegnazione casella di tipo standard
        listBox[randomIndex] = new BoardBoxProperty('S',10, 5, 5, 4, 8);

    }

    //assegnazione di 6 caselle lusso
    for(int i=0;i<6;i++){
        //genero un nuovo indice se quello precedentemente generato è già occupato da una casella
        do{
            randomIndex = distLength(rng);
        }while(listBox[randomIndex]->getBoxType() != "");

        //assegnazione casella di tipo lusso
        listBox[randomIndex] = new BoardBoxProperty('L',20,10,10,7,14);

    }
}

void Board::setPlayersOrder(Player* p, Player* pp, Player* ppp, Player* pppp){
    //array utilizzato per salvare il valore dei dadi lanciati da ciascun giocatore
    int arrD[4];

    Player* arrP[]= {p,pp,ppp,pppp};

    //stampa a console i dettagli del turno attuale
    std::cout << "I giocatori tirano i dadi per decidere l'ordine di gioco:" << std::endl;

    //lancio dei dadi per ogni giocatore
    for(int i=0; i<4; i++){
        arrD[i] = arrP[i]->throwDices();
    }

    //ricerca di eventuali valori uguali tra i lanci
    int vSize=0;
    do{
        std::vector<int> index;
        index.clear();
        vSize=0;

        for (int i = 0; i < 3; ++i) {
            for (int j = i + 1; j < 4; ++j) {
                if (arrD[i] == arrD[j]) {
                    //gli elementi sono uguali, registra gli indici
                    auto trovato = std::find(index.begin(), index.end(), arrD[i]);
                    //verifica se l'elemento è stato trovato
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
            //stampa a console i dettagli del turno attuale
            std::cout << "I giocatori ";
            for(int i=0; i<index.capacity(); i++){
                std::cout << arrP[index[i]]->getPlayerNumber() << ", ";
            }
            std::cout << " hanno ottenuto lo stesso numero, quindi ritirano i dadi" << std::endl;
            //eventuali valori uguali tra due o più giocatori con conseguente rilancio dei dadi per i giocatori interessati
            for(int i=0; i<index.capacity(); i++){
                arrD[index[i]] = arrP[index[i]]->throwDices();
            }
        }
    }while (vSize != 0);

    //ordinamento dei valori per determinare l'ordine di gioco
    for (int i = 0; i < 4 - 1; ++i) {
        for (int j = 0; j < 4 - i - 1; ++j) {
            if (arrD[j] < arrD[j + 1]) {
                // Scambia gli elementi se non sono in ordine
                std::swap(arrD[j], arrD[j + 1]);
                std::swap(arrP[j], arrP[j + 1]);
            }
        }
    }

    //inserisco i giocatori nell'array di giocatori secondo l'ordine appena determinato
    addPlayer({arrP[0], arrP[1], arrP[2], arrP[3]});
}

void Board::addPlayer(std::initializer_list<Player*> lst){
    //Salva in listPlayer i giocatori della partita attuale
    std::copy(lst.begin(), lst.end(), listPlayer);
}

int Board::getLength() {
    return sizeof(listBox) / sizeof(listBox[0]);
}

void Board::passedRound(){
    //Decrementa il numero di turni utili in partite tra quattro Computer, nel caso in cui sia raggiunto il limite imposta il flag exit=true in modo da provocare la terminazione della partita indipendentemente dal numero di giocatori attivi alla successiva chiamata di endedGame
    if(maxRounds>=1)
        maxRounds--;
    else
        exit=true;
}

bool Board::endedGame(){
    //partite tra quattro Computer, nel caso di partite tra quattro computer controllo se ci sono altri turni utili o se è stato raggiunto il limite utilizzando il flag exit
    //exit=true mi indica che il gioco ha raggiunto il numero massimo di turni quindi restituisco endedGame=true, cioè gioco finito
    if(gameMode==1 && exit){
        int fiorini[activePlayers];
        for(int i=0; i<activePlayers; i++)
            fiorini[i]=listPlayer[i]->getMoney();
        int maxFiorini = fiorini[0];
        for(int i=1; i<activePlayers; i++){
            if(fiorini[i]>maxFiorini)
                maxFiorini=fiorini[i];
        }
        int exEquo=0;
        for(int i=0; i<activePlayers; i++){
            if(maxFiorini == fiorini[i])
                exEquo++;
        }
        std::stringstream msg;
        if(exEquo!=1){
            //stampa a console i dettagli del turno attuale, log 10
            msg << "Giocatori ";
            for(int i=0; i<activePlayers; i++){
                if(fiorini[i]==maxFiorini)
                    msg << listPlayer[i]->getPlayerNumber() << " ";
            }
            msg <<" hanno vinto la partita" << std::endl;
        }else{
            //stampa a console i dettagli del turno attuale, log 10
            msg << "Giocatore ";
            for(int i=0; i<activePlayers; i++){
                if(fiorini[i]==maxFiorini)
                    msg << listPlayer[i]->getPlayerNumber() << " ";
            }
            msg<<" ha vinto la partita" << std::endl;
        }
        std::cout << msg.str();
        //stampa su file i dettagli del turno attuale, log F10
        logger.log(msg.str());

        return true;
    }

    //se il numero massimo di turni non è stato raggiunto controllo che ci siano abbastanza giocatori vivi per proseguire la partita
    if(activePlayers==1){
        //stampa a console i dettagli del turno attuale, log 10
        std::stringstream msg;
        msg << "Giocatore " << listPlayer[0]->getPlayerNumber() << " ha vinto la partita" << std::endl;
        std::cout<<msg.str();
        //stampa su file i dettagli del turno attuale, log F10
        logger.log(msg.str());

        return true;
    }else{
        return false;
    }
}