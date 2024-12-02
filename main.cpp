//  Lab 36: Modify BST to work with records instead of ints. See README.md

#include <iostream>
#include <fstream>
#include <chrono>    // For fun to test program speed
#include <algorithm> // transform
#include <cctype>    // tolower
#include <string>
#include "StringBinaryTree.h"
using namespace std;
using namespace std::chrono; // So chrono:: doesn't have to be used over and over again

int main_menu();                      // Outputs prompt and collects user selection
bool isValidOption(string, int, int); // Helper function to validate user input
char IsYesNo(string);                 // Helper function to validate user input
void AddNode(StringBinaryTree &);     // Adds a node to passed binary tree
void RemoveNode(StringBinaryTree &);  // Deletes a node ofthe  passed binary tree
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
            RemoveNode(bTree);
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

// Helper function to return validated yes/no option from user
char IsYesNo(string userInput)
{
    // Transform to lower to compare regardless of case
    string input = userInput;
    transform(input.begin(), input.end(), input.begin(),
              [](unsigned char c)
              { return tolower(c); });
    // Validate user input for yes, y
    if (input == "yes" || input == "y")
    {
        return 'y';
    }
    if (input == "no" || input == "n")
    {
        return 'n';
    }
    return '0'; // Return 0 if no option selected
}

// Adds a node to passed binary tree
void AddNode(StringBinaryTree &tree)
{
    string userInput = "";
    cout << "Please enter string to add to tree (Leave empty to cancel operation): ";
    getline(cin, userInput);
    // Guard against empty string and return
    if (userInput == "")
    {
        cout << "Operation Cancelled." << endl;
        return;
    }
    // Insert user value into tree
    tree.insertNode(userInput);
    cout << "String: \"" << userInput << "\" inserted into tree." << endl;
}

// Remove a node selected by user within the passed binary tree
void RemoveNode(StringBinaryTree &tree)
{
    string userInput = "";
    cout << "Please enter string to remove from tree (Leave empty to cancel operation): ";
    getline(cin, userInput);
    // Guard against empty string and return
    if (userInput == "")
    {
        cout << "Operation Cancelled." << endl;
        return;
    }
    // Check if node exists and remove
    if (!tree.searchNode(userInput))
    {
        cout << "\"" << userInput << "\" not found. Operation Cancelled." << endl;
        return;
    }

    tree.remove(userInput);
    cout << "String: \"" << userInput << "\" removed from tree." << endl;
}

// Searches for a node selected by user within the passed binary tree
void SearchNode(StringBinaryTree &tree)
{
    string userInput = "";
    cout << "Please enter string to search for in tree (Leave empty to cancel operation): ";
    getline(cin, userInput);
    // Guard against empty string and return
    if (userInput == "")
    {
        cout << "Operation Cancelled." << endl;
        return;
    }
    // Check if node exists and remove
    if (!tree.searchNode(userInput))
    {
        cout << "\"" << userInput << "\" NOT found in tree." << endl;
    }
    else
    {
        cout << "\"" << userInput << "\" FOUND in tree." << endl;
    }
}

// Allows user to modify a node selected by user within the passed binary tree
void ModifyNode(StringBinaryTree &tree)
{
    string userInput = "";
    string userOption = "";
    string newUserInput = "";
    cout << "Please enter string to modify in tree (Leave empty to cancel operation): ";
    getline(cin, userInput);
    // Guard against empty string and return
    if (userInput == "")
    {
        cout << "Operation Cancelled." << endl;
        return;
    }

    // Check if node even exists
    if (!tree.searchNode(userInput))
    {
        do
        {
            cout << "\"" << userInput << "\" NOT found in tree. Would you like to add it (y/n): ";
            getline(cin, userOption);
        } while (IsYesNo(userOption) == 0);

        // If user doesn't want to add element into tree:
        if (IsYesNo(userOption) == 'n')
        {
            cout << "\"" << userInput << "\" NOT inserted into tree.";
            return;
        }
        // Insert user value into tree
        tree.insertNode(userInput);
        cout << "String: \"" << userInput << "\" inserted into tree." << endl;
    }
    else // Node exists, allow user to modify
    {
        cout << "\"" << userInput << "\" FOUND in tree. Please enter new value (Leave empty to cancel operation):" << endl;
        getline(cin, newUserInput);
        // Guard against empty string and return
        if (newUserInput == "")
        {
            cout << "Operation Cancelled." << endl;
            return;
        }
        // User has given new value, delete old and insert new into tree
        tree.remove(userInput);
        tree.insertNode(newUserInput);
        cout << "\"" << userInput << "\" REMOVED from tree. \"" << newUserInput << "\" added." << endl;
    }
}
