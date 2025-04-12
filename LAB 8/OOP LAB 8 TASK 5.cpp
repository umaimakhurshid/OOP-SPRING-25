#include<iostream>
using namespace std;

class Fraction{
	private:
        int num;
		int denom;
    
	public:
        Fraction(int n = 0, int d = 1){
            num = n;
            denom = d;
        }

        Fraction operator+(Fraction f){
            int n = num * f.denom + f.num * denom;
            int d = denom * f.denom;
            return Fraction(n, d);
        }

        Fraction operator-(Fraction f){
            int n = num * f.denom - f.num * denom;
            int d = denom * f.denom;
            return Fraction(n, d);
        }

        Fraction operator*(Fraction f){
            return Fraction(num * f.num, denom * f.denom);
        }

        Fraction operator/(Fraction f){
            return Fraction(num * f.denom, denom * f.num);
        }

        friend ostream& operator<<(ostream &out, Fraction f){
            out << f.num << "/" << f.denom;
            return out;
        }
};

int main(){
    Fraction f1(1, 2), f2(3, 4);

    Fraction sum = f1 + f2;
    Fraction diff = f1 - f2;
    Fraction prod = f1 * f2;
    Fraction quot = f1 / f2;

    cout << "f1 + f2 = " << sum << endl;
    cout << "f1 - f2 = " << diff << endl;
    cout << "f1 * f2 = " << prod << endl;
    cout << "f1 / f2 = " << quot << endl;
    return 0;
}