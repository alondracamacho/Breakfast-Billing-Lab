#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

//Alondra Camacho - show menu of restaraunt, allow user to place order, and print reciept

//make struct menuItemType - 3 components: string menuItem, double menuPrice, int Count
struct menuItemType {
    string menuItem;
    double menuPrice;
    int Count;
};

//prototype of getData()
void getData(menuItemType [], int);

//prototype of showMenu()
void showMenu(menuItemType [], int);

//prototype for printCheck()
void printCheck(menuItemType [], int);

int main() {

    const int sizeOfMenu = 8;

    //make array menuList, of struct menuItemType
    menuItemType menuList[sizeOfMenu];

    //call getData()
    getData(menuList, sizeOfMenu);

    //call showMenu()
    showMenu(menuList, sizeOfMenu);

    //call printCheck()
    printCheck(menuList, sizeOfMenu);

    return 0;
}




//definition for getData()
void getData(menuItemType menuList [], int size) {

    //declare variable to open file
    ifstream inFile;

    //open file
    inFile.open("menu.txt");

    //if file fails to open...show error
    if (inFile.fail()) {
        cout << "ERROR. File not opened";
        exit(1);
    }

    //make variables to hold string name of item and double price
    string nameOfItem;
    double priceOfItem;

    int i = 0; 


    //read through each line in file
    while(!inFile.eof() && i < size) {



        //read line in file and store in variables declared
        inFile >> nameOfItem >> priceOfItem;

        //go to element in array and store data collected from file
        menuList[i].menuItem = nameOfItem;
        menuList[i].menuPrice = priceOfItem;
        menuList[i].Count = 0;

        //increment counter
        i++;

    }
    //close file
    inFile.close();
}

//definition of showMenu()
void showMenu(menuItemType menuList[], int size) {

    //display greeting
    cout << "Welcome to Johnny's Restaurant!\n\n";
    cout << "Here is today's breakfast menu:\n";

    //go through each item in array and display 
    for (int j = 0; j < size; j++) {

        cout << left << setw(25) << menuList[j].menuItem + ':' << setw(10) << fixed << setprecision(2) << menuList[j].menuPrice << endl;
    }

    cout << endl << "Please enter the quantity for each item you'd like to purchase." << endl << endl;
}

//definition for printCheck()
void printCheck(menuItemType menuList[], int size) {

    int numOfItems;
    double subtotal = 0.00;
    
    for (int k = 0; k < size; k++) {

        cout << "Quantity of " << menuList[k].menuItem << ":";

        cin >> numOfItems;

        menuList[k].Count = numOfItems;

        subtotal += menuList[k].menuPrice * numOfItems;
    }

    cout << "\nHere is your reciept: \n";

    for (int k = 0; k < size; k++) {

        if (menuList[k].Count > 0) {
            cout << left << setw(25) << menuList[k].menuItem + ':' << setw(10) << menuList[k].Count << "$" << setw(20) << fixed << setprecision(2) << menuList[k].menuPrice * menuList[k].Count << endl;
        }
    }

    double tax = subtotal * 0.05; //tax rate of 5%
    double finalCost = subtotal + tax;

    cout << setw(25) << "Subtotal:" << setw(10) << "" << "$" << setw(10) << fixed << setprecision(2) << subtotal << endl;
    cout << setw(25) << "Tax:" << setw(10) << "" << "$" << setw(10) <<  fixed << setprecision(2) << tax << endl;
    cout << setw(25) << "Total:" << setw(10) << "" << "$" << setw(10) <<  fixed << setprecision(2) << finalCost << endl;
}

/*OUTPUT:
Welcome to Johnny's Restaurant!

Here is today's breakfast menu:
Plain-Egg:               1.45      
Bacon-And-Egg:           2.45      
Muffin:                  0.99      
French-Toast:            1.99      
Fruit-Basket:            2.49      
Cereal:                  0.69      
Coffee:                  0.50      
Tea:                     0.75      

Please enter the quantity for each item you'd like to purchase.

Quantity of Plain-Egg:3
Quantity of Bacon-And-Egg:4
Quantity of Muffin:2
Quantity of French-Toast:5
Quantity of Fruit-Basket:3
Quantity of Cereal:2
Quantity of Coffee:2
Quantity of Tea:1

Here is your reciept: 
Plain-Egg:               3         $4.35                
Bacon-And-Egg:           4         $9.80                
Muffin:                  2         $1.98                
French-Toast:            5         $9.95                
Fruit-Basket:            3         $7.47                
Cereal:                  2         $1.38                
Coffee:                  2         $1.00                
Tea:                     1         $0.75                
Subtotal:                          $36.68     
Tax:                               $1.83      
Total:                             $38.51     
*/
