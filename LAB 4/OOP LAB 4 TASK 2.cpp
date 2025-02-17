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
    
    double discount(int quantity){
        double discount = 0.0;

        if(quantity > 10){
            discount = 0.10; 
        }
		else if(quantity > 5){
            discount = 0.05; 
        }
        return price * (1 - discount); 
    }

    void purchase(){
        int quantity;
        cout << "Enter the number of copies to purchase: ";
        cin >> quantity;

        if(quantity > stock){
            cout << "Error: Not enough stock available!" << endl;
			cout << "Maximum available stock: " << stock << "\n";
        } 
		else{
            double finalprice = discount(quantity) * quantity;
            stock -= quantity;
            cout << "Purchase successful! Final cost: $" << finalprice << "\n";
            cout << "Remaining stock: " << stock << " copies\n";
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