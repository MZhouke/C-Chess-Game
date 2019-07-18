//
//  grid.cpp
//  a5
//
//  Created by Michael Zhou on 2019-03-27.
//  Copyright © 2019 Michael Zhou. All rights reserved.
//

#include "grid.h"
#include "textDisplay.h"
#include "player.h"
#include "graphicsDisplay.h"

using namespace std;

        

//helper to attach avaliable moves to each ches
bool isValidCoord(int n){
    return n >= 0 && n <= 7;
}
//helper that decides if c can be replaced by anyone in cells
bool InDanger(Cell* c, vector<Cell*> cells){
    for(auto& lc :  cells){
        if(lc->inPath(*c)){
            return true;
        }
    }
    return false;
}

// resets all the path of chess
void Grid::resetPath(){
    for(int i = 0; i<size; i++){
        for(int j=0; j<size; j++){
            if(theGrid[i][j].getInfo().type != ChessType::King){
                theGrid[i][j].clearPath();
                addValidPath(theGrid[i][j]);
            }
        }
    }
    for(int i = 0; i<size; i++){
        for(int j=0; j<size; j++){
            if(theGrid[i][j].getInfo().type == ChessType::King){
                theGrid[i][j].clearPath();
                addValidPath(theGrid[i][j]);
            }
        }
    }
}

//helper to get the total validpath of p
int validPathSum(Player& p){
    int movesp = 0;
    for(int i = 0; i < p.getLiving().size(); ++i){
        movesp += p.selfGetter(i).getValidPath().size();
    }
    return movesp;
}


//resets all the path of this player's chess
void Grid::resetPath(Player* p){
    for(int i = 0; i<size; i++){
        for(int j=0; j<size; j++){
            if(theGrid[i][j].getInfo().colour == p->getColour()){
                theGrid[i][j].clearPath();
                addValidPath(theGrid[i][j]);
            }
        }
    }
}

//clears all the path of chess
void Grid::clearPath(){
    for(int i = 0; i<size; i++){
        for(int j=0; j<size; j++){
            theGrid[i][j].clearPath();
        }
    }
}

