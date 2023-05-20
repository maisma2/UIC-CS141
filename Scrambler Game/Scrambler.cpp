//
// Created by maism on 4/10/2023.
// Scrambler Class which has definitions for each function
//
//

#include "Scrambler.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>


using namespace std;


void Scrambler::createDictionary(string &filepath){ //Simple fstream to load the word vector
    ifstream file(filePath);
    string word;
    while (file >> word) {
        Dictionary.push_back(word);
    }
    file.close();
}
void Scrambler::fillBoard() { //fills it with a bunch of spaces, used this in the start to see the board for formatting
    board.resize(board_size);
    for (int i = 0; i < board_size; i++) {
        board[i].resize(board_size);
        for (int j = 0; j < board_size; j++) {
            board[i][j] = ' ';
        }
    }
}

void Scrambler::try_move ( const string & cmd )
{
    string lowerCmd = cmd;
    for (int i = 0; i < lowerCmd.length(); i++){ // Convert to lowercase
        lowerCmd[i] = tolower(lowerCmd[i]);
    }

    // Validate the input command
    if (lowerCmd.size() == 3 && (lowerCmd[0] == 'c' || lowerCmd[0] == 'r') && isdigit(lowerCmd[1]) &&
        (lowerCmd[2] == 'u' || lowerCmd[2] == 'd' || lowerCmd[2] == 'l' || lowerCmd[2] == 'r')) { //compounded checks to make sure the right input was added

        int index = lowerCmd[1] - '1'; // Convert the char to int
        index %= board_size; //to loop the board
        if (index >= 0 && index < board_size) {
            if (lowerCmd[0] == 'c') { //assumes column
                shiftColumn(board, index, lowerCmd[2]);
            } else { // assumes row
                shiftRow(board, index, lowerCmd[2]);
            }
        }

    } else if (lowerCmd.size() == 1 && lowerCmd[0] == 'r') {
        board = jumbled_board; // Restart the game from the initial jumbled board state
    }
}

void Scrambler::jumble_board(vector<vector<char>>& board) { //uses the algo provided in the assignment
    string move;
    int x = rand() % 8; // Randomly pick an integer x between [0, 7]
    int nmoves = x + 3;

    for (int i = 1; i <= nmoves; ++i) {
        int idx = rand() % board.size(); // Pick a random index

        if (i % 2 == 0) { // If i is even
            char dir = rand() % 2 ? 'u' : 'd'; // Picks u or d with 50% chances
            move = "Move " + to_string(i) + " (c," + to_string(idx + 1) + "," + dir + ")";  //Fills in the move vector so we can unscramble later
            shiftColumn(board, idx, dir); // Shift column with index idx and direction dir
        } else {
            char dir = rand() % 2 ? 'r' : 'l'; // Pick r or l with 50% chances
            move = "Move " + to_string(i) + " (r," + to_string(idx + 1) + "," + dir + ")";
            shiftRow(board, idx, dir); // Shift row with index idx and direction dir
        }
        jumble_boardMoves.push_back(move); //adds the move to the vector
    }
    jumbled_board = board; //saves the jumbled board for restarts

}

void Scrambler::shiftRow(vector<vector<char>>& board, int rowIndex, char dir) { //shifts the row in the direction specified, and makes sure no chars are lost
    int n = board.size();
    if (dir == 'r') {
        char temp = board[rowIndex][n - 1]; //saves the last char
        for (int i = n - 1; i > 0; --i) {
            board[rowIndex][i] = board[rowIndex][i - 1]; //shifts the row to the right by one until end of row
        }
        board[rowIndex][0] = temp; //puts the last char in the first spot to not lose any info
    } else if (dir == 'l') {
        char temp = board[rowIndex][0];
        for (int i = 0; i < n - 1; ++i) {
            board[rowIndex][i] = board[rowIndex][i + 1];
        }
        board[rowIndex][n - 1] = temp;
    }
}

void Scrambler::shiftColumn(vector<vector<char>>& board, int colIndex, char dir) { //shifts column the same way as shift row
    int n = board.size();
    if (dir == 'u') {
        char temp = board[0][colIndex];
        for (int i = 0; i < n - 1; ++i) {
            board[i][colIndex] = board[i + 1][colIndex];
        }
        board[n - 1][colIndex] = temp;
    } else if (dir == 'd') {
        char temp = board[n - 1][colIndex];
        for (int i = n - 1; i > 0; --i) {
            board[i][colIndex] = board[i - 1][colIndex];
        }
        board[0][colIndex] = temp;
    }
}

