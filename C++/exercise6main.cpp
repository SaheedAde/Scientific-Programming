#include "matrix.hpp"
#include "matrix.cpp"
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
  // Takes values to use for 2 players
  cout << "As convention, player 1 take the value 1 and player 2 take the value 2" << endl;
  int p1;
  int p2;
  cout << "Player 1 avatar" << endl;
  cin >> p1;
  assert(p1 == 1);
  cout << "Player 2 avatar" << endl;
  cin >> p2;
  assert(p2 == 2);

  // Create a game board for the players: a 3-by-3 populated matrix filled with zeros
  Matrix gameBoard(3,'F',0);
  int k1;
  int k2;
  int move = 1;     // to create an infinite loop that will terminate on condition

  while (move) {
    // Display play field
    gameBoard.printMatrix();

    //Player 1 move
    cout << "Player 1: Enter a point: ";
    cin >> k1;
    assert(gameBoard.getMatrix(k1) == 0);
    gameBoard.setMatrix(k1, p1);

    //Player 2 move
    cout << "Player 2: Enter a point: ";
    cin >> k2;
    assert(gameBoard.getMatrix(k2) == 0);
    gameBoard.setMatrix(k2, p2);
   }

   // Check for  winner
   if ((gameBoard.columnSumNorm() == 3*p1) || (gameBoard.rowSumNorm() == 3*p1) || (gameBoard.trace() == 3*p1)) {
     cout << "Player 1 wins\n";
     move = 0;
   }
   else if ((gameBoard.columnSumNorm() == 3*p2) || (gameBoard.rowSumNorm() == 3*p2) || (gameBoard.trace() == 3*p2)) {
     cout << "Player 2 wins\n";
     move = 0;
   }

   // check for a tie
   if (gameBoard.frobeniusNorm() != 0 && move ==1) {
     cout << "Tied game\n";
     move = 0;
   }

   return 0;
}
