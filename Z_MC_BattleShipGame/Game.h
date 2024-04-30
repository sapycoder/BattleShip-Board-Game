#ifndef GAME_H
#define GAME_H
#pragma once
#include<bits/stdc++.h>
#include "Board.h"
using namespace std;

class Game
{
private:
    int rows;
    int cols;
    int numberOfShipsLeftForPlayer1;
    int numberOfShipsLeftForPlayer2;
    string playerName1;
    string playerName2;
    Board board1;
    Board board2;
    bool isGameOver;
    string *currentPlayer;

protected:

public:
    Game(int pRows, int pCols,int pNumberOfShips, string pPlayerName1, string pPlayerName2);
    void startGame();
    void _fillShipsForPlayer(string playerName, Board &board);
    void _playerTurn();
    ~Game();

};

#endif