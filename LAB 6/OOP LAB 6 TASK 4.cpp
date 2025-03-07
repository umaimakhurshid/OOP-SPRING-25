#include<iostream>
using namespace std;

class Account{
	protected:
		int accountNumber;
		float balance;
	
	public:
		Account(int accNum, float b) : accountNumber(accNum), balance(b){}
		virtual void displayDetails(){
		cout << "\nAccount Number: " << accountNumber << endl;
		cout << "Balance: " << balance << endl;	
		}
};

class SavingsAccount : public Account{
	private:
		float interestRate;
	
	public:
		SavingsAccount(int accNum, float b, float iR): Account(accNum, b), interestRate(iR){}
		void displayDetails() override{
			Account :: displayDetails();
			cout << "Interest Rate: " << interestRate << "%" << endl;
		}
};

class CheckingAccount : public Account{  
    private:
        float overdraftLimit;
        
    public:
        CheckingAccount(int accNum, float b, float limit) : Account(accNum, b), overdraftLimit(limit){}
        void displayDetails() override{
            Account::displayDetails();
            cout << "Over Draft Limit: " << overdraftLimit << endl;
    }
};

int main(){
    int accountNumber;
	float balance;
	float interestRate;
	float overdraftLimit;

    cout << "Enter the savings account number: ";
    cin >> accountNumber;
    cout << "Enter the balance: ";
    cin >> balance;
    cout << "Enter the interest rate(%): ";
    cin >> interestRate;
    
    SavingsAccount savings(accountNumber, balance, interestRate);
    
    cout << "\nEnter the checking account number: ";
    cin >> accountNumber;
    cout << "Enter the balance: ";
    cin >> balance;
    cout << "Enter the over draft limit: ";
    cin >> overdraftLimit;

    CheckingAccount checking(accountNumber, balance, overdraftLimit);
    cout << "\nSavings Account Details:";
    savings.displayDetails();
    cout << "\nChecking Account Details:";
    checking.displayDetails();
    return 0;
}
