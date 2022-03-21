/** @file  */

/*
Computer Programming
Chess
*/


#ifndef MAINMENU_H
#define MAINMENU_H
#include<SFML/Graphics.hpp>
#include"Textbox.h"

/**Class for the main menu, it contains states e.g state where the player writes the name of a player*/
class MainMenu : public sf::Drawable
{

public:

	/**Constructor*/
	MainMenu();

	/**function to update the screen
	@param target target on which to draw
	@param states state*/
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	

	/**Destructor*/
	~MainMenu(){}


	/**What states now is*/
	int state=0;
	

	/**First textbox*/
	Textbox t1;

	/**second textbox*/
	Textbox t2;
private:

	/**font*/
	sf::Font font;

	/**start button*/
	sf::RectangleShape Start;

	/**string*/
	sf::Text text;

	/**tecture of background*/
	sf::Texture t;

	/**sprite of background*/
	sf::Sprite s;

	/**load button*/
	sf::RectangleShape Load;

	/**string for load*/
	sf::Text ld;

	/**string fo player 1*/
	sf::Text p1;

	/**string for player 2*/
	sf::Text p2;
	
};




#endif