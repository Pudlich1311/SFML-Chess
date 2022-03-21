#include <iostream>

#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Pieces.h"
#include "Square.h"

void Game::ld(sf::RectangleShape& obj)
{
    obj.setFillColor(sf::Color::White);
    obj.setOutlineThickness(-5.f);
    obj.setOutlineColor(sf::Color::Black);
    obj.setSize(sf::Vector2f(180.f, 60.f));
}


Game::Game(sf::Color c1, sf::Color c2, bool load)
{
 
    trn = true;
    font.loadFromFile("Textures/roboto.ttf");
    infoRestart.setFillColor(sf::Color::White);
    infoRestart.setOutlineThickness(-5.f);
    infoRestart.setOutlineColor(sf::Color::Black);
    infoRestart.setPosition(sf::Vector2f(860.f, 0.f));
    infoRestart.setSize(sf::Vector2f(180.f, 60.f));

    Save.setFillColor(sf::Color::White);
    Save.setOutlineThickness(-5.f);
    Save.setOutlineColor(sf::Color::Black);
    Save.setPosition(sf::Vector2f(810.f, 700.f));
    Save.setSize(sf::Vector2f(140.f, 90.f));

    Undo.setFillColor(sf::Color::White);
    Undo.setOutlineThickness(-5.f);
    Undo.setOutlineColor(sf::Color::Black);
    Undo.setPosition(sf::Vector2f(950.f, 700.f));
    Undo.setSize(sf::Vector2f(140.f, 90.f));

    textRestart.setFont(font);
    textRestart.setString("Start Again");
    textRestart.setCharacterSize(28);
    textRestart.setFillColor(sf::Color::Blue);
    textRestart.setPosition(infoRestart.getPosition().x + 35.f, infoRestart.getPosition().y + 13.f);

    sv.setFont(font);
    sv.setString("Save \nGame");
    sv.setCharacterSize(34);
    sv.setFillColor(sf::Color::Blue);
    sv.setPosition(Save.getPosition().x + 35.f, Save.getPosition().y);

    und.setFont(font);
    und.setString("Undo");
    und.setCharacterSize(34);
    und.setFillColor(sf::Color::Blue);
    und.setPosition(Undo.getPosition().x + 35.f, Undo.getPosition().y + 20.f);

    promo.setFont(font);
    promo.setString("Choose a piece");
    promo.setCharacterSize(28);
    promo.setFillColor(sf::Color::Blue);
    promo.setPosition(50.f, 10.f);

    mov.setFont(font);
    mov.setCharacterSize(16);
    mov.setFillColor(sf::Color::White);
    mov.setPosition(820.f, 120.f);

    half_moves.setFont(font);
    half_moves.setCharacterSize(16);
    half_moves.setFillColor(sf::Color::White);
    half_moves.setPosition(820.f, 120.f);

    ld(Q);
    Q.setPosition(sf::Vector2f(50.f, 50.f));
   

    ld(B);
    B.setPosition(sf::Vector2f(50.f, 120.f));
  
    ld(R);
    R.setPosition(sf::Vector2f(50.f, 190.f));
  

    ld(K);
    K.setPosition(sf::Vector2f(50.f, 260.f));


    Qn.setFont(font);
    Qn.setString("Queen");
    Qn.setCharacterSize(28);
    Qn.setFillColor(sf::Color::Blue);
    Qn.setPosition(Q.getPosition().x + 55.f, Q.getPosition().y + 13.f);

    Bp.setFont(font);
    Bp.setString("Bishop");
    Bp.setCharacterSize(28);
    Bp.setFillColor(sf::Color::Blue);
    Bp.setPosition(B.getPosition().x + 55.f, B.getPosition().y + 13.f);

    Rk.setFont(font);
    Rk.setString("Rook");
    Rk.setCharacterSize(28);
    Rk.setFillColor(sf::Color::Blue);
    Rk.setPosition(R.getPosition().x + 55.f, R.getPosition().y + 13.f);

    Kt.setFont(font);
    Kt.setString("Knight");
    Kt.setCharacterSize(28);
    Kt.setFillColor(sf::Color::Blue);
    Kt.setPosition(K.getPosition().x + 55.f, K.getPosition().y + 13.f);

    turn = 1;

   
    a.chance.setFont(font);
    a.chance.setCharacterSize(30);
    a.chance.setStyle(sf::Text::Regular);
    a.chance.setFillColor(sf::Color::White);
    a.chance.setPosition(880.f, 80.f);
    a.situation.setFont(font);
    a.situation.setCharacterSize(28);
    a.situation.setStyle(sf::Text::Regular);
    a.situation.setFillColor(sf::Color::White);
    a.situation.setPosition(a.chance.getPosition().x, a.chance.getPosition().y - 20.f);
    
    if (load)
    {
        loadgame(c1,c2);
    }
    else
    {
        a.start();
        Start(c1, c2);
    }
}

