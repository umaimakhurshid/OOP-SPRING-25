#include<iostream>
#include<string>
using namespace std;

class PaymentMethod{
    public:
        virtual void processPayment(double amount) = 0;
};

class CreditCard : public PaymentMethod{
    private:
        string cardNumber;

    public:
        CreditCard(string number){
            cardNumber = number;
        }

        void processPayment(double amount){
            if(amount > 0){
                cout << "Credit Card payment of $" << amount << " successful using card: " << cardNumber << endl;
            } 
			else{
                cout << "Invalid Credit Card payment amount!" << endl;
            }
        }
};

class DigitalWallet : public PaymentMethod{
    private:
        double balance;
   
    public:
        DigitalWallet(double bal){
            balance = bal;
        }
    
	    void processPayment(double amount){
            if (amount > 0 && balance >= amount){
                balance = balance - amount;
                cout << "Digital Wallet payment of $" << amount << " successful." << endl;
				cout << "Remaining balance: $" << balance << endl;
            } 
			else{
                cout << "Digital Wallet payment failed! Insufficient balance or invalid amount." << endl;
            }
        }
};

int main(){
    CreditCard cc("1234-5678-9012-3456");
    DigitalWallet dw(100.0);

    cc.processPayment(50.0);
    dw.processPayment(30.0);
    dw.processPayment(80.0); 
    return 0;
}