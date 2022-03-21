/** @file  */

/*
Computer Programming
Chess
*/


#ifndef PIECES_H
#define PIECES_H

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Square.h"
#include"Variables.h"
using namespace std;


/**Class for all pieces, they inheri everything from this class*/
class Pieces 
{
    

public:
  
    /**vector if all possible moves of a piece*/
    vector<Square> possibleMoves;

    /**Get all possible moves
      @param Cells the whole chessboard
      @param x x positon of the piece
      @param y y position o fthe piece
      @param flag if get moves to move or get moves to set attack
      @return vector with all possible moves*/
    virtual vector<Square> getMoves(vector<vector<Square>>& Cells, int x, int y, int flag) = 0;

    /**x and y parameters of a piece*/
    int x, y;

    /**true if a piece is alive*/
    bool isAlive;

    /**true if a piece is white*/
    bool isWhite;

    /**what color the piece has*/
    bool occupied_color;

    /**what kinf of piece it is*/
    int occupied_value;

    /**true if the piece attacks a king*/
    bool is_attacker;

    /**sprite of that piece*/
    sf::Sprite piece;
};

#endif