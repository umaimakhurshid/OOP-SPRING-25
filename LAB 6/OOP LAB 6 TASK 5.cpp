#include<iostream>
using namespace std;

class Device{
	protected:
		int deviceID;
		bool status;
	
	public:
		Device(int id, bool s) : deviceID(id), status(s){}
		virtual void displayDetails(){
		cout << "\nDevice ID: " << deviceID << endl;
		cout << "Status: " << (status ? "ON" : "OFF") << endl;	
		}
};

class SmartPhone : virtual public Device{
    protected:
        float screenSize;
        
    public:
        SmartPhone(int id, bool s, float ss) : Device(id, s), screenSize(ss){}
        void displayDetails() override{
            Device :: displayDetails();
            cout << "Screen Size: " << screenSize << " inches" << endl;
        }
};

class SmartWatch : virtual public Device{
    protected:
        bool heartRateMonitor;
        
    public:
        SmartWatch(int id, bool s, bool hrm) : Device(id, s), heartRateMonitor(hrm){}
        void displayDetails() override{
            Device :: displayDetails();
            cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Available" : "Not Available") << endl;
        }
};

class SmartWearable : public SmartPhone, public SmartWatch{
    private:
        int stepCounter;
        
    public:
        SmartWearable(int id, bool s, float ss, bool hrm, int sc): Device(id, s), SmartPhone(id, s, ss), SmartWatch(id, s, hrm), stepCounter(sc){}
        void displayDetails() override{
            SmartPhone :: displayDetails();
            cout << "Heart Rate Monitor: " << (heartRateMonitor ? "Available" : "Not Available") << endl;
            cout << "Step Counter: " << stepCounter << " steps" << endl;
        }
};

int main(){
    int deviceID;
    bool status;
    float screenSize;
    bool heartRateMonitor;
    int stepCounter;

    cout << "Enter the device ID: ";
    cin >> deviceID;
    cout << "Enter the status(1 for ON, 0 for OFF): ";
    cin >> status;
    cout << "Enter the screen size (inches): ";
    cin >> screenSize;
    cout << "Heart Rate Monitor Available? (1 for Yes, 0 for No): ";
    cin >> heartRateMonitor;
    cout << "Enter the step counter value: ";
    cin >> stepCounter;

    SmartWearable wearable(deviceID, status, screenSize, heartRateMonitor, stepCounter);
    cout << "\nSmart Wearable Details:";
    wearable.displayDetails();
    return 0;
}
