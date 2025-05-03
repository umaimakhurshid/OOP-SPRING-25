#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream file;
    file.open("large_log.txt");  

    if(!file.is_open()){
        cerr << "Failed to open file." << endl;
        return 1;
    }

    char buffer[11];  

    file.read(buffer, 10);
    buffer[10] = '\0';
    cout << "First 10 characters: " << buffer << endl;

    streampos pos1 = file.tellg(); 
    cout << "Position after first read: " << pos1 << endl;

    file.read(buffer, 10);
    buffer[10] = '\0';
    cout << "Next 10 characters: " << buffer << endl;

    streampos pos2 = file.tellg();  
    cout << "Position after second read: " << pos2 << endl;

    file.close();  
    return 0;
}