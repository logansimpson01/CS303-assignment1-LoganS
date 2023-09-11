#include "IntArray.h"
#include <iostream>
using namespace std;

int main() {
    // Create an instance of IntArray by reading integers from a file
    IntArray arr("data.txt");
    cout << "Initial array contents:" << endl;
    arr.print();
    cout << "------------------------" << endl;

    char choice;
    do {
        cout << "Menu:\n"
            << "1. Find an integer\n"
            << "2. Modify an integer by index\n"
            << "3. Add an integer to the end\n"
            << "4. Modify or remove an integer by index\n"
            << "5. Print current array\n"
            << "6. Exit\n"
            << "Enter your choice (1-6): ";
        cin >> choice;

        int val, index, newValue;
        switch (choice) {
        case '1':
            cout << "Enter the integer you'd like to search: ";
            while (!(cin >> val)) {
                cout << "Invalid input. Please enter an integer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            index = arr.find(val);
            if (index != -1) {
                cout << "Found " << val << " at index " << index << endl;
            }
            else {
                cout << val << " not found in the array." << endl;
            }
            break;

        case '2':
            cout << "Enter the index of the value you'd like to modify: ";
            while (!(cin >> index)) {
                cout << "Invalid input. Please enter an integer for index: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "Enter the new value: ";
            while (!(cin >> newValue)) {
                cout << "Invalid input. Please enter an integer for new value: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            arr.modify(index, newValue);
            cout << "Value at index " << index << " modified to " << newValue << endl;
            break;

        case '3':
            cout << "Enter the integer you'd like to add to the end of the array: ";
            while (!(cin >> val)) {
                cout << "Invalid input. Please enter an integer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            arr.add(val);
            cout << "Added " << val << " to the end of the array." << endl;
            break;

        case '4':
            cout << "Enter the index of the value you'd like to modify or remove: ";
            while (!(cin >> index)) {
                cout << "Invalid input. Please enter an integer for index: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "Would you like to (M)odify or (R)emove? Enter 'M' or 'R': ";
            char decision;
            cin >> decision;
            while (decision != 'M' && decision != 'm' && decision != 'R' && decision != 'r') {
                cout << "Invalid choice. Please enter 'M' or 'R': ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin >> decision;
            }
            if (decision == 'R' || decision == 'r') {
                arr.modifyOrRemove(index, true);
                cout << "Removed value at index " << index << endl;
            }
            else {
                arr.modifyOrRemove(index, false);
                cout << "Modified value at index " << index << " to 0." << endl;
            }
            break;

        case '5':
            cout << "Current array contents:" << endl;
            arr.print();
            break;

        case '6':
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice. Please choose a valid option." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }

        cout << "------------------------" << endl;
    } while (choice != '6');

    return 0;
}
