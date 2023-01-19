/**********************************************************
 * HEADER
 **********************************************************/

#include <iostream>
#include <cctype>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
using namespace std;

/********************************************** Structs for object Vectors and Function Declarations *******************************/
void splitString(string line, char delimiter, vector<string>& items); // Splits stirngs into vectors elements of strings
bool checkIfStringContainsAllVectorElements(string target, vector<string>& items); // Makes sure every element in a vector<string> is present in a target string
string toLowerCase(string s); // Lowercases the string
void movieSearchActors(string& tConsts, string& principalsFile, string &actorsFile); // Searches for the actors in a movie and is mainly called from the MovieVectorSearch
void actorSearchMovies(string &nmConst, string &principalsFile, string &moviesFile); // Same thing as above but for actors given a tconst/nmconst and is used mainly from ActorVectorSearch
struct movieTitles { // struct titleRecord
    string tconst;
    string primaryTitle;
    string originalTitle;
    string startYear;
    string genres;
};
struct actorNames { // struct nameRecord
    string nameId;
    string primaryName;
    string birthYear;
    string deathYear;
    string primaryProfession;
};
struct principalNames { // struct principalRecord
    string tconst;
    string nameId;
    string characters;
   // string category;
};
/**********************************************************Vector Creations**********************************************************/

vector<movieTitles> movieTitlesVector(const string& movieTitles){
        ifstream file;
        file.open(movieTitles); //opens file
        vector<struct movieTitles> titles; //makes a struct vector named title
        titles.clear(); // safety feature in the event vector is filled with garbage.

        while (file.good()) { // keeps going until there are no lines remaining, hardcoded to stop at the end of movie titles in the event fileGood fails
            string line = "";
            getline(file, line);
            if (line == "") continue; //Last line of file is a blank line and breaks splitString function.
            struct movieTitles obj; // Makes a temporary obj placeholder for each loop
            vector<string> lineItems; // Makes a temporary vector for each line item
            splitString(line, '\t', lineItems); // Uses the function to seperate each item
            obj.tconst = lineItems[0]; // for the titleId
            obj.primaryTitle = lineItems[2]; // for the title Name
            obj.originalTitle = lineItems[3]; // for the original title
            obj.startYear = lineItems[5];
            obj.genres = lineItems[8]; //the string of genres
            titles.push_back(obj);
        }
        //titles.erase(titles.begin());// The only concern is the first header line which we can remove now
        file.close();
        return titles;
};
vector<principalNames> principalVector(const string& principalsFile){
        ifstream file;
        file.open(principalsFile); //opens file
        vector<struct principalNames> principals; //makes a struct vector named title
        principals.clear(); // safety feature in the event vector is filled with garbage.
        while (file.good()){ // making sure it doesn't try reading the last blank line
            string line = "";
            getline(file, line);
            if (line == "") continue; //Last line of file is a blank line and breaks splitString function.
            struct principalNames obj; // Makes a temporary obj placeholder for each loop
            vector<string> lineItems; // Makes a temporary vector for each line item
            splitString(line, '\t', lineItems); // Uses the function to seperate each line
            obj.tconst = lineItems[0]; // for the titleId
            obj.nameId = lineItems[2]; // for the nameId
            obj.characters = lineItems[5]; // for the characters
            principals.push_back(obj);
        }
        //principals.erase(principals.begin()); // removes the header line
        file.close();
        return principals;
};
vector<actorNames> actorNames(const string& namesFile){
    ifstream file;
    file.open(namesFile); //opens file
    vector<struct actorNames> names; //makes a struct vector named title
    names.clear(); // safety feature in the event vector is filled with garbage.
    while (file.good()) {
        string line = "";
        getline(file, line);
        if (line == "") continue; //Last line of file is a blank line and breaks splitString function.
        struct actorNames obj;
        vector<string> lineItems;
        splitString(line, '\t', lineItems); // Uses the function to separate each line
        obj.nameId = lineItems[0]; // for the nameId
        obj.primaryName = lineItems[1]; // for the name
        obj.birthYear = lineItems[2]; // for the birth year
        obj.deathYear = lineItems[3]; // for the death year
        obj.primaryProfession = lineItems[4]; // for the profession
        names.push_back(obj);
    }
    //names.erase(names.begin()); // removes the header line
    file.close();
    return names;
};

