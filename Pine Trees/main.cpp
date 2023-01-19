/**------------------------------------------

    Program 1: Layered Pine Tree
    Prompt for the number of tree layers and display
    ASCII layered pine tree

    Course: CS 141, Fall 2022.
    System: Windows CLion
    Author: Professor Riazi, Abeer Ismail
 ---------------------------------------------**/

#include <iostream>   // for cin and cout
#include <iomanip>    // for setw. The number in setw(...) is the total of blank spaces including the printed item.

using namespace std; // so that we don't need to preface every cin and cout with std::

int main()
{
    // Display the menu and get the user choice
    int menu_option = 0;
    cout << "Program 1: The Pine Tree            \n"
         << "Choose from the following options:  \n"
         << "   1. Display the HELLO graphic  \n"
         << "   2. Display The Pine Tree        \n"
         << "   3. Exit the program          \n"
         << "Your choice -> ";
    cin >> menu_option;

    if (menu_option == 3) { // Handle menu option of 3 to exit
        exit(0); // The call to exit the code successfully (0 means the runs didn't encounter any problem).
    }

    else if (menu_option == 1) { // Handle menu option of 1 to display custom ASCII graphics
        // Display ASCII graphics for "HELLO".
	// The main purpose of this part is to give you hints about usnig setw and setfill and their behaviors.

	//the character for the frame of our display.
	char frame = '-';
	cout << "Enter your frame character: ";
        cin >> frame;
	cout << endl;
	// The goal of next three lines is to print a line with 77 dashes differently.
	cout << setfill(frame); //change the default character for filling the fields defined using setw. You can change it fill to different character to see the difference.
        cout << setw(78) << "\n"; // \n counts in 78 so you will get 77 dashes plus one \n
        cout << setw(78) << endl; ///after setfill you need to pass a string or character to push setfil to fill the field, otherwise you will see an empty line for this instruction. See the differnce in output from this line and the above line.
        cout << setw(77) << frame << endl; //I use 77 with setfill and one extra at the end to get the same result

	cout << setw(8) << " " << "   **    **    ********    **         **         ********    " << setw(9) << "\n";
        cout << setw(8) << " " << "   **    **    ********    **         **         ********    " << setw(9) << "\n";
        cout << setw(8) << " " << "   **    **    **          **         **         **    **    " << setw(9) << "\n";
        cout << setw(8) << " " << "   ********    ********    **         **         **    **    " << setw(9) << "\n";
        cout << setw(8) << " " << "   ********    ********    **         **         **    **    " << setw(9) << "\n";
        cout << setw(8) << " " << "   **    **    **          **         **         **    **    " << setw(9) << "\n";
        cout << setw(8) << " " << "   **    **    ********    ********   ********   ********    " << setw(9) << "\n";
        cout << setw(8) << " " << "   **    **    ********    ********   ********   ********    " << setw(9) << "\n";
        cout << setw(77) << frame << endl; //the extra character is - so in total we will have 77 dashes.
        cout << setw(78) << "\n"; //again, the extra character is \n so you have set the width to 78

	//you can do it this way using a for-loop too
	 for (int i = 0; i < 77; i++) {
            cout << frame;
        }
        cout << endl;



    } else if (menu_option == 2) {
        // Prompt for and get the number of layers for the tree.
        int number_of_tree_layers = 0;
    	cout << "Number of tree layers -> " << endl;
        cin >> number_of_tree_layers;

        int width = 5 + (number_of_tree_layers - 1) * 2;                // the width of the tree, its based off the last line of "leaves" also comes in handy later for making the trunk

        // this loop is for each layer of "leaves"
        for (int layer = 1; layer <= number_of_tree_layers; layer++)

        {
            int spaces = width / 2 - (layer - 1) + 1;            // we got this using the program example, and using linear slope with line 2  = 3 stars, line 3 = 5 stars.
            int stars = 2 * layer - 1;                            //we get this again by using a linear slope where each layer increases by 2, except the first row has to be 1 star

            for (int line = 1; line <= 3; line++)                   // each layer has three lines, the loop above handles each layer, this loop makes sure to print and move onto the next line within the layer
            {

                for (int spPrint = 1; spPrint <= spaces - line; spPrint++) // this handles spaces
                {
                    cout << " ";
                }
                for (int stPrint = 1; stPrint <= stars + 2 * (line - 1); stPrint++) // this handles stars
                {
                    cout << "*";
                }

                cout << "\n";                      // this newline is created after each line is done
            }
        }
        // end of leaves loop

        // this loop handles the "trunk" which is just |||
        int trunk = 2 * number_of_tree_layers;              // realized that the trunk is just layers * 2

        for (int i = 0; i < trunk; i++)
        {
            // the spaces for this is pretty much the same as the number of layers
            for (int spaces = 0; spaces < number_of_tree_layers; spaces++)
                cout << " ";

            // since the trunk is always 3 spaces we don't have to worry too much about other variables
            for (int vLine = 0; vLine < 3; vLine++)
                cout << "|";

            cout << "\n";                  //newline at the end of each line of the trunk
        }

    } //end if( menu_option == 2)


    cout << endl; //DO NOT CHANGE THIS LINE

    return 0;
}
