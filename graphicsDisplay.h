#ifndef _GRAPHICSDISPLAY_H
#define _GRAPHICSDISPLAY_H
#include <iostream>
#include <vector>
#include "observer.h"
#include "info.h"
#include "window.h"

class Cell;

class GraphicsDisplay: public Observer {
    const int gridSize;
    const int windowSize = 560;
    int recSize;
    Xwindow* xw;
public:
    GraphicsDisplay(int n);
    
    void notify(Subject& from,Subject& to) override;
    
    ~GraphicsDisplay();
};

#endif
