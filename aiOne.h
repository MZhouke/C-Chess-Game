//
//  aiOne.hpp
//  a5
//
//  Created by Michael Zhou on 2019-03-27.
//  Copyright © 2019 Michael Zhou. All rights reserved.
//

#ifndef aiOne_h
#define aiOne_h

#include <iostream>
#include "player.h"

class AI_1:public Player{
public:
    AI_1(Colour colour);
    void getInput() override; // when we read move in main, we call this function,
                              // it'll NOT read consecutive coordinates from stdin.
};

#endif /* aiOne_h */
