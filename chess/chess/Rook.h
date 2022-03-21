/** @file  */

/*
Computer Programming
Chess
*/
#ifndef ROOK_H
#define ROOK_H
#include "Pieces.h"
#include <vector>
using namespace std;


/**Class for Rook*/
class Rook : public Pieces
{
public:

	/**Constructor
 @param color of the rook*/
  Rook(int);

  /**Get all possible moves
  @param Cells the whole chessboard
  @param x x positon of the piece
  @param y y position o fthe piece
  @param flag if get moves to move or get moves to set attack
  @return vector with all possible moves*/
  vector<Square> getMoves(vector<vector<Square>>& cells, int x, int y, int flag);

  /**texture for black rook*/
  sf::Texture blackRook;

  /**texture for white rook*/
  sf::Texture whiteRook;

  /**Destructor*/
  ~Rook() {};

protected:
private:
};

#endif // ROOK_H
