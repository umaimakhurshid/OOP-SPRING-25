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
        Inventory(int maxProducts) : count(0), capacity(maxProducts) {
        products = new Product*[capacity];
    }

    // Add product dynamically
    void addProduct(Product* product) {
        if (count < capacity) {
            products[count++] = product;
        } else {
            cout << "Inventory full! Cannot add more products." << endl;
        }
    }

    // Sort products by price (Bubble Sort for simplicity)
    void sortByPrice() {
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - i - 1; j++) {
                if (products[j]->getPrice() > products[j + 1]->getPrice()) {
                    swap(products[j], products[j + 1]);
                }
            }
        }
    }

    // Search for a product by name
    void searchProduct(const string& searchName) const {
        for (int i = 0; i < count; i++) {
            if (products[i]->getName() == searchName) {
                cout << "Product Found: ";
                products[i]->display();
                return;
            }
        }
        cout << "Product not found!" << endl;
    }

    // Display all products
    void displayInventory() const {
        cout << "Inventory Details:" << endl;
        for (int i = 0; i < count; i++) {
            products[i]->display();
        }
        cout << "-----------------------------" << endl;
    }

    // Destructor to free allocated memory
    ~Inventory() {
        for (int i = 0; i < count; i++) {
            delete products[i];
        }
        delete[] products;
    }
};

int main() {
    Inventory store(5); // Max 5 products

    // Adding products dynamically
    store.addProduct(new Product(101, "Laptop", 850.50));
    store.addProduct(new Product(102, "Smartphone", 599.99));
    store.addProduct(new Product(103, "Headphones", 149.99));
    store.addProduct(new Product(104, "Smartwatch", 199.99));
    store.addProduct(new Product(105, "Tablet", 450.00));

    // Display products before sorting
    cout << "Before Sorting:" << endl;
    store.displayInventory();

    // Sort products by price and display
    store.sortByPrice();
    cout << "After Sorting by Price:" << endl;
    store.displayInventory();

    // Search for a product by name
    cout << "Searching for 'Smartwatch':" << endl;
    store.searchProduct("Smartwatch");

    return 0;
}