/***********************************************************************************************************/
void movieTitlesSearch(const string& fileName, string& sPhrase, string& principalsFile, string& NamesFile) {
    vector<movieTitles> titles = movieTitlesVector(fileName);
    vector<string> target;
    splitString(sPhrase, '+', target); // splits the search phrase with the +
    vector<struct movieTitles> foundObjects;
    sPhrase = toLowerCase(sPhrase);
    foundObjects.clear();

    for (auto & title : titles) {
        string lowered = toLowerCase(title.primaryTitle);
        string origLowered = toLowerCase(title.originalTitle);
        if(checkIfStringContainsAllVectorElements(lowered, target)) {
            foundObjects.push_back(title);
        }
        else if (checkIfStringContainsAllVectorElements(origLowered, target)) { // Using piazza resources to check both primary and original title
            foundObjects.push_back(title);
        }
    }
    // Replacing commas for spaces out of the genres
    for (auto & foundObject : foundObjects) {
        replace(foundObject.genres.begin(), foundObject.genres.end(), ',', ' ');
    }

    // Now once foundObjects is filled with the correct titles we can now start to print them out
    if (foundObjects.size() == 0) {
        cout << "No match found!" << endl;
    } else {
        for (int i = 0; i < foundObjects.size(); i++) { // Prints out using format given
            cout << i << ":" << endl
                 << "Title: " << foundObjects[i].primaryTitle << endl
                 << "Year: " << foundObjects[i].startYear << endl
                 << "Genre: " << foundObjects[i].genres << endl
                 << "---------------" << endl;
        }
        int continueSearch;
        cout << "Select a movie to see its actors/actresses (-1 to go back to the previous menu): ";
        cin >> continueSearch;
        if (!cin.fail() && continueSearch >= 0 && continueSearch < foundObjects.size()) { // This loop is used if you want to see the actors/actresses of a movie and if you want to re-search something
            movieSearchActors(foundObjects[continueSearch].tconst, principalsFile, NamesFile);
            string searchPhrase;
            cout << "Enter search phrase (type done to go back to previous menu): " << endl;
            cin >> searchPhrase;
            string newPhrase = toLowerCase(searchPhrase);
            if (newPhrase == "done") return;
            else movieTitlesSearch(fileName, newPhrase, principalsFile, NamesFile); // goes back into movie searching function for different title
        }
    }
}
void movieSearchActors(string& tConsts, string &principalsFile, string& NamesFile){ // This function is used to search for the actors/actresses of a movie given the index previous, the index is attached to a tconst
    vector<principalNames> principals = principalVector(principalsFile);
    vector<struct principalNames> foundPrincipalObjects;
    for (int i = 0; i < principals.size(); i++){
        if ((principals[i].tconst == tConsts) && principals[i].characters != "\\N")
            foundPrincipalObjects.push_back(principals[i]);
    }
    vector<struct actorNames> names = actorNames(NamesFile); // We now have the names of the actors/actresses character names from Principal vector, but now we need real names from this vector
    vector<struct actorNames> foundActorObjects;
    for (int i = 0; i < names.size(); i++){ // Two loops to compare both vector struct objects
        for (int j = 0; j < foundPrincipalObjects.size(); j++){
            if (names[i].nameId == foundPrincipalObjects[j].nameId)
                foundActorObjects.push_back(names[i]);
        }
    }
    for (int i = 0; i < foundActorObjects.size(); i++){ // Format to print it out
        cout << foundActorObjects[i].primaryName << " " << foundPrincipalObjects[i].characters << endl;
    }


}

