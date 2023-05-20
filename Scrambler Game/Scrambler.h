//
// Created by maism on 4/10/2023.
// Scrambler Class which has definitions for each function
// The private functions are used after scrambler_init() is called
//

#ifndef PROGRAM5_SCRAMBLER_H
#define PROGRAM5_SCRAMBLER_H

#include <vector>
#include <string>

using namespace std;

class Scrambler {

public:
    Scrambler(const string & path , const int size );
    string str() const;
    void try_move(const string & cmd );
    bool is_over() const;
    vector<string> get_words() const;
    string  display_solution();



private:
    void createDictionary(string &filepath);
    void fillBoard();
    void jumble_board(vector<vector<char>>& board);
    void scrambler_init(vector<vector<char>>& board, const vector<string>& dictionary);
    void shiftColumn(vector<vector<char>> &board, int colIndex, char dir);
    void shiftRow(vector<vector<char>> &board, int rowIndex, char dir);
    int board_size;
    string filePath;

    vector<string> Dictionary; //Words being used
    vector<vector<char>> board; //Global changing board
    vector<vector<char>> jumbled_board; //used to not change the jumbled board for display_solution
    vector<vector<char>> unjumbled_board; //used to see how the original board was made, redundant as the unscramble method is included
    vector<string> jumble_boardMoves; //record of moves committed
    vector<string> usedWords; //words that have been used in the scrambling
};


#endif //PROGRAM5_SCRAMBLER_H
