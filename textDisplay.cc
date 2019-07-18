#include "textDisplay.h"
#include "subject.h"

using namespace std;

TextDisplay::TextDisplay(int n): gridSize{n} {
    vector<vector<char>> newDisplay;
    theDisplay = newDisplay;
    for(int r = 0; r < n; ++r) {
        theDisplay.emplace_back(vector<char>());
        for(int c = 0; c < n; ++c) {
            theDisplay.back().emplace_back('-');
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i == 0){//white chess
                if(j == 0){
                    theDisplay[i][j] = 'R';
                }
                if(j == 1){
                    theDisplay[i][j] = 'N';
                }
                if(j == 2){
                    theDisplay[i][j] = 'B';
                }
                if(j == 3){
                    theDisplay[i][j] = 'Q';
                }
                if(j == 4){
                    theDisplay[i][j] = 'K';
                }
                if(j == 5){
                    theDisplay[i][j] = 'B';
                }
                if(j == 6){
                    theDisplay[i][j] = 'N';
                }
                if(j == 7){
                    theDisplay[i][j] = 'R';
                }
            }
            else if(i == 1){//white pawns
                theDisplay[i][j] = 'P';
            }
            else if(i == 6){//black pawns
                //add black to p2 living and p1 opponent
                theDisplay[i][j] = 'p';
            }
            else if(i == 7){//black chess
                if(j == 0){
                    theDisplay[i][j] = 'r';
                }
                if(j == 1){
                    theDisplay[i][j] = 'n';
                }
                if(j == 2){
                    theDisplay[i][j] = 'b';
                }
                if(j == 3){
                    theDisplay[i][j] = 'q';
                }
                if(j == 4){
                    theDisplay[i][j] = 'k';
                }
                if(j == 5){
                    theDisplay[i][j] = 'b';
                }
                if(j == 6){
                    theDisplay[i][j] = 'n';
                }
                if(j == 7){
                    theDisplay[i][j] = 'r';
                }
            }
        }
    }
}

ostream& operator<<(std::ostream &out, const TextDisplay &td) {
    int y_axis = 8;
    for(int i = 7; i >= 0; --i){
        auto &r = td.theDisplay[i];
        out << y_axis << " ";
        for(auto & c : r) {
            out << c;
        }
        out << endl;
        --y_axis;
    }
    out << endl;
    out << "  abcdefgh";
    return out;
}

void TextDisplay::notify(Subject &from, Subject &to) {
    theDisplay.at(from.getInfo().row).at(from.getInfo().col) = '-';
    size_t r = to.getInfo().row;
    size_t c = to.getInfo().col;
    //this is for pawn capture en passant.
    if (from.getInfo().type == ChessType::Pawn && from.getInfo().row == to.getInfo().row && from.getInfo().colour == Colour::Black) {
        theDisplay.at(r-1).at(c) = 'p';
        theDisplay.at(r).at(c) = '-';
    }
    else if (from.getInfo().type == ChessType::Pawn && from.getInfo().row == to.getInfo().row && from.getInfo().colour == Colour::White) {
        theDisplay.at(r+1).at(c) = 'P';
        theDisplay.at(r).at(c) = '-';
    }
    else {
        if(from.getInfo().type == ChessType::Empty) {
            theDisplay.at(r).at(c) = '-';
        } else if (from.getInfo().colour == Colour::Black) {
            if (from.getInfo().type == ChessType::Bishop) {
                theDisplay.at(r).at(c) = 'b';
            } else if (from.getInfo().type == ChessType::King) {
                theDisplay.at(r).at(c) = 'k';
            } else if (from.getInfo().type == ChessType::Knight) {
                theDisplay.at(r).at(c) = 'n';
            } else if (from.getInfo().type == ChessType::Pawn) {
                theDisplay.at(r).at(c) = 'p';
            } else if (from.getInfo().type == ChessType::Queen) {
                theDisplay.at(r).at(c) = 'q';
            } else if (from.getInfo().type == ChessType::Rook) {
                theDisplay.at(r).at(c) = 'r';
            }
        } else if (from.getInfo().colour == Colour::White) {
            if (from.getInfo().type == ChessType::Bishop) {
                theDisplay.at(r).at(c) = 'B';
            } else if (from.getInfo().type == ChessType::King) {
                theDisplay.at(r).at(c) = 'K';
            } else if (from.getInfo().type == ChessType::Knight) {
                theDisplay.at(r).at(c) = 'N';
            } else if (from.getInfo().type == ChessType::Pawn) {
                theDisplay.at(r).at(c) = 'P';
            } else if (from.getInfo().type == ChessType::Queen) {
                theDisplay.at(r).at(c) = 'Q';
            } else if (from.getInfo().type == ChessType::Rook) {
                theDisplay.at(r).at(c) = 'R';
            }
        }
    }
}
