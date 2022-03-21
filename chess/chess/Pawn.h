/** @file  */

/*
Computer Programming
Chess
*/


#ifndef PAWN_H
#define PAWN_H

#include <iostream>
#include <vector>
#include "Square.h"
#include "Pieces.h"

/**Class for pawns*/
class Pawn : public Pieces
{
public:

    /**Constructor
    @param color of the pawn*/
    Pawn(int);

    /**Get all possible moves
      @param Cells the whole chessboard
      @param x x positon of the piece
      @param y y position o fthe piece
      @param flag if get moves to move or get moves to set attack
      @return vector with all possible moves*/
    vector<Square> getMoves(vector<vector<Square>>& cells, int x, int y, int flag);

    /**texture for black pawn*/
    sf::Texture blackPawn;

    /**texture for white pawn*/
    sf::Texture whitePawn;
    ~Pawn() {};

protected:
};

#endif // PAWN_H