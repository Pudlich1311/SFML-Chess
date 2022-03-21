/** @file  */

/*
Computer Programming
Chess
*/

#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <utility>

#include "Board.h"
#include"Queen.h"
#include "Pieces.h"
#include"Bishop.h"
#include "HisMov.h"
#include"HisStruct.h"

/**Class for initializing the whole game*/
class Game : public sf::Drawable
{
    
public:

    /**Function set position of promoted piece
    @param piece piece that the pawn was promoted to
    @param color color of the piece*/
    template<typename P>
    void pro(P*& piece, int color);

    
    


    /**Constructor
    @param c1 color of the square
    @param c2 color of the square
    @load if the game was load or a new game was started*/
	Game(sf::Color c1, sf::Color c2, bool load);

    /**Start the game
    @param c1 color of the square
    @param c2 color of the square*/
    void Start(sf::Color c1, sf::Color c2);

    /**Update the screen
    @target target to draw on
    @states state*/
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    /**Function to check if game is over
    @return false if not over
    @return true if over*/
    bool Over();

    /**Function to move a piece
    @param x x parameter of that piece
    @param y y parameter of that piece*/
    void move(int x, int y);

    /**Function to know if a piece is selected
    @return true if a piece is selected
    @return false if no piece is selected*/
    bool getSec();

    /**Function to know which piece is selected
    @param x x parameter of that piece
    @param y y parameter of that piece
    @return true if a piece is selected*/
    bool Select(int x, int y);

    /**Draw all possible moves of a piece*/
    void DrawPossibleMoves();

    /**Function to promote a piece*/
    void promote();

    /**Update string with all moves
    @param x x parameter of moved piece
    @param y y parametef of moved piece*/
    void mv(int x, int y);

    /**Function to save the game*/
    void save();

    /**Function to load similar rectangles
    @param obj rectangle*/
    void ld(sf::RectangleShape& obj);

    /**Function to load a game from file
    @param c1 color of square
    @param c2 color of square*/
    void loadgame(sf::Color c1, sf::Color c2);

    /**Function to undo a move*/
    void undo();

    /**Destructor*/
    ~Game(){}

    /**Object of board class*/
    Board a;

    /**Object of hismov class*/
    HisMov m;

    /**Object of hissstruct struct*/
    HisStruct h;

private:

    /**char with board squares*/
    char brx[8] = { 'a', 'b' , 'c', 'd','e','f','g','h' };

    /**char with board squares*/
    char bry[8] = { '8', '7', '6', '5', '4', '3', '2', '1'};

    /**number of turns*/
    int turn;

    /**string with all moves*/
    sf::Text mov;

    /**String with all moves*/
    sf::Text half_moves;

    /**Font*/
    sf::Font font;

    /**Rectangle for start again*/
    sf::RectangleShape infoRestart;

    /**Text for start again*/
    sf::Text textRestart;

    /**Tect for promotion*/
    sf::Text promo;

    /**Text for promotion*/
    sf::Text Qn;

    /**Text for promotion*/
    sf::Text Bp;

    /**Text for promotion*/
    sf::Text Rk;

    /**Text for promotion*/
    sf::Text Kt;

    /**Rectangle for promotion*/
    sf::RectangleShape Q;

    /**Rectangle for promotion*/
    sf::RectangleShape B;

    /**Rectangle for promotion*/
    sf::RectangleShape R;

    /**Rectangle for promotion*/
    sf::RectangleShape K;

    /**Rectangle for Saving*/
    sf::RectangleShape Save;

    /**Rectangle for undo*/
    sf::RectangleShape Undo;

    /**Text for saving*/
    sf::Text sv;

    /**text for undo*/
    sf::Text und;

    /**variable to know if white rurn or not*/
    bool trn;
};






#endif