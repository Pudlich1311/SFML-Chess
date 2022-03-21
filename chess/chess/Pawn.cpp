#include <iostream>
#include "Game.h"
#include "Pieces.h"
#include "Pawn.h"

Pawn::Pawn(int color)
{
    possibleMoves.clear();
    isWhite = color;
    isAlive = true;
    blackPawn.loadFromFile("Textures/b_pawn.png");
    whitePawn.loadFromFile("Textures/w_pawn.png");
   // x = (color == 0) ? 1 : 6;
    piece.setTexture((color == 0) ? blackPawn : whitePawn);
    occupied_value = -3;
}

vector<Square> Pawn::getMoves(vector<vector<Square>>& cells, int x, int y, int flag)
{
    bool passant = en_passant;
  
    possibleMoves.clear();
    is_attacker = false;
    if (cells[x][y].occupied_color == -1)
    {
        
        if (x == 1)
            if (cells[x+2][y].occupied_color == 0)
                possibleMoves.push_back(cells[x+2][y]);
        if (x != 7)
            if (cells[x+1][y].occupied_value == 0 && cells[x+1][y].occupied_color == 0)
                possibleMoves.push_back(cells[x+1][y]);
        if (y != 0 && cells[x + 1][y - 1].occupied_color == 1)
        {   
            possibleMoves.push_back(cells[x + 1][y - 1]);
            if (cells[x + 1][y - 1].occupied_value == 3)
            {
                is_attacker = true;
            }
        }
        if (y != 7 && cells[x+1][y+1].occupied_color == 1)
        {
            possibleMoves.push_back(cells[x + 1][y + 1]);
            if (cells[x + 1][y + 1].occupied_value == 3)
            {
                is_attacker = true;
            }
        }
        if (x == 4 && y + 1 <= 7 && cells[x][y + 1].occupied_value == -3 && cells[x][y + 1].occupied_color == 1 && passant)
        {
            
            possibleMoves.push_back(cells[x + 1][y + 1]);
        }
        if (x == 4 && y - 1 >= 0 && cells[x][y - 1].occupied_value == -3 && cells[x][y - 1].occupied_color == 1 && passant)
        {
            
            possibleMoves.push_back(cells[x + 1][y - 1]);
        }
    }
    if (cells[x][y].occupied_color == 1)
    {
        if (x == 6)
            if (cells[x-2][y].occupied_color == 0)
                possibleMoves.push_back(cells[x-2][y]);
        if (x != 0)
            if (cells[x-1][y].occupied_value == 0 && cells[x-1][y].occupied_color == 0)
                possibleMoves.push_back(cells[x-1][y]);
        if (y != 0 && cells[x-1][y-1].occupied_color == -1)
        {
            possibleMoves.push_back(cells[x - 1][y - 1]);
            if (cells[x - 1][y - 1].occupied_value == 3)
            {
                is_attacker = true;
            }
        }
        if (y != 7 && cells[x-1][y+1].occupied_color == -1)
        {
            possibleMoves.push_back(cells[x - 1][y + 1]);
            if (cells[x - 1][y + 1].occupied_value == 3)
            {
                is_attacker = true;
            }
        }
        if (x == 3 && y + 1 <= 7 &&cells[x][y + 1].occupied_value == -3 && cells[x][y + 1].occupied_color == -1 && passant)
        {
           
            possibleMoves.push_back(cells[x - 1][y + 1]);
        }
        if (x == 3 && y - 1 >= 0 && cells[x][y - 1].occupied_value == -3 && cells[x][y - 1].occupied_color == -1 && passant)
        {
            
            possibleMoves.push_back(cells[x - 1][y - 1]);
        }
    }
    return possibleMoves;
}