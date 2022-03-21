/** @file  */

/*
Computer Programming
Chess
*/

#pragma once

#include <iostream>
#include <sstream>
#include <SFML/Graphics.hpp>


#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27


/**Class for textboxes in main menu*/
class Textbox 
{
	/**frien with mainmenu class*/
	friend class MainMenu;
public:

	/**Constructor*/
	Textbox();

	/**set font
	@param fonts font*/
	void setFont(sf::Font& fonts);


	/**set position
	@param point position*/
	void setPosition(sf::Vector2f point);

	/**set limit
	@param ToF true if there is a limit*/
	void setLimit(bool ToF);


	/**set limit
	@param RoF true if there is a limit
	@param lim what limit it is*/
	void setLimit(bool ToF, int lim);

	/**change selected state
	@param sel true if it has to vhange*/
	void setSelected(bool sel);

	/**get a text
	@return string with text*/
	std::string getText();

	/**text*/
	sf::Text textbox;
	
	/**see what is the input*/
	void typedOn(sf::Event input);
private:
	
	/**string with text*/
	std::ostringstream text;

	/**if selected*/
	bool isSelected = false;

	/**if has a limit*/
	bool hasLimit = false;

	/**what limit it has*/
	int limit = 0;

	/**Delete the last character of the text*/
	void deleteLastChar() {
		std::string t = text.str();
		std::string newT = "";
		for (int i = 0; i < t.length() - 1; i++) {
			newT += t[i];
		}
		text.str("");
		text << newT;
		textbox.setString(text.str() + "_");
	}

	/**Get user input */
	void inputLogic(int charTyped) {
		// If the key pressed isn't delete, or the two selection keys, then append the text with the char:
		if (!sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			text << static_cast<char>(charTyped);
		}
		// If the key is delete, then delete the char:
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
			if (text.str().length() > 0) {
				deleteLastChar();
			}
		}
		// Set the textbox text:
		textbox.setString(text.str() + "_");
	}
}; 
