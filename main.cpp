//  Lab 36: Modify BST to work with records instead of ints. See README.md

#include <iostream>
#include <fstream>
#include <chrono> // For fun to test program speed
#include "StringBinaryTree.h"
using namespace std;
using namespace std::chrono; // So chrono:: doesn't have to be used over and over again

int main_menu();                      // outputs prompt and collects user selection
bool isValidOption(string, int, int); // helper function to validate user input

int main()
{
    // File to read from
    const string INPUT_FILE_NAME = "codes.txt";
    ifstream inputFile;
    string fileLine = "";
    size_t lineCount = 0;
    // Binary Tree
    StringBinaryTree bTree;
    // Timers to test program speed
    high_resolution_clock::time_point timerStart;
    high_resolution_clock::time_point timerEnd;
    duration<double, milli> elapsed;

    // Try opening file and output error to console if file is no good
    inputFile.open(INPUT_FILE_NAME);
    if (!inputFile)
    {
        throw runtime_error("Error opening file: " + INPUT_FILE_NAME);
    }
    else
    {
        timerStart = high_resolution_clock::now();
        // Get each line and store in BST
        while (getline(inputFile, fileLine))
        {
            bTree.insertNode(fileLine);
            lineCount++;
        }
        timerEnd = high_resolution_clock::now();
        elapsed = timerEnd - timerStart;

        // CLOSE THE F-ING FILE
        inputFile.close();
    }

    // prompt user for selection and input
    // user selection 5 is the program exit code
    int userSelectedOption;
    do
    {
        userSelectedOption = main_menu();
        switch (userSelectedOption)
        {
        case 1:
            // Prints adjacency list representation of graph
            graph.printGraph();
            break;
        case 2:
            // Breadth first search from node 0
            graph.BFS(startingNode);
            break;
        case 3:
            // Depth first search from node 0
            graph.DFS(startingNode);
            break;
        case 4:
            // STEP 4 -- Shortest paths through graph from node 0
            graph.printShortestPathsWithDetails(startingNode);
            break;
        case 5:
            // STEP 5 -- MST using Prim's Algorithm
            graph.primMST(startingNode);
            break;
        default:
            break;
        }
    } while (userSelectedOption != 0);

    cout << "Thank you for using the BST management tool" << endl;

    // cout << "Total lines: " << lineCount << "\nTotal time: " << elapsed.count() << " ms" << endl;

    return 0;
}

// main menu fuction for STEP 6
int main_menu()
{
    string userInput = "";

    do
    {
        // output prompt
        cout << "\nVPN: Network Menu" << "\n"
             << "[1] Display Bandwidth Summary" << "\n"
             << "[2] Default Proxy Map [BFS]" << "\n"
             << "[3] Test Network Nodes [DFS]" << "\n"
             << "[4] Display Minimum Bandwidth From Source" << "\n"
             << "[5] MST: Minimum Spanning Tree For Network" << "\n"
             << "[0] Quit" << "\n"
             << "Choice --> ";
        getline(cin, userInput); // get user input as string and test
        cout << endl;
    } while (!isValidOption(userInput, 0, 5));

    // if isValidOption passed, stoi(userInput) has already been tested and is safe
    return stoi(userInput);
}

// return t/f if userInput is a valid int between min and max
// helper function for main_menu and delete_goat
// WARNING: stoi() will convert a double to an int or any string following an int.
// Ex: stoi("2.9") will return 2 and so will stoi("2tGznso"), etc.
bool isValidOption(string userInput, int minOption, int maxOption)
{
    int selectedOption = 0;
    try
    {
        selectedOption = stoi(userInput);
    }
    catch (const std::exception &e)
    {
        cout << "Invalid input: Please enter a valid integer." << "\n\n";
        return false;
    }

    // if userInput is an int but outside expected range
    if (selectedOption < minOption || selectedOption > maxOption)
    {
        cout << "Invalid input: Please enter an integer between " << minOption << " and " << maxOption << "." << "\n\n";
        return false;
    }

    return true;
}