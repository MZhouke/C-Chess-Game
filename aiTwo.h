//
//  aiTwo.hpp
//  a5
//
//  Created by Michael Zhou on 2019-03-27.
//  Copyright © 2019 Michael Zhou. All rights reserved.
//

#ifndef aiTwo_h
#define aiTwo_h

#include <iostream>
#include "player.h"

class AI_2 : public Player{
public:
    AI_2(Colour colour);
    void getInput() override; // when we read move in main, we call this function,
                              // it'll NOT read consecutive coordinates from stdin.
};
#endif /* aiTwo_h */
