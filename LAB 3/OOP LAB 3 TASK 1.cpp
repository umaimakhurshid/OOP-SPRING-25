#include<iostream>
using namespace std;

class MarkerPen{
    string brand;
	string color;
    int inkLevel;
    bool refillability;

public:
    MarkerPen(string b, string c, int ink, bool r){
        brand = b;
		color = c;
		inkLevel = ink;
		refillability = r;
	}

    void write(int usage){
        if(inkLevel >= usage){
            inkLevel -= usage;
            cout << "Wrote with " << color << " marker." << endl;
			cout << "Ink left: " << inkLevel << "%" << endl;
        } 
		else{
            cout << "Not enough ink!" << endl;
        }
    }

    void refill(){
        if(refillability){
		    inkLevel = 100;
			cout << color << " marker is refilled." << endl;
		}
        else{
		    cout << color << " marker is not refillable." << endl;
        }
    }

    void status(){
        cout << "Marker: " << color << endl;
		cout << "Ink Level: " << inkLevel << " %" <<endl;
		cout << "Refillable: " << (refillability ? "Yes" : "No") << endl;
    }
};

int main(){
    string brand;
	string color;
    int inkLevel;
	int usage;
    char choice;

    cout << "Enter the brand of marker:";
    cin >> brand;
    cout << "Enter the color of marker:";
    cin >> color;
    cout << "Enter the ink level(0-100):";
    cin >> inkLevel;
    cout << "Is it refillable?(y/n):";
    cin >> choice;

    MarkerPen marker(brand, color, inkLevel, (choice == 'y' || choice == 'Y'));

    marker.status();

    cout << "Enter the ink usage:";
    cin >> usage;
    marker.write(usage);

    cout << "Do you want to refill the marker?(y/n):";
    cin >> choice;
    if(choice == 'y' || choice == 'Y'){
	    marker.refill();
	}

    marker.status();
	return 0;
}