void Scrambler::scrambler_init(vector<vector<char>>& board, const vector<string>& dictionary) {

    for (auto& row : board) { //for each row in the board
        int remainingSpaces = row.size();
        bool firstWord = true; //we use this to see if extra words need to be added in

        while (remainingSpaces > 2) {
            // Draw a random word from the list of all words
            string word = dictionary[rand() % dictionary.size()];
            // If row has space for the word and remaining space != 3
            if (remainingSpaces >= word.size() + (firstWord ? 0 : 1) && remainingSpaces - (word.size() + (firstWord ? 0 : 1)) != 3) {
                // Insert word into row with space in front if following another word
                int idx = row.size() - remainingSpaces;
                if (!firstWord) {
                    row[idx++] = ' '; // Inserts a space if it's not the first word in the row
                }
                for (char c : word) {
                    row[idx++] = c; // Inserts the word into the row one char at a time
                }

                remainingSpaces -= word.size() + (firstWord ? 0 : 1); //ternary operator to check if we need to add a space
                firstWord = false;
                usedWords.push_back(word); //adds the word to the used words vector to get_words() later
            }
        }
    }
    unjumbled_board = board; // Save the unjumbled board before jumbling it
    jumble_board(board);
}

string Scrambler::str() const {
    string result;
    int board_size = board.size(); //redundant but helped with readability
    result += "    ";
    for (int i = 1; i <= board_size; i++) {
        result += to_string(i) + (i == board_size ? "" : "   "); // Checks for spaces using a ternary operator since we dont space the ending
    }
    result += "\n   ";
    //adds the dashed lines to the board
    for (int i = 0; i < 4 * board_size; i++) {
        result += "-";
    }
    result += "\n";
    //Adds the letters into the board, and does formatting
    for (int i = 0; i < board_size; i++) {
        result += to_string(i + 1) + " | ";
        for (int j = 0; j < board_size; j++) {
            result += board[i][j];
            if (j != board_size - 1) {
                result += " | ";
            }
            else {
                result += " |";
            }
        }
        result += "\n   ";
        for (int i = 0; i < 4 * board_size; i++) {
            result += "-";
        }
        if (i == board_size - 1){
            continue;
        }
        else {
            result += "\n";
        }

    }
    //result += "\n";
    return result;
}
string Scrambler::display_solution() {
    string result;

    // Make a copy of the original jumbled board
    vector<vector<char>> copied_jumbled_board = jumbled_board; //copies global board for safety reasons, we can also use const
    board = copied_jumbled_board;

    // Reverse the steps recorded and remove the formatting.
    vector<string> reverseSolution;
    for (const auto& str : jumble_boardMoves) {
        int start_pos = str.find('(') + 1;
        int end_pos = str.find(')');
        string info = str.substr(start_pos, end_pos - start_pos);
        info.erase(remove(info.begin(), info.end(), ','), info.end());
        reverseSolution.push_back(info);
    }

    // Invert the order of moves and directions as we go backwards in steps
    reverse(reverseSolution.begin(), reverseSolution.end());
    for (auto& move : reverseSolution) {
        if (move[0] == 'c') {
            move[2] = (move[2] == 'u') ? 'd' : 'u';
        } else {
            move[2] = (move[2] == 'r') ? 'l' : 'r';
        }
    }

    // Now we input it and display it onto the screen
    //if it's the last line we don't want to add a new line
    for (int i = 1; i <= reverseSolution.size(); i++) {

        result += str()+ "\n";

        result += "*** Move " + to_string(i) + " (" + reverseSolution[i - 1][0] + "," + reverseSolution[i-1][1] +"," + reverseSolution[i-1][2] + ") \n";

        try_move(reverseSolution[i - 1]);

    }

    result += str() ;

    return result;
}



bool Scrambler::is_over() const {
    vector<string> board_strings;
    //convert chars to strings
    for (int i = 0; i < board_size; i++) {
        string row_str(board[i].begin(), board[i].end());
        board_strings.push_back(row_str);
    }

    // Check if all usedWords are found in board, it does each row at a time so unscramble order doesnt matter
    for (const string& word : usedWords) {
        bool found = false;
        for (const string& row_str : board_strings) {
            if (row_str.find(word) != string::npos) {
                found = true;
                break;
            }
        }
        if (!found) {
            return false;
        }
    }
    return true;
}

vector<string> Scrambler::get_words() const { //returns the words without spaces vector, but changed last minute
  /*  vector<string> words_without_spaces;

    for (const string& word : usedWords) {
        string word_without_space;
        for (char c : word) {
            if (c != ' ') {
                word_without_space += c;
            }
        }
        words_without_spaces.push_back(word_without_space);
    }
*/
    return usedWords;
}

Scrambler::Scrambler(const string & path , const int size ) {
    board_size = size;
    fillBoard();
    filePath = path;
    createDictionary(filePath);

    scrambler_init(board, Dictionary); //runs game

}