void Grid::addValidPath(Cell & c) {
    if (c.getInfo().colour == Colour::NoColour) {
        return;
    }
    else if (c.getInfo().type == ChessType::Queen) {
        int row = c.getInfo().row;
        int col = c.getInfo().col;
        Colour colour = c.getInfo().colour;
        for (int i = 1; row+i <= 7 && col-i >=0; i++) {
            if (theGrid[row+i][col-i].getInfo().colour == Colour::NoColour) {
                c.attachPath(&theGrid[row+i][col-i]);
            }
            else if (theGrid[row+i][col-i].getInfo().colour != colour) {
                c.attachPath(&theGrid[row+i][col-i]);
                break;
            }
            else break;
        }
        for (int i = 1; row+i <= 7; i++) {
            if (theGrid[row+i][col].getInfo().colour == Colour::NoColour) {
                c.attachPath(&theGrid[row+i][col]);
            }
            else if (theGrid[row+i][col].getInfo().colour != colour) {
                c.attachPath(&theGrid[row+i][col]);
                break;
            }
            else break;
        }
        for (int i = 1; row+i <= 7 && col+i <= 7; i++) {
            if (theGrid[row+i][col+i].getInfo().colour == Colour::NoColour) {
                c.attachPath(&theGrid[row+i][col+i]);
            }
            else if (theGrid[row+i][col+i].getInfo().colour != colour) {
                c.attachPath(&theGrid[row+i][col+i]);
                break;
            }
            else break;
        }
        for (int i = 1; col+i <= 7; i++) {
            if (col+i > 7) break;
            if (theGrid[row][col+i].getInfo().colour == Colour::NoColour) {
                c.attachPath(&theGrid[row][col+i]);
            }
            else if (theGrid[row][col+i].getInfo().colour != colour) {
                c.attachPath(&theGrid[row][col+i]);
                break;
            }
            else break;
        }
        for (int i = 1; row-i >= 0 && col+i <=7; i++) {
            if (theGrid[row-i][col+i].getInfo().colour == Colour::NoColour) {
                c.attachPath(&theGrid[row-i][col+i]);
            }
            else if (theGrid[row-i][col+i].getInfo().colour != colour) {
                c.attachPath(&theGrid[row-i][col+i]);
                break;
            }
            else break;
        }
        for (int i = 1; row-i >= 0; i++) {
            if (theGrid[row-i][col].getInfo().colour == Colour::NoColour) {
                c.attachPath(&theGrid[row-i][col]);
            }
            else if (theGrid[row-i][col].getInfo().colour != colour) {
                c.attachPath(&theGrid[row-i][col]);
                break;
            }
            else break;
        }
        for (int i = 1; row-i >= 0 && col-i >= 0; i++) {
            if (theGrid[row-i][col-i].getInfo().colour == Colour::NoColour) {
                c.attachPath(&theGrid[row-i][col-i]);
            }
            else if (theGrid[row-i][col-i].getInfo().colour != colour) {
                c.attachPath(&theGrid[row-i][col-i]);
                break;
            }
            else break;
        }
        for (int i = 1; col-i >= 0; i++) {
            if (col-i < 0) break;
            if (theGrid[row][col-i].getInfo().colour == Colour::NoColour) {
                c.attachPath(&theGrid[row][col-i]);
            }
            else if (theGrid[row][col-i].getInfo().colour != colour) {
                c.attachPath(&theGrid[row][col-i]);
                break;
            }
            else break;
        }
    }
    else if (c.getInfo().type == ChessType::Bishop) {
        int row = c.getInfo().row;
        int col = c.getInfo().col;
        Colour colour = c.getInfo().colour;
        for (int i = 1; row+i <= 7 && col-i >=0; i++) {
            if (theGrid[row+i][col-i].getInfo().colour == Colour::NoColour) {
                c.attachPath(&theGrid[row+i][col-i]);
            }
            else if (theGrid[row+i][col-i].getInfo().colour != colour) {
                c.attachPath(&theGrid[row+i][col-i]);
                break;
            }
            else break;
        }
        for (int i = 1; row+i <= 7 && col+i <= 7; i++) {
            if (theGrid[row+i][col+i].getInfo().colour == Colour::NoColour) {
                c.attachPath(&theGrid[row+i][col+i]);
            }
            else if (theGrid[row+i][col+i].getInfo().colour != colour) {
                c.attachPath(&theGrid[row+i][col+i]);
                break;
            }
            else break;
        }
        for (int i = 1; row-i >=0 && col+i <=7; i++) {
            if (theGrid[row-i][col+i].getInfo().colour == Colour::NoColour) {
                c.attachPath(&theGrid[row-i][col+i]);
            }
            else if (theGrid[row-i][col+i].getInfo().colour != colour) {
                c.attachPath(&theGrid[row-i][col+i]);
                break;
            }
            else break;
        }
        for (int i = 1; row-i >= 0 && col-i >= 0; i++) {
            if (theGrid[row-i][col-i].getInfo().colour == Colour::NoColour) {
                c.attachPath(&theGrid[row-i][col-i]);
            }
            else if (theGrid[row-i][col-i].getInfo().colour != colour) {
                c.attachPath(&theGrid[row-i][col-i]);
                break;
            }
            else break;
        }
    }
    else if (c.getInfo().type == ChessType::Rook) {
        int row = c.getInfo().row;
        int col = c.getInfo().col;
        Colour colour = c.getInfo().colour;
        for (int i = 1; row+i <= 7; i++) {
            if (theGrid[row+i][col].getInfo().colour == Colour::NoColour) {
                c.attachPath(&theGrid[row+i][col]);
            }
            else if (theGrid[row+i][col].getInfo().colour != colour) {
                c.attachPath(&theGrid[row+i][col]);
                break;
            }
            else break;
        }
        for (int i = 1; col+i <= 7; i++) {
            if (theGrid[row][col+i].getInfo().colour == Colour::NoColour) {
                c.attachPath(&theGrid[row][col+i]);
            }
            else if (theGrid[row][col+i].getInfo().colour != colour) {
                c.attachPath(&theGrid[row][col+i]);
                break;
            }
            else break;
        }
        for (int i = 1; row-i >= 0; i++) {
            if (theGrid[row-i][col].getInfo().colour == Colour::NoColour) {
                c.attachPath(&theGrid[row-i][col]);
            }
            else if (theGrid[row-i][col].getInfo().colour != colour) {
                c.attachPath(&theGrid[row-i][col]);
                break;
            }
            else break;
        }
        for (int i = 1; col-i >= 0; i++) {
            if (theGrid[row][col-i].getInfo().colour == Colour::NoColour) {
                c.attachPath(&theGrid[row][col-i]);
            }
            else if (theGrid[row][col-i].getInfo().colour != colour) {
                c.attachPath(&theGrid[row][col-i]);
                break;
            }
            else break;
        }
    }
    else if (c.getInfo().type == ChessType::Knight) {
        int row = c.getInfo().row;
        int col = c.getInfo().col;
        Colour colour = c.getInfo().colour;
        if (isValidCoord(row-1) && isValidCoord(col+2)) {
            if (colour != theGrid[row-1][col+2].getInfo().colour) {
                c.attachPath(&theGrid[row-1][col+2]);
            }
        }
        if (isValidCoord(row-1) && isValidCoord(col-2)) {
            if (colour != theGrid[row-1][col-2].getInfo().colour) {
                c.attachPath(&theGrid[row-1][col-2]);
            }
        }
        if (isValidCoord(row+1) && isValidCoord(col+2)) {
            if (colour != theGrid[row+1][col+2].getInfo().colour) {
                c.attachPath(&theGrid[row+1][col+2]);
            }
        }
        if (isValidCoord(row+1) && isValidCoord(col-2)) {
            if (colour != theGrid[row+1][col-2].getInfo().colour) {
                c.attachPath(&theGrid[row+1][col-2]);
            }
        }
        if (isValidCoord(row-2) && isValidCoord(col+1)) {
            if (colour != theGrid[row-2][col+1].getInfo().colour) {
                c.attachPath(&theGrid[row-2][col+1]);
            }
        }
        if (isValidCoord(row-2) && isValidCoord(col-1)) {
            if (colour != theGrid[row-2][col-1].getInfo().colour) {
                c.attachPath(&theGrid[row-2][col-1]);
            }
        }
        if (isValidCoord(row+2) && isValidCoord(col+1)) {
            if (colour != theGrid[row+2][col+1].getInfo().colour) {
                c.attachPath(&theGrid[row+2][col+1]);
            }
        }
        if (isValidCoord(row+2) && isValidCoord(col-1)) {
            if (colour != theGrid[row+2][col-1].getInfo().colour) {
                c.attachPath(&theGrid[row+2][col-1]);
            }
        }
    }
    else if (c.getInfo().type == ChessType::Pawn) {
        int row = c.getInfo().row;
        int col = c.getInfo().col;
        Colour colour = c.getInfo().colour;
        if (colour == Colour::Black) {
            if (c.getMove() == 0) {
                if (isValidCoord(row-1) && Colour::NoColour == theGrid[row-1][col].getInfo().colour) {
                    c.attachPath(&theGrid[row-1][col]);
                }
                if (isValidCoord(row-2) && Colour::NoColour == theGrid[row-2][col].getInfo().colour) {
                    c.attachPath(&theGrid[row-2][col]);
                }
                if (isValidCoord(row-1) && isValidCoord(col+1)) {
                    if (theGrid[row-1][col+1].getInfo().colour == Colour::White) {
                        c.attachPath(&theGrid[row-1][col+1]);
                    }
                }
                if (isValidCoord(row-1) && isValidCoord(col-1)) {
                    if (theGrid[row-1][col-1].getInfo().colour == Colour::White) {
                        c.attachPath(&theGrid[row-1][col-1]);
                    }
                }
                // pawn capture en passant.
                if (isValidCoord(col+1)) {
                    if (theGrid[row][col+1].getInfo().colour == Colour::White && theGrid[row][col+1].getInfo().type == ChessType::Pawn && theGrid[row][col+1].getMove() == 1) {
                        c.attachPath(&theGrid[row-1][col+1]);
                    }
                }
                if (isValidCoord(col-1)) {
                    if (theGrid[row][col-1].getInfo().colour == Colour::White && theGrid[row][col-1].getInfo().type == ChessType::Pawn && theGrid[row][col-1].getMove() == 1) {
                        c.attachPath(&theGrid[row-1][col-1]);
                    }
                }
            }
            else {
                if (isValidCoord(row-1) && Colour::NoColour == theGrid[row-1][col].getInfo().colour) {
                    c.attachPath(&theGrid[row-1][col]);
                }
                if (isValidCoord(row-1) && isValidCoord(col+1)) {
                    if (theGrid[row-1][col+1].getInfo().colour == Colour::White) {
                        c.attachPath(&theGrid[row-1][col+1]);
                    }
                }
                if (isValidCoord(row-1) && isValidCoord(col-1)) {
                    if (theGrid[row-1][col-1].getInfo().colour == Colour::White) {
                        c.attachPath(&theGrid[row-1][col-1]);
                    }
                }
                // pawn capture en passant.
                if (isValidCoord(col+1)) {
                    if (theGrid[row][col+1].getInfo().colour == Colour::White && theGrid[row][col+1].getInfo().type == ChessType::Pawn && theGrid[row][col+1].getMove() == 1) {
                        c.attachPath(&theGrid[row-1][col+1]);
                    }
                }
                if (isValidCoord(col-1)) {
                    if (theGrid[row][col-1].getInfo().colour == Colour::White && theGrid[row][col-1].getInfo().type == ChessType::Pawn && theGrid[row][col-1].getMove() == 1) {
                        c.attachPath(&theGrid[row-1][col-1]);
                    }
                }
            }
        }
        else {
            if (c.getMove() == 0) {
                if (isValidCoord(row+1) && Colour::NoColour == theGrid[row+1][col].getInfo().colour) {
                    c.attachPath(&theGrid[row+1][col]);
                }
                if (isValidCoord(row+2) && Colour::NoColour == theGrid[row+2][col].getInfo().colour) {
                    c.attachPath(&theGrid[row+2][col]);
                }
                if (isValidCoord(row+1) && isValidCoord(col+1)) {
                    if (theGrid[row+1][col+1].getInfo().colour == Colour::Black) {
                        c.attachPath(&theGrid[row+1][col+1]);
                    }
                }
                if (isValidCoord(row+1) && isValidCoord(col-1)) {
                    if (theGrid[row+1][col-1].getInfo().colour == Colour::Black) {
                        c.attachPath(&theGrid[row+1][col-1]);
                    }
                }
                // pawn capture en passant.
                if (isValidCoord(col+1)) {
                    if (theGrid[row][col+1].getInfo().colour == Colour::Black && theGrid[row][col+1].getInfo().type == ChessType::Pawn && theGrid[row][col+1].getMove() == 1) {
                        c.attachPath(&theGrid[row+1][col+1]);
                    }
                }
                if (isValidCoord(col-1)) {
                    if (theGrid[row][col-1].getInfo().colour == Colour::Black && theGrid[row][col-1].getInfo().type == ChessType::Pawn && theGrid[row][col-1].getMove() == 1) {
                        c.attachPath(&theGrid[row+1][col-1]);
                    }
                }
            }
            else {
                if (isValidCoord(row+1) && Colour::NoColour == theGrid[row+1][col].getInfo().colour) {
                    c.attachPath(&theGrid[row+1][col]);
                }
                if (isValidCoord(row+1) && isValidCoord(col+1)) {
                    if (theGrid[row+1][col+1].getInfo().colour == Colour::Black) {
                        c.attachPath(&theGrid[row+1][col+1]);
                    }
                }
                if (isValidCoord(row+1) && isValidCoord(col-1)) {
                    if (theGrid[row+1][col-1].getInfo().colour == Colour::Black) {
                        c.attachPath(&theGrid[row+1][col-1]);
                    }
                }
                // pawn capture en passant.
                if (isValidCoord(col+1)) {
                    if (theGrid[row][col+1].getInfo().colour == Colour::Black && theGrid[row][col+1].getInfo().type == ChessType::Pawn && theGrid[row][col+1].getMove() == 1) {
                        c.attachPath(&theGrid[row+1][col+1]);
                    }
                }
                if (isValidCoord(col-1)) {
                    if (theGrid[row][col-1].getInfo().colour == Colour::Black && theGrid[row][col-1].getInfo().type == ChessType::Pawn && theGrid[row][col-1].getMove() == 1) {
                        c.attachPath(&theGrid[row+1][col-1]);
                    }
                }
            }
        }
    }
    else if (c.getInfo().type == ChessType::King) {
        int row = c.getInfo().row;
        int col = c.getInfo().col;
        Colour colour = c.getInfo().colour;
        if (isValidCoord(row+1) && isValidCoord(col-1)) {
            if (colour != theGrid[row+1][col-1].getInfo().colour) {
                c.attachPath(&theGrid[row+1][col-1]);
            }
        }
        if (isValidCoord(row+1) && isValidCoord(col+1)) {
            if (colour != theGrid[row+1][col+1].getInfo().colour) {
                c.attachPath(&theGrid[row+1][col+1]);
            }
        }
        if (isValidCoord(row-1) && isValidCoord(col+1)) {
            if (colour != theGrid[row-1][col+1].getInfo().colour) {
                c.attachPath(&theGrid[row-1][col+1]);
            }
        }
        if (isValidCoord(row-1) && isValidCoord(col-1)) {
            if (colour != theGrid[row-1][col-1].getInfo().colour) {
                c.attachPath(&theGrid[row-1][col-1]);
            }
        }
        if (isValidCoord(row+1)) {
            if (colour != theGrid[row+1][col].getInfo().colour) {
                c.attachPath(&theGrid[row+1][col]);
            }
        }
        if (isValidCoord(col+1)) {
            if (colour != theGrid[row][col+1].getInfo().colour) {
                c.attachPath(&theGrid[row][col+1]);
            }
        }
        if (isValidCoord(row-1)) {
            if (colour != theGrid[row-1][col].getInfo().colour) {
                c.attachPath(&theGrid[row-1][col]);
            }
        }
        if (isValidCoord(col-1)) {
            if (colour != theGrid[row][col-1].getInfo().colour) {
                c.attachPath(&theGrid[row][col-1]);
            }
        }
        if (theGrid[row][col].getMove() == 0 && theGrid[row][col+3].getMove() == 0 && theGrid[row][col+1].getInfo().type == ChessType::Empty && theGrid[row][col+2].getInfo().type == ChessType::Empty && theGrid[row][col+3].getInfo().type == ChessType::Rook) {
            if (p1->getColour() == theGrid[row][col].getInfo().colour) {
//                                for(auto& lp : p2->getLiving()){
//                                    if(lp->inPath(theGrid[row][col+1])){
//                                        cout << lp->getInfo().row << endl;
//                                        cout << lp->getInfo().col << endl;
//                                    }
//                                }
                if (!InDanger(&theGrid[row][col+1], p2->getLiving()) && !InDanger(&theGrid[row][col+2], p2->getLiving())) {
                    c.attachPath(&theGrid[row][col+2]);
                }
            }
            else {
                if (!InDanger(&theGrid[row][col+1], p1->getLiving()) && !InDanger(&theGrid[row][col+2], p1->getLiving())) {
                    c.attachPath(&theGrid[row][col+2]);
                }
            }
        }
        if (theGrid[row][col].getMove() == 0 && theGrid[row][col-4].getMove() == 0 && theGrid[row][col-1].getInfo().type == ChessType::Empty && theGrid[row][col-2].getInfo().type == ChessType::Empty && theGrid[row][col-3].getInfo().type == ChessType::Empty && theGrid[row][col-4].getInfo().type == ChessType::Rook) {
            if (p1->getColour() == theGrid[row][col].getInfo().colour) {
                if (!InDanger(&theGrid[row][col-1], p2->getLiving()) && !InDanger(&theGrid[row][col-2], p2->getLiving())) {
                    c.attachPath(&theGrid[row][col-2]);
                }
            }
            else {
                if (!InDanger(&theGrid[row][col-1], p2->getLiving()) && !InDanger(&theGrid[row][col-2], p1->getLiving())) {
                    c.attachPath(&theGrid[row][col-2]);
                }
            }
        }
    }
}

