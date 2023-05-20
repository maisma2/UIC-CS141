#include <iostream>
#include "ContactList.h"
#include <vector>

using namespace std;

//function to show additional options with numbers
void contactsAdditionalOptions(){
    cout << "Enter an option for contact: \n"
            "   A - Edit address\n"
            "   B - Edit date of birth\n"
            "   E - Edit email address\n"
            "   N - Edit name\n"
            "   P - Edit phone numbers\n"
            "   R - Return to main menu\n"
            "   D - Delete" << endl;
}

//used later for the name


//Does the additional options for contacts, we pass contact with pointers to change actual vector
//This entire function does a redundant contact pointer check, I did this back in main but I didn't want to break anything
//so I just left it in, but to optimize it you can remote the vector<int> temp, and the findContactByName function
void evaluateChoice3(char choice, ContactList & contactList, Contact *contact){;
    string input;

    //if A, edit address
    if (choice == 'A'){
        cout << "Enter a new address" << endl;
        vector<string> address; //create a new vector to store address, and we assume its in correct format
        cin.ignore();
        string line;
        while (getline(cin, line)){
            if (line == ""){
                break;
            }
            address.push_back(line);
        }


        cout << "Address updated" << endl;
    }
    //sets DOB even though this isn't checked in tester, no way of knowing if formatting is right
    else if (choice == 'B'){
        string currentDOB = contact->getDateOfBirth();
        cout << "Current date of birth:" << endl;
        cout << currentDOB << endl << endl;
        cout << "Enter new date of birth or C to cancel:" << endl;
        cin >> input;
        if (input == "C") {
            return;
        } else {
            contact->setDateOfBirth(input);
            cout << "Date of birth updated:" << endl;
            cout << contact->getDateOfBirth() << endl;
        }
    }

    //sets email to something different
    else if (choice == 'E'){
        string searchTerm = contact->getName();
        vector<int> temp = contactList.findContactsByName(searchTerm);

        string currentEmail = contact->getEmail();
        cout << "Current email:" << endl;
        cout << currentEmail << endl << endl;
        cout << "Enter new email or C to cancel:" << endl;
        cin >> input;

        if (input == "C") return;

        else {
            contact->setEmail(input);
            cout << "Email updated:" << endl;
            cout << contact->getEmail() << endl;
        }
    }
    //Also not in tester but changes names
    else if (choice == 'N'){
        //uses a vector to get the name and then sets it with setFirstName and setLastName
        string currentName = contact->getName();
        cout << "Current name:" << endl;
        cout << currentName << endl << endl;
        cout << "Enter new name or C to cancel:" << endl;
        cin >> input;
        if (input == "C") return;
        else {
            //Same code as address
            vector<string> name; //create a new vector to store address, and we assume its in correct format
            cin.ignore();
            string line;
            while (getline(cin, line)){
                if (line == ""){
                    break;
                }
                name.push_back(line);
            }
            contact->setFirstName(name[0]);
            contact->setLastName(name[1]);
            cout << "Name updated:" << endl;
            cout << contact->getName() << endl;
        }
    }

    //Adds and deletes phone numbers
    else if (choice == 'P'){
        vector<string> numbers = contact->getPhoneNumbers();
        //Does check if its plural or not
        if (numbers.size() > 1)
            cout << "Found " << contact->getPhoneNumbers().size() << " phone numbers" << endl;
        else if (numbers.size() == 1)
            cout << "Found " << contact->getPhoneNumbers().size() << " phone number" << endl;
         for (int i = 0; i < contact->getPhoneNumbers().size(); i++){
              cout << i + 1 << ". " << contact->getPhoneNumbers()[i] << endl;
         }
         cout << "Enter an option: " << endl;
         cout << "   A - Add a phone number\n"
                 "   R - Return to main menu\n"
                 "   or list number to delete" << endl;
         char choice;
         cin >> choice;
         if (choice == 'A' || choice == 'a'){
             cout << "Enter the letter for the phone number type: \n"
                     "C(ell), W(ork) or H(ome)" << endl;
             char choice2;
             cin >> choice2;
             cout << "Enter the phone number: " << endl;
             string phoneNumber;
             cin >> phoneNumber;
             cout << contact->addPhone(choice2, phoneNumber) << endl; //function to add phone number and type
         }
         else if (isdigit(choice)){
             cout << "Are you sure you want to delete phone:  " << numbers[choice - '0' - 1] << "? Enter 'Y' to confirm." << endl;
                char choice2;
                cin >> choice2;
                if (choice2 == 'Y' || choice2 == 'y'){
                    cout << contact->deletePhone(choice - '0' - 1); //to make a char into a number we use '0' and - 1 as it's an array but we start at 1

                }
         }
         else if (choice == 'R'){
             return;
         }
         else {
             cout << "Invalid option" << endl;
         }
    }
    //returns to main menu
    else if (choice == 'R'){
        return;
    }

    //deletes contact. We do this within the contactlist class not with the contact itself
    else if (choice == 'D') {
        string searchTerm = contact->getName();
        vector<int> temp = contactList.findContactsByName(searchTerm);
        cout << "Are you sure you want to delete contact " << contact->getName() << "? Enter 'Y' to confirm." << endl;;
        char choice;
        cin >> choice;
        if (choice == 'Y' || choice == 'y') cout << contactList.deleteContact(temp[0]) << endl;
        return;
    }
}

