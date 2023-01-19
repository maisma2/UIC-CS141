/*--------------------------------------------
 Program 2: Knight Escape
 The objective of this game is to get the white knight to the empty
 square in the upper right-hand corner of the board.

 The knight can only move in the way that it does during a traditional
 chess game. This means that a knight can only move in a valid L-shape
 (two squares in a horizontal direction, then one in a vertical direction OR
 two squares in a vertical direction, then one in a horizontal direction).

 Course: CS 141, Spring 2022
 System:
 Author:

---------------------------------------------*/

#include <iostream>       // for input and output

#include <cctype>        // for toupper()

using namespace std;

// Global variables for the pieces are allowed for this program,
// but will generally not be allowed in the future.
// You will likely want to declare global variables at least for the 25 board positions.
// ...
string p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12, p13, p14, p15, p16, p17, p18, p19, p20, p21, p22, p23, p24, p25;

// Characters of the pieces to be used on the board
// Note that these are global constants, so their values cannot be changed.
const string WhiteKnight = "\u2658"; // White knight character
const string BlackKnight = "\u265E"; // Black knight character
const string BlankPosition = " "; // Blank position character
int score = 500;
bool knightWin = false;
int startingPosition;
int secondPosition;
int moveNumber = 0;
int knightPosition;

//--------------------------------------------------------------------------------
// Display welcome message, introducing the user to the program and
// describing the instructions for the game
void displayWelcomeMessage() {
    cout << "Program 2: Knight Escape \n" <<
         "CS 141, Spring 2022, UIC \n" <<
         " \n" <<
         "The objective of this puzzle is to get the white knight " <<
         "up to the empty square in the top right corner of the board. " <<
         "Use standard knight moves from a traditional chess game, " <<
         "where a knight moves in an L-shape. \n" <<
         "This means that a knight can only move either " <<
         "1) two squares in a horizontal direction, then one in a vertical direction, OR " <<
         "2) two squares in a vertical direction, then one in a horizontal direction." <<
         " \n" <<
         "Your score decreases by 5 with each valid move, and by 10 with each invalid move. \n" <<
         "Try to complete the puzzle with the smallest number of valid moves!" <<
         endl;
} //end displayWelcomeMessage()

// ----------------------------------------------------------------------
// Display the current board, along with the corresponding positions
// This function makes use of global variables p1..p25, which represent
// each of the positions on the board
void displayBoard() {

    cout << "\n" <<
         "    Board   " << "      Position \n" <<
         " " << p1 << " " << p2 << " " << p3 << " " << p4 << " " << p5 << "     1  2  3  4  5 \n" <<
         " " << p6 << " " << p7 << " " << p8 << " " << p9 << " " << p10 << "     6  7  8  9 10 \n" <<
         " " << p11 << " " << p12 << " " << p13 << " " << p14 << " " << p15 << "    11 12 13 14 15 \n" <<
         " " << p16 << " " << p17 << " " << p18 << " " << p19 << " " << p20 << "    16 17 18 19 20 \n" <<
         " " << p21 << " " << p22 << " " << p23 << " " << p24 << " " << p25 << "    21 22 23 24 25 \n" <<
         endl;


} //end displayBoard()

void resetBoard() { //This resets the board to original values including scores, move number, etc.
    p1 = BlackKnight, p2 = BlackKnight, p3 = BlackKnight, p4 = BlackKnight, p5 = BlankPosition, p6 = BlackKnight, p7 = BlackKnight, p8 = BlackKnight, p9 = BlackKnight, p10 = BlackKnight, p11 = BlackKnight, p12 = BlackKnight, p13 = BlackKnight, p14 = BlackKnight, p15 = BlackKnight, p16 = BlackKnight, p17 = BlackKnight, p18 = BlackKnight, p19 = BlackKnight, p20 = BlackKnight, p22 = BlackKnight, p23 = BlackKnight, p24 = BlackKnight, p25 = BlackKnight;
    p21 = WhiteKnight;
    moveNumber = 1;
    score = 500;
    knightPosition = 21;
    knightWin = false;

} // Resets the board

