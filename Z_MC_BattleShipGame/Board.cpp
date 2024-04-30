#include "Board.h"
#include<bits/stdc++.h>
using namespace std;

Board::Board(int pRows, int pCols) : 
rows(pRows), 
cols(pCols), 
board1(pRows, vector<string> (pCols," ꩜ ")), 
board2(pRows, vector<string> (pCols," ꩜ "))
{}

void Board::displayBoard1(){
    for(int i=0;i<rows;i++){
        if(i!=0) cout<<"--------------------"<<endl;
        for(int j=0;j<cols;j++){
            cout<<board1[i][j];
            if(j!=cols-1)cout<<" | ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void Board::displayBoard2(){
    for(int i=0;i<rows;i++){
        if(i!=0) cout<<"--------------------"<<endl;
        for(int j=0;j<cols;j++){
            cout<<board2[i][j];
            if(j!=cols-1)cout<<" | ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool Board::placeShipOnBoard1(int pRow, int pCol){
    if(pRow<0 || pRow>=rows || pCol<0 || pCol>=cols){
        cout<<"Invalid Position. Please try again!"<<endl;
        return false;
    }
    else if(board1[pRow][pCol] == " ⏅ "){
        cout<<"Ship already placed at this position!"<<endl;
        return false;
    }
    board1[pRow][pCol] = " ⏅ "; //'o' signifies a ship on board 1
    return true;
}

bool Board::placeShipOnBoard2(int pRow, int pCol){
    if(pRow<0 || pRow>=rows || pCol<0 || pCol>=cols){
        cout<<"Invalid Position. Please try again!"<<endl;
        return false;
    }
    else if(board2[pRow][pCol] == " ⏅ "){
        cout<<"Ship already placed at this position!"<<endl;
        return false;
    }
    board2[pRow][pCol] = " ⏅ "; //'o' signifies a ship on board 2
    return true;
}

bool Board::placeBombOnBoard1(int pRow, int pCol){
    if(pRow<0 || pRow>=rows || pCol<0 || pCol>=cols || board1[pRow][pCol]==" ꩜ "){
        cout<<"It was a miss!"<<endl;
        return false;
    }
    cout<<"It was a hit!"<<endl;
    board1[pRow][pCol] = " ꩜ "; //'^' signifies a ship on board 1 was hitted, replaced by water
    return true;
}
bool Board::placeBombOnBoard2(int pRow, int pCol){
    if(pRow<0 || pRow>=rows || pCol<0 || pCol>=cols || board2[pRow][pCol]==" ꩜ "){
        cout<<"It was a miss!"<<endl;
        return false;
    }
    cout<<"It was a hit!"<<endl;
    board2[pRow][pCol] = " ꩜ "; //'^' signifies a ship on board 2 was hitted, replaced by water
    return true;
}
Board::~Board()
{

}