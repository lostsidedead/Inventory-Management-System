#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
using namespace std;

// Define a structure to represent an Item in the inventory
struct Item {
    int id;
    string name;
    int quantity;
    double price;
};

class Inventory {
private:
    vector<Item> items;
    int nextId;

public:
    Inventory() : nextId(1) {}

    void addItem() {
        Item newItem;
        newItem.id = nextId++;
        cout << "Enter item name: ";
        cin.ignore();
        getline(cin, newItem.name);
        cout << "Enter quantity: ";
        cin >> newItem.quantity;
        cout << "Enter price: ";
        cin >> newItem.price;
        items.push_back(newItem);
        cout << "Item added successfully!\n";
    }

    void updateItem() {
        int id;
        cout << "Enter item ID to update: ";
        cin >> id;

        for (auto &item : items) {
            if (item.id == id) {
                cout << "Updating item: " << item.name << "\n";
                cout << "Enter new name (or press Enter to keep current): ";
                cin.ignore();
                string newName;
                getline(cin, newName);
                if (!newName.empty()) {
                    item.name = newName;
                }

                cout << "Enter new quantity (or -1 to keep current): ";
                int newQuantity;
                cin >> newQuantity;
                if (newQuantity != -1) {
                    item.quantity = newQuantity;
                }

                cout << "Enter new price (or -1 to keep current): ";
                double newPrice;
                cin >> newPrice;
                if (newPrice != -1) {
                    item.price = newPrice;
                }

                cout << "Item updated successfully!\n";
                return;
            }
        }

        cout << "Item not found!\n";
    }

    void deleteItem() {
        int id;
        cout << "Enter item ID to delete: ";
        cin >> id;

        for (auto it = items.begin(); it != items.end(); ++it) {
            if (it->id == id) {
                cout << "Deleting item: " << it->name << "\n";
                items.erase(it);
                cout << "Item deleted successfully!\n";
                return;
            }
        }

        cout << "Item not found!\n";
    }

    void displayItems() const {
        if (items.empty()) {
            cout << "No items in the inventory.\n";
            return;
        }

        cout << left << setw(10) << "ID" << setw(20) << "Name" 
             << setw(10) << "Quantity" << setw(10) << "Price" << "\n";
        cout << string(50, '-') << "\n";

        for (const auto &item : items) {
            cout << left << setw(10) << item.id << setw(20) << item.name 
                 << setw(10) << item.quantity << "$" << fixed << setprecision(2) << item.price << "\n";
        }
    }

    void searchItem() const {
        string query;
        cout << "Enter item name to search: ";
        cin.ignore();
        getline(cin, query);

        bool found = false;
        for (const auto &item : items) {
            if (item.name.find(query) != string::npos) {
                cout << "Found item:\n";
                cout << "ID: " << item.id << "\n"
                     << "Name: " << item.name << "\n"
                     << "Quantity: " << item.quantity << "\n"
                     << "Price: $" << fixed << setprecision(2) << item.price << "\n";
                found = true;
            }
        }

        if (!found) {
            cout << "No item found with the name: " << query << "\n";
        }
    }
};

void menu() {
    cout << "\nInventory Management System\n";
    cout << "1. Add Item\n";
    cout << "2. Update Item\n";
    cout << "3. Delete Item\n";
    cout << "4. Display All Items\n";
    cout << "5. Search Item\n";
    cout << "6. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    Inventory inventory;
    int choice;

    do {
        menu();
        cin >> choice;

        switch (choice) {
            case 1:
                inventory.addItem();
                break;
            case 2:
                inventory.updateItem();
                break;
            case 3:
                inventory.deleteItem();
                break;
            case 4:
                inventory.displayItems();
                break;
            case 5:
                inventory.searchItem();
                break;
            case 6:
                cout << "Exiting the program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}
