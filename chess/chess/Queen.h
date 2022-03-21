/** @file  */

/*
Computer Programming
Chess
*/

#ifndef QUEEN_H
#define QUEEN_H

#include <vector>
#include "Pieces.h"

using namespace std;

/**Class for Queen*/
class Queen : public Pieces
{
public:

    /**Constructor
  @param color of the queen*/
    Queen(int);

    /**Get all possible moves
   @param Cells the whole chessboard
   @param x x positon of the piece
   @param y y position o fthe piece
   @param flag if get moves to move or get moves to set attack
   @return vector with all possible moves*/
    vector<Square> getMoves(vector<vector<Square>>& cells, int x, int y, int flag);

    /**texture for black queen*/
    sf::Texture blackQueen;

    /**texture for white queen*/
    sf::Texture whiteQueen;

    /**destructor*/
    ~Queen() {};

protected:
private:
};

#endif // QUEEN_H