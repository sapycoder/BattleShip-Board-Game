#include<bits/stdc++.h>
#include "Game.h"
using namespace std;

bool checkMaxShipsCriteriaFulfilled(int &numberOfShips, int &rows, int &cols){
    int minimum = 1, maximum = (rows*cols)-1;
    if(numberOfShips<minimum || numberOfShips>maximum){
        cout<<"The number of ships should be in the range of [ "<<minimum<<", "<<maximum<<" ] Please try again!"<<endl;
        return false;
    }
    return true;
}
int main(){

    int rows,cols; 
    cout<<"Enter the height of the Battle Board: ";
    cin>>rows;
    cout<<"Enter the width of the Battle Board: ";
    cin>>cols;

    int numberOfShips; // Max Nmber of ships can be [Minimum: 0,  Maximum: Rows * Columns]
    cout<<"Enter the maximum number of ships you want to place on Battle Board: ";
    cin>>numberOfShips;
    while(!checkMaxShipsCriteriaFulfilled(numberOfShips, rows, cols)){
        cin>>numberOfShips;
        cout<<endl;
    }

    string playerName1,playerName2;
    cout<<endl<<"Player 1, Enter your name: ";
    cin>>playerName1;
    cout<<endl<<"Player 2, Enter your name: ";
    cin>>playerName2;
    cout<<endl;
    transform(playerName1.begin(), playerName1.end(), playerName1.begin(), ::toupper);
    transform(playerName2.begin(), playerName2.end(), playerName2.begin(), ::toupper);

    Game game(rows, cols, numberOfShips, playerName1, playerName2);
    game.startGame();

    return 0;
}