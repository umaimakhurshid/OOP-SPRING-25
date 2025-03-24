#include<iostream>
using namespace std;

class Currency{
    protected:
        double amount;
        string currencyCode;
        string currencySymbol;
        double exchangeRate;

    public:
        Currency(double amt, string code, string symbol, double rate): amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate){}

        virtual double convertToBase(){
            return amount * exchangeRate; 
        }

        virtual void displayCurrency(){
            cout << "Currency: " << currencyCode << endl;
			cout << "Symbol: " << currencySymbol << endl;
            cout << "Amount: " << amount << endl;
        }

        virtual ~Currency(){}
};

class Dollar : public Currency{
    public:
        Dollar(double amt) : Currency(amt, "USD", "$", 1.0){}

        void displayCurrency() override{
            cout << "Dollar Amount: $" << amount << endl;
        }
};

class Euro : public Currency{
    public:
        Euro(double amt) : Currency(amt, "EUR", "€", 1.1){}

        void displayCurrency() override{
            cout << "Euro Amount: €" << amount << " (Converted to USD: $" << convertToBase() << ")" << endl;
        }
};

class Rupee : public Currency{
    public:
        Rupee(double amt) : Currency(amt, "INR", "₹", 0.012){}

        void displayCurrency() override{
            cout << "Rupee Amount: ₹" << amount << " (Converted to USD: $" << convertToBase() << ")" << endl;
        }
};

int main(){
    Currency* c1 = new Dollar(100);
    Currency* c2 = new Euro(100);
    Currency* c3 = new Rupee(100);

    c1->displayCurrency();
    c2->displayCurrency();
    c3->displayCurrency();

    delete c1;
    delete c2;
    delete c3;
    return 0;
}