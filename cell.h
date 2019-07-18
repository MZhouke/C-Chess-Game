//
//  cell.hpp
//  a5
//
//  Created by Michael Zhou on 2019-03-27.
//  Copyright © 2019 Michael Zhou. All rights reserved.
//

#ifndef cell_h
#define cell_h

#include <iostream>
#include "subject.h"
#include "info.h"


class Cell: public Subject{
    Info info;
    int move;
    std::vector<Cell*> validPath;
public:
    int getMove(); //get validPath
    void increMove(int); //increase move by 1
    Cell(int r, int c); // create empty cell
    std::vector<Cell*> getValidPath(); // get the valid path
    bool isCheck(); //decide if king is on path
    bool inPath(Cell& c); //see if c is on path
    void removePath(Cell& c); //removes c from the path
    Info getInfo() const override; //get info of cell
    void clearPath(); // clears validPath
    void attachPath(Cell*); //attach one move to validPath
    void setColour(Colour colour); //set the colour of cell
    void setType(ChessType type); //set the type of cell
};
#endif /* cell_h */
