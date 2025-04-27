#include<iostream>
#include<string>
using namespace std;

class SmartDevice{
    public:
        virtual void turnOn() = 0;
        virtual void turnOff() = 0;
        virtual void getStatus() const = 0;

        virtual ~SmartDevice(){}
};

class LightBulb : public SmartDevice{
    private:
        bool isOn;
        int brightness;

    public:
        LightBulb() : isOn(false), brightness(0){}

        void turnOn() override{
            isOn = true;
            brightness = 75; 
            cout << "LightBulb is turned ON with brightness " << brightness << "%." << endl;
        }

        void turnOff() override{
            isOn = false;
            brightness = 0;
            cout << "LightBulb is turned OFF." << endl;
        }

        void getStatus() const override{
            cout << "LightBulb Status: " << (isOn ? "ON" : "OFF") << endl;
			cout << "Brightness: " << brightness << "%" << endl;
        }
};

class Thermostat : public SmartDevice{
    private:
        bool isOn;
        double temperature; 
		
	public:
        Thermostat() : isOn(false), temperature(22.0){} 
        void turnOn() override{
            isOn = true;
            temperature = 24.0;
            cout << "Thermostat is turned ON and set to temp (in celsius): " << temperature << endl;
        }

        void turnOff() override{
            isOn = false;
            cout << "Thermostat is turned OFF." << endl;
        }

        void getStatus() const override{
            cout << "Thermostat Status: " << (isOn ? "ON" : "OFF") << endl;
			cout << "Temperature (in celsius): " << temperature << endl;
        }
};

int main(){
    SmartDevice* device1 = new LightBulb();
    SmartDevice* device2 = new Thermostat();

    device1->turnOn();
    device1->getStatus();
    cout << endl;

    device2->turnOn();
    device2->getStatus();
    cout << endl;

    device1->turnOff();
    device1->getStatus();
    cout << endl;

    device2->turnOff();
    device2->getStatus();

    delete device1;
    delete device2;
    return 0;
}