//
//  grid.hpp
//  a5
//
//  Created by Michael Zhou on 2019-03-27.
//  Copyright © 2019 Michael Zhou. All rights reserved.
//

#ifndef grid_h
#define grid_h
#include <cstddef>
#include <vector>
#include <iostream>
#include "cell.h"
#include "info.h"
#include "endGame.h"

class Player;
class TextDisplay;
class GraphicsDisplay;

class Grid{
    std::vector<std::vector<Cell>> theGrid;  // The actual grid.
    Player* p1;
    Player* p2;
    TextDisplay *td = nullptr; // The text display.
    GraphicsDisplay* gd = nullptr;  // graphics observer
    const int size = 8;

public:
    ~Grid();
    void init(Player* p1, Player* p2); // Sets up an n x n grid.  Clears old grid, if necessary.
    void move(Player& p);  // Plays piece at row r, col c.
    void isCheckMate(Player& p);
    bool valid(Cell& from, Cell& to);
    friend std::ostream &operator<<(std::ostream &out, const Grid &g);
    void addValidPath(Cell& c);//helper to add avaliable path to each chess
    void resetPath(); //resets path of all chess
    void resetPath(Player* p); //resets path of all opponent's path
    void clearPath(); //clears all path
};


#endif /* grid_h */