int KnightMovement(int first, int second) { //This function has all valid movements from each starting point, if the movement isn't valid it goes to the else statement
    if (first == 1) {
        if (second == 8 || second == 12) {
            score -= 5;
            if (second == 8) {
                string temp = p1;
                p1 = p8;
                p8 = temp;
                knightPosition = 8;
            }
            if (second == 12) {
                string temp = p1;
                p1 = p12;
                p12 = temp;
                knightPosition = 12;
            }
            p1 = BlankPosition;
            moveNumber++;displayBoard();
            cout << endl << "Current score: " << score << endl;
        } else {
            score -= 10;
            cout << "Invalid move. Knights can only move in an L-shape. Try again." << endl;
            cout << "Current score: " << score << endl;

        }
    }
    if (first == 2) {
        if (second == 11 || second == 13 || second == 9) {
            score -= 5;
            if (second == 11) {
                string temp = p2;
                p2 = p11;
                p11 = temp;
                knightPosition = 11;
            }
            if (second == 13) {
                string temp = p2;
                p2 = p13;
                p13 = temp;
                knightPosition = 13;
            }
            if (second == 9) {
                string temp = p2;
                p2 = p9;
                p9 = temp;
                knightPosition = 9;
            }
            p2 = BlankPosition;
            moveNumber++;displayBoard();
            cout << endl << "Current score: " << score << endl;
        } else {
            score -= 10;
            cout << "Invalid move. Knights can only move in an L-shape. Try again." << endl;
            cout << "Current score: " << score << endl;

        }
    }
    if (first == 3) {
        if (second == 6 || second == 12 || second == 10 || second == 14) {
            score -= 5;
            if (second == 6) {
                string temp = p3;
                p3 = p6;
                p6 = temp;
                knightPosition = 6;
            }
            if (second == 12) {
                string temp = p3;
                p3 = p12;
                p12 = temp;
                knightPosition = 12;
            }
            if (second == 10) {
                string temp = p3;
                p3 = p10;
                p10 = temp;
                knightPosition = 10;
            }
            if (second == 14) {
                string temp = p3;
                p3 = p14;
                p14 = temp;
                knightPosition = 14;
            }
            p3 = BlankPosition;
            moveNumber++;displayBoard();
            cout << endl << "Current score: " << score << endl;
        } else {
            score -= 10;
            cout << "Invalid move. Knights can only move in an L-shape. Try again." << endl;
            cout << "Current score: " << score << endl;

        }
    }
    if (first == 4) {
        if (second == 7 || second == 13 || second == 15) {
            score -= 5;
            if (second == 7) {
                string temp = p4;
                p4 = p7;
                p7 = temp;
                knightPosition = 7;
            }
            if (second == 13) {
                string temp = p4;
                p4 = p13;
                p13 = temp;
                knightPosition = 13;
            }
            if (second == 15) {
                string temp = p4;
                p4 = p15;
                p15 = temp;
                knightPosition = 15;
            }
            p4 = BlankPosition;
            moveNumber++;displayBoard();
            cout << endl << "Current score: " << score << endl;
        } else {
            score -= 10;
            cout << "Invalid move. Knights can only move in an L-shape. Try again." << endl;
            cout << "Current score: " << score << endl;

        }
    }
    if (first == 5) {
        if (second == 8 || second == 14) {
            score -= 5;
            if (second == 8) {
                string temp = p5;
                p5 = p8;
                p8 = temp;
                knightPosition = 8;
            }
            if (second == 14) {
                string temp = p5;
                p5 = p14;
                p14 = temp;
                knightPosition = 14;
            }
            p5 = BlankPosition;
            moveNumber++;displayBoard();
            cout << endl << "Current score: " << score << endl;
        } else {
            score -= 10;
            cout << "Invalid move. Knights can only move in an L-shape. Try again." << endl;
            cout << "Current score: " << score << endl;

        }
    }
    if (first == 6) {

        if (second == 3 || second == 13 || second == 17) {
            score -= 5;
            if (second == 3) {
                string temp = p6;
                p6 = p3;
                p3 = temp;
                knightPosition = 3;
            }
            if (second == 13) {
                string temp = p6;
                p6 = p13;
                p13 = temp;
                knightPosition = 13;
            }
            if (second == 17) {
                string temp = p6;
                p6 = p17;
                p17 = temp;
                knightPosition = 17;
            }
            p6 = BlankPosition;
            moveNumber++;displayBoard();
            cout << endl << "Current score: " << score << endl;
        } else {
            score -= 10;
            cout << "Invalid move. Knights can only move in an L-shape. Try again." << endl;
            cout << "Current score: " << score << endl;

        }
    }
    if (first == 7) {

        if (second == 4 || second == 14 || second == 16 || second == 18) {
            score -= 5;
            if (second == 4) {
                string temp = p7;
                p7 = p4;
                p4 = temp;
                knightPosition = 4;
            }
            if (second == 14) {
                string temp = p7;
                p7 = p14;
                p14 = temp;
                knightPosition = 14;
            }
            if (second == 16) {
                string temp = p7;
                p7 = p16;
                p16 = temp;
                knightPosition = 16;
            }
            if (second == 18) {
                string temp = p7;
                p7 = p18;
                p18 = temp;
                knightPosition = 18;
            }
            p7 = BlankPosition;
            moveNumber++;displayBoard();
            cout << endl << "Current score: " << score << endl;
        } else {
            score -= 10;
            cout << "Invalid move. Knights can only move in an L-shape. Try again." << endl;
            cout << "Current score: " << score << endl;

        }
    }
    if (first == 8) {

        if (second == 1 || second == 5 || second == 11 || second == 15 || second == 17 || second == 19) {
            score -= 5;
            if (second == 1) {
                string temp = p8;
                p8 = p1;
                p1 = temp;
                knightPosition = 1;
            }
            if (second == 5) {
                string temp = p8;
                p8 = p5;
                p5 = temp;
                /*if (p5 == WhiteKnight) {
                    displayBoard();
                    cout << endl << "Congratulations, you did it!\n"
                                    "Thank you for playing!";
                    return 0;
                }*/
                knightPosition = 5;

            }
            if (second == 11) {
                string temp = p8;
                p8 = p11;
                p11 = temp;
                knightPosition = 11;
            }
            if (second == 15) {
                string temp = p8;
                p8 = p15;
                p15 = temp;
                knightPosition = 15;
            }
            if (second == 17) {
                string temp = p8;
                p8 = p17;
                p17 = temp;
                knightPosition = 17;
            }
            if (second == 19) {
                string temp = p8;
                p8 = p19;
                p19 = temp;
                knightPosition = 19;
            }
            p8 = BlankPosition;
            moveNumber++;displayBoard();
            cout << endl << "Current score: " << score << endl;
        } else {
            score -= 10;
            cout << "Invalid move. Knights can only move in an L-shape. Try again." << endl;
            cout << "Current score: " << score << endl;

        }
    }
    if (first == 9) {

        if (second == 2 || second == 12 || second == 18 || second == 20) {
            score -= 5;
            if (second == 2) {
                string temp = p9;
                p9 = p2;
                p2 = temp;
                knightPosition = 2;
            }
            if (second == 12) {
                string temp = p9;
                p9 = p12;
                p12 = temp;
                knightPosition = 12;
            }
            if (second == 18) {
                string temp = p9;
                p9 = p18;
                p18 = temp;
                knightPosition = 18;
            }
            if (second == 20) {
                string temp = p9;
                p9 = p20;
                p20 = temp;
                knightPosition = 20;
            }
            p9 = BlankPosition;
            moveNumber++;displayBoard();
            cout << endl << "Current score: " << score << endl;
        } else {
            score -= 10;
            cout << "Invalid move. Knights can only move in an L-shape. Try again." << endl;
            cout << "Current score: " << score << endl;

        }
    }
    if (first == 10) {

        if (second == 3 || second == 13 || second == 19) {
            score -= 5;
            if (second == 3) {
                string temp = p10;
                p10 = p3;
                p3 = temp;
                knightPosition = 3;
            }
            if (second == 13) {
                string temp = p10;
                p10 = p13;
                p13 = temp;
                knightPosition = 13;
            }
            if (second == 19) {
                string temp = p10;
                p10 = p19;
                p19 = temp;
                knightPosition = 19;
            }
            p10 = BlankPosition;
            moveNumber++;displayBoard();
            cout << endl << "Current score: " << score << endl;
        } else {
            score -= 10;
            cout << "Invalid move. Knights can only move in an L-shape. Try again." << endl;
            cout << "Current score: " << score << endl;

        }
    }
    if (first == 11) {

        if (second == 2 || second == 8 || second == 18 || second == 20) {
            score -= 5;
            if (second == 2) {
                string temp = p11;
                p11 = p2;
                p2 = temp;
                knightPosition = 2;
            }
            if (second == 8) {
                string temp = p11;
                p11 = p8;
                p8 = temp;
                knightPosition = 8;
            }
            if (second == 18) {
                string temp = p11;
                p11 = p18;
                p18 = temp;
                knightPosition = 18;
            }
            if (second == 20) {
                string temp = p11;
                p11 = p20;
                p20 = temp;
                knightPosition = 20;
            }
            p11 = BlankPosition;
            moveNumber++;displayBoard();
            cout << endl << "Current score: " << score << endl;
        } else {
            score -= 10;
            cout << "Invalid move. Knights can only move in an L-shape. Try again." << endl;
            cout << "Current score: " << score << endl;

        }
    }
    if (first == 12) {

        if (second == 1 || second == 3 || second == 9 || second == 19 || second == 21 || second == 23) {
            score -= 5;
            if (second == 1) {
                string temp = p12;
                p12 = p1;
                p1 = temp;
                knightPosition = 1;
            }
            if (second == 3) {
                string temp = p12;
                p12 = p3;
                p3 = temp;
                knightPosition = 3;
            }
            if (second == 9) {
                string temp = p12;
                p12 = p9;
                p9 = temp;
                knightPosition = 9;
            }
            if (second == 19) {
                string temp = p12;
                p12 = p19;
                p19 = temp;
                knightPosition = 19;
            }
            if (second == 21) {
                string temp = p12;
                p12 = p21;
                p21 = temp;
                knightPosition = 21;
            }
            if (second == 23) {
                string temp = p12;
                p12 = p23;
                p23 = temp;
                knightPosition = 23;
            }
            p12 = BlankPosition;
            moveNumber++;displayBoard();
            cout << endl << "Current score: " << score << endl;
        } else {
            score -= 10;
            cout << "Invalid move. Knights can only move in an L-shape. Try again." << endl;
            cout << "Current score: " << score << endl;

        }
    }
    if (first == 13) {

        if (second == 2 || second == 4 || second == 6 || second == 10 || second == 16 || second == 20 || second == 22 || second == 24) {
            score -= 5;
            if (second == 2) {
                string temp = p13;
                p13 = p2;
                p2 = temp;
                knightPosition = 2;
            }
            if (second == 4) {
                string temp = p13;
                p13 = p4;
                p4 = temp;
                knightPosition = 4;
            }
            if (second == 6) {
                string temp = p13;
                p13 = p6;
                p6 = temp;
                knightPosition = 6;
            }
            if (second == 10) {
                string temp = p13;
                p13 = p10;
                p10 = temp;
                knightPosition = 10;
            }
            if (second == 16) {
                string temp = p13;
                p13 = p16;
                p16 = temp;
                knightPosition = 16;
            }
            if (second == 20) {
                string temp = p13;
                p13 = p20;
                p20 = temp;
                knightPosition = 20;
            }
            if (second == 22) {
                string temp = p13;
                p13 = p22;
                p22 = temp;
                knightPosition = 22;
            }
            if (second == 24) {
                string temp = p13;
                p13 = p24;
                p24 = temp;
                knightPosition = 24;
            }
            p13 = BlankPosition;
            moveNumber++;displayBoard();
            cout << endl << "Current score: " << score << endl;
        } else {
            score -= 10;
            cout << "Invalid move. Knights can only move in an L-shape. Try again." << endl;
            cout << "Current score: " << score << endl;

        }
    }
    if (first == 14) {

        if (second == 3 || second == 5 || second == 7 || second == 17 || second == 23 || second == 25) {
            score -= 5;
            if (second == 3) {
                string temp = p14;
                p14 = p3;
                p3 = temp;
                knightPosition = 3;
            }
            if (second == 5) {
                string temp = p14;
                p14 = p5;
                p5 = temp;
                /*if (p5 == WhiteKnight){
                    displayBoard();
                    cout << endl << "Congratulations, you did it!\n"
                                    "Thank you for playing!";
                    return 0;
                }*/
                knightPosition = 5;

            }
            if (second == 7) {
                string temp = p14;
                p14 = p7;
                p7 = temp;
                knightPosition = 7;
            }
            if (second == 17) {
                string temp = p14;
                p14 = p17;
                p17 = temp;
                knightPosition = 17;
            }
            if (second == 23) {
                string temp = p14;
                p14 = p23;
                p23 = temp;
                knightPosition = 23;
            }
            if (second == 25) {
                string temp = p14;
                p14 = p25;
                p25 = temp;
                knightPosition = 25;
            }
            p14 = BlankPosition;
            moveNumber++;displayBoard();
            if (p5 != WhiteKnight) cout << endl << "Current score: " << score << endl;
        } else {
            score -= 10;
            cout << "Invalid move. Knights can only move in an L-shape. Try again." << endl;
            cout << "Current score: " << score << endl;

        }
    }
    if (first == 15) {

        if (second == 4 || second == 8 || second == 18 || second == 24) {
            score -= 5;
            if (second == 4) {
                string temp = p15;
                p15 = p4;
                p4 = temp;
                knightPosition = 4;
            }
            if (second == 8) {
                string temp = p15;
                p15 = p8;
                p8 = temp;
                knightPosition = 8;
            }
            if (second == 18) {
                string temp = p15;
                p15 = p18;
                p18 = temp;
                knightPosition = 18;
            }
            if (second == 24) {
                string temp = p15;
                p15 = p24;
                p24 = temp;
                knightPosition = 24;
            }
            p15 = BlankPosition;
            moveNumber++;displayBoard();
            cout << endl << "Current score: " << score << endl;
        } else {
            score -= 10;
            cout << "Invalid move. Knights can only move in an L-shape. Try again." << endl;
            cout << "Current score: " << score << endl;

        }
    }
    if (first == 16) {

        if (second == 7 || second == 13 || second == 23) {
            score -= 5;
            if (second == 7) {
                string temp = p16;
                p16 = p7;
                p7 = temp;
                knightPosition = 7;
            }
            if (second == 13) {
                string temp = p16;
                p16 = p13;
                p13 = temp;
                knightPosition = 13;
            }
            if (second == 23) {
                string temp = p16;
                p16 = p23;
                p23 = temp;
                knightPosition = 23;
            }
            p16 = BlankPosition;
            moveNumber++;displayBoard();
            cout << endl << "Current score: " << score << endl;
        } else {
            score -= 10;
            cout << "Invalid move. Knights can only move in an L-shape. Try again." << endl;
            cout << "Current score: " << score << endl;

        }
    }
    if (first == 17) {

        if (second == 6 || second == 8 || second == 14 || second == 24) {
            score -= 5;
            if (second == 6) {
                string temp = p17;
                p17 = p6;
                p6 = temp;
                knightPosition = 6;
            }
            if (second == 8) {
                string temp = p17;
                p17 = p8;
                p8 = temp;
                knightPosition = 8;
            }
            if (second == 14) {
                string temp = p17;
                p17 = p14;
                p14 = temp;
                knightPosition = 14;
            }
            if (second == 24) {
                string temp = p17;
                p17 = p24;
                p24 = temp;
                knightPosition = 24;
            }
            p17 = BlankPosition;
            moveNumber++;displayBoard();
            cout << endl << "Current score: " << score << endl;
        } else {
            score -= 10;
            cout << "Invalid move. Knights can only move in an L-shape. Try again." << endl;
            cout << "Current score: " << score << endl;

        }
    }
    if (first == 18) {

        if (second == 7 || second == 9 || second == 11 || second == 15 || second == 21 || second == 25) {
            score -= 5;
            if (second == 7) {
                string temp = p18;
                p18 = p7;
                p7 = temp;
                knightPosition = 7;
            }
            if (second == 9) {
                string temp = p18;
                p18 = p9;
                p9 = temp;
                knightPosition = 9;
            }
            if (second == 11) {
                string temp = p18;
                p18 = p11;
                p11 = temp;
                knightPosition = 11;
            }
            if (second == 15) {
                string temp = p18;
                p18 = p15;
                p15 = temp;
                knightPosition = 15;
            }
            if (second == 21) {
                string temp = p18;
                p18 = p21;
                p21 = temp;
                knightPosition = 21;
            }
            if (second == 25) {
                string temp = p18;
                p18 = p25;
                p25 = temp;
                knightPosition = 25;
            }
            p18 = BlankPosition;
            moveNumber++;displayBoard();
            cout << endl << "Current score: " << score << endl;
        } else {
            score -= 10;
            cout << "Invalid move. Knights can only move in an L-shape. Try again." << endl;
            cout << "Current score: " << score << endl;

        }
    }
    if (first == 19) {

        if (second == 8 || second == 10 || second == 12 || second == 22) {
            score -= 5;
            if (second == 8) {
                string temp = p19;
                p19 = p8;
                p8 = temp;
                knightPosition = 8;
            }
            if (second == 10) {
                string temp = p19;
                p19 = p10;
                p10 = temp;
                knightPosition = 10;
            }
            if (second == 12) {
                string temp = p19;
                p19 = p12;
                p12 = temp;
                knightPosition = 12;
            }
            if (second == 22) {
                string temp = p19;
                p19 = p22;
                p22 = temp;
                knightPosition = 22;
            }
            p19 = BlankPosition;
            moveNumber++;
            displayBoard();
            cout << endl << "Current score: " << score << endl;
        } else {
            score -= 10;
            cout << "Invalid move. Knights can only move in an L-shape. Try again." << endl;
            cout << "Current score: " << score << endl;

        }
    }
    if (first == 20) {

        if (second == 9 || second == 13 || second == 23) {
            score -= 5;
            if (second == 9) {
                string temp = p20;
                p20 = p9;
                p9 =  temp;
                knightPosition = 9;
            }
            if (second == 13) {
                string temp = p20;
                p20 = p13;
                p13 = temp;
                knightPosition = 13;
            }
            if (second == 23) {
                string temp = p20;
                p20 = p23;
                p23 =  temp;
                knightPosition = 23;
            }
            p20 = BlankPosition;
            moveNumber++;
            displayBoard();
            cout << endl << "Current score: " << score << endl;
        } else {
            score -= 10;
            cout << "Invalid move. Knights can only move in an L-shape. Try again." << endl;
            cout << "Current score: " << score << endl;

        }
    }
    if (first == 21) {

        if (second == 12 || second == 18) {
            score -= 5;
            if (second == 12) {
                string temp = p21;
                p21 = p12;
                p12 =  temp;
                knightPosition = 12;
            }
            if (second == 18) {
                string temp = p21;
                p21 = p18;
                p18 =  temp;
                knightPosition = 18;
            }
            p21 = BlankPosition;
            moveNumber++;
            displayBoard();
            cout << endl << "Current score: " << score << endl;
        } else {
            score -= 10;
            cout << "Invalid move. Knights can only move in an L-shape. Try again." << endl;
            cout << "Current score: " << score << endl;

        }
    }
    if (first == 22) {

        if (second == 11 || second == 13 || second == 19) {
            score -= 5;
            if (second == 19) {
                string temp = p22;
                p22 = p19;
                p19 =  temp;
                knightPosition = 19;
            }
            if (second == 13) {
                string temp = p22;
                p22 = p13;
                p13 =  temp;
                knightPosition = 13;
            }
            if (second == 11) {
                string temp = p22;
                p22 = p11;
                p11 =  temp;
                knightPosition = 11;
            }
            p22 = BlankPosition;
            moveNumber++;
            displayBoard();
            cout << endl << "Current score: " << score << endl;
        } else {
            score -= 10;
            cout << "Invalid move. Knights can only move in an L-shape. Try again." << endl;
            cout << "Current score: " << score << endl;

        }
    }
    if (first == 23) {
        if (second == 12 || second == 14 || second == 20) {
            score -= 5;
            if (second == 12) {
                string temp = p23;
                p23 = p12;
                p12 =  temp;
                knightPosition = 12;
            }
            if (second == 14) {
                string temp = p23;
                p23 = p14;
                p14 =  temp;
                knightPosition = 14;
            }
            if (second == 20) {
                string temp = p23;
                p23 = p20;
                p20 =  temp;
                knightPosition = 20;
            }
            p23 = BlankPosition;
            moveNumber++;
            displayBoard();
            cout << endl << "Current score: " << score << endl;
        } else {
            score -= 10;
            cout << "Invalid move. Knights can only move in an L-shape. Try again." << endl;
            cout << "Current score: " << score << endl;

        }
    }
    if (first == 24) {

        if (second == 13 || second == 15 || second == 17) {
            score -= 5;
            if (second == 13) {
                string temp = p24;
                p24 = p13;
                p13 =  temp;
                knightPosition = 13;
            }
            if (second == 15) {
                string temp = p24;
                p24 = p15;
                p15 =  temp;
                knightPosition = 15;
            }
            if (second == 17) {
                string temp = p24;
                p24 = p17;
                p17 =  temp;
                knightPosition = 17;
            }
            p24 = BlankPosition;
            moveNumber++;
            displayBoard();
            cout << endl << "Current score: " << score << endl;
        } else {
            score -= 10;
            cout << "Invalid move. Knights can only move in an L-shape. Try again." << endl;
            cout << "Current score: " << score << endl;

        }
    }
    if (first == 25) {
        if (second == 14 || second == 18) {
            score -= 5;
            if (second == 14) {
                string temp = p25;
                p25 = p14;
                p14 =  temp;
                knightPosition = 14;
            }
            if (second == 18) {
                string temp = p23;
                p23 = p18;
                p18 =  temp;
                knightPosition = 18;
            }
            p25 = BlankPosition;
            moveNumber++;
            displayBoard();
            cout << endl << "Current score: " << score << endl;
        } else {
            score -= 10;
            cout << "Invalid move. Knights can only move in an L-shape. Try again." << endl;
            cout << "Current score: " << score << endl;


        }

    }



}
bool checkForKnight(int pos) { //Very manual way of checking if each individual position has a knight either white or black on it #If theres time combine with the blank function as theres only 3 values
    switch (pos) {
        case 1:
            if (p1 == BlackKnight || p1 == WhiteKnight) {
                return true;
            } else return false;

        case 2:
            if (p2 == BlackKnight || p2 == WhiteKnight) {
                return true;
            } else return false;

        case 3:
            if (p3 == BlackKnight || p3 == WhiteKnight) {
                return true;
            } else return false;

        case 4:
            if (p4 == BlackKnight || p4 == WhiteKnight) {
                return true;
            } else return false;

        case 5:
            if (p5 == BlackKnight || p5 == WhiteKnight) {
                return true;
            } else return false;

        case 6:
            if (p6 == BlackKnight || p6 == WhiteKnight) {
                return true;
            } else return false;

        case 7:
            if (p7 == BlackKnight || p7 == WhiteKnight) {
                return true;
            } else return false;

        case 8:
            if (p8 == BlackKnight || p8 == WhiteKnight) {
                return true;
            } else return false;

        case 9:
            if (p9 == BlackKnight || p9 == WhiteKnight) {
                return true;
            } else return false;

        case 10:
            if (p10 == BlackKnight || p10 == WhiteKnight) {
                return true;
            } else return false;

        case 11:
            if (p11 == BlackKnight || p11 == WhiteKnight) {
                return true;
            } else return false;

        case 12:
            if (p12 == BlackKnight || p12 == WhiteKnight) {
                return true;
            } else return false;

        case 13:
            if (p13 == BlackKnight || p13 == WhiteKnight) {
                return true;
            } else return false;

        case 14:
            if (p14 == BlackKnight || p14 == WhiteKnight) {
                return true;
            } else return false;

        case 15:
            if (p15 == BlackKnight || p15 == WhiteKnight) {
                return true;
            } else return false;

        case 16:
            if (p16 == BlackKnight || p16 == WhiteKnight) {
                return true;
            } else return false;

        case 17:
            if (p17 == BlackKnight || p17 == WhiteKnight) {
                return true;
            } else return false;

        case 18:
            if (p18 == BlackKnight || p18 == WhiteKnight) {
                return true;
            } else return false;

        case 19:
            if (p19 == BlackKnight || p19 == WhiteKnight) {
                return true;
            } else return false;

        case 20:
            if (p20 == BlackKnight || p20 == WhiteKnight) {
                return true;
            } else return false;

        case 21:
            if (p21 == BlackKnight || p21 == WhiteKnight) {
                return true;
            } else return false;

        case 22:
            if (p22 == BlackKnight || p22 == WhiteKnight) {
                return true;
            } else return false;

        case 23:
            if (p23 == BlackKnight || p23 == WhiteKnight) {
                return true;
            } else return false;

        case 24:
            if (p24 == BlackKnight || p24 == WhiteKnight) {
                return true;
            } else return false;

        case 25:
            if (p25 == BlackKnight || p25 == WhiteKnight) {
                return true;
            } else return false;

    }
    return false;
}

