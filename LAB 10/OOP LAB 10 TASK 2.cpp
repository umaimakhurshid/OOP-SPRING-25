#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;

int main(){
    ifstream inputFile("vehicles1.txt"); 
    if(!inputFile.is_open()){ 
        cout << "Error! File is not opening." << endl;
        return 1;
    }
    
    string line;
    while(getline(inputFile, line)){
        if(line.empty() || line[0] == '#'){
            continue;
        }

        istringstream ss(line);

        string type, id, name, year, extradata, certification;

        getline(ss, type, ',');
        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, year, ',');
        getline(ss, extradata, ',');
        getline(ss, certification, ',');

        cout << "Type: " << type << endl;
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Year: " << year << endl;
        cout << "ExtraData: " << extradata << endl;
        cout << "Certification: " << certification << endl;
    }

    inputFile.close(); 
    return 0;
}