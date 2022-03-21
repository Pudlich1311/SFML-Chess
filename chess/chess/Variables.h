/** @file  */

/*
Computer Programming
Chess
*/

#ifndef VARIABLES_H
#define VARIABLES_H
#include<SFML/Graphics.hpp>

/**Some global variables*/

	/**name of first player*/
	extern sf::Text player1;

	/**name of second player*/
	extern sf::Text player2;

	/**if en passant was performed*/
	extern bool en_passant;

	/**if white has castled*/
	extern bool w_cs;

	/**if black has castled*/
	extern bool b_cs;

	/**if white promoted*/
	extern bool w_promote;

	/**if black promoted*/
	extern bool b_promote;

	/**if the gmae is load*/
	extern bool load;

#endif 