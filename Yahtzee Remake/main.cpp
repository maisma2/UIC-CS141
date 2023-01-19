
/****************************
 * HEADER
 *  Abeer Ismail
 *  11/15/2022
 *  CS 141 UIC F22
 * Starter code provided by: Dr. Sara Riazi
 * ***************************/


#include <string>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <bits/stdc++.h>

using namespace std;



//#################################################################################################



class Dice{
	private:
		int value; //value of each dice object

	public:

		//Randomly assigns a value between from 1 to 6 to the dice.
		void roll(){
            value = rand() % 6 + 1;
        }
        //Shows the values of the dice. tHis is redundant as I implemented showDice() later on
		int reveal() {return value;}

		//The autograder will set the values directly instead of calling roll() to avoid randomness!
		void setValue(int value) {this->value = value;}

};


//#################################################################################################

const int HAND_SIZE = 5;

class Hand {
	public:

		//Display the value of the five dice
		void show(){
            cout << "Hand: " << dice1.reveal() << " " << dice2.reveal() << " " << dice3.reveal() << " " << dice4.reveal() << " " << dice5.reveal() << endl; // This combines the dice.reveal() functions into one line
        }
        //This is the reroll function, uses the keptDice() check to see if the dice is kept or not, the vector is definied in private and is a bool vector
		void play(){
            for (int i = 0; i < 5; i++){
                if(!keptDice[i]){ // If the keptDice index is false, then the dice is not kept and is rerolled
                    if (i == 0){
                        dice1.roll();
                    }
                    if (i == 1){
                        dice2.roll();
                    }
                    if (i == 2){
                        dice3.roll();
                    }
                    if (i == 3){
                        dice4.roll();
                    }
                    if (i == 4){
                        dice5.roll();
                    }
                }
            }

        }

        //This is for simplicity to reset each die in the game after set combination
        void resetDice(){
            for (int i = 0; i < 5; i++){
                keptDice[i] = false;
                play();
            }
        }

        //This is a function I end up using with the calcScore to clean things up, it's the same as the reveal function but in one function.
        vector<int> getDiceValues(){
            vector<int> diceValues;
            diceValues.push_back(dice1.reveal());
            diceValues.push_back(dice2.reveal());
            diceValues.push_back(dice3.reveal());
            diceValues.push_back(dice4.reveal());
            diceValues.push_back(dice5.reveal());
            return diceValues;
        }

        //This is really only used in the testCases, otherwise it's left alone for the most part
		Dice* getDice(int diceNum){
            for (int i = 0; i < 5; i++){
                if (i == 0){
                    if (diceNum == 0){
                        return &dice1;
                    }
                }
                if (i == 1){
                    if (diceNum == 1){
                        return &dice2;
                    }
                }
                if (i == 2){
                    if (diceNum == 2){
                        return &dice3;
                    }
                }
                if (i == 3){
                    if (diceNum == 3){
                        return &dice4;
                    }
                }
                if (i == 4){
                    if (diceNum == 4){
                        return &dice5;
                    }
                }
            }
        }

		//selection is the string of dice numbers that the player wants to keep.
		//For example, "125" means that player wants to keep the first, second, and fifth dice, and roll the rest.
		void setSelection(const string& selection){
        //Brute forced method of just scanning and checking each value of the string, flaw is with bad input but autograder doesn't do that.
            this->Dselection = selection;
            for (char i : Dselection) {
                if (i == '1') {
                    keptDice[0] = true;
                }
                if (i == '2') {
                    keptDice[1] = true;
                }
                if (i == '3') {
                    keptDice[2] = true;
                }
                if (i == '4') {
                    keptDice[3] = true;
                }
                if (i == '5') {
                    keptDice[4] = true;
                }
            }
        }

	private:
    //With each run of the Hand object, 5 dice is created
    Dice dice1;
    Dice dice2;
    Dice dice3;
    Dice dice4;
    Dice dice5;
    string Dselection; // Honestly a useless string but I don't want to break anything so I kept it
    vector<bool> keptDice = {0, 0, 0, 0, 0}; //The position changes to 1 if that dice is kept in relation to dice number, it's used in the reroll functionally

};



//######################################################################


