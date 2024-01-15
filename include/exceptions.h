
#ifndef TESTCIRCULARARRAY_EXCEPTIONS_H
#define TESTCIRCULARARRAY_EXCEPTIONS_H

#include <exception>
#include "../include/Player.h"
#include <string>

/* completeTurnException:
 * Eccezione per gestire l'accredito dei fiorini al passaggio dal via.
 * Salva nell'oggetto eccezione la nuova posizione del giocatore per consentire al chiamante di recuperarla dopo aver gestito l'accredito.
 * Lanciata da BoardManager e gestita da Board.
 */
class completeTurnException : public std::exception{
    public:
        completeTurnException(int newPosition_) : newPosition(newPosition_){};
        int getNewPosition(){return newPosition;}
    private:
        int newPosition;
};

/* outOfMoneyException:
 * Eccezione per notificare al chiamante il termine dei soldi del giocatore del turno attuale.
 * Salva nell'oggetto eccezione il giocatore che è stato eliminato.
 * Lanciata da Player e gestita da Board.
 */
class outOfMoneyException : public std::exception{
    public:
        outOfMoneyException(Player* actualPlayer_) : actualPlayer(actualPlayer_) {};
    private:
    Player* actualPlayer;
};

/* showRequestException:
 * Eccezione per gestire la richiesta di visualizzazione del tabellone e dei suoi dettagli.
 * Lanciata da BoardBoxProperty e gestita da Board.
 */
class showRequestException : public std::exception{
    public:
        showRequestException(){};
    private:
};

/* loggerException:
 * Eccezione per gestire problemi legati alla scrittura su file.
 */
class loggerException : public std::exception{
    public:
        loggerException(std::string msgError_) : msgError(msgError_){};
        std::string getMsgError(){ return msgError; }
    private:
        std::string msgError;
};

#endif //TESTCIRCULARARRAY_EXCEPTIONS_H