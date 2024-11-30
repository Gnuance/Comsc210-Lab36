//  Lab 36: Modify BST to work with records instead of ints. See README.md

#include <iostream>
#include <fstream>
#include <chrono> // For fun to test program speed
#include "StringBinaryTree.h"
using namespace std;
using namespace std::chrono; // So chrono:: doesn't have to be used over and over again

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

    cout << "Total lines: " << lineCount << "\nTotal time: " << elapsed.count() << " ms" << endl;

    return 0;
}