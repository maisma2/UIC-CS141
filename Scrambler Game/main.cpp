
#include <iostream>
#include "Scrambler.h"
#include <string>

using namespace std;

int main() {
    srand(time(NULL));
    Scrambler game("dictionary.txt", 4);
    for (int i = 0; i < game.get_words().size(); i++){
        cout << game.get_words()[i] << endl;
    }
    cout << game.display_solution() << endl;
    cout << game.is_over();
    Scrambler game2("dictionary.txt", 4);
    for (int i = 0; i < game.get_words().size(); i++){
        cout << game2.get_words()[i] << endl;
    }
    cout << game2.display_solution() << endl;
    cout << game2.is_over();
    Scrambler game3("dictionary.txt", 4);
     for (int i = 0; i < game.get_words().size(); i++){
         cout << game3.get_words()[i] << endl;
     }
     cout << game3.display_solution() << endl;
     cout << game3.is_over();



}


/*
 *  cout << game.str();
    game.try_move("r3r");
    game.try_move("c2u");
    game.try_move("r3r");
    cout << game.str();
    game.try_move("r8l");
    cout << game.str();
    game.try_move("c7u");
    game.try_move("r5r");
    cout << game.str();
    game.try_move("c3u");
    cout << game.str();
    game.try_move("R");
    cout << game.str();
    cout << game.display_solution();
game.try_move("r3r");
game.try_move("c2u");
game.try_move("r3r");
game.try_move("r8l");
game.try_move("c7u");
game.try_move("r5r");
game.try_move("c3u");
game.try_move("r6l");
game.try_move("c8u");
game.try_move("r1r");
game.try_move("c3u");
game.try_move("r4r");
game.try_move("c5u");
game.try_move("r1l");
game.try_move("c6d");
game.try_move("r3r");
game.try_move("c8d");
game.try_move("r4l");
game.try_move("c6d");
cout << "tried move 20" << endl;
game.try_move("r7r");
game.try_move("c7d");
game.try_move("r4l");
game.try_move("c4u");
game.try_move("r4l");
game.try_move("r3r");
game.try_move("c2d");
game.try_move("r4r");
game.try_move("c6u");
game.try_move("r5l");
game.try_move("c6u");
game.try_move("r3r");
game.try_move("r3r");
game.try_move("c3u");
game.try_move("r1r");
game.try_move("c1d");
game.try_move("r2l");
game.try_move("c5u");
game.try_move("r1l");
game.try_move("c2u");
game.try_move("r4r");
game.try_move("r3r");
game.try_move("c2d");
game.try_move("r4l");
game.try_move("c1d");
game.try_move("r2r");
game.try_move("c3d");
game.try_move("r2r");
cout << "Try move 50" << endl;
game.try_move("r3r");
game.try_move("c3u");
game.try_move("r2r");
game.try_move("c3d");
game.try_move("r3r");
game.try_move("c3u");
game.try_move("r5r");
game.try_move("c6u");
game.try_move("r3l");
game.try_move("r7r");
game.try_move("c7d");
game.try_move("r1r");
game.try_move("c8u");
game.try_move("r3r");
game.try_move("r3r");
game.try_move("c4d");
game.try_move("r5l");
game.try_move("r4l");
game.try_move("c4d");
game.try_move("r6l");
game.try_move("c7d");
game.try_move("r1l");
game.try_move("c7d");
game.try_move("r5r");
game.try_move("r1r");
game.try_move("c5u");
game.try_move("r1l");
game.try_move("c1u");
game.try_move("r2r");
game.try_move("c3u");
game.try_move("r4r");
game.try_move("c5u");
game.try_move("r5l");
game.try_move("r3l");
game.try_move("c1d");
game.try_move("r1l");
game.try_move("c2d");
game.try_move("r1l");
game.try_move("c3u");
game.try_move("r1l");
game.try_move("c1u");
game.try_move("r2l");
game.try_move("c2d");
game.try_move("r3r");
game.try_move("c1u");
game.try_move("r3l");
cout << "tried move 93" << endl;
*/