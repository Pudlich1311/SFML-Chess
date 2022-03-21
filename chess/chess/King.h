/** @file  */

/*
Computer Programming
Chess
*/

#ifndef KING_H
#define KING_H

#include <vector>
#include "Square.h"
#include "Pieces.h"

/**Class for king*/
class King : public Pieces
{
public:

    /**Constructor
    @param color of the king*/
    King(int);

    /**check if king is in check
    @param Cells the whole chessboard
    @param x x position of the king
    @param y y position of the king
    @return true if is in check
    @return false if not*/
    bool isCheck(vector<vector<Square>>& Cells, int x, int y);

    /**check if king is in checkmate
    @param Cells the whole chessboard
    @param x x position of the king
    @param y y position of the king
     @return true if is in checkmate
    @return false if not*/
    bool isCheckmate(vector<vector<Square>>& Cells, int x, int y);

    /**Get all possible moves 
    @param Cells the whole chessboard
    @param x x positon of the piece
    @param y y position o fthe piece
    @param flag if get moves to move or get moves to set attack
    @return vector with all possible moves*/
    vector<Square> getMoves(vector<vector<Square>>& Cells, int x, int y, int flag);

    /**Texture fo black king*/
    sf::Texture blackKing;

    /**Trxture for white king*/
    sf::Texture whiteKing;
    ~King() {};

protected:
private:
};

#endif // KING_H