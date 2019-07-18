//
//  endGame.hpp
//  a5
//
//  Created by Michael Zhou on 2019-04-04.
//  Copyright © 2019 Michael Zhou. All rights reserved.
//

#ifndef endGame_h
#define endGame_h

#include <iostream>
#include <cstddef>

//exception class to end the game
class end_game : public std::exception {
    std::string s;
    Colour winner;
public:
    Colour whoWon(){
        return winner;
    }
    end_game(Colour c, bool isCheckMate = true):s{}{
        if(isCheckMate){
            // if it's a checkmage exception
            winner = c == Colour::White? Colour::Black : c == Colour::Black? Colour::White : Colour::NoColour;
            s = c == Colour::White? "Checkmate! Black wins!" : c == Colour::Black? "Checkmate! White wins!" : "Stalemate!";
            }
        else{
            winner = c;
            s = c == Colour::White? "White wins! Black's King is taken" : "Black wins! White's King is taken";
        }
        std::cout << s << std::endl;
    }
};
#endif /* endGame_hpp */
