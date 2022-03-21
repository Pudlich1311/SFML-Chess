/** @file  */

/*
Computer Programming
Chess
*/

#ifndef SQUARE_H
#define SQUARE_H
#include<SFML/Graphics.hpp>

/**Class of a single Square*/
class Square
{
public:

	/**Constructor*/
	Square();

	/**x and y parameters of a square*/
	int x, y;

	/**what piece is on that square*/
	int occupied_value;

	/**what color is on that square*/
	int occupied_color;

	/**what color has the cell*/
	int cell_color;

	/**what color is attacking the square*/
	int is_attacked;

	/**Shape of the square*/
	sf::RectangleShape square;

	/**destructor*/
	~Square() {}
};

#endif
