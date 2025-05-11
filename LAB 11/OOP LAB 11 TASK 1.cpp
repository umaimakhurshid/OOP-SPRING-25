#include<iostream>
#include<exception>  
using namespace std;

class InvalidValueException : public exception{
    public:
        const char* what() const noexcept override{
            return "InvalidValueException - Age cannot be negative or exceed 120.";
        }
};

void validateAge(int age){
    if(age < 0 || age > 120){
        throw InvalidValueException(); 
    } 
	else{
        cout << "Age is valid: " << age << endl;
    }
}

int main(){
    int age;
    cout << "Enter the age:";
    cin >> age;

    try{
        validateAge(age);  
    } 
	catch(const exception& e){
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}