/* Name: 
 * IDE: Clion
 * Date: 01/23/2021
 */
#include <iostream>
using namespace std;

int main() {
    // This is the "main menu" for the program
    int option = 0;
    cout << "Program 1: Matryoshka Dolls            \n"
         << "Choose from among the following options:  \n"
         << "   1. Display original graphic  \n"
         << "   2. Display Matryoshka Dolls         \n"
         << "   3. Exit the program          \n"
         << "Your choice -> ";
    cin >> option;

    // Different options
    if (option == 1) { // Original Graphics option
        for (int linenum = 1; linenum <= (3 * 2 - 1); linenum++) { //This is the top portion of the diamond
            cout << " ";
            for (int space = 1; space <= (3 * 2 - 1) - linenum; space++) {
                cout << " ";
            }
            for (int slash = 1; slash <= linenum; slash++) {
                cout << "/";
            }
            cout << "*+*";
            for (int backslash = 1; backslash <= linenum; backslash++) {
                cout << "\\";
            }

            cout << endl;
        }
        for (int linenum = 3 * 2 - 1; linenum >= 1; linenum--) { //Bottom portion of the diamond
            cout << " ";
            for (int space = 1; space <= (3 * 2 - 1) - linenum; space++) {
                cout << " ";
            }
            for (int slash = 1; slash <= linenum; slash++) {
                cout << "\\";
            }
            cout << "*+*";
            for (int backslash = 1; backslash <= linenum; backslash++) {
                cout << "/";
            }
            cout << endl;
        }
        cout << "Exiting";

    }

        // Option 2 This builds the dolls
    else if (option == 2) {
        // Prompt for and get the number of dolls.
        int numberOfDolls = 0;
        cout << "Number of dolls -> ";
        cin >> numberOfDolls;

        // Place your code starting here
        // ...
        for (int inc = 0; inc < numberOfDolls; inc++) {
            int top = numberOfDolls - 2;
            int bottom = numberOfDolls - inc;

            for (int spaces = 0; spaces < numberOfDolls; spaces++) cout << " ";

            cout << "( )" << endl;

            for (int spaces = 0; spaces < numberOfDolls - 1; spaces++) cout << " ";

            if (inc % 2 == 0) { // this checks for the alternating pattern between : and -
                cout << "/ - \\\n";
            }
            else {
                cout << "/ : \\\n";
            }
            // Top of doll
            int numSpaces = 5;
            for (int repeat = 0; repeat < inc; repeat++, numSpaces = numSpaces + 2, top--) {

                for (int space = 0; space < top; space++) cout << " ";
                cout << "/";
                for (int backslash = 0; backslash < numSpaces; backslash++) cout << " ";
                cout << "\\\n";
            }
            // bottom of dolls
            numSpaces -= 4;
            for (int j = 0; j < inc; j++, numSpaces -= 2, bottom++) {
                for (int space = 0; space < bottom; space++) cout << " ";
                cout << "\\";
                for (int space = 0; space < numSpaces; space++) cout << " ";
                cout << "/\n";
            }

            for (int inc = 0; inc < numberOfDolls; inc++) cout << " ";
            cout << "\\ /\n";

            for (int inc = 0; inc < numberOfDolls + 1; inc++) cout << " ";
            cout << "-\n";
        }
        cout << "Exiting" << endl;

    }

        // Option 3 essentially ends program
    else cout << "Exiting" << endl;
}


