#include<iostream>
using namespace std;

class Battery{
    private:
        int capacity; 
    public:
        Battery(int cap){
		    capacity = cap;
		}

    void display() const{
        cout << "Battery Capacity: " << capacity << " mAh" << endl;
    }
};

class Smartphone{
    private:
        string model;
        Battery battery; 

    public:
        Smartphone(string mod, int batterycapacity) : model(mod), battery(batterycapacity){}

    void display() const{
        cout << "Smartphone Model: " << model << endl;
        battery.display(); 
    }
};

int main(){
    Smartphone phone1("iPhone 16", 3000);
    Smartphone phone2("Samsung A23", 2000);

    phone1.display();
    phone2.display();
    return 0;
}