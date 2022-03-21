/** @file  */

/*
Computer Programming
Chess
*/


#ifndef KNIGHT_H
#define KNIGHT_H

#include <vector>
#include "Square.h"
#include "Pieces.h"
using namespace std;

/**Class for Knight*/
class Knight : public Pieces
{
public:
    /**Constructor
@param color of the knight*/
    Knight(int);

    /**Get all possible moves
    @param Cells the whole chessboard
    @param x x positon of the piece
    @param y y position o fthe piece
    @param flag if get moves to move or get moves to set attack
    @return vector with all possible moves*/
    vector<Square> getMoves(vector<vector<Square>>& Cells, int x, int y, int flag);

    /**texture for white knight*/
    sf::Texture whiteKnight;

    /**texture for black knight*/
    sf::Texture blackKnight;

    /**destructor*/
    ~Knight() {};

protected:
private:
};

#endif // KNIGHT_H
