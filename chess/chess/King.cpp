#include <iostream>
#include <vector>
#include "Square.h"
#include "Pieces.h"
#include "King.h"
using namespace std;

King::King(int color)
{
    possibleMoves.clear();
    isWhite = color;
    isAlive = true;
    blackKing.loadFromFile("Textures/b_king.png");
    whiteKing.loadFromFile("Textures/w_king.png");
    piece.setTexture((color == 0) ? blackKing : whiteKing);
    occupied_value = 3;
  
}
vector<Square> King::getMoves(vector<vector<Square>>& Cells, int x, int y, int flag)
{
    possibleMoves.clear();
   
    int dx[] = { 1, 1, 1, -1, -1, -1, 0, 0 }; // all possible moves.
    int dy[] = { 1, -1, 0, -1, 1, 0, -1, 1 }; // all possible moves.
    for (int i = 0; i < 8; i++)
    {
        if (x + dx[i] > 7 || x + dx[i] < 0)
            continue;
        if (y + dy[i] > 7 || y + dy[i] < 0)
            continue;
        if (Cells[x + dx[i]][y + dy[i]].occupied_color == Cells[x][y].occupied_color)
            continue;
        if (Cells[x + dx[i]][y + dy[i]].is_attacked == 3)
            continue;
        if (flag == 0)
        {
            if (isCheck(Cells, x + dx[i], y + dy[i]))
                continue;
        }

        possibleMoves.push_back(Cells[x + dx[i]][y + dy[i]]);
    }

    if (Cells[x][y].occupied_color==1)
    {
        if (x==7 && y==4)
        {
            if (Cells[x][7].occupied_value == 1 && Cells[x][7].occupied_color == 1 && Cells[x][6].occupied_value == 0 && Cells[x][5].occupied_value == 0)
            {
                if (!isCheck(Cells, x, 6))
                {
                    if (!isCheck(Cells, x, y))
                    {
                        possibleMoves.push_back(Cells[x][6]);
                        w_cs = true;
                    }
                }

            }
            else if (Cells[x][0].occupied_value == 1 && Cells[x][0].occupied_color == 1)
            {
                if (Cells[x][1].occupied_value == 0 && Cells[x][2].occupied_value == 0 && Cells[x][3].occupied_value == 0)
                {
                    if (!isCheck(Cells, x, 2))
                    {
                        if (!isCheck(Cells, x, y))
                        {
                            possibleMoves.push_back(Cells[x][2]);
                            w_cs = true;
                        }
                    }
                }
            }
            
            
        }
        
    }
    else if (Cells[x][y].occupied_color == -1)
    {
        if (x == 0 && y == 4)
        {
            if (Cells[x][7].occupied_value == 1 && Cells[x][7].occupied_color == -1 && Cells[x][6].occupied_value == 0 && Cells[x][5].occupied_value == 0)
            {
                if (!isCheck(Cells, x, 6))
                {
                    if (!isCheck(Cells, x, y))
                    {
                        possibleMoves.push_back(Cells[x][6]);
                    }
                }

            }
            else if (Cells[x][0].occupied_value == 1 && Cells[x][0].occupied_color == -1)
            {
                if (Cells[x][1].occupied_value == 0 && Cells[x][2].occupied_value == 0 && Cells[x][3].occupied_value == 0)
                {
                    if (!isCheck(Cells, x, 2))
                    {
                        if (!isCheck(Cells, x, y))
                        {
                            possibleMoves.push_back(Cells[x][2]);
                        }
                    }
                }
            }


        }

    }
    return possibleMoves;
}


bool King::isCheck(vector<vector<Square>>&Cells, int x, int y)
{
   
    if (this->isWhite)
    {
        if (Cells[x][y].is_attacked == 2 || Cells[x][y].is_attacked == 3)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    if (!this->isWhite)
    {
        if (Cells[x][y].is_attacked == 1 || Cells[x][y].is_attacked == 3)
        {
            return true;
        }
        else
        {
            return false;
        }
    } 
    
  
     
}

bool King::isCheckmate(vector<vector<Square>>& Cells, int x, int y)
{
    if (isCheck(Cells, x, y))
    {
        if (possibleMoves.empty())
        {
            return true;
        }
    }
    return false;
}

