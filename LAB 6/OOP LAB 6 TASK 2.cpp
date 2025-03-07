#include<iostream>
using namespace std;

class Vehicle{
	protected:
		string brand;
		int speed;
	
	public:
		Vehicle(string b, int s) : brand(b), speed(s){}
		virtual void displayDetails(){
		cout << "\nBrand: " << brand << endl;
		cout << "Speed: " << speed << endl;	
		}
};

class Car : public Vehicle{
	protected:
		int seats;
	
	public:
		Car(string b, int s, int seat): Vehicle(b,s), seats(seat){}
		void displayDetails() override{
			Vehicle :: displayDetails();
			cout << "Seats: " << seats << endl;
		}
};

class ElectricCar : public Car{  
    private:
        int batteryLife;
        
    public:
        ElectricCar(string b, int s, int seat, int bl) : Car(b, s, seat), batteryLife(bl){}
        void displayDetails() override{
            Car::displayDetails();
            cout << "Battery Life: " << batteryLife << " hours" << endl;
    }
};

int main(){
    string brand;
    int speed;
	int seats;
	int batteryLife;

    cout << "Enter the Electric Car brand: ";
    cin >> brand;
    cout << "Enter the speed: ";
    cin >> speed;
    cout << "Enter the number of seats: ";
    cin >> seats;
    cout << "Enter the battery life (hours): ";
    cin >> batteryLife;

    ElectricCar eCar(brand, speed, seats, batteryLife);
    cout << "\nElectric Car Details:";
    eCar.displayDetails();

    return 0;
}
