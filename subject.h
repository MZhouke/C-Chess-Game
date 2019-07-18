//
//  subject.hpp
//  a5
//
//  Created by Michael Zhou on 2019-03-27.
//  Copyright © 2019 Michael Zhou. All rights reserved.
//

#ifndef subject_h
#define subject_h

#include <iostream>
#include <vector>
#include "info.h"

class Observer;
class Subject {
    std::vector <Observer*> observers;
public:
    void attach(Observer* o);
    void notifyObservers(Subject& o);
    virtual Info getInfo() const = 0;
};

#endif /* subject_h */