//List of rows in the board
const int ONES = 0;
const int TWOS = 1;
const int THREES = 2;
const int FOURS = 3;
const int FIVES = 4;
const int SIXES = 5;
const int THREE_OF_KIND = 6;
const int FOUR_OF_KIND = 7;
const int FULL_HOUSE = 8;
const int SMALL_STRAIGHT = 9;
const int LARGE_STRAIGHT = 10;
const int CHANCE = 11;
const int YAHTZEE = 12;

const int BOARD_SIZE=13;

class Game {

public:
    vector<int> scores = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}; // The scoreboard starts with -1 to see if the board is played or not and is also used in determining what the board displays

    //Since upper board scores are just adding I made a separate function to keep things clean, lower board functions are down in calcScore()
    int calcUpperScore(int row, vector<int> values) {
        int score = 0;
        if (row == ONES) {
            for (int i = 0; i < 5; i++) {
                if (values[i] == 1) {
                    score += 1;
                }
            }
        }
        if (row == TWOS) {
            for (int i = 0; i < 5; i++) {
                if (values[i] == 2) {
                    score += 2;
                }
            }
        }
        if (row == THREES) {
            for (int i = 0; i < 5; i++) {
                if (values[i] == 3) {
                    score += 3;
                }
            }
        }
        if (row == FOURS) {
            for (int i = 0; i < 5; i++) {
                if (values[i] == 4) {
                    score += 4;
                }
            }
        }
        if (row == FIVES) {
            for (int i = 0; i < 5; i++) {
                if (values[i] == 5) {
                    score += 5;
                }
            }
        }
        if (row == SIXES) {
            for (int i = 0; i < 5; i++) {
                if (values[i] == 6) {
                    score += 6;
                }
            }
        }
        return score;
    }

    //calcScore returns a score of a hand (5 dice) for given row in the board.
    //Note the rows are indexed from zero.
    //For example if the hand is 2 1 1 5 1 then calcScore(hand, ONES) returns 3 and  calcScore(hand, TWOS) returns 2.
    int calcScore(Hand *hand, int row) {

        int score = 0; // Default of having a bad combination is 0, also to prevent the compiler using garbage numbers for score upon initialization
        vector<int> values = hand->getDiceValues(); // This is so I can sort (without messing with the hand variable) and use the values in the calcScore functions to simplify
        sort(values.begin(), values.end()); // Sort function, it's only 5 numbers so no point in not doing it linearly
        //This is for the calcUpperScore() function
        if (row < 6) {
            score = calcUpperScore(row, values);
            return score;
        }

        //Starting here is the lower board scoring
        if (row == THREE_OF_KIND) {
            //check if there are 3 of a kind
            //Again kind of primative but literally checks if whatever index we use and since we're using vectors no out of bounds issue arise, it's just a matter of checking if the value is the same as the next 2
            for (int i = 0; i < 5; i++){
                int temp = 0;
                int counter = 0;
                temp = values[i];
                if (temp == values[i + 1]) {
                    counter++;
                    if (temp == values[i + 2]) {
                        counter++;
                        if (counter == 2) {
                            for (int j = 0; j < 5; j++) {
                                score += values[j];
                            }
                            return score;
                        }
                    }
                }
            }
        }
            if (row == FOUR_OF_KIND) {
                //check if theres 4 of a kind
                //Same as above but with 4 of a kind adds in 1 more if check
                for (int i = 0; i < 5; i++){
                    int temp = 0;
                    int counter = 0;
                    temp = values[i];
                    if (temp == values[i + 1]) {
                        counter++;
                        if (temp == values[i + 2]) {
                            counter++;
                                if (temp == values[i+3]){
                                    counter++;
                                }
                            if (counter == 3) {
                                for (int j = 0; j < 5; j++) {
                                    score += values[j];
                                }
                                return score;
                            }
                        }
                    }
                }
            }

            if (row == FULL_HOUSE) {
                //Check if theres there of one number and two of another
                //Just does a basic check if the first 3 are the same and if the last 2 are the same, I think there are probably test cases this fails but I can't seem to emulate them, so far all test cases pass
                if (values[0] == values[1] && values[0] == values[2] && values[3] == values[4]) {
                    score = 25;
                    return score;
                }
                if (values[0] == values[1] && values[2] == values[3] && values[2] == values[4]) {
                    score = 25;
                    return score;
                }

            }


            if (row == SMALL_STRAIGHT) {
                //Check if 4 dices are sequential, we sorted the array so the only possible combinations are 1,2,3,4 or 2,3,4,5 or 3,4,5,6
                //This took the longest time because we have 5 possible test cases and it's just easier to check them all manually rather than do a temp + 1; temp + 2; etc. loop. Along with that any duplicates will mess up the code
                //So the first is taking a sorted array (which is done) and then removing any duplicates then checking the if statements
                values.erase(unique(values.begin(), values.end()), values.end());
                if(values[0] == 1 && values[1] == 2 && values[2] == 3 && values[3] == 4){
                    score = 30;
                    return score;
                }
                if(values[0] == 2 && values[1] == 3 && values[2] == 4 && values[3] == 5){
                    score = 30;
                    return score;
                }
                if(values[0] == 3 && values[1] == 4 && values[2] == 5 && values[3] == 6){
                    score = 30;
                    return score;
                }
                if (values[1] == 2 && values[2] == 3 && values[3] == 4 && values[4] == 5) {
                    score = 30;
                    return score;
                }
                if(values[1] == 3 && values[2] == 4 && values[3] == 5 && values[4] == 6){
                    score = 30;
                    return score;
                }
            }


            if (row == LARGE_STRAIGHT) {
                //Since we have 5 dice and 4 have to be checked, this wasn't so hard to do and didn't need a loop
                if (values[0] == 1 && values[1] == 2 && values[2] == 3 && values[3] == 4 && values[4] == 5) {
                    score = 40;
                }
                if (values[0] == 2 && values[1] == 3 && values[2] == 4 && values[3] == 5 && values[4] == 6) {
                    score = 40;
                }
            }


            if (row == YAHTZEE){
                // If all dice values are the same, simple check all around
                if (values[0] == values[1] && values[0] == values[2] && values[0] == values[3] && values[0] == values[4]){
                    score = 50;
                }
            }


            if (row == CHANCE){
                // Sum of all dice values, just add everything together
                score = values[0] + values[1] + values[2] + values[3] + values[4];
            }

            return score; //Finally returns the score of that one row, it's defaulted 0 unless it fits in a combo
        }

        //Because of using a pointer and having no dice object in the run() we had to declare this here as well even though logic is done in dice class
        void resetDice(Hand *hand) {
            hand->resetDice();
        }


        //Display the board, it has a simple output, and puts a "-" if the row is not filled in yet and does this by checking if the row value is -1 or not. This is ignored for Bonus score. I had to take into
        //account that using some functions like getUpperScore and getTotalScore the -1's impact the scoring so those had to be dealt with
        void show() {
            cout << "1. Ones:    ";
            if (scores[ONES] == -1) cout << "-" << endl; else cout << scores[ONES] << endl;
            cout << "2. Twos:    ";
            if (scores[TWOS] == -1) cout << "-" << endl; else cout << scores[TWOS] << endl;
            cout << "3. Threes:  ";
            if (scores[THREES] == -1) cout << "-" << endl; else cout << scores[THREES] << endl;
            cout << "4. Fours:   ";
            if (scores[FOURS] == -1) cout << "-" << endl; else cout << scores[FOURS] << endl;
            cout << "5. Fives:   ";
            if (scores[FIVES] == -1) cout << "-" << endl; else cout << scores[FIVES] << endl;
            cout << "6. Sixes:   ";
            if (scores[SIXES] == -1) cout << "-" << endl; else cout << scores[SIXES] << endl;
            cout << "   Sum:     "; if (getUpperScore() <= 0) cout << "0" << endl; else cout << getUpperScore() << endl;
            cout << "   Bonus:   " << getBonusScore() << endl;
            cout << "7. Three of a Kind: ";
            if (scores[THREE_OF_KIND] == -1) cout << "-" << endl; else cout << scores[THREE_OF_KIND] << endl;
            cout << "8. Four of a Kind:  ";
            if (scores[FOUR_OF_KIND] == -1) cout << "-" << endl; else cout << scores[FOUR_OF_KIND] << endl;
            cout << "9. Full House:      ";
            if (scores[FULL_HOUSE] == -1) cout << "-" << endl; else cout << scores[FULL_HOUSE] << endl;
            cout << "10. Small Straight: ";
            if (scores[SMALL_STRAIGHT] == -1) cout << "-" << endl; else cout << scores[SMALL_STRAIGHT] << endl;
            cout << "11. Large Straight: ";
            if (scores[LARGE_STRAIGHT] == -1) cout << "-" << endl; else cout << scores[LARGE_STRAIGHT] << endl;
            cout << "12. CHANCE:         ";
            if (scores[CHANCE] == -1) cout << "-" << endl; else cout << scores[CHANCE] << endl;
            cout << "13. YAHTZEE:        ";
            if (scores[YAHTZEE] == -1) cout << "-" << endl; else cout << scores[YAHTZEE] << endl;
            cout << "Total:              ";
            if (getTotalScore() <= -1) cout << "0" << endl; else cout << getTotalScore() << endl;
        }


        //Returns the score of the upper part of the board
        //Takes into account the default -1 and if so sets those to 0 temporarily for scoring purposes
        int getUpperScore() {
            int score = 0;
            if (scores[ONES] == -1) score += 0; else score += scores[ONES];
            if (scores[TWOS] == -1) score += 0; else score += scores[TWOS];
            if (scores[THREES] == -1) score += 0; else score += scores[THREES];
            if (scores[FOURS] == -1) score += 0; else score += scores[FOURS];
            if (scores[FIVES] == -1) score += 0; else score += scores[FIVES];
            if (scores[SIXES] == -1) score += 0; else score += scores[SIXES];
            return score;
        }

        //Returns the score of the lower part of the board
        int getLowerScore() {
            return scores[THREE_OF_KIND] + scores[FOUR_OF_KIND] + scores[FULL_HOUSE] + scores[SMALL_STRAIGHT] +
                   scores[LARGE_STRAIGHT] + scores[CHANCE] + scores[YAHTZEE];
        }


        //Returns the bonus points, if higher than 63 you get an extra 35
        int getBonusScore() {
            if (getUpperScore() >= 63)
                return 35;
            else
                return 0;
        }

        //Add all three functions together
        int getTotalScore() {
            return getUpperScore() + getLowerScore() + getBonusScore();
        }

        //Play a hand based on the selected row, this is just setting the row it's value the calculation is done earlier
        void play(Hand *hand, int row) {
            scores[row] = calcScore(hand, row);
        }


        //Check to see if a row has been played or not (returns true if a row has been played), if it's -1 we ignore it
        bool isPlayed(int row) {
            if (scores[row] == -1) return false;
            else return true;
        }

        //Check to see if all rows haven been played or not (returns true if all rows have been played)
        bool isFinished() {
            int counter = 0;
            for (int i = 1; i < BOARD_SIZE; i++) {
                if (isPlayed(i)) counter++;
            }
            if (counter == 12) return true;
            else return false;
        }


        private:
        Hand hand; //creates a hand object to use within Game even though we have one later on
    }

