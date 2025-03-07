#include<iostream>
using namespace std;

class Product{
    private:
        int id;
        string name;
        double price;

    public:
        Product(int prodid, string prodname, double prodprice){
        	id = prodid;
			name = prodname;
			price = prodprice;
		}

    int getID() const{ 
	    return id; 
	}
	
    string getName() const{ 
	    return name; 
	}
	
    double getPrice() const{ 
	    return price; 
	}

    void display() const{
        cout << "Product ID: " << id << endl;
		cout << "Name: " << name << endl;
		cout << "Price: $" << price << endl;
    }
};

class Inventory{
    private:
        Product** products; 
        int count;
        int capacity;

    public:
        Inventory(int maxProducts) : count(0), capacity(maxProducts){
        products = new Product*[capacity];
    }

        void addproduct(Product* product){
            if(count < capacity){
                products[count++] = product;
            } 
		    else{
                cout << "Inventory full! Cannot add more products." << endl;
            }
        }
    
        void sorting(){
            for(int i = 0; i < count - 1; i++){
                for(int j = 0; j < count - i - 1; j++){
                    if(products[j] -> getPrice() > products[j + 1] -> getPrice()){
                        swap(products[j], products[j + 1]);
                    }
                }
            }
        }

        void searchproduct(const string& searchName) const{
            for(int i = 0; i < count; i++){
                if(products[i] -> getName() == searchName){
                    cout << "Product Found:\n";
                    products[i] -> display();
                    return;
                }
            }
            cout << "Product not found!" << endl;
        }
    
        void displayinventory() const{
            cout << "Inventory Details:" << endl;
            for(int i = 0; i < count; i++){
                products[i] -> display();
            }
        }

        ~Inventory(){
            for(int i = 0; i < count; i++){
                delete products[i];
            }
            delete[] products;
        }
};

int main(){
    Inventory store(5); 

    store.addproduct(new Product(101, "Laptop", 850.50));
    store.addproduct(new Product(102, "Smartphone", 599.29));
    store.addproduct(new Product(103, "Headphones", 149.14));
    store.addproduct(new Product(104, "Smartwatch", 199.83));
    store.addproduct(new Product(105, "Tablet", 450.26));

    cout << "Before sorting:" << endl;
    store.displayinventory();

    store.sorting();
    cout << "After sorting by price:" << endl;
    store.displayinventory();

    cout << "Searching for 'Smartwatch':" << endl;
    store.searchproduct("Smartwatch");
    return 0;
}