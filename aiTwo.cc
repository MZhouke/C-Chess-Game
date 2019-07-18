//
//  aiTwo.cpp
//  a5
//
//  Created by Michael Zhou on 2019-03-27.
//  Copyright © 2019 Michael Zhou. All rights reserved.
//

#include "aiTwo.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include "cell.h"

using namespace std;

AI_2::AI_2(Colour colour):Player(colour){
    isAI = true;
}

void AI_2::getInput() {
    // capture king if I can
    for(auto& livingCell : livingChess) {
        vector<Cell*> validPath = livingCell->getValidPath();
        for(auto& validCell : validPath) {
            if(validCell->getInfo().type == ChessType::King) {
                r1 = livingCell->getInfo().row;
                c1 = livingCell->getInfo().col;
                r2 = validCell->getInfo().row;
                c2 = validCell->getInfo().col;
//                cout << r1 << endl;
//                cout << c1 << endl;
//                cout << r2 << endl;
//                cout << c2 << endl;
                return;
            }
        }
    }

    // capture anything if I can
    for(auto& livingCell : livingChess) {
        vector<Cell*> validPath = livingCell->getValidPath();
        for(auto& validCell : validPath) {
            if(validCell->getInfo().type != ChessType::Empty) {
                r1 = livingCell->getInfo().row;
                c1 = livingCell->getInfo().col;
                r2 = validCell->getInfo().row;
                c2 = validCell->getInfo().col;
//                cout << r1 << endl;
//                cout << c1 << endl;
//                cout << r2 << endl;
//                cout << c2 << endl;
                return;
            }
        }
    }

    // random move

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
//            cout << r1 << endl;
//            cout << c1 << endl;
//            cout << r2 << endl;
//            cout << c2 << endl;
            break;
        }
    }
}