void Game::loadgame(sf::Color c1, sf::Color c2)
{
    m.ld();
    a.start();

    //a.place();
    int k = 0;
    int l = 0;
    int u = 0;
    int o = 0;
    for (int i =0; i < m.whitePieces.size(); i++)
    {
        if (i >= a.whitePieces.size())
        {
            if (m.whitePieces[i]->occupied_value==2)
            {
                a.w_p_queen[k] = new Queen(1);
                a.whitePieces.push_back(a.w_p_queen[k]);
                k++;
            }
            if (m.whitePieces[i]->occupied_value == -2)
            {
                a.w_p_bishop[l] = new Bishop(1);
                a.whitePieces.push_back(a.w_p_bishop[l]);
                l++;
            }
            if (m.whitePieces[i]->occupied_value == 1)
            {
                a.w_p_rook[u] = new Rook(1);
                a.whitePieces.push_back(a.w_p_rook[u]);
                u++;
            }
            if (m.whitePieces[i]->occupied_value == -1)
            {
                a.w_p_knight[o] = new Knight(1);
                a.whitePieces.push_back(a.w_p_knight[o]);
                o++;
            }
        }
        if (a.whitePieces[i]->occupied_value == m.whitePieces[i]->occupied_value)
        {
            a.whitePieces[i]->x = m.whitePieces[i]->x;
            a.whitePieces[i]->y = m.whitePieces[i]->y;
            a.whitePieces[i]->isAlive = m.whitePieces[i]->isAlive;
        }
    }

    k = 0;
    l = 0;
    u = 0;
    o = 0;
    for (int i = 0; i < m.blackPieces.size(); i++)
    {

        if (i >= a.blackPieces.size())
        {
            if (m.blackPieces[i]->occupied_value == 2)
            {
                a.b_p_queen[k] = new Queen(1);
                a.blackPieces.push_back(a.b_p_queen[k]);
                k++;
            }
            if (m.blackPieces[i]->occupied_value == -2)
            {
                a.b_p_bishop[l] = new Bishop(1);
                a.blackPieces.push_back(a.b_p_bishop[l]);
                l++;
            }
            if (m.blackPieces[i]->occupied_value == 1)
            {
                a.b_p_rook[u] = new Rook(1);
                a.blackPieces.push_back(a.b_p_rook[u]);
                u++;
            }
            if (m.blackPieces[i]->occupied_value == -1)
            {
                a.b_p_knight[o] = new Knight(1);
                a.blackPieces.push_back(a.b_p_knight[o]);
                o++;
            }
        }
        if (a.blackPieces[i]->occupied_value == m.blackPieces[i]->occupied_value)
        {
            a.blackPieces[i]->x = m.blackPieces[i]->x;
            a.blackPieces[i]->y = m.blackPieces[i]->y;
            a.blackPieces[i]->isAlive = m.blackPieces[i]->isAlive;
        }
    } 
  

    for (auto& i : a.whitePieces)
    {
        a.set(i);
    }

    for (auto& j : a.blackPieces)
    {
        a.set(j);
    }

    for (int i=0; i<8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            a.cells[i][j].square.setPosition(sf::Vector2f(j * 100.0f, i * 100.0f));
            a.cells[i][j].square.setSize(sf::Vector2f(100.f, 100.f));
            a.cells[i][j].square.setFillColor((i + j) % 2 ? c2 : c1);
            a.cells[i][j].is_attacked = m.cells[i][j].is_attacked;
            a.cells[i][j].occupied_color = m.cells[i][j].occupied_color;
            a.cells[i][j].occupied_value = m.cells[i][j].occupied_value;
        }
    }

    mov.setString(m.mov.getString());
    turn = m.turn;
    a.number_of_moves = m.number_of_moves;
    a.isOver = false;
    a.gameStatus = m.gameStatus;
    a.whiteTurn = m.whiteTurn; 
    a.selected = false;
    a.selected_piece = NULL;

    a.SetRightSideofWindow();
}


