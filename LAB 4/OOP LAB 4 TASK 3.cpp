#include<iostream>
#include<string>
using namespace std;

class Book{
    private:
        string title;
        double price;
        int stock;

    public:
        Book(){
            title = "Unknown";
            price = 0.0;
            stock = 30;
        }
        Book(string t, double p, int s){
            title = t;
            price = p;
            stock = s;
        }

        Book(const Book &book){
            title = book.title;
            price = book.price;
            stock = book.stock;
            cout << "Copy constructor called: A new book copy has been created.\n";
        }
        
        ~Book(){
            cout << "Destructor called: Book \"" << title << "\" is being destroyed.\n";
        }

        void input(){
            cout << "Enter the book title: ";
            getline(cin, title);
            cout << "Enter the book price: ";
            cin >> price;
            cout << "Enter the initial stock quantity: ";
            cin >> stock;
        }

        void display(){
            cout << "Book Details:\n";
            cout << "Title: " << title << "\n";
            cout << "Price: $" << price << "\n";
            cout << "Stock: " << stock << " copies\n";
        }

        void modifystock(int newstock){
            stock = newstock;
        }
};

int main(){
    Book originalbook("C++ Programming", 10.99, 10);
    cout << "Original book details:\n";
    originalbook.display();

    Book copiedbook = originalbook;
    cout << "Copied book details:\n";
    copiedbook.display();

    originalbook.modifystock(5);
    cout << "\nAfter modifying the original book stock:\n";
    cout << "Original book details:\n";
    originalbook.display();
    cout << "Copied book details:\n";
    copiedbook.display();
    return 0;
}
