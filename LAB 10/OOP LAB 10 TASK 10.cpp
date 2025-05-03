#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream file;
    file.open("data_records.txt");  

    if(!file.is_open()){
        cerr << "Failed to open file." << endl;
        return 1;
    }

    streampos offset = 20; 

    file.seekg(offset, ios::beg);

    string record;
    getline(file, record);
    cout << "Third record: " << record << endl;

    file.close();
    return 0;
}