#include<iostream>
#include<cmath>
#include<string>
using namespace std;

class NegativeNumberException{
    public:
        const char* what() const{
            return "NegativeNumberException - Input must be non-negative!";
        }
};

class InvalidTypeException{
    public:
        const char* what() const{
            return "InvalidTypeException - Only numeric types allowed!";
        }
};

double sqroot(int num){
    if(num < 0){
	    throw NegativeNumberException();
	}
	else{
        return sqrt(num);
    }
}

double sqroot(double num){
    if(num < 0){
	    throw NegativeNumberException();
	}
	else{
        return sqrt(num);
    }
}

template<typename T>
double sqroot(T){
    throw InvalidTypeException();
}

int main(){
    try{
        cout << "sqrt(16) = " << sqroot(16) << endl;
        cout << "sqrt(-5) = " << sqroot(-5) << endl;
    } 
	catch(NegativeNumberException& e){
        cout << e.what() << endl;
    }
    try{
        cout << "sqrt(\"hello\") = " << sqroot(string("hello")) << endl;
    } 
	catch(InvalidTypeException& e){
        cout << e.what() << endl;
    }
    return 0;
}