Grid::~Grid(){
    delete td;
    delete gd;
}
void Grid::init(Player* p1, Player* p2){
    delete td;
    delete gd;
    theGrid.clear();
    //create display ptr and assign p1 p2 ptrs
    td = new TextDisplay(size);
    gd = new GraphicsDisplay(size);
    this->p1 = p1;
    this->p2 = p2;
    //gd = new GraphicsDisplay(size);
    for (int i = 0; i < size; ++i){
        vector<Cell> row;
        theGrid.emplace_back(row);
        for (int j = 0; j < size; ++j){
            Cell c = Cell(i,j);
            //set the board
            if(i == 0){//white chess
                //p1 is white, p2 is black
                //add white to p1 living, p2 opponent list
                if(j == 0){
                    c.setType(ChessType::Rook);
                    c.setColour(Colour::White);
                }
                if(j == 1){
                    c.setType(ChessType::Knight);
                    c.setColour(Colour::White);
                }
                if(j == 2){
                    c.setType(ChessType::Bishop);
                    c.setColour(Colour::White);
                }
                if(j == 3){
                    c.setType(ChessType::Queen);
                    c.setColour(Colour::White);
                }
                if(j == 4){
                    c.setType(ChessType::King);
                    c.setColour(Colour::White);
                }
                if(j == 5){
                    c.setType(ChessType::Bishop);
                    c.setColour(Colour::White);
                }
                if(j == 6){
                    c.setType(ChessType::Knight);
                    c.setColour(Colour::White);
                }
                if(j == 7){
                    c.setType(ChessType::Rook);
                    c.setColour(Colour::White);
                }
            }
            else if(i == 1){//white pawns
                c.setType(ChessType::Pawn);
                c.setColour(Colour::White);
            }
            else if(i == 6){//black pawns
                //add black to p2 living and p1 opponent
                c.setType(ChessType::Pawn);
                c.setColour(Colour::Black);
            }
            else if(i == 7){//black chess
                if(j == 0){
                    c.setType(ChessType::Rook);
                    c.setColour(Colour::Black);
                }
                if(j == 1){
                    c.setType(ChessType::Knight);
                    c.setColour(Colour::Black);
                }
                if(j == 2){
                    c.setType(ChessType::Bishop);
                    c.setColour(Colour::Black);
                }
                if(j == 3){
                    c.setType(ChessType::Queen);
                    c.setColour(Colour::Black);
                }
                if(j == 4){
                    c.setType(ChessType::King);
                    c.setColour(Colour::Black);
                }
                if(j == 5){
                    c.setType(ChessType::Bishop);
                    c.setColour(Colour::Black);
                }
                if(j == 6){
                    c.setType(ChessType::Knight);
                    c.setColour(Colour::Black);
                }
                if(j == 7){
                    c.setType(ChessType::Rook);
                    c.setColour(Colour::Black);
                }
            }
            //attach observers to all chess
            c.attach(td);
            c.attach(gd);
            c.attach(p1);
            c.attach(p2);
            theGrid[i].emplace_back(c);
        }
    }
    for(int i = 0; i<7; i++){
        //add path to all living chess
        addValidPath(theGrid[0][i]);
        addValidPath(theGrid[1][i]);
        addValidPath(theGrid[6][i]);
        addValidPath(theGrid[7][i]);
    }
    //add the living chess to their corresponding player
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){
            if(theGrid[i][j].getInfo().colour == Colour::NoColour){}
            else if(theGrid[i][j].getInfo().colour == Colour::White){
                p1->addLiving(&(theGrid[i][j]));
            }
            else{
                p2->addLiving(&(theGrid[i][j]));
            }
        }
    }
} // Sets up an n x n grid.



