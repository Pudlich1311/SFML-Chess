#include <iostream>
#include "Game.h"
#include "Pieces.h"
#include "Queen.h"

Queen::Queen(int color)
{
    possibleMoves.clear();
    isWhite = color;
    isAlive = true;
    blackQueen.loadFromFile("Textures/b_queen.png");
    whiteQueen.loadFromFile("Textures/w_queen.png");
    piece.setTexture((color == 0) ? blackQueen : whiteQueen);
  
    occupied_value = 2;
 
}

vector<Square> Queen::getMoves(vector<vector<Square>>& cells, int x, int y, int flag)
{
   is_attacker = false;
    possibleMoves.clear();
    int a = x + 1, b = y + 1;
    while (a <= 7 && b <= 7)
    {
        if (cells[a][b].occupied_value == 0)
            possibleMoves.push_back(cells[a][b]);
        else if (cells[a][b].occupied_color == cells[x][y].occupied_color)
        {
            if (flag == 1)
            {
                possibleMoves.push_back(cells[a][b]);
                break;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (flag == 1)
            {
                if (cells[a][b].occupied_value == 3)
                {
                    possibleMoves.push_back(cells[a][b]);
                }
                else
                {
                    possibleMoves.push_back(cells[a][b]);
                    break;
                }
            }
            if (flag == 0)
            {
                possibleMoves.push_back(cells[a][b]);
                if (cells[a][b].occupied_value == 3)
                {
                    is_attacker = true;
                }
                break;
            }
        }
        a++;
        b++;
    }
    a = x + 1, b = y - 1;
    while (a <= 7 && b >= 0)
    {
        if (cells[a][b].occupied_value == 0)
            possibleMoves.push_back(cells[a][b]);
        else if (cells[a][b].occupied_color == cells[x][y].occupied_color)
        {
            if (flag == 1)
            {
                possibleMoves.push_back(cells[a][b]);
                break;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (flag == 1)
            {
                if (cells[a][b].occupied_value == 3)
                {
                    possibleMoves.push_back(cells[a][b]);
                }
                else
                {
                    possibleMoves.push_back(cells[a][b]);
                    break;
                }
            }
            if (flag == 0)
            {
                possibleMoves.push_back(cells[a][b]);
                if (cells[a][b].occupied_value == 3)
                {
                    is_attacker = true;
                }
                break;
            }
        }
        a++;
        b--;
    }
    a = x - 1, b = y - 1;
    while (a >= 0 && b >= 0)
    {
        if (cells[a][b].occupied_value == 0)
            possibleMoves.push_back(cells[a][b]);
        else if (cells[a][b].occupied_color == cells[x][y].occupied_color)
        {
            if (flag == 1)
            {
                possibleMoves.push_back(cells[a][b]);
                break;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (flag == 1)
            {
                if (cells[a][b].occupied_value == 3)
                {
                    possibleMoves.push_back(cells[a][b]);
                }
                else
                {
                    possibleMoves.push_back(cells[a][b]);
                    break;
                }
            }
            if (flag == 0)
            {
                possibleMoves.push_back(cells[a][b]);
                if (cells[a][b].occupied_value == 3)
                {
                    is_attacker = true;
                }
                break;
            }
        }
        a--;
        b--;
    }
    a = x - 1, b = y + 1;
    while (a >= 0 && b <= 7)
    {
        if (cells[a][b].occupied_value == 0)
            possibleMoves.push_back(cells[a][b]);
        else if (cells[a][b].occupied_color == cells[x][y].occupied_color)
        {
            if (flag == 1)
            {
                possibleMoves.push_back(cells[a][b]);
                break;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (flag == 1)
            {
                if (cells[a][b].occupied_value == 3)
                {
                    possibleMoves.push_back(cells[a][b]);
                }
                else
                {
                    possibleMoves.push_back(cells[a][b]);
                    break;
                }
            }
            if (flag == 0)
            {
                possibleMoves.push_back(cells[a][b]);
                if (cells[a][b].occupied_value == 3)
                {
                    is_attacker = true;
                }
                break;
            }
        }
        a--;
        b++;
    }
    int r = x - 1;
    while (r >= 0)
    {
        if (cells[r][y].occupied_value == 0)
            possibleMoves.push_back(cells[r][y]);
        else if (cells[r][y].occupied_color == cells[x][y].occupied_color)
        {
            if (flag == 1)
            {
                possibleMoves.push_back(cells[r][y]);
                break;
            }
            else
            {
                break;
            }
        }
        else if (cells[r][y].occupied_color != cells[x][y].occupied_color)
        {
            if (flag == 1)
            {
                if (cells[r][y].occupied_value == 3)
                {
                    possibleMoves.push_back(cells[r][y]);
                }
                else
                {
                    possibleMoves.push_back(cells[r][y]);
                    break;
                }
            }
            if (flag == 0)
            {
                possibleMoves.push_back(cells[r][y]);
                if (cells[r][y].occupied_value == 3)
                {
                    is_attacker = true;
                }
                break;
            }
        }
        r--;
    }
    r = x + 1;
    while (r <= 7)
    {
        if (cells[r][y].occupied_value == 0)
            possibleMoves.push_back(cells[r][y]);
        else if (cells[r][y].occupied_color == cells[x][y].occupied_color)
        {
            if (flag == 1)
            {
                possibleMoves.push_back(cells[r][y]);
                break;
            }
            else
            {
                break;
            }
        }
        else if (cells[r][y].occupied_color != cells[x][y].occupied_color)
        {
            if (flag == 1)
            {
                if (cells[r][y].occupied_value == 3)
                {
                    possibleMoves.push_back(cells[r][y]);
                }
                else
                {
                    possibleMoves.push_back(cells[r][y]);
                    break;
                }
            }
            if (flag == 0)
            {
                possibleMoves.push_back(cells[r][y]);
                if (cells[r][y].occupied_value == 3)
                {
                    is_attacker = true;
                }
                break;
            }
        }
        r++;
    }
    r = y - 1;
    while (r >= 0)
    {
        if (cells[x][r].occupied_value == 0)
            possibleMoves.push_back(cells[x][r]);
        else if (cells[x][r].occupied_color == cells[x][y].occupied_color)
        {
            if (flag == 1)
            {
                possibleMoves.push_back(cells[x][r]);
                break;
            }
            else
            {
                break;
            }
        }
        else if (cells[x][r].occupied_color != cells[x][y].occupied_color)
        {
            if (flag == 1)
            {
                if (cells[x][r].occupied_value == 3)
                {
                    possibleMoves.push_back(cells[x][r]);
                }
                else
                {
                    possibleMoves.push_back(cells[x][r]);
                    break;
                }
            }
            if (flag == 0)
            {
                possibleMoves.push_back(cells[x][r]);
                if (cells[x][r].occupied_value == 3)
                {
                    is_attacker = true;
                }
                break;
            }
        }
        r--;
    }
    r = y + 1;
    while (r <= 7)
    {
        if (cells[x][r].occupied_value == 0)
            possibleMoves.push_back(cells[x][r]);
        else if (cells[x][r].occupied_color == cells[x][y].occupied_color)
        {
            if (flag == 1)
            {
                possibleMoves.push_back(cells[x][r]);
                break;
            }
            else
            {
                break;
            }
        }
        else if (cells[x][r].occupied_color != cells[x][y].occupied_color)
        {
            if (flag == 1)
            {
                if (cells[x][r].occupied_value == 3)
                {
                    possibleMoves.push_back(cells[x][r]);
                }
                else
                {
                    possibleMoves.push_back(cells[x][r]);
                    break;
                }
            }
            if (flag == 0)
            {
                possibleMoves.push_back(cells[x][r]);
                if (cells[x][r].occupied_value == 3)
                {
                    is_attacker = true;
                }
                break;
            }
        }
        r++;
    } 
    return possibleMoves;
}