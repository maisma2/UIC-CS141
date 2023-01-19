/**************************
 *
 * HEADER
 *
 * ************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <list>
#include <algorithm>

using namespace std;

//************************** Node *************************

class Node;

//************************** Graph ****************************
class Graph {
public:
    int maxDegree = 0;
    //add the node with neighborId as the neighbor of nodeId
    void addNeighbor(int nodeId, int neighborId, list<int> *list){
        list[nodeId].push_back(neighborId);
        list[neighborId].push_back(nodeId);

    }

    //reads the edge list from file and creates the adjacency list data structure
    void loadGraph(string edgeListFileName, string adjListFileName){
        //Setting basic variables
        ifstream file;
        file.open(edgeListFileName);
        vector<vector<int>> edgeList;
        vector<int> nodeCounter;
        nodeCounter.clear();
        edgeList.clear();


        //read the edge list from file
        while(file.good()){
            string line;
            getline(file, line);
            if (line == "")break;
            vector<int> tempLine;
            stringstream ss(line);
            int a,b;
            ss >> a >> b;
            tempLine.push_back(a);
            tempLine.push_back(b);
            edgeList.push_back(tempLine);
        }
        file.close();

        //We remove all duplicates from edgeList
        sort(edgeList.begin(), edgeList.end());
        edgeList.erase(unique(edgeList.begin(), edgeList.end()), edgeList.end());
        l = new list<int> [edgeList.size()];

        //Place all elements in edgeList into nodeCounter
        for(int i = 0; i < edgeList.size(); i++){
            nodeCounter.push_back(edgeList[i][0]);
            nodeCounter.push_back(edgeList[i][1]);
        }
        //Remove all duplicate elements from nodeCounter, this is so we can get a list of the nodes at the beginning of the file
        sort(nodeCounter.begin(), nodeCounter.end());
        nodeCounter.erase(unique(nodeCounter.begin(), nodeCounter.end()), nodeCounter.end());
        for (int i = 0; i < edgeList.size(); i++){
            cout << edgeList[i][0] << " " << edgeList[i][1] << endl;
        }

        //Now we add neighbors with our ascending nodes list
        for (int i = 0; i < edgeList.size(); i++){
            addNeighbor(edgeList[i][0], edgeList[i][1], l);
        }

        //Send out to different functions, one for file print other for console print
        dumpGraph(adjListFileName, nodeCounter.size());
        printGraphInfo(nodeCounter.size(), edgeList.size());

    }

    //writes the adjacency list into the file
    void dumpGraph(string adjListFileName, int x){
        //creates the file variables, degreeCounter used for maxDegree finding
        vector<int> degreeCounter;
        ofstream file;
        file.open(adjListFileName);

        //Output this to a file
        for (int i = 0; i < x+1; i++){
            int counter = 0;
            if(l[i].empty()) continue;
            file << i << ": ";
            //remove duplicates from l[i]
            l[i].sort();
            l[i].unique();
            //outs to the file of the actual neighbors of a node
            for (auto y:l[i]){
                //if end of list, don't add a space
                if(y == l[i].back()){
                    file << y;
                }
                else{
                    file << y << " ";
                }
                counter++;
            }
            //This is maxDegree use
            degreeCounter.push_back(counter);
            file << endl;
        }
        file.close();
        //Find the largest degree and push it out to variable
        std::sort(degreeCounter.begin(), degreeCounter.end());
        maxDegree = degreeCounter.back();

    }

    //Prints number of nodes, number of edges, and maximum degree on terminal
    void printGraphInfo(int numofNodes, int edges){
        cout << "Number of nodes: " << numofNodes << endl;
        cout << "Number of edges: " << edges << endl;
        cout << "Maximum degree: " << maxDegree << endl;
    }

    //returns the number of neighbor (degree) of a node, unused in this program
    int getNumNeighbors(int nodeId) {
        return 2;
    }

    //returns the number of nodes in the graph, unused in this program
    int getNumVertices(){
        return 3;
    }

private:
    list<int> *l = new list<int>; //Linked List for the adjacency list

};


void run(string edgeListFileName, string adjListFileName) {
    //Create graph object to start each file
    Graph graph;
    //First thing is running edgeListFileName
    graph.loadGraph(edgeListFileName, adjListFileName);
}

//*****************************************************************************


// The main will be removed for testing, do not add any code in the main function
int main() {
    //Change the filenames according to your local path.

        string edgeListFileName("toy.txt");
        string adjListFileName("toy_adj.txt");
        run(edgeListFileName, adjListFileName);



    return 0;
}

