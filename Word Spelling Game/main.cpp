#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <limits>
#include <sstream>
using namespace std;

const int NMISP = 5;
const int RNG_RANGE = 100;

void
display_header(const int ndict, const int nmiss)
{
    cout << "*** Typing Tutor" << endl;
    cout << "There are " << ndict << " words in the dictionary." << endl;
    cout << "There are "<< nmiss <<" commonly misspelled words" << endl;
}

void
display_menu_options()
{
    cout << endl << "*** Select a menu option:" << endl
         << "1. Spell commonly misspelled words" << endl
         << "2. Type random words from the full dictionary" << endl
         << "3. Display some words from one of the lists" << endl
         << "4. Use binary search to lookup a word in the dictionary" << endl
         << "5. Exit the program." << endl
         << "Your choice: ";
}

vector<int> randn(const int n, const int max){

    vector<int> v;
    for (int i = 1; i <= n; i++){
        v.push_back(rand() % max);
    }
    return v;
}

ifstream open(const string& src_file)
{
    //opens the file and checks if it exists
    ifstream src{src_file};
    if (!src.is_open()) {
        cout << "Could not find file " << src_file << "." << endl;
        exit(1);
    }
    return src;
}

void extract_dict(vector<string>& dst, const string& src_file)
{
    //ifstream is used to open the file, and while the file exists it imports into the dictionary vector
    ifstream temp = open(src_file);
    string line;
    while(getline(temp, line)){
        dst.push_back(line);
    }
}

void extract_misspelled(vector<string>& misspelled, vector<string>& correct, const string& src_file){
    //takes misspelled words file and seperates them based on a delimiter and puts them into their respective vectors
    ifstream temp = open(src_file);
    string line;
    while(getline(temp, line)){
        //delimiter used here for the space between the misspelled and correct words
        int pos = line.find(" ");
        misspelled.push_back(line.substr(0, pos));
        correct.push_back(line.substr(pos + 1));
    }
}

void
display_elems(const vector<string>& src, const vector<int>& positions)
{
   /* Parameters:
        src -> a vector (strings), passed by reference, that is not
               allowed to be modified (const), which holds the data
               that is to be printed

        positions -> a vector (int), passed by reference, that is not
                     allowed to be modified (const),  which holds the
                     indices for elements in src to print.
    */
    for(int i = 0; i < positions.size(); i++){
        if(i == positions.size() - 1){
            cout << src[positions[i]] << endl;
        }
        else{
            cout << src[positions[i]] << " ";
        }
    }

}

void
extract_spelling_answers(vector<string>& dst, const vector<string>& correct,
                            const vector<int> positions)
{
    /* TODO: Copy the elements at the indices, in the positions vector,
    from the correct vector, into the vector dst. See Section "Menu Op-
    tion 1: Spelling Misspelled".

    Parameters:
        dst -> an empty vector (of strings), passed by reference, that
               you will copy the specific elements from correct into.

        correct -> a vector (strings), passed by reference, that is not
                   allowed to be modified (const), which holds the data
                   that is to be copied over to dst

        positions -> a vector (int), passed by reference, that is not
                     allowed to be modified (const),  which holds the
                     indices of the elements in correct to copy over

    Hints:
        This is very similar to display_elems, except you are not printing
        out the elements but instead copying them over to dst.
    */
    for(int i = 0; i < positions.size(); i++){
        dst.push_back(correct[positions[i]]);
    }

}

void
extract_spelling_mistakes(vector<string>& dst, const string& to_grade,
                const vector<string>& correct)
{
    /* TODO: Populate the vector dst with all the spelling errors in the
    user's answer (to_grade).  See Section "Menu Option 1: Spelling Mis-
    spelled"

    Parameters:
        dst -> an empty vector (of strings), passed by reference, that you
        will fill with strings that represent spelling errors  (mispelling
        -> correct spelling) (see Hints)

        to_grade -> a string, passed  by reference,  that is not allowed to
                    be modified (const) that holds the user's typed answer.

        correct -> a vector (strings), passed by reference, that is not
                   allowed to be modified (const), which holds the correct
                   answers. (one vector element -> one word)

    Hints:
        First you need to extract the answer, the user gave, for each word.
        Once you have those, you can compare it with the associated correct
        answer  (answer ?= correct[i] for the ith word).  You then populate
        the vector dst with a string that described the error. For example,
        if the word is  "hello" and  the user types  "jello" then the error
        will be "jello -> hello".
    */
    string temp;


}

void
report_misspell_mistakes(const vector<string>& mistakes,
                            const int num_words)
{
    /*  TODO: Print out the spelling mistakes to the user. Following
    the format from the write-up. See Section "Menu Option 1: Spell-
    ing Misspelled".

    Parameters:
        mistakes -> a vector (strings), passed by reference, that is
                    not allowed  to be modified  (const),  and holds
                    the messages about  misspellings that we want to
                    report to the user.

        num_words -> an integer, that is not allowed to be modified
                     (const),  which is  the total number  of words
                     being tested
    */
}

