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

    void input(){
        cout << "Enter the book title: ";
        getline(cin, title);
        cout << "Enter the book price: ";
        cin >> price;
        cout << "Enter the initial stock quantity: ";
        cin >> stock;
    }

    void purchase(){
        int quantity;
        cout << "Enter the number of copies to purchase: ";
        cin >> quantity;

        if(quantity > stock){
            cout << "Not enough stock available!\n";
        } 
		else{
            stock -= quantity;
            cout << "Purchase successful!";
			cout << "Remaining stock: " << stock << endl;
            if(stock < 5){
                cout << "Warning: Low stock! Only " << stock << " left.\n";
            }
        }
    }

    void display(){
        cout << "Book Details:\n";
        cout << "Title: " << title << "\n";
        cout << "Price: $" << price << "\n";
        cout << "Stock: " << stock << " copies\n";
    }
};

int main(){
    Book book;
    
    book.input();  
    book.display(); 

    char choice;
    do{
        book.purchase();
        cout << "Do you want to purchase again? (y/n): ";
        cin >> choice;
    } 
	while(choice == 'y' || choice == 'Y');
    return 0;
}