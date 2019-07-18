//
//  subject.cpp
//  a5
//
//  Created by Michael Zhou on 2019-03-27.
//  Copyright © 2019 Michael Zhou. All rights reserved.
//

#include "subject.h"
#include "observer.h"
using namespace std;


void Subject::attach(Observer*o) {
    observers.emplace_back(o);
}


void Subject::notifyObservers(Subject& s) {
    for (auto &ob : observers) ob->notify(*this,s);
}

