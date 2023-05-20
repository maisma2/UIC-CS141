/**------------------------------------------
    Program 2: Great 13
    Name: Abeer Ismail
    Date: Feb 5th 2023
    Course: CS 141, Spring 2023.
    System: Linux x86_64 and G++
    Author: George Maratos and David Hayes
 ---------------------------------------------**/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <map>
#include <string>

/* Everything below this comment is starter code, and you are not
allowed to modify */

using namespace std;

// Function that displays the instructions to the user

void display_instructions()
{
    cout << "Class: CS 141" << endl
         << "Program 2: Great 13" << endl << endl
         << "Make a series of jumps until there is a single piece left" << endl
         << "anywhere on board. On each move you must jump an adjacent" << endl
         << "piece   into   an  empty  square,  jumping  horizontally," << endl
         << "vertically, or diagonally." << endl << endl
         << "Input of 'R' resets the board back to the beginning, and " << endl
         << "'X' exits the game." << endl;
}

// The internal representation of the board as an array. Do not modify directly.

char board[13]{};

/* These two functions are how you will get and set elements on the board. Only
use these two when changing, or reading the board. */

char get_element(char position)
{
    if ((position < 'A') || (position > 'M')) {
        cout << "Failed to get element at position " << position << endl
             << "Make sure the given position is an uppercase letter " << endl
             << "between A-M." << endl;
        exit(1);
    }
    return board[position - 'A'];
}

void set_element(char position, char value)
{
    if ((position < 'A') || (position > 'M')) {
        cout << "Failed to set element at postion " << position << endl
             << "Make sure the given position is an uppercase letter " << endl
             << "between A-M." << endl;
        exit(1);
    }
     board[position - 'A'] = value;
}

// print out the board with the legend on the right

void display_board()
{
    cout << endl;
    cout << setw(7) << "Board" << setw(12) << "Position" << endl;
    cout << setw(5) << board[0] << setw(11) << 'A' << endl
         << setw(3) << board[1] << ' ' << board[2] << ' ' << board[3]
         << setw(11) << "B C D" << endl
         << board[4] << ' ' << board[5] << ' ' << board[6] << ' '
         << board[7] << ' ' << board[8] << ' '
         << " E F G H I" << endl
         << setw(3) << board[9] << ' ' << board[10] << ' ' << board[11]
         << setw(11) << "J K L" << endl
         << setw(5) << board[12] << setw(11) << 'M' << endl;
    cout << endl;
}

/* This is the end of the starter code, and below is where you can
add your own code. Feel free to add helper functions or variables.
 forward declarations for the functions you will write later. This
is so the order of the function definitions, in this file,  does not
matter. */

void isValidMove(char from, char jump, char to);
void validPossibleMoves(char from, char jump, char to);
void initialize_board();
bool game_over();
bool checkValidPositions(string input);
string upperCase(string& input);

int main() {
    display_instructions();
    initialize_board();
    //This keeps running to keep running and every round checks for number of pegs remaining
    while (!game_over()){
        char from, jump, to;
        string tempinput;

        display_board();
        cout << "Enter positions from, jump, and to (e.g. EFG): ";

        cin >> tempinput;
        string input = upperCase(tempinput); //makes temp input to be uppercased when function returns

        if (input[0] == 'X' && input.length() == 1){
            //ends game
            cout << "Exiting." << endl;
            return 0;
        }
        if (input[0] == 'R' && input.length() == 1){
            //resets board and ends iteration of loop
            initialize_board();
            cout << "Restarting game." << endl;
            continue;
        }
        if (input.length() != 3) {
            //Checks for 3 letters
            cout << "*** Invalid sequence. Please retry." << endl;
            continue;
        }

        if(checkValidPositions(input)){
            //If it passes the check for characters being between A-M it then assigns them to variables
            //Then gets passed onto the function which will check for getting elements, legality, and setting the move
            //Most game logic happens within that function
            from = input[0];
            jump = input[1];
            to = input[2];

            isValidMove(from, jump, to);
        }
        else continue;
    }
    return 0;
}

void initialize_board(){ //Sets each element of board manually, loops for all the '#'
    for (int i = 0; i < 6; i++){
        set_element(65 + i, '#');
    }
    set_element('G', '.');
    for (int i = 0; i < 6; i++){
        set_element(72 + i, '#');
    }

}

bool game_over(){ //It counts the number of pegs remaining, the loop goes from letter A - M, and if/else for how many pegs left
    int counter = 0;
    for (int i = 0; i <13; i++){
        if (get_element(65 + i) == '#') counter++;
    }

    if (counter == 1) {
        cout << "Congrats you win!" << endl;
        return true;
    }
    else return false;

}

string upperCase(string& input){ // Simple uppercase loop
    string upperCase = "";
    for (char x:input){
        upperCase += toupper(x);
    }
    return upperCase;
}

