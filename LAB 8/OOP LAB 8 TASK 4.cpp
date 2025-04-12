#include<iostream>
using namespace std;

class Currency{
	private:
        float amount;
    
	public:
        Currency(float a = 0){
            amount = a;
        }

        Currency operator-(){
            return Currency(-amount);
        }

        Currency operator+(Currency c){
            return Currency(amount + c.amount);
        }

        Currency operator-(Currency c){
            return Currency(amount - c.amount);
        }

        Currency& operator+=(Currency c){
            amount += c.amount;
            return *this;
        }

        Currency& operator-=(Currency c){
            amount -= c.amount;
            return *this;
        }

        friend ostream& operator<<(ostream &out, Currency c){
            out << c.amount;
            return out;
        }
};

int main(){
    Currency c1(100), c2(10);
    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;

    Currency c3 = c1 + c2;
    cout << "c1 + c2: " << c3 << endl;

    Currency c4 = c1 - c2;
    cout << "c1 - c2: " << c4 << endl;

    c1 += c2;
    cout << "c1 += c2: " << c1 << endl;

    c1 -= c2;
    cout << "c1 -= c2: " << c1 << endl;

    cout << "Negation of c1: " << -c1 << endl;
    return 0;
}