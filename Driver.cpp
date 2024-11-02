#include "LinkedList.h"
#include "DataClass.h"
#include "SmartPointer.h"

void printMenu();
void printStartupArt();
int numGen(int max, int min);

int main(){
    LinkedList<DataClass> groceryList;
    int userInput;

    do {
        printStartupArt();
        printMenu();
        cin >> userInput;

        if (userInput < 1 || userInput > 5) {
            cout << "\n\nPlease choose a number 1-4." << endl;
        }

        switch (userInput) {
            case 1:  // Display cart
                if (groceryList.size() == 0) {  // Check if the list is empty
                    cout << "\nYour cart is empty." << endl;
                } else {
                    cout << groceryList;  // Call the method to display items
                }
                break;
            case 2:{  // Add item to cart
                string name;
                double price;
                string category;

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
            case 3:{ // Remove item from cart
                if (groceryList.size() == 0) {  // Check if the list is empty
                    cout << "Your cart is empty. Nothing to remove." << endl;  // Print message if empty
                } else {
                    cout << groceryList;  // Show current items in cart
                    
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
            case 4:
            {
                int sortC;
                bool ascending;

                if (groceryList.size() == 0) 
                { 
                    cout << "\nYour cart is empty." << endl;
                }
                else
                {
                    cout << "\nWould you like to sort the cart in ascending or descending price order?";
                    cout << "\n1.) Ascending order.";
                    cout << "\n2.) Descending order.\n\n";

                    cin >> sortC;

                    while (sortC != 1 && sortC != 2)
                    {
                        cout << "\nPlease enter 1 or 2.\n\n";
                        cin >> sortC;
                    }

                    if (sortC == 1)
                    {
                        ascending = true;
                    }

                    else
                    {
                        ascending = false;
                    }

                    groceryList.sort(ascending);

                    cout << "Your cart has been sorted.\n";

                    cout << groceryList;
                }
                break;
            }
            case 5:  // Checkout and exit
                cout << "Thank you for using TechTarget!" << endl;
                break;
        }
    } while (userInput != 5);

    return 0;
}

void printMenu() {
    cout << "\n\nWelcome to TechTarget!" << endl;
    cout << "\nHow can we help you today?" << endl;
    cout << "\n1.) Display cart." << endl;
    cout << "\n2.) Add item to cart." << endl;
    cout << "\n3.) Remove item from cart." << endl;
    cout << "\n4.) Sort the items in cart." << endl;
    cout << "\n5.) Checkout and exit.\n" << endl;
}

void printStartupArt(){
    int max = 4;
    int min = 1;
    int randNum = numGen(max, min);

    if(randNum == 1){
        cout << "                             _        ," << endl;
        cout << "                            (_\\______/________ " << endl;
        cout << "                               \\-|-|/|-|-|-|-|/ " << endl;
        cout << "                                \\==/-|-|-|-|-/ " << endl;
        cout << "                                 \\/|-|-|-|,-' " << endl;
        cout << "                                  \\--|-''' " << endl;
        cout << "                                   \\_j________ " << endl;
        cout << "                                   (_)     (_) " << endl;
    }
    else if(randNum == 2){
        cout << "                ______________ " << endl;
        cout << "    __,.,---'''''              '''''---..._ " << endl;
        cout << " ,-'             .....:::''::.:            '`-. " << endl;
        cout << "'           ...:::.....       ' " << endl;
        cout << "            ''':::'''''       .               , " << endl;
        cout << "|'-.._           ''''':::..::':          __,,- " << endl;
        cout << " '-.._''`---.....______________.....---''__,,- " << endl;
        cout << "      ''`---.....______________.....---'' " << endl;
    }
    else if(randNum == 3){
        cout << "()   ()      ()    /" << endl;
        cout << "  ()      ()  ()  / " << endl;
        cout << "   ______________/___ " << endl;
        cout << "   \\            /   / " << endl;
        cout << "    \\^^^^^^^^^^/^^^/ " << endl;
        cout << "     \\     ___/   / " << endl;
        cout << "      \\   (   )  / " << endl;
        cout << "       \\  (___) / " << endl;
        cout << "        \\ /    / " << endl;
        cout << "         \\    / " << endl;
        cout << "          \\  / " << endl;
        cout << "           \\/ " << endl;
        cout << "           || " << endl;
        cout << "           || " << endl;
        cout << "           || " << endl;
        cout << "           || " << endl;
        cout << "           || " << endl;
        cout << "           /\\ " << endl;
        cout << "          /;;\\ " << endl;
        cout << "     ============== " << endl;
    }
    else{
        cout << "      _____________,-.___     _ " << endl;
        cout << "     |____        { {]_]_]   [_] " << endl;
        cout << "     |___ `-----.__\\ \\_]_]_    . ` " << endl;
        cout << "     |   `-----.____} }]_]_]_   , " << endl;
        cout << "     |_____________/ {_]_]_]_] , ` " << endl;
    }
}

int numGen(int max, int min) {
    if (max < min) {
        swap(max, min);
    }
    srand(time(0));
    return rand() % (max - min + 1) + min;
}