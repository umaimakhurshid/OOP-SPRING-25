#include<iostream>
#include<string>  
using namespace std;

class Car{
    private:
        string registrationnumber;
        string model;
        string ownername;

    public:
        Car(string regnum, string mod, string owner){  
            registrationnumber = regnum;
			model = mod;
			ownername = owner;
		}

    Car(const Car &car, string newowner){
        registrationnumber = car.registrationnumber;
        model = car.model;
        ownername = newowner;
    }

    void display(){
        cout << "Registration Number: " << registrationnumber << endl;
        cout << "Model: " << model << endl;
        cout << "Owner Name: " << ownername << endl;
    }
};

int main(){
    Car car1("UKS-195", "Toyota Corolla", "Sarim");
    cout << "Original Car Details" << endl;
    car1.display();

    Car car2(car1, "Sara");
    cout << "\nNew Owner's Car Details" << endl;
    car2.display();
    return 0;
}