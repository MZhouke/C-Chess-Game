#include "graphicsDisplay.h"
#include "subject.h"
#include <iostream>
#include "window.h"

using namespace std;

GraphicsDisplay::GraphicsDisplay(int n):gridSize{n},recSize{windowSize/n}{
    xw = new Xwindow(windowSize, windowSize);
    for (int i = 0; i < windowSize; i+=recSize){
        for (int j = 0; j < windowSize; j+=recSize){
            //set the middle 4
            if((i/recSize + j/recSize)%2 == 0){
                xw->fillRectangle(j, i, recSize, recSize,4);
            }
            else{
                xw->fillRectangle(j, i, recSize, recSize,0);
            }
        }
    }
               
               for(int i = 0; i < n; ++i) {
                   for(int j = 0; j < n; ++j) {
                       if(i == 0){//white chess
                           if(j == 0){
                               xw->drawString(j*recSize+recSize/2, i*recSize+recSize/2, "r");
                           }
                           if(j == 1){
                               xw->drawString(j*recSize+recSize/2, i*recSize+recSize/2, "n");
                           }
                           if(j == 2){
                               xw->drawString(j*recSize+recSize/2, i*recSize+recSize/2, "b");
                           }
                           if(j == 3){
                               xw->drawString(j*recSize+recSize/2, i*recSize+recSize/2, "q");
                           }
                           if(j == 4){
                               xw->drawString(j*recSize+recSize/2, i*recSize+recSize/2, "k");
                           }
                           if(j == 5){
                               xw->drawString(j*recSize+recSize/2, i*recSize+recSize/2, "b");
                           }
                           if(j == 6){
                               xw->drawString(j*recSize+recSize/2, i*recSize+recSize/2, "n");
                           }
                           if(j == 7){
                               xw->drawString(j*recSize+recSize/2, i*recSize+recSize/2, "r");
                           }
                       }
                       else if(i == 1){//white pawns
                           xw->drawString(j*recSize+recSize/2, i*recSize+recSize/2, "p");
                       }
                       else if(i == 6){//black pawns
                           //add black to p2 living and p1 opponent
                           xw->drawString(j*recSize+recSize/2, i*recSize+recSize/2, "P");
                       }
                       else if(i == 7){//black chess
                           if(j == 0){
                               xw->drawString(j*recSize+recSize/2, i*recSize+recSize/2, "R");
                           }
                           if(j == 1){
                               xw->drawString(j*recSize+recSize/2, i*recSize+recSize/2, "N");
                           }
                           if(j == 2){
                               xw->drawString(j*recSize+recSize/2, i*recSize+recSize/2, "B");
                           }
                           if(j == 3){
                               xw->drawString(j*recSize+recSize/2, i*recSize+recSize/2, "Q");
                           }
                           if(j == 4){
                               xw->drawString(j*recSize+recSize/2, i*recSize+recSize/2, "K");
                           }
                           if(j == 5){
                               xw->drawString(j*recSize+recSize/2, i*recSize+recSize/2, "B");
                           }
                           if(j == 6){
                               xw->drawString(j*recSize+recSize/2, i*recSize+recSize/2, "N");
                           }
                           if(j == 7){
                               xw->drawString(j*recSize+recSize/2, i*recSize+recSize/2, "R");
                           }
                       }
                }
            }
}

               
               void GraphicsDisplay::notify(Subject &from, Subject &to) {
                   size_t r1 = from.getInfo().row;
                   r1 = 7-r1;
                   size_t c1 = from.getInfo().col;
                   //c1 = 8-c1;
                   if((c1 + r1)%2 == 0){
                       xw->fillRectangle(c1*recSize, r1*recSize, recSize, recSize,4);
                   }
                   else{
                       xw->fillRectangle(c1*recSize, r1*recSize, recSize, recSize,0);
                   }
                   size_t r = to.getInfo().row;
                   r=7-r;
                   size_t c = to.getInfo().col;
                   //c=8-c;
                   //this is for pawn capture en passant.
                   if (from.getInfo().type == ChessType::Pawn && from.getInfo().row == to.getInfo().row && from.getInfo().colour == Colour::Black) {
                       //want to refill the two cells
                       if((c + (r-1))%2 == 0){
                           xw->fillRectangle(c*recSize, (r-1)*recSize, recSize, recSize,4);
                       }
                       else{
                           xw->fillRectangle(c*recSize, (r-1)*recSize, recSize, recSize,0);
                       }
                       if((c + r)%2 == 0){
                           xw->fillRectangle(c*recSize, r*recSize, recSize, recSize,4);
                       }
                       else{
                           xw->fillRectangle(c*recSize, r*recSize, recSize, recSize,0);
                       }
                       //then add the value
                       xw->drawString(c*recSize+recSize/2, (r-1)*recSize+recSize/2, "p");
                   }
                   else if (from.getInfo().type == ChessType::Pawn && from.getInfo().row == to.getInfo().row && from.getInfo().colour == Colour::White) {
                       //want to refill the two cells
                       if((c + (r-1))%2 == 0){
                           xw->fillRectangle(c*recSize, (r-1)*recSize, recSize, recSize,4);
                       }
                          else{
                              xw->fillRectangle(c*recSize, (r-1)*recSize, recSize, recSize,0);
                          }
                          if((c + r)%2 == 0){
                              xw->fillRectangle(c*recSize, r*recSize, recSize, recSize,4);
                          }
                          else{
                              xw->fillRectangle(c*recSize, r*recSize, recSize, recSize,0);
                          }
                          //then add the value
                          xw->drawString(c*recSize+recSize/2, (r-1)*recSize+recSize/2, "P");
                   }
                   else {
                       if(from.getInfo().type == ChessType::Empty) {
                           
                       } else if (from.getInfo().colour == Colour::Black) {
                           if (from.getInfo().type == ChessType::Bishop) {
                               if((c + r)%2 == 0){
                                   xw->fillRectangle(c*recSize, r*recSize, recSize, recSize,4);
                               }
                               else{
                                   xw->fillRectangle(c*recSize, r*recSize, recSize, recSize,0);
                               }
                               xw->drawString(c*recSize+recSize/2, (r)*recSize+recSize/2, "b");
                           } else if (from.getInfo().type == ChessType::King) {
                               if((c + r)%2 == 0){
                                   xw->fillRectangle(c*recSize, r*recSize, recSize, recSize,4);
                               }
                               else{
                                   xw->fillRectangle(c*recSize, r*recSize, recSize, recSize,0);
                               }
                               xw->drawString(c*recSize+recSize/2, (r)*recSize+recSize/2, "k");
                           } else if (from.getInfo().type == ChessType::Knight) {
                               if((c + r)%2 == 0){
                                   xw->fillRectangle(c*recSize, r*recSize, recSize, recSize,4);
                               }
                               else{
                                   xw->fillRectangle(c*recSize, r*recSize, recSize, recSize,0);
                               }
                               xw->drawString(c*recSize+recSize/2, (r)*recSize+recSize/2, "n");
                           } else if (from.getInfo().type == ChessType::Pawn) {
                               if((c + r)%2 == 0){
                                   xw->fillRectangle(c*recSize, r*recSize, recSize, recSize,4);
                               }
                               else{
                                   xw->fillRectangle(c*recSize, r*recSize, recSize, recSize,0);
                               }
                               xw->drawString(c*recSize+recSize/2, (r)*recSize+recSize/2, "p");
                           } else if (from.getInfo().type == ChessType::Queen) {
                               if((c + r)%2 == 0){
                                   xw->fillRectangle(c*recSize, r*recSize, recSize, recSize,4);
                               }
                               else{
                                   xw->fillRectangle(c*recSize, r*recSize, recSize, recSize,0);
                               }
                               xw->drawString(c*recSize+recSize/2, (r)*recSize+recSize/2, "q");
                           } else if (from.getInfo().type == ChessType::Rook) {
                               if((c + r)%2 == 0){
                                   xw->fillRectangle(c*recSize, r*recSize, recSize, recSize,4);
                               }
                               else{
                                   xw->fillRectangle(c*recSize, r*recSize, recSize, recSize,0);
                               }
                               xw->drawString(c*recSize+recSize/2, (r)*recSize+recSize/2, "r");
                           }
                       } else if (from.getInfo().colour == Colour::White) {
                           if (from.getInfo().type == ChessType::Bishop) {
                               if((c + r)%2 == 0){
                                   xw->fillRectangle(c*recSize, r*recSize, recSize, recSize,4);
                               }
                               else{
                                   xw->fillRectangle(c*recSize, r*recSize, recSize, recSize,0);
                               }
                               xw->drawString(c*recSize+recSize/2, (r)*recSize+recSize/2, "B");
                           } else if (from.getInfo().type == ChessType::King) {
                               if((c + r)%2 == 0){
                                   xw->fillRectangle(c*recSize, r*recSize, recSize, recSize,4);
                               }
                               else{
                                   xw->fillRectangle(c*recSize, r*recSize, recSize, recSize,0);
                               }
                               xw->drawString(c*recSize+recSize/2, (r)*recSize+recSize/2, "K");
                           } else if (from.getInfo().type == ChessType::Knight) {
                               if((c + r)%2 == 0){
                                   xw->fillRectangle(c*recSize, r*recSize, recSize, recSize,4);
                               }
                               else{
                                   xw->fillRectangle(c*recSize, r*recSize, recSize, recSize,0);
                               }
                               xw->drawString(c*recSize+recSize/2, (r)*recSize+recSize/2, "N");
                           } else if (from.getInfo().type == ChessType::Pawn) {
                               if((c + r)%2 == 0){
                                   xw->fillRectangle(c*recSize, r*recSize, recSize, recSize,4);
                               }
                               else{
                                   xw->fillRectangle(c*recSize, r*recSize, recSize, recSize,0);
                               }
                               xw->drawString(c*recSize+recSize/2, (r)*recSize+recSize/2, "P");
                           } else if (from.getInfo().type == ChessType::Queen) {
                               if((c + r)%2 == 0){
                                   xw->fillRectangle(c*recSize, r*recSize, recSize, recSize,4);
                               }
                               else{
                                   xw->fillRectangle(c*recSize, r*recSize, recSize, recSize,0);
                               }
                               xw->drawString(c*recSize+recSize/2, (r)*recSize+recSize/2, "Q");
                           } else if (from.getInfo().type == ChessType::Rook) {
                               if((c + r)%2 == 0){
                                   xw->fillRectangle(c*recSize, r*recSize, recSize, recSize,4);
                               }
                               else{
                                   xw->fillRectangle(c*recSize, r*recSize, recSize, recSize,0);
                               }
                               xw->drawString(c*recSize+recSize/2, (r)*recSize+recSize/2, "R");
                           }
                       }
                   }
               }

               

GraphicsDisplay::~GraphicsDisplay(){
    delete xw;
}
