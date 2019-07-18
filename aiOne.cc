//
//  aiOne.cpp
//  a5
//
//  Created by Michael Zhou on 2019-03-27.
//  Copyright © 2019 Michael Zhou. All rights reserved.
//

#include "aiOne.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "cell.h"

using namespace std;

AI_1::AI_1(Colour colour):Player(colour) {
    isAI = true;
}

void AI_1::getInput() {
    srand(time(NULL));
    int living_size = livingChess.size();
    while(true) {
        int living_index = rand() % living_size;
        int valid_size = livingChess[living_index]->getValidPath().size();
        if(valid_size != 0) {
            int valid_index = rand() % valid_size;
            r1 = livingChess[living_index]->getInfo().row;
            c1 = livingChess[living_index]->getInfo().col;
            r2 = livingChess[living_index]->getValidPath()[valid_index]->getInfo().row;
            c2 = livingChess[living_index]->getValidPath()[valid_index]->getInfo().col;
            break;
        }
    }
}


