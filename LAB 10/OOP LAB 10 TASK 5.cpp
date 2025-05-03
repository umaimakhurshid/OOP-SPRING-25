#include<iostream>
#include<string>
using namespace std;

int main(){
    string type = "HybridTruck";
    string extraData = "Cargo:150|Battery:80";

    if(type == "HybridTruck"){
        size_t colonPos = extraData.find(':');
        size_t pipePos = extraData.find('|');
        size_t batteryPos = extraData.find("Battery:");

        if(colonPos != string::npos && pipePos != string::npos && batteryPos != string::npos){
            string cargoStr = extraData.substr(colonPos + 1, pipePos - colonPos - 1);
            string batteryStr = extraData.substr(batteryPos + 8);

            int cargo = stoi(cargoStr);
            int battery = stoi(batteryStr);

            cout << "HybridTruck Cargo: " << cargo << endl;
            cout << "HybridTruck Battery: " << battery << endl;
        } 
		else{
            cout << "Error: Invalid format for HybridTruck ExtraData." << endl;
        }
    }
    else{
        cout << "Error: Unknown vehicle type." << endl;
    }
    return 0;
}