bool checkForBlank(int pos) { //Very manual way to check if each position is a blank holder or not
    switch (pos) {
        case 1:
            if (p1 == BlankPosition) {
                return true;
            } else return false;

        case 2:
            if (p2 == BlankPosition) {
                return true;
            } else return false;

        case 3:
            if (p3 == BlankPosition) {
                return true;
            } else return false;

        case 4:
            if (p4 == BlankPosition) {
                return true;
            } else return false;

        case 5:
            if (p5 == BlankPosition) {
                return true;
            } else return false;

        case 6:
            if (p6 == BlankPosition) {
                return true;
            } else return false;

        case 7:
            if (p7 == BlankPosition) {
                return true;
            } else return false;

        case 8:
            if (p8 == BlankPosition) {
                return true;
            } else return false;

        case 9:
            if (p9 == BlankPosition) {
                return true;
            } else return false;

        case 10:
            if (p10 == BlankPosition) {
                return true;
            } else return false;

        case 11:
            if (p11 == BlankPosition) {
                return true;
            } else return false;

        case 12:
            if (p12 == BlankPosition) {
                return true;
            } else return false;

        case 13:
            if (p13 == BlankPosition) {
                return true;
            } else return false;

        case 14:
            if (p14 == BlankPosition) {
                return true;
            } else return false;

        case 15:
            if (p15 == BlankPosition) {
                return true;
            } else return false;

        case 16:
            if (p16 == BlankPosition) {
                return true;
            } else return false;

        case 17:
            if (p17 == BlankPosition) {
                return true;
            } else return false;

        case 18:
            if (p18 == BlankPosition) {
                return true;
            } else return false;

        case 19:
            if (p19 == BlankPosition) {
                return true;
            } else return false;

        case 20:
            if (p20 == BlankPosition) {
                return true;
            } else return false;

        case 21:
            if (p21 == BlankPosition) {
                return true;
            } else return false;

        case 22:
            if (p22 == BlankPosition) {
                return true;
            } else return false;

        case 23:
            if (p23 == BlankPosition) {
                return true;
            } else return false;

        case 24:
            if (p24 == BlankPosition) {
                return true;
            } else return false;

        case 25:
            if (p25 == BlankPosition) {
                return true;
            } else return false;

    }

}