void Game::mv(int x, int y)
{
   

    if (a.cells[x][y].occupied_color == 1 && trn)
    {
        sf::String tur = std::to_string(turn) + ".";
        mov.setString(mov.getString() + tur);
    }
  
   


    sf::String xi = bry[x];
    sf::String yi = brx[y];

    sf::String xj = bry[a.c];
    sf::String yj = brx[a.d];

    sf::String cap = "x";

    if (a.w_shr || a.b_shr)
    {
        mov.setString(mov.getString() + " O-O");
        
    }
    else if (a.w_lg || a.b_shr)
    {
        mov.setString(mov.getString() + " O-O-O");
    }
    else if (a.cells[x][y].occupied_value == 3)
    {
        sf::String k = "K";
        mov.setString(mov.getString() + k);

        if (a.capture)
        {

            
            mov.setString(mov.getString() + " "  +cap);
        }
    
        mov.setString(mov.getString() + yi + xi );

    }
    else if (a.cells[x][y].occupied_value == 2)
    {
        sf::String Q = "Q";
        mov.setString(mov.getString() + " " + Q);

        if (a.capture)
        {
            
            mov.setString(mov.getString() + yj + xj + cap);
        }

        mov.setString(mov.getString() + yi + xi );

    }
    else if (a.cells[x][y].occupied_value == -2)
    {

        sf::String B = "B";
        mov.setString(mov.getString() + " " + B);

        if (a.capture)
        {
           
            mov.setString(mov.getString() + yj + xj + cap);
        }

        mov.setString(mov.getString()  + yi + xi );

    }
    else if (a.cells[x][y].occupied_value == -1)
    {

        sf::String Kn = "N";
        mov.setString(mov.getString() + " " + Kn);

        if (a.capture)
        {
            
            mov.setString(mov.getString() + yj + xj + cap);
        }

        mov.setString(mov.getString() + yi + xi);

    }
    else if (a.cells[x][y].occupied_value == 1)
    {

        sf::String R = "R";
        mov.setString(mov.getString() + " " + R);

        if (a.capture)
        {
            
            mov.setString(mov.getString() + yj + xj + cap);
        }

        mov.setString(mov.getString() + yi + xi);

    }
    else if (a.cells[x][y].occupied_value == -3)
    {

        if (a.capture)
        {
            
            mov.setString(mov.getString() + " " + yj + cap + yi + xi);
            
        }
        else
        {
            mov.setString(mov.getString() + " " + yi + xi);
        }

    }

    if (a.cells[x][y].occupied_color == -1)
    {
        turn++;
        mov.setString(mov.getString() + '\n');

        if (turn == 30)
        {

            half_moves.setString(mov.getString());
            mov.setString("");
            mov.setPosition(940.f, 120.f);
        }
    }

    
    
}
void Game::Start(sf::Color c1, sf::Color c2)
{
    a.place(c1, c2);
    a.number_of_moves = 0;
    a.isOver = false;
    a.gameStatus = true, a.whiteTurn = 1, a.selected = false;
   a.selected_piece = NULL;

    a.SetRightSideofWindow();
}



void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.clear();
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            target.draw(a.cells[i][j].square);
        }
    }
    target.draw(infoRestart);
    target.draw(textRestart);
    target.draw(Save);
    target.draw(Undo);
    target.draw(a.situation);
    target.draw(mov);
    target.draw(half_moves);
    target.draw(sv);
    target.draw(und);
    if (a.isOver == false)
        target.draw(a.chance);
    for (int i = 0; i < a.moves.size(); i++)
    {
        target.draw(a.moves[i].square);
    }

    if ((a.selected_piece != NULL))
    {
        for (int i = 0; i < a.newmoves.size(); i++)
        {
            target.draw(a.newmoves[i]);
        }
    }
    for (int i = 0; i < a.whitePieces.size(); i++)
    {
        if (a.whitePieces[i]->isAlive)
        {
            target.draw(a.whitePieces[i]->piece);
        }
    
    }
    for (int i = 0; i < a.blackPieces.size(); i++)
    {
        if (a.blackPieces[i]->isAlive)
        {
            target.draw(a.blackPieces[i]->piece);
        }
    
    }
}

