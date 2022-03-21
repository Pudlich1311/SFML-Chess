#include"Board.h"

bool en_passant;
bool w_cs = false;
bool b_cs = false;


template < typename T>
void Board::atk(T* piece, int val, vector<vector<Square>>& cell)
{
  
    
    int x = piece->x;
    int y = piece->y;
   
    bool valid = false;
        if (cell[x][y].occupied_value==-3)
        {
            int xi = piece->x - 1;
            int xj = piece->x + 1;

            int yi = piece->y - 1;
            int yj = piece->y + 1;

            if (cell[x][y].occupied_color == 1)
            {
                if (xi>=0 && yj<=7 && yi>=0)
                {
                   atppawn(val, xi, yj);
                   atppawn(val, xi, yi);
                   
                }
            
            }
            if (cell[x][y].occupied_color == -1)
            {
                if (xj <= 7 && yj <= 7 && yi>=0)
                {
                    atppawn(val, xj, yj);
                    atppawn(val, xj, yi);

                }
            }
              
           
        }
        else
        {
            vector<Square> a = piece->getMoves(cell, piece->x, piece->y,1);
            for (int i = 0; i < a.size(); i++)
            {
                if (x == a[i].x && y == a[i].y)
                {
                    valid = true;
                    break;
                } 
                int xi = a[i].x;
                int yi = a[i].y;
            
                if (cell[xi][yi].is_attacked == 0)
                {
                    cell[xi][yi].is_attacked = val;
                    continue;
                }

                if (cell[xi][yi].is_attacked == 2 || cell[xi][yi].is_attacked == 1)
                {
                    if (cell[xi][yi].is_attacked != val)
                    {
                        cell[xi][yi].is_attacked = 3;
                        continue;
                    } 
                    else
                    {
                        continue;
                    }
                }
              
                
               
            }

        }
       
     
           
    return;
}

template<typename Y>
void Board::set(Y* pieces)
{

   

    pieces->piece.setPosition(pieces->y * 100.0f + 50.f, pieces->x * 100.f + 50.f);
    pieces->piece.setOrigin(sf::Vector2f(pieces->piece.getTexture()->getSize().x / 2, pieces->piece.getTexture()->getSize().y / 2));
    pieces->piece.setScale(sf::Vector2f(0.375f, 0.375f));
}

void Board::atppawn(int val, int x, int y)
{
   
        if (cells[x][y].is_attacked == 0)
        {
            cells[x][y].is_attacked = val;
            
        }

        if (cells[x][y].is_attacked == 2 || cells[x][y].is_attacked == 1)
        {
            if (cells[x][y].is_attacked != val)
            {
                cells[x][y].is_attacked = 3;
               
            }
        }
    
}

void Board::start()
{
    
    cells.resize(8, vector<Square>(8));

    w_king = new King(1);
    whitePieces.push_back(w_king);

    w_queen = new Queen(1);
    whitePieces.push_back(w_queen);

    b_king = new King(0);
    blackPieces.push_back(b_king);

    b_queen = new Queen(0);
    blackPieces.push_back(b_queen);

    for (int i = 0; i < 8; i++)
    {
        b_pawn[i] = new Pawn(0);
        blackPieces.push_back(b_pawn[i]);
        w_pawn[i] = new Pawn(1);
        whitePieces.push_back(w_pawn[i]);

    }
    for (int i = 0; i < 2; i++)
    {
        w_bishop[i] = new Bishop(1);
        whitePieces.push_back(w_bishop[i]);
        w_rook[i] = new Rook(1);
        whitePieces.push_back(w_rook[i]);
        w_knight[i] = new Knight(1);
        whitePieces.push_back(w_knight[i]);
        b_bishop[i] = new Bishop(0);
        blackPieces.push_back(b_bishop[i]);
        b_rook[i] = new Rook(0);
        blackPieces.push_back(b_rook[i]);
        b_knight[i] = new Knight(0);
        blackPieces.push_back(b_knight[i]);

    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cells[i][j].x = i;
            cells[i][j].y = j;
        }
    }
}

