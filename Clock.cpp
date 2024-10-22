#include <iostream>
#include <string>
using namespace std;

// Helper Functions
string twoDigitString(unsigned int n) {
    if (n < 10) {
        return "0" + to_string(n);
    }
    return to_string(n);
}

string nCharString(size_t n, char c) {
    return string(n, c);
}

// Time Formatting Functions
string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
    string am_pm = h >= 12 ? "PM" : "AM";
    h = h % 12;
    if (h == 0) h = 12;
    return twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + " " + am_pm;
}

string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
    return twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);
}

// Display the Clocks
void displayClocks(unsigned int h, unsigned int m, unsigned int s) {
    cout << nCharString(27, '*') + nCharString(3, ' ') + nCharString(27, '*') << endl;
    cout << "*      12-HOUR CLOCK     *" + nCharString(3, ' ') + "*      24-HOUR CLOCK     *" << endl;
    cout << "*      " + formatTime12(h, m, s) + "     *"
        + nCharString(3, ' ') + "*      " + formatTime24(h, m, s) + "     *" << endl;
    cout << nCharString(27, '*') + nCharString(3, ' ') + nCharString(27, '*') << endl;
}

// Print Menu
void printMenu(string menuItems[], unsigned int numItems, unsigned int width) {
    cout << nCharString(width, '*') << endl;
    for (unsigned int i = 0; i < numItems; i++) {
        cout << "* " << i + 1 << " - " << menuItems[i]
            << nCharString(width - 6 - menuItems[i].length(), ' ') << "*" << endl;
    }
    cout << nCharString(width, '*') << endl;
}

// Add One Hour
void addOneHour(unsigned int& hours) {
    if (hours < 23) {
        hours++;
    }
    else {
        hours = 0;
    }
}

// Add One Minute
void addOneMinute(unsigned int& hours, unsigned int& minutes) {
    if (minutes < 59) {
        minutes++;
    }
    else {
        minutes = 0;
        addOneHour(hours);  // Overflow, so add one hour
    }
}

// Add One Second
void addOneSecond(unsigned int& hours, unsigned int& minutes, unsigned int& seconds) {
    if (seconds < 59) {
        seconds++;
    }
    else {
        seconds = 0;
        addOneMinute(hours, minutes);  // Overflow, so add one minute
    }
}

// Get Users Menu Choice
unsigned int getMenuChoice(unsigned int maxChoice) {
    unsigned int choice;
    do {
        cout << "Enter your choice: ";
        cin >> choice;
    } while (choice < 1 || choice > maxChoice);
    return choice;
}

// Main Menu
void mainMenu(unsigned int& hours, unsigned int& minutes, unsigned int& seconds) {
    string menuItems[] = { "Add One Hour", "Add One Minute", "Add One Second", "Exit Program" };
    bool running = true;

    while (running) {
        displayClocks(hours, minutes, seconds);
        printMenu(menuItems, 4, 27);
        unsigned int choice = getMenuChoice(4);

        switch (choice) {
        case 1:
            addOneHour(hours);
            break;
        case 2:
            addOneMinute(hours, minutes);
            break;
        case 3:
            addOneSecond(hours, minutes, seconds);
            break;
        case 4:
            running = false;
            break;
        }
    }
}

// Main Function
int main() {
    unsigned int hours = 0, minutes = 0, seconds = 0;
    mainMenu(hours, minutes, seconds);
    return 0;
}