bool Game::Over()
{
    return a.isOver;
}

bool Game::getSec()
{
    return a.selected;
}

void Game::move(int x, int y)
{
    a.moveSelected(a.cells,x, y);

    if (a.performed_move)
    {
        mv(x, y);
    }
    trn = true;
}


bool Game::Select(int x, int y)
{

    a.cells[x][y].occupied_color;
    if (a.cells[x][y].occupied_color == 0)
    {
        a.selected_piece = NULL;
        return false;
    }
    if (a.cells[x][y].occupied_color == 1 && a.whiteTurn == 0 || a.cells[x][y].occupied_color == -1 && a.whiteTurn == 1)
    {
        a.selected_piece = NULL;
        return false;
    }
    a.selected = true;
    if (a.cells[x][y].occupied_color == 1)
    {
        if (a.cells[x][y].occupied_value == 3)
            a.selected_piece = a.w_king;
        else if (a.cells[x][y].occupied_value == 2)
        {
            for (int i = 0; i < 8; i++)
            {
                if (a.w_p_queen[i] != nullptr && a.w_p_queen[i]->x == x && a.w_p_queen[i]->y == y)
                {
                    a.selected_piece = a.w_p_queen[i];
                    break;
                }
            }
            if(a.w_queen->x == x && a.w_queen->y == y)
            {
                a.selected_piece = a.w_queen;
            }
            
        }
        else if (a.cells[x][y].occupied_value == 1)
        {
            if (a.w_rook[0]->x == x && a.w_rook[0]->y == y)
            {
                a.selected_piece = a.w_rook[0];
            }
            else if (a.w_rook[1]->x == x && a.w_rook[1]->y == y)
            {
                a.selected_piece = a.w_rook[1];
            }
            for (int i = 0; i < 8; i++)
            {
                if (a.w_p_rook[i] != nullptr && a.w_p_rook[i]->x == x && a.w_p_rook[i]->y == y)
                {
                    a.selected_piece = a.w_p_rook[i];
                    break;
                }
            }
        }
        else if (a.cells[x][y].occupied_value == -2)
        {
            if (a.w_bishop[0]->x == x && a.w_bishop[0]->y == y)
            {
                a.selected_piece = a.w_bishop[0];
            }
            else if (a.w_bishop[1]->x == x && a.w_bishop[1]->y == y)
            {
                a.selected_piece = a.w_bishop[1];
            }
            for (int i = 0; i < 8; i++)
            {
                if (a.w_p_bishop[i] != nullptr && a.w_p_bishop[i]->x == x && a.w_p_bishop[i]->y == y)
                {
                    a.selected_piece = a.w_p_bishop[i];
                    break;
                }
            }
        }
        else if (a.cells[x][y].occupied_value == -1)
        {
            if (a.w_knight[0]->x == x && a.w_knight[0]->y == y)
            {
                a.selected_piece = a.w_knight[0];
            }
            else if (a.w_knight[1]->x == x && a.w_knight[1]->y == y)
            {
                a.selected_piece = a.w_knight[1];
            }
            for(int i = 0; i < 8; i++)
            {
                if (a.w_p_knight[i] != nullptr && a.w_p_knight[i]->x == x && a.w_p_knight[i]->y == y)
                {
                    a.selected_piece = a.w_p_knight[i];
                    break;
                }
            }
        }
        else if (a.cells[x][y].occupied_value == -3)
        {
            for (int i = 0; i < 8; i++)
            {
                if (a.w_pawn[i]->x == x && a.w_pawn[i]->y == y)
                {
                    a.selected_piece = a.w_pawn[i];
                    break;
                }
            }
        }
    }
    else
    {
        if (a.cells[x][y].occupied_value == 3)
            a.selected_piece = a.b_king;
        else if (a.cells[x][y].occupied_value == 2)
        {
            for (int i = 0; i < 8; i++)
            {
                if (a.b_p_queen[i] != nullptr && a.b_p_queen[i]->x == x && a.b_p_queen[i]->y == y)
                {
                    a.selected_piece = a.b_p_queen[i];
                    break;
                }
            }
            if(a.b_queen->x == x && a.b_queen->y == y)
            {
                a.selected_piece = a.b_queen;
            }
        }
        else if (a.cells[x][y].occupied_value == 1)
        {
            if (a.b_rook[0]->x == x && a.b_rook[0]->y == y)
            {
                a.selected_piece = a.b_rook[0];
            }
            else if (a.b_rook[1]->x == x && a.b_rook[1]->y == y)
            {
                a.selected_piece = a.b_rook[1];
            }
            for (int i = 0; i < 8; i++)
            {
                if (a.b_p_rook[i] != nullptr && a.b_p_rook[i]->x == x && a.b_p_rook[i]->y == y)
                {
                    a.selected_piece = a.b_p_rook[i];
                    break;
                }
            }
        }
        else if (a.cells[x][y].occupied_value == -2)
        {
            if (a.b_bishop[0]->x == x && a.b_bishop[0]->y == y)
            {
                a.selected_piece = a.b_bishop[0];
            }
            else if (a.b_bishop[1]->x == x && a.b_bishop[1]->y == y)
            {
                a.selected_piece = a.b_bishop[1];
                
            }
            for (int i = 0; i < 8; i++)
            {
                if (a.b_p_bishop[i] != nullptr && a.b_p_bishop[i]->x == x && a.b_p_bishop[i]->y == y)
                {
                    a.selected_piece = a.b_p_bishop[i];
                    break;
                }
            }
        }
        else if (a.cells[x][y].occupied_value == -1)
        {
            if (a.b_knight[0]->x == x && a.b_knight[0]->y == y)
            {
                a.selected_piece = a.b_knight[0];
            }
            else if (a.b_knight[1]->x == x && a.b_knight[1]->y == y)
            {
                a.selected_piece = a.b_knight[1];
            }
            for (int i = 0; i < 8; i++)
            {
                if (a.b_p_knight[i] != nullptr && a.b_p_knight[i]->x == x && a.b_p_knight[i]->y == y)
                {
                    a.selected_piece = a.b_p_knight[i];
                    break;
                }
            }
        }
        else
        {
            for (int i = 0; i < 8; i++)
            {
                if (a.b_pawn[i]->x == x && a.b_pawn[i]->y == y)
                {
                    a.selected_piece = a.b_pawn[i];
                    break;
                }
            }
        }
    }
    DrawPossibleMoves();
    return true;
}


