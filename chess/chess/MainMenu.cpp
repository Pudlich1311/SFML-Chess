#include<iostream>
#include "MainMenu.h"

MainMenu::MainMenu()
{
    t.loadFromFile("Textures/chess.jpeg");
    font.loadFromFile("Textures/roboto.ttf");

    Start.setFillColor(sf::Color::White);
    Start.setOutlineThickness(-5.f);
    Start.setOutlineColor(sf::Color::Black);
    Start.setPosition(sf::Vector2f(420.f, 100.f));
    Start.setSize(sf::Vector2f(200.f, 80.f));

    Load.setFillColor(sf::Color::White);
    Load.setOutlineThickness(-5.f);
    Load.setOutlineColor(sf::Color::Black);
    Load.setPosition(sf::Vector2f(420.f, 250.f));
    Load.setSize(sf::Vector2f(200.f, 80.f));

    ld.setFont(font);
    ld.setString("Load");
    ld.setCharacterSize(56);
    ld.setFillColor(sf::Color::Blue);
    ld.setPosition(465.f, 255.f);

    text.setFont(font);
    text.setString("Start");
    text.setCharacterSize(56);
    text.setFillColor(sf::Color::Blue);
    text.setPosition(465.f,105.f);

    p1.setFont(font);
    p1.setString("Insert name of the first player \n           and hit Enter");
    p1.setCharacterSize(40);
    p1.setFillColor(sf::Color::Blue);
    sf::FloatRect textRect = p1.getLocalBounds();
    p1.setOrigin(textRect.left + textRect.width / 2.0f,
        textRect.top + textRect.height / 2.0f);
    p1.setPosition(sf::Vector2f(1000 / 2.0f, 100.f));

    p2.setFont(font);
    p2.setString("Insert name of the second player \n                and hit Enter");
    p2.setCharacterSize(40); 
    p2.setFillColor(sf::Color::Blue);
    textRect = p2.getLocalBounds();
    p2.setOrigin(textRect.left + textRect.width / 2.0f,
        textRect.top + textRect.height / 2.0f);
    p2.setPosition(sf::Vector2f(1000 / 2.0f, 100.f));

    s.setTexture(t);

    t1.textbox.setCharacterSize(64);
    t1.textbox.setFillColor(sf::Color::Blue);
    t1.isSelected = true;
    t1.setFont(font);
    t1.setPosition({ 200,200 });
    t1.setLimit(true, 15);

    t2.textbox.setCharacterSize(64);
    t2.textbox.setFillColor(sf::Color::Blue);
    t2.isSelected = true;
    t2.setFont(font);
    t2.setPosition({ 200,200 });
    t2.setLimit(true, 15);

}

void MainMenu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (state == 0)
    {
        target.clear();
        target.draw(s);
        target.draw(Start);
        target.draw(text);
        target.draw(Load);
        target.draw(ld);
    }
    if (state == 1)
    {   
        target.clear(sf::Color::White);
        target.draw(p1);
        
        target.draw(t1.textbox);
 
    }
    if (state == 2)
    {
        target.clear(sf::Color::White);

        target.draw(p2);
        target.draw(t2.textbox);
    }
    
}


