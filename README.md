# LAB 36: BST
## Requirements
    1. Modify the class to process the codes found in the codes.txt file, which are strings, rather than integers.
    2. Write a program that creates and populates a BST from these records. 
    3. Add interactive, menu-driven functionality to add, delete, search, and modify records.

## Initial thoughts
    + Converting to strings from ints shouldn't be too hard; standard string comparison is included by default with the language.

## Design Decisions
     

## Completion Updates
    + Converted binary tree declaration & definition files to string from int.
    + Started working on inserting each line from input file into BST.
    + Binary tree declaration and insert functionality seem to be working properly. main now loads all lines of data from codes.txt into binary tree and timer was added just for fun to check speed.
    + Starting to work on menu driven functionality. Planning to use menu from goat herd project as a base and add functionality on top of that.
        - Add, delete and search shouldn't be too hard because methods are already built, but modification will require deletion + insert.

## Issues/Bugs
    + VsCode once again needed tasks.json modified to compile all files within directory.
        - In case you need it: "args": ["-fdiagnostics-color=always","-g","${fileDirname}/*.cpp","-o","${fileDirname}/${fileBasenameNoExtension}"],
    + IsYesNo() functionality not working because Lowercase() transform function not working.
        - Worked around by requiring user to enter simple char 'y' || 'n'.