#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <ctime>


using namespace std;

//              GLOBAL VARIABLES
//      vvv     only applicable to first 2 rows
const string col1 = "_";
const string col2 = "_|_";
const string col3 = col2;
const string col4 = col1;
//      vvv     only applicable to row 3
const string col13 = " ";
const string col23 = " | ";
const string col33 = col23;
const string col43 = col13;
//      vvv     loop breakers
int breakertemp = -1;               // used in userTurn and compTurn

int firstTurn = -1;                 // 'O' goes first

// Spots on board
bool un = false;        bool deux = false;      bool trois = false;
bool quatre = false;    bool cinq = false;      bool six = false;
bool sept = false;      bool huit = false;      bool neuf = false;
//      vvv values on board
char one = '_';       char two = one;       char three = one;
char four = one;      char five = one;      char sixx = one;
char seven = ' ';     char eight = ' ';     char nine = ' ';

// if this equals 1, 'O' wins
// if this equals 2, 'X' wins
int victoryCondition = 0;


void headsVsTails() {
    string comp_guess;
    int computer_guess = time(0) % 2;   // random number between 0 and 1
                // 0 is heads, 1 is tails
    if (computer_guess == 0) {
        comp_guess = "heads";
    }
    else {
        comp_guess = "tails";
    }
    string guess;                   // user guess: heads or tail
    
    cout << endl;
    cout << "-------------------------------------------------" << endl;
    
    cout << "Let's Play Tic-Tac-Toe!" << endl;
    do {                            // repeat loop if no heads or tails
        cout << "\'Heads\' or \'Tails\' to see who will start: ";
        cin >> guess;
        for (int i = 0; i < guess.length(); ++i) {
            guess.at(i) = tolower(guess.at(i));     // turns guess into
        }                                           // into lowercase
        
        if (guess != "heads" && guess != "tails") {
            cout << "Try Again" << endl;
        }
    } while (guess != "heads" && guess != "tails");
    
    cout << "-------------------------------------------------" << endl;
    
                        // Who goes first
    
    cout << "Coin flip: " << comp_guess << endl;
    if (guess == comp_guess) {
        cout << "You go first" << endl;
        firstTurn = 0;
    }
    else {
        cout << "I go first" << endl;
        firstTurn = 1;
    }
    
    cout << "-------------------------------------------------" << endl;
    //                      Display Board
    cout << "Board: " << endl;
    cout << "_1_|_2_|_3_" << endl;
    cout << "_4_|_5_|_6_" << endl;
    cout << " 7 | 8 | 9 " << endl;
    
    cout << "-------------------------------------" << endl;
}



//                  PRINTS BOARD
string currentBoard(char one,char two,char three,char four,char five,
    char sixx,char seven,char eight,char nine) {
    
    return col1 + one + col2 + two + col3 + three + col4 +
        "\n" + col1 + four + col2 + five + col3 + sixx + col4 +
        "\n" + col13 + seven + col23 + eight + col33 + nine + col43 +
        "\n";
}



//                  WHO WINS :D
void checkVictory() {
    if (one == 'O' && one == two && one == three) {
        victoryCondition = 1;
    }
    if (one == 'X' && one == two && one == three) {
        victoryCondition = 2;
    }
    if (one == 'O' && one == four && one == seven) {
        victoryCondition = 1;
    }
    if (one == 'X' && one == four && one == seven) {
        victoryCondition = 2;
    }
    if (one == 'O' && one == five && one == nine) {
        victoryCondition = 1;
    }
    if (one == 'X' && one == five && one == nine) {
        victoryCondition = 2;
    }
    if (two == 'O' && two == five && two == eight) {
        victoryCondition = 1;
    }
    if (two == 'X' && two == five && two == eight) {
        victoryCondition = 2;
    }
    if (three == 'O' && three == sixx && three == nine) {
        victoryCondition = 1;
    }
    if (three == 'X' && three == sixx && three == nine) {
        victoryCondition = 2;
    }
    if (three == 'O' && three == five && three == seven) {
        victoryCondition = 1;
    }
    if (three == 'X' && three == five && three == seven) {
        victoryCondition = 2;
    }
    if (four == 'O' && four == five && four == sixx) {
        victoryCondition = 1;
    }
    if (four == 'X' && four == five && four == sixx) {
        victoryCondition = 2;
    }
    if (seven == 'O' && seven == eight && seven == nine) {
        victoryCondition = 1;
    }
    if (seven == 'X' && seven == eight && seven == nine) {
        victoryCondition = 2;
    }
}




