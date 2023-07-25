#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstddef>
#include <vector>

using namespace std;

// Function to calculate the total amount with discount and VAT
double calculateTotalAmount(double subtotal) {
    double discount = subtotal * 0.05;
    double vat = subtotal * 0.16;
    return subtotal - discount + vat;
}

int main() {
    // Welcome note
    cout << "Welcome to Construct Tech Hardware Shop!" << endl;

    // Login system
    string username, password;
    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    // Cashier name input
    string cashierName;
    cout << "Enter the cashier's name: ";
    cin.ignore();
    getline(cin, cashierName);

    // Telephone number input
    string telephoneNumber;
    cout << "Enter your telephone number: ";
    getline(cin, telephoneNumber);

    // Menu items and their prices
    string itemNames[] = {"Hammer", "Screwdriver", "Wrench", "Cement", "Mabati", "Wheelbarrow", "Standardglasses", "Glue", "Pindingwire", "Electric cable"};
    double itemPrices[] = {500.0, 250.0, 1500.0, 750.0, 900.0, 2500.0, 300.0, 70.0,1800.0, 3000.0};

    // Prompt user to enter the type and quantity of items
    int quantity;
    double subtotal = 0.0;

    cout << "\nMenu:\n";
    for (int i = 0; i < 10; i++) {
        cout << i + 1 << ". " << itemNames[i] << " - Kshs" << itemPrices[i] << endl;
    }

    cout << "\nEnter the item number and quantity (0 to exit):\n";

    int itemNumber;
    vector<string> selectedItems;
    vector<int> quantities;

    while (true) {
        cout << "Item number: ";
        cin >> itemNumber;

        if (itemNumber == 0) {
            break;
        }

        if (itemNumber < 1 || itemNumber > 10) {
            cout << "Invalid item number. Try again.\n";
            continue;
        }

        cout << "Quantity: ";
        cin >> quantity;

        if (quantity < 1) {
            cout << "Invalid quantity. Try again.\n";
            continue;
        }

        double itemPrice = itemPrices[itemNumber - 1];
        double itemTotal = itemPrice * quantity;
        subtotal += itemTotal;

        selectedItems.push_back(itemNames[itemNumber - 1]);
        quantities.push_back(quantity);
    }

    // Calculate the total amount with discount and VAT
    double totalAmount = calculateTotalAmount(subtotal);

    // Generate the time serviced automatically
    time_t currentTime = time(NULL);
    string timeServiced = ctime(&currentTime);
    
     // Method of payment input
    int paymentOption;
    cout << "\nChoose your method of payment:\n";
    cout << "1. Cash\n";
    cout << "2. Credit Card\n";
    cout << "3. Mobile Payment\n";
    cout << "Enter the option number: ";
    cin >> paymentOption;

    string paymentMethod;
    switch (paymentOption) {
        case 1:
            paymentMethod = "Cash";
            break;
        case 2:
            paymentMethod = "Credit Card";
            break;
        case 3:
            paymentMethod = "Mobile Payment";
            break;
        default:
            paymentMethod = "Unknown";
            break;
    }

    // Print receipt
    cout << "\n\n---------- Receipt ----------\n";
    cout << "Title: Construct Tech Hardware Shop" << endl;
    cout << "Cashier: " << cashierName << endl;
    cout << "Username: " << username << endl;
    cout << "Telephone number: " << telephoneNumber << endl;
    cout << "Time serviced: " << timeServiced;
    cout << "------------------------------\n";

    // Print selected items and quantities
    cout << "Items Bought:\n";
    int totalItems = 0;
    for (int i = 0; i < selectedItems.size(); i++) {
        cout << selectedItems[i] << " - Quantity: " << quantities[i] << endl;
        totalItems += quantities[i];
    }

    cout << "------------------------------\n";
    cout << "Subtotal: Kshs" << fixed << setprecision(2) << subtotal << endl;
    cout << "Discount (5%): Kshs" << fixed << setprecision(2) << subtotal * 0.05 << endl;
    cout << "VAT (16%): Kshs" << fixed << setprecision(2) << subtotal * 0.16 << endl;
    cout << "------------------------------\n";
    cout << "Total amount: Kshs" << fixed << setprecision(2) << totalAmount << endl;
    cout << "Total number of items bought: " << totalItems << endl;
    cout << "Payment method: " << paymentMethod << endl;
    cout << "Thank you for shopping with us!" << endl << endl;
    cout << "------------------------------\n";

    // Prompt the user if they want to reduce the quantity of items
    char reduceQuantity;
    cout << "Do you want to reduce the quantity of any items? (Y/N): ";
    cin >> reduceQuantity;

    if (reduceQuantity == 'Y' || reduceQuantity == 'y') {
        // Reduce the quantity of items
        int itemToRemove;
        int newQuantity;

        while (true) {
            cout << "Enter the item number to reduce the quantity (0 to finish): ";
            cin >> itemToRemove;

            if (itemToRemove == 0) {
                break;
            }

            if (itemToRemove < 1 || itemToRemove > selectedItems.size()) {
                cout << "Invalid item number. Try again.\n";
                continue;
            }

            cout << "Enter the new quantity for item " << itemToRemove << ": ";
            cin >> newQuantity;

            if (newQuantity < 0 || newQuantity > quantities[itemToRemove - 1]) {
                cout << "Invalid quantity. Try again.\n";
                continue;
            }

            int reducedQuantity = quantities[itemToRemove - 1] - newQuantity;
            subtotal -= itemPrices[itemToRemove - 1] * reducedQuantity;
            quantities[itemToRemove - 1] = newQuantity;

            if (newQuantity == 0) {
                selectedItems.erase(selectedItems.begin() + itemToRemove - 1);
                quantities.erase(quantities.begin() + itemToRemove - 1);
            }
        }

        // Recalculate the total amount with discount and VAT
        totalAmount = calculateTotalAmount(subtotal);

        // Print updated receipt
        cout << "\n\n---------- Updated Receipt ----------\n";
        cout << "Title: Construct Tech Hardware Shop" << endl;
        cout << "Cashier: " << cashierName << endl;
        cout << "Username: " << username << endl;
        cout << "Telephone number: " << telephoneNumber << endl;
        cout << "Time serviced: " << timeServiced;
        cout << "Payment method: " << paymentMethod << endl; 
        cout << "Thank you for shopping with us!" << endl << endl;
        cout << "------------------------------\n";

        // Print updated selected items and quantities
        cout << "Updated Items Bought:\n";
        totalItems = 0;
        for (int i = 0; i < selectedItems.size(); i++) {
            cout << selectedItems[i] << " - Quantity: " << quantities[i] << endl;
            totalItems += quantities[i];
        }

        cout << "------------------------------\n";
        cout << "Subtotal: Kshs" << fixed << setprecision(2) << subtotal << endl;
        cout << "Discount (5%): Kshs" << fixed << setprecision(2) << subtotal * 0.05 << endl;
        cout << "VAT (16%): Kshs" << fixed << setprecision(2) << subtotal * 0.16 << endl;
        cout << "------------------------------\n";
        cout << "Total amount: Kshs" << fixed << setprecision(2) << totalAmount << endl;
        cout << "Total number of items bought: " << totalItems << endl;
        cout << "------------------------------\n";
    }

    return 0;
}


