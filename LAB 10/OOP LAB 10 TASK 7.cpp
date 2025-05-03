#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ofstream outFile("sensor_log.txt");

    if(!outFile){
        cerr << "Failed to open file!" << endl;
        return 1;
    }

    outFile << "Temperature: 25C" << endl;
    cout << "Write position after first line: " << outFile.tellp() << endl;

    outFile << "Humidity: 60%" << endl;
    cout << "Write position after second line: " << outFile.tellp() << endl;

    outFile << "Pressure: 1013hPa" << endl;
    cout << "Write position after third line: " << outFile.tellp() << endl;
    
    outFile.close();
    return 0;
}