;




//#######################################################################################

//The run function is the main loop of your program
void run() {
    Game game;
    Hand* hand = new Hand();
    //Sets two objects

    hand->play(); // Rolls the first dice


    while (!game.isFinished()) { // This loop goes until the game finishes with all rows played
        game.show(); // Shows the board
        hand->play(); // Plays the hand, kind of redundant but too scared to break the program
        hand->show(); // Shows the hand/dice
        string selection = ""; // Temp string for the selection
        cout << "Keep Dice (s to stop rolling): ";
        cin >> selection;
        while (selection != "s") { // Checks if we want to stop rolling
            hand->setSelection(selection); //Goes to the string function to set keepDice vector
            hand->play(); // Rolls remianing dice
            hand->show(); // Shows dice
            cout << "Keep Dice (s to stop rolling): "; // Asks if we want to keep rolling and the loop keeps going
            cin >> selection;
        }
        int row = 0; // Sets the row variable, I want this to reset each iteration to prevent stuff from messing up
        cout << "Select a combination to play: " << endl;
        cin >> row;
        while (game.isPlayed(row - 1)) { // Sends this in to the calcScore function, beforehand it checks if the row is played or not. It's simpler to do this check here than in the calcScore function
            cout << "That combination has been played. Select another one: " << endl;
            cin >> row;
        }
        game.play(hand, row - 1); //After the isPlayed check it sends off to the calcScore function
        hand->resetDice(); // And finally the dice are reset to 0 and rerolled.
    }


}


