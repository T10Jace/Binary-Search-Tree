/**
 * @file driver.cpp
 * @author Tristan Riley
 * @date 2023-11-27
 * @brief displays menu and allows user interaction
 * 
 * This file uses functions from other files to create a menu option for the user. The user can then decide which option they want to use and this file will implement the command given by the user.
 */

#include <iostream>
#include <fstream>
#include <string>
#include "BST.h"

using namespace std;

void displayMenu() {
    cout << "Which of the following options would you like to choose: " << endl;
    cout << "1. Set a data point" << endl;
    cout << "2. Find a data point" << endl;
    cout << "3. Print the data" << endl;
    cout << "4. Find the minimum data point" << endl;
    cout << "5. Find the maximum data point" << endl;
    cout << "6. Save the BST to a file" << endl;
    cout << "7. Delete or remove a data point" << endl;
    cout << "8. Exit" << endl;

    cout << "Enter a number (1-8)";
}

int main() {
    BST bst;

    cout << "Hello, welcome to my Binary Search Tree! " << endl;

    int choice;
    string key;
    int data;
    string filename;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key and data (key data): ";
                cin >> key >> data;
                cout << "Enter filename: ";
                cin >> filename;
                bst.set(key, data, filename);
                break;
            case 2:
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter filename: ";
                cin >> filename;
                cout << "Found data: " << bst.find(key, filename) << endl;
                break;
            case 3:
                cout << "Enter filename: ";
                cin >> filename;
                bst.print(filename);
                break;
            case 4:
                cout << "Enter filename: ";
                cin >> filename;
                bst.min(filename);
                break;
            case 5:
                cout << "Enter filename: ";
                cin >> filename;
                bst.max(filename);
                break;
            case 6:
                cout << "Enter filename: ";
                cin >> filename;
                bst.save_file(filename);
                break;
            case 7:
                cout << "Enter key to delete: ";
                cin >> key;
                bst.deleteKey(key);
                break;
            case 8:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 8);

    return 0;
}

