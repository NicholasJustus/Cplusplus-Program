#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <iomanip>

using namespace std;

// Function to read the input file and count item frequencies
map<string, int> ReadInputFile(const string& filename) {
    map<string, int> itemFrequency;
    ifstream inputFile(filename);

    if (!inputFile) {
        cerr << "Error: Unable to open file " << filename << endl;
        return itemFrequency;
    }

    string item;
    while (inputFile >> item) {
        itemFrequency[item]++;
    }

    inputFile.close();
    return itemFrequency;
}

// Function to search for a specific item
void SearchItem(const map<string, int>& itemFrequency) {
    string item;
    cout << "Enter the item you wish to search for: ";
    cin >> item;

    auto it = itemFrequency.find(item);
    if (it != itemFrequency.end()) {
        cout << item << " was purchased " << it->second << " times." << endl;
    }
    else {
        cout << item << " was not found in the purchase records." << endl;
    }
}

// Function to display all items with their frequencies
void DisplayAllItems(const map<string, int>& itemFrequency) {
    cout << "Item Purchase Frequencies:" << endl;
    for (const auto& entry : itemFrequency) {
        cout << setw(15) << left << entry.first << entry.second << endl;
    }
}

// Function to display a histogram of item frequencies
void DisplayHistogram(const map<string, int>& itemFrequency) {
    cout << "\nPurchase Histogram:" << endl;
    for (const auto& entry : itemFrequency) {
        cout << setw(15) << left << entry.first << string(entry.second, '*') << endl;
    }
}

// Function to create the frequency.dat file for backup
void WriteFrequencyFile(const map<string, int>& itemFrequency, const string& filename) {
    ofstream outputFile(filename);
    if (!outputFile) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    for (const auto& entry : itemFrequency) {
        outputFile << entry.first << " " << entry.second << endl;
    }

    outputFile.close();
}

int main() {
    string inputFile = "CS210_Project_Three_Input_File.txt";
    string outputFile = "frequency.dat";

    map<string, int> itemFrequency = ReadInputFile(inputFile);
    WriteFrequencyFile(itemFrequency, outputFile);

    int choice;
    do {
        // Displaying the menu
        cout << "\nMenu:\n";
        cout << "1. Search for an item\n";
        cout << "2. Display all items with frequencies\n";
        cout << "3. Display histogram of items\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            SearchItem(itemFrequency);
            break;
        case 2:
            DisplayAllItems(itemFrequency);
            break;
        case 3:
            DisplayHistogram(itemFrequency);
            break;
        case 4:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 4);

    return 0;
}
