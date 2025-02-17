#include<iostream>
#include<string>  
using namespace std;

class Book{
    private: 
        string title;  
        double baseprice;
        double discountpercentage;
        int quantity;

    public:
        Book(string title, double baseprice, double discountpercentage, int quantity){
            this -> title = title;  
            this -> baseprice = baseprice;
            this -> discountpercentage = discountpercentage;
            this -> quantity = quantity;
        }

        void setTitle(const string& newTitle){
            this -> title = newTitle;
        }

        void setbasePrice(double newbasePrice){
            this -> baseprice = newbasePrice;
        }

        void setdiscountPercentage(double newdiscountPercentage){
            this -> discountpercentage = newdiscountPercentage;
        }

        void setQuantity(int newQuantity){
            this -> quantity = newQuantity;
        }

        double calculateprice() const{
            double discountamount = (this -> discountpercentage / 100.0) * this -> baseprice;
            double finalprice = this -> baseprice - discountamount;

            if(this -> quantity > 10){
                finalprice *= 0.90; 
            }
            return finalprice * this -> quantity;
        }

        void display() const{
            cout << "Title: " << this -> title << endl;
            cout << "Base Price: $" << this -> baseprice << endl;
            cout << "Discount: " << this -> discountpercentage << "%" << endl;
            cout << "Quantity: " << this -> quantity << endl;
            cout << "Total Price after Discount: $" << this -> calculateprice() << endl;
        }
};

int main(){
    Book* book1 = new Book("C++ Programming", 50.0, 10.0, 5);
    book1 -> display();

    book1 -> setTitle("Advanced C++ Programming");
    book1 -> setbasePrice(55.0);
    book1 -> setdiscountPercentage(15.0);
    book1 -> setQuantity(8);

    cout << "\nAfter updating the book attributes:\n";
    book1 -> display();
    delete book1;
    return 0;
}
