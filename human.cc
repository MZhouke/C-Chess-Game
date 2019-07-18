//
//  human.cpp
//  a5
//
//  Created by Michael Zhou on 2019-03-27.
//  Copyright  2019 Michael Zhou. All rights reserved.
//

#include "human.h"
#include <iostream>

using namespace std;

Human::Human (Colour colour): Player(colour) {
    isAI = false;
}

void Human::getInput() {
    char c; // use this char to read columns, and convert it later to ints
    cin >> std::skipws >> c;
    while (c < 'a' || c > 'h'){
        cout << "invalid input" << endl;
        cin >> std::skipws >> c;
    }
    c1 = c - 'a';
    //cout << c1;
     cin >> std::skipws >> r1;
    while (r1 < 1 || r1 > 8){
        cout << "invalid input" << endl;
        cin >> std::skipws >> r1;
    }
    r1 = r1 -1;
    cin >> std::skipws >> c;
    while (c < 'a' || c > 'h'){
        cout << "invalid input" << endl;
        cin >> std::skipws >> c;
    }
    //cout << r1 << endl;
    c2 = c - 'a';
    //cout << c2;
    cin >> std::skipws >> r2;
    while (r2 < 1 || r2 > 8){
        cout << "invalid input" << endl;
        cin >> std::skipws >> r2;
    }
    r2 = r2-1;
    //cout << r2 << endl;
}

