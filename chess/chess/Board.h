/** @file  */

/*
Computer Programming
Chess
*/


#ifndef BOARD_H
#define BOARD_H

#include<algorithm>
#include "Pieces.h"
#include "King.h"
#include "Bishop.h"
#include "Queen.h"
#include "Knight.h"
#include "Pawn.h"
#include "Rook.h"
#include "Variables.h"
#include "HisMov.h"
#include "HisStruct.h"
#include <unordered_map>

/** Class for board, mostly logic */
class Board 
{
    /**This class is a friend to Game*/
    friend class Game;

   
public:
   
    /**Constructor*/
    Board() {};

    /**Function to set the texture of the piece to a new position
    @param pieces piece that is moved*/
    template<typename Y>
    void set(Y* pieces);


    /**Function to set what cells are by what color attacked
    @param piece current piece
    @param val color of the piece
    @param cell while chessboard*/
    template < typename T>
    void atk(T* piece, int val, vector<vector<Square>>& cell);

    /**Function to set attacked cells for a pawn
    @param val colour of the pawn
    @param x x position of the cell to set attack on
    @param y y position of the cell to set attack on*/
    void atppawn(int val, int x, int y);


    /**Function to check for valid moves
    @param moves all posiible moves of a piece
    @cells the whole chessboard*/
    void checkifvalid(vector<Square>& moves, vector<vector<Square>>& cells);

    /**Function to add moves that are possible
    @param cells the whole chessboard
    @param temp a temporary chessboard
    @param attacker a piece that attacks the king
    @param a current position x of the piece
    @param b current position y of the piece
    @param x x position to be set if valid 
    @param y y position to be set if valid
    @param king king of that piece*/
    void addmoves(vector<vector<Square>>& cells, vector<vector<Square>>& temp, Pieces* attacker, int a, int b, int x, int y, King* king);

    /**Function to initialize all pieces*/
	void start();

    /**Function to place all pieces and set their positions
    @param c1 color of square
    @param c2 color of square*/
    void place(sf::Color c1, sf::Color c2);

    /**Function to move selected piece
    @param Cells the whole chessboard
    @param x x position to be set
    @param y y position to be set*/
    void moveSelected(vector<vector<Square>>& Cells, int x, int y);

    /**Function to show proper message if game is over
    @param a which color won*/
    void gameOver(int a);

    /**Function to update which player now move*/
    void SetRightSideofWindow();

    /**Function to set what squares are by what color attacked
    @param cell the whole chessboard*/
    void setattack(vector<vector<Square>>& cell);

    /**Function to set what pieces and where was moved
    @param moved the moved piece
    @param x x parameter
    @param y y parameter*/
    void pushmove(Pieces* moved, int x, int y);

    /**Destructor*/
    ~Board();


    /**2D vector of Square class that represents the whole chessboard*/
    std::vector<std::vector<Square>> cells;

    /**Currently selected piece*/
    Pieces* selected_piece;

    /**Vector of all white pieces*/
    vector<Pieces*> whitePieces;

    /**Vector of all black pieces*/
    vector<Pieces*> blackPieces; 

    /**Object of the hisstruct struct*/
    HisStruct ht;

    /**Piece that has been captured*/
    Pieces* killed;

    /**Parameters with the position of a piece before a move*/
    int xi, yi;

    /**What piece has been moved*/
    Pieces* moved;
    
    /**vector of struct that contains the history of all moves*/
    vector<HisStruct> md;
    


    /**White King*/
    King* w_king;

    /**White queen*/
    Queen* w_queen;

    /**Two white bishops*/
    Bishop* w_bishop[2];

    /**Two white Rooks*/
    Rook* w_rook[2];

    /**two white knights*/
    Knight* w_knight[2];

    /**white pawns*/
    Pawn* w_pawn[8];
  
    /**black king*/
    King* b_king;

    /**black queen*/
    Queen* b_queen;

    /**black bishops*/
    Bishop* b_bishop[2];

    /**black rooks*/
    Rook* b_rook[2];

    /**black knights*/
    Knight* b_knight[2];

    /**black pawns*/
    Pawn* b_pawn[8];
   
    /**all promoted white queens*/
    Queen* w_p_queen[8];

    /**all promoted white bishops*/
    Bishop* w_p_bishop[8];

    /**all promoted white rooks*/
    Rook* w_p_rook[8];

    /**all promoted white knights*/
    Knight* w_p_knight[8];


    /**all promoted black queens*/
    Queen* b_p_queen[8];

    /**all promoted black bishops*/
    Bishop* b_p_bishop[8];

    /**all promoted black rooks*/
    Rook* b_p_rook[8];

    /**all promoted black knights*/
    Knight* b_p_knight[8];

private:

    /**vector with all possible moves*/
    vector<Square> moves;

    /**vector to contain which squares to color*/
    vector<sf::RectangleShape> newmoves;

    /**variables to know whos turn it is and if a piece is selected*/
    bool gameStatus, selected, whiteTurn;

    /**variable to know if a game is over or not*/
    bool isOver;

    /**Strings with turn information*/
    sf::Text situation, chance;
  
    /**variable to know if there was a captur*/
    bool capture; 

    /**variable to know if a moved was performed*/
    bool performed_move;

    /**variables to know what castle is possible*/
    bool w_lg, w_shr, b_lg, b_shr;
    
    /**variables for x and y position of a piece*/
    int c, d;

    /**number of moves*/
    int number_of_moves;

    /**variable to know if an en passant was performed*/
    bool performed_passant;

    /**parameter of square that starts promotion*/
    int y_pr;
 
    
};


#endif
