// we giveup on AI three :>


#ifndef aiThree_h
#define aiThree_h

#include <iostream>

#include <iostream>
#include "player.h"

class AI_3 : public Player{
public:
    AI_3(Colour colour);
    void getInput() override; // when we read move in main, we call this function,
    // it'll NOT read consecutive coordinates from stdin.
};

#endif /* aiThree_h */
