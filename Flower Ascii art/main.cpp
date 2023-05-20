/*-------------------------------------------
Program 1: Flower Ascii
Name: Abeer Ismail
Course: CS 141, Spring 2023, UIC
System: Clion on Windows 11
------------------------------------------- */


#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // display the prompt to the user
    cout << "Program 1: ASCII Flowers\n"
         << "Choose from the following options:\n"
         << "   1. Display the HELLO graphic\n"
         << "   2. Display The Flower\n"
         << "   3. Exit the program\n"
         << "Your choice -> ";

    // read in the user's choice
    int menu_option;
    cin >> menu_option;

    // handle option to quit
    if (menu_option == 3) {
        exit(0);
    }

    // handle the HELLO graphic choice
    if (menu_option == 1) {
        char frame;
        cout << "Enter your frame character: ";
        cin >> frame;
        //top border
        cout << endl;
        for (int i=0; i<2; i++) {
            cout << setfill(frame) << setw(36) << ' ' << endl;
        }
        //message
        cout << setfill(frame) << setw(3) << right << " "
             << "** ** ***** **    **    *****"
             << setfill(frame) << setw(3) << left << " " << endl
             << setfill(frame) << setw(3) << right << " "
             << "** ** ***** **    **    *****"
             << setfill(frame) << setw(3) << left << " " << endl
             << setfill(frame) << setw(3) << right << " "
             << "** ** **    **    **    ** **"
             << setfill(frame) << setw(3) << left << " " << endl
             << setfill(frame) << setw(3) << right << " "
             << "***** ***** **    **    ** **"
             << setfill(frame) << setw(3) << left << " " << endl
             << setfill(frame) << setw(3) << right << " "
             << "***** ***** **    **    ** **"
             << setfill(frame) << setw(3) << left << " " << endl
             << setfill(frame) << setw(3) << right << " "
             << "** ** **    **    **    ** **"
             << setfill(frame) << setw(3) << left << " " << endl
             << setfill(frame) << setw(3) << right << " "
             << "** ** ***** ***** ***** *****"
             << setfill(frame) << setw(3) << left << " " << endl
             << setfill(frame) << setw(3) << right << " "
             << "** ** ***** ***** ***** *****"
             << setfill(frame) << setw(3) << left << " " << endl
             << right;
        //bottom border
        for (int i=0; i<2; i++) {
            cout << setfill(frame) << setw(36) << " " << endl;
        }
    }

    // handle the floral pattern TODO for students
    if (menu_option == 2) {
        //This is to retrieve the number of "layers"
        int flowerLayer = 0;
        cout << "Number of sections: " << endl;
        cin >> flowerLayer;

        //Now we build the flower
        for (int layer = 1; layer <= flowerLayer; layer++){
            //For each layer it builds a divider first before starting the layer building
            for (int spaces = 0; spaces < flowerLayer; spaces++) cout << " ";
            for (int dashes = 0; dashes < 3; dashes++) cout << "-";
            for (int spaces = 0; spaces < flowerLayer; spaces++) cout << " ";
            cout << endl;

            //The flower building part
            //It first checks the median for the @ formatting, if not it builds up colons
            //If else statements are used to see if it's above or below the median to see if it builds colons or decreases
            //Some of the variables are overcomplicated but I don't want to break the program and realized too late into the program
            int lineNum = 2 * layer - 1 ;
            int medianCounter = (((lineNum / 2) +1)-1);
            for(int lines = 1; lines <= lineNum; lines++){

                if (lines == (lineNum / 2)+1){
                    for (int i = 0; i < flowerLayer - layer; i++) cout << " ";
                    cout << "{";
                    for (int i = 0; i < layer; i++) cout << ":";
                    cout << "@";
                    for (int i = 0; i < layer; i++) cout << ":";
                    cout << "}" << endl;
                }
                else{
                    if (lines < ((lineNum / 2) + 1)){
                        for (int i = 0; i < flowerLayer - lines; i++) cout << " ";
                        int colons = (2 * lines) + 1;
                        cout << "{";
                        for (int i = 0; i < colons; i++) cout << ":";
                        cout << "}" << endl;
                    }
                    else{
                        for (int i = 0; i < flowerLayer - medianCounter; i++) cout << " ";
                        int colons = (2 * medianCounter) + 1;
                        cout << "{";
                        for (int i = 0; i < colons; i++) cout << ":";
                        cout << "}" << endl;
                        medianCounter--;
                    }
                }
            }
        }

        //Final divider between flower and stem
        for (int spaces = 0; spaces < flowerLayer; spaces++) cout << " ";
        for (int dashes = 0; dashes < 3; dashes++) cout << "-";
        for (int spaces = 0; spaces < flowerLayer; spaces++) cout << " ";
        cout << endl;


        //This is the stem, it checks for which layer and how it should be formatted
        //If is for even layers, else is for odd layers
        for (int stemLayer = 1; stemLayer <= flowerLayer; stemLayer++){
            if (stemLayer % 2 == 0){
                for (int spaces = 0; spaces < flowerLayer; spaces++){
                    cout << " ";
                }
                cout << "\\|" << endl;
                for (int spaces = 0; spaces < flowerLayer+1; spaces++){
                    cout << " ";
                }
                cout << "|" << endl;
            }
            else{
                for (int spaces = 0; spaces < flowerLayer+1; spaces++){
                    cout << " ";
                }
                cout << "|/" << endl;
                for (int spaces = 0; spaces < flowerLayer+1; spaces++){
                    cout << " ";
                }
                cout << "|" << endl;
            }

        }
    }
    return 0;
}
