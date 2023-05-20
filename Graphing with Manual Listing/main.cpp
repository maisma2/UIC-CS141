#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

//************************** Node *************************
//This class will be used for the entire linked list
class Node {
public:
    int data;
    Node *next;

    Node(int data) : data(data), next(nullptr) {}
};

//**************************Linked List************************
class LinkedList {
public:
    Node *head;

    LinkedList() : head(nullptr) {} //Default constructor

    LinkedList(const LinkedList &other) : head(nullptr) { //Deep copy constructor, to remove empty nodes later on
        Node *current = other.head;
        while (current) {
            add(current->data);
            current = current->next;
        }
    }

    LinkedList &operator=(const LinkedList &other) { //Assignment operator, to reassign values
        if (this == &other) {
            return *this;
        }

        // Clear the current list, this is causing duplicates in output file
        Node *current = head;
        while (current) {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;

        // Assign the new values to current object without any accidental value removal
        current = other.head;
        while (current) {
            add(current->data);
            current = current->next;
        }

        return *this;
    }

    ~LinkedList() { //destructor, otherwise the program gets too heavy when doing Youtube or RoadNet-CA
        Node *current = head;
        while (current) {
            Node *nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void add(int value) { //adds to linked list, it first goes to contains() function to check if it already exists
        Node *newNode = new Node(value);

        if (head == nullptr || head->data > value) { //checks if list is empty or the value is less
            newNode->next = head;
            head = newNode;
        } else { //adds the value to the correct position in the list, since we have to sort as well
            Node *current = head;
            while (current->next != nullptr && current->next->data < value) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    bool contains(int value) { //checks if value is already in linked list
        Node *current = head;
        while (current) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    int size() const { //used in dumping information to file, const because of emptyNodes function
        int count = 0;
        Node *current = head;
        while (current) {
            count++;
            current = current->next;
        }
        return count;
    }
};


//************************** Graph ****************************

class Graph {
public:
    vector<LinkedList> adjList;
    vector<int> nodeIndices; //This to keep track of nodes
    int maxDegree = 0;

    void addNeighbor(int nodeId, int neighborId) { //adds neighbor to linked list vector, most of the work is done in the linked list class
        if (!adjList[nodeId].contains(neighborId)) { //adds in neighbor information if it doesn't already exist
            adjList[nodeId].add(neighborId);
        }
        if (!adjList[neighborId].contains(nodeId)) { //adds in node information if it doesn't exist, this deals with duplicates as well
            adjList[neighborId].add(nodeId);
        }
    }
    void initializeGraph(int numNodes) { //initializes graph with max nodes, this is to allocate memory from the start, works with maxNodeID
        adjList.resize(numNodes);
    }

    void loadGraph(const string &edgeListFileName, const string &dst_path) { //loads graph from txt file, added a method to delete the file if it already exists
                                                                             // so that the file is not appended and we know the latest version ran
        ifstream file(edgeListFileName);
        if (remove(dst_path.c_str()) == 0) {
            cout << "File " << dst_path << " found, it was deleted. File will be recreated at end of process" << endl;
        }
        int a, b;
        while (file >> a >> b) { //adds raw data to addNeighbor function
            while (a >= adjList.size() || b >= adjList.size()) {
                adjList.emplace_back();
            }
            addNeighbor(a, b);
        }
        file.close();
    }
    void removeEmptyNodes() { //since the linked list goes up to the max node id, this function removes the empty nodes to print correctly but uses
                                // a new linked list which then replaces the old one.
        vector<LinkedList> newAdjList;
        nodeIndices.clear(); // clears nodeIndices vector to prevent any old data being used

        for (int i = 0; i < adjList.size(); i++) { // changed from range based loop to normal loop
            if (adjList[i].size() > 0) {
                newAdjList.push_back(adjList[i]);
                nodeIndices.push_back(i);
            }
        }

        adjList = newAdjList;
    }

    void dumpGraph(const string &adjListFileName) { //ofstream into creating a new txt file
        ofstream file(adjListFileName);
        removeEmptyNodes();
        for (int i = 0; i < adjList.size(); i++) {
            file << nodeIndices[i]  << ":"; //prints the original node id
            Node *current = adjList[i].head;
            while (current) {
                file << " " << current->data; //prints all the neighbors attached to that node, by traversing the linked list
                current = current->next;
            }
            file << endl;
        }
        file.close();
    }

    void printGraphStats() { //prints stats into console
        removeEmptyNodes();
        int numNodes = adjList.size();
        int numEdges = 0;
        for (int i = 0; i < numNodes; i++) {
            int degree = adjList[i].size();
            numEdges += degree;
            maxDegree = max(maxDegree, degree); //max is an algo function that returns the max of two values
        }
        numEdges /= 2; //removes duplicates

        cout << "Number of nodes: " << numNodes << endl;
        cout << "Number of edges: " << numEdges << endl;
        cout << "Maximum degree: " << maxDegree << endl;
    }
};
int getMaxNodeId(const string &filePath) { //used this function after looking up how to handle large input files for linked lists
                                            // The program would crash locally without this for runtime issues.
    ifstream file(filePath);
    int maxNodeId = 0;
    int a, b;

    while (file >> a >> b) {
        maxNodeId = max(maxNodeId, max(a, b));
    }

    file.close();
    return maxNodeId;
}

void run(const string &src_path, const string &dst_path) {
    Graph graph; //makes object
    int maxNodeId = getMaxNodeId(src_path); //gets max nodes in a file
    graph.initializeGraph(maxNodeId + 1); //initializes graph with max nodes, this is to allocate memory from the start, works with maxNodeID
    graph.loadGraph(src_path, dst_path); //creates vector and adds data
    graph.dumpGraph(dst_path); //ofstream to file
    graph.printGraphStats(); //prints stats
}

int main() {
    vector<string> src_paths;
    vector<string> dst_paths;
    src_paths.push_back("givenGraph.txt");
    src_paths.push_back("toy.txt");
    src_paths.push_back("roadNet-CA.txt");
    src_paths.push_back("karate.txt");
    src_paths.push_back("youtube.txt");
    src_paths.push_back("graphCreation.txt");

    dst_paths.push_back("givenGraph_adj.txt");
    dst_paths.push_back("toy_adj.txt");
    dst_paths.push_back("roadNet-CA_adj.txt");
    dst_paths.push_back("karate_adj.txt");
    dst_paths.push_back("youtube_adj.txt");
    dst_paths.push_back("graphCreation_adj.txt");


    for (int i = 0; i < 5; i ++){
        run(src_paths[i], dst_paths[i]);
        cout << endl;
    }
    return 0;
}