void Board::place(sf::Color c1, sf::Color c2)
{
    
    for (int i = 0; i < 8; i++)
    {
        b_pawn[i]->y = i;
        b_pawn[i]->x = 1;
        w_pawn[i]->y = i;
        w_pawn[i]->x = 6;
    
    }
    w_king->x = 7;
    w_king->y = 4;


    b_king->x = 0;
    b_king->y = 4;


    w_queen->x = 7;
    w_queen->y = 3;

    b_queen->x = 0;
    b_queen->y = 3;

    b_bishop[0]->y = 2;
    b_bishop[1]->y = 5;
    b_bishop[0]->x = 0;
    b_bishop[1]->x = 0;

    b_rook[0]->y = 0;
    b_rook[1]->y = 7;
    b_rook[0]->x = 0;
    b_rook[1]->x = 0;

    b_knight[0]->y = 1;
    b_knight[1]->y = 6;
    b_knight[0]->x = 0;
    b_knight[1]->x = 0;

    w_bishop[0]->y = 2;
    w_bishop[1]->y = 5;
    w_bishop[0]->x = 7;
    w_bishop[1]->x = 7;

    w_rook[0]->y = 0;
    w_rook[1]->y = 7;
    w_rook[0]->x = 7;
    w_rook[1]->x = 7;

    w_knight[0]->y = 1;
    w_knight[1]->y = 6;
    w_knight[0]->x = 7;
    w_knight[1]->x = 7;


    for (auto& i : whitePieces)
    {
        set(i);
    }

    for (auto& j : blackPieces)
    {
        set(j);
    }
   
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cells[i][j].square.setPosition(sf::Vector2f(j * 100.0f, i * 100.0f));
            cells[i][j].square.setSize(sf::Vector2f(100.f, 100.f));
            cells[i][j].square.setFillColor((i + j) % 2 ? c2 : c1);
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cells[7 - i][j].occupied_color = 1;
            cells[i][j].occupied_color = -1;
        }
    }
    // loop to set up pawns on board
    for (int j = 0; j < 8; j++)
    {
        
        cells[1][j].occupied_value = -3;
        cells[6][j].occupied_value = -3;
    }
    cells[0][0].occupied_value = 1;
    cells[7][7].occupied_value = 1;
    cells[7][0].occupied_value = 1;
    cells[0][7].occupied_value = 1; // setting up rook
    cells[0][1].occupied_value = -1;
    cells[7][6].occupied_value = -1;
    cells[0][6].occupied_value = -1;
    cells[7][1].occupied_value = -1; // setting up knight
    cells[0][2].occupied_value = -2;
    cells[7][5].occupied_value = -2;
    cells[0][5].occupied_value = -2;
    cells[7][2].occupied_value = -2; // setting up bishop
    cells[7][3].occupied_value = 2;
    cells[0][3].occupied_value = 2; // setting up queen
    cells[7][4].occupied_value = 3;
    cells[0][4].occupied_value = 3; // setting up king
}


void Board::addmoves(vector<vector<Square>>& cells, vector<vector<Square>>& temp, Pieces* attacker, int a, int b, int x, int y, King* king)
{
    if (attacker->is_attacker && attacker->isAlive)
    {

        if (cells[a][b].occupied_value == -3)
        {
            if (x == king->x)
            {

                setattack(temp);
                if (!king->isCheck(temp, king->x, king->y))
                {
                    moves.push_back(cells[x][y]);
                    return;
                }

            }

        }

        if (x == attacker->x && x == king->x)
        {

            int yi = king->y;
            int yj = attacker->y;
            if (yi >= y && y >= yj)
            {

                if (cells[x][y].occupied_value == 0 || cells[x][y].occupied_value == attacker->occupied_value)
                {
                    moves.push_back(cells[x][y]);
                    return;
                }

            }
            else if (yi <= y && y <= yj)
            {

                if (cells[x][y].occupied_value == 0 || cells[x][y].occupied_value == attacker->occupied_value)
                {
                    moves.push_back(cells[x][y]);
                    return;
                }

            }

        }

        if (y == attacker->y && y == king->y)
        {
            int xi = king->x;
            int xj = attacker->x;

            if (xi >= x && x >= xj)
            {
                if (cells[x][y].occupied_value == 0 || cells[x][y].occupied_value == attacker->occupied_value)
                {
                    moves.push_back(cells[x][y]);
                    return;
                }

            }
            else if (xi <= x && x <= xj)
            {

                if (cells[x][y].occupied_value == 0 || cells[x][y].occupied_value == attacker->occupied_value)
                {
                    moves.push_back(cells[x][y]);
                    return;
                }

            }

        }

        else if (attacker->y != king->y && attacker->x != king->x)
        {

            //using simple math to determine if a cell is on a diagonal between the king and attacker
            int yi = king->y;
            int xi = king->x;
            int yj = attacker->y;
            int xj = attacker->x;
            float e = (xj - xi) / (yj - yi);
            if ((yi <= y && y <= yj) || (yi >= y && y >= yj))
            {
                if ((xi <= x && x <= xj) || (xi >= x && x >= xj))
                {
                    if (x - xj == e * (y - yj))
                    {
                        if (cells[x][y].occupied_value == 0 || cells[x][y].occupied_value == attacker->occupied_value)
                        {
                            moves.push_back(cells[x][y]);
                            return;
                        }
                    }
                }
            }
        }
        if (x == attacker->x && y == attacker->y)
        {
            moves.push_back(cells[x][y]);

        }

    }
}

