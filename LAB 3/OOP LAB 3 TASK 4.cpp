#include<iostream>
#include<string>
using namespace std;

class Laptop{
private:
    string brand;
    string model;
    int processor; 
    int RAM;            
    int storage;         

public:
	Laptop(){
	    brand = "";
		model = "";
		processor = 0;
		RAM = 0;
		storage = 0;
	}
    Laptop(string b, string m, int proc, int r, int s){
        brand = b;
        model = m;
        processor = proc;
        RAM = r;
        storage = s;
    }
    
    void inputspecifications(){
        cout << "Enter the brand:";
        cin >> brand;
        cout << "Enter the model:";
        cin >> model;
        cout << "Enter the processor speed(GHz):";
        cin >> processor;
        cout << "Enter the RAM(GB):";
        cin >> RAM;
        cout << "Enter the storage(GB):";
        cin >> storage;
    }
    
    void displayspecifications() {
        cout << "Laptop Specifications" << endl;
        cout << "Brand: " << brand << endl;
        cout << "Model: " << model << endl;
        cout << "Processor Speed: " << processor << " GHz" << endl;
        cout << "RAM: " << RAM << " GB" << endl;
        cout << "Storage: " << storage << " GB" << endl;
    }

    static void comparelaptops(Laptop &laptop1, Laptop &laptop2){
        cout << "\nComparing Laptops" << endl;
        
        if(laptop1.processor > laptop2.processor){
            cout << laptop1.brand << " " << laptop1.model << " has a faster processor." << endl;
        }
        else if(laptop1.processor < laptop2.processor){
            cout << laptop2.brand << " " << laptop2.model << " has a faster processor." << endl;
        }
        else{
            cout << "Both laptops have the same processor speed." << endl;
        }

        if(laptop1.RAM > laptop2.RAM){
            cout << laptop1.brand << " " << laptop1.model << " has more RAM." << endl;
        }
        else if(laptop1.RAM < laptop2.RAM){
            cout << laptop2.brand << " " << laptop2.model << " has more RAM." << endl;
        }
        else{
            cout << "Both laptops have the same RAM size." << endl;
        }

        if(laptop1.storage > laptop2.storage){
            cout << laptop1.brand << " " << laptop1.model << " has more storage." << endl;
        }
        else if(laptop1.storage < laptop2.storage){
            cout << laptop2.brand << " " << laptop2.model << " has more storage." << endl;
        }
        else{
            cout << "Both laptops have the same storage size." << endl;
        }
    }
};

int main(){
    Laptop laptop1;
	Laptop laptop2;
    
    cout << "Enter the details for Bilal's Laptop:\n";
    laptop1.inputspecifications();
    
    cout << "\nEnter the details for Ayesha's Laptop:\n";
    laptop2.inputspecifications();

    cout << "\nBilal's Laptop:\n";
    laptop1.displayspecifications();
    cout << "\nAyesha's Laptop:\n";
    laptop2.displayspecifications();

    Laptop::comparelaptops(laptop1, laptop2);
    return 0;
}