void Grid::move(Player& p){
    //get info of p and opponent
    Player* self = &p;
    Player* opponent = p.getColour() == p1->getColour() ? p2 : p1;
    int c1 = p.getC1();
    int c2 = p.getC2();
    int r1 = p.getR1();
    int r2 = p.getR2();
    Colour colour = p.getColour();
    
    //check if it's p's chess that he's moving
    if(theGrid[r1][c1].getInfo().colour != colour) throw out_of_range("not your chess");
    
    //check if the chess can actually get there
    if(!valid(theGrid[r1][c1],theGrid[r2][c2])) throw out_of_range("invalid move");
    
    //check if removing the chess will put king in danger
    if(theGrid[r1][c1].getInfo().type != ChessType::King){
        //pretend that this move is taken
        Colour temp1 = theGrid[r1][c1].getInfo().colour;
        theGrid[r1][c1].setColour(Colour::NoColour);
        Colour temp2 = theGrid[r2][c2].getInfo().colour;
        theGrid[r2][c2].setColour(colour);
        resetPath(opponent);
        //if that move will put king in danger, dont do it
        if(InDanger(p.getKing(), opponent->getLiving())){
            //reset
            theGrid[r1][c1].setColour(temp1);
            theGrid[r2][c2].setColour(temp2);
            resetPath(opponent);
            //remove this step from valid path
            theGrid[r1][c1].removePath(theGrid[r2][c2]);
            //check if stale
            if(validPathSum(p) == 0) {
                throw end_game(Colour::NoColour);
            }
            throw out_of_range("invalid move,removing this chess will put king in danger");
        }
        //reset the change
        theGrid[r1][c1].setColour(temp1);
        theGrid[r2][c2].setColour(temp2);
        resetPath(opponent);
    }
    
    //check if the player is trying to move the king and it is safe to do so
    if(theGrid[r1][c1].getInfo().type == ChessType::King){
        //pretend that place is empty, and if it's on enemy's path, then king should not go there
        Colour temp = theGrid[r2][c2].getInfo().colour;
        //ChessType tempType = theGrid[r2][c2].getInfo().type;
        theGrid[r2][c2].setColour(colour);
        //theGrid[r2][c2].setType(ChessType::King);
        theGrid[r1][c1].setColour(Colour::NoColour);
        resetPath(opponent);
        //if that place will be under attack, it's an invalid move
        if(InDanger(&(theGrid[r2][c2]), opponent->getLiving())){
            //resets the path
            theGrid[r2][c2].setColour(temp);
            //theGrid[r2][c2].setType(tempType);
            theGrid[r1][c1].setColour(colour);
            resetPath(opponent);
            //remove this step from valid path
            theGrid[r1][c1].removePath(theGrid[r2][c2]);
            //check if stale
            if(validPathSum(p) == 0) {
                throw end_game(Colour::NoColour);
            }
            throw out_of_range("invalid move, let king go there is not a smart choice");
        }
        //resets the path
        theGrid[r2][c2].setColour(temp);
        //theGrid[r2][c2].setType(tempType);
        theGrid[r1][c1].setColour(colour);
        resetPath(opponent);
    }
    
    //check if it's king that is taken, if yes , throw an exception to show that the game is over
    if(theGrid[r2][c2].getInfo().type == ChessType::King) {
        throw end_game(colour,false);
    }
    
    // pawn promotion
    if (theGrid[r1][c1].getInfo().type == ChessType::Pawn && theGrid[r1][c1].getInfo().colour == Colour::Black && r2 == 0) {
        if (!p.isAI) {
            char promotion;
            cin >> promotion;
            if (promotion == 'Q') {
                theGrid[r1][c1].setType(ChessType::Queen);
            }
            else if (promotion == 'R') {
                theGrid[r1][c1].setType(ChessType::Rook);
            }
            else if (promotion == 'N') {
                theGrid[r1][c1].setType(ChessType::Knight);
            }
            else if (promotion == 'B') {
                theGrid[r1][c1].setType(ChessType::Bishop);
            }
        }
        else {
            theGrid[r1][c1].setType(ChessType::Queen);
        }
    }
    else if (theGrid[r1][c1].getInfo().type == ChessType::Pawn && theGrid[r1][c1].getInfo().colour == Colour::White && r2 == 7) {
        if (!p.isAI) {
            char promotion;
            cin >> promotion;
            if (promotion == 'Q') {
                theGrid[r1][c1].setType(ChessType::Queen);
            }
            else if (promotion == 'R') {
                theGrid[r1][c1].setType(ChessType::Rook);
            }
            else if (promotion == 'N') {
                theGrid[r1][c1].setType(ChessType::Knight);
            }
            else if (promotion == 'B') {
                theGrid[r1][c1].setType(ChessType::Bishop);
            }
        }
        else {
            theGrid[r1][c1].setType(ChessType::Queen);
        }
    }
    
    
    //check if this is a move of pawn capture en passant by black player
    if (theGrid[r1][c1].getInfo().type == ChessType::Pawn && theGrid[r2][c2].getInfo().type == ChessType::Empty && c2 != c1 && theGrid[r1][c1].getInfo().colour == Colour::Black) {
        
        //tell the observers that we are actually taking the pawn below me
        theGrid[r1][c1].notifyObservers(theGrid[r2+1][c2]);
        //create an empty cell at the opponent pawn's position
        theGrid[r2+1][c2] = Cell(r2+1, c2);
        theGrid[r2+1][c2].attach(gd);
        theGrid[r2+1][c2].attach(td);
        theGrid[r2+1][c2].attach(p1);
        theGrid[r2+1][c2].attach(p2);
    }
    
    //check if this is a move of pawn capture en passant by white player
    else if (theGrid[r1][c1].getInfo().type == ChessType::Pawn && theGrid[r2][c2].getInfo().type == ChessType::Empty && c2 != c1 && theGrid[r1][c1].getInfo().colour == Colour::White) {
        //tell the observers that we are actually taking the pawn below me
        theGrid[r1][c1].notifyObservers(theGrid[r2-1][c2]);
        //create an empty cell at the opponent pawn's position
        theGrid[r2-1][c2] = Cell(r2-1, c2);
        theGrid[r2-1][c2].attach(gd);
        theGrid[r2-1][c2].attach(td);
        theGrid[r2-1][c2].attach(p1);
        theGrid[r2-1][c2].attach(p2);
    }
    
    //check if this is a castling move and king is moving to the right
    else if (theGrid[r1][c1].getInfo().type == ChessType::King && c2 - c1 == 2) {
        //since it's castling, the player is actually making two moves
        //move the king
        theGrid[r1][c1].notifyObservers(theGrid[r2][c2]);
        //move the Rook
        theGrid[r1][c1+3].notifyObservers(theGrid[r1][c1+1]);
        //move rook to it's position after the castling
        //create new Cell at r1,c1+1 with r1,c1+3 (Rook) type and colour and observers
        theGrid[r1][c1+1].setColour(colour);
        theGrid[r1][c1+1].setType(ChessType::Rook);
        //add one move the the newly moved chess (rook cannot be previously moved)
        theGrid[r1][c1+1].increMove(0);
        //attach observers
        theGrid[r1][c1+1].attach(gd);
        theGrid[r1][c1+1].attach(td);
        theGrid[r1][c1+1].attach(p1);
        theGrid[r1][c1+1].attach(p2);
        //update p1 p2's living chess list
        p.addLiving(&theGrid[r1][c1+1]);
        //clear the cell at r1, c1+3 (Rook)
        theGrid[r1][c1+3] = Cell(r1, c1+3);
        theGrid[r1][c1+3].attach(gd);
        theGrid[r1][c1+3].attach(td);
        theGrid[r1][c1+3].attach(p1);
        theGrid[r1][c1+3].attach(p2);
    }
    //if this is a castling move and king is moving to the left
    else if (theGrid[r1][c1].getInfo().type == ChessType::King && c2 - c1 == -2) {
        //since it's castling, the player is actually making two moves
        //move the king
        theGrid[r1][c1].notifyObservers(theGrid[r2][c2]);
        //move the Rook
        theGrid[r1][c1-4].notifyObservers(theGrid[r1][c1-1]);
        //move rook to it's position after the castling
        //create new Cell at r1,c1-1 with r1,c1-4 (Rook) type and colour
        theGrid[r1][c1-1].setColour(colour);
        theGrid[r1][c1-1].setType(ChessType::Rook);
        //add one move the the newly moved chess (rook cannot be previously moved)
        theGrid[r1][c1-1].increMove(0);
        //attach observers
        theGrid[r1][c1-1].attach(gd);
        theGrid[r1][c1-1].attach(td);
        theGrid[r1][c1-1].attach(p1);
        theGrid[r1][c1-1].attach(p2);
        //update p1 p2's living chess list
        p.addLiving(&theGrid[r1][c1-1]);
        //clear the cell at r1, c1+3 (Rook)
        theGrid[r1][c1-4] = Cell(r1, c1-4);
        theGrid[r1][c1-4].attach(gd);
        theGrid[r1][c1-4].attach(td);
        theGrid[r1][c1-4].attach(p1);
        theGrid[r1][c1-4].attach(p2);
    }
    //else it's not a special move
    //notify the observers that this move will be executed
    else theGrid[r1][c1].notifyObservers(theGrid[r2][c2]);
    //create new Cell at r2,c2 with r1,c1 chess's type and colour and observers
    theGrid[r2][c2].setColour(colour);
    theGrid[r2][c2].setType(theGrid[r1][c1].getInfo().type);
    //add one move to the newly moved chess
    theGrid[r2][c2].increMove(theGrid[r1][c1].getMove());
    //update p1 p2's living chess list
    p.addLiving(&theGrid[r2][c2]);
    //create empty chess at r1 c1
    theGrid[r1][c1] = Cell(r1, c1);
    //attach observers to empty chess
    theGrid[r1][c1].attach(gd);
    theGrid[r1][c1].attach(td);
    theGrid[r1][c1].attach(p1);
    theGrid[r1][c1].attach(p2);
    //clear all chess's avaliable path and then initialize new path correspondingly
    resetPath();

} // move chess at r1, c1 to r2 c2 is possible




