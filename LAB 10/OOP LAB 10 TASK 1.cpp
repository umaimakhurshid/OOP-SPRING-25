#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
	ifstream inputFile("vehicles.txt"); 
    if(!inputFile.is_open()){ 
        cout << "Error! File is not opening." << endl;
        return 1;
    }

    string line;
    while(getline(inputFile, line)){ 
        if(line.empty() || line[0] == '#'){
            continue;
        }
        cout << line << endl; 
    }

    inputFile.close(); 
    return 0;
}