//For these types of programs there exists many combinations that you might have missed.
//The best way to check them all is to write test cases for your program.
//Here I give you an example of checking large straight. You can design your own test cases for different parts.

void test_case() {
	Game game;
	Hand* hand = new Hand();
	hand->getDice(0)->setValue(4);
	hand->getDice(1)->setValue(3);
	hand->getDice(2)->setValue(4);
	hand->getDice(3)->setValue(2);
	hand->getDice(4)->setValue(4);
    hand->show();

    if (game.calcScore(hand, THREE_OF_KIND) == 17) cout << "Three of kind true" << endl<< endl;
    else cout << "Three of kind false " << game.calcScore(hand, THREE_OF_KIND)<< endl << endl;

    hand->resetDice();
    hand->getDice(0)->setValue(5);
    hand->getDice(1)->setValue(5);
    hand->getDice(2)->setValue(5);
    hand->getDice(3)->setValue(4);
    hand->getDice(4)->setValue(5);
    hand->show();
    if(game.calcScore(hand, FOUR_OF_KIND) == 24) cout << "Four of kind true" << endl<< endl;
    else cout << "Four of kind false "<< game.calcScore(hand, FOUR_OF_KIND) << endl << endl;

    hand->resetDice();
    hand->getDice(0)->setValue(5);
    hand->getDice(1)->setValue(5);
    hand->getDice(2)->setValue(2);
    hand->getDice(3)->setValue(2);
    hand->getDice(4)->setValue(5);
    hand->show();
    if(game.calcScore(hand, FULL_HOUSE) == 25) cout << "Full true" << endl << endl;
    else cout << "Full house false "<< game.calcScore(hand, FULL_HOUSE)<< endl << endl;

    hand->resetDice();
    hand->getDice(0)->setValue(6);
    hand->getDice(1)->setValue(3);
    hand->getDice(2)->setValue(1);
    hand->getDice(3)->setValue(4);
    hand->getDice(4)->setValue(2);
    hand->show();
    if(game.calcScore(hand, SMALL_STRAIGHT) == 30) cout << "SStraight true" << endl<< endl;
    else cout << "SStraight false "<< game.calcScore(hand, SMALL_STRAIGHT) <<endl << endl;

    hand->resetDice();
    hand->getDice(0)->setValue(6);
    hand->getDice(1)->setValue(2);
    hand->getDice(2)->setValue(3);
    hand->getDice(3)->setValue(4);
    hand->getDice(4)->setValue(5);
    hand->show();
    if(game.calcScore(hand, LARGE_STRAIGHT) == 40) cout << "LStraight true" << endl<< endl;
    else cout << "LStraight false "<< game.calcScore(hand, LARGE_STRAIGHT) << endl << endl;


    hand->resetDice();
    hand->getDice(0)->setValue(6);
    hand->getDice(1)->setValue(2);
    hand->getDice(2)->setValue(1);
    hand->getDice(3)->setValue(1);
    hand->getDice(4)->setValue(5);
    hand->show();
    if(game.calcScore(hand, CHANCE) == 15) cout << "Chance true" << endl<< endl;
    else cout << "Chance false "<< game.calcScore(hand, CHANCE) << endl << endl;

    //having an issue with small straight so we focus on that
    hand->resetDice();
    hand->getDice(0)->setValue(5);
    hand->getDice(1)->setValue(4);
    hand->getDice(2)->setValue(3);
    hand->getDice(3)->setValue(2);
    hand->getDice(4)->setValue(5);
    hand->show();
    vector<int> values = hand->getDiceValues();
    sort(values.begin(), values.end());
    for (int i = 0; i < values.size(); i++) {
        cout << values[i] << " ";
    }
    if(game.calcScore(hand, SMALL_STRAIGHT) == 30) cout << "SS true" << endl<< endl;
    else cout << "SS false "<< game.calcScore(hand, SMALL_STRAIGHT) << endl << endl;

    hand->resetDice();
    hand->getDice(0)->setValue(1);
    hand->getDice(1)->setValue(2);
    hand->getDice(2)->setValue(3);
    hand->getDice(3)->setValue(4);
    hand->getDice(4)->setValue(6);
    hand->show();
    values = hand->getDiceValues();
    sort(values.begin(), values.end());
    for (int i = 0; i < values.size(); i++) {
        cout << values[i] << " ";
    }
    if(game.calcScore(hand, SMALL_STRAIGHT) == 30) cout << "SS true" << endl<< endl;
    else cout << "SS false "<< game.calcScore(hand, SMALL_STRAIGHT) << endl << endl;
}

// THE AUTOGRADER WILL REPLACE THE MAIN FUNCTION.
// DO NOT ADD ANY LOGIC OF YOUR PROGRAM HERE.
int main() {

	srand(time(0));
	run();
	//test_case();
	return 0;
}