void Board::checkifvalid(vector<Square>& moves, vector<vector<Square>>& cells)
{
    
    vector<vector<Square>> temp = cells;
    vector<Square> tu = moves;
    int a = selected_piece->x;
    int b = selected_piece->y;
    Pieces* attacker;
    vector<Square> mv;

    if (cells[a][b].occupied_value == 3)
    {
        return;
    }
  
    
    moves.clear();

    for (auto&p : tu)
    {
        int x =p.x;
        int y =p.y;

        for (auto& a : temp)
        {
            for (auto& b : a)
            {
                b.is_attacked = 0;
            }
        }

 
            temp[x][y].occupied_color = (whiteTurn == 1) ? 1 : -1;
            temp[x][y].occupied_value = selected_piece->occupied_value;
            temp[a][b].occupied_value = 0;
            temp[selected_piece->x][selected_piece->y].occupied_color = 0;


            setattack(temp);

           
            
            if (selected_piece->isWhite)
            {

                if (w_king->isCheck(cells, w_king->x, w_king->y))
                {
                    continue;
                }
                else if (!w_king->isCheck(temp, w_king->x, w_king->y))
                {

                    moves.push_back(cells[x][y]);
                }

            }
            else if (!selected_piece->isWhite)
            {
              
                if (b_king->isCheck(cells, b_king->x, b_king->y))
                {
                    continue;

                }
                else if (!b_king->isCheck(temp, b_king->x, b_king->y))
                {

                    moves.push_back(cells[x][y]);
                }
 
            }

    }

        if (moves.size() == 0)
        {
 
            for (auto& p : tu)
            {
                int flag = 0;
                int x = p.x;
                int y = p.y;
      
                for (auto& a : temp)
                {
                    for (auto& b : a)
                    {
                        b.is_attacked = 0;
                    }
                }

                temp[x][y].occupied_color = (whiteTurn == 1) ? 1 : -1;
                temp[x][y].occupied_value = selected_piece->occupied_value;
                temp[a][b].occupied_value = 0;
                temp[selected_piece->x][selected_piece->y].occupied_color = 0;

               
                setattack(temp);
                

                if (selected_piece->isWhite)
                {
                    if (w_king->isCheck(cells, w_king->x, w_king->y))
                    {
                        for (auto& i : blackPieces)
                        {
                            if (!i->isAlive)
                            {
                                continue;
                            }
                            setattack(temp);
                            attacker = i;

                            mv = attacker->getMoves(cells, attacker->x, attacker->y, 0);

                            addmoves(cells, temp, attacker, a, b, x, y, w_king);
                            
                        }
                    }
                }
                else if (!selected_piece->isWhite)
                {
                    if (b_king->isCheck(cells, b_king->x, b_king->y))
                    {
                        for (auto& i : whitePieces)
                        {
                            if (!i->isAlive)
                            {
                                continue;
                            }
                            setattack(temp);
                            attacker = i;
                           
                            mv = attacker->getMoves(cells, attacker->x, attacker->y, 0);
                           
                            addmoves(cells, temp, attacker, a, b, x, y, b_king);
                           
                        }
                    }
                }
            }
        }
}


