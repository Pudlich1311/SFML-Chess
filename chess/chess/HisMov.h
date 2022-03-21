/** @file  */

/*
Computer Programming
Chess
*/

#ifndef HISMOV_H
#define HISMOV_H

#include <SFML/Graphics.hpp>
#include"Square.h"
#include"Pieces.h"
#include "King.h"
#include "Bishop.h"
#include "Queen.h"
#include "Knight.h"
#include "Pawn.h"
#include "Rook.h"
#include <iostream>
#include <fstream> 

/**Class  to save and load a game*/
class HisMov
{
public:
	
	/**Constructor*/
	HisMov() {};

	/**Destructor*/
	~HisMov();

	/**Function to save a game to file*/
	void sv();

	/**Function to load a game from file*/
	void ld();


	/** 2D vector of the whole chessboard*/
	std::vector<std::vector<Square>> cells;

	/**vector with all white pieces*/
	std::vector<Pieces*> whitePieces;

	/**vector with all black pieces*/
	std::vector<Pieces*> blackPieces;

	/**variables to know what is the status of the game and whos turn*/
	bool gameStatus, whiteTurn;

	/**number of moves*/
	int number_of_moves;

	/**If there was an en passant*/
	bool performed_passant;

	/**number of turns*/
	int turn;

	/**number of objects in vectors with pieces*/
	int whitesize, blacksize;

	/**string with all moves*/
	sf::Text mov;
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
};

#endif
