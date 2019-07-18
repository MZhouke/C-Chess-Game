//
//  player.hpp
//  a5
//
//  Created by Michael Zhou on 2019-03-27.
//  Copyright © 2019 Michael Zhou. All rights reserved.
//

#ifndef player_h
#define player_h

#include <iostream>
#include "observer.h"
#include <vector>
#include "info.h"

class Cell;
class Player:public Observer {
protected:
    Colour colour;
    int c1;
    int r1;
    int c2;
    int r2;
    std::vector<Cell*> livingChess;
public:
    Player(Colour c);
    void clear(); //clears this player's field
    bool isAI = false;
    //getters
    Colour getColour();
    int getC1();
    int getC2();
    int getR1();
    int getR2();
    std::vector<Cell*> getLiving();
    void addLiving(Cell* c);
    void notify(Subject &from, Subject &to) override;
    virtual void getInput() = 0; // this is used to either get user input(human) or decide which chess to move(ai)
    Cell selfGetter(int index); // get the living chess at position index
    Cell* getKing();
    virtual ~Player() = default;
};

#endif /* player_h */
