#include <iostream>
using namespace std;

void printMenu();

int main() {
    int userInput;

    do {
        //Prints the menu to the user.
        printMenu();
        cin >> userInput;

        if(userInput < 1 || userInput > 5) {
            cout << "\n\nPlease choose a number 1-5. " << endl;
        }
        
        switch(userInput){
            case 1:

            break;
            
            case 2:

            break;

            case 3:

            break;

            case 4:

            break;


        }
    } while(userInput < 1 || userInput > 5);


    return 0;
}

void printMenu() {

    cout << "Welcome to Techtarget!" << endl;
    cout << "How could we help you today? " << endl;
    cout << "1.) Display stock. " << endl;
    cout << "2.) Add item to cart. " << endl;
    cout << "3.) Remove item from cart. " << endl;
    cout << "4.) Checkout " << endl;
}