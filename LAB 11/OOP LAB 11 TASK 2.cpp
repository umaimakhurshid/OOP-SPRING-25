#include<iostream>
#include<exception>
using namespace std;

class StackOverflowException : public exception{
    public:
        const char* what() const noexcept override{
            return "StackOverflowException - Stack is full!";
        }
};

class StackUnderflowException : public exception{
    public:
        const char* what() const noexcept override{
            return "StackUnderflowException - Stack is empty!";
    }
};

template <typename T>
class Stack{
    private:
        int capacity;
        T* data;
        int top;

    public:
        Stack(int size){
            capacity = size;
            data = new T[capacity];
            top = -1;
        }

        ~Stack(){
            delete[] data;
        }

        void push(T value){
            if(top >= capacity - 1){
                throw StackOverflowException();
            }
            data[++top] = value;
        }

        T pop(){
            if(top < 0){
                throw StackUnderflowException();
            }
            return data[top--];
        }
};

int main(){
    Stack<int> s(2); 

    try{
        s.push(10);
        s.push(20);
        s.push(30); 
    } 
	catch(const exception& e){
        cout << "Pushing to a full stack: " << e.what() << endl;
    }

    try{
        s.pop();
        s.pop();
        s.pop(); 
    } 
	catch(const exception& e){
        cout << "Popping from an empty stack: " << e.what() << endl;
    }
    return 0;
}