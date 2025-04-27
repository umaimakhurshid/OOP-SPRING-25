#include<iostream>
#include<string>
using namespace std;

class Vehicle{
    protected:
        string model;
        double rate;

    public:
        Vehicle(string m, double r) : model(m), rate(r){}

        virtual double getDailyRate() const = 0;
        virtual void displayDetails() const = 0;

        virtual ~Vehicle(){} 
};

class Car : public Vehicle{
    public:
        Car(string m, double r) : Vehicle(m, r){}

        double getDailyRate() const override{
            return rate;
        }

        void displayDetails() const override{
            cout << "Car Model: " << model << endl;
			cout << "Daily Rate: $" << rate << endl;
        }
};

class Bike : public Vehicle{
    public:
        Bike(string m, double r) : Vehicle(m, r){}

        double getDailyRate() const override{
            return rate;
        }

        void displayDetails() const override{
            cout << "\nBike Model: " << model << endl;
			cout << "Daily Rate: $" << rate << endl;
        }
};

int main(){
    Vehicle* v1 = new Car("Toyota Corolla", 55.0);
    Vehicle* v2 = new Bike("Yamaha YZF-R3", 35.0);

    v1->displayDetails();
    v2->displayDetails();
    
    delete v1;
    delete v2;
    return 0;
}