//                  USER TURN            
//  vvvvvvvvvv      FIX FOR MULTIPLE INPUTS OF NUMBER   vvvvvvvvvvvvvv



void userTurn(char theO) {
    // breakertemp is -1
    char number = -1;
    while (breakertemp == -1) {
        cout << "Make your move (pick a number 1- 9): ";
        cin >> number;
        breakertemp = -1;          // resets value to -1
        
        if (!isdigit(number)) {
            cout << "Not a valid entry" << endl;
        } else if (number == '1') {             // number is char so
            if (un) {                   // need single quote
                cout << "Space not vacant" << endl;
            }
            else {
                un = true;
                one = theO;
                breakertemp += 1;
            }
        } else if (number == '2') {
            if (deux) {                   // need single quote
                cout << "Space not vacant" << endl;
            }
            else {
                deux = true;
                two = theO;
                breakertemp += 1;
            }
        } else if (number == '3') {
            if (trois) {                   // need single quote
                cout << "Space not vacant" << endl;
            }
            else {
                trois = true;
                three = theO;
                breakertemp += 1;
            }
        } else if (number == '4') {
            if (quatre) {                   // need single quote
                cout << "Space not vacant" << endl;
            }
            else {
                quatre = true;
                four = theO;
                breakertemp += 1;
            }
        } else if (number == '5') {
            if (cinq) {                   // need single quote
                cout << "Space not vacant" << endl;
            }
            else {
                cinq = true;
                five = theO;
                breakertemp += 1;
            }
        } else if (number == '6') {
            if (six) {                   // need single quote
                cout << "Space not vacant" << endl;
            }
            else {
                six = true;
                sixx = theO;
                breakertemp += 1;
            }
        } else if (number == '7') {
            if (sept) {                   // need single quote
                cout << "Space not vacant" << endl;
            }
            else {
                sept = true;
                seven = theO;
                breakertemp += 1;
            }
        } else if (number == '8') {
            if (huit) {                   // need single quote
                cout << "Space not vacant" << endl;
            }
            else {
                huit = true;
                eight = theO;
                breakertemp += 1;
            }
        } else if (number == '9') {
            if (neuf) {                   // need single quote
                cout << "Space not vacant" << endl;
            }
            else {
                neuf = true;
                nine = theO;
                breakertemp += 1;
            }
        }
        else {
            cout << "Not a valid entry" << endl;
        }
    }
    
    cout << currentBoard(one,two,three,four,five,sixx,seven,eight,nine);
    breakertemp = -1;                  // resets back to -1
}



//                      Comp will try to win
void compSmart(char theX) {
    
    //  top row
    if (one == theX && two == theX && !trois) {
        trois = true;
        three = theX;
        breakertemp += 1;
    }
    else if (two == theX && three == theX && !un) {
        un = true;
        one = theX;
        breakertemp += 1;
    }
    else if (three == theX && one == theX && !deux) {
        deux = true;
        two = theX;
        breakertemp += 1;
    }
    
    //  mid row
    else if (four == theX && five == theX && !six) {
        six = true;
        sixx = theX;
        breakertemp += 1;
    }
    else if (five == theX && sixx == theX && !quatre) {
        quatre = true;
        four = theX;
        breakertemp += 1;
    }
    else if (sixx == theX && four == theX && !cinq) {
        cinq = true;
        five = theX;
        breakertemp += 1;
    }
    
    //  bot row
    else if (seven == theX && eight == theX && !neuf) {
        neuf = true;
        nine = theX;
        breakertemp += 1;
    }
    else if (eight == theX && nine == theX && !sept) {
        sept = true;
        seven = theX;
        breakertemp += 1;
    }
    else if (nine == theX && seven == theX && !huit) {
        huit = true;
        eight = theX;
        breakertemp += 1;
    }
    
    // top diagonal
    else if (one == theX && five == theX && !neuf) {
        neuf = true;
        nine = theX;
        breakertemp += 1;
    }
    else if (five == theX && nine == theX && !un) {
        un = true;
        one = theX;
        breakertemp +=1;
    }
    else if (nine == theX && one == theX && !cinq) {
        cinq = true;
        five = theX;
        breakertemp += 1;
    }
    
    //  bot diagonal
    else if (three == theX && five == theX && !sept) {
        sept = true;
        seven = theX;
        breakertemp += 1;
    }
    else if (five == theX && seven == theX && !trois) {
        trois = true;
        three = theX;
        breakertemp += 1;
    }
    else if (seven == theX && three == theX && !cinq) {
        cinq = true;
        five = theX;
        breakertemp += 1;
    }
    
    //  left column
    else if (one == theX && four == theX && !sept) {
        sept = true;
        seven = theX;
        breakertemp += 1;
    }
    else if (four == theX && seven == theX && !un) {
        un = true;
        one = theX;
        breakertemp += 1;
    }
    else if (seven == theX && one == theX && !quatre) {
        quatre = true;
        four = theX;
        breakertemp += 1;
    }
    
    //  mid column
    else if (two == theX && five == theX && !huit) {
        huit = true;
        eight = theX;
        breakertemp += 1;
    }
    else if (five == theX && eight == theX && !deux) {
        deux = true;
        two = theX;
        breakertemp += 1;
    }
    else if (eight == theX && two == theX && !cinq) {
        cinq = true;
        five = theX;
        breakertemp += 1;
    }
    
    //  right column
    else if (three == theX && sixx == theX && !neuf) {
        neuf = true;
        nine = theX;
        breakertemp += 1;
    }
    else if (sixx == theX && nine == theX && !trois) {
        trois = true;
        three = theX;
        breakertemp += 1;
    }
    else if (nine == theX && three == theX && !six) {
        six = true;
        sixx = theX;
        breakertemp += 1;
    }
    
}

