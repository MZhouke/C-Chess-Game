#include <iostream>
#include <string>
#include "grid.h"
#include "human.h"
#include "aiOne.h"
#include "aiTwo.h"

// dui de
using namespace std;

int main() {
    float whiteScore = 0;
    float blackScore = 0;
    cout << "Please input \"game player1 player2 to start game\"" << endl;
    string cmd;
    cin >> cmd;
    if(cin.eof()){
        cout << "Final Score:" << endl;
        cout << "White: " << whiteScore << endl;
        cout << "Black: " << blackScore << endl;
        return 0;
    }
    if(cmd == "game") {
        string white_player;
        string black_player;
        cin >> white_player;
        if(cin.eof()){
            cout << "Final Score:" << endl;
            cout << "White: " << whiteScore << endl;
            cout << "Black: " << blackScore << endl;
            return 0;
        }
        cin >> black_player;
        if(cin.eof()){
            cout << "Final Score:" << endl;
            cout << "White: " << whiteScore << endl;
            cout << "Black: " << blackScore << endl;
            return 0;
        }
        Player * white;
        Player * black;
        if(white_player == "computer1") {
            white = new AI_1(Colour::White);
        } else if (white_player == "computer2") {
            white = new AI_2(Colour::White);
        } else {
            white = new Human(Colour::White);
        }
        if(black_player == "computer1") {
            black = new AI_1(Colour::Black);
        } else if (black_player == "computer2") {
            black = new AI_2(Colour::Black);
        } else {
            black = new Human(Colour::Black);
        }
        Grid g;
        g.init(white, black);
        cout << "Chessboard Initialized" << endl;
        cout << g << endl;
        bool whiteTurn = true;
        
        // Play the game
        while(true) {
            if((whiteTurn && !white->isAI) || (!whiteTurn && !black->isAI)) { // When Human's turn
                cin >> cmd;
                if(cin.eof()){
                    cout << "Final Score:" << endl;
                    cout << "White: " << whiteScore << endl;
                    cout << "Black: " << blackScore << endl;
                    return 0;
                }
                if(cmd == "resign") {
                    if(whiteTurn) {
                        cout << "Black Wins!" << endl;
                        blackScore += 1;
                        cout << "Do you want to play again? (Y/N)" << endl;
                        char again;
                        cin >> again;
                        if(cin.eof()){
                            cout << "Final Score:" << endl;
                            cout << "White: " << whiteScore << endl;
                            cout << "Black: " << blackScore << endl;
                            return 0;
                        }
                        if (again == 'Y') {
                            white->clear();
                            black->clear();
                            g.init(white, black);
                            cout << "Chessboard Initialized" << endl;
                            cout << g << endl;
                            whiteTurn = true;
                            continue;
                        }
                        else {
                            cout << "Final Score:" << endl;
                            cout << "White: " << whiteScore << endl;
                            cout << "Black: " << blackScore << endl;
                            break;
                        }
                    } else {
                        cout << "White Wins!" << endl;
                        whiteScore += 1;
                        cout << "Do you want to play again? (Y/N)" << endl;
                        char again;
                        cin >> again;
                        if(cin.eof()){
                            cout << "Final Score:" << endl;
                            cout << "White: " << whiteScore << endl;
                            cout << "Black: " << blackScore << endl;
                            return 0;
                        }
                        if (again == 'Y') {
                            white->clear();
                            black->clear();
                            g.init(white, black);
                            cout << "Chessboard Initialized" << endl;
                            cout << g << endl;
                            whiteTurn = true;
                            continue;
                        }
                        else {
                            cout << "Final Score:" << endl;
                            cout << "White: " << whiteScore << endl;
                            cout << "Black: " << blackScore << endl;
                            break;
                        }
                    }
                } else if (cmd == "move") { //human is moving
                    try {
                        if(whiteTurn){
                            cout << "Human white" << endl;
                            white->getInput();
                            g.move(*white);
                            whiteTurn = false;
                            cout << g << endl;
                            g.isCheckMate(*black);
                        } else {
                            cout << "Human black" << endl;
                            black->getInput();
                            g.move(*black);
                            whiteTurn = true;
                            cout << g << endl;
                            g.isCheckMate(*white);
                        }
                    } catch (out_of_range& r) {
                        cout << r.what() << endl;
                        continue;
                    }
                    catch(end_game &e){
                        if(e.whoWon() == Colour::White){
                            whiteScore += 1;
                        }
                        else if (e.whoWon() == Colour::Black){
                            blackScore += 1;
                        }
                        else{
                            whiteScore += 0.5;
                            blackScore += 0.5;
                        }
                        cout << "Do you want to play again? (Y/N)" << endl;
                        char again;
                        cin >> again;
                        if(cin.eof()){
                            cout << "Final Score:" << endl;
                            cout << "White: " << whiteScore << endl;
                            cout << "Black: " << blackScore << endl;
                            return 0;
                        }
                        if (again == 'Y') {
                            white->clear();
                            black->clear();
                            g.init(white, black);
                            cout << "Chessboard Initialized" << endl;
                            cout << g << endl;
                            whiteTurn = true;
                            continue;
                        }
                        else {
                            cout << "Final Score:" << endl;
                            cout << "White: " << whiteScore << endl;
                            cout << "Black: " << blackScore << endl;
                            break;
                        }
                    }
                }
            } else { // when AI's turn
                cin >> cmd;
                try{
                    if(whiteTurn) {
                        if (cmd != "move") continue;
                        //cout << "AI white" << endl;
                        white->getInput();
                        g.move(*white);
                        whiteTurn = false;
                        cout << g << endl;
                        g.isCheckMate(*black);
                    } else if (!whiteTurn) {
                        if (cmd != "move") continue;
                        //cout << "AI black" << endl;
                        black->getInput();
                        g.move(*black);
                        whiteTurn = true;
                        cout << g << endl;
                        g.isCheckMate(*white);
                    }
                }
                catch(end_game &e){
                    if(e.whoWon() == Colour::White){
                        whiteScore += 1;
                    }
                    else if (e.whoWon() == Colour::Black){
                        blackScore += 1;
                    }
                    else{
                        whiteScore += 0.5;
                        blackScore += 0.5;
                    }
                    cout << "Do you want to play again? (Y/N)" << endl;
                    char again;
                    cin >> again;
                    if(cin.eof()){
                        cout << "Final Score:" << endl;
                        cout << "White: " << whiteScore << endl;
                        cout << "Black: " << blackScore << endl;
                        return 0;
                    }
                    if (again == 'Y') {
                        white->clear();
                        black->clear();
                        g.init(white, black);
                        cout << "Chessboard Initialized" << endl;
                        cout << g << endl;
                        whiteTurn = true;
                        continue;
                    }
                    else {
                        cout << "Final Score:" << endl;
                        cout << "White: " << whiteScore << endl;
                        cout << "Black: " << blackScore << endl;
                        break;
                    }
                }
                catch(out_of_range &o) {
                    //cout << o.what() << endl;
                    continue;
                }
            }
        }
        delete white;
        delete black;
    } else {
        cout << "You did not start the game" << endl;
    }
    
    
    return 0;
}
