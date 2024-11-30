//  Lab 36: Modify BST to work with records instead of ints. See README.md

#include <iostream>
#include <fstream>
#include "StringBinaryTree.h"
using namespace std;

int main()
{
    // File to read from
    const string INPUT_FILE_NAME = "codes.txt";
    ifstream inputFile;
    string fileLine = "";
    size_t lineCount = 0;
    // Binary Tree
    StringBinaryTree *bTree;

    // Try opening file and output error to console if file is no good
    // inputFile.open(INPUT_FILE_NAME);
    // if (!inputFile)
    // {
    //     throw runtime_error("Error opening file: " + INPUT_FILE_NAME);
    // }
    // else
    // {
    //     // Get each line and store in BST
    //     while (getline(inputFile, fileLine))
    //     {
    //         bTree.insertNode(fileLine);
    //         lineCount++;
    //     }

    //     // CLOSE THE F-ING FILE
    //     inputFile.close();
    // }

    // bTree.insertNode("Hello");

    // cout << "Total lines: " << lineCount << endl;

    return 0;
}