//                  Try to block user from winning
void compBlock(char theX, char theP) {
    
    //  top row
    if (one == theP && two == theP && !trois) {
        trois = true;
        three = theX;
        breakertemp += 1;
    }
    else if (two == theP && three == theP && !un) {
        un = true;
        one = theX;
        breakertemp += 1;
    }
    else if (three == theP && one == theP && !deux) {
        deux = true;
        two = theX;
        breakertemp += 1;
    }
    
    //  mid row
    else if (four == theP && five == theP && !six) {
        six = true;
        sixx = theX;
        breakertemp += 1;
    }
    else if (five == theP && sixx == theP && !quatre) {
        quatre = true;
        four = theX;
        breakertemp += 1;
    }
    else if (sixx == theP && four == theP && !cinq) {
        cinq = true;
        five = theX;
        breakertemp += 1;
    }
    
    //  bot row
    else if (seven == theP && eight == theP && !neuf) {
        neuf = true;
        nine = theX;
        breakertemp += 1;
    }
    else if (eight == theP && nine == theP && !sept) {
        sept = true;
        seven = theX;
        breakertemp += 1;
    }
    else if (nine == theP && seven == theP && !huit) {
        huit = true;
        eight = theX;
        breakertemp += 1;
    }
    
    // top diagonal
    else if (one == theP && five == theP && !neuf) {
        neuf = true;
        nine = theX;
        breakertemp += 1;
    }
    else if (five == theP && nine == theP && !un) {
        un = true;
        one = theX;
        breakertemp +=1;
    }
    else if (nine == theP && one == theP && !cinq) {
        cinq = true;
        five = theX;
        breakertemp += 1;
    }
    
    //  bot diagonal
    else if (three == theP && five == theP && !sept) {
        sept = true;
        seven = theX;
        breakertemp += 1;
    }
    else if (five == theP && seven == theP && !trois) {
        trois = true;
        three = theX;
        breakertemp += 1;
    }
    else if (seven == theP && three == theP && !cinq) {
        cinq = true;
        five = theX;
        breakertemp += 1;
    }
    
    //  left column
    else if (one == theP && four == theP && !sept) {
        sept = true;
        seven = theX;
        breakertemp += 1;
    }
    else if (four == theP && seven == theP && !un) {
        un = true;
        one = theX;
        breakertemp += 1;
    }
    else if (seven == theP && one == theP && !quatre) {
        quatre = true;
        four = theX;
        breakertemp += 1;
    }
    
    //  mid column
    else if (two == theP && five == theP && !huit) {
        huit = true;
        eight = theX;
        breakertemp += 1;
    }
    else if (five == theP && eight == theP && !deux) {
        deux = true;
        two = theX;
        breakertemp += 1;
    }
    else if (eight == theP && two == theP && !cinq) {
        cinq = true;
        five = theX;
        breakertemp += 1;
    }
    
    //  right column
    else if (three == theP && sixx == theP && !neuf) {
        neuf = true;
        nine = theX;
        breakertemp += 1;
    }
    else if (sixx == theP && nine == theP && !trois) {
        trois = true;
        three = theX;
        breakertemp += 1;
    }
    else if (nine == theP && three == theP && !six) {
        six = true;
        sixx = theX;
        breakertemp += 1;
    }
    
}






