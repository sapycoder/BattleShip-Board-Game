#ifndef BOARD_H
#define BOARD_H
#pragma once
#include<bits/stdc++.h>
using namespace std;

class Board
{
private:
    int rows;
    int cols;
    vector<vector<string>> board1;
    vector<vector<string>> board2;
protected:

public:
    Board(int pRows, int pCols);
    void displayBoard1();
    void displayBoard2();
    bool placeShipOnBoard1(int pRow, int pCol);
    bool placeShipOnBoard2(int pRow, int pCol);
    bool placeBombOnBoard1(int pRow, int pCol);
    bool placeBombOnBoard2(int pRow, int pCol);  
    ~Board();

};

#endif