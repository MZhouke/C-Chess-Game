//
//  ai.hpp
//  a5
//
//  Created by Michael Zhou on 2019-03-27.
//  Copyright © 2019 Michael Zhou. All rights reserved.
//

#ifndef ai_h
#define ai_h

#include "player.h"


class AI: public Player{
public:
    virtual void getInput() = 0; // when we read move in main, we call this function,
                              // it'll NOT read consecutive coordinates from stdin.
};

#endif /* ai_h */
