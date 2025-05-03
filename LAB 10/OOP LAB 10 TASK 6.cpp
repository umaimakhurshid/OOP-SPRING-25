#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

struct InventoryItem{
    int itemID;
    char itemName[20];
};

int main(){
    int itemID = 101;
    char itemName[20];
    strncpy(itemName, "Laptop", sizeof(itemName));
    itemName[sizeof(itemName) - 1] = '\0';

    ofstream outFile("inventory.dat", ios::binary);
    if(!outFile){
        cout << "Error opening file for writing." << endl;
        return 1;
    }
    outFile.write((char*)&itemID, sizeof(itemID));
    outFile.write(itemName, sizeof(itemName));
    outFile.close();

    int loadedID;
    char loadedName[20];

    ifstream inFile("inventory.dat", ios::binary);
    if(!inFile){
        cout << "Error opening file for reading." << endl;
        return 1;
    }
    inFile.read((char*)&loadedID, sizeof(loadedID));
    inFile.read(loadedName, sizeof(loadedName));
    inFile.close();

    cout << "Loaded Inventory Item" << endl;
    cout << "Item ID: " << loadedID << endl;
    cout << "Item Name: " << loadedName << endl;
    return 0;
}