#include<iostream>
using namespace std;

class Account{
    protected:
        int accountNumber;
        double balance;
        string accountHolderName;
        string accountType;

    public:
        Account(int accno, double bal, string name, string type = "") : accountNumber(accno), balance(bal), accountHolderName(name), accountType(type){}

        void deposit(double amount){
            if(amount > 0){
                balance += amount;
                cout << "Deposited: " << amount << endl;
				cout << "New Balance: " << balance << endl;
            } 
			else{
                cout << "Invalid deposit amount!";
            }
        }

        virtual void withdraw(double amount){
            if(amount > 0 && amount <= balance){
                balance -= amount;
                cout << "Withdrawn: " << amount << endl;
				cout << "Remaining Balance: " << balance << endl;
            } 
			else{
                cout << "Invalid withdrawal amount or insufficient balance!";
            }
        }

        virtual double calculateInterest(){
            return 0; 
        }

        virtual void printStatement(){
        	cout << "Account Number: " << accountNumber << endl;
            cout << "Account Holder: " << accountHolderName << endl;
            cout << "Balance: " << balance << endl;
        }

        virtual ~Account(){}
};

class SavingsAccount : public Account{
    double interestRate;
    double minimumBalance;

    public:
        SavingsAccount(int accno, double bal, string name, double rate, double minbal) : Account(accno, bal, name, "Savings"), interestRate(rate), minimumBalance(minbal){}

        double calculateInterest() override{
            return balance * interestRate / 100;
        }

        void withdraw(double amount) override{
            if((balance - amount) >= minimumBalance){
                balance -= amount;
                cout << "Withdrawn: " << amount << endl;
				cout << "Remaining Balance: " << balance << endl;
            } 
			else{
                cout << "Withdrawal denied! Insufficient balance";
            }
        }

        void printStatement() override{
            Account :: printStatement();
            cout << "Interest Rate: " << interestRate << "%" << endl;
            cout << "Minimum Balance: " << minimumBalance << endl;
        }
};

class CheckingAccount : public Account{
    public:
        CheckingAccount(int accno, double bal, string name) : Account(accno, bal, name, "Checking"){}

        void withdraw(double amount) override{
            if (amount > 0 && amount <= balance){
                balance -= amount;
                cout << "Withdrawn: " << amount << endl;
				cout << "Remaining Balance: " << balance << endl;
            } 
			else{
                cout << "Invalid withdrawal amount or insufficient balance!";
            }
        }

        void printStatement() override{
            Account :: printStatement();
            cout << "Checking Account does not earn interest.";
        }
};

class FixedDepositAccount : public Account{
    double fixedInterestRate;
    int maturityDate;

    public:
        FixedDepositAccount(int accno, double bal, string name, double rate, int maturity) : Account(accno, bal, name, "Fixed Deposit"), fixedInterestRate(rate), maturityDate(maturity){}
  
        double calculateInterest() override{
            return balance * fixedInterestRate / 100;
        }

        void withdraw(double amount) override{
            cout << "Withdrawal not allowed before maturity date!" << endl;
        }

        void printStatement() override{
            Account :: printStatement();
            cout << "Fixed Interest Rate: " << fixedInterestRate << "%" << endl;
            cout << "Maturity Date: " << maturityDate << endl;
    }
};

int main(){
    Account* savings = new SavingsAccount(101, 5000, "Sarim", 5.0, 1000);
    Account* checking = new CheckingAccount(102, 3000, "Sara");
    Account* fixed = new FixedDepositAccount(103, 10000, "Saim", 6.5, 2027);

    savings -> printStatement();
    cout << "Interest Earned: " << savings -> calculateInterest() << endl;
    savings -> withdraw(500);
  
    checking->printStatement();
    cout << "Interest Earned: " << checking -> calculateInterest() << endl;
    checking -> withdraw(500);

    fixed -> printStatement();
    cout << "Interest Earned: " << fixed -> calculateInterest() << endl;
    fixed -> withdraw(500);

    delete savings;
    delete checking;
    delete fixed;
    return 0;
}