void Board::setattack(vector<vector<Square>>& cell)
{
   

    for (auto& white : whitePieces)
    {
        if (!white->isAlive)
        {
            continue;
        }
        atk(white,1,cell);  
    }
    
    for (auto& black : blackPieces)
    {
        if (!black->isAlive)
        {
            continue;
        }
        atk(black, 2,cell);
    }
}

void Board::pushmove(Pieces* move, int x, int y)
{
    moved = move;
    xi = x;
    yi = y;
}


void Board::moveSelected(vector<vector<Square>>& Cells, int x, int y)
{
    y_pr = 10;
    capture = false;
    performed_move = false;
    w_lg = false;
    w_shr = false;
    b_lg = false;
    b_shr = false;
    killed = NULL;
    ht = {};

    for (auto& a : Cells)
    {
        for (auto& b : a)
        {
            b.is_attacked = 0;
        }
    }

    if (selected_piece == NULL)
        return;
    bool valid = false;
    
    
    for (auto& i: moves)
    {
        
        if (x == i.x && y == i.y)
        {
         
            valid = true;
          
        }
    }

    if (valid)
    {
        
        int a = selected_piece->x, b = selected_piece->y;
        c = a;
        d = b;

        if (Cells[x][y].occupied_value == 0 && Cells[a][b].occupied_value == -3 && y != b)
        {
            performed_passant = true;
        }

       if (Cells[x][y].occupied_color != 0 && Cells[x][y].occupied_color != Cells[a][b].occupied_color)
        {
            if (Cells[x][y].occupied_color == 1)
            {
                for (int i = 0; i < whitePieces.size(); i++)
                {
                    if (whitePieces[i]->x == x && whitePieces[i]->y == y)
                    {
                        whitePieces[i]->isAlive = false;
                        killed = whitePieces[i];
                        capture = true;
                    }
                }
            }
            else
            {
                for (int i = 0; i < blackPieces.size(); i++)
                {
                    if (blackPieces[i]->x == x && blackPieces[i]->y == y)
                    {
                        blackPieces[i]->isAlive = false;
                        killed = blackPieces[i];
                        capture = true;
                    }
                }
            }
        } 
       if (performed_passant)
       {
           if (Cells[a][b].occupied_color == 1 && Cells[a][b].occupied_value == -3)
           {
               if (Cells[x+1][y].occupied_color == -1 && Cells[x+1][y].occupied_value == -3)
               {
                   for (int i = 0; i < blackPieces.size(); i++)
                   {
                       if (blackPieces[i]->x == x + 1 && blackPieces[i]->y == y)
                       {
                           blackPieces[i]->isAlive = false;
                           killed = blackPieces[i];
                          // delete blackPieces[i];
                           performed_passant = false;
                           Cells[x + 1][y].occupied_color = 0;
                           Cells[x + 1][y].occupied_value = 0;
                       }
                   }
               }
           }
           else if(Cells[a][b].occupied_color == -1 && Cells[a][b].occupied_value == -3)
           {
               if (Cells[x - 1][y].occupied_color == 1 && Cells[x - 1][y].occupied_value == -3)
               {
                   for (int i = 0; i < whitePieces.size(); i++)
                   {
                       if (whitePieces[i]->x == x - 1 && whitePieces[i]->y == y)
                       {
                           whitePieces[i]->isAlive = false;
                           killed = whitePieces[i];
                          // delete whitePieces[i];
                           performed_passant = false;
                           Cells[x-1][y].occupied_color = 0;
                           Cells[x-1][y].occupied_value = 0;

                       }
                   }
               }
           }
       }
     
        Cells[x][y].occupied_color = (whiteTurn == 1) ? 1 : -1;
        Cells[x][y].occupied_value = selected_piece->occupied_value;
        Cells[a][b].occupied_value = 0;
        Cells[selected_piece->x][selected_piece->y].occupied_color = 0;
        en_passant = false;

        if (whiteTurn)
        {
            en_passant = false;
            if (w_king->x == a && w_king->y == b)
            {

                w_king->x = x, w_king->y = y;
                pushmove(w_king, a, b);

                if (y == 2)
                {
                    
                    cells[x][3].occupied_value = 1;
                    cells[x][3].occupied_color = 1;
                    cells[x][0].occupied_value = 0;
                    cells[x][0].occupied_color = 0;
                 
                   
                    if (w_rook[0]->x == 7 && w_rook[0]->y == 0)
                    {
                        w_rook[0]->x = 7;
                        w_rook[0]->y = 3;
                        w_rook[0]->piece.setPosition(sf::Vector2f(100.f * (y + 1) + 50.f, 100.f * x + 50.f));
                        w_lg = true;
                    }
                    w_cs = false;
                }
                if (y == 6)
                {
                   
                    cells[x][5].occupied_color = 1;
                    cells[x][5].occupied_value = 1;
                    cells[x][7].occupied_color = 0;
                    cells[x][7].occupied_value = 0;
                    if (w_rook[1]->x == 7 && w_rook[1]->y == 7)
                    {
                        w_rook[1]->x = 7;
                        w_rook[1]->y = 5;
                        w_rook[1]->piece.setPosition(sf::Vector2f(100.f * (y-1) + 50.f, 100.f * x + 50.f));
                        w_shr = true;
                    }
                    w_cs = false;
                }
               
                
            } 
            else if (w_queen->x == a && w_queen->y == b)
            {
                w_queen->x = x, w_queen->y = y;
                pushmove(w_queen, a, b);
            }
            else if (w_bishop[0]->x == a && w_bishop[0]->y == b)
            {
                w_bishop[0]->x = x, w_bishop[0]->y = y;
                pushmove(w_bishop[0], a, b);
            }
            else if (w_bishop[1]->x == a && w_bishop[1]->y == b)
            {
                w_bishop[1]->x = x, w_bishop[1]->y = y;
                pushmove(w_bishop[1], a, b);
            }
            if (w_knight[0]->x == a && w_knight[0]->y == b)
            {
                w_knight[0]->x = x, w_knight[0]->y = y;
                pushmove(w_knight[0], a, b);
            }
            else if (w_knight[1]->x == a && w_knight[1]->y == b)
            {
                w_knight[1]->x = x, w_knight[1]->y = y;
                pushmove(w_bishop[1], a, b);
            }
            
          
            if (w_rook[0]->x == a && w_rook[0]->y == b)
            {
                w_rook[0]->x = x, w_rook[0]->y = y;
                pushmove(w_rook[0], a, b);
            }
            else if (w_rook[1]->x == a && w_rook[1]->y == b)
            {
                w_rook[1]->x = x, w_rook[1]->y = y;
                pushmove(w_rook[1], a, b);
            }
            else if(cells[x][y].occupied_value==-3)
            {
                for (int i = 0; i < 8; i++)
                {
                    if (w_pawn[i]->x == a && w_pawn[i]->y == b)
                    {
                        if (x == 4)
                        {
                            en_passant = true;
                        }
                       
                        w_pawn[i]->x = x;
                        w_pawn[i]->y = y;
                        pushmove(w_pawn[i], a, b);
                        
                        if (x == 0)
                        {
                            y_pr= w_pawn[i]->y = y;
                            w_promote = true;
                        }
                        break;
                    }
                }
            }
            for (int i = 0; i < 8; i++)
            {
                if (w_p_bishop[i] != nullptr && w_p_bishop[i]->x == a && w_p_bishop[i]->y == b)
                {
                    w_p_bishop[i]->x = x, w_p_bishop[i]->y = y;
                    pushmove(w_p_bishop[i], a, b);
                    break;
                }

                if (w_p_knight[i] != nullptr && w_p_knight[i]->x == a && w_p_knight[i]->y == b)
                {
                    w_p_knight[i]->x = x, w_p_knight[i]->y = y;
                    pushmove(w_p_knight[i], a, b);
                    break;
                }

                if (w_p_queen[i] != nullptr && w_p_queen[i]->x == a && w_p_queen[i]->y == b)
                {
                    w_p_queen[i]->x = x, w_p_queen[i]->y = y;
                    pushmove(w_p_queen[i], a, b);
                    break;
                }

                if (w_p_rook[i] != nullptr && w_p_rook[i]->x == a && w_p_rook[i]->y == b)
                {
                    w_p_rook[i]->x = x, w_p_rook[i]->y = y;
                    pushmove(w_p_rook[i], a, b);
                    break;
                }
            }
        }
        else 
        {
        en_passant = false;

            if (b_king->x == a && b_king->y == b)
            {
                b_king->x = x, b_king->y = y;
                pushmove(b_king, a, b);

                if (y == 2)
                {
                    
                    cells[x][3].occupied_value = 1;
                    cells[x][3].occupied_color = -1;
                    cells[x][0].occupied_value = 0;
                    cells[x][0].occupied_color = 0;

                    if (b_rook[0]->x == 0 && b_rook[0]->y == 0)
                    {
                        b_rook[0]->x = 0;
                        b_rook[0]->y = 3;
                        b_rook[0]->piece.setPosition(sf::Vector2f(100.f * (y + 1) + 50.f, 100.f * x + 50.f));
                        b_lg = true;
                    }
                }
                if (y == 6)
                {
                    b_cs = false;
                    cells[x][5].occupied_color = -1;
                    cells[x][5].occupied_value = 1;
                    cells[x][7].occupied_color = 0;
                    cells[x][7].occupied_value = 0;

                    if (b_rook[1]->x == 0 && b_rook[1]->y == 7)
                    {
                        b_rook[1]->x = 0;
                        b_rook[1]->y = 5;
                        b_rook[1]->piece.setPosition(sf::Vector2f(100.f * (y - 1) + 50.f, 100.f * x + 50.f));
                        b_shr = true;
                    }
                    
                }
            }
            else if (b_queen->x == a && b_queen->y == b)
            {
                b_queen->x = x, b_queen->y = y;
                pushmove(b_queen, a, b);
            }
            else if (b_bishop[0]->x == a && b_bishop[0]->y == b)
            {
                b_bishop[0]->x = x, b_bishop[0]->y = y;
                pushmove(b_bishop[0], a, b);
            }
            else if (b_bishop[1]->x == a && b_bishop[1]->y == b)
            {
                b_bishop[1]->x = x, b_bishop[1]->y = y;
                pushmove(b_bishop[1], a, b);
            }
            else if (b_knight[0]->x == a && b_knight[0]->y == b)
            {
                b_knight[0]->x = x, b_knight[0]->y = y;
                pushmove(b_knight[0], a, b);
            }
            else if (b_knight[1]->x == a && b_knight[1]->y == b)
            {
                b_knight[1]->x = x, b_knight[1]->y = y;
                pushmove(b_knight[1], a, b);
            }
            else if (b_rook[0]->x == a && b_rook[0]->y == b)
            {
                b_rook[0]->x = x, b_rook[0]->y = y;
                pushmove(b_rook[0], a, b);
                
            }
            else if (b_rook[1]->x == a && b_rook[1]->y == b)
            {
                b_rook[1]->x = x, b_rook[1]->y = y;
                pushmove(b_rook[1], a, b);
               
            }
            else if(cells[x][y].occupied_value==-3)
            {
                for (int i = 0; i < 8; i++)
                {
                    if (b_pawn[i]->x == a && b_pawn[i]->y == b)
                    {
                        if (x == 3)
                        {
                            en_passant = true;
                        }
                    
                        b_pawn[i]->x = x;
                        b_pawn[i]->y = y;
                        pushmove(b_pawn[i], a, b);
                        if (x == 7)
                        {
                            y_pr = b_pawn[i]->y;
                            b_promote = true;
                        }
                        
                    }
                }
            }
            for (int i = 0; i < 8; i++)
            {
                if (b_p_bishop[i] != nullptr && b_p_bishop[i]->x == a && b_p_bishop[i]->y == b)
                {
                    b_p_bishop[i]->x = x, b_p_bishop[i]->y = y;
                    pushmove(b_p_bishop[i], a, b);
                    break;
                }

                if (b_p_knight[i] != nullptr && b_p_knight[i]->x == a && b_p_knight[i]->y == b)
                {
                    b_p_knight[i]->x = x, b_p_knight[i]->y = y;
                    pushmove(b_p_knight[i], a, b);
                    break;
                }

                if (b_p_queen[i] != nullptr && b_p_queen[i]->x == a && b_p_queen[i]->y == b)
                {
                    b_p_queen[i]->x = x, b_p_queen[i]->y = y;
                    pushmove(b_p_queen[i], a, b);
                    break;
                }

                if (b_p_rook[i] != nullptr && b_p_rook[i]->x == a && b_p_rook[i]->y == b)
                {
                    b_p_rook[i]->x = x, b_p_rook[i]->y = y;
                    pushmove(b_p_rook[i], a, b);
                    break;
                }
            }

        }
      

        ht.md = moved;
        ht.killed = killed;
        ht.x = xi;
        ht.y = yi;
        md.push_back(ht);
        selected_piece->piece.setPosition(sf::Vector2f(100.f * y + 50.f, 100.f * x + 50.f));
        whiteTurn = !whiteTurn;
        SetRightSideofWindow();
        performed_move = true;

    }

        setattack(Cells);


      
        try {
            vector<vector<Square>> temp = Cells;

            if (w_king->isCheck(Cells, w_king->x, w_king->y))
            {
                if (!w_king->possibleMoves.empty())
                {
                    selected_piece = NULL;
                    selected = false;
                    return;
                }
                for (auto& i : whitePieces)
                {
                    if (i->isAlive)
                    {
                        
                        moves.clear();
                        moves = i->getMoves(cells, i->x, i->y, 0);

                        if (i != w_king)
                        checkifvalid(moves, temp);

                        if (!i->possibleMoves.empty())
                        {

                            if (!moves.empty())
                            {
                                selected_piece = NULL;
                                selected = false;
                                moves.clear();
                                return;
                            }
                        }
                    }
                    

                }
                throw 1;
            }
            else if (b_king->isCheck(Cells, b_king->x, b_king->y))
            {
                
               
                for (auto& i : blackPieces)
                {
                
                    if (i->isAlive)
                    {
                        moves.clear();
                        moves = i->getMoves(cells, i->x, i->y, 0);

                        if(i != b_king)
                        checkifvalid(moves, temp);

                        if (!i->possibleMoves.empty())
                        {

                            if (!moves.empty())
                            {
                                selected_piece = NULL;
                                selected = false;
                                moves.clear();
                                return;
                            }
                        }
                    }
                       
                    
                    
                }
                throw 'a';
            }
        }

        catch (int)
        {
            this->gameOver(1);
        }
        catch (char)
        {
            this->gameOver(2);
        }
      
      

    selected_piece = NULL;
    selected = false;
}

