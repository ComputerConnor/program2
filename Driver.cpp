#include <iostream>
#include "LinkedList.h"
#include "DataClass.h"
#include "SmartPointer.h"

void printMenu();

int main() {
    LinkedList<DataClass> groceryList;
    int userInput;

    do {
        printMenu();
        cin >> userInput;

        if (userInput < 1 || userInput > 4) {
            cout << "\n\nPlease choose a number 1-4." << endl;
        }

        switch (userInput) {
            case 1:  // Display cart
                if (groceryList.size() == 0) {  // Check if the list is empty
                    cout << "\nYour cart is empty." << endl;  // Print message if empty
                } else {
                    groceryList.displayItems();  // Call the method to display items
                }
                break;
            case 2: {  // Add item to cart
                string name;
                double price;
                string category;

                // Get item details from the user
                cin.ignore();
                cout << "\nEnter item name: ";
                getline (cin, name);
                cout << "\nEnter item price: ";
                cin >> price;
                cin.ignore();
                cout << "\nEnter item category: ";
                getline (cin, category);

                // Create a new DataClass item and add it to the grocery list
                DataClass item;
                item.setItem(name, price, category);
                groceryList.append(item);
                cout << name << " has been added to your cart." << endl;
                break;
            }
            case 3: {  // Remove item from cart
                if (groceryList.size() == 0) {  // Check if the list is empty
                    cout << "Your cart is empty. Nothing to remove." << endl;  // Print message if empty
                } else {
                    groceryList.displayItems();  // Show current items in cart
                    
                    int itemToRemove;
                    cout << "\nEnter the number of the item to remove: ";
                    cin >> itemToRemove;

                    if (itemToRemove < 1 || itemToRemove > groceryList.size()) {
                        cout << "Invalid item number. Please try again." << endl;
                    } else {
                        groceryList.removeAt(itemToRemove);  // Remove item at the specified index
                        cout << "Item removed from the cart." << endl;
                    }
                }
                break;
            }
            case 4:  // Checkout and exit
                cout << "Thank you for using TechTarget!" << endl;
                break;
        }
    } while (userInput != 4);

    return 0;
}

void printMenu() {
    cout << "\n\nWelcome to TechTarget!" << endl;
    cout << "\nHow can we help you today?" << endl;
    cout << "\n1.) Display cart." << endl;
    cout << "2.) Add item to cart." << endl;
    cout << "3.) Remove item from cart." << endl;
    cout << "4.) Checkout and exit." << endl;
}
