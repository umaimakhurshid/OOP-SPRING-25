#include<iostream>
using namespace std;

class InsufficientFundsException{
    public:
        double deficit;

        InsufficientFundsException(double d){
            deficit = d;
        }
};

template <typename T>
class BankAccountT{
    private:
        T balance;

    public:
        BankAccountT(T initialbalance){
            balance = initialbalance;
        }

        void withdraw(T amount){
            if(amount > balance){
                T deficit = amount - balance;
                throw InsufficientFundsException(deficit);
            }
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << balance << endl;
        }
};

int main(){
    BankAccountT<double> account(500.0); 
    
	try{
        account.withdraw(600.0);  
    }
    catch(InsufficientFundsException& e){
        cout << "Deficit amount = " << e.deficit << endl;
    }
    return 0;
}