bool checkWin(){ //Check if the White Knight sits on p5
    if (p5 == WhiteKnight) {
        cout << "Congratulations, you did it! \n"
                "Thank you for playing!";
        return true;
    }
    else return false;
}
// ----------------------------------------------------------------------
// Main() function of the program, containing the loop that controls
// game play
int main() {

    resetBoard();
    displayWelcomeMessage();
    displayBoard();
    cout << endl << "Current score: " << score << endl;


    // Loop that controls game play
    do {
        char menuOption;
        cout << endl;
        cout << moveNumber << ". " <<
             "Enter one of the following: \n" <<
             "  - M to move a knight from one position to another, \n" <<
             "  - R to reset the board back to the beginning, or \n" <<
             "  - X to exit the game. \n" <<
             "Your choice -> ";
        cin >> menuOption;
        menuOption = toupper(menuOption); // convert user input to uppercase
        switch (menuOption) {

            // If the user entered 'X' to exit,
            // break out of this loop that controls game play
            // ...
            case 'X': // Exit "X"
                cout << "Exiting..." << endl << "Thank you for playing!";
                return 0;

            case 'R': // Reset "R"
                cout << "   *** Restarting" << endl;
                resetBoard();
                displayBoard();
                cout << endl << "Current score: " << score << endl;
                break;
            case 'M': // Move "M"
                cout
                        <<
                        "Enter the positions from and to, separated by a space (e.g. 14 5 to move the knight in position 14 to position 5): "
                        <<
                        endl;
                cin >> startingPosition >> secondPosition;
                cout << "You have chosen to move a knight from position " << startingPosition << " to position "
                     << secondPosition << "." << endl;
                // Preliminary checks
                // Check that FROM position is valid, i.e. within 1-25
                if (startingPosition <= 0 || startingPosition > 25) {
                    cout << "The source position should be a valid position on the board (1-25). Try again." << endl;
                    score -= 10;
                    cout << endl << "Current score: " << score << endl;
                }
                    // Check that TO position is valid, i.e. within 1-25
                else if (secondPosition <= 0 || secondPosition > 25) {
                    cout << "The destination position should be a valid position on the board (1-25). Try again."
                         << endl;
                    score -= 10;
                    cout << endl << "Current score: " << score << endl;
                }

                    // Check that the source position has a knight
                else if (!checkForKnight(startingPosition)) {
                    cout << "The source position should have a knight. Try again." << endl;
                    score -= 10;
                    cout << endl << "Current score: " << score << endl;
                }
                    // Check that the destination position is empty
                else if (!checkForBlank(secondPosition)) {
                    cout << "The destination position should be empty. Try again." << endl;
                    score -= 10;
                    cout << endl << "Current score: " << score << endl;
                }

                    // Movement after Checks
                    // Valid movements done in function
                else {
                    KnightMovement(startingPosition, secondPosition);

                }

        }
        // Make the move and update the board
        //    if (p5 == WhiteKnight) {
        //       cout << "Congratulations, you did it! \n"
        //              "Thank you for playing!";
        //     return 0;
        //}
        if (score <= 0){
            cout << "You have run out of moves. Try to do better next time!\n"
                    "Thank you for playing!";
            return 0;
        }
    }
    while (!checkWin() || score <= 0);

    // end loop for game play

    return 0;
}