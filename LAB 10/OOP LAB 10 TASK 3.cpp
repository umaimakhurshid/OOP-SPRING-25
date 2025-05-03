#include<iostream>
#include<string>
using namespace std;

int main(){
    string yearstring = "2025"; 
    int year;

    year = stoi(yearstring); 
    cout << "The year as an integer is: " << year << endl;
    return 0;
}