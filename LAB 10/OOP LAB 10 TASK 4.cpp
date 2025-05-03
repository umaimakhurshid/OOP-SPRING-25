#include<iostream>
#include<string>
using namespace std;

int main(){
    string type = "AutonomousCar"; 
    string extradata = "SoftwareVersion:2.2"; 
    string vehicleID = "ID123"; 

    size_t colonPos = extradata.find(':'); 
    if(colonPos != string::npos){
        string numberstring = extradata.substr(colonPos + 1); 
        
        if(type == "AutonomousCar"){
            float softwareversion = stof(numberstring); 
            cout << "Vehicle ID: " << vehicleID << endl;
			cout << "Software Version: " << softwareversion << endl;
        }
        else if(type == "ElectricVehicle"){
            int batterycapacity = stoi(numberstring); 
            cout << "Vehicle ID: " << vehicleID << endl;
			cout << "Battery Capacity: " << batterycapacity << endl;
        }
        else{
            cout << "Unknown vehicle type." << endl;
        }
    }
    else{
        cout << "Colon not found in extra data." << endl;
    }
    return 0;
}