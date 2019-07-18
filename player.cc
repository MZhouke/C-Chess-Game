//
//  player.cpp
//  a5
//
//  Created by Michael Zhou on 2019-03-27.
//  Copyright © 2019 Michael Zhou. All rights reserved.
//

#include "player.h"
#include "cell.h"
using namespace std;

Player::Player(Colour c):colour(c),r1(0),c1(0),r2(0),c2(0){
    livingChess.clear();
}

void Player::clear(){
    r1 = 0;
    c1 = 0;
    r2 = 0;
    c2 = 0;
    livingChess.clear();
}

Colour Player::getColour(){
    return colour;
}
int Player::getC1(){
    return c1;
}
int Player::getC2(){
    return c2;
}
int Player::getR1(){
    return r1;
}
int Player::getR2(){
    return r2;
}
void Player::addLiving(Cell* c){
    livingChess.emplace_back(c);
}


Cell Player::selfGetter(int index) {
    return *(livingChess[index]);
}


void Player::notify(Subject& from, Subject& to){
    if(from.getInfo().colour == colour){ //my chess
        //cout << livingChess.size() << endl;
        for(int i = 0; i < livingChess.size(); ++i){
            if (livingChess[i]->getInfo().row == from.getInfo().row && livingChess[i]->getInfo().col == from.getInfo().col){
                livingChess.erase(livingChess.begin()+i);
            }
        }
    }
    else{ //not my chess check if one of mine is taken
       
        if(to.getInfo().colour == Colour::NoColour) return;
         //cout << livingChess.size() << endl;
        for(int i = 0; i < livingChess.size(); ++i){
            if (livingChess[i]->getInfo().row == to.getInfo().row && livingChess[i]->getInfo().col == to.getInfo().col){
                livingChess.erase(livingChess.begin()+i);
            }
        }
    }
}

Cell* Player::getKing(){
    for(auto& lc : livingChess){
        if(lc->getInfo().type == ChessType::King){
            return lc;
        }
    }
    return nullptr;
}

vector<Cell*> Player::getLiving(){
    return livingChess;
}