void Game::DrawPossibleMoves()
{
    if (a.selected_piece == NULL)
        return;
    a.newmoves.clear();
    a.moves.clear();
    a.moves = a.selected_piece->getMoves(a.cells, a.selected_piece->x, a.selected_piece->y, 0);
    
    a.checkifvalid(a.moves, a.cells);


    for (auto& i : a.moves)
    {
        sf::RectangleShape tmp;
        tmp.setPosition(sf::Vector2f((i.y) * 100.f, (i.x) * 100.f));
        tmp.setSize(sf::Vector2f(100.f, 100.f));
        tmp.setFillColor(sf::Color(0x66b4cc50));
        a.newmoves.push_back(tmp);
    }
    sf::RectangleShape tmp;
    tmp.setPosition(sf::Vector2f((a.selected_piece->y) * 100.f, (a.selected_piece->x) * 100.f));
    tmp.setSize(sf::Vector2f(100.f, 100.f));
    tmp.setFillColor(sf::Color(0x00000000));
    tmp.setOutlineColor(sf::Color::Red);
    tmp.setOutlineThickness(-3.f);
    a.newmoves.push_back(tmp);
}

template<typename P>
void Game::pro(P*& piece, int color)
{
    if(color==1)
    {
        piece->x = 0;
        w_promote = false;
    }
    else if (color == 0)
    {
        piece->x = 7;
        b_promote = false;
    }
    piece->y = a.y_pr;
    piece->piece.setPosition(piece->y * 100.0f + 50.f, piece->x * 100.f + 50.f);
    piece->piece.setOrigin(sf::Vector2f(piece->piece.getTexture()->getSize().x / 2, piece->piece.getTexture()->getSize().y / 2));
    piece->piece.setScale(sf::Vector2f(0.375f, 0.375f));
   
   

}