bool checkIfStringContainsAllVectorElements(string target, vector<string>& items) { // This just compares all vector elements (string) to a target string if every element matches its true
    int count = 0;
    for (int i = 0; i < items.size(); i++) {
        if (target.find(items[i]) != string::npos) {
            count++;
        }
    }
    if (count == items.size()) {
        return true;
    } else {
        return false;
    }
}
void actorNameSearch(string namesFile, string searchPhrase, string titlesFile, string principalsFile){ // This is nearly a copy and paste from the movie search
    vector<struct actorNames> names = actorNames(namesFile);
    vector<string> target;
    splitString(searchPhrase, '+', target); // splits the search phrase with the +
    vector<struct actorNames> foundObjects;
    foundObjects.clear(); // Safety feature

    for (int i = 0; i < names.size(); i++){
        string lowered = toLowerCase(names[i].primaryName); // This function lowers the string to make it easier to compare
        if(checkIfStringContainsAllVectorElements(lowered, target)) { // Goes back to target string and element compare
            foundObjects.push_back(names[i]);
        }
    }
    vector<string> primaryProf;
    splitString(foundObjects[0].primaryProfession, ',', primaryProf); // This makes the primary profession string spaced out
    if(foundObjects.size() == 0) cout << "No match found!" << endl;
    else { // this prints out found objects
        for (int i = 0; i < foundObjects.size(); i++){ // Previously I used replace function this is more brute forced
            cout << i << ":" << endl << foundObjects[i].primaryName << endl;
            for (int i = 0; i < primaryProf.size(); i++){
                cout << primaryProf[i] <<  ", ";
            }
            cout << endl;
            cout << "(" << foundObjects[i].birthYear << "-" << foundObjects[i].deathYear << ")" << endl
                 << "----------------" << endl;
        }
        // Starting from here it gives an actors entire list of movies by going into the names and principals file and also gives the ability to restart the search
        string choice;
        cout << "Select an actor/actress to see movies (-1 to go back to the previous menu): " << endl;
        cin >> choice;
        if (!cin.fail() && stoi(choice) >= 0 && stoi(choice) < foundObjects.size()){
            actorSearchMovies(foundObjects[stoi(choice)].nameId, titlesFile, principalsFile);
            string searchPhrase;
            cout << "Enter search phrase (type done to go back to previous memu): " << endl;
            cin >> searchPhrase;
            if (searchPhrase == "done") return;
            else actorNameSearch(namesFile, searchPhrase, titlesFile, principalsFile);
        }

    }
}
void actorSearchMovies(string &nameId, string& titlesFile, string&principalsFile){ // This function just compares nameids between vectors to match a nmId to a name and tconst values
    vector<struct principalNames> principals = principalVector(principalsFile);
    vector<struct principalNames> foundPrincipalObjects; // PLaceholder for struct objects that match the nameId
    for (int i = 0; i < principals.size(); i++){
        if (principals[i].nameId == nameId)
            foundPrincipalObjects.push_back(principals[i]);
    }
    vector<struct movieTitles> titles = movieTitlesVector(titlesFile);
    vector<struct movieTitles> foundMovieObjects;
    for (int i = 0; i < titles.size(); i++){ // Same thing as movie searching
        for (int j = 0; j < foundPrincipalObjects.size(); j++){
            if (titles[i].tconst == foundPrincipalObjects[j].tconst)
                foundMovieObjects.push_back(titles[i]);
        }
    }
    for (int i = 0; i < foundMovieObjects.size(); i++){ // Format to print out the found objects
        cout << foundMovieObjects[i].primaryTitle << " " << foundMovieObjects[i].startYear << " " << foundPrincipalObjects[i].characters << endl;
    }
}
/*********************************************** Helper functions ***************************************/

//The splitString function takes a line and split it on the delimiter and push the parts into items
void splitString(string line, char delimiter, vector<string>& items ) {
    stringstream s_stream(line);
    while (s_stream.good()) {
        string item;
        getline(s_stream, item, delimiter);
        items.push_back(item);
    }
}
void startFile(){
    cout << "Select a menu option:" << endl
    << "   1. Search for movies" << endl
    << "   2. Search for actors/actresses" << endl
    << "   3. Exit" << endl
    << "Your choice -->" << endl;
}
string toLowerCase(string s) { // Function to make string lowercase
    for (int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}
/**********************************************************************************************************/

int run(string titlesFile, string namesFile, string principalsFile) {
    int menuChoice = 0;
    string searchPhrase = "";
        do {
            startFile();
            cin >> menuChoice;
            if (cin.fail()) break;
            if (menuChoice == 1){
                cout << "Enter search phrase: " << endl;
                cin >> searchPhrase;
                string newPhrase = toLowerCase(searchPhrase);
                movieTitlesSearch(titlesFile, newPhrase, principalsFile, namesFile);
            }
            else if (menuChoice == 2){
                cout << "Enter search phrase: " << endl;
                cin >> searchPhrase;
                string newPhrase = toLowerCase(searchPhrase);
                actorNameSearch(namesFile, newPhrase, titlesFile, principalsFile);
            }
        }
        while (menuChoice != 3);

    return 0;
}

int main() {
    //Change these addresses according to your local machine
    string titlesFile =	"movie.titles.tsv";
    string namesFile = "movie.names.tsv";
    string principalsFile = "movie.principals.tsv";

    //DO NOT change the main function. The main function will be removed by the autograder
    run(titlesFile, namesFile, principalsFile);
    return 0;
}