void Grid::isCheckMate(Player& p){
    Player* opponent = p.getColour() == p1->getColour() ? p2 : p1;
    bool kingChecked = false;
    Cell* checking;
    
    //check if game is tied only king left
    if(p1->getLiving().size() == 1 && p2->getLiving().size() == 1){
        throw end_game(Colour::NoColour);
    }
    //check if  one has no legal moves
    if(validPathSum(p) == 0 || validPathSum(*opponent) == 0){
        throw end_game(Colour::NoColour);
    }
    //p's king is checked
    for(auto& op: opponent->getLiving()){
        //if one of opponent's chess is checking king
        if(op->isCheck()){
            kingChecked = true;
            checking = op;
            string s = p.getColour() == Colour::White ? "White": "Black";
            cout << s + " is in check!" << endl;
        }
    }
    if(!kingChecked) { // p's king is not checked
        return;
    }
    
    //p's chess can take the checking chess
    for(auto& lc :  p.getLiving()){
        if(lc->inPath(*checking) && lc->getInfo().type != ChessType::King){
            //see if removing that chess will put king in danger
            lc->setColour(Colour::NoColour);
            checking->setColour(p.getColour());
            resetPath();
            //it's a valid protection
            if(!InDanger(p.getKing(), opponent->getLiving())){
                cout << "checking chess can be taken" << endl;
                
                //the only move is to take the checking chess
                clearPath();
                lc->attachPath(checking);
                //reset the changes
                lc->setColour(p.getColour());
                checking->setColour(opponent->getColour());
                return;
            }
        }
        lc->setColour(p.getColour());
        checking->setColour(opponent->getColour());
        resetPath();
        
    }

    //if king can take the checking chess we need to check if that position will be checked
    if(p.getKing()->inPath(*(checking))){
        checking->setColour(p.getColour());
        p.getKing()->setColour(Colour::NoColour);
        resetPath(opponent);
        if(!InDanger(checking, opponent->getLiving())){
            //the only move is to take the checking chess
            clearPath();
            p.getKing()->attachPath(checking);
            //reset the change modified
            checking->setColour(opponent->getColour());
            p.getKing()->setColour(p.getColour());
            return;
        }
        //king can't take checking's position, now reset
        checking->setColour(opponent->getColour());
        p.getKing()->setColour(p.getColour());
        resetPath(opponent);
        
        //algorithm
        //pretend that spot is empty so that we can see that position is "guarded" by an ally
        // if not let king take that chess
        
    }

    //p's king cannot move
    // p's king's validpath are all in opponent's living chess's validpath
    for(auto& km: p.getKing()->getValidPath()){ // king's valid path
        // if one of king's validPath is not in danger, means that king can escape
        //pretend king goes there
        Colour temp = km->getInfo().colour;
        km->setColour(p.getColour());
        p.getKing()->setColour(Colour::NoColour);
        resetPath(opponent);
        if(!InDanger(km, opponent->getLiving())) {

            cout << "king can escape" << endl;
            //the only move is the escape move
            clearPath();
            p.getKing()->attachPath(km);
            //reset
            km->setColour(temp);
            p.getKing()->setColour(p.getColour());
            cout << km->getInfo().row << " " << km->getInfo().col << endl;
            return;
        }
        //reset
        km->setColour(temp);
        p.getKing()->setColour(p.getColour());
        resetPath(opponent);
    }



    //p's chess can block the checking chess
    if((checking->getInfo().type == ChessType::Queen || checking->getInfo().type == ChessType::Rook || checking->getInfo().type == ChessType::Bishop) && p.getLiving().size() != 1){
        int rk = p.getKing()->getInfo().row; //row of king
        int ck = p.getKing()->getInfo().col; //column of king
        int rc = checking->getInfo().row; //row of checking chess
        int cc = checking->getInfo().col; //column of checking chess
        //remove king from living temporarily so that we can check if checking chess can be blocked
        p.getKing()->clearPath();
        if(rc > rk && cc < ck){
            for(int i = 1; rc - i > rk ; i++){
                if(InDanger(&(theGrid[rc-i][cc+i]), p.getLiving())){ //the checking chess can be blocked by one of p's living chess
                    cout << "checking chess can be blocked" << endl;
                    
                    return;
                }
            }
        }
        else if(rc > rk && cc == ck){
            for(int i = 1; rc - i > rk ; i++){
                if(InDanger(&(theGrid[rc-i][cc]), p.getLiving())){ //the checking chess can be blocked by one of p's living chess
                    cout << "checking chess can be blocked" << endl;

                    return;
                }
            }
        }
        else if(rc > rk && cc > ck){
            for(int i = 1; rc - i > rk ; i++){
                if(InDanger(&(theGrid[rc-i][cc-i]), p.getLiving())){ //the checking chess can be blocked by one of p's living chess
                    cout << "checking chess can be blocked" << endl;

                    return;
                }
            }
        }
        else if(rc == rk && cc < ck){
            for(int i = 1; cc + i < ck ; i++){
                if(InDanger(&(theGrid[rc][cc+i]), p.getLiving())){ //the checking chess can be blocked by one of p's living chess
                    cout << "checking chess can be blocked" << endl;

                    return;
                }
            }
        }
        else if(rc == rk && cc > ck){
            for(int i = 1; cc - i > ck ; i++){
                if(InDanger(&(theGrid[rc][cc-i]), p.getLiving())){ //the checking chess can be blocked by one of p's living chess
                    cout << "checking chess can be blocked" << endl;

                    return;
                }
            }
        }
        else if(rc < rk && cc < ck){
            for(int i = 1; rc + i < rk ; i++){
                if(InDanger(&(theGrid[rc+i][cc+i]), p.getLiving())){ //the checking chess can be blocked by one of p's living chess
                    cout << "checking chess can be blocked" << endl;

                    return;
                }
            }
        }
        else if(rc < rk && cc == ck){
            for(int i = 1; rc + i < rk ; i++){
                if(InDanger(&(theGrid[rc+i][cc]), p.getLiving())){ //the checking chess can be blocked by one of p's living chess
                    cout << "checking chess can be blocked" << endl;

                    return;
                }
            }
        }
        else if(rc < rk && cc > ck){
            for(int i = 1; rc + i < rk ; i++){
                if(InDanger(&(theGrid[rc+i][cc-i]), p.getLiving())){ //the checking chess can be blocked by one of p's living chess
                    cout << "checking chess can be blocked" << endl;
                    return;
                }
            }
        }
        //add king back to the list
        resetPath();
        
    }
    //otherwise p loses
    throw end_game(p.getColour());
}


// returns true if to is on from's path
bool Grid::valid(Cell& from, Cell& to){
    return from.inPath(to);
}

//print the grid
 ostream& operator<<(std::ostream &out, const Grid &g){
     out << *(g.td);
    return out;
}


