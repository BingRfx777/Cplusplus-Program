// CornerGrocerProject.cpp
// CornerGrocerProject.cpp : This program reads a grocery-item file, counts how many times each item appears, saves the results to a backup file, and gives the user four menu options.

#include <iostream>     // Lets the program use cout and cin
#include <fstream>      // Lets the program read and write files
#include <map>          // Provides map container
#include <string>       // Allows the use of strings
#include <limits>       // Helps remove invalid input from cin

using namespace std;    // Allows use of standard C++ names without writing std:: each time

// Reads the input file and counts how many times each item appears
map<string, int> loadItemFrequencies (const string& inputFileName) { 
    map<string, int> itemFrequencies;
    ifstream inputFile(inputFileName);
    string itemName;

    // Verify that the input file opened successfully
    if (!inputFile.is_open()) {
        cout << "Error: Could not open " << inputFileName << endl;
        return itemFrequencies;
    }

    // Read each item and increase its frequency count
    while (inputFile >> itemName) {
        itemFrequencies[itemName]++;
    }

    inputFile.close();
    return itemFrequencies;
}

// Creates the backup file frequency.dat automatically
void createBackupFile(const map<string, int>& itemFrequencies, const string& backupFileName) {
    
    ofstream outputFile(backupFileName);

    // Verify that the backup file was created succesfully
    if (!outputFile.is_open()) {
        cout << "Error: Could not create " << backupFileName << endl;
        return;
    }

    // Write each item and its frequency to the backup file
    for (const auto& item : itemFrequencies) {
        outputFile << item.first << " " << item.second << endl;
    }

    outputFile.close();
}

// Menu Option One - Searches for a specific item
void searchForItem(const map<string, int>& itemFrequencies) {
    string itemName;

    // Ask the user for an item name
    cout << "Enter the item you wish to search for: ";
    cin >> itemName;

    // Search the map for the requested item
    auto item = itemFrequencies.find(itemName);

    // Display the item's frequency if found
    if (item != itemFrequencies.end()) {
        cout << itemName << " was purchased " << item->second << " time(s)." << endl;
    }
    else {
        cout << itemName << " was purchased 0 time(s)." << endl;
    }
}

// Menu Option Two - Displays all items and their frequencies
void printItemFrequencies(const map<string, int>& itemFrequencies) {
    cout << endl;
    cout << "Item Frequency List" << endl;
    cout << "-------------------" << endl;

    // Print each item and its frequency
    for (const auto& item : itemFrequencies) {
        cout << item.first << " " << item.second << endl;
    }
}

// Menu Option Three - Displays item frequencies as a histogram
void printHistogram(const map<string, int>& itemFrequencies) {
    cout << endl;
    cout << "Item Frequency Histogram" << endl;
    cout << "------------------------" << endl;

    // Loop through each item in the map
    for (const auto& item : itemFrequencies) {
        cout << item.first << " ";

        // Print one asterisk for each occurence
        for (int count = 0; count < item.second; ++count) {
            cout << "*";
        }
        cout << endl;
    }
}

    // Displays the program menu
    void displayMenu() {
        cout << endl;
        cout << "Corner Grocer Menu" << endl;
        cout << "------------------" << endl;
        cout << "1. Search for an item" << endl;
        cout << "2. Print item frequency list" << endl;
        cout << "3. Print item frequency histogram" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
    }

    int main() {
        // Set the input and backup file names
        const string inputFileName = "CS210_Project_Three_Input_File.txt";
        const string backupFileName = "frequency.dat";

        //Load item frequencies fromt the input file
        map<string, int>itemFrequencies = loadItemFrequencies(inputFileName);

        // Automatically create the backup file
        createBackupFile(itemFrequencies, backupFileName);

        int userChoice = 0;

        // Continue displaying the menu until the user selects Exit
        do {
            displayMenu();
            cin >> userChoice;

            // Handle nonnumeric input
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number from 1 to 4." << endl;
                continue;
            }

            // Perform the selected menu operation
            switch (userChoice) {
            case 1:
                searchForItem(itemFrequencies);
                break;

            case 2:
                printItemFrequencies(itemFrequencies);
                break;

            case 3:
                printHistogram(itemFrequencies);
                break;

            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a number from 1 to 4" << endl;
                break;
            }

        } while (userChoice != 4);

        return 0;
    }