void
evaluate_user_misspells(const vector<string>& src, const vector<int>& positions)
{
    /*
    Parameters:
        src -> a vector (strings), passed by reference, that is not
               allowed to be modified (const), which holds the data
               that the user is being tested on.

        positions -> a vector (int), passed by reference, that is not
                     allowed to be modified (const),  which holds the
                     indices of the elements in correct to copy over
    */
    //first we seperate the src into user_input and correct
    vector<string> user_input =;
    vector<string> correct;




}

void misspelled(const vector<string>& mspelled, const vector<string>& correct){

    vector<int> positions = randn(5, mspelled.size() - 1);
    cout << "*** Using commonly misspelled words." << endl;
    display_elems(mspelled, positions);
    cout << "Type the words above with the correct spelling." << endl;
    //use getline and make each word imported into the vector and with each element the correct word should be next to it
    vector<string> user_input;
    string temp;
    for(int i = 0; i < positions.size(); i++){
        cin >> temp;
        user_input.push_back(temp);
    }
    //vector evaluate will be user input + " " + correct word
    vector<string> evaluate;
    for(int i = 0; i < positions.size(); i++){
        evaluate.push_back(user_input[i] + " " + correct[positions[i]]);
    }
    evaluate_user_misspells(user_input, positions);

}

void
full_dict(const vector<string>& dict)
{
    /* TODO: Print out starting message for menu option 2, display five random
    words from the full dictionary, then evaluate the user's input. See Section
    "Menu Option 2: Typing From Dictionary"

    Parameters:
        dict -> a vector (string), passed by reference, where
                each element is one word from the full
                dictionary.

    Hints:
        Do not start by writing this function. It's role is to simply drive
        the whole procedure for menu option 2,  it should be calling helper
        functions to  handle the details  of the task.  You should be using
        randn, display_elems, and evaluate_user_misspells.
    */
}

void
display_words_prompt()
{
    // This displays the data set choices for menu option 3
    cout << endl << "*** Displaying word list entries." << endl
         << "Which words do you want to display?" << endl
         << "A. Dictionary of all words" << endl
         << "B. Commonly misspelled words (wrongly spelled)" << endl
         << "C. Commonly misspelled words (correctly spelled)" << endl
         << "Your choice: ";
}

void
print_range(const vector<string>& data)
{
    /* TODO:  Display the starting  message for menu option 3,  read the
    users chosen range, verify that the indices are in range, then print
    out the  words in the index range.  See Section "Menu Option 3: Word
    Range"

    Parameters:
        data -> a vector (string),  passed by reference, that cannot be
                modified (const), which holds the all the data (and the
                user will print some of it in a range)

        Hints:
            You can determine the range of the data by checking the size
            of the vector. You need to make sure the  range is valid for
            the given dataset  (think about what  values  the user could
            give that would be invalid). Check the write-up to make sure
            you are printing the data in the expected format.
    */
}

void
display_in_range(const vector<string>& dict, const vector<string>& mspelled,
                const vector<string>& correct)
{
    /* TODO: Display the initial messages for menu option 3, read in
    the user's choice of dataset, and display the data in range. See
    Section "Menu Option 3: Word Range"

    Parameters:
        dict -> a vector (string),  passed by reference, that cannot be
                modified (const), which holds the all the data from the
                full dictionary

        mspelled -> a vector (string), passed by reference, that cannot
                    be modified (const),  which holds the all the miss-
                    pelled words

        correct -> a vector (string), passed by reference, that cannot
                   be modified (const),  which holds the all the words
                   with correct spelling

    Hints:
        First write  the function print_range, which will print data in a
        range (in general). This function should call print_range, but it
        will read in the user's  choice of data set and  call print_range
        with the user's choice.
    */

}

void
bsearch(const vector<string>& data)
{
    /* TODO:  Read in the word to search for, from the user, and run the
    Binary Search Algorithm to search for the word. At every step of the
    algorithm,  print out the current word,  that is being compared with
    the target.

    Parameters:
        data -> a vector (string),  passed by reference, that cannot be
                modified (const), which holds the all the data from the
                full dictionary
    Hints:
        See our sample code to learn how the binary search algorithm works.
        Remember to  output the text in the same  format as you  see in the
        write-up.
    */

}

void
extract_all_data(vector<string>& dict, vector<string>& mspelled,
                    vector<string>& correct)
{
    extract_dict(dict, "dictionary.txt");
    extract_misspelled(mspelled, correct, "misspelled_words.txt");
}

int
main()
{
    vector <int> rands = {12, 51, 61, 2, 9, 2};
    srand(1);
    vector<string> dict, mspelled, correct;
    extract_all_data(dict, mspelled, correct);
    display_header(dict.size(), correct.size());
    unsigned int choice;

    do {
        display_menu_options();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice) {
        case 1:
            misspelled(mspelled, correct);
            break;
        case 2:
            full_dict(dict);
            break;
        case 3:
            display_in_range(dict, mspelled, correct);
            break;
        case 4:
            bsearch(dict);
            break;
        case 5:
            cout << "Exiting." << endl;
            break;
        default:
            cout << "No menu option " << choice << ". "
                 << "Please try again." << endl;
        }
    } while ((choice != 5) && !cin.eof());


    return 0;
}
