/*
 * Calculator.cpp
 *
 *  Date: 09/15/24
 *  Author: Nicholas Justus
 */
#include <iostream>

using namespace std;

int main() { // Changed 'void main()' to 'int main()'
    char statement[100];
    int op1, op2;
    char operation;
    char answer = 'Y';

    while (answer == 'Y' || answer == 'y') { // Modified to accept upper and lower case
        cout << "Enter expression (e.g., 5 + 3): " << endl;
        cin >> op1 >> operation >> op2; // Corrected the input order

        // Arithmetic operations based on the user input
        if (operation == '+') {
            cout << op1 << " + " << op2 << " = " << op1 + op2 << endl;
        }
        else if (operation == '-') {
            cout << op1 << " - " << op2 << " = " << op1 - op2 << endl;
        }
        else if (operation == '*') {
            cout << op1 << " * " << op2 << " = " << op1 * op2 << endl;
        }
        else if (operation == '/') {
            // Check for division by zero
            if (op2 != 0) {
                cout << op1 << " / " << op2 << " = " << op1 / op2 << endl;
            }
            else {
                cout << "Error: Division by zero!" << endl; // Fixed error message
            }
        }
        else {
            cout << "Error: Invalid operator. Please use +, -, *, or /." << endl; // Corrected error message
        }

        cout << "Do you wish to evaluate another expression? (Y/N): " << endl;
        cin >> answer; // Takes the user's input to decide if the loop continues
    }

    cout << "Program Finished." << endl;
    return 0; // Properly end the main function
}
