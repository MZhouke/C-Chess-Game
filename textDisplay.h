//
//  textDisplay.hpp
//  a5
//
//  Created by Michael Zhou on 2019-03-27.
//  Copyright © 2019 Michael Zhou. All rights reserved.
//

#ifndef textDisplay_h
#define textDisplay_h

#include <iostream>
#include "observer.h"
#include <vector>
class Cell;

class TextDisplay: public Observer {
    std::vector<std::vector<char>> theDisplay;
    const int gridSize;
public:
    TextDisplay(int n);
    
    void notify(Subject& from,Subject& to) override;
    
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
    
};

#endif /* textDisplay_h */
