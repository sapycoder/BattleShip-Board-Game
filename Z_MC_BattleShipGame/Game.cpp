#include "Game.h"
#include "Board.h"
#include<bits/stdc++.h>
using namespace std;

Game::Game(int pRows,int pCols,int pNumberOfShips, string pPlayerName1, string pPlayerName2) :
 rows(pRows), cols(pCols), 
 numberOfShipsLeftForPlayer1(pNumberOfShips),numberOfShipsLeftForPlayer2(pNumberOfShips),
 playerName1(pPlayerName1), playerName2(pPlayerName2), 
 board1(pRows, pCols), board2(pRows,pCols),
 isGameOver(false),
 currentPlayer(&playerName1)
{}

void Game::startGame(){
    cout<<"---------------------******* WELCOME TO BATTLE SHIP ARENA *******---------------------"<<endl<<endl;

    //Place Ships for Players
    _fillShipsForPlayer(playerName1, board1);
    _fillShipsForPlayer(playerName2, board2);

    while(!isGameOver){
        _playerTurn();
    }
    cout<<endl<<endl<<"---------------------------------******** ********* ********--------------------------------"<<endl<<endl;
    cout<<endl<<"\t\t\t\t\t"<<*currentPlayer<<" Wins!!!!"<<endl<<endl;
    cout<<endl<<endl<<"---------------------------------******** GAME OVER ********--------------------------------"<<endl<<endl;

}

void Game:: _fillShipsForPlayer(string pPlayerName, Board &board){
    cout<<pPlayerName<<", Enter the postion (row,col) you want to place your ships:"<<endl;
    int i=0, row, col;
    
    // Place Battle Ships for Player 1
    if(pPlayerName == playerName1){
        while(i<numberOfShipsLeftForPlayer1){
            cin>>row>>col;
            if(board.placeShipOnBoard1(row,col)){ //If correct position
                i++;
            }
            board.displayBoard1();
        }
    }

    // Place Battle Ships for Player 2
    if(pPlayerName == playerName2){
        while(i<numberOfShipsLeftForPlayer2){
            cin>>row>>col;
            if(board.placeShipOnBoard2(row,col)){ //If correct position
                i++;
            }
            board.displayBoard2();
        }
    }
}

void Game :: _playerTurn(){
    int row,col;
    cout<<*currentPlayer<<", Enter the attack position on opponent's board: ";
    cin>>row>>col;
    if(currentPlayer == &playerName1){
        if(board2.placeBombOnBoard2(row,col)){
            numberOfShipsLeftForPlayer2--; //If the ship was hit, decrease the count of ship on board2
        }
        //Check if all oppnent ships are destroyed
        if(numberOfShipsLeftForPlayer2==0){
            isGameOver = true;
            return;
        }
        board2.displayBoard2();
        //If above condition is true we dont change the current player as this player will be Winner
        currentPlayer = &playerName2; //Replace the current ship to other ship
    }
    else{
        if(board1.placeBombOnBoard1(row,col)){
            numberOfShipsLeftForPlayer1--; //If the ship was hit, decrease the count of ship on board2
        }
        //Check if all oppnent ships are destroyed
        if(numberOfShipsLeftForPlayer1==0){
            isGameOver = true;
            return;
        }
        board1.displayBoard1();
        //If above condition is true we dont change the current player as this player will be Winner
        currentPlayer = &playerName1; //Replace the current ship to other ship
    }

}
Game::~Game()
{

}