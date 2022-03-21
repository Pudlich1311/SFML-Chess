#include <iostream>
#include "Game.h"
#include <vector>
#include "Pieces.h"
#include "Bishop.h"
using namespace std;

Bishop::Bishop(int color)
{
    possibleMoves.clear();
    isWhite = color;
    isAlive = true;
    blackBishop.loadFromFile("Textures/b_bishop.png");
    whiteBishop.loadFromFile("Textures/w_bishop.png");
    occupied_value = -2;
    piece.setTexture((color == 0) ? blackBishop : whiteBishop);
}
vector<Square> Bishop::getMoves(vector<vector<Square>>& cells, int x, int y, int flag)
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
    return possibleMoves;
}