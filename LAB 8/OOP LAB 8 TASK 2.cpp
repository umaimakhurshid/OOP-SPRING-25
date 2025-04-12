#include<iostream>
#include<string>
using namespace std;

class Book{
	private:
        string title;
        float price;
        
    public:
        Book(string t, float p){
            title = t;
            price = p;
    }
    
    friend class Librarian;
};

class Librarian{
    public:
    	void applydiscount(Book &b, float discount){
            b.price -= b.price * (discount / 100.0);
        }

        void displaybook(Book &b){
            cout << "Title: " << b.title << endl;
            cout << "Price: " << b.price << endl;
        }       
};

int main(){
    Book b("Programming", 1000);
    Librarian l;
    l.displaybook(b);
    l.applydiscount(b, 10);
    cout << "After Discount:" << endl; 
    l.displaybook(b);
    return 0;
}