int main() {
    ContactList contactList;
    //Keeps going until exit
    while(true){
        cout << endl;
        cout << "********************************************\n"
                "Main Menu\n"
                "\n"
                "Enter the letter for the desired menu option:\n"
                "   C - Get count\n"
                "   L - Load contacts from file\n"
                "   S - Search contacts\n"
                "   P - Print contacts\n"
                "   X - Exit\n";
         char choice;
        cin >> choice;
        choice = toupper(choice);
        if(choice == 'C') {
            cout << "There are " << contactList.getCount() << " contacts"; //counts the number of contacts
        }
        //loads contacts from filename
        else if (choice == 'L'){
            string filename;
            cout << "Enter a filename" << endl;
            cin >> filename;
            cout << contactList.loadContactsFromFile(filename);
            cout << endl;
        }
        //Searches based on term given
        else if (choice == 'S'){
            string searchTerm;
            cout << "Enter a search term " << endl;
            cin >> searchTerm;
            vector<int> positions = contactList.findContactsByName(searchTerm); //We need a vector of positions to traverse the contact list
            vector<Contact> contacts;
            for (int position : positions){
                 contacts.push_back(*contactList.getContact(position)); //This gives us pointers of each contact that we push into our own vector named Contacts
            }
            if (contacts.size() == 1) cout << "Found " << contacts.size() << " result" << endl;
            else if (contacts.size() > 1) cout << "Found " << contacts.size() << " results" << endl;
            else cout << "No results found" << endl;
            int counter = 1;
            for (auto & contact : contacts){
                cout << counter << ". " << contact.getName() << endl; //Prints contact names, counter to give the number of contacts found
                counter++;
            }
            cout << endl;

            //second part of finding contacts, actually printing information
            if (!contacts.empty()) {
                cout << "Enter an option:\n"
                        "   P - Print contacts\n"
                        "   or a Contact number to view/edit\n"
                        "   R - Return to main menu\n";
                string choice2;
                cin >> choice2;

                //this small code was implemented to handle double digit numbers
                bool is_digit = true;
                for (char c : choice2) {
                    if (!isdigit(c)) {
                        is_digit = false;
                        break;
                    }
                }

                //Checks for numbers and if so it will do contact searches instead of leaving or printing all information
                if (is_digit) {
                    //use contact.getAsString() to print contact
                    cout << contacts[stoi (choice2) - 1].getAsString() << endl;

                    //This goes to the contact options for individual contacts
                    while (true) {
                        contactsAdditionalOptions();
                        char choice3;
                        cin >> choice3;
                        choice3 = toupper(choice3);
                        if (choice3 == 'R') {
                            break;
                        }
                        //This part sends a pointer of the contact to actually modify the contact within the vector, this part is done again within the actual evaluateChoice function
                        //But didn't want to break anything so it was left in
                        vector<int> idx = contactList.findContactsByName(contacts[stoi(choice2) - 1].getName());
                        Contact* contactpass = contactList.getContact(idx[0]);
                        evaluateChoice3(choice3, contactList, contactpass);
                        break;
                    }
                }
                //basic print contacts function
                else if (choice2 == "P" || choice2 == "p"){
                    contactList.printContacts(positions);
                }
                //retunrs
                else if (choice2 == "R" || choice2 == "r"){
                    continue;
                }
                //safety case
                else{
                    cout << "Invalid choice";
                    continue;
                }
            }
        }
        //prints all contacts found in list
        else if (choice == 'P'){
            contactList.printContacts();
        }
        //exits
        else if (choice == 'X'){
            return 0;
        }
        //safety case
        else {
            cout << "Invalid choice";
        }
    }
}