void isValidMove(char from, char jump, char to){ //First checks for valid elements in each place, then checks for move legality in second function
    if (get_element(from) != '#'){
        cout << "*** Source needs a piece. Please retry." << endl;
        return;
    }
    else if (get_element(jump) != '#'){
        cout << "*** Must jump a piece. Please retry." << endl;
        return;
    }
    else if (get_element(to) != '.') {
        cout << "*** Destination must be empty. Please retry." << endl;
        return;
    }
    else validPossibleMoves(from, jump, to);

}
bool checkValidPositions(string input){ //loops through input and makes sure each character is between A-M
    for (char x:input){
        if (x < 'A' || x > 'M'){
            cout << "*** Given move has positions not on the board! Please retry." << endl;
            return false;
        }
    }
    return true;
}
void validPossibleMoves(char from, char jump, char to){
    //Hardcoded for each possible move combination from each starting block
    //If the move is illegal it goes to else and prints statement, else it sets the elements using the set_element method

    if (from == 'A'){
        if ((jump == 'B' && to == 'E') || (jump == 'C' && to == 'G') || (jump == 'D' && to == 'I')) {
            set_element(from, '.');
            set_element(jump, '.');
            set_element(to, '#');
        }
        else {
            cout << "*** Move is invalid." << endl;
        }
    }
    if (from == 'B'){
        if ((jump == 'C' && to == 'D') || (jump == 'F' && to == 'J') || (jump == 'G' && to == 'L')) {
            set_element(from, '.');
            set_element(jump, '.');
            set_element(to, '#');
        }
        else {
            cout << "*** Move is invalid." << endl;
        }
    }
    if (from == 'C'){
        if ((jump == 'G' && to == 'K')) {
            set_element(from, '.');
            set_element(jump, '.');
            set_element(to, '#');
        }
        else {
            cout << "*** Move is invalid." << endl;
        }
    }
    if (from == 'D'){
        if ((jump == 'G' && to == 'J') || (jump == 'H' && to == 'L') || (jump == 'C' && to == 'B')) {
            set_element(from, '.');
            set_element(jump, '.');
            set_element(to, '#');
        }
        else {
            cout << "*** Move is invalid." << endl;
        }
    }
    if (from == 'E'){
        if ((jump == 'B' && to == 'A') || (jump == 'F' && to == 'G') || (jump == 'J' && to == 'M')) {
            set_element(from, '.');
            set_element(jump, '.');
            set_element(to, '#');
        }
        else {
            cout << "*** Move is invalid." << endl;
        }
    }
    if (from == 'F'){
        if ((jump == 'G' && to == 'H')) {
            set_element(from, '.');
            set_element(jump, '.');
            set_element(to, '#');
        }
        else {
            cout << "*** Move is invalid." << endl;
        }
    }
    if (from == 'G'){
        if ((jump == 'F' && to == 'E') || (jump == 'H' && to == 'I') || (jump == 'C' && to == 'A') || (jump == 'K' && to == 'M')) {
            set_element(from, '.');
            set_element(jump, '.');
            set_element(to, '#');
        }
        else {
            cout << "*** Move is invalid." << endl;
        }
    }
    if (from == 'H'){
        if ((jump == 'G' && to == 'F')) {
            set_element(from, '.');
            set_element(jump, '.');
            set_element(to, '#');
        }
        else {
            cout << "*** Move is invalid." << endl;
        }
    }
    if (from == 'I'){
        if ((jump == 'D' && to == 'A') ||  (jump == 'H' && to == 'G') || (jump == 'L' && to == 'M')) {
            set_element(from, '.');
            set_element(jump, '.');
            set_element(to, '#');
        }
        else {
            cout << "*** Move is invalid." << endl;
        }
    }
    if (from == 'J'){
        if ((jump == 'K' && to == 'L') || (jump == 'G' && to == 'D') || (jump == 'F' && to == 'B')) {
            set_element(from, '.');
            set_element(jump, '.');
            set_element(to, '#');
        }
        else {
            cout << "*** Move is invalid." << endl;
        }
    }
    if (from == 'K'){
        if ((jump == 'G' && to == 'C')) {
            set_element(from, '.');
            set_element(jump, '.');
            set_element(to, '#');
        }
        else {
            cout << "*** Move is invalid." << endl;
        }
    }
    if (from == 'L'){
        if ((jump == 'K' && to == 'J') || (jump == 'G' && to == 'B') ||(jump == 'H' && to == 'D')) {
            set_element(from, '.');
            set_element(jump, '.');
            set_element(to, '#');
        }
        else {
            cout << "*** Move is invalid." << endl;
        }
    }
    if (from == 'M'){
        if ((jump == 'K' && to == 'G') || (jump == 'J' && to == 'E') || (jump == 'L' && to == 'I')){
            set_element(from, '.');
            set_element(jump, '.');
            set_element(to, '#');
        }
        else {
            cout << "*** Move is invalid." << endl;
        }
    }
}