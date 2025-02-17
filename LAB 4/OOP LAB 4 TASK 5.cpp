#include<iostream>
#include<string>
using namespace std;

class Book{
    private:
        static int idcounter; 
        int bookID;
        string title;
        double price;
        int stock;

    public:
    Book(string t = "Unknown", double p = 0.0, int s = 30) 
        : bookID(++idcounter), title(t), price(p), stock(s){}

    void display(){
        cout << "Book Details:\n";
        cout << "Book ID: " << bookID << "\n";
        cout << "Title: " << title << "\n";
        cout << "Price: $" << price << "\n";
        cout << "Stock: " << stock << " copies\n";
    }
};

int Book::idcounter = 0;

int main(){
    Book book1("Data Structures", 25.99, 9);
    Book book2("Calculus", 17.99, 10);
    Book book3("Machine Learning", 20.99, 5);

    book1.display();
    book2.display();
    book3.display();

    return 0;
}