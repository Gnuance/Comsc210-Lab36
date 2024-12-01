//  Lab 36: Modify BST to work with records instead of ints. See README.md

#include <iostream>
#include <fstream>
#include <chrono> // For fun to test program speed
#include "StringBinaryTree.h"
using namespace std;
using namespace std::chrono; // So chrono:: doesn't have to be used over and over again

int main_menu();                      // Outputs prompt and collects user selection
bool isValidOption(string, int, int); // Helper function to validate user input
void AddNode(StringBinaryTree &);     // Adds a node to passed binary tree
void DeleteNode(StringBinaryTree &);  // Deletes a node ofthe  passed binary tree
void SearchNode(StringBinaryTree &);  // Searches for a node from passed binary tree
void ModifyNode(StringBinaryTree &);  // Modifies a node of the passed binary tree

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
    // Variable for user selection for main menu
    int userSelectedOption;

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

    // Prompt user for selection and input
    // User selection 0 is the program exit code
    do
    {
        userSelectedOption = main_menu();
        switch (userSelectedOption)
        {
        case 1:
            // Takes user to function to add a given text string
            AddNode(bTree);
            break;
        case 2:
            // Takes user to function to delete a given text string within tree
            DeleteNode(bTree);
            break;
        case 3:
            // Takes user to function to search for a given text string within tree
            SearchNode(bTree);
            break;
        case 4:
            // Takes user to function to modify a given text string
            ModifyNode(bTree);
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
        cout << "\nBST: Management Menu" << "\n"
             << "[1] Add node" << "\n"
             << "[2] Delete node" << "\n"
             << "[3] Search for string" << "\n"
             << "[4] Modify node" << "\n"
             << "[0] Quit" << "\n"
             << "Choice --> ";
        getline(cin, userInput); // get user input as string and test
        cout << endl;
    } while (!isValidOption(userInput, 0, 4));

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

// Adds a node to passed binary tree
void AddNode(StringBinaryTree &tree){
    string userInput = "";
    cout << "Please enter string to add to tree (Leave empty to cancel operation): ";

} 
void DeleteNode(StringBinaryTree &); // Deletes a node ofthe  passed binary tree
void SearchNode(StringBinaryTree &); // Searches for a node from passed binary tree
void ModifyNode(StringBinaryTree &); // Modifies a node of the passed binary tree