void Game::promote() 
{
    sf::RenderWindow window(sf::VideoMode(300, 400), "Promote", sf::Style::Titlebar | sf::Style::Close);
    sf::Event pr;
    while (window.isOpen())
    {
        while (window.pollEvent(pr))
        {  window.clear();
                window.draw(promo);
                window.draw(Q);
                window.draw(B);
                window.draw(R);
                window.draw(K);
                window.draw(Qn);
                window.draw(Bp);
                window.draw(Rk);
                window.draw(Kt);
            if (w_promote)
            {   
              
                for (auto& i : a.whitePieces)
                {
                    if (i->occupied_value == -3 && i->x == 0)
                    {
                        
                        i->isAlive = false;

                        if (pr.type == sf::Event::MouseButtonPressed)
                        {
                            if (pr.mouseButton.button == sf::Mouse::Left)
                            {
                                if (pr.mouseButton.x >= 50.f && pr.mouseButton.x <= 230.f && pr.mouseButton.y >= 50.f && pr.mouseButton.y <= 110.f)
                                {
                                    //Queen
                                    for (int i = 0; i < 8; i++)
                                    {
                                        if (a.w_p_queen[i] == nullptr)
                                        {
                                            a.w_p_queen[i] = new Queen(1);
                                            pro(a.w_p_queen[i], 1);
                                            a.cells[a.w_p_queen[i]->x][a.w_p_queen[i]->y].occupied_value = 2;
                                            a.whitePieces.push_back(a.w_p_queen[i]);
                                            window.close();
                                            return;
                                        }
                                    }
                                  
                                    
                                }
                                else if (pr.mouseButton.x >= 50.f && pr.mouseButton.x <= 230.f && pr.mouseButton.y >= 120.f && pr.mouseButton.y <= 180.f)
                                {
                                    //Bishop
                                    for (int i = 0; i < 8; i++)
                                    {
                                        if (a.w_p_bishop[i] == nullptr)
                                        {
                                            a.w_p_bishop[i] = new Bishop(1);
                                            pro(a.w_p_bishop[i], 1);
                                            a.cells[a.w_p_bishop[i]->x][a.w_p_bishop[i]->y].occupied_value = -2;
                                            a.whitePieces.push_back(a.w_p_bishop[i]);
                                            window.close();
                                            return;
                                        }
                                    }
                                   
                                }
                                else if (pr.mouseButton.x >= 50.f && pr.mouseButton.x <= 230.f && pr.mouseButton.y >= 190.f && pr.mouseButton.y <= 250.f)
                                {
                                    //Rook
                                    for (int i = 0; i < 8; i++)
                                    {
                                        if (a.w_p_rook[i] == nullptr)
                                        {
                                            a.w_p_rook[i] = new Rook(1);
                                            pro(a.w_p_rook[i], 1);
                                            a.cells[a.w_p_rook[i]->x][a.w_p_rook[i]->y].occupied_value = 1;
                                            a.whitePieces.push_back(a.w_p_rook[i]);
                                            window.close();
                                            return;
                                        }
                                    }
                                   
                                }
                                else if (pr.mouseButton.x >= 50.f && pr.mouseButton.x <= 230.f && pr.mouseButton.y >= 260.f && pr.mouseButton.y <= 320.f)
                                {
                                    //Knight
                                    for (int i = 0; i < 8; i++)
                                    {
                                        if (a.w_p_knight[i] == nullptr)
                                        {
                                            a.w_p_knight[i] = new Knight(1);
                                            pro(a.w_p_knight[i], 1);
                                            a.cells[a.w_p_knight[i]->x][a.w_p_knight[i]->y].occupied_value = -1;
                                            a.whitePieces.push_back(a.w_p_knight[i]);
                                            window.close();
                                            return;
                                        }
                                    }

                                  
                                }
                            }
                        }
                    }
                }
            }
            else if (b_promote)
            {
                for (auto& i : a.blackPieces)
                {
                    if (i->occupied_value == -3 && i->x == 7)
                    {

                        i->isAlive = false;

                        if (pr.type == sf::Event::MouseButtonPressed)
                        {
                            if (pr.mouseButton.button == sf::Mouse::Left)
                            {
                                if (pr.mouseButton.x >= 50.f && pr.mouseButton.x <= 230.f && pr.mouseButton.y >= 50.f && pr.mouseButton.y <= 110.f)
                                {
                                    //Queen
                                    for (int i = 0; i < 8; i++)
                                    {
                                        if (a.b_p_queen[i] == nullptr)
                                        {
                                            a.b_p_queen[i] = new Queen(0);
                                            pro(a.b_p_queen[i], 0);
                                            a.cells[a.b_p_queen[i]->x][a.b_p_queen[i]->y].occupied_value = 2;
                                            a.blackPieces.push_back(a.b_p_queen[i]);
                                            window.close();
                                            return;
                                        }
                                    }
                                   

                                }
                                else if (pr.mouseButton.x >= 50.f && pr.mouseButton.x <= 230.f && pr.mouseButton.y >= 120.f && pr.mouseButton.y <= 180.f)
                                {
                                    //Bishop
                                    for (int i = 0; i < 8; i++)
                                    {
                                        if (a.b_p_bishop[i] == nullptr)
                                        {
                                            a.b_p_bishop[i] = new Bishop(0);
                                            pro(a.b_p_bishop[i], 0);
                                            a.cells[a.b_p_bishop[i]->x][a.b_p_bishop[i]->y].occupied_value = -2;
                                            a.blackPieces.push_back(a.b_p_bishop[i]);
                                            window.close();
                                            return;
                                        }
                                    }

                                  
                                }
                                else if (pr.mouseButton.x >= 50.f && pr.mouseButton.x <= 230.f && pr.mouseButton.y >= 190.f && pr.mouseButton.y <= 250.f)
                                {
                                    //Rook
                                    for (int i = 0; i < 8; i++)
                                    {
                                        if (a.b_p_rook[i] == nullptr)
                                        {
                                            a.b_p_rook[i] = new Rook(0);
                                            pro(a.b_p_rook[i], 0);
                                            a.cells[a.b_p_rook[i]->x][a.b_p_rook[i]->y].occupied_value = 1;
                                            a.blackPieces.push_back(a.b_p_rook[i]);
                                            window.close();
                                            return;
                                        }
                                    }
                                 
                                }
                                else if (pr.mouseButton.x >= 50.f && pr.mouseButton.x <= 230.f && pr.mouseButton.y >= 260.f && pr.mouseButton.y <= 320.f)
                                {
                                    //Knight
                                    for (int i = 0; i < 8; i++)
                                    {
                                        if (a.b_p_knight[i] == nullptr)
                                        {
                                            a.b_p_knight[i] = new Knight(0);
                                            pro(a.b_p_knight[i], 0);
                                            a.cells[a.b_p_knight[i]->x][a.b_p_knight[i]->y].occupied_value = -1;
                                            a.blackPieces.push_back(a.b_p_knight[i]);
                                            window.close();
                                            return;
                                        }
                                    }

                                
                                }
                            }
                        }
                    }
                }
            }
        }
        window.display();
    }
}

