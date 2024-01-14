
#ifndef PROVAFINALE_BOARD_H
#define PROVAFINALE_BOARD_H

#include "BoardBox.h"
#include "Player.h"
#include <initializer_list>

//Classe Board: Rappresenta la scacchiera di gioco e ne gestisce la logica

class Board{
public:
    /* Costruttore di Board:
     * in: -int gameType, definisce il tipo di partita: assume valore 1 se è tra quattro Computer, assume valore 2 se è tra tre Computer e un Umano
     * */
    Board(int gameType);
    /* move:
     * Fa tirare i dadi al giocatore del turno attuale, lo sposta tra le caselle del tabellone e
     * invoca la funzione action della casella in cui si è fermato il giocatore.
     * Gestisce il ritiro dei 20 fiorini al passaggio dalla Partenza.
     * Gestisce l'eliminazione di un giocatore dalla partita nel caso termini i soldi.
     * */
    void move();
    /* endedGame:
     * out: True se la partita è terminata, False altrimenti.
     * Gestisce il controllo dell'effettiva terminazione di una partita controllando se è stato raggiunto il numero massimo di turni fissato nelle partite tra quattro Computer
     * o se rimane un solo giocatore attivo.
     * */
    bool endedGame();
    /* addPlayer:
     * in: std::initializer_list<Player*> contenente i giocatori della partita attuale
     * Salva in 'Player* listPlayer[4]' di Board i giocatori della partita attuale.
     * */
    void addPlayer(std::initializer_list<Player*>);
    /* getLength:
     * out: Lunghezza di 'BoardBox* listBox[28];' ovvero il numero di caselle del tabellone
     * Permette di conoscere il numero di caselle del tabellone.
     * */
    int getLength();
    /* show:
     * Permette di visualizzare il tabellone di gioco secondo le specifiche fornite in fase di progettazione.
     * */
    void show();
    /* deletePlayer:
     * in: 'Player* actualPlayer', giocatore da eliminare dalla partita.
     * Rimette in vendita le proprietà possedute dal giocatore da eliminare ed esclude il giocatore dalla possibilità di giocare nei turni successivi.
     */
    void deletePlayer(Player* actualPlayer);
    /* nextPlayerRound:
     * Incrementa 'int playerRound', variabile utilizzata per accedere ad ogni turno al giocatore interessato.
     * Essendo playerRound utilizzata come indice per accedere a listPlayer può assumere valori tra 0 e il numero di giocatori attivi - 1.
     */
    void nextPlayerRound();

private:
    //salva in Board il tipo di partita scelto: assume valore 1 se è tra quattro Computer, assume valore 2 se è tra tre Computer e un Umano
    int gameMode;
    //numero massimo di round per partite tra quattro Computer
    int maxRounds = 30;
    //utilizzata come indice permette di recuperare da listPlayer il giocatore del turno attuale, identificato da playerRound
    int playerRound = 0;
    //array contenente le caselle che compongono il tabellone
    BoardBox* listBox[28];
    //array contenente i giocatori della partita ordinati in modo decrescente rispetto al valore dei dadi lanciati da ciascuno prima dell'inizio della partita
    Player* listPlayer[4];
    //array contenente le posizioni nel tabellone dei giocatori della partita ordinate in modo decrescente rispetto al valore dei dadi lanciati da ciascuno prima dell'inizio della partita
    int listPosition[4] = {};
    //numero di giocatori attivi nella partita
    int activePlayers=4;
    //flag usato da endedGame in partite tra quattro Computer per terminare il gioco prima di controllare se ci sono più di un giocatore vivi
    bool exit=false;
    //accredito ad ogni giro
    int completeTurnPrize = 2;

    /* assignBoxType:
     * Dispone in modo casuale le caselle nel tabellone.
     * Le caselle vengono inserite in 'BoardBox* listBox[28]'
     * */
    void assignBoxType();
    /* setPlayersOrder:
     * in: 'Player* p, Player* pp, Player* ppp, Player* pppp', i quattro giocatori della partita arttuale
     * Permette ai giocatori di tirare i dadi per determinare l'ordine di gioco tra i giocatori e li inserisce in modo ordinato decrescente rispetto al numero dei dadi in listPlayer.
     * In caso di lanci uguali tra giocatori si prosegue finchè non escono valori diversi per poi rideterminare il nuovo ordine di gioco.
     */
    void setPlayersOrder(Player* p, Player* pp, Player* ppp, Player* pppp);
    /* passedRound:
     * Decrementa il numero di turni utili in partite tra quattro Computer, nel caso in cui sia raggiunto il limite imposta il flag
     * exit=true in modo da provocare la terminazione della partita indipendentemente dal numero di giocatori attivi alla successiva chiamata di endedGame.
     */
    void passedRound();
};

#endif //PROVAFINALE_BOARD_H