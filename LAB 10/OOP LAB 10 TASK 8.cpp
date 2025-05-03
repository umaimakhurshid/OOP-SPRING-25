#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ofstream writeFile("config.txt");
    if(!writeFile){
        cerr << "Failed to create file!" << endl;
        return 1;
    }

    writeFile << "AHSJK";
    writeFile << "BKWQS";
    writeFile << "WDEGE";
    writeFile.close();

    fstream file("config.txt", ios::in | ios::out);
    if(!file){
        cerr << "Failed to open file!" << endl;
        return 1;
    }

    file.seekp(5, ios::beg);
    file << "XXXXX";

    file.close();

    ifstream readFile("config.txt");
    string content;
    if(readFile){
        getline(readFile, content);
        cout << "Updated file content: " << content << endl;
    } 
	else{
        cerr << "Failed to read file!" << endl;
    }
    
    readFile.close();
    return 0;
}