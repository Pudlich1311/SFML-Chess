#include <SFML/Graphics.hpp>
#include<iostream>
#include"Game.h"
#include"MainMenu.h"
#include"Variables.h"

sf::Text player1;
sf::Text player2;
bool w_promote;
bool b_promote;
bool load;

int main()
{

    sf::RenderWindow main(sf::VideoMode(1000, 800), "Main screen", sf::Style::Titlebar | sf::Style::Close);
    bool start = false;
   

    MainMenu menu;
    while (main.isOpen())
    {
        sf::Event a;
        while (main.pollEvent(a))
        {
            if (a.type == sf::Event::Closed)
            {
                main.close();
            }
            if (menu.state == 0)
            {
                if (a.type == sf::Event::MouseButtonPressed)
                {
                    if (a.mouseButton.button == sf::Mouse::Left)
                    {
                        if (a.mouseButton.x >= 420.f && a.mouseButton.x <= 620.f && a.mouseButton.y >= 100.f && a.mouseButton.y <= 180.f)
                        {
                            menu.state = 1;
                            break;
                        }
                        else if (a.mouseButton.x >= 420.f && a.mouseButton.x <= 620.f && a.mouseButton.y >= 170.f && a.mouseButton.y <= 330.f)
                        {
                            start = true;
                            load = true;
                        }
                    }
                }
            }

            if (menu.state == 2)
            {
                if (a.type == sf::Event::TextEntered)
                {
                    menu.t2.typedOn(a);
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                    {
                        srand(time(NULL));
                        menu.state = 3;
                        start = true;
                        int r = rand() % 2;
                        if (r == 1)
                        {
                            player1 = menu.t1.textbox;
                            player2 = menu.t2.textbox;
                            break;
                        }
                        else
                        {
                            player2 = menu.t1.textbox;
                            player1 = menu.t2.textbox;
                            break;
                        }

                    }
                }
            }
            if (menu.state == 1)
            {
                if (a.type == sf::Event::TextEntered)
                {
                    menu.t1.typedOn(a);
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                    {
                        menu.state = 2;
                        break;
                    }
                }
            }


            if (start)
            {
            label:
                sf::RenderWindow window(sf::VideoMode(1100, 800), "Chess", sf::Style::Titlebar | sf::Style::Close);
                
                Game chess(sf::Color(234, 240, 206), sf::Color(187, 190, 100), load);
                

                while (window.isOpen())
                {

                    sf::Event e;
                    while (window.pollEvent(e))
                    {
                        if (e.type == sf::Event::Closed)
                            window.close();

                        main.close();
                        start = false;
                        if (e.type == sf::Event::MouseButtonPressed)
                        {
                            if (e.mouseButton.button == sf::Mouse::Left)
                            {
                                if (e.mouseButton.x >= 0 && e.mouseButton.x <= 800 && e.mouseButton.y >= 0 && e.mouseButton.y <= 800)
                                {
                                    int x = e.mouseButton.y / 100, y = e.mouseButton.x / 100;
                                    if (!chess.getSec() && chess.Over() == false)
                                    {
                                        chess.Select(e.mouseButton.y / 100, e.mouseButton.x / 100);
                                    }
                                    else
                                    {
                                        chess.move(e.mouseButton.y / 100, e.mouseButton.x / 100);
                                       
                                    }
                                }
                                if (e.mouseButton.x >= 850 && e.mouseButton.x <= 1024 && e.mouseButton.y >= 5 && e.mouseButton.y <= 55)
                                {
                                    sf::Text playertemp = player1;
                                    player1 = player2;
                                    player2 = playertemp;
                                    load = false;
                                    goto label;
                                }
                                if (e.mouseButton.x >= 815 && e.mouseButton.x <= 943 && e.mouseButton.y >= 705 && e.mouseButton.y <= 784)
                                {
                                   
                                    chess.save();
                                }
                                if (e.mouseButton.x >= 955 && e.mouseButton.x <= 1083 && e.mouseButton.y >= 705 && e.mouseButton.y <= 784)
                                {
                                    
                                    chess.undo();
                                }
                                if (w_promote || b_promote)
                                {
                                    chess.promote();
                                    chess.a.setattack(chess.a.cells);
                                }
                            }
                            
                        }
                        
                        
                    }
                  
                    
                   window.draw(chess);
                    window.display();
                }
            }
        }
        main.draw(menu);
        main.display();
    }

    return 0;
}