//                           COMP TURN
void compTurn(char theX) {
    // breakertemp is -1
    int ai_intel = -1;
    char theP;                      // user's piece
    cout << "My turn" << endl;
    while (breakertemp == -1) {
        if (theX == 'O') {
            theP = 'X';
        }
        else {
            theP = 'O';
        }
        
        compSmart(theX);            // comp will try to win
        if (breakertemp == -1) {
            compBlock(theX, theP);  // comp will try to block user
        }
        
        if (breakertemp == -1) {
            ai_intel = (time(0) % 9) + 1;        // number between 1-9
            if (ai_intel == 1) {
                if (!un) {              // if un == false
                    un = true;
                    one = theX;
                    breakertemp += 1;
                }
            }
            if (ai_intel == 2) {
                if(!deux) {
                    deux = true;
                    two = theX;
                    breakertemp += 2;
                }
            }
            if (ai_intel == 3) {
                if (!trois) {
                    trois = true;
                    three = theX;
                    breakertemp += 3;
                }
            }   
            if (ai_intel == 4) {
                if(!quatre) {
                    quatre = true;
                    four = theX;
                    breakertemp += 4;
                }
            }
            if (ai_intel == 5) {
                if (!cinq) {
                    cinq = true;
                    five = theX;
                    breakertemp += 5;
              }
            }
            if (ai_intel == 6) {
                if(!six) {
                    six = true;
                    sixx = theX;
                    breakertemp += 6;
                }
            }
            if (ai_intel == 7) {
                if (!sept) {
                    sept = true;
                    seven = theX;
                    breakertemp += 7;
                }
            }
            if (ai_intel == 8) {
                if(!huit) {
                    huit = true;
                    eight = theX;
                    breakertemp += 8;
                }
            }
            if (ai_intel == 9) {
                if (!neuf) {
                    neuf = true;
                    nine = theX;
                    breakertemp += 9;
                }
            }
            checkVictory();
        }
    }
    
    cout << currentBoard(one,two,three,four,five,sixx,seven,eight,nine);
    breakertemp = -1;
}




//                      USER GOES FIRST
void user_init() {
    int turns = 0;
    while (turns < 4) {
        
        userTurn('O');
        checkVictory();
        // cout << "Victory Condition: " << victoryCondition << endl;
        if (victoryCondition == 1) {
            cout << "\nYou Win\n\n";
            turns = 4;
        }
        
        if (victoryCondition == 0) {        // if user hasn't won yet
            compTurn('X');
            checkVictory();
            // cout << "Victory Condition: " << victoryCondition << endl;
            if (victoryCondition == 2) {
                cout << "\nI win\n\n";
                turns = 4;
            }
            cout << "-------------------------------------" << endl;
        }
            
        ++turns;
        if (turns == 4) {
            userTurn('O');
            checkVictory();
            if (victoryCondition == 1) {
                cout << "\nYou Win\n\n";
            }
            if (victoryCondition == 0) {
                cout << "\nStalemate\n\n";
            }
        }
    }
}

//                      COMP GOES FIRST
void comp_init() {
    int turns = 0;
    while (turns < 4) {
        compTurn('O');
        checkVictory();
        // cout << "Victory Condition: " << victoryCondition << endl;
        if (victoryCondition == 1) {
            cout << "\nI Win\n\n";
            turns = 4;
        }
    
        if (victoryCondition == 0) {        // if user hasn't won yet
            userTurn('X');
            checkVictory();
            // cout << "Victory Condition: " << victoryCondition << endl;
            if (victoryCondition == 2) {
                cout << "\nYou win\n\n";
                turns = 4;
            }
            cout << "-------------------------------------" << endl;
        }
        
        ++turns;
        if (turns == 4) {
            compTurn('O');
            checkVictory();
            if (victoryCondition == 1) {
                cout << "\nI Win\n\n";
            }
            if (victoryCondition == 0) {
                cout << "\nStalemate\n\n";
            }
        }
    }
}






//                          MAIN







int main() {
    
    // User picks Heads or Tails
    headsVsTails();
    
    // USER GOES FIRST
    if (firstTurn == 0) {
        user_init();
    }
    // COMP GOES FIRST
    if (firstTurn == 1) {
        comp_init();
    }
    
    cout << "-------------------------------------------------" << endl;
    cout << "End of code\n-Alex Nguyen\n\n";
    return -1;
}