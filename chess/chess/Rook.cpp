#include <iostream>
#include "Game.h"
#include "Pieces.h"
#include <vector>
#include "Rook.h"
using namespace std;

Rook::Rook(int color)
{
    possibleMoves.clear();
    isWhite = color;
    isAlive = true;
    blackRook.loadFromFile("Textures/b_rook.png");
    whiteRook.loadFromFile("Textures/w_rook.png");
    occupied_value = 1;

    piece.setTexture((color == 0) ? blackRook : whiteRook);
}

vector<Square> Rook::getMoves(vector<vector<Square>>& cells, int x, int y, int flag)
{
    
    is_attacker = false;
    possibleMoves.clear();
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