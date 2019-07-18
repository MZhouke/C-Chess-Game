//
//  human.hpp
//  a5
//
//  Created by Michael Zhou on 2019-03-27.
//  Copyright  2019 Michael Zhou. All rights reserved.
//

#ifndef human_h
#define human_h

#include <iostream>
#include "player.h"

class Human:public Player{
public:
    Human(Colour colour);
    void getInput() override; // when we read move in main, we call this function, it'll read consecutive coordinates from stdin.
    
};

#endif
