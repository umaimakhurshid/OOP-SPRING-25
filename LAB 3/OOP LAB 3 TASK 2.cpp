#include<iostream>
using namespace std;

class TeaMug{
    string brand;
	string color;
    int capacity;
	int currentFillLevel;

public:
    TeaMug(string b, string c, int cap, int fill){
        brand = b;
		color = c;
		capacity = cap;
		currentFillLevel = fill;
	}

    void siptea(int amount){
        if(currentFillLevel >= amount){
            currentFillLevel -= amount;
			cout << "Sipped " << amount << " ml" << endl;
			cout << "Remaining: " << currentFillLevel << " ml" << endl;
		}
        else{
            cout << "Not enough tea to sip!" << endl;
        }
    }

    void refill(){ 
        currentFillLevel = capacity;
        cout << "Mug refilled to " << capacity << " ml" << endl; 
    }

    bool empty(){ 
	    return currentFillLevel == 0; 
	}

    void status(){
        cout << "Mug Details" << endl;
		cout << "Brand: " << brand << endl;
		cout << "Color: " << color << endl; 
        cout << "Capacity: " << capacity << " ml" << endl;
		cout << "Fill: " << currentFillLevel << " ml" << endl;
    }
};

int main(){
    string brand;
	string color;
    int capacity;
	int fill;
	int sip;
    char choice;

    cout << "Enter the brand of mug:";
    cin >> brand;
    cout << "Enter the color of mug:";
    cin >> color;
    cout << "Enter the mug capacity(ml):";
    cin >> capacity;
    cout << "Enter the initial fill level(ml):";
    cin >> fill;

    TeaMug mug(brand, color, capacity, fill);
    
    mug.status();

    while(true){
        cout << "Enter the amount to sip (0 to exit):";
        cin >> sip;
        if(sip == 0){
		    break;
		}
        mug.siptea(sip);
        cout << (mug.empty()? "The mug is empty!" : "The mug still has tea.") << endl;
        cout << "Refill mug?(y/n):" << endl;
        cin >> choice;
        
        if(choice == 'y' || choice == 'Y'){
		    mug.refill();
		}
        mug.status();
    }
    
    return 0;
}
