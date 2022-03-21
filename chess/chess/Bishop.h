/** @file  */

/*
Computer Programming
Chess
*/

#ifndef BISHOP_H
#define BISHOP_H

#include <iostream>
#include <vector>
#include "Pieces.h"
using namespace std;

/** Class for Bishop */
class Bishop : public Pieces
{
public:
    /**Constructor
    @param color color of the piece*/
    Bishop(int color);

    /**Get all possible moves
       @param Cells the whole chessboard
       @param x x positon of the piece
       @param y y position o fthe piece
       @param flag if get moves to move or get moves to set attack
       @return vector with all possible moves*/
    vector<Square> getMoves(vector<vector<Square>>& cells, int x, int y, int flag);

    /** Texture for black Bishop*/
    sf::Texture blackBishop;

    /** Texture for white bishop*/
    sf::Texture whiteBishop;

    /**Destructor*/
    ~Bishop() {};

protected:
private:
};

#endif // BISHOP_H