void Game::save()
{
   

    m.cells = a.cells;
    m.whitePieces = a.whitePieces;
    m.blackPieces = a.blackPieces;

    m.gameStatus = a.gameStatus; 
    m.whiteTurn = a.whiteTurn;
    m.number_of_moves = a.number_of_moves;
    m.performed_passant = a.performed_passant;
    m.turn = turn;
    m.mov = mov;
    m.sv();
}


void Game::undo()
{
    if (a.md.size() == 0)
    {
        return;
    }
    h = a.md.back();
    a.md.pop_back();
    

    for (auto& i : a.whitePieces)
    {
        if (h.md == i)
        {

                for (auto& f : a.whitePieces)
                {
                    if (f->x == 0 && f->occupied_value == -3 && f==i)
                    {
                        i->isAlive = true;
                        f->piece.setPosition(h.y * 100.0f + 50.f, h.x * 100.f + 50.f);
                        a.whitePieces.pop_back();
                       
                        break;
                    }
                }
               
            a.cells[i->x][i->y].occupied_value = 0;
            a.cells[i->x][i->y].occupied_color = 0;

            i->x = h.x;
            i->y = h.y;

            a.cells[i->x][i->y].occupied_color = 1;
            a.cells[i->x][i->y].occupied_value = i->occupied_value;
        

            i->piece.setPosition(sf::Vector2f(100.f * i->y + 50.f, 100.f * i->x + 50.f));
          
            if (a.w_shr)
            {
                a.cells[a.w_rook[1]->x][a.w_rook[1]->y].occupied_value = 0;
                a.cells[a.w_rook[1]->x][a.w_rook[1]->y].occupied_color = 0;
                a.w_rook[1]->x = 7;
                a.w_rook[1]->y = 7;
                a.w_rook[1]->piece.setPosition(sf::Vector2f(100.f * (a.w_rook[1]->y) + 50.f, 100.f * a.w_rook[1]->x + 50.f));
                a.cells[7][7].occupied_value = 1;
                a.cells[7][7].occupied_color = 1;
            }
            if (a.w_lg)
            {
                a.cells[a.w_rook[0]->x][a.w_rook[0]->y].occupied_value = 0;
                a.cells[a.w_rook[0]->x][a.w_rook[0]->y].occupied_color = 0;
                a.w_rook[0]->x = 7;
                a.w_rook[0]->y = 0;
                a.w_rook[0]->piece.setPosition(sf::Vector2f(100.f * (a.w_rook[0]->y) + 50.f, 100.f * a.w_rook[0]->x + 50.f));
                a.cells[7][0].occupied_value = 1;
                a.cells[7][0].occupied_color = 1;
            }

            a.whiteTurn = !a.whiteTurn;
            a.SetRightSideofWindow();
        }
        if (h.killed == i)
        {
            i->isAlive = true;
            a.cells[i->x][i->y].occupied_color = 1;
            a.cells[i->x][i->y].occupied_value = i->occupied_value;
        }
    }

    for (auto& j : a.blackPieces)
    {

        if (h.md == j)
        {
            for (auto& f : a.blackPieces)
            {
                if (f->x == 0 && f->occupied_value == -3 && f == j)
                {
                    j->isAlive = true;
                    f->piece.setPosition(h.y * 100.0f + 50.f, h.x * 100.f + 50.f);
                    a.blackPieces.pop_back();

                    break;
                }
            }


            a.cells[j->x][j->y].occupied_value = 0;
            a.cells[j->x][j->y].occupied_color = 0;
            j->x = h.x;
            j->y = h.y;

            a.cells[j->x][j->y].occupied_color = -1;
            a.cells[j->x][j->y].occupied_value = j->occupied_value;
        
            j->piece.setPosition(sf::Vector2f(100.f * j->y + 50.f, 100.f * j->x + 50.f));
            
            if (a.b_shr)
            {
                a.cells[a.b_rook[1]->x][a.b_rook[1]->y].occupied_value = 0;
                a.cells[a.b_rook[1]->x][a.b_rook[1]->y].occupied_color = 0;
                    a.b_rook[1]->x = 0;
                    a.b_rook[1]->y = 7;
                    a.b_rook[1]->piece.setPosition(sf::Vector2f(100.f * (a.b_rook[1]->y) + 50.f, 100.f * a.b_rook[1]->x + 50.f));
                    a.cells[0][7].occupied_value = 1;
                    a.cells[0][7].occupied_color = -1;
            }
            if (a.b_lg)
            {
                a.cells[a.b_rook[0]->x][a.b_rook[0]->y].occupied_value = 0;
                a.cells[a.b_rook[0]->x][a.b_rook[0]->y].occupied_color = 0;
                a.b_rook[0]->x = 0;
                a.b_rook[0]->y = 0;
                a.b_rook[0]->piece.setPosition(sf::Vector2f(100.f * (a.b_rook[0]->y) + 50.f, 100.f * a.b_rook[0]->x + 50.f));
                a.cells[0][0].occupied_value = 1;
                a.cells[0][0].occupied_color = -1;
            }
            
            a.whiteTurn = !a.whiteTurn;
            a.SetRightSideofWindow();

            
        }
        if (h.killed == j)
        {
            j->isAlive = true;
            a.cells[j->x][j->y].occupied_color = -1;
            a.cells[j->x][j->y].occupied_value = j->occupied_value;
        }
    }

    int flag=0;
    for (auto& i : a.cells)
    {
        for (auto& j : i)
        {
            std::cout << j.occupied_color <<"  ";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;

    std::string s = mov.getString();

    const auto pos = s.find_last_of(" \t\n");

    s = s.substr(0, pos);
    if (!a.whiteTurn)
    {
        const auto ps = s.find_last_of(" \t\n");
        s = s.substr(0, ps);
    }
    mov.setString(s);
    if (a.whiteTurn)
    {
        trn = false;
    }
  //  turn--;
    en_passant = true;
    a.selected_piece = NULL;
    a.selected = false;
}