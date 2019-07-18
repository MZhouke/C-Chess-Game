//
//  observer.hpp
//  a5
//
//  Created by Michael Zhou on 2019-03-27.
//  Copyright © 2019 Michael Zhou. All rights reserved.
//

#ifndef observer_h
#define observer_h

#include <iostream>
class Subject;

class Observer {
public:
    virtual void notify(Subject& from, Subject& to) = 0; // pass the Subject that called the notify method
    virtual ~Observer() = default;
};
#endif /* observer_h */