void Board::gameOver(int a)
{
    isOver = true;
    if (a == 2)
        situation.setString("CHECKMATE! \n White Won!!");
    else if(a==1)
        situation.setString("CHECKMATE! \n Black Won!!");
}


void Board::SetRightSideofWindow()
{
    number_of_moves++;
   
    sf::String p1 = player1.getString();
    sf::String p2 = player2.getString();
    sf::String play1 = p1.substring(0, p1.getSize() - 1);
    sf::String play2 = p2.substring(0, p2.getSize() - 1);
    if (whiteTurn == 0 && !isOver)
    {
        chance.setString(play1 + " Turn");
    }
    else if (whiteTurn == 1 && !isOver)
    {
        chance.setString(play2 + " Turn");
    }
}

Board::~Board()
{ 
    delete w_king;
    delete b_king;
    delete w_queen;
    delete b_queen;
    for (int i = 0; i < 2; i++)
    {
        delete w_knight[i];
        delete b_knight[i];
        delete w_bishop[i];
        delete b_bishop[i];
        delete w_rook[i];
        delete b_rook[i];
    }
    for (int i = 0; i < 8; i++)
    {
        delete w_pawn[i];
        delete b_pawn[i];
        delete w_p_bishop[i];
        delete w_p_queen[i];
        delete w_p_knight[i];
        delete w_p_rook[i];

        delete b_p_bishop[i];
        delete b_p_queen[i];
        delete b_p_knight[i];
        delete b_p_rook[i];
    }

    
}