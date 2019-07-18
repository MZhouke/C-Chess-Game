//
//  cell.cpp
//  a5
//
//  Created by Michael Zhou on 2019-03-27.
//  Copyright © 2019 Michael Zhou. All rights reserved.
//

#include "cell.h"

using namespace std;

Cell::Cell(int r, int c):info{r,c,Colour::NoColour,ChessType::Empty},move{0}{}

bool Cell::isCheck(){
    Colour opposite = info.colour == Colour::Black? Colour::White : Colour::Black;
    for(auto & vp : validPath){
        if(vp->getInfo().colour == opposite && vp->getInfo().type == ChessType::King) return true;
    }
    return false;
}
bool Cell::inPath(Cell& c){
    for(auto & vp : validPath){
        if(vp->getInfo().row == c.getInfo().row && vp->getInfo().col == c.getInfo().col) return true;
    }
    return false;
}

void Cell::removePath(Cell& c){
    Cell* vp;
    for(int i = 0; i < validPath.size(); ++i){
        vp = validPath[i];
        if(vp->getInfo().row == c.getInfo().row && vp->getInfo().col == c.getInfo().col){
            validPath.erase(validPath.begin()+i);
            return;
        }
    }
}

Info Cell::getInfo() const{
    return info;
}

void Cell::attachPath(Cell* c){
    validPath.emplace_back(c);
}
void Cell::clearPath(){
    validPath.clear();
}
void Cell::setColour(Colour colour){
    info.colour = colour;
}
void Cell::setType(ChessType type){
    info.type = type;
}

void Cell::increMove(int m) {
    move = m+1;
}

int Cell::getMove() {
    return move;
}

std::vector<Cell*> Cell::getValidPath(){
    return validPath;
}
